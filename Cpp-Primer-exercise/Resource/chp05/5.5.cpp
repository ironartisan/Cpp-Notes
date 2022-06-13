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

    if(i == 9)
        score = "A";
    else if (i == 8)
        score = "B";
    else if (i == 7)
        score = "C";
    else
        score = "D";

    if (j > 7) {
        level = "+";
    }else if (j < 3) {
        level = "-";
    }else {
        level = "";
    }
    finalGrade = score + level;

    cout << "等级成绩是：" << finalGrade << endl;
    return 0;
}