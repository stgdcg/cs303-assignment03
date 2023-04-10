# cs303-assignment03

## Building
Run `make all` to build. `./main` to run the program. Use `make clean` to clean up `*.0` files.

Choose an option. Fill in any prompts as requested.

## Data Structure
The `Queue.h` is a single header that includes a fully functional templated queue backed with a circular array. The interaction functions are as specified in the spec doc.
Every function runs in constant time.

## Postfix Converter Class
The `PostfixConverter` class is a class that contains all the functions needed to convert infix notation to postfix notation. In `main.cpp`, it can be accessed by entering `c` on the menu.

### Operator Precedence
The class has 3 important static const variables that can be edited in the `.cpp` file to add more operators. There are two strings, each corresponding to the list of open and closed parentheses. There is also a vector of strings. The first string in the vector corresponds to all of the operators that have the highest priority, in this case they are `*/%`. The next levels show the next highest priority and so on. This makes it easy to add in new operators and properly assign them in the order of operations.

### Usage
To use the class in your own program, instantiate a new `PostfixConverter` class. The constructor defaults to an empty string, but you can use this to directly input your infix expression. A new infix expression can be added with `set_infix(const string expression)`. To get the postfix, use `convert_to_postfix()`. This function will perform the balanced parentheses check (outputting a `runtime_error` if it fails) and then output the converted postfix expression. Here is an example of its usage in `main.cpp`:

```
Enter your choice: c

        Enter an infix expression: 1+2*(3-4)
        The postfix operation is: 1234-*+
```

## Interaction
A menu is given to the user as shown below:

```
(p) push to the queue
(P) pop from the queue
(t) show the top
(e) is the queue empty
(s) show the size of the queue
(c) convert an infix to a postfix expression
(Q) quit
Enter your choice: 

```

## Demo
Here is a short demo showing the functionality of `main.cpp` (the queue has an initial size of 5 to showcase that the array properly resizes when needed):

```
(p) push to the queue
(P) pop from the queue
(t) show the top
(e) is the queue empty
(s) show the size of the queue
(c) convert an infix to a postfix expression
(Q) quit
Enter your choice: c

        Enter an infix expression: 1+2*(3-4)
        The postfix operation is:
1234-*+

(p) push to the queue
(P) pop from the queue
(t) show the top
(e) is the queue empty
(s) show the size of the queue
(c) convert an infix to a postfix expression
(Q) quit
Enter your choice: p   

        Enter a value to push to the queue: 1

(p) push to the queue
(P) pop from the queue
(t) show the top
(e) is the queue empty
(s) show the size of the queue
(c) convert an infix to a postfix expression
(Q) quit
Enter your choice: p

        Enter a value to push to the queue: 2

(p) push to the queue
(P) pop from the queue
(t) show the top
(e) is the queue empty
(s) show the size of the queue
(c) convert an infix to a postfix expression
(Q) quit
Enter your choice: p

        Enter a value to push to the queue: 3

(p) push to the queue
(P) pop from the queue
(t) show the top
(e) is the queue empty
(s) show the size of the queue
(c) convert an infix to a postfix expression
(Q) quit
Enter your choice: p

        Enter a value to push to the queue: 4

(p) push to the queue
(P) pop from the queue
(t) show the top
(e) is the queue empty
(s) show the size of the queue
(c) convert an infix to a postfix expression
(Q) quit
Enter your choice: p

        Enter a value to push to the queue: 5

(p) push to the queue
(P) pop from the queue
(t) show the top
(e) is the queue empty
(s) show the size of the queue
(c) convert an infix to a postfix expression
(Q) quit
Enter your choice: p

        Enter a value to push to the queue: 6

(p) push to the queue
(P) pop from the queue
(t) show the top
(e) is the queue empty
(s) show the size of the queue
(c) convert an infix to a postfix expression
(Q) quit
Enter your choice: s

        The size is: 6

(p) push to the queue
(P) pop from the queue
(t) show the top
(e) is the queue empty
(s) show the size of the queue
(c) convert an infix to a postfix expression
(Q) quit
Enter your choice: t

        The value at the top is: 1

(p) push to the queue
(P) pop from the queue
(t) show the top
(e) is the queue empty
(s) show the size of the queue
(c) convert an infix to a postfix expression
(Q) quit
Enter your choice: P

        The popped value was: 1

(p) push to the queue
(P) pop from the queue
(t) show the top
(e) is the queue empty
(s) show the size of the queue
(c) convert an infix to a postfix expression
(Q) quit
Enter your choice: P

        The popped value was: 2

(p) push to the queue
(P) pop from the queue
(t) show the top
(e) is the queue empty
(s) show the size of the queue
(c) convert an infix to a postfix expression
(Q) quit
Enter your choice: P

        The popped value was: 3

(p) push to the queue
(P) pop from the queue
(t) show the top
(e) is the queue empty
(s) show the size of the queue
(c) convert an infix to a postfix expression
(Q) quit
Enter your choice: P

        The popped value was: 4

(p) push to the queue
(P) pop from the queue
(t) show the top
(e) is the queue empty
(s) show the size of the queue
(c) convert an infix to a postfix expression
(Q) quit
Enter your choice: P

        The popped value was: 5

(p) push to the queue
(P) pop from the queue
(t) show the top
(e) is the queue empty
(s) show the size of the queue
(c) convert an infix to a postfix expression
(Q) quit
Enter your choice: P

        The popped value was: 6

(p) push to the queue
(P) pop from the queue
(t) show the top
(e) is the queue empty
(s) show the size of the queue
(c) convert an infix to a postfix expression
(Q) quit
Enter your choice: P

        The popped value was:   Unable to pop from an empty queue!

(p) push to the queue
(P) pop from the queue
(t) show the top
(e) is the queue empty
(s) show the size of the queue
(c) convert an infix to a postfix expression
(Q) quit
Enter your choice: e

        The queue is empty

(p) push to the queue
(P) pop from the queue
(t) show the top
(e) is the queue empty
(s) show the size of the queue
(c) convert an infix to a postfix expression
(Q) quit
Enter your choice: q

Invalid option; please enter a valid option.

(p) push to the queue
(P) pop from the queue
(t) show the top
(e) is the queue empty
(s) show the size of the queue
(c) convert an infix to a postfix expression
(Q) quit
Enter your choice: Q
```