#pragma once
#include <Object.hpp>

namespace geo { namespace structure { namespace point {
class Point2D_I32;
}}}

using namespace geo::structure::point;

namespace geo { namespace structure { namespace line {

/**
 * Defines a line segment by its two end points.
 *
 */
class LineSegment2D_I32 : public Object {
  D_OBJECT(LineSegment2D_I32)

  public:
  LineSegment2D_I32();

  LineSegment2D_I32( Ref<Point2D_I32> a, Ref<Point2D_I32> b );

  LineSegment2D_I32( int x0, int y0, int x1, int y1 );

  static Ref<LineSegment2D_I32> wrap( Ref<Point2D_I32> a , Ref<Point2D_I32> b );

  void set( Ref<LineSegment2D_I32>  l );

  void set( Ref<Point2D_I32>  a, Ref<Point2D_I32>  b );

  void set( int x0, int y0, int x1, int y1 );

  Ref<Point2D_I32> getA();

  void setA( Ref<Point2D_I32>  a );

  Ref<Point2D_I32> getB();

  void setB( Ref<Point2D_I32> b );

  int slopeX();

  int slopeY();

  double getLength();

  int getLength2();

  Ref<LineSegment2D_I32> copy();

private:
  Ref<Point2D_I32> a_;
  Ref<Point2D_I32> b_;
};

}}}
