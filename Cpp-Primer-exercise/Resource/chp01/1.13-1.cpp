#include <iostream>
// 修改1.9
int main() {
    int  sum = 0;
    for (int i = 50; i <= 100; i++) {
        sum += i;
    }
    std::cout << "sum is  " << sum << std::endl;
}