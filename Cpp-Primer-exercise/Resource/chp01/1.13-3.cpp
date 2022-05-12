#include <iostream>

int main() {
    int temp = 0;
    std::cout << "Please enter two numbers"<< std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    // 若v1 > v2,则调换顺序
    if (v1 > v2) {
        temp  = v2;
        v2 = v1;
        v1 = temp;
    }

    for (;v1 <= v2;v1++){
        std::cout << v1 << std::endl;
    }
}
