#pragma once
#include <geo/struct/GeoTuple.hpp>

/**
 * An integer 2D point
 */

namespace geo { namespace structure { namespace point {

class Point2D_I32 : public GeoTuple<Point2D_I32> {
  D_OBJECT(Point2D_I32)

public:
  virtual ~Point2D_I32() = default;

  Point2D_I32(int x, int y);

  Point2D_I32(Ref<Point2D_I32> orig);

  Point2D_I32();

  void set(Ref<Point2D_I32> v);

  void set( int x, int y );

  void setX(int x);

  void setY(int y);

  int getX();

  int getY();

  double distance( Ref<Point2D_I32> a );

  double distance( int x , int y );

  /**
   * <p>
   * Returns the Euclidean distance squared from 'this' to 'a'.  No floating point
   * operations are used.
   * </p>
   *
   * <p>
   * d<sup>2</sup> =  (x-a.x)<sup>2</sup> + (y-a.y)<sup>2</sup>
   * </p>
   *
   * @param a Point that distance is computed from.
   * @return Euclidean distance squared.
   */
  int distance2( Ref<Point2D_I32> a );

  int distance2( int x , int y );

  bool equals(Ref<Point2D_I32> p) const;

  virtual int getDimension() override;

  virtual Ref<Point2D_I32> createNewInstance() override;

  virtual Ref<Point2D_I32> copy() override;


  int x_;
  int y_;
};

}}}
