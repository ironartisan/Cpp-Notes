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
    if (v.cbegin() == v.cend()) {
        cout << "没有任何元素" <<endl;
        return -1;
    }
    cout << "首尾两项的和为：" <<endl;
    auto begin = v.begin();
    auto end = v.end();
    for(auto it = begin; it != begin + (end - begin) / 2; it ++){
        cout <<  (*it + *(begin + (end - it) - 1))<< " ";

    if (v.size() % 2 != 0)
        cout <<  *(begin + (end - it + 1)/ 2);
    cout <<endl;
    }

    return 0;
}