#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // 范围for语句
    int ia[2][2] = {1, 2, 3, 4};
    for (int (&row)[2] : ia){
        for(int &val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    // 普通for语句，下标形式
    for (int i = 0; i != 2; i++){
        for(int j = 0; j != 2; j++) {
            cout << ia[i][j] << " ";
        }
        cout << endl;
    }
    // 普通for语句，指针形式
    for (int (*p)[2] = ia; p != ia  + 2; p++){
        for(int *q = *p; q != *p + 2; q++) {
            cout << *q << " ";
        }
        cout << endl;
    }
    return 0;
}