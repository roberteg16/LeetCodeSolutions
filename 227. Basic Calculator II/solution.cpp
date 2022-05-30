class Solution {
public:
  void lTrim(string_view &s) {
    while (s.size() && s.front() == ' ') {
      s.remove_prefix(1);
    }
  }

  bool isNumber(const char c) {
    switch (c) {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      return true;
    default:
      return false;
    }
  }

  enum class Op { None = 0, Add, Sub, Mul, Div };

  int applyOp(int lhs, Op op, int rhs) {
    switch (op) {
    case Op::Add:
      return lhs + rhs;
    case Op::Sub:
      return lhs - rhs;
    case Op::Div:
      return lhs / rhs;
    case Op::Mul:
      return lhs * rhs;
    default:
      std::abort();
    }
  }

  bool hasPrecedence(Op op) { return op == Op::Mul || op == Op::Div; }

  int getNumber(string_view &s) {
    assert(s.size());
    lTrim(s);

    unsigned number = 0;
    while (isNumber(s.front())) {
      number *= 10;
      number += (s.front() - '0');
      s.remove_prefix(1);
    }

    return number;
  }

  Op getOpImpl(const char c) {
    switch (c) {
    case '+':
      return Op::Add;
    case '-':
      return Op::Sub;
    case '/':
      return Op::Div;
    case '*':
      return Op::Mul;
    default:
      std::abort();
    }
  }

  Op getOp(string_view &s) {
    lTrim(s);

    if (!s.size()) {
      return Op::None;
    }

    Op op = getOpImpl(s.front());
    s.remove_prefix(1);

    return op;
  }

  int calculate(string str) {
    string_view s = str;

    std::vector<int> nums;
    nums.push_back(getNumber(s));

    std::vector<Op> ops;

    while (s.size()) {
      auto op = getOp(s);
      if (op == Op::None) {
        break;
      }
      int rhs = getNumber(s);

      if (hasPrecedence(op)) {
        nums.back() = applyOp(nums.back(), op, rhs);
      } else {
        nums.push_back(rhs);
        ops.push_back(op);
      }
    }

    int result = nums[0];
    for (size_t i = 1; i < nums.size(); i++) {
      result = applyOp(result, ops[i-1], nums[i]);
    }

    return result;
  }
};

