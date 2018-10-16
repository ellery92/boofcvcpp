#include "UtilPoint2D_F64.hpp"

#include <geo/struct/point/Point2D_F64.hpp>
#include <geo/struct/point/Vector2D_F64.hpp>
#include <geo/struct/shapes/Rectangle2D_F64.hpp>
#include <geo/struct/shapes/RectangleLength2D_F64.hpp>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

namespace geo { namespace geometry {

void
UtilPoint2D_F64::mean( Point2D_F64 *list, int length, Point2D_F64* mean ) {
  double x = 0;
  double y = 0;

  for (int i = 0; i < length; i++) {
    x += list[i].x;
    y += list[i].y;
  }

  x /= length;
  y /= length;

  mean->set(x, y);
}

void UtilPoint2D_F64::mean( Point2D_F64 *a , Point2D_F64 *b, Point2D_F64 *mean) {
  mean->x = (a->x + b->x)/2.0;
  mean->y = (a->y + b->y)/2.0;
}

void
UtilPoint2D_F64::bounding(Point2D_F64* points,
                          int length,
                          RectangleLength2D_F64 *bounding) {
  double minX=std::numeric_limits<double>::max();
  double maxX=std::numeric_limits<double>::min();
  double minY=std::numeric_limits<double>::max();
  double maxY=std::numeric_limits<double>::min();

  for( int i = 0; i < length; i++ ) {
    Point2D_F64 *p = points + i;
    if( p->x < minX )
      minX = p->x;
    if( p->x > maxX )
      maxX = p->x;
    if( p->y < minY )
      minY = p->y;
    if( p->y > maxY )
      maxY = p->y;
  }

  bounding->x0 = minX;
  bounding->y0 = minY;
  bounding->width = maxX-minX;
  bounding->height = maxY-minY;

  // make sure rounding doesn't cause a point to be out of bounds
  bounding->width  += std::max(0.0,(maxX-(bounding->x0+bounding->width ))*10.0);
  bounding->height += std::max(0.0,(maxY-(bounding->y0+bounding->height))*10.0);
}

void
UtilPoint2D_F64::orderCCW( Point2D_F64 *points, int length,
                           Point2D_F64 *out) {
  Point2D_F64 center;
  mean(points, length, &center);

  struct angle {
    double val;
    int index;

    bool operator<(const angle b) const {
      return val < b.val;
    }
  };

  std::vector<struct angle> angles(length);

  for (int i = 0; i < angles.size(); i++) {
    Point2D_F64 *p = points + i;

    double dx = p->x - center.x;
    double dy = p->y - center.y;

    angles[i].val = atan2(dy, dx);
  }

  std::sort(angles.begin(), angles.end());

  for (int i = 0; i < length; i++) {
    int j = angles[i].index;
    out[i].x = points[j].x;
    out[i].y = points[j].y;
  }
}

}}
