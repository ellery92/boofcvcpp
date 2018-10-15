#pragma once
#include <vector>
#include <geo/struct/point/Point2D_I32.hpp>
#include <geo/geometry/UtilPolygons2D_I32.hpp>

using namespace geo::structure::point;
// using namespace geo::geometry;

namespace geo { namespace structure { namespace shapes {

class Polygon2D_I32 : public Object {
public:
  std::vector<Point2D_I32> vertexes;

  Polygon2D_I32( int numVertexes ) {
    vertexes = std::vector<Point2D_I32>(numVertexes);
  }

  Polygon2D_I32() {
  }

  Polygon2D_I32( Polygon2D_I32 const &original ) {
    set(original);
  }

  Polygon2D_I32( int *points, int length ) {
    if( length % 2 == 1 )
      throw std::invalid_argument("Expected an even number");
    vertexes = std::vector<Point2D_I32>(length / 2);
    Point2D_I32 *data = vertexes.data();

    int count = 0;
    for (int i = 0; i < length; i += 2) {
      data[count++].set( points[i],points[i+1]);
    }
  }

  int size() const {
    return vertexes.size();
  }

  const Point2D_I32 &get(int index ) const {
    return vertexes[index];
  }

  void flip() {
    UtilPolygons2D_I32::flip(*this);
  }

  bool isCCW() {
    return UtilPolygons2D_I32::isCCW(vertexes);
  }

  bool isConvex() {
    return UtilPolygons2D_I32::isConvex(this);
  }

  bool isIdentical( Polygon2D_I32 const &a ) {
    return UtilPolygons2D_I32::isIdentical(*this, a);
  }

  bool isEquivalent( Polygon2D_I32 const &a , double tol ) {
    return UtilPolygons2D_I32::isEquivalent(*this, a);
  }

  void set( Polygon2D_I32 const &orig ) {
    vertexes.resize(orig.size());
    for (int i = 0; i < orig.size(); i++) {
      vertexes[i].set( orig.vertexes[i]);
    }
  }

  void set( int index , int x , int y ) {
    vertexes[index].set(x,y);
  }

  //  Polygon2D_I32 clone() {
  //    return new Polygon2D_I32(this);
  // }
};

}}}
