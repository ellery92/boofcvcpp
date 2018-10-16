#include "Intersection2D_I32.hpp"

#include <geo/struct/point/Point2D_I32.hpp>
#include <geo/struct/shapes/Polygon2D_I32.hpp>
#include <geo/struct/shapes/Rectangle2D_I32.hpp>
#include <geo/struct/shapes/RectangleLength2D_I32.hpp>
#include <algorithm>

namespace geo { namespace metric {

bool Intersection2D_I32::intersects( Rectangle2D_I32 *a , Rectangle2D_I32 *b ) {
  return( a->x0_ < b->x1_ && a->x1_ > b->x0_ && a->y0_ < b->y1_ && a->y1_ > b->y0_ );
}

bool Intersection2D_I32::intersection( Rectangle2D_I32 *a ,
                                       Rectangle2D_I32 *b ,
                                       Ref<Rectangle2D_I32> result ) {
  if( !intersects(a,b) )
    return false;

  result->x0_ = std::max(a->x0_,b->x0_);
  result->x1_ = std::min(a->x1_, b->x1_);
  result->y0_ = std::max(a->y0_,b->y0_);
  result->y1_ = std::min(a->y1_,b->y1_);

  return true;
}

bool Intersection2D_I32::containConvex( Polygon2D_I32 *polygon , Point2D_I32 *pt )
{
  const int N = polygon->size();

  bool c = false;
  for (int i = 0, j = N-1; i < N; j = i++) {
    Ref<Point2D_I32> &a = polygon->vertexes[i];
    Ref<Point2D_I32> &b = polygon->vertexes[j];

    if ( ((a->y_>pt->y_) != (b->y_>pt->y_))
         && (pt->x_ < (b->x_-a->x_) * (pt->y_-a->y_) / (b->y_-a->y_) + a->x_) )
      c = !c;
  }
  return c;
}

bool Intersection2D_I32::containConcave( Polygon2D_I32 *polygon , Point2D_I32 *pt )
{
  const int N = polygon->size();

  int left=0;
  int right=0;
  for (int i = 0; i < N-1; i++) {
    Ref<Point2D_I32> &a = polygon->vertexes[i];
    Ref<Point2D_I32> &b = polygon->vertexes[i+1];

    if( (pt->y_ >= a->y_ && pt->y_ < b->y_) || (pt->y_ >= b->y_ && pt->y_ < a->y_) ) {
      // location of line segment along x-axis at y = pt->y
      double x = (b->y_==a->y_) ?
        pt->x_ : (pt->y_-a->y_)*(b->x_-a->x_)/(double)(b->y_-a->y_) + a->x_;

      if( x <= pt->x_)
        left++;
      else if( x > pt->x_ )
        right++;
    }
  }

  Ref<Point2D_I32> &a = polygon->vertexes[N-1];
  Ref<Point2D_I32> &b = polygon->vertexes[0];

  if( (pt->y_ >= a->y_ && pt->y_ < b->y_) || (pt->y_ >= b->y_ && pt->y_ < a->y_) ) {
    // location of line segment along x-axis at y = pt->y
    double x = (b->y_==a->y_) ?
      pt->x_ : (pt->y_-pt->y_)*(b->x_-a->x_)/(double)(b->y_-a->y_) + a->x_;

    if( x <= pt->x_ )
      left++;
    else if( x > pt->x_ )
      right++;
  }

  return (left % 2 == 1 && right % 2 == 1);
}

bool Intersection2D_I32::contains( RectangleLength2D_I32 *a, int x, int y ) {
  if( a->getX() <= x && a->getX() + a->getWidth() > x ) {
    return a->getY() <= y && a->getY() + a->getHeight() > y;
  }
  return false;
}

bool Intersection2D_I32::contains( Rectangle2D_I32 *a, int x, int y ) {
  return( x >= a->x0_ && y >= a->y0_ && x < a->x1_ && y < a->y1_ );
}

}}
