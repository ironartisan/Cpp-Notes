#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::vector;

int main() {
    vector<int> v;
    int  w;
    cout << "请输入数字" << endl;
    while (cin >> w) {
        v.push_back(w);
    }
    if (v.size() == 0) {
        cout << "没有任何元素" <<endl;
        return -1;
    }
    cout << "相邻一组数的和为：" <<endl;
    for(decltype((v.size())) i = 0; i < v.size() - 1; i += 2)
        cout << v[i] + v[i + 1] << " ";

    if (v.size() % 2 != 0)
        cout << v[v.size() - 1];
    cout <<endl;

    cout << "首尾两项数的和为：" <<endl;
    decltype(v.size())  i = 0, j = v.size() - 1;
    while (i < j) {
        cout << v[i] +v[j] << " ";
        ++i,--j;
    }
    if (v.size() % 2 != 0)
        cout << v[v.size() / 2];
    cout <<endl;
    return 0;
}