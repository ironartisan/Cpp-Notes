#include <iostream>
#include "Sales_item.h"

int main() {
    Sales_item sum_item;

    for (Sales_item item; std::cin >> item; std::cout << item << std::endl) {
        sum_item += item;
    }

    std::cout << "sum is " << sum_item << std::endl;
    return 0;
}
