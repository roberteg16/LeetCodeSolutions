#include <bits/stdc++.h>

class Solution {
public:
  int calPoints(std::vector<std::string> &ops) {
    std::vector<int> scores;
    scores.reserve(ops.size());

    for (auto &op : ops) {
      switch (op.front()) {
      case '+':
        scores.push_back(scores[scores.size() - 1] + scores[scores.size() - 2]);
        break;
      case 'D':
        scores.push_back(scores.back() * 2);
        break;
      case 'C':
        scores.pop_back();
        break;
      case '-':
        scores.push_back(std::atoi(op.c_str() + 1) * -1);
        break;
      default:
        scores.push_back(std::atoi(op.c_str()));
        break;
      }
    }

    return std::accumulate(scores.begin(), scores.end(), 0);
  }
};
