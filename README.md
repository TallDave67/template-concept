# Template Concept

This project demonstrates a c++20 concept which is used to semantically constrain the parameters for a valid template instantiation.

Linux distro "Pop!_OS 20.10"

cmake version 3.16.3

Ubuntu clang version 11.0.0-2

## Steps

cd build

./doCmake.sh

make VERBOSE=1

./template-concept

## History

dates: June 27, 2021

duration: 2 hours

### Code from Another Developer

These folks gave me my start.

[cppreference.com - concept](https://en.cppreference.com/w/cpp/language/constraints)

[Rainer Grimm - concept](https://www.modernescpp.com/index.php/c-20-concepts-the-details)

[Bjarne Stroustrup - see concept](https://www.stroustrup.com/tour2.html)

## Output

If we uncomment this line of code in main.cpp ...

Vector<std::string> vec2; //will not compile as std::string does not satisfy the user-defined IsArithmetic concept

... here is the output from the compiler 

> /usr/bin/clang++-11    -Wall   -std=c++20 -stdlib=libstdc++ -std=c++2a -o CMakeFiles/template-concept.dir/main.cpp.o -c ~/dev/moderncpp/template-concept/main.cpp
> 
> ~/dev/moderncpp/template-concept/main.cpp:13:3: error: constraints not satisfied for class template 'Vector' [with T = std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>]
> 
> Vector<std::string> vec2; //will not compile as std::string does not satisfy the user-defined IsArithmetic concept
> 
> ^~~~~~~~~~~~~~~~~~~
> 
> ~/dev/moderncpp/template-concept/template-concept.hpp:25:12: note: because 'std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>' does not satisfy 'IsArithmetic'
> 
> requires IsArithmetic<T> //use the concept we defined
>          ^
> ~/dev/moderncpp/template-concept/template-concept.hpp:10:24: note: because 'std::is_arithmetic<basic_string<char, char_traits<char>, allocator<char> > >::value' evaluated to false
> 
> concept IsArithmetic = std::is_arithmetic<T>::value;
>                      ^
> 1 error generated.

So as you can see, concepts protect us from using the wrong concrete type to instantiate our abstraction.


