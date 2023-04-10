#include <iostream>
#include "Queue.h"
#include "PostfixConverter.h"
using namespace std;

int main() {
  Queue<string> queue(5);
  char option;
  string value;
  // Create a postfix converter object.
  PostfixConverter converter("");
  
  // Loop until the user wants to quit.
  do {
    // Prompt the user and save that value.
    cout << "(p) push to the queue" << endl;
    cout << "(P) pop from the queue" << endl;
    cout << "(t) show the top" << endl;
    cout << "(e) is the queue empty" << endl;
    cout << "(s) show the size of the queue" << endl;
    cout << "(c) convert an infix to a postfix expression" << endl;
    cout << "(Q) quit" << endl;
    cout << "Enter your choice: ";
    cin >> option;

    cout << endl;

    // Decide what to do based on the inputted option.
    switch(option) {
    case 'p':
      // Prompt the user for a value to push.
      cout << "\tEnter a value to push to the queue: ";
      cin >> value;

      // Push the value.
      queue.push(value);
      
      break;
    case 'P':
      // Pop from the queue.
      try {
        cout << "\tThe popped value was: " << queue.pop() << endl;
      } catch (out_of_range &e) {
        cout << "\tUnable to pop from an empty queue!" << endl;
      }
      break;
    case 't':
      // Output the value at the top.
      if (queue.empty()) {
	cout << "\tThe queue is empty" << endl;
      } else {
	cout << "\tThe value at the top is: " << queue.top() << endl;
      }
      break;
    case 's':
      // Output the size
      if (queue.empty())
	cout << "\tThe queue is empty" << endl;
      else
	cout << "\tThe size is: " << queue.size() << endl;
      break;
    case 'e':
      // Test if queue is empty.
      if (queue.empty())
	cout << "\tThe queue is empty" << endl;
      else
	cout << "\tThe queue is not empty" << endl;
      break;
    case 'c':
      // Input an expression.
      cout << "\tEnter an infix expression: ";
      cin >> value;

      // Load the expression into the converter.
      converter.set_infix(value);

      try {
	// Output the converted expression.
        cout << "\tThe postfix operation is:" << endl;
        cout << converter.convert_to_postfix() << endl;
      } catch (runtime_error &e) {
        cout << "\tUnable to convert; " << e.what() << endl;
      }
      break;
    case 'Q':
      // End the loop
      break;
    default:
      // Output invalid option
      cout << "Invalid option; please enter a valid option." << endl;
      break;
    }
    cout << endl;
  } while (option != 'Q');
}
