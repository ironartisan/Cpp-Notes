#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::vector;

int main() {
    const int sz = 10;
    int num[sz];
    for (int i = 0; i < sz; i++) {
        num[i] = i;
    }

    for (auto val : num) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}