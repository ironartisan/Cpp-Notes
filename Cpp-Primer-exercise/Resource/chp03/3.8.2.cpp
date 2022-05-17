#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cout << "请输入一个字符串" <<endl;
    getline(cin, s);
    for (unsigned int i = 0; i < s.size(); i++) {
        s[i] = 'X';
    }
    cout << s << endl;
    return 0;
}
