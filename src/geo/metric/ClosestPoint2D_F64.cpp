#include "ClosestPoint2D_F64.hpp"

#include <geo/struct/line/LineGeneral2D_F64.hpp>
#include <geo/struct/line/LineParametric2D_F64.hpp>
#include <geo/struct/line/LineSegment2D_F64.hpp>

#include <geo/struct/point/Point2D_F64.hpp>
#include <geo/struct/point/Vector2D_F64.hpp>

namespace geo { namespace metric {

Ref<Point2D_F64>
ClosestPoint2D_F64::closestPoint( LineGeneral2D_F64 *line,
                                  Point2D_F64 *p,
                                  Ref<Point2D_F64> output) {
  if( !output )
    output = new Point2D_F64();

  double AA = line->A*line->A;
  double AB = line->A*line->B;
  double BB = line->B*line->B;

  output->y = AA*p->y - AB*p->x - line->B*line->C;
  output->y /= AA+BB;

  output->x = BB*p->x - AB*p->y - line->A*line->C;
  output->x /= AA+BB;

  return output;
}

Ref<Point2D_F64>
ClosestPoint2D_F64::closestPoint( LineParametric2D_F64 *line,
                                  Point2D_F64 *p,
                                  Ref<Point2D_F64> output) {
  if( !output )
    output = new Point2D_F64();

  double t = closestPointT( line, p );

  output->x = line->p->x + line->slope->x * t;
  output->y = line->p->y + line->slope->y * t;

  return output;
}

double
ClosestPoint2D_F64::closestPointT( LineParametric2D_F64 *line, Point2D_F64 *p ) {
  double t = line->slope->x * ( p->x - line->p->x ) + line->slope->y * ( p->y - line->p->y );
  t /= line->slope->x * line->slope->x + line->slope->y * line->slope->y;

  return t;
}

double ClosestPoint2D_F64::closestPointT( LineParametric2D_F64 *line, double x, double y) {
  double t = line->slope->x * ( x - line->p->x ) + line->slope->y * ( y - line->p->y );
  t /= line->slope->x * line->slope->x + line->slope->y * line->slope->y;

  return t;
}

Ref<Point2D_F64> ClosestPoint2D_F64::closestPoint( LineSegment2D_F64 *line,
                                      Point2D_F64 *p,
                                      Ref<Point2D_F64> output) {

  if( !output )
    output = new Point2D_F64();

  double slopeX = line->b_->x - line->a_->x;
  double slopeY = line->b_->y - line->a_->y;

  double t = slopeX * ( p->x - line->a_->x ) + slopeY * ( p->y - line->a_->y );
  t /= slopeX*slopeX + slopeY*slopeY;

  if( t < 0 )
    t = 0;
  else if( t > 1 )
    t = 1;

  output->x = line->a_->x + slopeX * t;
  output->y = line->a_->y + slopeY * t;

  return output;
}

}}
