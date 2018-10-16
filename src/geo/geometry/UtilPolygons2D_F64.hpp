#pragma once
#include <Object.hpp>
#include <vector>

// import georegression.geometry.algs.AndrewMonotoneConvexHull_F64;
namespace geo { namespace structure { namespace  line {
class LineSegment2D_F64;
}}}

namespace geo { namespace structure { namespace point {
class Point2D_F64;
}}}

namespace geo { namespace structure { namespace shapes {
class Polygon2D_F64;
class Quadrilateral_F64;
class Rectangle2D_F64;
class RectangleLength2D_I32;
}}}

using namespace geo::structure::line;
using namespace geo::structure::point;
using namespace geo::structure::shapes;

namespace geo { namespace geometry {

/**
 * Various functions related to polygons.
 *
 */
class UtilPolygons2D_F64 {
public:
  /**
   * Determines if the polugon is convex or concave.
   *
   * @param poly Polygon
   * @return true if convex and false if concave
   */
  static bool isConvex( Polygon2D_F64 *poly );

  /**
   * Converts a rectangle into a quadrilateral
   *
   * @param input Rectangle.
   * @param output Quadrilateral.  Modified.
   */
  static void convert( Rectangle2D_F64 *input , Quadrilateral_F64 *output );

  /**
   * Converts a rectangle into a polygon
   *
   * @param input Rectangle.
   * @param output Polygon2D_F64.  Modified.
   */
  static void convert( Rectangle2D_F64 *input , Polygon2D_F64 *output );

  /**
   * Converts a quadrilateral into a polygon
   *
   * @param input Quadrilateral.
   * @param output Polygon2D_F64.  Modified.
   */
  static void convert( Quadrilateral_F64 *input , Polygon2D_F64 *output );

  /**
   * Converts a polygon into a quadrilateral
   *
   * @param input polygon.
   * @param output Quadrilateral.  Modified.
   */
  static void convert( Polygon2D_F64 *input , Quadrilateral_F64 *output );

  /**
   * Converts a rectangle into a quadrilateral
   *
   * @param input Rectangle.
   * @param output Quadrilateral.  Modified.
   */
  static void convert( RectangleLength2D_I32 *input , Quadrilateral_F64 *output );

  /**
   * Finds the minimum area bounding rectangle around the quadrilateral.
   *
   * @param quad (Input) Quadrilateral
   * @param rectangle (Output) Minimum area rectangle
   */
  static void bounding( Quadrilateral_F64 *quad , Rectangle2D_F64 *rectangle );

  /**
   * Finds the minimum area bounding rectangle around the quadrilateral that is aligned with coordinate
   * system axises.
   *
   * @param polygon (Input) Polygon
   * @param rectangle (Output) Minimum area rectangle
   */
  static void bounding( Polygon2D_F64 *polygon , Rectangle2D_F64 *rectangle );

  /**
   * Computes the center or average point in the quadrilateral.
   *
   * @param quad (Input) Quadrilateral
   * @param center (output) Center point of the quadrilateral.  Can be null.
   * @return The center point.
   */
  static Ref<Point2D_F64> center( Quadrilateral_F64 *quad,
                                  Ref<Point2D_F64> center = Ref<Point2D_F64>(0));

  /**
   * Returns true if the polygon is ordered in a counter-clockwise order.  This is done by summing up the interior
   * angles.
   *
   * @param polygon List of ordered points which define a polygon
   * @return true if CCW and false if CW
   */
  static bool isCCW( std::vector<Ref<Point2D_F64> > &polygon );

  static bool isCCW( Polygon2D_F64 *polygon );

  /**
   * Computes the average of all the vertexes
   * @param input (input) polygon
   * @param average (output) average point
   */
  static void vertexAverage(Polygon2D_F64 *input, Point2D_F64 *average );

  /**
   * Checks to see if the vertexes of the two polygon's are the same up to the specified tolerance
   *
   * @param a Polygon
   * @param b Polygon
   * @param tol tolerance
   * @return true if identical up to tolerance or false if not
   */
  static bool isIdentical( Polygon2D_F64 *a , Polygon2D_F64 *b , double tol );

  /**
   * Checks to see if the vertexes of the two polygon's are the same up to the specified tolerance and allows
   * for a shift in their order
   *
   * @param a Polygon
   * @param b Polygon
   * @param tol tolerance
   * @return true if identical up to tolerance or false if not
   */
  static bool isEquivalent( Polygon2D_F64 *a , Polygon2D_F64 *b , double tol );

  /**
   * Flips the order of points inside the polygon.  The first index will remain the same will otherwise be reversed
   *
   * @param a Polygon of order 3 or more.
   */
  static void flip( Polygon2D_F64 *a );

  /**
   * Shifts all the vertexes in the polygon up one element.  Wraps around at the end
   * @param a Polygon
   */
  static void shiftUp( Polygon2D_F64 *a );

  /**
   * Shifts all the vertexes in the polygon up one element.  Wraps around at the end
   * @param a Polygon
   */
  static void shiftDown( Polygon2D_F64 *a );

  /**
   * Computes the convex hull of the set of points.
   *
   * <p>
   * NOTE: This method declares a temporary array.  If you want to avoid that invoke {@link AndrewMonotoneConvexHull_F64}
   * directly.
   * </p>
   *
   * @param points (Input) Set of points.
   * @param hull (output) storage for convex hull.  Will be in counter-clockwise order
   */
  static void convexHull( std::vector<Ref<Point2D_F64> > &points , Polygon2D_F64 *hull );

  /**
   * Removes a node from a polygon if the two lines its attached two are almost parallel
   * @param polygon The polygon being modified
   * @param tol Tolerance in radians
   */
  static void removeAlmostParallel( Polygon2D_F64 *polygon , double tol );

  /**
   * Remove a point if it's identical to a neighbor
   *
   * @param polygon The polygon being modified
   * @param tol Tolerance in radians
   */
  static void removeAdjacentDuplicates( Polygon2D_F64 *polygon , double tol );

  /**
   * Remove a point if it's identical to a neighbor
   *
   * @param polygon The polygon being modified
   * @param tol Tolerance in radians
   */
  static bool hasAdjacentDuplicates( Polygon2D_F64 *polygon , double tol );

  /**
   * Compute the error as a function of the distance between the model and target. The target is sampled at regular
   * intervals and for each of these points the closest point on the model is found. The returned metric is the
   * average of difference between paired points.
   *
   * NOTE: A different answer will be returned depending on which polygon is the model and which one is the target.
   *
   * @param model Model polygon
   * @param target Target polygon
   * @return average of closest point error
   */
  static double
  averageOfClosestPointError(Polygon2D_F64 *model,
                             Polygon2D_F64 *target,
                             int numberOfSamples );
};

}}
