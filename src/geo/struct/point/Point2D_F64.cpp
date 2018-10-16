#include "Point2D_F64.hpp"
#include <cmath>
#include <stdexcept>

namespace geo { namespace structure { namespace point {

void Point2D_F64::swapX(Ref<Point2D_F64> other) {
  std::swap(x, other->x);
}

void Point2D_F64::swapY(Ref<Point2D_F64> other) {
  std::swap(y, other->y);
}


}}}
