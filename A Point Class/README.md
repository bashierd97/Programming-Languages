## A Point Class

This program explores class design in the C++ language and uses some of the unique features C++ offers over Java. 
User's will be able to compare two point objects and their distance from the origin

### Functionality

- Displays a friendly menu to the user allowing them to select certain options
- Uses a class to model the "mathematical point"
- Overload operators to simply code in the calling functions
- Uses a friend function

The point object supports logical operations in source code, so one may compare two points and determine which is closer to the origin. Operations are defined using inline to reduce function call overhead. Additionally, the less than operation is used for all other conditions as well. Meaning, only the less than comparision shall actually compare x and y coordinates between points, and the other logical operations will use the less than operation to establish a true or false value for the current task

**I.E.:** Something is equal to something else if it neither less than the other thing nor greater than it.

### Running the Program

To compile ```g++ -o distance pointMain.cpp```
To execute ```.\distance.exe```
