#pragma once
#include <Object.hpp>
#include <algorithm>
#include <cmath>
#include <cstdlib>

namespace geo { namespace geometry {
class UtilPoint2D_F64;
}}

namespace geo { namespace structure { namespace line {
class LineGeneral2D_F64;
class LineParametric2D_F64;
class LineSegment2D_F64;
}}}

namespace geo { namespace structure { namespace point {
class Point2D_F64;
}}}

namespace geo { namespace structure { namespace shapes {
class Polygon2D_F64;
class Quadrilateral_F64;
}}}

using namespace geo::structure::point;
using namespace geo::structure::line;
using namespace geo::structure::shapes;

namespace geo { namespace metric {

/**
 * Functions related to finding the distance of one shape from another shape.  This is often
 * closely related to finding the {@link ClosestPoint3D_F64 closest point}.
 *
 */
// TODO distance between two line segments, line lines
// handle parallel overlapping cases by returning zero
class Distance2D_F64 {
public:
  /**
   * <p>
   * Returns the Euclidean distance of the closest point on the line from a point.
   * </p>
   *
   * @param line A line segment. Not modified.
   * @param p The point. Not modified.
   * @return Distance the closest point on the line is away from the point.
   */
  static double distance( LineParametric2D_F64 *line, Point2D_F64 *p ) {
    return sqrt(distanceSq(line, p));
  }

  /**
   * <p>
   * Returns the Euclidean distance of the closest point on the line from a point.
   * </p>
   *
   * @param line A line segment. Not modified.
   * @param x Point's x-coordinate
   * @param y Point's y-coordinate
   * @return Distance the closest point on the line is away from the point.
   */
  static double distance( LineParametric2D_F64 *line, double x , double y ) {
    return sqrt(distanceSq(line, x,y));
  }

  /**
   * <p>
   * Returns the Euclidean distance squared of the closest point on the line from a point.
   * </p>
   *
   * @param line A line segment. Not modified.
   * @param p The point. Not modified.
   * @return Euclidean distance squared to the closest point on the line is away from the point.
   */
  static double distanceSq( LineParametric2D_F64 *line, Point2D_F64 *p );

  /**
   * <p>
   * Returns the Euclidean distance squared of the closest point on the line from a point.
   * </p>
   *
   * @param line A line segment. Not modified.
   * @param x Point's x-coordinate
   * @param y Point's y-coordinate
   * @return Euclidean distance squared to the closest point on the line is away from the point.
   */
  static double distanceSq( LineParametric2D_F64 *line, double x , double y );

  /**
   * <p>
   * Returns the Euclidean distance of the closest point on a line segment to the specified point.
   * </p>
   *
   * @param line A line segment. Not modified.
   * @param p The point. Not modified.
   * @return Euclidean distance of the closest point on a line is away from a point.
   */
  static double distance( LineSegment2D_F64 *line, Point2D_F64 *p ) {
    return sqrt(distanceSq(line, p));
  }

  /**
   * <p>
   * Returns the Euclidean distance of the closest point on a line segment to the specified point.
   * </p>
   *
   * @param line A line segment. Not modified.
   * @param x Point's x-coordinate
   * @param y Point's y-coordinate
   * @return Euclidean distance of the closest point on a line is away from a point.
   */
  static double distance( LineSegment2D_F64 *line, double x , double y) {
    return sqrt(distanceSq(line, x,y));
  }

  /**
   * <p>
   * Returns the Euclidean distance squared of the closest point on a line segment to the specified point.
   * </p>
   *
   * @param line A line segment. Not modified.
   * @param p The point. Not modified.
   * @return Euclidean distance squared of the closest point on a line is away from a point.
   */
  static double distanceSq( LineSegment2D_F64 *line, Point2D_F64 *p );

  /**
   * <p>
   * Returns the Euclidean distance squared of the closest point on a line segment to the specified point.
   * </p>
   *
   * @param line Line segment. Not modified.
   * @param x Point's x-coordinate
   * @param y Point's y-coordinate
   * @return Euclidean distance squared of the closest point on a line is away from a point.
   */
  static double distanceSq( LineSegment2D_F64 *line, double x , double y );


