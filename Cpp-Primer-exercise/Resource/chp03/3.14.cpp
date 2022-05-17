#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::vector;

int main() {
    vector<int> v;
    int i;
    char cont = 'y';
    cout << "请输入数字" << endl;
    while(cin >> i) {
        v.push_back(i);
        cout << "是否继续(y or n)" << endl;
        cin >> cont;
        if (cont == 'y' || cont == 'Y'){
            cout << "请输入下一个整数" << endl;
        }else {
            break;
        }
    }
    for (auto &m : v)
        cout << "输入的整数为" <<m << endl;
    return 0;
}
