#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::vector;

int main() {
    vector<string> v;
    string w;
    cout << "请输入一段话" << endl;

    while (getline(cin, w)) { //利用getline读取一句话，直接回车产生一个空串，表示段落结束
        v.push_back(w);
    }
    for(auto it = v.begin(); it != v.end() && !it -> empty();it++) {
        for (auto it2 = it->begin(); it2 != it->end(); it2++){
            *it2 = toupper(*it2);
        }
        cout << *it << endl;
    }
    return 0;
}