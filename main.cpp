// main.cpp
#include "template-concept.hpp"
#include <iostream>
#include <string>
 
int main() {
  std::cout << std::boolalpha << "Enable the boolalpha flag in the stream as if we called stream.setf(std::ios_base::boolalpha)" << std::endl;
  std::cout << "all_arithmetic(5, true, 5.5, false): " << all_arithmetic(5, true, 5.5, false) << std::endl;  
  std::cout << "any_arithmetic(5, true, 5.5, false): " << any_arithmetic(5, true, 5.5, false) << std::endl; 
  std::cout << "none_arithmetic(5, true, 5.5, false): " << none_arithmetic(5, true, 5.5, false) << std::endl;
  
  Vector<int> vec1;
  //Vector<std::string> vec2; //will not compile as std::string does not satisfy the user-defined IsArithmetic concept
  Vector<bool> vec3;
  Vector<float> vec4;

  List<int> list1;
  //List<std::string> list2; //will not compile as std::string does not satisfy the system-defined std::integral concept
  List<bool> list3;
  //List<float> vec4; //will not compile as float does not satisfy the system-defined std::integral concept

  return 0;
}
