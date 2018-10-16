#pragma once

#include <Object.hpp>

namespace geo { namespace structure {
namespace shapes {
class Polygon2D_I32;
class Rectangle2D_I32;
}
namespace point {
class Point2D_I32;
}
}}

using namespace geo::structure::point;
using namespace geo::structure::shapes;

#include <vector>

namespace geo { namespace geometry {

/**
 * Various functions related to polygons.
 *
 */
class UtilPolygons2D_I32 {
public:
  /**
   * Finds the minimum area bounding rectangle which is aligned to the x and y axis around the list of points.
   * Note (x0,y0) is inclusive and (x1,y1) is exclusive.
   *
   * @param points (Input) Quadrilateral
   * @param rectangle (Output) Minimum area rectangle
   */
  static void bounding( std::vector<Ref<Point2D_I32 > > const &points ,
                        Rectangle2D_I32 &rectangle );

  /**
   * Finds the minimum area bounding rectangle which is aligned to the x and y axis around the polygon.
   * Note (x0,y0) is inclusive and (x1,y1) is exclusive.
   *
   * @param quad (Input) Quadrilateral
   * @param rectangle (Output) Minimum area rectangle
   */
  void bounding( Ref<Polygon2D_I32> quad , Ref<Rectangle2D_I32> rectangle );

  /**
   * Returns true if the polygon is ordered in a counter-clockwise order.  This is done by summing up the interior
   * angles.
   *
   * @param polygon List of ordered points which define a polygon
   * @return true if CCW and false if CW
   */
  static bool isCCW( std::vector<Ref<Point2D_I32> > &polygon );

  /**
   * Flips the order of points inside the polygon.  The first index will remain the same will otherwise be reversed
   *
   * @param a Polygon of order 3 or more.
   */
  static void flip( Polygon2D_I32 *a );

  /**
   * Determines if the polugon is convex or concave.
   *
   * @param poly Polygon
   * @return true if convex and false if concave
   */
  static bool isConvex( Polygon2D_I32 *poly );

  /**
   * Returns true if the cross product would result in a strictly positive z (e.g. z > 0 ). If true then
   * the order is clockwise.
   *
   * v0 = a-b
   * v1 = c-b
   *
   * @param a first point in sequence
   * @param b second point in sequence
   * @param c third point in sequence
   * @return true if positive z
   */
  static bool isPositiveZ(Point2D_I32 const *a,
                          Point2D_I32 const *b,
                          Point2D_I32 const *c  );

  /**
   * Checks to see if the vertexes of the two polygon's are the same up to the specified tolerance
   *
   * @param a Polygon
   * @param b Polygon
   * @return true if identical up to tolerance or false if not
   */
  static bool isIdentical(Polygon2D_I32 *a, Ref<Polygon2D_I32> b);

  /**
   * Checks to see if the vertexes of the two polygon's are the same up to the specified tolerance and allows
   * for a shift in their order
   *
   * @param a Polygon
   * @param b Polygon
   * @return true if identical up to tolerance or false if not
   */
  static bool isEquivalent( Polygon2D_I32 *a , Ref<Polygon2D_I32> b);

};

}}
