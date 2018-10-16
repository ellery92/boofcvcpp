#include "Quadrilateral_F64.hpp"

#include <geo/struct/point/Point2D_F64.hpp>
#include <geo/struct/line/LineSegment2D_F64.hpp>
#include <geo/metric/Area2D_F64.hpp>

using namespace geo::metric;

namespace geo { namespace structure { namespace shapes {

Quadrilateral_F64::Quadrilateral_F64() {
  a = Ref<Point2D_F64>(new Point2D_F64());
  b = Ref<Point2D_F64>(new Point2D_F64());
  c = Ref<Point2D_F64>(new Point2D_F64());
  d = Ref<Point2D_F64>(new Point2D_F64());
}

Quadrilateral_F64::Quadrilateral_F64( Quadrilateral_F64 *quad ) {
  Quadrilateral_F64();
  a->set(quad->a);
  b->set(quad->b);
  c->set(quad->c);
  d->set(quad->d);
}

Quadrilateral_F64::Quadrilateral_F64( double x0, double y0 , double x1, double y1 ,
                                      double x2, double y2 , double x3, double y3 ) {
  a = Ref<Point2D_F64>(new Point2D_F64(x0,y0));
  b = Ref<Point2D_F64>(new Point2D_F64(x1,y1));
  c = Ref<Point2D_F64>(new Point2D_F64(x2,y2));
  d = Ref<Point2D_F64>(new Point2D_F64(x3,y3));
}

Quadrilateral_F64::Quadrilateral_F64(Point2D_F64 *a, Point2D_F64 *b,
                                     Point2D_F64 *c, Point2D_F64 *d, bool copy ) {
  if( copy ) {
    this->a = Ref<Point2D_F64>(new Point2D_F64(a));
    this->b = Ref<Point2D_F64>(new Point2D_F64(b));
    this->c = Ref<Point2D_F64>(new Point2D_F64(c));
    this->d = Ref<Point2D_F64>(new Point2D_F64(d));
  } else {
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
  }
}

double Quadrilateral_F64::area() {
  return Area2D_F64::quadrilateral(this);
}

Ref<LineSegment2D_F64>
Quadrilateral_F64::getLine( int which, Ref<LineSegment2D_F64> storage ) {
  if( !storage )
    storage = Ref<LineSegment2D_F64>(new LineSegment2D_F64());

  switch( which ) {
  case 0: storage->a_->set(a);storage->b_->set(b);break;
  case 1: storage->a_->set(b);storage->b_->set(c);break;
  case 2: storage->a_->set(c);storage->b_->set(d);break;
  case 3: storage->a_->set(d);storage->b_->set(a);break;
  default:
    throw std::invalid_argument(std::string("Requested index out of range. ")
                                +std::to_string(which));
  }
  return storage;
}

double Quadrilateral_F64::getSideLength2( int which ) {
  switch( which ) {
  case 0: return a->distance2(b);
  case 1: return b->distance2(c);
  case 2: return c->distance2(d);
  case 3: return d->distance2(a);
  default:
    throw std::invalid_argument("Requested index out of range. "+std::to_string(which));
  }
}

void Quadrilateral_F64::set(Quadrilateral_F64 *quad) {
  this->a->set(quad->a);
  this->b->set(quad->b);
  this->c->set(quad->c);
  this->d->set(quad->d);
}

void Quadrilateral_F64::set( std::vector<Ref<Point2D_F64> > *list ) {
  if( list->size() != 4 )
    throw std::invalid_argument("List must have size of 4");

  a->set(list->at(0));
  b->set(list->at(1));
  c->set(list->at(2));
  d->set(list->at(3));
}

bool Quadrilateral_F64::isEquals( Quadrilateral_F64 *quad , double tol ) {
  tol *= tol;

  if( a->distance2(quad->a) > tol )
    return false;
  if( b->distance2(quad->b) > tol )
    return false;
  if( c->distance2(quad->c) > tol )
    return false;
  return d->distance2(quad->d) <= tol;
}

std::string Quadrilateral_F64::toString() {
  return getClass()+"{ a("+std::to_string(a->x)+" "+std::to_string(a->y)
    +") b("+std::to_string(b->x)+" "+std::to_string(b->y)+") c("+
    std::to_string(c->x)+" "+std::to_string(c->y)+") d("+
    std::to_string(d->x)+" "+std::to_string(d->y)+") }";
}

}}}
