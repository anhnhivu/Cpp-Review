# Exercise

### 003. Big integer
Let’s implement a program to calculate the signed big integer 128bit, only using the build-in type in C++.
- Read and write value with console.
- Read and write value with the text file.
- Read and write value with the binary file in big-endian and little-endian.
- Overload the operators: + - * / < > == !=
- Calculate the reversed Polish notation formula input from the console.

### 005. Reader - Writer problem

An airline reservation system consists of a huge database with many processes that read and write the data. Reading information from the database will not cause a problem since no data is changed. The problem lies in writing information to the database. If no constraints are put on access to the database, data may change at any moment. By the time a reading process displays the result of a request for information to the user, the actual data in the database may have changed. What if, for instance, a process reads the number of available seats on a flight, finds a value of one, and reports it to the customer. Before the customer has a chance to make their reservation, another process makes a reservation for another customer, changing the number of available seats to zero.

Please implement a program to control the reading and writing operator for this system. Should we use a reader-prioritized or writer-prioritized solution?