#include <hwy/base.h>

namespace project {
  void CallMulAddLoop(const float* HWY_RESTRICT mul_array,
                      const float* HWY_RESTRICT add_array,
                      const size_t size, float* HWY_RESTRICT x_array);
}