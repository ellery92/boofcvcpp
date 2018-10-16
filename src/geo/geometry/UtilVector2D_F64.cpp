#include "UtilVector2D_F64.hpp"
#include <geo/struct/point/Point2D_F64.hpp>
#include <geo/struct/point/Vector2D_F64.hpp>
#include <cmath>

namespace geo { namespace geometry {

double UtilVector2D_F64::acute(  Vector2D_F64 *a , Vector2D_F64 *b ) {
  double dot = a->dot(b);

  double value = dot/(a->norm()*b->norm());
  if( value > 1.0 )
    value = 1.0;
  else if( value < -1.0 )
    value = -1.0;

  return acos( value );
}

double UtilVector2D_F64::acute( double ax , double ay, double bx , double by ) {
  double dot = ax*bx + ay*by;
  double na = sqrt(ax*ax + ay*ay);
  double nb = sqrt(bx*bx + by*by);

  double value = dot/(na*nb);
  if( value > 1.0 )
    value = 1.0;
  else if( value < -1.0 )
    value = -1.0;

  return acos( value );
}

void UtilVector2D_F64::minus( Point2D_F64 *a, Point2D_F64 *b, Vector2D_F64 *output ) {
  if( output == NULL )
    output = new Vector2D_F64();

  output->x = a->x - b->x;
  output->y = a->y - b->y;
}

bool
UtilVector2D_F64::identicalSign( double xa , double ya ,
                                 double xb , double yb ,
                                 double tol ) {
  double dx0 = xb-xa;
  double dy0 = yb-ya;
  double dx1 = xb+xa;
  double dy1 = yb+ya;


  double error0 = dx0*dx0 + dy0*dy0;
  double error1 = dx1*dx1 + dy1*dy1;

  if( error0 < error1 ) {
    return error0 <= tol*tol;
  } else {
    return error1 <= tol*tol;
  }
}

}}
