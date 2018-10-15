#include "LineSegment2D_F64.hpp"
#include <geo/struct/point/Point2D_F64.hpp>

namespace geo { namespace structure { namespace line {

LineSegment2D_F64::LineSegment2D_F64() {
}

LineSegment2D_F64::LineSegment2D_F64( Ref<Point2D_F64> a, Ref<Point2D_F64> b ) {
  set( a, b );
}

LineSegment2D_F64::LineSegment2D_F64( double x0, double y0, double x1, double y1 ) {
  set( x0, y0, x1, y1 );
}

Ref<LineSegment2D_F64>
LineSegment2D_F64::wrap( Ref<Point2D_F64> a, Ref<Point2D_F64> b ) {
  return Ref<LineSegment2D_F64>(new LineSegment2D_F64(a, b));
}

void LineSegment2D_F64::set( Ref<LineSegment2D_F64> l ) {
  a_->set(l->a_);
  b_->set(l->b_);
}

void LineSegment2D_F64::set( Ref<Point2D_F64> a, Ref<Point2D_F64> b ) {
  a_->set( a );
  b_->set( b );
}

void LineSegment2D_F64::set( double x0, double y0, double x1, double y1 ) {
  a_->set( x0, y0 );
  b_->set( x1, y1 );
}

Ref<Point2D_F64> LineSegment2D_F64::getA() {
  return a_;
}

void LineSegment2D_F64::setA( Ref<Point2D_F64> a ) {
  a_ = a;
}

Ref<Point2D_F64> LineSegment2D_F64::getB() {
  return b_;
}

void LineSegment2D_F64::setB( Ref<Point2D_F64> b ) {
  b_ = b;
}

double LineSegment2D_F64::slopeX() {
  return b_->getX() - a_->getX();
}

double LineSegment2D_F64::slopeY() {
  return b_->getY() - a_->getY();
}

double LineSegment2D_F64::getLength() {
  return a_->distance(b_);
}

double LineSegment2D_F64::getLength2() {
  return a_->distance2(b_);
}

Ref<LineSegment2D_F64> LineSegment2D_F64::copy() {
  return Ref<LineSegment2D_F64>(new LineSegment2D_F64( a_, b_ ));
}

}}}
