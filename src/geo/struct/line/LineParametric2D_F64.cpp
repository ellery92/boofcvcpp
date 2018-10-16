#include "LineParametric2D_F64.hpp"
#include <geo/struct/point/Vector2D_F64.hpp>
#include <geo/struct/point/Point2D_F64.hpp>
#include <cmath>

namespace geo { namespace structure { namespace line {

LineParametric2D_F64::LineParametric2D_F64 (double x_0, double y_0,
                                            double slopeX, double slopeY ) {
  p->set( x_0, y_0 );
  slope->set(slopeX, slopeY);
}

LineParametric2D_F64::LineParametric2D_F64(Ref<Point2D_F64> p, Ref<Vector2D_F64> slope ) {
  setPoint(p);
  setSlope(slope);
}

void LineParametric2D_F64::set( Ref<LineParametric2D_F64> line ) {
  this->p->set(line->p);
  this->slope->set(line->slope);
}

void LineParametric2D_F64::setPoint( Ref<Point2D_F64> pt ) {
  this->p->set( pt );
}

void LineParametric2D_F64::setPoint( double x, double y ) {
  this->p->setX(x);
  this->p->setY(y);
}

void LineParametric2D_F64::setAngle( double angle )
{
  slope->set(cos(angle), sin(angle));
}

double LineParametric2D_F64::getAngle()
{
  return atan2(slope->x, slope->y);
}

Ref<Point2D_F64> LineParametric2D_F64::getPointOnLine( double t ) {
  return Ref<Point2D_F64>(new Point2D_F64( slope->x * t + p->getX(),
                                           slope->y * t + p->getY() ));
}

int LineParametric2D_F64::getSlopeX() {
  return slope->x;
}

int LineParametric2D_F64::getSlopeY() {
  return slope->y;
}

int LineParametric2D_F64::getX() {
  return p->getX();
}

int LineParametric2D_F64::getY() {
  return p->getY();
}

std::string LineParametric2D_F64::toString() {
  std::string sx = std::to_string(getX());
  std::string sy = std::to_string(getX());
  std::string slx = std::to_string(slope->x);
  std::string sly = std::to_string(slope->y);
  return getClass()+" P( "+sx+" "+sy+" ) Slope( "+slx+" "+sly+" )";
}

}}}
