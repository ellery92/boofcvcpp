#include "Point2D_F64.hpp"
#include <cmath>
#include <stdexcept>

namespace geo { namespace structure { namespace point {

Point2D_F64::Point2D_F64() {
  set(0.0, 0.0);
}

Point2D_F64::Point2D_F64(double x, double y) {
  set(x, y);
}

bool Point2D_F64::equals(double x, double y) {
  return x_ == x && y_ == y;
}

bool Point2D_F64::equals(double x, double y, double tol) {
  return abs(x_ - x) <= tol && abs(y_ - y) < tol;
}

bool Point2D_F64::equals(Ref<Point2D_F64> other, double tol) {
  return abs(x_ - other->x_) <= tol && abs(y_ - other->y_) < tol;
}

void Point2D_F64::set(Ref<Point2D_F64> orig) {
  x_ = orig->x_;
  y_ = orig->y_;
}

void Point2D_F64::set(double x, double y) {
  x_ = x;
  y_ = y;
}

void Point2D_F64::setX(double x) {
  x_ = x;
}

void Point2D_F64::setY(double y) {
  y_ = y;
}

double Point2D_F64::getX() {
  return x_;
}

double Point2D_F64::getY() {
  return y_;
}

void Point2D_F64::plusIP(const Point2D_F64& other) {
  x_ += other.x_;
  y_ += other.y_;
}

Ref<Point2D_F64> Point2D_F64::plus(const Point2D_F64& other) {
  Ref<Point2D_F64> b(new Point2D_F64());
  b->set(other.x_ + x_, other.y_ + y_);
  return b;
}

void Point2D_F64::timesIP(double scalar) {
  x_ *= scalar;
  y_ *= scalar;
}

void Point2D_F64::scale(double scalar) {
  x_ *= scalar;
  y_ *= scalar;
}

Ref<Point2D_F64> Point2D_F64::times(double scalar) {
  Ref<Point2D_F64> b(new Point2D_F64());
  b->x_ = x_ * scalar;
  b->y_ = y_ * scalar;
  return b;
}

double Point2D_F64::distance(double x, double y) {
  double dx = x - x_;
  double dy = y - y_;
  return sqrt(dx*dx + dy*dy);
}

double Point2D_F64::distance2(double x, double y) {
  double dx = x - x_;
  double dy = y - y_;
  return dx*dx + dy*dy;
}

double Point2D_F64::distance(Ref<Point2D_F64> other) {
  double dx = other->x_ - x_;
  double dy = other->y_ - y_;
  return sqrt(dx*dx + dy*dy);
}

double Point2D_F64::distance2(Ref<Point2D_F64> other) {
  double dx = other->x_ - x_;
  double dy = other->y_ - y_;
  return (dx*dx + dy*dy);
}

double Point2D_F64::getIndex(int index) {
  switch (index) {
  case 0:
    return x_;
  case 1:
    return y_;
  default:
    throw std::invalid_argument("Invalid index_");
  }
  return 0.0;
}

void Point2D_F64::setIndex(int index, double value) {
  switch (index) {
  case 0:
    x_ = value;
    break;
  case 1:
    y_ = value;
    break;
  default:
    throw std::invalid_argument("Invalid index");
  }
}

double Point2D_F64::norm() {
  return sqrt(x_*x_ + y_*y_);
}

double Point2D_F64::normSq() {
  return x_*x_ + y_*y_;
}

int Point2D_F64::getDimention() {
  return 2;
}

void Point2D_F64::swapX(Ref<Point2D_F64> other) {
  std::swap(x_, other->x_);
}

void Point2D_F64::swapY(Ref<Point2D_F64> other) {
  std::swap(y_, other->y_);
}


}}}
