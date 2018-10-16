#include "UtilPolygons2D_F64.hpp"

#include <geo/struct/line/LineSegment2D_F64.hpp>
#include <geo/struct/point/Point2D_F64.hpp>
#include <geo/struct/shapes/Polygon2D_F64.hpp>
#include <geo/struct/shapes/Quadrilateral_F64.hpp>
#include <geo/struct/shapes/Rectangle2D_F64.hpp>
#include <geo/struct/shapes/RectangleLength2D_F64.hpp>
#include <geo/struct/shapes/RectangleLength2D_I32.hpp>

#include <geo/geometry/UtilVector2D_F64.hpp>
#include <geo/geometry/algs/AndrewMonotoneConvexHull_F64.hpp>

#include <geo/metric/Distance2D_F64.hpp>
#include <geo/metric/ClosestPoint2D_F64.hpp>

#include <vector>
#include <algorithm>
#include <iterator>

using namespace geo::metric;
using namespace geo::geometry::algs;

namespace geo { namespace geometry {

bool UtilPolygons2D_F64::isConvex( Polygon2D_F64 *poly ) {
  // if the cross product of all consecutive triples is positive or negative then it is convex

  const int N = poly->size();
  int numPositive = 0;
  for (int i = 0; i < N; i++) {
    int j = (i+1)%N;
    int k = (i+2)%N;

    Point2D_F64 a = poly->vertexes[i];
    Point2D_F64 b = poly->vertexes[j];
    Point2D_F64 c = poly->vertexes[k];

    double dx0 = a.x-b.x;
    double dy0 = a.y-b.y;

    double dx1 = c.x-b.x;
    double dy1 = c.y-b.y;

    double z = dx0 * dy1 - dy0 * dx1;
    if( z > 0 )
      numPositive++;
    // z can be zero if there are duplicate points.
    // not sure if it should throw an exception if its "bad" or not
  }

  return( numPositive == 0 || numPositive == N );
}

void UtilPolygons2D_F64::convert( Rectangle2D_F64 *input , Quadrilateral_F64 *output ) {
  output->a->x = input->p0_->x;
  output->a->y = input->p0_->y;

  output->b->x = input->p1_->x;
  output->b->y = input->p0_->y;

  output->c->x = input->p1_->x;
  output->c->y = input->p1_->y;

  output->d->x = input->p0_->x;
  output->d->y = input->p1_->y;
}

void UtilPolygons2D_F64::convert( Rectangle2D_F64 *input , Polygon2D_F64 *output ) {
  if (output->size() != 4)
    throw std::invalid_argument("polygon of order 4 expected");

  output->get(0)->set(input->p0_->x, input->p0_->y);
  output->get(1)->set(input->p1_->x, input->p0_->y);
  output->get(2)->set(input->p1_->x, input->p1_->y);
  output->get(3)->set(input->p0_->x, input->p1_->y);
}

void UtilPolygons2D_F64::convert( Quadrilateral_F64 *input , Polygon2D_F64 *output ) {
  if (output->size() != 4)
    throw std::invalid_argument("polygon of order 4 expected");

  output->get(0)->set(input->a);
  output->get(1)->set(input->b);
  output->get(2)->set(input->c);
  output->get(3)->set(input->d);
}

void UtilPolygons2D_F64::convert( Polygon2D_F64 *input , Quadrilateral_F64 *output ) {
  if( input->size() != 4 )
    throw std::invalid_argument("Expected 4-sided polygon as input");

  output->a->set(input->get(0));
  output->b->set(input->get(1));
  output->c->set(input->get(2));
  output->d->set(input->get(3));
}

void UtilPolygons2D_F64::convert( RectangleLength2D_I32 *input , Quadrilateral_F64 *output ) {
  output->a->x = input->x0;
  output->a->y = input->y0;

  output->b->x = input->x0+input->width-1;
  output->b->y = input->y0;

  output->c->x = input->x0+input->width-1;
  output->c->y = input->y0+input->height-1;

  output->d->x = input->x0;
  output->d->y = input->y0+input->height-1;
}

void UtilPolygons2D_F64::bounding( Quadrilateral_F64 *quad , Rectangle2D_F64 *rectangle ) {

  rectangle->p0_->x = std::min(quad->a->x,quad->b->x);
  rectangle->p0_->x = std::min(rectangle->p0_->x,quad->c->x);
  rectangle->p0_->x = std::min(rectangle->p0_->x,quad->d->x);

  rectangle->p0_->y = std::min(quad->a->y,quad->b->y);
  rectangle->p0_->y = std::min(rectangle->p0_->y,quad->c->y);
  rectangle->p0_->y = std::min(rectangle->p0_->y,quad->d->y);

  rectangle->p1_->x = std::max(quad->a->x,quad->b->x);
  rectangle->p1_->x = std::max(rectangle->p1_->x,quad->c->x);
  rectangle->p1_->x = std::max(rectangle->p1_->x,quad->d->x);

  rectangle->p1_->y = std::max(quad->a->y,quad->b->y);
  rectangle->p1_->y = std::max(rectangle->p1_->y,quad->c->y);
  rectangle->p1_->y = std::max(rectangle->p1_->y,quad->d->y);
}

void UtilPolygons2D_F64::bounding( Polygon2D_F64 *polygon , Rectangle2D_F64 *rectangle ) {

  rectangle->p0_->set(polygon->get(0));
  rectangle->p1_->set(polygon->get(0));

  for (int i = 0; i < polygon->size(); i++) {
    const Ref<Point2D_F64> &p = polygon->get(i);
    if( p->x < rectangle->p0_->x ) {
      rectangle->p0_->x = p->x;
    } else if( p->x > rectangle->p1_->x ) {
      rectangle->p1_->x = p->x;
    }

    if( p->y < rectangle->p0_->y ) {
      rectangle->p0_->y = p->y;
    } else if( p->y > rectangle->p1_->y ) {
      rectangle->p1_->y = p->y;
    }
  }
}

Ref<Point2D_F64> UtilPolygons2D_F64::center( Quadrilateral_F64 *quad,
                                Ref<Point2D_F64> center) {
  if( !center )
    center = new Point2D_F64();

  center->x = quad->a->x + quad->b->x + quad->c->x + quad->d->x;
  center->y = quad->a->y + quad->b->y + quad->c->y + quad->d->y;

  center->x /= 4.0;
  center->y /= 4.0;

  return center;
}

bool UtilPolygons2D_F64::isCCW( std::vector<Ref<Point2D_F64> > &polygon ) {
  const int N = polygon.size();
  int sign = 0;
  for (int i = 0; i < N; i++) {
    int j = (i+1)%N;
    int k = (i+2)%N;

    Ref<Point2D_F64> &a = polygon.at(i);
    Ref<Point2D_F64> &b = polygon.at(j);
    Ref<Point2D_F64> &c = polygon.at(k);

    double dx0 = a->x-b->x;
    double dy0 = a->y-b->y;

    double dx1 = c->x-b->x;
    double dy1 = c->y-b->y;

    double z = dx0 * dy1 - dy0 * dx1;
    if( z > 0 )
      sign++;
    else
      sign--;
  }

  return sign < 0;
}

bool UtilPolygons2D_F64::isCCW( Polygon2D_F64 *polygon ) {
  return isCCW(polygon->vertexes);
}

void UtilPolygons2D_F64::vertexAverage(Polygon2D_F64 *input, Point2D_F64 *average ) {
  average->set(0,0);

  for (int i = 0; i < input->size(); i++) {
    Ref<Point2D_F64> &v = input->vertexes[i];
    average->x += v->x;
    average->y += v->y;
  }
  average->x /= input->size();
  average->y /= input->size();
}

bool UtilPolygons2D_F64::isIdentical( Polygon2D_F64 *a , Polygon2D_F64 *b , double tol ) {
  if( a->size() != b->size())
    return false;

  double tol2 = tol*tol;
  for (int i = 0; i < a->size(); i++) {
    if( a->get(i)->distance2(b->get(i)) > tol2 )
      return false;
  }
  return true;
}

bool UtilPolygons2D_F64::isEquivalent( Polygon2D_F64 *a , Polygon2D_F64 *b , double tol ) {
  if( a->size() != b->size())
    return false;

  double tol2 = tol*tol;

  // first find two vertexes which are the same
  const Ref<Point2D_F64> &a0 = a->get(0);

  int match = -1;
  for (int i = 0; i < b->size(); i++) {
    if( a0->distance2(b->get(i)) <= tol2 ) {
      match = i;
      break;
    }
  }

  if( match < 0 )
    return false;

  // now go in a circle and see if they all line up
  for (int i = 1; i < b->size(); i++) {
    const Ref<Point2D_F64> &ai = a->get(i);
    const Ref<Point2D_F64> &bi = b->get((match+i)%b->size());

    if( ai->distance2(bi) > tol2 ) {
      return false;
    }
  }
  return true;
}

void UtilPolygons2D_F64::flip( Polygon2D_F64 *a ) {
  int N = a->size();
  int H = N/2;

  for (int i = 1; i <= H; i++) {
    int j = N-i;
    Ref<Point2D_F64> tmp = a->vertexes[i];
    a->vertexes[i] = a->vertexes[j];
    a->vertexes[j] = tmp;
  }
}

void UtilPolygons2D_F64::shiftUp( Polygon2D_F64 *a ) {
  const int N = a->size();

  const Ref<Point2D_F64> first = a->get(0);

  for (int i = 0; i < N-1; i++ ) {
    a->vertexes[i] = a->vertexes[i+1];
  }
  a->vertexes[N-1] = first;
}

void UtilPolygons2D_F64::shiftDown( Polygon2D_F64 *a ) {
  const int N = a->size();

  const Ref<Point2D_F64> last = a->get(N-1);

  for (int i = N-1; i > 0; i-- ) {
    a->vertexes[i] = a->vertexes[i-1];
  }
  a->vertexes[0] = last;
}

void UtilPolygons2D_F64::
convexHull( std::vector<Ref<Point2D_F64> > &points, Polygon2D_F64 *hull ) {
  std::vector<Point2D_F64*> array(points.size());
  for (int i = 0; i < points.size(); i++) {
    array[i] = points.at(i).get();
  }

  AndrewMonotoneConvexHull_F64::process(array, array.size(), hull);
}

void UtilPolygons2D_F64::removeAlmostParallel( Polygon2D_F64 *polygon , double tol ) {

  for (int i = 0; i < polygon->size(); ) {
    int j = (i+1)%polygon->size();
    int k = (i+2)%polygon->size();

    Ref<Point2D_F64> &p0 = polygon->vertexes.at(i);
    Ref<Point2D_F64> &p1 = polygon->vertexes.at(j);
    Ref<Point2D_F64> &p2 = polygon->vertexes.at(k);

    double angle = UtilVector2D_F64::acute(p1->x-p0->x,p1->y-p0->y,p2->x-p1->x,p2->y-p1->y);

    if( angle <= tol) {
      polygon->vertexes.erase(polygon->vertexes.begin() + j);
      if( j < i )
        i = polygon->vertexes.size()-1;
    } else {
      i++;
    }
  }
}

void UtilPolygons2D_F64::removeAdjacentDuplicates( Polygon2D_F64 *polygon , double tol ) {

  for (int i = polygon->vertexes.size()-1,j=0; i >= 0 && polygon->size()>1; j=i,i--) {
    if( polygon->get(i)->isIdentical(polygon->get(j),tol)) {
      polygon->vertexes.erase(polygon->vertexes.begin() + i);
    }
  }
}

bool UtilPolygons2D_F64::hasAdjacentDuplicates( Polygon2D_F64 *polygon , double tol ) {

  for (int i = polygon->size()-1,j=0; i >= 0 && polygon->size()>1; j=i,i--) {
    if( polygon->get(i)->isIdentical(polygon->get(j),tol)) {
      return true;
    }
  }
  return false;
}

double UtilPolygons2D_F64::averageOfClosestPointError(Polygon2D_F64 *model , Polygon2D_F64 *target , int numberOfSamples ) {
  Ref<LineSegment2D_F64> line(new LineSegment2D_F64());

  std::vector<double> cornerLocationsBVec(target->size()+1);
  double *cornerLocationsB = cornerLocationsBVec.data();
  double totalLength = 0;
  for (int i = 0; i < target->size(); i++) {
    const Ref<Point2D_F64> &b0 = target->get(i%target->size());
    const Ref<Point2D_F64> &b1 = target->get((i+1)%target->size());

    cornerLocationsB[i] = totalLength;
    totalLength += b0->distance(b1);
  }
  cornerLocationsB[target->size()] = totalLength;

  Ref<Point2D_F64> pointOnB(new Point2D_F64());
  double error = 0;
  int cornerB = 0;
  for (int k = 0; k < numberOfSamples; k++) {
    // Find the point on B to match to a point on A
    double location = totalLength*k/numberOfSamples;

    while (location > cornerLocationsB[cornerB + 1]) {
      cornerB++;
    }
    const Ref<Point2D_F64> &b0 = target->get(cornerB);
    const Ref<Point2D_F64> &b1 = target->get((cornerB+1)%target->size());

    double locationCornerB = cornerLocationsB[cornerB];
    double fraction = (location-locationCornerB)/(cornerLocationsB[cornerB+1]-locationCornerB);

    pointOnB->x = (b1->x-b0->x)*fraction + b0->x;
    pointOnB->y = (b1->y-b0->y)*fraction + b0->y;

    // find the best fit point on A to the point in B
    double best = std::numeric_limits<double>::max();
    for (int i = 0; i < model->size()+1; i++) {
      line->a_ = model->get(i%model->size());
      line->b_ = model->get((i+1)%model->size());

      double d = Distance2D_F64::distance(line,pointOnB);
      if( d < best ) {
        best = d;
      }
    }
    error += best;
  }

  return error/numberOfSamples;
}

}}
