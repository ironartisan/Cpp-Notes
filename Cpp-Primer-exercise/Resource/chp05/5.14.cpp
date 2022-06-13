#include <iostream>

using namespace std;


int main()
{
    string currStr, preStr = " ", maxStr;

    int currCnt = 1, maxCnt = 0;


    while (cin >> currStr) {
        //
        if (currStr == preStr) {
           ++currCnt;
           if (currCnt > maxCnt) {
               maxCnt = currCnt;
               maxStr = currStr;
           }
        }else {
            currCnt = 1;
        }
        preStr = currStr;
    }
    if (maxCnt >1) {
        cout << "出现最多的字符串是 : " << maxStr << ", 次数是：" << maxCnt << endl;
    }else {
        cout << "每个字符串都出现了一次"  << endl;
    }
    return 0;
}