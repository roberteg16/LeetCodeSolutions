#include <bits/stdc++.h>
#include <string_view>

static long ToInteger(char c) {
  return c - '0';
} 

class Solution {
public:
  int myAtoi(std::string s) {
    std::string_view str = s;

    long rectifier = 1;
    long solution = 0;

    // Handle trailing spaces
    while(!str.empty() && str.front() == ' ') { 
      str = str.substr(1, str.size() - 1 );
    }

    if (str.empty()) {
      return 0;
    }

    // Handle possible signs
    if (str.front() == '-') {
      rectifier = -1;
      str = str.substr(1, str.size() - 1 );
    } else if (str.front() == '+') {
      str = str.substr(1, str.size() - 1 );
    }

    // Handle number
    while(!str.empty() && std::isdigit(str.front())) {
      solution = solution * 10 + ToInteger(str.front()) * rectifier;

      if (solution < std::numeric_limits<int>::min()) {
        return std::numeric_limits<int>::min();
      } else if (solution > std::numeric_limits<int>::max()) {
        return std::numeric_limits<int>::max();
      }

      str = str.substr(1, str.size() - 1 );
    }

    return solution;
  }
};
