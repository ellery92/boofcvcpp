#pragma once
#include <Object.hpp>

namespace geo { namespace structure { namespace line {
class LineSegment2D_I32;
}}}

using namespace geo::structure::line;

namespace geo { namespace geometry {
class UtilLine2D_I32 {
public:
  /**
   * Computes the acute angle between the two lines.  Does not check for intersection
   *
   * @param line0 First line
   * @param line1 Second line
   * @return Acute angle in radians
   */
  static double acuteAngle( LineSegment2D_I32 *line0 , LineSegment2D_I32 *line1 );
  static double acuteAngle( Ref<LineSegment2D_I32> line0 , Ref<LineSegment2D_I32> line1 ) {
    return acuteAngle(line0.get(), line1.get());
  }
};

}}
