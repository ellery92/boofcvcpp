#include "Rectangle2D_I32.hpp"
#include <algorithm>

namespace geo { namespace structure { namespace shapes {

Rectangle2D_I32::Rectangle2D_I32(int x0, int y0, int x1, int y1) {
  set(x0,y0,x1,y1);
}

Rectangle2D_I32::Rectangle2D_I32(Ref<Rectangle2D_I32> orig) {
  set(orig);
}

void Rectangle2D_I32::set( Ref<Rectangle2D_I32> orig ) {
  x0_ = orig->x0_;
  this->y0_ = orig->y0_;
  x1_ = orig->x1_;
  y1_ = orig->y1_;
}

void Rectangle2D_I32::set(int x0, int y0, int x1, int y1) {
  x0_ = x0;
  y0_ = y0;
  x1_ = x1;
  y1_ = y1;
}

Rectangle2D_I32::Rectangle2D_I32() {
  set(0, 0, 0, 0);
}

/**
 * Makes sure x0,y0 is the lower extent and x1,y1 is the upper extent
 */
void Rectangle2D_I32::enforceExtents() {
  if( x1_ < x0_ ) {
    std::swap(x0_, x1_);
  }
  if( y1_ < y0_ ) {
    std::swap(y1_, y0_);
  }
}

int Rectangle2D_I32::getWidth() {
  return x1_-x0_;
}

int Rectangle2D_I32::getHeight() {
  return y1_-y0_;
}

int Rectangle2D_I32::area() {
  return (y1_-y0_)*(x1_-x0_);
}

int Rectangle2D_I32::getX0() {
  return x0_;
}

void Rectangle2D_I32::setX0(int x0) {
  x0_ = x0;
}

int Rectangle2D_I32::getY0() {
  return y0_;
}

void Rectangle2D_I32::setY0(int y0) {
  y0_ = y0;
}

int Rectangle2D_I32::getX1() {
  return x1_;
}

void Rectangle2D_I32::setX1(int x1) {
  x1_ = x1;
}

int Rectangle2D_I32::getY1() {
  return y1_;
}

void Rectangle2D_I32::setY1(int y1) {
  y1 = y1;
}

bool Rectangle2D_I32::equals(Ref<Rectangle2D_I32> r) {
  return x0_==r->x0_&&y0_==r->y0_&&x1_==r->x1_&&y1_==r->y1_;
}

}}}
