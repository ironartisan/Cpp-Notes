#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char str1[] = "Welcome to";
    char str2[] = "C++";

    char result[strlen(str1) + strlen(str2)  - 1];

    strcpy(result, str1);
    strcat(result, str2);

    cout << "第一个字符为" << str1 <<endl;
    cout << "第二个字符为" << str2 <<endl;
    cout << "拼接后的字符为" << result <<endl;

    return 0;
}