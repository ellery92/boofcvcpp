#pragma once
#include <Object.hpp>

namespace geo { namespace structure { namespace point {
class Point2D_I32;
}}}
namespace geo { namespace structure { namespace shapes {
class Polygon2D_I32;
class Rectangle2D_I32;
class RectangleLength2D_I32;
}}}

using namespace geo::structure::point;
using namespace geo::structure::shapes;

namespace geo { namespace metric {
class Intersection2D_I32 {
  /**
   * Checks to see if the two rectangles intersect each other
   *
   * @param a Rectangle
   * @param b Rectangle
   * @return true if intersection
   */
  static bool intersects( Rectangle2D_I32 *a , Rectangle2D_I32 *b );
  /**
   * Finds the intersection between two rectangles.  If the rectangles don't intersect then false is returned.
   *
   * @param a Rectangle
   * @param b Rectangle
   * @param result Storage for the found intersection
   * @return true if intersection
   */
  static bool intersection( Rectangle2D_I32 *a , Rectangle2D_I32 *b ,
                            Ref<Rectangle2D_I32> result );

  /**
   * Checks to see if the point is contained inside the convex polygon.  If the
   * point is an the polygon's perimeter it is considered to NOT be inside.
   *
   * @param polygon Convex polygon. Not modified.
   * @param pt Point. Not modified.
   * @return True if the point is contained inside the polygon.
   */
  // Ported from internet code 12/2011
  // http://www.ecse.rpi.edu/Homepages/wrf/Research/Short_Notes/pnpoly.html
  static bool containConvex( Polygon2D_I32 *polygon , Point2D_I32 *pt );

  /**
   * Checks to see if the point is contained inside the concave polygon.
   *
   * NOTE: Points which lie along the perimeter may or may not be considered as inside
   *
   * @param polygon Convex polygon. Not modified.
   * @param pt Point. Not modified.
   * @return True if the point is contained inside the polygon.
   */
  static bool containConcave( Polygon2D_I32 *polygon , Point2D_I32 *pt );

  /**
   * True if the point is contained inside the rectangle
   *
   * @param a Rectangle
   * @param x x-coordinate of point
   * @param y y-coordinate of point
   * @return true if the point is inside and false it is not
   */
  static bool contains( RectangleLength2D_I32 *a, int x, int y );

  /**
   * True if the point is contained inside the rectangle
   *
   * @param a Rectangle
   * @param x x-coordinate of point
   * @param y y-coordinate of point
   * @return true if the point is inside and false it is not
   */
  static bool contains( Rectangle2D_I32 *a, int x, int y );
};

}}
