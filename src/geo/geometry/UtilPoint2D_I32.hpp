#pragma once
#include <Object.hpp>
#include <cmath>
#include <vector>

namespace geo { namespace structure { namespace point {
class Point2D_I32;
}}}

using namespace geo::structure::point;

namespace geo { namespace geometry {
class UtilPoint2D_I32 {
public:
  static double distance( Point2D_I32 *a , Point2D_I32 *b );

  static int distanceSq( Point2D_I32 *a , Point2D_I32 *b );

  static double distance( int x0, int y0, int x1, int y1 ) {
    int dx = x1 - x0;
    int dy = y1 - y0;

    return sqrt( dx * dx + dy * dy );
  }

  static int distanceSq( int x0, int y0, int x1, int y1 ) {
    int dx = x1 - x0;
    int dy = y1 - y0;

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
  static Ref<Point2D_I32> mean(std::vector<Ref<Point2D_I32> > &list,
                               Ref<Point2D_I32> mean = Ref<Point2D_I32>(0));
};
}}
