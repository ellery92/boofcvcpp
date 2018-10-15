#pragma once
#include <Object.hpp>

namespace geo { namespace structure { namespace point {

/**
 * A point in 2D
 */
class Point2D_F64 : public Object {
  D_OBJECT(Point2D_F64)
public:
  virtual ~Point2D_F64() = default;
  Point2D_F64();
  Point2D_F64(double x, double y);

  bool equals(double x, double y);
  bool equals(double x, double y, double tol);
  bool equals(Ref<Point2D_F64> other, double tol);

  void set(Ref<Point2D_F64> orig);
  void set(double x, double y);
  void setX(double x);
  void setY(double y);
  double getX();
  double getY();

  void plusIP(Point2D_F64 const &other);
  Ref<Point2D_F64> plus(Point2D_F64 const &other);

  void timesIP(double scalar);
  void scale(double scalar);
  Ref<Point2D_F64> times(double scalar);

  double distance(double x, double y);
  double distance2(double x, double y);
  double distance(Ref<Point2D_F64> other);
  double distance2(Ref<Point2D_F64> other);

  double getIndex(int index);
  void setIndex(int index, double value);

  double norm();
  double normSq();
  int getDimention();

  void swapX(Ref<Point2D_F64> other);
  void swapY(Ref<Point2D_F64> other);

private:
  double x_;
  double y_;
};

}}}
