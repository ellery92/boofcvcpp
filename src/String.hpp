#pragma once
#include <string>

class String {
public:
  String() {}
  String(std::string const &str) : str_(str) {}
  String(const char *ch) : str_(ch) {}

  String operator+(const char *ch) {
    return str_ + ch;
  }

  String operator+(int v) {
    return str_ + std::to_string(v);
  }

  bool operator==(String const &str) {
    return str_ == str.str_;
  }

  bool operator!=(String const &str) {
    return str_ != str.str_;
  }

public:
  std::string str_;
};