  /**
   * Finds the distance between the two line segments
   * @param segmentA Line segment. Not modified.
   * @param segmentB Line segment. Not modified.
   * @return Euclidean distance of the closest point between the two line segments.
   */
  static double distance( LineSegment2D_F64 *segmentA , LineSegment2D_F64 *segmentB ) {
    return sqrt(distanceSq(segmentA, segmentB));
  }

  /**
   * Finds the distance squared between the two line segments
   * @param segmentA Line segment. Not modified.
   * @param segmentB Line segment. Not modified.
   * @return Euclidean distance squared of the closest point between the two line segments.
   */
  static double distanceSq( LineSegment2D_F64 *segmentA , LineSegment2D_F64 *segmentB );

  /**
   * Returns the Euclidean distance of the closest point on the quadrilateral to the provided point.
   *
   * @param quad Quadrilateral
   * @param p Point
   * @return Distance apart
   */
  static double distance( Quadrilateral_F64 *quad , Point2D_F64 *p ) {
    return sqrt(distanceSq(quad,p));
  }

  /**
   * Returns the Euclidean distance squared of the closest point on the quadrilateral to the provided point.
   *
   * @param quad Quadrilateral
   * @param p Point
   * @return Distance squared apart
   */
  static double distanceSq( Quadrilateral_F64 *quad , Point2D_F64 *p );

  /**
   * Returns the Euclidean distance of the closest point on the Polygon to the provided point.
   *
   * @param poly Polygon2D
   * @param p Point
   * @return Distance squared apart
   */
  static double distance( Polygon2D_F64 *poly , Point2D_F64 *p ) {
    return sqrt(distanceSq(poly, p, Ref<LineSegment2D_F64>(0)));
  }

  /**
   * Returns the Euclidean distance squared of the closest point on the Polygon to the provided point.
   *
   * @param poly Polygon2D
   * @param p Point
   * @param storage Optional storage for linesegment which is used internally to compute the distance
   * @return Distance squared apart
   */
  static double distanceSq( Polygon2D_F64 *poly ,
                            Point2D_F64 *p , LineSegment2D_F64 *storage );

  /**
   * <p>
   * Returns the Euclidean distance of the closest point on the line to the specified point.
   * </p>
   *
   * @param line A line. Not modified.
   * @param p The point. Not modified.
   * @return Euclidean distance of the closest point on the line to the specified point.
   */
  static double distance( LineGeneral2D_F64 *line , Point2D_F64 *p );

  /**
   * <p>
   * Returns the signed Euclidean distance of the closest point on the line to the specified point.
   * The line is assumed be normalized.  See {@link LineGeneral2D_F64} for details on normalization.
   * </p>
   *
   * @param line A normalized line. Not modified.
   * @param p The point. Not modified.
   * @return Euclidean distance of the closest point on the line to the specified point.
   */
  static double distanceNorm(LineGeneral2D_F64 *line, Point2D_F64 *p);

  /**
   * Returns the distance of the closest point on the line from the origin
   * @param line Line
   * @return Euclidean distance
   */
  static double distanceOrigin( LineParametric2D_F64 *line );

  /**
   * Euclidean distance of closest point on ellipse to point 'p'.
   *
   * @param ellipse Ellipse
   * @param p Point
   * @return Euclidean distance
   */
  // static double distance(EllipseRotated_F64 ellipse , Point2D_F64 p ) {
  //   return sqrt(distance2(ellipse, p));
  // }

  /**
   * Euclidean distance squared of closest point on ellipse to point 'p'.
   *
   * @param ellipse Ellipse
   * @param p Point
   * @return Euclidean distance squared
   */
#if 0
  static double distance2(EllipseRotated_F64 ellipse , Point2D_F64 p ) {
    // put point into ellipse's reference frame
    double cphi = Math.cos(ellipse.phi);
    double sphi = Math.sin(ellipse.phi);

    double xc = p.x - ellipse.center.x;
    double yc = p.y - ellipse.center.y;
    double r = Math.sqrt(xc*xc + yc*yc);

    double x =  cphi*xc + sphi*yc;
    double y = -sphi*xc + cphi*yc;

    double ct = x/r;
    double st = y/r;

    x = ellipse.center.x + ellipse.a*ct*cphi - ellipse.b*st*sphi;
    y = ellipse.center.y + ellipse.a*ct*sphi + ellipse.b*st*cphi;

    return p.distance2(x,y);
  }
#endif
};

}}
