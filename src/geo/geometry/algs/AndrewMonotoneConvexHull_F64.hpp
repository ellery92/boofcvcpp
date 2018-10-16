#pragma once
#include <vector>

namespace geo { namespace structure { namespace point {
class Point2D_F64;
}}}
namespace geo { namespace structure { namespace shapes {
class Polygon2D_F64;
}}}

using namespace geo::structure::point;
using namespace geo::structure::shapes;

namespace geo { namespace geometry { namespace algs {

/**
 * Computes the convex hull of a set of points using Andrew's monotone chain algorithm.  O(n log n) for sort and
 * O(N) for convex hull computation, where N is number of input points.
 *
 */
class AndrewMonotoneConvexHull_F64 {
public:
  static bool point_compare(Point2D_F64 *a, Point2D_F64 *b);

  /**
   * Computes the convex hull.  The output will be in counter-clockwise order.
   *
   * @param input List of input points.  The list will be modified by sorting
   * @param length Number of valid elements in list
   * @param hull (Output) Where the complex hull is written to
   */
  static void process( std::vector<Point2D_F64*> &input , int length , Polygon2D_F64 *hull );

  /**
   * Performs the following operation: output = z-component[ (a-b) cross (a-c) ]
   */
  static double subtractThenCross( Point2D_F64 *a , Point2D_F64 *b , Point2D_F64 *c );

};

}}}
