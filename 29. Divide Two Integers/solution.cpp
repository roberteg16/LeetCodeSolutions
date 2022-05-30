#include <iostream>
#include <limits>

#define TRY(NUM)                                                               \
  long per##NUM = divisor_ * NUM;                                              \
  while (dividend_ >= per##NUM) {                                              \
    dividend_ -= per##NUM;                                                     \
    result += 1 * NUM;                                                        \
  }

class Solution {
public:
  long divide(int dividend, int divisor) {
    long result = 0;

    size_t nNegatives = 0;
    nNegatives += dividend < 0;
    nNegatives += divisor < 0;

    long dividend_ = dividend < 0 ? -static_cast<long>(dividend) : dividend;
    long divisor_ = divisor < 0 ? -static_cast<long>(divisor) : divisor;

    TRY(1000000)
    TRY(100000)
    TRY(10000)
    TRY(1000)
    TRY(100)
    TRY(10)
    TRY(1)

    if (nNegatives % 2 != 0) {
      result *= -1;
    }

    if (result > std::numeric_limits<int>::max()) {
      return std::numeric_limits<int>::max();
    } else if (result < std::numeric_limits<int>::min()) {
      return std::numeric_limits<int>::min();
    }

    return result;
  }
};

int main() {
  Solution s;
  std::cout << s.divide(-2147483648, -1) << std::endl;
  std::cout << s.divide(10, 3) << std::endl;
}