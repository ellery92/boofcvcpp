#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <limits>

namespace geo { namespace misc {
/**
 * Constants used throughout the library.
 *
 */
class GrlConstants {
public:
  static constexpr const float F_PI = (float)M_PI;
  static constexpr const float F_PI2 = (float)(2.0*M_PI);
  static constexpr const float F_PId2 = (float)(M_PI/2.0);

  static constexpr const double PI = M_PI;
  static constexpr const double PI2 = 2.0*M_PI;
  static constexpr const double PId2 = M_PI/2.0;

  // identifies the library version
  static constexpr const char VERSION[] = "0.15";

  // standard tolerances used in unit tests
  static constexpr float const TEST_F32 = 1e-4f;
  static constexpr double const TEST_F64 = 1e-8;
  static constexpr double const TEST_SQ_F64 = sqrt(TEST_F64);
  static constexpr float const TEST_SQ_F32 = (float)sqrt(TEST_F32);

  // tolerances for convergence
  static constexpr float const FCONV_TOL_A = 1e-5f;
  static constexpr double const DCONV_TOL_A = 1e-10;
  static constexpr float const FCONV_TOL_B = 1e-6f;
  static constexpr double const DCONV_TOL_B = 1e-12;

  static constexpr float const F_EPS = std::numeric_limits<float>::epsilon();
  static constexpr double const EPS = std::numeric_limits<double>::epsilon();
};

}}
