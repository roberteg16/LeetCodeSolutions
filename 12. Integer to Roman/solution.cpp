#include <bits/stdc++.h>

class Solution {

  struct Triplet {
    char Lower;
    char Middle;
    char Higher;
  };

  void add(std::stringstream &ss, Triplet t, unsigned n) {
    switch (n) {
    case 0:
      return;
    case 1:
      ss << t.Lower;
      break;
    case 2:
      ss << t.Lower << t.Lower;
      break;
    case 3:
      ss << t.Lower << t.Lower << t.Lower;
      break;
    case 4:
      ss << t.Lower << t.Middle;
      break;
    case 5:
      ss << t.Middle;
      break;
    case 6:
      ss << t.Middle << t.Lower;
      break;
    case 7:
      ss << t.Middle << t.Lower << t.Lower;
      break;
    case 8:
      ss << t.Middle << t.Lower << t.Lower << t.Lower;
      break;
    case 9:
      ss << t.Lower << t.Higher;
      break;
    default:
      abort();
    }
  }

public:
  std::string intToRoman(int num) {
    std::string str;
    str.reserve(3 * 4);

    std::stringstream ss(str);

    constexpr Triplet triplets[4] = {Triplet{'M', 0, 0}, Triplet{'C', 'D', 'M'},
                                     Triplet{'X', 'L', 'C'},
                                     Triplet{'I', 'V', 'X'}};
    constexpr unsigned divs[4] = {1000, 100, 10, 1};
    for (unsigned i = 0; i < 4; i++) {
      add(ss, triplets[i], num / divs[i]);
      num %= divs[i];
    }

    return ss.str();
  }
};