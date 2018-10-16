#pragma once
#include <Object.hpp>

namespace geo { namespace structure { namespace shapes {
/**
 * An axis aligned rectangle in 2D that is specified by its lower extent (x0,y0), width, and height.  The three
 * other corners are {@code (x0 + width-1,y0), (x0,y0 + height-1), (x0 + width-1,y0 + height-1)}.
 */
class RectangleLength2D_I32 : public Object {
  D_OBJECT(RectangleLength2D_I32);

public:
  /**
   * Lower extent x-axis
   */
  int x0;
  /**
   * Lower extent y-axis
   */
  int y0;
  /**
   * Rectangle's width
   */
  int width;
  /**
   * Rectangle's height
   */
  int height;

  RectangleLength2D_I32() {
  }

  RectangleLength2D_I32(int x0, int y0, int width, int height) {
    this->x0 = x0;
    this->y0 = y0;
    this->width = width;
    this->height = height;
  }

  void set( int tl_x, int tl_y, int width, int height ) {
    this->x0 = tl_x;
    this->y0 = tl_y;
    this->width = width;
    this->height = height;
  }

  /**
   * Sets lower extent
   *
   * @param x x-coordinate
   * @param y y-coordinate
   */
  void setLowerExtent(int x, int y) {
    this->x0 = x;
    this->y0 = y;
  }

  int getWidth() {
    return width;
  }

  void setWidth( int width ) {
    this->width = width;
  }

  int getHeight() {
    return height;
  }

  void setHeight( int height ) {
    this->height = height;
  }

  /**
   * @return Lower-extent x-coordinate
   */
  int getX() {
    return x0;
  }

  /**
   * Sets the Lower-extent x-coordinate
   *
   * @param x Lower-extentx-coordinate
   */
  void setX( int x ) {
    this->x0 = x;
  }

  /**
   * @return Lower-extent y-coordinate
   */
  int getY() {
    return y0;
  }

  /**
   * Sets the Lower-extenty-coordinate
   *
   * @param y Lower-extent y-coordinate
   */
  void setY( int y ) {
    this->y0 = y;
  }

  /**
   * Sets this rectangle to be equal to the passed in rectangle->
   * @param r Rectangle which this is to be set equal to
   */
  void set(RectangleLength2D_I32 *r) {
    this->x0 = r->x0;
    this->y0 = r->y0;
    this->width = r->width;
    this->height = r->height;
  }

  std::string toString() {
    return getClass()+"{" +
      "p=[ " + std::to_string(x0) + " , " + std::to_string(y0) +
      "], width=" + std::to_string(width) + ", height=" + std::to_string(height) + '}';
  }
};

}}}
