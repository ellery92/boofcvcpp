#pragma once
#include <Object.hpp>

namespace geo { namespace structure {

template<typename T>
struct GeoTuple : public Object {
  D_OBJECT(GeoTuple)

  virtual ~GeoTuple() = default;

  virtual int getDimension() = 0;
  virtual Ref<T> createNewInstance() = 0;
  virtual Ref<T> copy() = 0;
};

}}
