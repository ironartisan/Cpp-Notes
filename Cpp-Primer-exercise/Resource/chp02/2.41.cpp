#include <iostream>


int main() {
    int a = 1;
    auto c1 = a;
    decltype(a) c2 = a;
    decltype((a)) c3 = a;

    const int d = 3;
    auto f1 = d;
    decltype(d) f2 = d;

    std::cout << typeid(c1).name() << std::endl;
    std::cout << typeid(c2).name() << std::endl;
    std::cout << typeid(c3).name() << std::endl;
    std::cout << typeid(f1).name() << std::endl;
    std::cout << typeid(f2).name() << std::endl;

    c1++;
    c2++;
    c3++;
    f1++;
//    f2++; f2是整型变量，不能执行自增操作

    std::cout << c1 << " " << c2 << " "<< c3 << " "<< f1 << " "<< f2 << " " << std::endl;
    return 0;
}
