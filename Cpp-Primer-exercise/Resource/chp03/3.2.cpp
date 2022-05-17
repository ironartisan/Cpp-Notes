#include <iostream>
#include <string>

using namespace std;

int main() {
//    string line;
//    cout << "请输入字符串" <<endl;
//    while (getline(cin, line)) { // 读入一整行
//        cout << line << endl;
//    }
    string word;
    while (cin >> word) { // 读入一个词
        cout << word << endl;
    }

    return 0;
}
