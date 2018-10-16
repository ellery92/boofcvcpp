#include "LineParametric2D_I32.hpp"
#include <geo/struct/point/Point2D_I32.hpp>
#include <geo/struct/point/Point2D_F64.hpp>

namespace geo { namespace structure { namespace line {

LineParametric2D_I32::LineParametric2D_I32(int x_0, int y_0, int slopeX, int slopeY ) {
  p->set( x_0, y_0 );
  this->slopeX = slopeX;
  this->slopeY = slopeY;
}

LineParametric2D_I32::LineParametric2D_I32(Ref<Point2D_I32> p, int slopeX, int slopeY ) {
  setPoint(p);
  setSlope(slopeX,slopeY);
}

void LineParametric2D_I32::set( Ref<LineParametric2D_I32> line ) {
  this->p->set(line->p);
  this->slopeX = line->slopeX;
  this->slopeY = line->slopeY;
}

void LineParametric2D_I32::setPoint( Ref<Point2D_I32> pt ) {
  this->p->set( pt );
}

void LineParametric2D_I32::setPoint( int x, int y ) {
  this->p->setX(x);
  this->p->setY(y);
}

Ref<Point2D_F64> LineParametric2D_I32::getPointOnLine( double t ) {
  return Ref<Point2D_F64>(new Point2D_F64( slopeX * t + p->getX(), slopeY * t + p->getY() ));
}

int LineParametric2D_I32::getX() {
  return p->getX();
}

int LineParametric2D_I32::getY() {
  return p->getY();
}

std::string LineParametric2D_I32::toString() {
  std::string sx = std::to_string(getX());
  std::string sy = std::to_string(getX());
  std::string slx = std::to_string(slopeX);
  std::string sly = std::to_string(slopeY);
  return getClass()+" P( "+sx+" "+sy+" ) Slope( "+slx+" "+sly+" )";
}

}}}
