#pragma once
#include <Object.hpp>
#include <vector>

namespace geo { namespace structure { namespace point {
class Point2D_I32;
}}}

using namespace geo::structure::point;

namespace geo { namespace structure { namespace shapes {

class Polygon2D_I32 : public Object {
  D_OBJECT(Polygon2D_I32);
public:
  // vertexes in the polygon
  std::vector<Ref<Point2D_I32> > vertexes;

  Polygon2D_I32( int numVertexes );

  Polygon2D_I32() {
  }

  virtual ~Polygon2D_I32() = default;

  Polygon2D_I32( Ref<Polygon2D_I32> original ) {
    set(original);
  }

  Polygon2D_I32( int *points, int length );

  int size() const {
    return vertexes.size();
  }

  Ref<Point2D_I32> get(int index ) {
    return vertexes[index];
  }

  void flip();

  bool isCCW();

  bool isConvex();

  bool isIdentical( Ref<Polygon2D_I32> a );

  bool isEquivalent( Ref<Polygon2D_I32> a , double tol );

  void set( Ref<Polygon2D_I32> orig );

  void set( int index , int x , int y );

  Ref<Polygon2D_I32> clone() {
    Ref<Polygon2D_I32> c(new Polygon2D_I32());
    *c = *this;
    return c;
  }
};

}}}
