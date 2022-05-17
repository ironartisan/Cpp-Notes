#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1;         // size:0,  no values.
    vector<int> v2(10);     // size:10, value:0
    vector<int> v3(10, 42); // size:10, value:42
    vector<int> v4{ 10 };     // size:1,  value:10
    vector<int> v5{ 10, 42 }; // size:2,  value:10, 42
    vector<string> v6{ 10 };  // size:10, value:""
    vector<string> v7{ 10, "hi" };  // size:10, value:"hi"

    cout << "v1 size :" << v1.size() << endl;
    cout << "v2 size :" << v2.size() << endl;
    cout << "v3 size :" << v3.size() << endl;
    cout << "v4 size :" << v4.size() << endl;
    cout << "v5 size :" << v5.size() << endl;
    cout << "v6 size :" << v6.size() << endl;
    cout << "v7 size :" << v7.size() << endl;

    cout << "v1 content: ";
    if (v1.cbegin() != v1.cend()) {
        for (auto it = v1.cbegin(); it != v1.cend(); it++) {
            cout << *it << " , ";
        }
        cout << endl;
    }
    cout << "v2 content: ";
    if (v2.cbegin() != v2.cend()) {
        for (auto it = v2.cbegin(); it != v2.cend(); it++) {
            cout << *it << " , ";
        }
        cout << endl;
    }

    cout << "v3 content: ";
    if (v3.cbegin()!= v3.cend()) {
        for (auto it = v3.cbegin(); it != v3.cend(); it++){
            cout << *it << " , ";
        }
        cout << endl;
    }



    cout << "v4 content: ";
    if (v4.cbegin() != v4.cend()) {
        for(auto it = v4.cbegin(); it != v4.cend(); it++) {
            cout << *it << ",";
        }
        cout << endl;
    }

    cout << "v5 content: ";
    if (v5.cbegin() != v5.cend()) {
        for(auto it = v5.cbegin(); it != v5.cend(); it++) {
            cout << *it << ",";
        }
        cout << endl;
    }


    cout << "v6 content: ";
    if (v6.cbegin() != v6.cend()) {
        for(auto it = v6.cbegin(); it != v6.cend(); it++) {
            cout << *it << ",";
        }
        cout << endl;
    }


    cout << "v7 content: ";
    if (v7.cbegin() != v7.cend()) {
        for(auto it = v7.cbegin(); it != v7.cend(); it++) {
            cout << *it << ",";
        }
        cout << endl;
    }

    return 0;
}