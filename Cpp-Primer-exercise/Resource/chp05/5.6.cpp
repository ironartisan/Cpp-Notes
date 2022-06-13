#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{

    int g;

    cout <<"请输入成绩："<<endl;

    cin >> g;

    if (g < 0 || g > 100) {
        cout << "该成绩不合法" <<endl;
        return  -1;
    }
    if(g == 100) {
        cout << "等级成绩是：" << "A++" << endl;
        return -1;
    }

    if(g < 60) {
        cout << "等级成绩是：" << "F" << endl;
        return -1;
    }

    int i = g /10;
    int j = g % 10;
    string score, level, finalGrade;

    score = (i == 9) ? "A" :(i == 8) ? "B": (i == 7)? "C":"D";
    level = (j > 7) ? "+" : (j < 3)? "-": "";

    finalGrade = score + level;

    cout << "等级成绩是：" << finalGrade << endl;
    return 0;
}