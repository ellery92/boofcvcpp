#pragma once
#include <Object.hpp>

namespace geo { namespace structure { namespace shapes {
/**
 * An axis aligned rectangle in 2D that is specified by its lower extent (x0,y0), width, and height.  The three
 * other corners are {@code (x0 + width-1,y0), (x0,y0 + height-1), (x0 + width-1,y0 + height-1)}.
 */
class RectangleLength2D_F64 : public Object {
  D_OBJECT(RectangleLength2D_F64);

public:
  /**
   * Lower extent x-axis
   */
  double x0;
  /**
   * Lower extent y-axis
   */
  double y0;
  /**
   * Rectangle's width
   */
  double width;
  /**
   * Rectangle's height
   */
  double height;

  RectangleLength2D_F64() {
  }

  RectangleLength2D_F64(double x0, double y0, double width, double height) {
    this->x0 = x0;
    this->y0 = y0;
    this->width = width;
    this->height = height;
  }

  void set( double tl_x, double tl_y, double width, double height ) {
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
  void setLowerExtent(double x, double y) {
    this->x0 = x;
    this->y0 = y;
  }

  double getWidth() {
    return width;
  }

  void setWidth( double width ) {
    this->width = width;
  }

  double getHeight() {
    return height;
  }

  void setHeight( double height ) {
    this->height = height;
  }

  /**
   * @return Lower-extent x-coordinate
   */
  double getX() {
    return x0;
  }

  /**
   * Sets the Lower-extent x-coordinate
   *
   * @param x Lower-extentx-coordinate
   */
  void setX( double x ) {
    this->x0 = x;
  }

  /**
   * @return Lower-extent y-coordinate
   */
  double getY() {
    return y0;
  }

  /**
   * Sets the Lower-extenty-coordinate
   *
   * @param y Lower-extent y-coordinate
   */
  void setY( double y ) {
    this->y0 = y;
  }

  /**
   * Sets this rectangle to be equal to the passed in rectangle->
   * @param r Rectangle which this is to be set equal to
   */
  void set(RectangleLength2D_F64 *r) {
    this->x0 = r->x0;
    this->y0 = r->y0;
    this->width = r->width;
    this->height = r->height;
  }

  std::string toString() {
    return getClass()+"{" +
      "p=[ " + std::to_string(x0) + " , " +
      "], width=" + std::to_string(width) + ", height=" + std::to_string(height) + '}';
  }
};

}}}
