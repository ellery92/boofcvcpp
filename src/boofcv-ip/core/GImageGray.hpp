#include <Object.hpp>

namespace boofcv {
namespace core {
namespace image {

  struct GImageGray {
    virtual void wrap(Ref<ImageGray> image) = 0;
    virtual int getWidth() = 0;
    virtual int getHeight() = 0;
    virtual bool isFloatingPoint() = 0;
    virtual int get(int x, int y) = 0;
    virtual void set(int x, int y, int num) = 0;
    virtual double getf(int x, int y) = 0;
    virtual void set(int x, int y, double value) = 0;
    virtual void set(int index, double value) = 0;
    virtual void getf(int index) = 0;
    Ref<ImageGray>
  };

}}}
