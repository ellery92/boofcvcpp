#pragma once

#include <Object.hpp>

namespace geo { namespace structure { namespace point{
class Point2D_F64;
}}}

namespace geo { namespace structure { namespace shapes {
class Polygon2D_F64;
class Quadrilateral_F64;
}}}

using namespace geo::structure::point;
using namespace geo::structure::shapes;

namespace geo { namespace metric {

class Area2D_F64 {
public:
	/**
	 * Computes the area of an arbitrary triangle from 3-vertices.
	 *
	 * area = | a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y) | / 2
	 *
	 * @param a Corner point 1
	 * @param b Corner point 2
	 * @param c Corner point 3
	 * @return area
	 */
  static double triangle( Point2D_F64 *a, Point2D_F64 *b, Point2D_F64  *c );

	/**
	 * Area of a quadrilateral computed from two triangles.
	 *
	 * @param quad quadrilateral
	 * @return area
	 */
  static double quadrilateral( Quadrilateral_F64 *quad );

	/**
	 * Area of a simple polygon.  Meaning it can be concave or convex, but can't have self intersections
	 * @param poly Simple polygon
	 * @return area
	 */
  static double polygonSimple( Polygon2D_F64 *poly );
};

}}
