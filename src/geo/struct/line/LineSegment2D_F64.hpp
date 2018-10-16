#pragma once
#include <Object.hpp>

namespace geo { namespace structure { namespace point {
class Point2D_F64;
}}}

using namespace geo::structure::point;

namespace geo { namespace structure { namespace line {

/**
 * Defines a line segment by its two end points.
 *
 */
class LineSegment2D_F64 : public Object {
  D_OBJECT(LineSegment2D_F64)

public:
  LineSegment2D_F64();
  virtual ~LineSegment2D_F64() = default;

  LineSegment2D_F64( Ref<Point2D_F64> a, Ref<Point2D_F64> b );

  LineSegment2D_F64( double x0, double y0, double x1, double y1 );

  static Ref<LineSegment2D_F64> wrap( Ref<Point2D_F64> a , Ref<Point2D_F64> b );

  void set( Ref<LineSegment2D_F64>  l );

  void set( Ref<Point2D_F64>  a, Ref<Point2D_F64>  b );

  void set( double x0, double y0, double x1, double y1 );

  Ref<Point2D_F64> getA();

  void setA( Ref<Point2D_F64>  a );

  Ref<Point2D_F64> getB();

  void setB( Ref<Point2D_F64> b );

  double slopeX();

  double slopeY();

  double getLength();

  double getLength2();

  Ref<LineSegment2D_F64> copy();

  Ref<Point2D_F64> a_;
  Ref<Point2D_F64> b_;
};

}}}
