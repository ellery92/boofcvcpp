#pragma once
#include <cmath>

namespace geo {namespace structure { namespace point {
class Point2D_F64;
}}}

namespace geo {namespace structure { namespace shapes {
class Rectangle2D_F64;
class RectangleLength2D_F64;
}}}

using namespace geo::structure::shapes;
using namespace geo::structure::point;

/**
 *
 *
 */
namespace geo { namespace geometry {

class UtilPoint2D_F64 {
public:
  static double distance( double x0, double y0, double x1, double y1 ) {
    double dx = x1 - x0;
    double dy = y1 - y0;

    return sqrt( dx * dx + dy * dy );
  }

  static double distanceSq( double x0, double y0, double x1, double y1 ) {
    double dx = x1 - x0;
    double dy = y1 - y0;

    return dx * dx + dy * dy;
  }

  /**
   * Finds the point which has the mean location of all the points in the list. This is also known
   * as the centroid.
   *
   * @param list List of points
   * @param mean Storage for mean point.  If null then a new instance will be declared
   * @return The found mean
   */
  static void mean( Point2D_F64* list,
                    int length,
                    Point2D_F64* mean);

  /**
   * Computes the mean/average of two points.
   *
   * @param a (input) Point A
   * @param b (input) Point B
   * @param mean (output) average of 'a' and 'b'
   *
   */
  static void mean( Point2D_F64 *a , Point2D_F64 *b, Point2D_F64 *mean);

  /**
   * Finds the minimal volume {@link georegression.struct.shapes.RectangleLength2D_F64} which contains all the points.
   *
   * @param points Input: List of points.
   * @param bounding Output: Bounding rectangle
   */
  static void
  bounding(Point2D_F64* points,
           int length,
           RectangleLength2D_F64 *bounding);

  /**
   * Puts the points into counter-clockwise order around their center.
   *
   * @param points List of points. Not modified.
   * @return ordered list
   */
  static void orderCCW( Point2D_F64* points, int length,
                        Point2D_F64* out);
};

}}
