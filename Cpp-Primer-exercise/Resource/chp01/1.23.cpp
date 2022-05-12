#include <iostream>
#include "Sales_item.h"

int main() {
    Sales_item item1, item2;
    int num = 1;
    std::cout << "请输入销售记录" << std::endl;

    if (std::cin >> item1) {
        while (std::cin >> item2) {
            if (compareIsbn(item1, item2)) { //相同
                num++;
            }
            else {
                std::cout << item1.isbn() << "共有 " << num << "条销售记录" << std::endl;
                item1 = item2;
                num = 1;
            }
        }
        std::cout << item1.isbn() << "共有 " << num << "条销售记录" << std::endl;
    }
    else {
        std::cerr << "没有数据" <<std::endl;
        return -1;
    }

    return 0;
}
