#include "Area2D_F64.hpp"
#include <cstdlib>

#include <geo/struct/point/Point2D_F64.hpp>
#include <geo/struct/shapes/Quadrilateral_F64.hpp>
#include <geo/struct/shapes/Polygon2D_F64.hpp>

namespace geo { namespace metric {

double Area2D_F64::triangle( Point2D_F64 *a, Point2D_F64 *b, Point2D_F64  *c ) {
  double inner = a->x*(b->y - c->y) + b->x*(c->y - a->y) + c->x*(a->y - b->y);

  return std::abs(inner/2.0);
}

double Area2D_F64::quadrilateral( Quadrilateral_F64 *quad ) {
  double bx = quad->b->x-quad->a->x;
  double by = quad->b->y-quad->a->y;
  double cx = quad->c->x-quad->a->x;
  double cy = quad->c->y-quad->a->y;
  double dx = quad->d->x-quad->a->x;
  double dy = quad->d->y-quad->a->y;

  if( (bx * cy - by * cx >= 0) == (cx * dy - cy * dx >= 0)) {
    return triangle(quad->a,quad->b,quad->c) + triangle(quad->a,quad->c,quad->d);
  } else {
    return triangle(quad->a,quad->b,quad->d) + triangle(quad->b,quad->c,quad->d);
  }
}

double Area2D_F64::polygonSimple( Polygon2D_F64 *poly ) {
  double total = 0;

  Ref<Point2D_F64> v0 = poly->get(0);
  Ref<Point2D_F64> v1 = poly->get(1);
  for (int i = 2; i < poly->size(); i++) {
    Ref<Point2D_F64> v2 = poly->get(i);

    total += v1->x*( v2->y - v0->y);

    v0 = v1; v1 = v2;
  }

  Ref<Point2D_F64> v2 = poly->get(0);
  total += v1->x*( v2->y - v0->y);
  v0 = v1; v1 = v2;
  v2 = poly->get(1);
  total += v1->x*( v2->y - v0->y);

  return std::abs(total/2.0);
}

}}
