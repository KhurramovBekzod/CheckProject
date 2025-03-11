Midterm Practice Assignment
Important Notes
The work will be graded based on the output of your programs, the correctness of the structure of your repository, and the style of your code. You may be penalized and receive a lower grade if the printed text by your program does not match (wrong letters, additional spaces, or newlines, incorrectly computed result) the correct one. Please check your code and output before submitting it to GitHub or Exam Document. Ensure the outcome of your program matches the specified output on this page. Do not forget to print a \n control sequence to go to a new line after the last message from your program. Ensure that your code style is consistent, meaning the code is properly indented, groups of code are separated by blank lines, variable names are consistent in naming style, and describe in a compact manner the data stored in them. Your files and directories must be properly named as per the requirements outlined at the bottom of the page. Moreover, your repository should not contain additional files with unrelated code, especially within the folder designated for lab tasks. If you are told to use a particular function, you must base your solution on that function even if there exists a better solution without the use of it. Do not hesitate to contact your practice instructor if you have any questions.

Tasks
Complete the following programming exercise on your own.

Problem #1: Class vector3
Write a command-line program that, for the following test code in the main function (provided in the starter code):

using std::cout;

vector3 a{ 10.0f, 20.0f, 30.0f};
vector3 b{-42.0f, 4.0f,  2.0f};
vector3 c; // create a zero vector

cout << "a.x: " << a.get_x() << ", a.y: " << a.get_y() << ", a.z: " << a.get_z() << "\n";
cout << "b.x: " << b.get_x() << ", b.y: " << b.get_y() << ", b.z: " << b.get_z() << "\n";

cout << a << " + "     << b    << " = " << (a + b)    << "\n";
cout << a << " - "     << b    << " = " << (a - b)    << "\n";
cout << a << " * "     << 2.0f << " = " << (a * 2.0f) << "\n";
cout << a << " dot "   << b    << " = " << a.dot(b)   << "\n";
cout << a << " cross " << b    << " = " << a.cross(b) << "\n";

cout << "||"  << a << "|| = " << a.get_length()             << "\n";
cout << "||"  << c << "|| = " << c.get_length()             << "\n";
cout << "||^" << b << "|| = " << b.normalize().get_length() << "\n";
...produces precisely this output in the console, using the correct computations:

a.x: 10, a.y: 20, a.z: 30
b.x: -42, b.y: 4, b.z: 2
(10, 20, 30) + (-42, 4, 2) = (-32, 24, 32)
(10, 20, 30) - (-42, 4, 2) = (52, 16, 28)
(10, 20, 30) * 2 = (20, 40, 60)
(10, 20, 30) dot (-42, 4, 2) = -280
(10, 20, 30) cross (-42, 4, 2) = (-80, -1280, 880)
||(10, 20, 30)|| = 37.4166
||(0, 0, 0)|| = 0
||^(-42, 4, 2)|| = 1

Build a vector3 class directly in the main.cpp file that represents a three-component float vector, supporting addition, subtraction, multiplication by a scalar, dot product, cross product, magnitude calculation, and string conversion by overloading the std::ostream operator. Provide an appropriate constructor, member functions such as getters, operator overloading functions, and private fields. The type must be immutable, meaning each operation that creates a new vector should return a new instance rather than modifying any existing vector. Maintain proper encapsulation so that the internal workings of the class remain hidden. Use each language construct where it fits best, choose appropriate data types, and keep your code clear, concise, and stylistically consistent.

If you’ve forgotten some of your linear algebra from a previous semester or university course, you can consult the following slides for a quick reminder:

https://docs.google.com/presentation/d/1oGSmNs_fzIQrFJpQfZZm0kKPcl5xMrtweVTXZqQgsgU
Grading Rubric
The program works correctly and produces the expected output, passing all GitHub Actions tests. (5 points)
The class vector3 is well-defined, immutable, and properly encapsulated with correct access modifiers and accessors. (1 point)
The class vector3 has appropriate constructors. (1 point)
The class vector3 has a member function get_length. (1 point)
The class vector3 has operator overloads for operator+, operator-, and operator*. (1 point)
The class vector3 has dot and cross member functions. (1 point)
The class vector3 has a member function normalize. (1 point)
A non-member function, operator<<, is used to overload the insertion operator. (1 point)
All variables are named in a consistent style and in a meaningful, concise way. (1 point)
The code uses whitespace and blank lines to consistently separate groups of code. (1 point)
The code is indented properly. (1 point)
Expected Repository Structure
Upon completion of the assignment, your repository should look like this:

. (.idea, .gitignore, CMakeLists.txt, Readme.md)
└── problem01.cpp
If the file with the assignment is named incorrectly, you will be penalized.

Documentation
https://isocpp.org
https://cppreference.com
