#pragma once

namespace geo { namespace structure { namespace point {
class Point2D_F64;
class Vector2D_F64;
}}}

using namespace geo::structure::point;

namespace geo { namespace geometry {

class UtilVector2D_F64 {
public:
  /**
   * Returns the acute angle between the two vectors.  Computed using the dot product.
   * @param a vector
   * @param b vector
   * @return acute angle
   */
  static double acute( double ax , double ay, double bx , double by );
  static double acute( Vector2D_F64 *a , Vector2D_F64 *b );

  /**
   * Sets the vector equal to 'a' - 'b'.
   *
   * @param a point
   * @param b point
   * @param output (output) optional storage for vector.
   * @return Solution
   */
  static void minus( Point2D_F64 *a, Point2D_F64 *b, Vector2D_F64 *output);

  /**
   * Tests to see if the two vectors are identical up to a sign difference
   * @param xa x-component of vector 'a'
   * @param ya y-component of vector 'a'
   * @param xb x-component of vector 'b'
   * @param yb y-component of vector 'b'
   * @param tol Tolerance in Euclidan distance
   * @return true if identical to within tolerance and a sign ambiguity
   */
  static bool identicalSign( double xa , double ya , double xb , double yb , double tol );

};

}}
