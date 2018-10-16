#pragma once
#include <Object.hpp>

namespace geo { namespace structure { namespace line {
class LineGeneral2D_F64;
class LineParametric2D_F64;
class LinePolar2D_F64;
class LineSegment2D_F64;
}}}

namespace geo { namespace structure { namespace point {
class Point2D_F64;
}}}

using namespace geo::structure::line;
using namespace geo::structure::point;

namespace geo { namespace geometry {
/**
 * Various functions related to lines
 *
 * @author Peter Abeles
 */
class UtilLine2D_F64 {
public:
  /**
   * Returns the acute angle between the slope of two lines.  Lines do not need to ever
   * intersect.  Found using the dot product.
   *
   * @param a (input) line
   * @param b (input) line
   * @return acute angle in radians
   */
  static double acuteAngle( LineGeneral2D_F64 *a , LineGeneral2D_F64 *b );

  /**
   * Returns the acute angle between the slope of two lines and assumes that the lines have
   * been normalized such that A*A + B*B = 1.  This avoids the need to compute the square root
   * twice.  Lines do not need to ever intersect.  Found using the dot product.
   *
   * @param a (input) normalized line
   * @param b (input) normalized line
   * @return acute angle in radians
   */
  static double acuteAngleN( LineGeneral2D_F64 *a , LineGeneral2D_F64 *b );

  /**
   * Converts a line from polar form to parametric.
   *
   * @param src (input) line is polar notation
   * @param ret (output) line in parametric notation.  If null a new instance will be created.
   * @return Converted line in parametric notation
   */
  static Ref<LineParametric2D_F64>
  convert( LinePolar2D_F64 *src ,
           Ref<LineParametric2D_F64> ret = Ref<LineParametric2D_F64>(0));

  /**
   * Converts a line from polar form to general.  After conversion the line will be normalized, e.g. A*A + B*B == 1.
   *
   * @param src (input) line is polar notation
   * @param ret (output) line in general notation.  If null a new instance will be created.
   * @return Converted line in general notation
   */
  static Ref<LineGeneral2D_F64>
  convert( LinePolar2D_F64 *src ,
           Ref<LineGeneral2D_F64> ret = Ref<LineGeneral2D_F64>(0));

  /**
   * Converts a line from general to polar.
   *
   * @param src (input) line is general notation
   * @param ret (output) line in polar notation.  If null a new instance will be created.
   * @return Converted line in polar notation
   */
  static Ref<LinePolar2D_F64>
  convert( LineGeneral2D_F64 *src ,
           Ref<LinePolar2D_F64> ret = Ref<LinePolar2D_F64>(0));

  /**
   * Converts a line segment into a parametric line.  The start point will be 'src.a' and the
   * direction will be in the direction of 'src.b-src.a'
   *
   * @param src (input) line segment
   * @param ret (output) line in parametric notation.  If null a new instance will be created.
   * @return Converted line in parametric notation
   */
  static Ref<LineParametric2D_F64>
  convert( LineSegment2D_F64 *src ,
           Ref<LineParametric2D_F64> ret = Ref<LineParametric2D_F64>(0));

  /**
   * Converts a line segment into a general line.
   *
   * @param src (Input) line segment
   * @param ret (output) line in general notation. If null a new instance will be created.
   * @return Line in general notation
   */
  static Ref<LineGeneral2D_F64>
  convert( LineSegment2D_F64 *src,
           Ref<LineGeneral2D_F64> ret = Ref<LineGeneral2D_F64>(0));

  /**
   * Converts a line segment into a general line. Line segment is defined by two points.
   *
   * @param a (Input) End point of line segment
   * @param b (Input) End point of line segment
   * @param ret (output) line in general notation. If null a new instance will be created.
   * @return Line in general notation
   */
  static Ref<LineGeneral2D_F64>
  convert( Ref<Point2D_F64> a , Ref<Point2D_F64> b ,
           Ref<LineGeneral2D_F64> ret = Ref<LineGeneral2D_F64>(0));

  /**
   * Converts a line segment into a line in parametric format. It will point from a to b. Point a and b must
   * be unique.
   *
   * @param a (Input) End point of line segment
   * @param b (Input) End point of line segment
   * @param ret (output) Storage for new line.. If null a new instance will be created.
   * @return The resulting line
   */
  static Ref<LineParametric2D_F64>
  convert( Ref<Point2D_F64> a , Ref<Point2D_F64> b ,
           Ref<LineParametric2D_F64> ret = Ref<LineParametric2D_F64>(0));

  /**
   * Converts a line from parametric to polar.
   *
   * @param src (Input) line in parametric notation
   * @param ret (output) line in polar notation. If null a new instance will be created.
   * @return Line in polar notation
   */
  static Ref<LinePolar2D_F64>
  convert( LineParametric2D_F64 *src, Ref<LinePolar2D_F64> ret = Ref<LinePolar2D_F64>(0));

  /**
   * Converts a line from parametric to general
   *
   * @param src (input) line in parametric notation.
   * @param ret (output) line in general notation.  If null a new instance will be created.
   * @return Converted line in general notation
   */
  static Ref<LineGeneral2D_F64>
  convert( LineParametric2D_F64 *src,
           Ref<LineGeneral2D_F64> ret = Ref<LineGeneral2D_F64>(0));

  /**
   * Converts a line from general to parametric
   *
   * @param src (input) line in general notation.
   * @param ret (output) line in parametric notation.  If null a new instance will be created.
   * @return Converted line in parametric notation
   */
  static Ref<LineParametric2D_F64>
  convert( LineGeneral2D_F64 *src,
           Ref<LineParametric2D_F64> ret = Ref<LineParametric2D_F64>(0));
};

}}
