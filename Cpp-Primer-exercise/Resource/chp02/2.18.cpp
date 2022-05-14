#include <iostream>


int main() {
    int i = 1, j = 2;
    int *p  = &i;
    std::cout << p << " " << *p << std::endl;
    p = &j; //更改指针的值，令p指向另一个整数对象j
    std::cout << p << " " << *p << std::endl;
    *p = 10; // 显式改变指针p指向的内容
    std::cout << p << " " << *p << std::endl;
    j = 20; // 通过改变变量j的值
    std::cout << p << " " << *p << std::endl;
    return 0;
}
