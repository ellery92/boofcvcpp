#pragma once
#include <Object.hpp>

namespace geo { namespace structure { namespace line {
/**
 * <p>
 * Defines a line in 2D space based upon the distance of its closest point to the origin
 * and the angle of a line from the origin to that point.  Also referred to as the polar line
 * equation.
 * </p>
 *
 * <p>
 * Equation:<br>
 * x*cos(&theta;) + y*sin(&theta;) = r<br>
 * where r is the distance from the closest point on the line to the origin, and &theta; is
 * an angle tangent to the line.
 * </p>
 */
class LinePolar2D_F64 : public Object {
  D_OBJECT(LinePolar2D_F64)
public:
	/**
	 * Distance from the origin to the closest point on the line.
	 */
	double distance;
	/**
	 * Angle in radians from the origin to the closest point on the line.
	 */
	double angle;

	LinePolar2D_F64(double distance, double angle) {
		this->distance = distance;
		this->angle = angle;
	}

	LinePolar2D_F64() {
	}

	double getDistance() {
		return distance;
	}

	void setDistance(double distance) {
		this->distance = distance;
	}

	double getAngle() {
		return angle;
	}

	void setAngle(double angle) {
		this->angle = angle;
	}

  std::string toString() {
    return getClass()+"{ d = "+std::to_string(distance)+" angle = "+std::to_string(angle)+" }";
	}
};

}}}
