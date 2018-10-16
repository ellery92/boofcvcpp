#pragma once
#include <Object.hpp>
#include <string>
#include <cmath>
#include <stdexcept>
#include <vector>

namespace geo { namespace structure { namespace point {
class Point2D_F64;
}}}
namespace geo { namespace structure { namespace line {
class LineSegment2D_F64;
}}}

using namespace geo::structure::point;
using namespace geo::structure::line;

namespace geo { namespace structure { namespace shapes {
/**
 * A polygon with 4 vertices, a,b,c, and d.  The vertices are in order sequential order of a,b,c,d.
 *
 */
class Quadrilateral_F64 : public Object {
  D_OBJECT(Quadrilateral_F64);
public:
  Ref<Point2D_F64> a;
  Ref<Point2D_F64> b;
  Ref<Point2D_F64> c;
  Ref<Point2D_F64> d;

  Quadrilateral_F64();

  Quadrilateral_F64( Quadrilateral_F64 *quad );

  Quadrilateral_F64( double x0, double y0 , double x1, double y1 ,
                     double x2, double y2 , double x3, double y3 );

  Quadrilateral_F64(Point2D_F64 *a, Point2D_F64 *b, Point2D_F64 *c, Point2D_F64 *d ) {
    Quadrilateral_F64(a,b,c,d,true);
  }

  Quadrilateral_F64(Point2D_F64 *a, Point2D_F64 *b,
                    Point2D_F64 *c, Point2D_F64 *d, bool copy );

  /**
   * Returns the area of this quadrilateral
   * @return area
   */
  double area();

  Ref<Point2D_F64> get( int index ) {
    switch( index ) {
    case 0: return a;
    case 1: return b;
    case 2: return c;
    case 3: return d;
    }
    throw std::invalid_argument("Requested index out of range. "+std::to_string(index));
  }

  Ref<Point2D_F64> getA() {
    return a;
  }

  void setA(Ref<Point2D_F64> a) {
    this->a = a;
  }

  Ref<Point2D_F64> getB() {
      return b;
    }

    void setB(Ref<Point2D_F64> b) {
      this->b = b;
    }

  Ref<Point2D_F64> getC() {
      return c;
    }

  void setC(Ref<Point2D_F64> c) {
      this->c = c;
    }

  Ref<Point2D_F64> getD() {
      return d;
    }

  void setD(Ref<Point2D_F64> d) {
      this->d = d;
    }

  Ref<LineSegment2D_F64> getLine( int which, Ref<LineSegment2D_F64> storage );

  double getSideLength( int which ) {
    return sqrt(getSideLength2(which));
  }

  double getSideLength2( int which );

  void set(Quadrilateral_F64 *quad);

  /**
   * Converts the polygon into a list.
   *
   * @param storage (Optional) storage to put the vertexes into
   * @param copy If points will be copied otherwise a reference of points will be returned
   * @return List of vertexes
   */
  // std::vector<Ref<Point2D_F64> convert(std::vector<Point2D_F64> storage , boolean copy );

  /**
   * Sets the polygon to be the same as the list. A true copy is created and no references
   * to points in the list are saved.
   * @param list List which the polygon will be set to
   */
  void set( std::vector<Ref<Point2D_F64> > *list );

  Ref<Quadrilateral_F64> copy() {
    return Ref<Quadrilateral_F64>(new Quadrilateral_F64(this));
  }

  /**
   * Returns true if the two quadrilaterals are equal to each other to within tolerance.  Equality is defined
   * by seeing if the distance between two equivalent vertexes is within tolerance.
   *
   * @param quad The second quadrilateral
   * @param tol Maximum allowed distance between vertexes.
   * @return true if equals or false if not
   */
  bool isEquals( Quadrilateral_F64 *quad , double tol );

  std::string toString();
};

}}}
