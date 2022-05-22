#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    vector<int> vInt;
    const int sz = 10;
    srand((unsigned ) time(NULL));

    cout <<"数组的初始值为"  << endl;

    for(int i = 0; i != sz; ++i) {
        vInt.push_back(rand() % 100);
        cout << vInt[i] << " ";
    }
    cout <<endl;

    for(auto &val : vInt) {
        val = (val % 2 == 0) ? val  : val * 2;
    }
    cout <<"最终数组为"  << endl;

    for(auto it  = vInt.cbegin(); it != vInt.cend(); ++it) {
        cout << *it << " ";
    }
    cout <<endl;
    return 0;
}
