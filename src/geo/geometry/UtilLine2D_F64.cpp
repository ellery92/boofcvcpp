#include "UtilLine2D_F64.hpp"
#define _USE_MATH_DEFINES
#include <cmath>

#include <geo/struct/line/LineGeneral2D_F64.hpp>
#include <geo/struct/line/LineParametric2D_F64.hpp>
#include <geo/struct/line/LinePolar2D_F64.hpp>
#include <geo/struct/line/LineSegment2D_F64.hpp>
#include <geo/struct/point/Point2D_F64.hpp>
#include <geo/struct/point/Vector2D_F64.hpp>

#include <geo/metric/UtilAngle.hpp>

using namespace geo::geometry;
using namespace geo::metric;

double UtilLine2D_F64::acuteAngle( LineGeneral2D_F64 *a , LineGeneral2D_F64 *b ) {
  double la = sqrt(a->A*a->A + a->B*a->B);
  double lb = sqrt(b->A*b->A + b->B*b->B);

  // numerical round off error can cause it to be barely greater than 1, which is outside the allowed
  // domain of acos()
  double value = (a->A*b->A + a->B*b->B)/(la*lb);
  if( value < -1.0 ) value = -1.0;
  else if( value > 1.0 ) value = 1.0;
  return acos(value);
}

double UtilLine2D_F64::acuteAngleN( LineGeneral2D_F64 *a , LineGeneral2D_F64 *b ) {
  double value = a->A*b->A + a->B*b->B;
  if( value < -1.0 ) value = -1.0;
  else if( value > 1.0 ) value = 1.0;
  return acos(value);
}

Ref<LineParametric2D_F64>
UtilLine2D_F64::convert( LinePolar2D_F64 *src , Ref<LineParametric2D_F64> ret ) {
  if( !ret )
    ret = Ref<LineParametric2D_F64>(new LineParametric2D_F64());

  double c = (double) cos(src->angle);
  double s = (double) sin(src->angle);

  ret->p->set(c*src->distance,s*src->distance);
  ret->slope->set(-s,c);

  return ret;
}

Ref<LineGeneral2D_F64>
UtilLine2D_F64::convert( LinePolar2D_F64 *src , Ref<LineGeneral2D_F64> ret) {
  if( !ret )
    ret = Ref<LineGeneral2D_F64>(new LineGeneral2D_F64());

  double c = (double) cos(src->angle);
  double s = (double) sin(src->angle);

  ret->A = c;
  ret->B = s;
  ret->C = -src->distance;

  return ret;
}

Ref<LinePolar2D_F64>
UtilLine2D_F64::convert( LineGeneral2D_F64 *src , Ref<LinePolar2D_F64> ret)
{
  if( !ret )
    ret = Ref<LinePolar2D_F64>(new LinePolar2D_F64());

  double r = sqrt(src->A*src->A + src->B*src->B);

  double sign = src->C < 0 ? -1 : 1;

  ret->angle = atan2(-sign*src->B/r,-sign*src->A/r);
  ret->distance = sign*src->C/r;

  return ret;
}

Ref<LineParametric2D_F64>
UtilLine2D_F64::convert( LineSegment2D_F64 *src, Ref<LineParametric2D_F64> ret)
{
  if( !ret )
    ret = Ref<LineParametric2D_F64>(new LineParametric2D_F64());

  ret->p->set(src->a_);
  ret->slope->set(src->slopeX(),src->slopeY());

  return ret;
}

Ref<LineGeneral2D_F64>
UtilLine2D_F64::convert( LineSegment2D_F64 *src, Ref<LineGeneral2D_F64> ret) {
  return convert(src->a_,src->b_,ret);
}

Ref<LineGeneral2D_F64>
UtilLine2D_F64::convert( Ref<Point2D_F64> a, Ref<Point2D_F64> b, Ref<LineGeneral2D_F64> ret) {
  if( !ret )
    ret = Ref<LineGeneral2D_F64>(new LineGeneral2D_F64());

  ret->A = a->y - b->y;
  ret->B = b->x - a->x;
  ret->C = -(ret->A*a->x + ret->B*a->y);

  return ret;
}

Ref<LineParametric2D_F64>
UtilLine2D_F64::convert( Ref<Point2D_F64> a , Ref<Point2D_F64> b ,
                         Ref<LineParametric2D_F64> ret) {
  if( !ret )
    ret = Ref<LineParametric2D_F64>(new LineParametric2D_F64());

  ret->p->set(a);
  ret->slope->x = b->x-a->x;
  ret->slope->y = b->y-a->y;

  return ret;
}

Ref<LinePolar2D_F64>
UtilLine2D_F64::convert( LineParametric2D_F64 *src, Ref<LinePolar2D_F64> ret) {
  if( !ret )
    ret = Ref<LinePolar2D_F64>(new LinePolar2D_F64());

  double top = src->slope->y*src->p->x - src->slope->x*src->p->y;
  ret->distance = top/src->slope->norm();
  ret->angle = atan2(-src->slope->x,src->slope->y);

  if( ret->distance < 0 ) {
    ret->distance = -ret->distance;
    ret->angle = UtilAngle::bound(ret->angle + M_PI);
  }

  return ret;
}

Ref<LineGeneral2D_F64>
UtilLine2D_F64::convert( LineParametric2D_F64 *src, Ref<LineGeneral2D_F64> ret) {
  if( !ret ) {
    ret = Ref<LineGeneral2D_F64> (new LineGeneral2D_F64());
  }

  ret->A = -src->slope->y;
  ret->B = src->slope->x;
  ret->C = -ret->A*src->p->x - ret->B*src->p->y;

  return ret;
}

Ref<LineParametric2D_F64>
UtilLine2D_F64::convert( LineGeneral2D_F64 *src, Ref<LineParametric2D_F64> ret) {
  if( !ret ) {
    ret = Ref<LineParametric2D_F64>(new LineParametric2D_F64());
  }

  ret->slope->x = src->B;
  ret->slope->y = -src->A;

  // find a point on the line
  if( abs(src->B) > abs(src->A) ) {
    ret->p->y = -src->C/src->B;
    ret->p->x = 0;
  } else {
    ret->p->x = -src->C/src->A;
    ret->p->y = 0;
  }

  return ret;
}
