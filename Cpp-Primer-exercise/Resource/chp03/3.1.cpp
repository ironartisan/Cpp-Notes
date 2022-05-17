#include <iostream>
using std::cout;
using std::endl;
int main() {
    int i = 50, sum = 0;
    while (i <= 100) {
        sum += i;
        i += 1;
    }
    cout << "sum is  " << sum << endl;
}
