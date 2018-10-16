#pragma once
#include <geo/misc/GrlConstants.hpp>
using namespace geo::misc;

namespace geo { namespace metric {
/**
 * Utility functions relating to angles.  Unless otherwise state all angles
 * are in radians and have a domain of -pi to pi
 */
class UtilAngle {
public:
  static double radianToDegree( double angleRad ) {
    return 180.0 * angleRad / GrlConstants::F_PI;
  }

  static double degreeToRadian( double angleDegree ) {
    return M_PI * angleDegree / 180.0;
  }

  static float radianToDegree( float angleRad ) {
    return 180.0f * angleRad / GrlConstants::F_PI;
  }

  static float degreeToRadian( float angleDegree ) {
    return GrlConstants::F_PI * angleDegree / 180.0f;
  }

  /**
   * Converts radians into degrees
   * @param angleDegree angle in degrees
   * @return angle in radians
   */
  static double radian( double angleDegree ) {
    return degreeToRadian(angleDegree);
  }

  /**
   * Converts degrees into radians
   * @param angleRad angle in radians
   * @return angle in degrees
   */
  static double degree( double angleRad ) {
    return radianToDegree(angleRad);
  }

  /**
   * Converts radians into degrees
   * @param angleDegree angle in degrees
   * @return angle in radians
   */
  static float radian( float angleDegree ) {
    return degreeToRadian(angleDegree);
  }

  /**
   * Converts degrees into radians
   * @param angleRad angle in radians
   * @return angle in degrees
   */
  static float degree( float angleRad ) {
    return radianToDegree(angleRad);
  }


  static double atanSafe( double y , double x ) {
    if( x == 0.0 ) {
      if( y >= 0.0)
        return M_PI / 2;
      else
        return -M_PI / 2;
    }
    return atan(y/x);
  }

  static float atanSafe( float y , float x ) {
    if( x == 0.0 ) {
      if( y >= 0.0)
        return GrlConstants::F_PId2;
      else
        return -GrlConstants::F_PId2;
    }
    return (float)atan(y/x);
  }

  /**
   * Converts an angle which is (-pi to pi) into a half circle angle (-pi/2 to pi/2).
   *
   * @param angle Angle between -pi and pi.
   * @return -pi/2 to pi/2
   */
  static double toHalfCircle( double angle ) {
    if( angle < 0 )
      angle += M_PI;
    if( angle > M_PI/2.0 )
      angle -= M_PI;
    return angle;
  }

  /**
   * Converts an angle which is (-pi to pi) into a half circle angle (0 to pi).
   *
   * @param angle Angle between -pi and pi.
   * @return 0 to pi
   */
  static float toHalfCircle( float angle ) {
    if( angle >= 0 )
      return angle;
    return GrlConstants::F_PI+angle;
  }

  /**
   * Checks to see if it is between -&pi; and &pi;.
   *
   * @param ang Angle being tested
   * @return true if it is between -&pi; and &pi;
   */
  static bool isStandardDomain( double ang ) {
    return ( ang <= M_PI && ang >= -M_PI );
  }

  /**
   * Checks to see if it is between -&pi;/2 and &pi;/2.
   *
   * @param ang Angle being tested
   * @return true if it is between -&pi;/2 and &pi;/2;
   */
  static bool isHalfDomain( double ang ) {
    return ( ang <= M_PI/2 && ang >= -M_PI/2 );
  }

  /**
   * Returns an angle which is equivalent to the one provided, but between (inclusive) -&pi; and &pi;.
   */
  static double bound( double ang ) {
    ang = fmod(ang, GrlConstants::PI2);

    if( ang > M_PI ) {
      return ang - GrlConstants::PI2;
    } else if( ang < -M_PI ) {
      return ang + GrlConstants::PI2;
    }

    return ang;
  }

  /**
   * Returns an angle which is equivalent to the one provided, but between (inclusive) -&pi; and &pi;.
   */
  static float bound( float ang ) {
    ang = fmod(ang, GrlConstants::PI2);

    if( ang > GrlConstants::F_PI ) {
      return ang - GrlConstants::F_PI2;
    } else if( ang < -GrlConstants::F_PI ) {
      return ang + GrlConstants::F_PI2;
    }

    return ang;
  }

