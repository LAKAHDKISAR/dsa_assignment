# Question 1 - Balanced Parentheses

## How the data structure is defined

I used a simple stack implemented as a global char array with a top variable to keep track of the current position.

```c
char stack[SIZE];
int top = -1;
```

The top is reset to -1 at the start of each check() call so it works correctly for multiple expressions.

## Functions

**push(char c)** - increments top and stores the character. No overflow check since expressions won't be that long.

**pop()** - returns the top character and decrements top. If the stack is empty, it prints "Stack Underflow" and exits the program using exit(1)

**isEmpty()** - just checks if top is -1.

**checking_if_balance_or_not(char \*expr[])** - this is the main logic. It goes through each character of the expression one by one. If it sees an opening bracket `(`, `[`, or `{` it pushes it onto the stack. If it sees a closing bracket it pops from the stack and checks if they match. If the stack is empty when we get a closing bracket, or the brackets don't match, it returns 0 (not balanced). At the end if the stack is still not empty that means some opening bracket was never closed, so it returns 0 too.

**main()** - main() takes a mathematical expression as input from the user using fgets(), calls checking_if_balance_or_not() and prints whether the expression is balanced or not.

## Output

![](assets/Screenshot%202026-02-10%20at%207.22.27 PM.png)
