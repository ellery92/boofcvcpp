#pragma once
#include <Object.hpp>

namespace geo { namespace structure { namespace point {
class Point2D_F64;
class Vector2D_F64;
}}}

using namespace geo::structure::point;

namespace geo { namespace structure { namespace line {
/**
 * <p>
 * 2D line parameterized using parametric equation:<br>
 * [x, y] = [x_0, y_0] + tÂ·[slopeX, slopeY]<br>
 * where t specifies the location along the line, (x_0,y_0) is an arbitrary point on the line,
 * and (slopeX,slopeY).
 * </p>
 */
class LineParametric2D_F64 : public Object {
  D_OBJECT(LineParametric2D_F64)
public:
  /**
   * A point on the line
   */
  Ref<Point2D_F64> p;
  /**
   * The line's slope
   */
  Ref<Vector2D_F64> slope;

  LineParametric2D_F64(double x_0, double y_0, double slopeX, double slopeY );

  LineParametric2D_F64(Ref<Point2D_F64> p, Ref<Vector2D_F64> slope);

  LineParametric2D_F64(Ref<Point2D_F64> a, Ref<Point2D_F64> b);

  LineParametric2D_F64() {
  }

  void set( Ref<LineParametric2D_F64> line );

  void setPoint( Ref<Point2D_F64> pt );

  void setPoint( double x, double y );

  void setSlope( Ref<Vector2D_F64> slope) {
    this->slope = slope;
  }

  void setSlope( double slopeX , double slopeY );

  /**
   * Sets the slope to the unit vector specified by the provided angle.
   *
   * @param angle Angle of the line specified in radians.
   */
  void setAngle( double angle );

  double getAngle();

  /**
   * Returns a point along the line.  See parametric equation in class description.
   *
   * @param t Location along the line.
   * @return Point on the line.
   */
  Ref<Point2D_F64> getPointOnLine( double t );

  Ref<Point2D_F64> getPoint() {
    return p;
  }

  int getSlopeX();

  int getSlopeY();

  int getX();

  int getY();

  Ref<Point2D_F64> getP() {
    return p;
  }

  void setP(Ref<Point2D_F64> p) {
    this->p = p;
  }

  Ref<Vector2D_F64> getSlope() {
    return slope;
  }

  Ref<LineParametric2D_F64> copy() {
    return Ref<LineParametric2D_F64>(new LineParametric2D_F64( p, slope ));
  }

  std::string toString();
};

}}}
