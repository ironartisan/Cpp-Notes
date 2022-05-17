#include <iostream>
#include <vector>

using namespace std;
using  int_array = int[2];

int main()
{
    // 范围for语句
    int ia[2][2] = {1, 2, 3, 4};
    for (auto &row : ia){
        for(auto &val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    // 普通for语句，下标形式
    for (auto i = 0; i != 2; i++){
        for(auto j = 0; j != 2; j++) {
            cout << ia[i][j] << " ";
        }
        cout << endl;
    }
    // 普通for语句，指针形式
    for (auto *p = ia; p != ia  + 2; p++){
        for(auto *q = *p; q != *p + 2; q++) {
            cout << *q << " ";
        }
        cout << endl;
    }
    return 0;
}