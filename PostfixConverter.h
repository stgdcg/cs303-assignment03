#pragma once
#include <stack>
#include <vector>
#include <string>
using namespace std;

class PostfixConverter {
private:
  string infix;

  static const string VALID_OPEN_PARENTHESES;
  static const string VALID_CLOSED_PARENTHESES;
  static const vector<string> OPERATOR_PRECEDENCE;
  static const string VALID_OPERATORS;

  bool is_open_parenthesis(char character) const;
  
  bool is_closed_parenthesis(char character) const;
  
  bool is_operator(char character) const;

  bool operator_greater_or_equal(char lhs, char rhs) const;
  
  bool balanced_parentheses_check() const;
  
public:
  PostfixConverter(string expression);

  string convert_to_postfix();

  string get_infix() const;
  
  void set_infix(const string expression);
};
