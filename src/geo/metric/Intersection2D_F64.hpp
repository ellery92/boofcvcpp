#pragma once
#include <Object.hpp>

namespace geo { namespace structure { namespace shapes {
class Polygon2D_F64;
}}}

namespace geo { namespace structure { namespace point {
class Point2D_F64;
}}}


using namespace geo::structure::shapes;
using namespace geo::structure::point;

namespace geo { namespace metric {
/**
 * Functions relating to finding the points at which two shapes intersect with each other.
 *
 */
class Intersection2D_F64 {
public:
	// todo comment
	// todo how are parallel lines handled?

	/**
	 * <p>
	 * Checks to see if the point is contained inside the convex polygon.  If the
	 * point is an the polygon's perimeter it is considered to NOT be inside.
	 * </p>
	 *
	 * <p>
	 * Clockwise or counter-clockwise order of the polygon does not matter.
	 * </p>
	 *
	 * @param polygon Convex polygon. Not modified.
	 * @param pt Point. Not modified.
	 * @return True if the point is contained inside the polygon.
	 */
	// Ported from internet code 12/2011
	// http://www.ecse.rpi.edu/Homepages/wrf/Research/Short_Notes/pnpoly.html
  static bool containConvex( Polygon2D_F64 *polygon, Point2D_F64 *pt );

	/**
	 * Checks to see if the point is contained inside the concave polygon.
	 *
	 * NOTE: Points which lie along the perimeter may or may not be considered as inside
	 *
	 * @param polygon Convex polygon. Not modified.
	 * @param pt Point. Not modified.
	 * @return True if the point is contained inside the polygon.
	 */
  static bool containConcave( Polygon2D_F64 *polygon , Point2D_F64 *pt );
};

}}