  /**
   * Bounds the angle between -&pi;/2 and &pi/2
   * @param angle angle in radians
   * @return bounded angle
   */
  static double boundHalf( double angle ) {
    angle = bound(angle);

    if( angle > GrlConstants::PId2 ) {
      angle -= M_PI;
    } else if( angle < -GrlConstants::PId2 ){
      angle += M_PI;
    }
    return angle;
  }

  /**
   * Bounds the angle between -&pi;/2 and &pi/2
   * @param angle angle in radians
   * @return bounded angle
   */
  static float boundHalf( float angle ) {
    angle = bound(angle);

    if( angle > GrlConstants::F_PId2 ) {
      angle -= GrlConstants::F_PI;
    } else if( angle < -GrlConstants::F_PId2 ){
      angle += GrlConstants::F_PI;
    }
    return angle;
  }

  /**
   * Angular distance in radians to go from angA to angB in counter clock-wise direction.
   * The resulting angle will be from 0 to 2&pi;.
   *
   * @param angA First angle. -pi to pi
   * @param angB Second angle -pi to pi
   * @return An angle from 0 to 2 &pi;
   */
  static double distanceCCW( double angA, double angB ) {
    if( angB >= angA )
      return angB-angA;
    else
      return GrlConstants::PI2 - (angA-angB);
  }

  /**
   * Angular distance in radians to go from angA to angB in counter clock-wise direction.
   * The resulting angle will be from 0 to 2&pi;.
   *
   * @param angA First angle. -pi to pi
   * @param angB Second angle -pi to pi
   * @return An angle from 0 to 2 &pi;
   */
  static float distanceCCW( float angA, float angB ) {
    if( angB >= angA )
      return angB-angA;
    else
      return GrlConstants::F_PI2 - (angA-angB);
  }

  /**
   * Angular distance in radians to go from angA to angB in clock-wise direction.
   * The resulting angle will be from 0 to 2&pi;.
   *
   * @param angA First angle. -pi to pi
   * @param angB Second angle   -pi to pi
   * @return An angle from 0 to 2 &pi;
   */
  static double distanceCW( double angA, double angB ) {
    if( angA >= angB )
      return angA-angB;
    else
      return GrlConstants::PI2-(angB-angA);
  }

  /**
   * Angular distance in radians to go from angA to angB in clock-wise direction.
   * The resulting angle will be from 0 to 2&pi;.
   *
   * @param angA First angle. -pi to pi
   * @param angB Second angle   -pi to pi
   * @return An angle from 0 to 2 &pi;
   */
  static float distanceCW( float angA, float angB ) {
    if( angA >= angB )
      return angA-angB;
    else
      return GrlConstants::F_PI2-(angB-angA);
  }

  /**
   * <p>
   * Returns the difference between two angles and bounds the result between -pi and pi:<br>
   * result = angA - angB<br>
   * and takes in account boundary conditions.
   * </p>
   *
   * @param angA first angle.  Must be between -pi and pi.
   * @param angB second angle. Must be between -pi and pi.
   * @return an angle between -pi and pi
   */
  static double minus( double angA, double angB ) {
    double diff = angA - angB;

    if( diff > M_PI ) {
      return GrlConstants::PI2 - diff;
    } else if( diff < -M_PI )
      return -GrlConstants::PI2 - diff;

    return diff;
  }

  /**
   * <p>
   * Returns the difference between two angles and bounds the result between -pi and pi:<br>
   * result = angA - angB<br>
   * and takes in account boundary conditions.
   * </p>
   *
   * @param angA first angle.  Must be between -pi and pi.
   * @param angB second angle. Must be between -pi and pi.
   * @return an angle between -pi and pi
   */
  static float minus( float angA, float angB ) {
    float diff = angA - angB;

    if( diff > GrlConstants::F_PI ) {
      return GrlConstants::F_PI2 - diff;
    } else if( diff < -GrlConstants::F_PI )
      return -GrlConstants::F_PI2 - diff;

    return diff;
  }

