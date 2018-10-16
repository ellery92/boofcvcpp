#include "UtilPolygons2D_I32.hpp"

#include <geo/struct/shapes/Rectangle2D_I32.hpp>
#include <geo/struct/point/Point2D_I32.hpp>
#include <geo/struct/shapes/Polygon2D_I32.hpp>

#include <vector>
#include <limits>

using namespace geo::structure::point;
using namespace geo::structure::shapes;
using namespace geo::geometry;

void UtilPolygons2D_I32::bounding( std::vector<Ref<Point2D_I32> > const &points,
                                   Rectangle2D_I32 &rectangle ) {

  rectangle.x0_ = std::numeric_limits<int>::max();
  rectangle.y0_ = std::numeric_limits<int>::max();
  rectangle.x1_ = std::numeric_limits<int>::min();
  rectangle.y1_ = std::numeric_limits<int>::min();

  for( int i = 0; i < points.size(); i++ ) {
    Point2D_I32 *p = points[i].get();

    if( p->x_ < rectangle.x0_ )
      rectangle.x0_ = p->x_;
    if( p->x_ > rectangle.x1_ )
      rectangle.x1_ = p->x_;
    if( p->y_ < rectangle.y0_ )
      rectangle.y0_ = p->y_;
    if( p->y_ > rectangle.y1_ )
      rectangle.y1_ = p->y_;
  }

  rectangle.x1_++;
  rectangle.y1_++;
}

void UtilPolygons2D_I32::bounding( Ref<Polygon2D_I32> quad , Ref<Rectangle2D_I32> rectangle ) {
  UtilPolygons2D_I32::bounding(quad->vertexes, *rectangle);
}

bool UtilPolygons2D_I32::isCCW( std::vector<Ref<Point2D_I32> > &polygon ) {
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

void UtilPolygons2D_I32::flip( Polygon2D_I32 *a ) {
  int N = a->size();
  int H = N/2;

  for (int i = 1; i <= H; i++) {
    int j = N-i;
    Ref<Point2D_I32> tmp = a->vertexes[i];
    a->vertexes[i] = a->vertexes[j];
    a->vertexes[j] = tmp;
  }
}

bool UtilPolygons2D_I32::isConvex( Polygon2D_I32 *poly ) {
  // if the cross product of all consecutive triples is positive or negative then it is convex

  const int N = poly->size();
  int numPositive = 0;
  for (int i = 0; i < N; i++) {
    int j = (i+1)%N;
    int k = (i+2)%N;

    Point2D_I32 *a = poly->vertexes[i].get();
    Point2D_I32 *b = poly->vertexes[j].get();
    Point2D_I32 *c = poly->vertexes[k].get();

    int dx0 = a->x_-b->x_;
    int dy0 = a->y_-b->y_;

    int dx1 = c->x_-b->x_;
    int dy1 = c->y_-b->y_;

    int z = dx0 * dy1 - dy0 * dx1;
    if( z > 0 )
      numPositive++;
    // z can be zero if there are duplicate points.
    // not sure if it should throw an exception if its "bad" or not
  }

  return( numPositive == 0 || numPositive == N );
}

bool UtilPolygons2D_I32::isPositiveZ(Point2D_I32 const *a,
                                     Point2D_I32 const *b,
                                     Point2D_I32 const *c) {
  int dx0 = a->x_-b->x_;
  int dy0 = a->y_-b->y_;

  int dx1 = c->x_-b->x_;
  int dy1 = c->y_-b->y_;

  int z = dx0 * dy1 - dy0 * dx1;

  return z > 0 ;
}

bool UtilPolygons2D_I32::isIdentical(Polygon2D_I32 *a , Ref<Polygon2D_I32> b  ) {
  if( a->size() != b->size())
    return false;

  for (int i = 0; i < a->size(); i++) {
    if( !a->get(i)->equals(b->get(i))  )
      return false;
  }
  return true;
}

bool UtilPolygons2D_I32::isEquivalent( Polygon2D_I32 *a , Ref<Polygon2D_I32> b) {
  if( a->size() != b->size())
    return false;

  // first find two vertexes which are the same
  Point2D_I32 *a0 = a->get(0).get();
  int match = -1;
  for (int i = 0; i < b->size(); i++) {
    if( a0->equals(b->get(i)) ) {
      match = i;
      break;
    }
  }

  if( match < 0 )
    return false;

  // now go in a circle and see if they all line up
  for (int i = 1; i < b->size(); i++) {
    Point2D_I32 *ai = a->get(i).get();
    Ref<Point2D_I32> bi = b->get((match+i)%b->size());

    if( !ai->equals(bi)  ) {
      return false;
    }
  }
  return true;
}
