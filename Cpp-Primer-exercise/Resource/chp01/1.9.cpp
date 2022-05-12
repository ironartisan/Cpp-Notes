#include <iostream>

int main() {
    int i = 50, sum = 0;
    while (i <= 100) {
        sum += i;
        i += 1;
    }
    std::cout << "sum is  " << sum << std::endl;
}
