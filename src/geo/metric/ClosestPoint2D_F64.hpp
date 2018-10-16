#pragma once
#include <Object.hpp>
#include <geo/misc/GrlConstants.hpp>

namespace geo { namespace structure { namespace line {
class LineGeneral2D_F64;
class LineParametric2D_F64;
class LineSegment2D_F64;
}}}

namespace geo { namespace structure { namespace point {
class Point2D_F64;
}}}

using namespace geo::structure::line;
using namespace geo::structure::point;

namespace geo { namespace metric {

/**
 * Functions related to finding the closest point(s) on one shape from another shape.
 *
 */
class ClosestPoint2D_F64 {
public:
  /**
   * <p>
   * Finds the closest point on 'line' to the specified point.
   * </p>
   *
   * @param line Line along which the closest point is to be found.
   * @param p Point.
   * @param output Where the solution is stored.  If null a new instance is created. Modified.
   * @return Closest point on the line.
   */
  static Ref<Point2D_F64> closestPoint( LineGeneral2D_F64 *line,
                                        Point2D_F64 *p,
                                        Ref<Point2D_F64> output = Ref<Point2D_F64>(0));

  /**
   * <p>
   * Finds the closest point on 'line' to the specified point.
   * </p>
   *
   * @param line	Line along which the closest point is being found.
   * @param p	   Point.
   * @param output Where the solution is stored.  If null a new instance is created. Modified.
   * @return Closest point on the line.
   */
  static Ref<Point2D_F64> closestPoint( LineParametric2D_F64 *line,
                                        Point2D_F64 *p,
                                        Ref<Point2D_F64> output = Ref<Point2D_F64>(0));

  /**
   * <p>
   * Computes the closest point along the line as a function of 't':<br>
   * [x, y] = [x_0, y_0] + t·[slopeX, slopeY]
   * </p>
   *
   * @param line The line along which the closest point is being found. Not modified.
   * @param p	A point. Not modified.
   * @return Distance as a function of 't'
   */
  static double closestPointT( LineParametric2D_F64 *line,
                               Point2D_F64 *p );

  /**
   * <p>
   * Computes the closest point along the line as a function of 't':<br>
   * [x, y] = [x_0, y_0] + t·[slopeX, slopeY]
   * </p>
   *
   * @param line The line along which the closest point is being found. Not modified.
   * @param x Point's x-coordinate
   * @param y Point's y-coordinate
   * @return Distance as a function of 't'
   */
  static double closestPointT( LineParametric2D_F64 *line, double x, double y);

  /**
   * Finds the closest point on the line segment to the provided point 'p'.
   *
   * @param line Line segment
   * @param p Point`
   * @param output Optional storage for the closet point on the line to p.  If null a new instance is created.
   * @return Closest point on the line to the point
   */
  static Ref<Point2D_F64> closestPoint( LineSegment2D_F64 *line,
                                        Point2D_F64 *p,
                                        Ref<Point2D_F64> output = Ref<Point2D_F64>(0));

};

}}
