## c++11/c++14

g++ main.cpp -std=c++11

g++ main.cpp -std=c++14

### 弃用的特性

char* str="Hello";

不允许字符串字面常量赋值给一个char*,应该给const char*/auto

### 与c兼容

在不得不适用c时，注意使用extern "c"特性，将c语言代码和c++分离编译，再统一链接

gcc -c foo.c 

g++ main.cpp foo.o -o main

