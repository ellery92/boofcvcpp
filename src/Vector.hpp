#pragma once

#include <Object.hpp>
#include <vector>

template<typename T>
class Vector : public Object, public std::vector<T> {
public:
  virtual String getClass() const override {
    return "Vector";
  }
};
