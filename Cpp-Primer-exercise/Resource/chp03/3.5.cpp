#include <iostream>
#include <string>

using namespace std;

int main() {
    char cont = 'y';
    string s, result;
    cout << "请输入字符串" << endl;
    while(cin >> s) {
        if (!result.size())
            result += s;
        else
            result = result + " " + s;
        cout << "是否继续(y or n)" << endl;
        cin >> cont;
        if (cont == 'y' || cont == 'Y'){
            cout << "请输入下一个字符串" << endl;
        }else {
            break;
        }
    }
        cout << "拼接后的字符为" <<result << endl;

    
    return 0;
}
