#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {

    string finalGrade;
    int grade;

    cout <<"请输入成绩"  << endl;

    while (cin >> grade && grade >=0 && grade <=100) {
        finalGrade = (grade >90) ?  "high pass": (grade > 75)? "pass": (grade > 60) ? "low pass": "fail";
    }
    cout << "等级为" << finalGrade << endl;

    // -------------------------
    if (grade > 90)         cout << "high pass";
    else if (grade < 60)    cout << "fail";
    else if (grade < 75)    cout << "low pass";
    else                cout << "pass";
    cout << endl;

    return 0;
}
