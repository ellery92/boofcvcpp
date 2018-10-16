#include "UtilLine2D_I32.hpp"
#include <geo/struct/point/Point2D_I32.hpp>
#include <geo/struct/line/LineSegment2D_I32.hpp>
#include <cmath>

namespace geo { namespace geometry {

double UtilLine2D_I32::acuteAngle( LineSegment2D_I32 *line0 , LineSegment2D_I32 *line1 )
{
  int dx0 = line0->getB()->getX() - line0->getA()->getX();
  int dy0 = line0->getB()->getY() - line0->getA()->getY();
  int dx1 = line1->getB()->getX() - line1->getA()->getX();
  int dy1 = line1->getB()->getY() - line1->getA()->getY();

  double bottom = sqrt(dx0*dx0 + dy0*dy0) * sqrt(dx1*dx1 + dy1*dy1);
  return acos((dx0*dx1 + dy0*dy1)/bottom);
}

}}
