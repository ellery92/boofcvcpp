#include <iostream>

#include <geo/struct/point/Point2D_I32.hpp>
#include <geo/struct/point/Point2D_F64.hpp>

#include <geo/struct/shapes/Rectangle2D_I32.hpp>
#include <geo/struct/shapes/Rectangle2D_F64.hpp>

// #include <geo/struct/shapes/Polygon2D_I32.hpp>
// #include <geo/struct/line/LineSegment2D_F64.hpp>

using namespace geo::structure::point;

int main()
{
  Ref<Point2D_I32> pt_i32(new Point2D_I32(1, 1));
  Ref<Point2D_F64> pt_f64(new Point2D_F64(1.0, 12.0));

  std::cout << pt_i32->distance(2, 3) << std::endl;
  std::cout << pt_f64->distance(2, 3) << std::endl;

  return 0;
}
