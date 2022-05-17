#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::vector;

int main() {
    const int sz = 10;
    int nums[sz];
    for (int i = 0; i < sz; i++) {
        nums[i] = i;
    }


    for (auto ptr = nums; ptr != nums + sz; ++ptr) *ptr = 0;
//    int *p = begin(nums);
//    while (p != end(nums)) {
//        *p = 0;
//        p++;
//    }

    for (auto num : nums) {
       cout << num << " ";
    }
    cout << endl;
    return 0;
}