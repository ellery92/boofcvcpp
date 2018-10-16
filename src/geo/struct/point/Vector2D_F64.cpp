#include "Vector2D_F64.hpp"
#include <geo/struct/point/Point2D_F64.hpp>
#include <geo/geometry/UtilVector2D_F64.hpp>

using namespace geo::geometry;

namespace geo { namespace structure { namespace point {

void Vector2D_F64::minus( Ref<Point2D_F64> a , Ref<Point2D_F64> b ) {
  x = a->x - b->x;
  y = a->y - b->y;
}

double Vector2D_F64::acute( Ref<Vector2D_F64> a ) {
  return UtilVector2D_F64::acute(this, a);
}

}}}
