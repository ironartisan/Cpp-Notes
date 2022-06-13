#include <iostream>

using namespace std;


int main()
{
    unsigned int flCnt = 0, ffCnt = 0, fiCnt = 0;
    char ch, prech= '\0';
    cout << "请输入一段文本" << endl;
    while (cin >> ch)
    {
        bool flag = true;
        if (prech == 'f') {
            switch (ch) {
                case 'f':
                    ++ffCnt;
                    flag = false;
                    break;
                case 'l':
                    ++flCnt;
                    break;
                case 'i':
                    ++flCnt;
                    break;
            }
        }
        if (!flag) {
            prech = '\0';
        }else {
            prech = ch;}
        }
    cout << "Number of ff : \t" << ffCnt << '\n'
         << "Number of fi \t" << fiCnt << '\n'
         << "Number of fl: \t" << flCnt << '\n'
         << endl;

    return 0;
}