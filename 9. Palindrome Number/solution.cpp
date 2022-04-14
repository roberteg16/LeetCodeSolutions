#include <bits/stdc++.h>

constexpr size_t NumberOfDigitsOfPositiveNumber(size_t n) {
  size_t nDigits = 1;

  while (n) {
    n /= 10;
    nDigits++;
  }

  return nDigits;
}

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }

    if ((x / 10) == 0) {
      return true;
    }

    constexpr size_t nDigitsOfInt =
        NumberOfDigitsOfPositiveNumber(std::numeric_limits<int>::max());
    unsigned char digitsOfNumber[nDigitsOfInt] = {0};

    size_t i = 0;
    size_t divisor = 10;
    while (x) {
      digitsOfNumber[i++] = x % divisor;
      x /= 10;
    }

    unsigned lp = i - 1;
    unsigned rp = 0;
    while (lp > rp) {
      if (digitsOfNumber[lp] != digitsOfNumber[rp]) {
        return false;
      }

      lp--;
      rp++;
    }

    return true;
  }
};
