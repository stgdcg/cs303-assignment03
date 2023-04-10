#include "PostfixConverter.h"
#include <stdexcept>
#include <deque>
#include <numeric>
using namespace std;

const string PostfixConverter::VALID_OPEN_PARENTHESES = "([{";
const string PostfixConverter::VALID_CLOSED_PARENTHESES = ")]}";

const vector<string> PostfixConverter::OPERATOR_PRECEDENCE = {"*/%", "+-"};
const string PostfixConverter::VALID_OPERATORS = accumulate(OPERATOR_PRECEDENCE.begin(), OPERATOR_PRECEDENCE.end(), string{});

bool PostfixConverter::is_open_parenthesis(char character)  const {
  return (VALID_OPEN_PARENTHESES.find(character) != string::npos);
}

bool PostfixConverter::is_closed_parenthesis(char character)  const {
  return (VALID_CLOSED_PARENTHESES.find(character) != string::npos);
}

bool PostfixConverter::is_operator(char character)  const {
  return (VALID_OPERATORS.find(character) != string::npos);
}

bool PostfixConverter::balanced_parentheses_check() const {

  stack<char> parentheses_check_stack;
  
  for (auto character : infix) {
    if (is_open_parenthesis(character)) {
      parentheses_check_stack.push(character);
    } else {
      if (character == ')' && parentheses_check_stack.top() != '(') {
        return false;
      } else if (character == ']' && parentheses_check_stack.top() != '[') {
        return false;
      } else if (character == '}' && parentheses_check_stack.top() != '{') {
        return false;
      }
    }
  }

  return true;
}

bool PostfixConverter::operator_greater_or_equal(char lhs, char rhs) const {
  // Loop through the operator precedence vector.
  for (auto level : OPERATOR_PRECEDENCE) {
    if (level.find(lhs) != string::npos) {
      return true;
    } else if (level.find(rhs) != string::npos) {
      return false;
    }
  }

  // If the loop completes then neither could be found. Throw an error. Return
  // because the compiler wants that.
  throw runtime_error("Invalid operator in expression");
  return false;
}

PostfixConverter::PostfixConverter(string expression = "") {
  infix = expression;
}

string PostfixConverter::convert_to_postfix() {
  // If parentheses are unbalanced, throw an error, to be caught in the main function.
  if (!balanced_parentheses_check()) {
    throw runtime_error("Unbalanced parentheses in expression");
  }

  deque<char> output_queue;
  stack<char> operator_stack;
  
  for (auto token : infix) {
    if (is_open_parenthesis(token)) {
      // Token is an open parenthesis. Push to the operator stack.
      operator_stack.push(token);
      
    } else if (is_closed_parenthesis(token)) {
      // Token is a closed parenthesis. Pop from the operator stack into the output queue
      // until the top of the operator stack is an open parenthesis. Pop and discard that.
      while (!is_open_parenthesis(operator_stack.top())) {
        output_queue.push_back(operator_stack.top());
	operator_stack.pop();
      }

      operator_stack.pop();
      
    } else if (is_operator(token)) {
      // Token is an operator. While there is an operator at the top of the stack that is
      // not an open parenthesis AND the top of the operator stack has >= precedence than
      // the token, pop from the operator stack into the output queue. Finally, push token
      // to the output queue.
      if (!operator_stack.empty()) {
        while (!is_open_parenthesis(operator_stack.top()) &&
               operator_greater_or_equal(operator_stack.top(), token)) {
          output_queue.push_back(operator_stack.top());
          operator_stack.pop();
        }
      }

      operator_stack.push(token);

    } else {
      // Token is a number or a variable. Directly push to the output queue.
      output_queue.push_back(token);
    }
  }

  // Empty out the operator stack into the output queue.
  while (!operator_stack.empty()) {
    output_queue.push_back(operator_stack.top());
    operator_stack.pop();
  }

  // Convert output queue to a string.
  return accumulate(output_queue.begin(), output_queue.end(), string{});
}

string PostfixConverter::get_infix() const {
  return infix;
}

void PostfixConverter::set_infix(const string expression) {
  infix = expression;
}
