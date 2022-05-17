#include <iostream>
#include <vector>

using namespace std;

int main()
{


    const int sz = 10;
    vector<int> words;
    int nums[10];

    for (int i = 0; i < sz; i++) {
        words.push_back(i);
    }

    auto it = words.cbegin();
    for (auto & val : nums) {
        val = *it;
        cout << val << " ";
        it++;
    }
    cout << endl;


    return 0;
}