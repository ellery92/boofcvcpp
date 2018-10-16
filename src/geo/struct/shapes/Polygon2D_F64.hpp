#pragma once
#include <Object.hpp>

namespace geo { namespace geometry {
class UtilPolygons2D_F64;
}}
namespace geo { namespace metric {
class Area2D_F64;
class Intersection2D_F64;
}}
namespace geo { namespace structure { namespace  line {
class LineSegment2D_F64;
}}}
namespace geo { namespace structure { namespace point {
class Point2D_F64;
}}}

#include <vector>

using namespace geo::geometry;
using namespace geo::structure::line;
using namespace geo::structure::point;
using namespace geo::metric;

namespace geo { namespace structure { namespace shapes {
/**
 * Describes a polygon in 2D.
 *
 */
class Polygon2D_F64 : public Object {
  D_OBJECT(Polygon2D_F64);
public:

  // vertexes in the polygon
  std::vector<Ref<Point2D_F64> > vertexes;

  Polygon2D_F64( double *a, int length);

  Polygon2D_F64( Polygon2D_F64 *a );

  Polygon2D_F64( int numVertexes );

  Polygon2D_F64() {}

  void set( Polygon2D_F64 *orig );

  void set( int index , double x , double y );

  /**
   * Resturns the length of the specified side that is composed of point index and index+1
   * @return Euclidean length of the side
   */
  double getSideLength( int index );

  Ref<Point2D_F64> get( int index ) {
    return vertexes[index];
  }

  int size() {
    return vertexes.size();
  }

  Ref<Polygon2D_F64> copy() {
    return Ref<Polygon2D_F64>(new Polygon2D_F64(this));
  }

  /**
   * Returns the area for simply polygons.  Non-self intersecting convex or concave.
   * @return area
   */
  double areaSimple();

  /**
   * Returns true if the point is inside the polygon.  Points along the border are ambiguously considered inside
   * or outside.
   *
   * @see Intersection2D_F64#containConcave(Polygon2D_F64, Point2D_F64)
   * @see Intersection2D_F64#containConcave(Polygon2D_F64, Point2D_F64)
   *
   * @param p A point
   * @return true if inside and false if outside
   */
  bool isInside( Point2D_F64 *p );

  /**
   * true if the order of vertexes is in counter clockwise order.
   * @return true if ccw or false if cw
   */
  bool isCCW();

  bool isConvex();

  bool isIdentical( Polygon2D_F64 *a , double tol );

  bool isEquivalent( Polygon2D_F64 *a , double tol );

  void flip();

  /**
   * Returns the line/edge defined by vertex index and index+1.
   * @param index Index of the line
   * @return A new instance of the line segment.
   */
  Ref<LineSegment2D_F64> getLine( int index , Ref<LineSegment2D_F64> storage );

  /**
   * Converts the polygon into a list.
   *
   * @param storage (Optional) storage to put the vertexes into
   * @param copy If points will be copied otherwise a reference of points will be returned
   * @return List of vertexes
   */
  // List<Point2D_F64> convert( @Nullable List<Point2D_F64> storage , boolean copy );

  /**
   * Sets the polygon to be the same as the list. A true copy is created and no references
   * to points in the list are saved.
   * @param list List which the polygon will be set to
   */
  void set( std::vector<Ref<Point2D_F64> > &list );

  std::string toString();
};

}}}
