#include "Rectangle2D_F64.hpp"
#include <geo/struct/point/Point2D_F64.hpp>
using namespace geo::structure::point;

namespace geo { namespace structure { namespace shapes {

Rectangle2D_F64::Rectangle2D_F64(double x0, double y0, double x1, double y1) {
  set(x0,y0,x1,y1);
}

Rectangle2D_F64::Rectangle2D_F64(Ref<Rectangle2D_F64> orig) {
  set(orig);
}

void Rectangle2D_F64::set( Ref<Rectangle2D_F64> orig ) {
  p0_->set(orig->p0_);
  p1_->set(orig->p1_);
}

void Rectangle2D_F64::set(double x0, double y0, double x1, double y1) {
  p0_->set(x0,y0);
  p1_->set(x1,y1);
}

Rectangle2D_F64::Rectangle2D_F64() {
}

/**
 * Makes sure x0,y0 is the lower extent and x1,y1 is the upper extent
 */
void Rectangle2D_F64::enforceExtents() {
  if( p1_->getX() < p0_->getX() ) {
    p1_->swapX(p0_);
  }
  if( p1_->getY() < p0_->getY() ) {
    p1_->swapY(p0_);
  }
}

double Rectangle2D_F64::getWidth() {
  return p1_->getX() - p0_->getY();
}

double Rectangle2D_F64::getHeight() {
  return p1_->getY() - p0_->getY();
}

double Rectangle2D_F64::area() {
  return ( p1_->getY() - p0_->getY()) * (p1_->getX() - p0_->getX());
}

Ref<Point2D_F64> Rectangle2D_F64::getP0() {
  return p0_;
}

void Rectangle2D_F64::setP0(Ref<Point2D_F64> p0) {
  p0_ = p0;
}

Ref<Point2D_F64> Rectangle2D_F64::getP1() {
  return p1_;
}

void Rectangle2D_F64::setP1(Ref<Point2D_F64> p1) {
  p1_ = p1;
}

bool Rectangle2D_F64::equals(Ref<Rectangle2D_F64> r) {
  return p0_->getX()==r->p0_->getX()
    &&p0_->getY()==r->p0_->getY()
    &&p1_->getX()==r->p1_->getX()
    &&p1_->getY()==r->p1_->getY();
}

}}}
