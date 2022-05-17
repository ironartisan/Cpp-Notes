#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::vector;

int main() {

    vector<int> words;
    for (int i = 0; i < 10; i++) {
        words.push_back(rand() % 1000);
    }
    cout << "随机生成的数字是：" <<endl;
    for(auto it = words.begin(); it != words.end() && !words.empty(); it++) {
        cout << *it << " ";
    }
    cout <<endl;

    cout << "翻倍后的数字是：" <<endl;

    for(auto it = words.begin(); it != words.end() && !words.empty(); it++) {
        *it = *it * 2;
        cout << *it << " ";
    }
    return 0;
}