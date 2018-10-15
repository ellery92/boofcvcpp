#include "Point2D_I32.hpp"
#include <cmath>

namespace geo { namespace structure { namespace point {

Point2D_I32::Point2D_I32(int x, int y) {
  x_ = x;
  y_= y;
}

Point2D_I32::Point2D_I32(Ref<Point2D_I32> orig) {
  x_ = orig->x_;
  y_ = orig->y_;
}

Point2D_I32::Point2D_I32() {
  x_ = 0;
  y_ = 0;
}

void Point2D_I32::set(Ref<Point2D_I32> v) {
  x_ = v->x_;
  y_ = v->y_;
}

void Point2D_I32::set( int x, int y ) {
  x_ = x;
  y_ = y;
}

void Point2D_I32::setX(int x) {
  x_ = x;
}

void Point2D_I32::setY(int y) {
  y_ = y;
}

int Point2D_I32::getX() {
  return x_;
}

int Point2D_I32::getY() {
  return y_;
}

double Point2D_I32::distance( Ref<Point2D_I32> a ) {
  int dx = x_-a->x_;
  int dy = y_-a->y_;

  return sqrt(dx*dx + dy*dy);
}

double Point2D_I32::distance( int x , int y ) {
  int dx = x_-x;
  int dy = y_-y;

  return sqrt(dx*dx + dy*dy);
}

int Point2D_I32::distance2( Ref<Point2D_I32> a ) {
  int dx = x_-a->x_;
  int dy = y_-a->y_;

  return dx*dx + dy*dy;
}

int Point2D_I32::distance2( int x , int y ) {
  int dx = x-x_;
  int dy = y-y_;

  return dx*dx + dy*dy;
}

bool Point2D_I32::equals(Ref<Point2D_I32> p) const {
  return x_==p->x_&&y_==p->y_;
}

int Point2D_I32::getDimension() {
  return 2;
}

Ref<Point2D_I32> Point2D_I32::createNewInstance() {
  return Ref<Point2D_I32>(new Point2D_I32());
}

Ref<Point2D_I32> Point2D_I32::copy() {
  return Ref<Point2D_I32>(new Point2D_I32(x_, y_));
}

}}}
