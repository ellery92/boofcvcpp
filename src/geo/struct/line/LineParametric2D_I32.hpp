#pragma once
#include <Object.hpp>

namespace geo { namespace structure { namespace point {
class Point2D_F64;
class Point2D_I32;
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
class LineParametric2D_I32 : public Object {
  D_OBJECT(LineParametric2D_I32)
public:
  /**
   * A point on the line
   */
  Ref<Point2D_I32> p;
  /**
   * The line's slope
   */
  int slopeX,slopeY;

  LineParametric2D_I32(int x_0, int y_0, int slopeX, int slopeY );

  LineParametric2D_I32(Ref<Point2D_I32> p, int slopeX, int slopeY );

  LineParametric2D_I32() {
  }

  void set( Ref<LineParametric2D_I32> line );

  void setPoint( Ref<Point2D_I32> pt );

  void setPoint( int x, int y );

  void setSlope( int slopeX , int slopeY ) {
    this->slopeX = slopeX;
    this->slopeY = slopeY;
  }

  /**
   * Returns a point along the line.  See parametric equation in class description.
   *
   * @param t Location along the line.
   * @return Point on the line.
   */
  Ref<Point2D_F64> getPointOnLine( double t );

  Ref<Point2D_I32> getPoint() {
    return p;
  }

  int getSlopeX() {
    return slopeX;
  }

  int getSlopeY() {
    return slopeY;
  }

  int getX();

  int getY();

  Ref<Point2D_I32> getP() {
    return p;
  }

  void setP(Ref<Point2D_I32> p) {
    this->p = p;
  }

  Ref<LineParametric2D_I32> copy() {
    return Ref<LineParametric2D_I32>(new LineParametric2D_I32( p, slopeX, slopeY ));
  }

  std::string toString();
};

}}}
