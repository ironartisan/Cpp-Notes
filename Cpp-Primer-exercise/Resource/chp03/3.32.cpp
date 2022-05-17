#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::vector;

int main() {
    const int sz = 10;
    vector<int> num3;
    vector<int> num4;
    int num1[sz], num2[sz];
    for (int i = 0; i < sz; i++) {
        num1[i] = i;
    }
    for (int i = 0; i < sz; i++) {
        num2[i] = num1[i];
    }
    cout << "num2中的值为" << endl;
    for (auto val : num2) {
        cout << val << " ";
    }
    cout << endl;

    for (int i = 0; i < sz; i++) {
        num3.push_back(i);
    }
    for (int i = 0; i < sz; i++) {
        num4.push_back(num3[i]);
    }
    cout << "num4中的值为" << endl;
    for (auto val : num4) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}