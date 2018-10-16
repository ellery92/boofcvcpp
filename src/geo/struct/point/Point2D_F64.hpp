#pragma once
#include <Object.hpp>
#include <geo/struct/GeoTuple2D_F64.hpp>

namespace geo { namespace structure { namespace point {

/**
 * A point in 2D
 */
class Point2D_F64 : public GeoTuple2D_F64<Point2D_F64> {
  D_OBJECT(Point2D_F64)
public:
  virtual ~Point2D_F64() = default;
  Point2D_F64() {
  }

  Point2D_F64(Ref<GeoTuple2D_F64> orig) {
    GeoTuple2D_F64::set(orig->x, orig->y);
  }

  Point2D_F64(double x, double y) {
    GeoTuple2D_F64::set(x, y);
  }

  Point2D_F64(Ref<Point2D_F64> pt) {
    GeoTuple2D_F64::set(pt->x, pt->y);
  }

  Point2D_F64(Point2D_F64 *pt) {
    GeoTuple2D_F64::set(pt->x, pt->y);
  }

  void set(Ref<Point2D_F64> orig) {
    _set(orig);
  }

  void set(Point2D_F64 *orig) {
    GeoTuple2D_F64::set(orig->x, orig->y);
  }

  virtual void set(double x, double y) override {
    GeoTuple2D_F64::set(x, y);
  }

  void swapX(Ref<Point2D_F64> other);
  void swapY(Ref<Point2D_F64> other);

  virtual Ref<Point2D_F64> copy() override {
    return Ref<Point2D_F64>(new Point2D_F64(x, y));
  }

  virtual Ref<Point2D_F64> createNewInstance() override {
    return Ref<Point2D_F64>(new Point2D_F64());
  }
};

}}}
