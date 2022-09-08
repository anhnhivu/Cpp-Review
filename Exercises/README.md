# Exercise

### 001. Two’s complement
Given an array of 8-bit unsigned numbers {0, 1, 2, 126, 127, 128, 129, 130, 254, 255}, write a program
- Calculate two’s complement value of the binary based on its bits
- Keep in mind time and space complexity

### 002. Reversed Polish Notation
Write a program to calculate an arithmetic expression in infix notation
- Convert it from infix notation to postfix notation
- Derive the result from the postfix notation
Example

- Input: ((2 + 9) * 3) - 5
- Postfix notation: 2 9 + 3 * 5 -
- Result: 28

### 003. Big integer
Let’s implement a program to calculate the signed big integer 128bit, only using the build-in type in C++.
- Read and write value with console.
- Read and write value with the text file.
- Read and write value with the binary file in big-endian and little-endian.
- Overload the operators: + - * / < > == !=
- Calculate the reversed Polish notation formula input from the console.

### 004. AVL tree demo
Write a program to tell your friends about how AVL tree work

- Implement the data structure of the AVL tree, including operations insertion, deletion, search

- Rotate the tree to be balanced during insertion and deletion
    - Be noted of four cases of imbalance: left-left, left-right, right-right and right-left
    - Make sure to classify imbalance into correct cases and rebalance the tree with proper rotation operations including left rotation and right rotation

### 005. Reader - Writer problem

An airline reservation system consists of a huge database with many processes that read and write the data. Reading information from the database will not cause a problem since no data is changed. The problem lies in writing information to the database. If no constraints are put on access to the database, data may change at any moment. By the time a reading process displays the result of a request for information to the user, the actual data in the database may have changed. What if, for instance, a process reads the number of available seats on a flight, finds a value of one, and reports it to the customer. Before the customer has a chance to make their reservation, another process makes a reservation for another customer, changing the number of available seats to zero.

Please implement a program to control the reading and writing operator for this system. Should we use a reader-prioritized or writer-prioritized solution?

## Reference
- [Readers and Writers problem](http://denninginstitute.com/modules/ipc/aqua/readers.html#:~:text=A%20practical%20example%20of%20a,information%20to%20the%20data%20base.)