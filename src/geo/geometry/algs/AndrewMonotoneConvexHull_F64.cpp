#include "AndrewMonotoneConvexHull_F64.hpp"

#include <geo/struct/point/Point2D_F64.hpp>
#include <geo/struct/shapes/Polygon2D_F64.hpp>
#include <vector>
#include <algorithm>

namespace geo { namespace geometry { namespace algs {
bool AndrewMonotoneConvexHull_F64::point_compare(Point2D_F64 *a, Point2D_F64 *b) {
  if( a->x < b->x )
    return -1;
  else if( a->x > b->x )
    return 1;
  else if( a->y < b->y )
    return -1;
  else if( a->y > b->y )
    return 1;
  return 0;
}

double AndrewMonotoneConvexHull_F64::
subtractThenCross( Point2D_F64 *a, Point2D_F64 *b, Point2D_F64 *c) {
  double x0 = b->x - a->x;
  double y0 = b->y - a->y;

  double x1 = c->x - a->x;
  double y1 = c->y - a->y;

  return x0 * y1 - y0 * x1;
}

void AndrewMonotoneConvexHull_F64::
process( std::vector<Point2D_F64*> &input , int length , Polygon2D_F64 *hull )
{
  // ahdnle special cases
  if( length == 2 ) {
    hull->vertexes.clear();
    hull->vertexes.resize(length);
    for (int i = 0; i < length; i++) {
      hull->vertexes[i] = new Point2D_F64();
      hull->vertexes[i]->set(input[i]);
    }
    return;
  }

  std::sort(input.begin(), input.end(), point_compare);
  std::vector<Point2D_F64*> work;

  // construct the lower hull
  for (int i = 0; i < length; i++) {
    Point2D_F64 *p = input[i];
    //Contains at least 2 points and the last two points and 'p' do not make a counter-clockwise turn
    while( work.size() >= 2 &&
           subtractThenCross(p,work.at(work.size()-1),work.at(work.size()-2)) >= 0) {
      // remove the last points from the hull
      work.pop_back();
    }
    // append p to the end
    work.push_back(p);
  }

  work.pop_back();
  int minSize = work.size()+2;

  // construct upper hull
  for(int i = length-1 ; i >= 0 ; i --)                // Finding top layer from hull
    {
      //Contains at least 2 points and the last two points and 'p' do not make a counter-clockwise turn
      Point2D_F64 *p = input[i];
      while( work.size() >= minSize
             && subtractThenCross(p,work.at(work.size()-1),work.at(work.size()-2)) >= 0 ) {
        work.pop_back();
      }
      // append p to the end
      work.push_back(p);
    }
  work.pop_back();

  // create a copy for the output
  // the work buffer contains references to the input points, but to be safe the output should have its
  // own instances
  hull->vertexes.clear();
  hull->vertexes.resize(work.size());
  for (int i = 0; i < work.size(); i++) {
    hull->vertexes[i] = new Point2D_F64();
    hull->vertexes[i]->set(work.at(i));
  }
}

}}}
