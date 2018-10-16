#pragma once
#include <Object.hpp>

namespace geo { namespace structure { namespace point {
class Point2D_F64;
}}}

namespace geo { namespace structure { namespace shapes {

using namespace geo::structure::point;

/**
 * An axis aligned rectangle in 2D that is specified by its lower-extent p0, and upper-extent p1.
 */
class Rectangle2D_F64 : public Object {
  D_OBJECT(Rectangle2D_F64)
public:
  Rectangle2D_F64(double x0, double y0, double x1, double y1);

  Rectangle2D_F64(Ref<Rectangle2D_F64> orig);

  void set( Ref<Rectangle2D_F64> orig );

  void set(double x0, double y0, double x1, double y1);

  Rectangle2D_F64();

	/**
	 * Makes sure x0,y0 is the lower extent and x1,y1 is the upper extent
	 */
  void enforceExtents();

  double getWidth();

  double getHeight();

  double area();

  Ref<Point2D_F64> getP0();

  void setP0(Ref<Point2D_F64> p0);

  Ref<Point2D_F64> getP1();

  void setP1(Ref<Point2D_F64> p1);

  bool equals(Ref<Rectangle2D_F64> obj);

  /**
   * Lower extent
   */
  Ref<Point2D_F64> p0_;
  /**
   * Upper extent
   */
  Ref<Point2D_F64> p1_;
};

}}}
