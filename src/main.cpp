#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
#include "simd.hpp"
#include <hwy/aligned_allocator.h>
#include <hwy/cache_control.h>

template<class It>
std::size_t calc_mem_cells(It begin, It end) {
  typename It::difference_type result = *begin;
  if (std::distance(begin, end) == 1) {
    return result;
  }
  It it = begin + 1;
  do {
    result += *it;
    result += (*it) * (*(it - 1));
    ++it;
  } while (it != end);
  return result;
}

int main() {
  std::vector<std::uint32_t> layers = {
    14 + 19, 20, 20, 19
  };

  auto result = calc_mem_cells(layers.begin(), layers.end());

  result *= 1000000;

  std::cout << result << " --- " << float(sizeof(float)*result) / 1024 / 1024 << " Mb" << std::endl;
}