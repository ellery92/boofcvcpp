#pragma once
#include <Object.hpp>
#include <geo/struct/GeoTuple2D_F64.hpp>

namespace geo { namespace structure { namespace point {
class Point2D_F64;

/**
 * Spacial vector in 2D
 */
class Vector2D_F64 : public GeoTuple2D_F64<Vector2D_F64> {
  D_OBJECT(Vector2D_F64)
public:
  Vector2D_F64( Ref<GeoTuple2D_F64> orig ) {
    GeoTuple2D_F64::set(orig->x,orig->y);
  }

  Vector2D_F64( GeoTuple2D_F64 const &orig ) {
    GeoTuple2D_F64::set(orig.x,orig.y);
  }

  Vector2D_F64( double x, double y ) {
    GeoTuple2D_F64::set( x, y );
  }

  Vector2D_F64() {
  }

  Vector2D_F64( Ref<Vector2D_F64> pt ) {
    GeoTuple2D_F64::set( pt->x, pt->y );
  }

  virtual Ref<Vector2D_F64> createNewInstance() override {
    return Ref<Vector2D_F64>(new Vector2D_F64());
  }

  void set( Ref<Vector2D_F64> orig ) {
    _set( orig );
  }

  virtual void set(double x, double y) override {
    GeoTuple2D_F64::set(x, y);
  }

  virtual Ref<Vector2D_F64> copy() override {
    return Ref<Vector2D_F64>(new Vector2D_F64( *this ));
  }

  void normalize() {
    double r = norm();
    x /= r;
    y /= r;
  }

  /**
   * In-place minus operation. this = a - b.
   *
   * @param a Point
   * @param b Point
   */
  void minus( Ref<Point2D_F64> a , Ref<Point2D_F64> b );

  std::string toString() {
    return std::string("V( ") + std::to_string(x) + " " + std::to_string(y) + " )";
  }

  /**
   * Dot product between this and 'a' = this.x * a.x + this.y * a.y
   *
   * @param a A vector
   * @return dot product.
   */
  double dot( Ref<Vector2D_F64> a ) {
    return x * a->x + y * a->y;
  }

  double dot( Vector2D_F64 *a ) {
    return x * a->x + y * a->y;
  }

  /**
   * Returns the acute angle between the two vectors.  Computed using the dot product.
   * @param a Vector
   * @return Acute angle in radians between 'this' and 'a'.
   */
  double acute( Ref<Vector2D_F64> a );
};

}}}
