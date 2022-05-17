#include <iostream>
#include <string>

using namespace std;

int main() {
    string str1, str2;
    cout << "请输入两个字符串" << endl;
    cin >> str1;
    cin >> str2;

    if (str1 == str2) {
        cout << "两个字符相等" << endl;
    }else if (str1 > str2) {
            cout << str1 << endl;
    }else {
            cout << str2 <<endl;
    }
    auto len1 = str1.size();
    auto len2 = str2.size();

    if (len1 == len2) {
        cout << str1 << "和" << str2 << "的长度是" << len2 << endl;
    }else if (len1 > len2)
        cout << str1 << "比" << str2 << "的长度多" << len1 - len2 << endl;
    else
        cout << str1 << "比" << str2 << "的长度少" << len2 - len1 << endl;

    
    return 0;
}
