#include "UtilPolygons2D_I32.hpp"

#include <vector>
#include <limits>

using namespace geo::structure::point;
using namespace geo::structure::shapes;
using namespace geo::geometry;

void UtilPolygons2D_I32::bounding( std::vector<Point2D_I32> const &points ,
                                   Rectangle2D_I32 &rectangle ) {

  rectangle.x0 = std::numeric_limits<int>::max();
  rectangle.y0 = std::numeric_limits<int>::max();
  rectangle.x1 = std::numeric_limits<int>::min();
  rectangle.y1 = std::numeric_limits<int>::min();

  for( int i = 0; i < points.size(); i++ ) {
    const Point2D_I32 &p = points[i];

    if( p.x < rectangle.x0 )
      rectangle.x0 = p.x;
    if( p.x > rectangle.x1 )
      rectangle.x1 = p.x;
    if( p.y < rectangle.y0 )
      rectangle.y0 = p.y;
    if( p.y > rectangle.y1 )
      rectangle.y1 = p.y;
  }

  rectangle.x1++;
  rectangle.y1++;
}

void UtilPolygons2D_I32::bounding( Polygon2D_I32 const &quad , Rectangle2D_I32 &rectangle ) {

  UtilPolygons2D_I32.bounding(quad.vertexes, rectangle);
}

bool UtilPolygons2D_I32::isCCW( std::vector<Point2D_I32> &polygon ) {
  const int N = polygon.size();
  int sign = 0;
  for (int i = 0; i < N; i++) {
    int j = (i+1)%N;
    int k = (i+2)%N;

    if( isPositiveZ(polygon[i], polygon[j], polygon[k]) ) {
      sign++;
    } else {
      sign--;
    }
  }

  return sign < 0;
}

void UtilPolygons2D_I32::flip( Polygon2D_I32 &a ) {
  int N = a.size();
  int H = N/2;

  for (int i = 1; i <= H; i++) {
    int j = N-i;
    Point2D_I32 tmp = a.vertexes[i];
    a.vertexes[i] = a.vertexes[j];
    a.vertexes[j] = tmp;
  }
}

bool UtilPolygons2D_I32::isConvex( Polygon2D_I32 const &poly ) {
  // if the cross product of all consecutive triples is positive or negative then it is convex

  const int N = poly.size();
  int numPositive = 0;
  for (int i = 0; i < N; i++) {
    int j = (i+1)%N;
    int k = (i+2)%N;

    const Point2D_I32 &a = poly.vertexes[i];
    const Point2D_I32 &b = poly.vertexes[j];
    const Point2D_I32 &c = poly.vertexes[k];

    int dx0 = a.x-b.x;
    int dy0 = a.y-b.y;

    int dx1 = c.x-b.x;
    int dy1 = c.y-b.y;

    int z = dx0 * dy1 - dy0 * dx1;
    if( z > 0 )
      numPositive++;
    // z can be zero if there are duplicate points.
    // not sure if it should throw an exception if its "bad" or not
  }

  return( numPositive == 0 || numPositive == N );
}

bool UtilPolygons2D_I32::isPositiveZ(Point2D_I32 const &a,
                                     Point2D_I32 const &b,
                                     Point2D_I32 const &c  ) {
  int dx0 = a.x-b.x;
  int dy0 = a.y-b.y;

  int dx1 = c.x-b.x;
  int dy1 = c.y-b.y;

  int z = dx0 * dy1 - dy0 * dx1;

  return z > 0 ;
}

bool UtilPolygons2D_I32::isIdentical(Polygon2D_I32 const &a , Polygon2D_I32 const &b  ) {
  if( a.size() != b.size())
    return false;

  for (int i = 0; i < a.size(); i++) {
    if( !a.get(i).equals(b.get(i))  )
      return false;
  }
  return true;
}

bool UtilPolygons2D_I32::isEquivalent( Polygon2D_I32 const &a , Polygon2D_I32 const &b  ) {
  if( a.size() != b.size())
    return false;

  // first find two vertexes which are the same
  const Point2D_I32 &a0 = a.get(0);
  int match = -1;
  for (int i = 0; i < b.size(); i++) {
    if( a0.equals(b.get(i)) ) {
      match = i;
      break;
    }
  }

  if( match < 0 )
    return false;

  // now go in a circle and see if they all line up
  for (int i = 1; i < b.size(); i++) {
    const Point2D_I32 &ai = a.get(i);
    const Point2D_I32 &bi = b.get((match+i)%b.size());

    if( !ai.equals(bi)  ) {
      return false;
    }
  }
  return true;
}