  /**
   * <p>
   * Returns the number of radians two angles are apart.  This is equivalent to
   * Math.abs(UtilAngle.minus(angA,angB)).
   * </p>
   *
   * @param angA first angle.  Must be between -pi and pi.
   * @param angB second angle. Must be between -pi and pi.
   * @return an angle between 0 and pi
   */
  static double dist( double angA, double angB ) {
    return abs(minus(angA,angB));
  }

  /**
   * <p>
   * Returns the number of radians two angles are apart.  This is equivalent to
   * Math.abs(UtilAngle.minus(angA,angB)).
   * </p>
   *
   * @param angA first angle.  Must be between -pi and pi.
   * @param angB second angle. Must be between -pi and pi.
   * @return an angle between 0 and pi
   */
  static float dist( float angA, float angB ) {
    return abs(minus(angA,angB));
  }

  /**
   * Angular distance between two half circle angles.
   *
   * @param angA Angle between -pi/2 and pi/2.
   * @param angB Angle between -pi/2 and pi/2.
   * @return Acute angle between the two input angles.
   */
  static double distHalf( double angA , double angB ) {
    double a = abs(angA-angB);
    if( a <= M_PI/2 )
      return a;
    else
      return M_PI-a;
  }

  /**
   * Converts an angle from -pi to pi into 0 to 2*pi domain
   * @param angle angle from -pi to pi radians
   * @return angle from 0 to 2*pi radians
   */
  static double domain2PI( double angle ) {
    if( angle < 0 ) {
      return angle + 2*M_PI;
    } else {
      return angle;
    }
  }

  /**
   * Ensures a wrapping circular bound so that the numbers from 0 to 1, where 0 is inclusive and 1 is exclusive.
   * <pre>Examples:
   * 1.5   = 0.5
   * -0.25 = 0.75
   * 0     = 0
   * 1     = 0
   * 0.999 = 0.999
   * 2     = 0
   * -1    = 0
   * </pre>
   *
   * @return A value from 0 to 1. [0,1)
   */
  static double wrapZeroToOne(double value ) {
    if( value >= 0 )
      return fmod(value, 1.0);
    else {
      return fmod((1.0+(fmod(value, 1.0))), 1.0); // last bit is to ensure that 1.0 is returned as 0.0
    }
  }

  /**
   * Ensures a wrapping circular bound so that the numbers from 0 to 1, where 0 is inclusive and 1 is exclusive.
   * <pre>Examples:
   * 1.5   = 0.5
   * -0.25 = 0.75
   * 0     = 0
   * 1     = 0
   * 0.999 = 0.999
   * 2     = 0
   * -1    = 0
   * </pre>
   *
   * @return A value from 0 to 1. [0,1)
   */
  static float wrapZeroToOne(float value ) {
    if( value >= 0 )
      return fmod(value, 1.0f);
    else {
      return fmod((1.0f+(fmod(value,1.0f))),1.0f); // last bit is to ensure that 1.0 is returned as 0.0
    }
  }

  /**
   * Ensures a reflective bound so that the numbers from 0 to 1, where 0 is inclusive and 1 is inclusive.
   * <pre>Examples:
   * 1.5   = 0.5
   * -0.25 = 0.25
   * -0.75 = 0.75
   * 0     = 0
   * 1     = 1
   * 0.999 = 0.999
   * 2     = 0
   * -1    = 1
   * </pre>
   *
   * @return A value from 0 to 1. [0,1]
   */
  static double reflectZeroToOne(double value ) {
    if( value < 0 )
      value = -value;
    value = fmod(value, 2.0);
    if( value > 1.0 )
      return 2.0 - value;
    return value;
  }

  /**
   * Ensures a reflective bound so that the numbers from 0 to 1, where 0 is inclusive and 1 is inclusive.
   * <pre>Examples:
   * 1.5   = 0.5
   * -0.25 = 0.25
   * -0.75 = 0.75
   * 0     = 0
   * 1     = 1
   * 0.999 = 0.999
   * 2     = 0
   * -1    = 1
   * </pre>
   *
   * @return A value from 0 to 1. [0,1]
   */
  static float reflectZeroToOne(float value ) {
    if( value < 0 )
      value = -value;
    value = fmod(value, 2.0f);
    if( value > 1.0f )
      return 2.0f - value;
    return value;
  }
};

}}
