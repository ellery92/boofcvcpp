#pragma once
#include <Object.hpp>
#include <cmath>

namespace geo { namespace structure { namespace line {
/**
 * <p>
 * Represents the line using three parameters such that any point on the line obeys the
 * following formula, A*x + B*y + C = 0.  Any 2D line can be represented using this notation.
 * This formulation is also known as standard and implicit.  The slope is -A/B.
 * </p>
 * <p>
 * If it is said the line is normalized that refers to it being scaled such that A*A + B*B = 1.  To
 * normalize a line call {@link #normalize()}.  After normalization several operations become less expensive.
 * </p>
 *
 */
class LineGeneral2D_F64 : public Object {
  D_OBJECT(LineGeneral2D_F64);
public:
  /**
   * Coefficients which define the line.
   */
  double A,B,C;

  /**
   * A*x + B*y + C = 0
   *
   * @param a parameter A
   * @param b parameter B
   * @param c parameter C
   */
  LineGeneral2D_F64(double a, double b, double c) {
    set(a,b,c);
  }

  LineGeneral2D_F64(LineGeneral2D_F64 *line ) {
    set(line);
  }

  LineGeneral2D_F64(Ref<LineGeneral2D_F64> line ) {
    set(line);
  }

  LineGeneral2D_F64() {
  }

  double getA() {
    return A;
  }

  double getB() {
    return B;
  }

  double getC() {
    return C;
  }

  void set( Ref<LineGeneral2D_F64> original ) {
    set(original.get());
  }

  void set( LineGeneral2D_F64 *original ) {
    this->A = original->A;
    this->B = original->B;
    this->C = original->C;
  }

  /**
   * A*x + B*y + C = 0
   *
   * @param a parameter A
   * @param b parameter B
   * @param c parameter C
   */
  void set(double a, double b, double c) {
    this->A = a;
    this->B = b;
    this->C = c;
  }

  void setA(double a) {
    A = a;
  }

  void setB(double b) {
    B = b;
  }

  void setC(double c) {
    C = c;
  }

  /**
   * Ensures that A*A + B*B == 1
   */
  void normalize() {
    double d = sqrt(A*A + B*B);
    A /= d;
    B /= d;
    C /= d;
  }

  /**
   * Returns the result of A*x + B*y + C.  If the line is normalized then this is also the signed distance
   * away from the line.
   *
   * @param x x-coordinate of a point
   * @param y y-coordinate of a point
   * @return result of line equation
   */
  double evaluate( double x , double y ) {
    return A*x + B*y + C;
  }

  Ref<LineGeneral2D_F64> copy() {
    return Ref<LineGeneral2D_F64>(new LineGeneral2D_F64(this));
  }

  std::string toString() {
    return getClass()+"{ A="+std::to_string(A)+" B="+std::to_string(B)+" C="
      +std::to_string(C)+" }";
  }
};
}}}
