#include "Polygon2D_F64.hpp"
#include <stdexcept>
#include <geo/struct/point/Point2D_F64.hpp>
#include <geo/struct/line/LineSegment2D_F64.hpp>

#include <geo/metric/Area2D_F64.hpp>
#include <geo/metric/Intersection2D_F64.hpp>
#include <geo/geometry/UtilPolygons2D_F64.hpp>

using namespace geo::metric;

namespace geo { namespace structure { namespace shapes {

Polygon2D_F64::Polygon2D_F64( double *points, int length) {
  if( length % 2 == 1 )
    throw std::invalid_argument("Expected an even number");

  Polygon2D_F64(length/2);

  int count = 0;
  for (int i = 0; i < length; i += 2) {
    vertexes[count++]->set( points[i], points[i+1]);
  }
}

Polygon2D_F64::Polygon2D_F64( Polygon2D_F64 *a ) {
  vertexes = std::vector<Ref<Point2D_F64> >(a->size());
  for (int i = 0; i < a->size(); i++) {
    vertexes[i] = Ref<Point2D_F64>(new Point2D_F64());
    vertexes[i]->set(a->get(i));
  }
}

Polygon2D_F64::Polygon2D_F64( int numVertexes ) {
  vertexes = std::vector<Ref<Point2D_F64> >(numVertexes);
  for (int i = 0; i < numVertexes; i++) {
    vertexes[i] = Ref<Point2D_F64>(new Point2D_F64());
  }
}

void Polygon2D_F64::set( Polygon2D_F64 *orig ) {
  vertexes = std::vector<Ref<Point2D_F64> >(orig->size());
  for (int i = 0; i < orig->size(); i++) {
    vertexes[i] = Ref<Point2D_F64>(new Point2D_F64());
    vertexes[i]->set( orig->vertexes[i]);
  }
}

void Polygon2D_F64::set( int index , double x , double y ) {
  vertexes[index]->set(x,y);
}

double Polygon2D_F64::getSideLength( int index ) {
  Ref<Point2D_F64> a = vertexes[index];
  Ref<Point2D_F64> b = vertexes[(index+1)%vertexes.size()];

  return (double)a->distance(b);
}

double Polygon2D_F64::areaSimple() {
  return Area2D_F64::polygonSimple(this);
}

bool Polygon2D_F64::isInside( Point2D_F64 *p ) {
  if( isConvex() ) {
    return Intersection2D_F64::containConvex(this,p);
  } else {
    return Intersection2D_F64::containConcave(this,p);
  }
  return false;
}

bool Polygon2D_F64::isCCW() {
  return UtilPolygons2D_F64::isCCW(vertexes);
}

bool Polygon2D_F64::isConvex() {
  return UtilPolygons2D_F64::isConvex(this);
}

bool Polygon2D_F64::isIdentical( Polygon2D_F64 *a , double tol ) {
  return UtilPolygons2D_F64::isIdentical(this,a,tol);
}

bool Polygon2D_F64::isEquivalent( Polygon2D_F64 *a , double tol ) {
  return UtilPolygons2D_F64::isEquivalent(this, a, tol);
}

void Polygon2D_F64::flip() {
  UtilPolygons2D_F64::flip(this);
}

Ref<LineSegment2D_F64> Polygon2D_F64::getLine( int index , Ref<LineSegment2D_F64> storage ) {
  if( !storage )
    storage = Ref<LineSegment2D_F64> (new LineSegment2D_F64());

  int j = (index+1)%vertexes.size();

  storage->a_->set(get(index));
  storage->b_->set(get(j));

  return storage;
}

void Polygon2D_F64::set( std::vector<Ref<Point2D_F64> > &list ) {
  vertexes = std::vector<Ref<Point2D_F64> >(list.size());
  for (int i = 0; i < list.size(); i++) {
    vertexes[i] = Ref<Point2D_F64>(new Point2D_F64());
    vertexes[i]->set( list[i]);
  }
}

std::string Polygon2D_F64::toString() {
  std::string out = getClass()+"{ order "
    +std::to_string(vertexes.size())+" : vertexes [ ";

  for (int i = 0; i < vertexes.size(); i++) {
    Ref<Point2D_F64> p = vertexes[i];
    out += std::to_string(p->x)+" , "+std::to_string(p->y)+" ; ";
  }

  out += " ] }";

  return out;
}

}}}
