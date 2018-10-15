#pragma once
#include <geo/struct/GeoTuple.hpp>
#include <cmath>
#include <stdexcept>

namespace geo { namespace structure {

/**
 * Describes geometric objects that are composed of N double values.  Where N is the dimension
 * of space the object is contained in.  Points and vectors are two examples of a GeoTuple.  Each
 * value is the value of the object along a dimension in the space it occupies.
 *
 */
template<typename T>
class GeoTuple_F64 : public GeoTuple<T> {
  D_OBJECT(GeoTuple_F64)
public:
  /**
   * Checks to see if the two GeoTuple have values which are nearly the same.  False is always
   * returned if the dimension is different.
   *
   * @param t   The GeoTuple it is being compared against.
   * @param tol How similar each element must be for them to be considered identical.
   * @return if they are identical or not.
   */
  bool isIdentical( Ref<T> t, double tol ) {
    if( t->getDimension() != this->getDimension() )
      return false;

    int N = this->getDimension();
    for( int i = 0; i < N; i++ ) {
      double diff = abs( this->getIndex( i ) - t->getIndex( i ) );

      if( diff > tol )
        return false;
    }

    return true;
  }

  /**
   * Generic copy routine.  It is recommended that this be overridden with a faster implementation.
   *
   * @return An exact copy of this GeoTuple.
   */
  Ref<T> copy() {
    Ref<T> ret = this->createNewInstance();

    int N = this->getDimension();
    for( int i = 0; i < N; i++ ) {
      ret->setIndex( i, this->getIndex( i ) );
    }

    return ret;
  }

  /**
   * Computes the  Euclidean norm.
   *
   * @return norm.
   */
  virtual double norm() {
    return (float) sqrt( normSq() );
  }

  /**
   * Computes the square of the Euclidean norm.
   *
   * @return norm squared.
   */
  virtual double normSq() {
    double total = 0;
    int N = this->getDimension();
    for( int i = 0; i < N; i++ ) {
      double a = this->getIndex( i );
      total += a * a;
    }

    return total;
  }

  double distance( T t ) {
    return sqrt( distance2( t ) );
  }

  double distance2( T t ) {
    if( t.getDimension() != this->getDimension() )
      throw std::invalid_argument( "Dimension of input tuple does not match" );

    double total = 0;
    const int N = this->getDimension();
    for( int i = 0; i < N; i++ ) {
      double diff = abs( this->getIndex( i ) - t.getIndex( i ) );

      total += diff * diff;
    }

    return total;
  }

  /**
   * Returns the value of the tuple along the specified coordinate system axis.
   *
   * @param index Which axis in the coordinate system.
   * @return Its value.
   */
  virtual double getIndex( int index ) = 0;

  virtual void setIndex( int index, double value ) = 0;

  virtual bool equals(Ref<GeoTuple_F64<T> > obj) {
    if( this->getClass() != obj->getClass() )
      return false;
    Ref<GeoTuple_F64<T> > p = obj;
    const int N = this->getDimension();

    if( N != p->getDimension() )
      return false;
    for( int i = 0; i < N; i++ ) {
      if( this->getIndex(i) != p->getIndex(i))
        return false;
    }
    return true;
  }
};


}}
