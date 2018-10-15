#pragma once
#include <geo/struct/GeoTuple_F64.hpp>

#include <iostream>

namespace geo {namespace structure {

/**
 * Generic Tuple for geometric objects that store (x,y)
 */
template<typename T>
class GeoTuple2D_F64 : public GeoTuple_F64<T> {
  D_OBJECT(GeoTuple_F64)
public:
  double x;
  double y;

  GeoTuple2D_F64( double x, double y ) {
    this->x = x;
    this->y = y;
  }

  GeoTuple2D_F64() {
  }

  void _set( Ref<GeoTuple2D_F64> a ) {
    x = a->x;
    y = a->y;
  }

  void set( double x, double y ) {
    this->x = x;
    this->y = y;
  }

  bool isIdentical( double x, double y ) {
    return this->x == x && this->y == y;
  }

  bool isIdentical( double x, double y, double tol ) {
    return ( abs( this->x - x ) <= tol && abs( this->y - y ) <= tol );
  }

  bool isIdentical( T t, double tol ) {
    return ( abs( this->x - t.x ) <= tol && abs( this->y - t.y ) <= tol );
  }

  void setX( double x ) {
    this->x = x;
  }

  void setY( double y ) {
    this->y = y;
  }

  double getX() {
    return x;
  }

  double getY() {
    return y;
  }

  /**
   * <p>In-place addition</p>
   *
   * this->x = this->x + a.x;
   *
   * @param a value which is to be added
   */
  void plusIP( Ref<GeoTuple2D_F64> a ) {
    x += a->x;
    y += a->y;
  }

  /**
   * <p>Addition</p>
   *
   * ret.x = this->x + a.x;
   *
   * @param a value which is to be added
   */
  T plus( Ref<GeoTuple2D_F64> a ) {
    Ref<T> ret = this->createNewInstance();
    ret->x = x + a->x;
    ret->y = y + a->y;
    return ret;
  }

  /**
   * In-place scalar multiplication
   * @param scalar value that it is multiplied by
   */
  void timesIP( double scalar ) {
    x *= scalar;
    y *= scalar;
  }

  /**
   * In-place scalar multiplication
   * @param scalar value that it is multiplied by
   */
  void scale( double scalar ) {
    x *= scalar;
    y *= scalar;
  }

  /**
   * Scalar multiplication
   * @param scalar value which is it multiplied by
   * @return new matrix which is the original scaled
   */
  T times( double scalar ) {
    T ret = this->createNewInstance();
    ret.x = x*scalar;
    ret.y = y*scalar;
    return ret;
  }

  /**
   * Euclidean distance from the point
   * @param x x-coordinate
   * @param y y-coordinate
   * @return distance
   */
  double distance( double x , double y ) {
    double dx = x - this->x;
    double dy = y - this->y;

    return sqrt(dx*dx + dy*dy);
  }

  /**
   * Euclidean squared distance from the point
   * @param x x-coordinate
   * @param y y-coordinate
   * @return distance squared
   */
  double distance2( double x , double y ) {
    double dx = x - this->x;
    double dy = y - this->y;

    return dx*dx + dy*dy;
  }

  double distance( T t ) {
    double dx = t.x - x;
    double dy = t.y - y;

    return sqrt( dx * dx + dy * dy );
  }

  double distance2( T t ) {
    double dx = t.x - x;
    double dy = t.y - y;

    return dx * dx + dy * dy;
  }

  double getIndex( int index ) {
    switch( index ) {
    case 0:
      return x;

    case 1:
      return y;

    default:
      throw std::invalid_argument( "Invalid index" );
    }
  }

  void setIndex( int index, double value ) {
    switch( index ) {
    case 0:
      x = value;
      break;

    case 1:
      y = value;
      break;

    default:
      throw std::invalid_argument( "Invalid index" );
    }
  }

  virtual double norm() override {
    return sqrt( x * x + y * y );
  }

  virtual double normSq() override {
    return x * x + y * y;
  }

  virtual int getDimension() override {
    return 2;
  }

  void print() {
    std::cout << "(" << x << "," << y << ")";
  }

  virtual bool equals(Ref<Object> obj) override {
    if( this->getClass() != obj->getClass() )
      return false;
    Ref<GeoTuple2D_F64> p = (Ref<GeoTuple2D_F64>)obj;
    return x==p->x&&y==p->y;
  }
};

}}
