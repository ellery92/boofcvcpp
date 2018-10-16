#include "Polygon2D_I32.hpp"
#include <geo/struct/point/Point2D_I32.hpp>
#include <geo/geometry/UtilPolygons2D_I32.hpp>
#include <stdexcept>

using namespace geo::geometry;

Polygon2D_I32::Polygon2D_I32( int numVertexes ) {
  vertexes = std::vector<Ref<Point2D_I32> >(numVertexes);
  for (int i = 0; i < numVertexes; i++) {
    vertexes[i] = Ref<Point2D_I32>(new Point2D_I32());
  }
}

Polygon2D_I32::Polygon2D_I32( int *points, int length ) {
  if( length % 2 == 1 )
    throw std::invalid_argument("Expected an even number");
  vertexes = std::vector<Ref<Point2D_I32> >(length / 2);

  int count = 0;
  for (int i = 0; i < length; i += 2) {
    vertexes[count] = Ref<Point2D_I32>(new Point2D_I32());
    vertexes[count]->set( points[i],points[i+1]);
    count++;
  }
}

void Polygon2D_I32::flip() {
  UtilPolygons2D_I32::flip(this);
}

bool Polygon2D_I32::isCCW() {
  return UtilPolygons2D_I32::isCCW(vertexes);
}

bool Polygon2D_I32::isConvex() {
  return UtilPolygons2D_I32::isConvex(this);
}

bool Polygon2D_I32::isIdentical( Ref<Polygon2D_I32> a ) {
  return UtilPolygons2D_I32::isIdentical(this, a);
}

bool Polygon2D_I32::isEquivalent( Ref<Polygon2D_I32> a , double tol ) {
  return UtilPolygons2D_I32::isEquivalent(this, a);
}

void Polygon2D_I32::set( Ref<Polygon2D_I32> orig ) {
  vertexes.resize(orig->size());
  for (int i = 0; i < orig->size(); i++) {
    vertexes[i]->set( orig->vertexes[i]);
  }
}

void Polygon2D_I32::set( int index , int x , int y ) {
  vertexes[index]->set(x,y);
}
