#ifndef _TEMPLATE_CONCEPT_H_
#define _TEMPLATE_CONCEPT_H_

#include <type_traits>
#include <vector>
#include <list>

// define our own concept to test if a value is arithmetic
template<typename T>
concept IsArithmetic = std::is_arithmetic<T>::value;

// use our defined concept to test if values in an arbitrary list are arithmetic
template<IsArithmetic... Args>
bool all_arithmetic(Args... args) { return (... && args); }

template<IsArithmetic... Args>
bool any_arithmetic(Args... args) { return (... || args); }

template<IsArithmetic... Args>
bool none_arithmetic(Args... args) { return !(... || args); }

// use our defined concept in conjunction with requires
// to restrict template instantiation to arithmetic types only
template<typename T>
  requires IsArithmetic<T> //use the concept we defined
class Vector : public std::vector<T> {};

// use system-defined concept in conjunction with requires
// to restrict template instantiation to integral types only
template<typename T>
  requires std::integral<T>
class List : public std::list<T> {};

#endif
