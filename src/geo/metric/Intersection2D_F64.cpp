#include "Intersection2D_F64.hpp"

#include <geo/struct/point/Point2D_F64.hpp>
#include <geo/struct/shapes/Polygon2D_F64.hpp>

namespace geo { namespace metric {

bool Intersection2D_F64::containConvex( Polygon2D_F64 *polygon, Point2D_F64 *pt )
{
  const int N = polygon->size();

  bool c = false;
  for (int i = 0, j = N-1; i < N; j = i++) {
    Ref<Point2D_F64> &a = polygon->vertexes[i];
    Ref<Point2D_F64> &b = polygon->vertexes[j];

    if ( ((a->y>pt->y) != (b->y>pt->y)) && (pt->x < (b->x-a->x) * (pt->y-a->y) / (b->y-a->y) + a->x) )
      c = !c;
  }
  return c;
}

bool Intersection2D_F64::containConcave( Polygon2D_F64 *polygon , Point2D_F64 *pt )
{
  const int N = polygon->size();

  int left=0;
  int right=0;
  for (int i = 0; i < N-1; i++) {
    Ref<Point2D_F64> &a = polygon->vertexes[i];
    Ref<Point2D_F64> &b = polygon->vertexes[i+1];

    if( (pt->y >= a->y && pt->y < b->y) || (pt->y >= b->y && pt->y < a->y) ) {
      // location of line segment along x-axis at y = pt->y
      double x = b->y==a->y ? pt->x : (pt->y-a->y)*(b->x-a->x)/(b->y-a->y) + a->x;

      if( x <= pt->x )
        left++;
      else if( x > pt->x )
        right++;
    }
  }

  Ref<Point2D_F64> &a = polygon->vertexes[N-1];
  Ref<Point2D_F64> &b = polygon->vertexes[0];

  if( (pt->y >= a->y && pt->y < b->y) || (pt->y >= b->y && pt->y < a->y) ) {
    // location of line segment along x-axis at y = pt->y
    double x = b->y==a->y ? pt->x : (pt->y-pt->y)*(b->x-a->x)/(b->y-a->y) + a->x;

    if( x <= pt->x )
      left++;
    else if( x > pt->x )
      right++;
  }

  return (left % 2 == 1 && right % 2 == 1);
}

}}
