#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::vector;

int main() {
    vector<string> v;
    string i;
    char cont = 'y';
    cout << "请输入字符串" << endl;
    while (cin >> i) {
        v.push_back(i);
        cout << "是否继续(y or n)" << endl;
        cin >> cont;
        if (cont == 'y' || cont == 'Y') {
            cout << "请输入下一个字符串" << endl;
        } else {
            break;
        }
    }
    for (auto &m: v) {
        for (auto &c: m){
            c = toupper(c);
        }
        cout << m << " ";
        cout << endl;
    }
    return 0;
}