#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int nums[] =  {1, 2, 3, 4} ;

    vector<int> words(begin(nums), end(nums));

    for (auto val : words) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}