#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::vector;

int main() {
    vector<unsigned> v(11);
    auto it = v.begin();
    int i;
    cout << "请输入一组成绩"<<endl;
    while(cin >> i) {
        if (i < 101) {
            ++*(it + i / 10);
        }
    }
    cout << "各分数段的人数分布式" << endl;
    for (it  = v.begin(); it!= v.end();it++) {
        cout <<  *it << " ";
    }
    cout << endl;
    return 0;
}