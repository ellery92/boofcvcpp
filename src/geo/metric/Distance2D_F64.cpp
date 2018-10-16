#include "Distance2D_F64.hpp"

#include <geo/metric/ClosestPoint2D_F64.hpp>
#include <geo/struct/line/LineParametric2D_F64.hpp>
#include <geo/struct/line/LineGeneral2D_F64.hpp>
#include <geo/struct/point/Point2D_F64.hpp>
#include <geo/struct/point/Vector2D_F64.hpp>
#include <geo/struct/line/LineSegment2D_F64.hpp>
#include <geo/geometry/UtilPoint2D_F64.hpp>
#include <geo/struct/shapes/Quadrilateral_F64.hpp>
#include <geo/struct/shapes/Polygon2D_F64.hpp>

using namespace geo::geometry;

namespace geo { namespace metric {

double Distance2D_F64::distanceSq( LineParametric2D_F64 *line, Point2D_F64 *p ) {
  double t = ClosestPoint2D_F64::closestPointT( line, p );

  double a = line->slope->x * t + line->p->x;
  double b = line->slope->y * t + line->p->y;

  double dx = p->x - a;
  double dy = p->y - b;

  return dx * dx + dy * dy;
}

double Distance2D_F64::distanceSq( LineParametric2D_F64 *line, double x , double y ) {
  double t = ClosestPoint2D_F64::closestPointT( line, x,y );

  double a = line->slope->x * t + line->p->x;
  double b = line->slope->y * t + line->p->y;

  double dx = x - a;
  double dy = y - b;

  return dx * dx + dy * dy;
}

double Distance2D_F64::distanceSq( LineSegment2D_F64 *line, Point2D_F64 *p ) {
  double a = line->b_->x - line->a_->x;
  double b = line->b_->y - line->a_->y;

  double t = a * ( p->x - line->a_->x ) + b * ( p->y - line->a_->y );
  t /= ( a * a + b * b );

  // if the point of intersection is past the end points return the distance
  // from the closest end point
  if( t < 0 ) {
    return UtilPoint2D_F64::distanceSq(line->a_->x, line->a_->y, p->x, p->y);
  } else if( t > 1.0 )
    return UtilPoint2D_F64::distanceSq(line->b_->x, line->b_->y, p->x, p->y);

  // return the distance of the closest point on the line
  return UtilPoint2D_F64::distanceSq(line->a_->x + t * a, line->a_->y + t * b, p->x, p->y);
}

double Distance2D_F64::distanceSq( LineSegment2D_F64 *line, double x , double y ) {
  double a = line->b_->x - line->a_->x;
  double b = line->b_->y - line->a_->y;

  double t = a * ( x - line->a_->x ) + b * ( y - line->a_->y );
  t /= ( a * a + b * b );

  // if the point of intersection is past the end points return the distance
  // from the closest end point
  if( t < 0 ) {
    return UtilPoint2D_F64::distanceSq(line->a_->x, line->a_->y, x, y);
  } else if( t > 1.0 )
    return UtilPoint2D_F64::distanceSq(line->b_->x, line->b_->y, x, y);

  // return the distance of the closest point on the line
  return UtilPoint2D_F64::distanceSq(line->a_->x + t * a, line->a_->y + t * b, x, y);
}

double Distance2D_F64::distanceSq( LineSegment2D_F64 *segmentA ,
                                   LineSegment2D_F64 *segmentB ) {

  // intersection of the two lines relative to A
  double slopeAX = segmentA->slopeX();
  double slopeAY = segmentA->slopeY();
  double slopeBX = segmentB->slopeX();
  double slopeBY = segmentB->slopeY();

  double ta = slopeBX*( segmentA->a_->y - segmentB->a_->y )
    - slopeBY*( segmentA->a_->x - segmentB->a_->x );
  double bottom = slopeBY*slopeAX - slopeAY*slopeBX;

  // see they intersect
  if( bottom != 0 ) {
    // see if the intersection is inside of lineA
    ta /= bottom;
    if( ta >= 0 && ta <= 1.0 ) {
      // see if the intersection is inside of lineB
      double tb = slopeAX*( segmentB->a_->y - segmentA->a_->y )
        - slopeAY*( segmentB->a_->x - segmentA->a_->x );
      tb /= slopeAY*slopeBX - slopeBY*slopeAX;
      if( tb >= 0 && tb <= 1.0 )
        return 0;
    }
  }

  double closest = std::numeric_limits<double>::max();
  closest = std::min(closest,distanceSq(segmentA, segmentB->a_));
  closest = std::min(closest,distanceSq(segmentA, segmentB->b_));
  closest = std::min(closest,distanceSq(segmentB, segmentA->a_));
  closest = std::min(closest,distanceSq(segmentB, segmentA->b_));

  return closest;
}

double Distance2D_F64::distanceSq( Quadrilateral_F64 *quad , Point2D_F64 *p ) {
  Ref<LineSegment2D_F64> seg = LineSegment2D_F64::wrap(quad->a, quad->b);
  double a = distanceSq(seg, p);
  seg->a_ = quad->b;seg->b_ = quad->c;
  a = std::min(a,distanceSq(seg,p));
  seg->a_ = quad->c;seg->b_ = quad->d;
  a = std::min(a,distanceSq(seg,p));
  seg->a_ = quad->d;seg->b_ = quad->a;
  return std::min(a, distanceSq(seg, p));
}

double Distance2D_F64::distanceSq( Polygon2D_F64 *poly ,
                                   Point2D_F64 *p , LineSegment2D_F64 *storage ) {
  if( !storage )
    storage = LineSegment2D_F64::wrap(Ref<Point2D_F64>(0), Ref<Point2D_F64>(0));

  double minimum = std::numeric_limits<double>::max();
  for (int i = 0; i < poly->size(); i++) {
    int j = (i+1)%poly->size();

    storage->a_ = poly->vertexes[i];
    storage->b_ = poly->vertexes[j];

    double d = distanceSq(storage, p);
    if( d < minimum )
      minimum = d;
  }

  return minimum;
}

double Distance2D_F64::distance( LineGeneral2D_F64 *line , Point2D_F64 *p ) {
  return std::abs(line->A*p->x + line->B*p->y + line->C)
    / sqrt( line->A*line->A + line->B*line->B );
}

double Distance2D_F64::distanceNorm(LineGeneral2D_F64 *line, Point2D_F64 *p) {
  return std::abs(line->A*p->x + line->B*p->y + line->C);
}

double Distance2D_F64::distanceOrigin( LineParametric2D_F64 *line ) {
  double top = line->slope->y*line->p->x - line->slope->x*line->p->y;

  return std::abs(top)/line->slope->norm();
}

}}
