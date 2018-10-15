#include "LineSegment2D_I32.hpp"
#include <geo/struct/point/Point2D_I32.hpp>

namespace geo { namespace structure { namespace line {

LineSegment2D_I32::LineSegment2D_I32() {
}

LineSegment2D_I32::LineSegment2D_I32( Ref<Point2D_I32> a, Ref<Point2D_I32> b ) {
  set( a, b );
}

LineSegment2D_I32::LineSegment2D_I32( int x0, int y0, int x1, int y1 ) {
  set( x0, y0, x1, y1 );
}

Ref<LineSegment2D_I32>
LineSegment2D_I32::wrap( Ref<Point2D_I32> a, Ref<Point2D_I32> b ) {
  return Ref<LineSegment2D_I32>(new LineSegment2D_I32(a, b));
}

void LineSegment2D_I32::set( Ref<LineSegment2D_I32> l ) {
  a_->set(l->a_);
  b_->set(l->b_);
}

void LineSegment2D_I32::set( Ref<Point2D_I32> a, Ref<Point2D_I32> b ) {
  a_->set( a );
  b_->set( b );
}

void LineSegment2D_I32::set( int x0, int y0, int x1, int y1 ) {
  a_->set( x0, y0 );
  b_->set( x1, y1 );
}

Ref<Point2D_I32> LineSegment2D_I32::getA() {
  return a_;
}

void LineSegment2D_I32::setA( Ref<Point2D_I32> a ) {
  a_ = a;
}

Ref<Point2D_I32> LineSegment2D_I32::getB() {
  return b_;
}

void LineSegment2D_I32::setB( Ref<Point2D_I32> b ) {
  b_ = b;
}

int LineSegment2D_I32::slopeX() {
  return b_->getX() - a_->getX();
}

int LineSegment2D_I32::slopeY() {
  return b_->getY() - a_->getY();
}

double LineSegment2D_I32::getLength() {
  return a_->distance(b_);
}

int LineSegment2D_I32::getLength2() {
  return a_->distance2(b_);
}

Ref<LineSegment2D_I32> LineSegment2D_I32::copy() {
  return Ref<LineSegment2D_I32>(new LineSegment2D_I32( a_, b_ ));
}

}}}
