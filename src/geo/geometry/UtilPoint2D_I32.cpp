#include "UtilPoint2D_I32.hpp"
#include <geo/struct/point/Point2D_I32.hpp>

namespace geo { namespace geometry {

double UtilPoint2D_I32::distance( Point2D_I32 *a , Point2D_I32 *b ) {
  int dx = b->x_ - a->x_;
  int dy = b->y_ - a->y_;

  return sqrt( dx * dx + dy * dy );
}

int UtilPoint2D_I32::distanceSq( Point2D_I32 *a , Point2D_I32 *b ) {
  int dx = b->x_ - a->x_;
  int dy = b->y_ - a->y_;

  return dx * dx + dy * dy;
}

Ref<Point2D_I32> UtilPoint2D_I32::mean(std::vector<Ref<Point2D_I32> > &list,
                                       Ref<Point2D_I32> mean) {
  if( !mean )
    mean = new Point2D_I32();

  int sumX = 0, sumY = 0;
  int N = list.size();

  for( int i = 0; i < N; i++ ) {
    Ref<Point2D_I32> &p = list.at(i);

    sumX += p->x_;
    sumY += p->y_;
  }

  mean->x_ = sumX/N;
  mean->y_ = sumY/N;

  return mean;
}

}}
