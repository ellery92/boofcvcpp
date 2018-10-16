#pragma once
#include <Object.hpp>

namespace geo { namespace structure { namespace shapes {

/**
 * An axis aligned rectangle in 2D that is specified by its lower extent (x0,y0), and upper extent (x1,y1).
 * x0 &le; x1 and y0 &le; y1.  (x1,y1) is exclusive and not contained in the rectangle.
 */
class Rectangle2D_I32 : public Object {
  D_OBJECT(Rectangle2D_I32);
public:
  Rectangle2D_I32(int x0, int y0, int x1, int y1);

  Rectangle2D_I32(Ref<Rectangle2D_I32> orig);

  void set( Ref<Rectangle2D_I32> orig );

  void set(int x0, int y0, int x1, int y1);

  Rectangle2D_I32();

  /**
   * Makes sure x0,y0 is the lower extent and x1,y1 is the upper extent
   */
  void enforceExtents();

  int getWidth();

  int getHeight();

  int area();

  int getX0();

  void setX0(int x0);

  int getY0();

  void setY0(int y0);

  int getX1();

  void setX1(int x1);

  int getY1();

  void setY1(int y1);

  bool equals(Ref<Rectangle2D_I32> r);

  /**
   * Lower extent
   */
  int x0_,y0_;
  /**
   * Upper extent
   */
  int x1_,y1_;
};

}}}
