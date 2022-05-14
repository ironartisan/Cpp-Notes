//
// Created by ChenYL on 2022/5/14.
//

#ifndef PAT_SALES_DATA_H
#define PAT_SALES_DATA_H
# include <iostream>
# include <string>

class Sales_data {
friend std::istream& operator >> (std::istream&, Sales_data&);
friend std::ostream& operator >> (std::ostream&, const Sales_data&);
friend bool operator < (const Sales_data&, const Sales_data&);
friend bool operator == (const Sales_data&, const Sales_data&);

public:
    Sales_data() = default;
    Sales_data(const std::string &book):bookNo(book) { }
    Sales_data(std::istream &is) {is >> *this;}

public:
    Sales_data& operator += (const Sales_data&);
    std::string isbn() const { return bookNo;}

private:
    std::string bookNo;          //书籍编号
    unsigned units_sold = 0;     //销售量
    double selling_price = 0.0;  //原始价格
    double sale_price =0.0;      //市售价格
    double discount = 0.0;        //折扣
};

inline bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.isbn() == rhs.isbn();
}

inline bool operator !=(const Sales_data &lhs, const Sales_data &rhs) {
    return !(lhs == rhs); //基于运算符==给出!=的定义
}

Sales_data& Sales_data::operator+=(const Sales_data& rhs) {
    units_sold += rhs.units_sold;
    sale_price = (rhs.sale_price * rhs.units_sold + sale_price * units_sold) / (rhs.units_sold + units_sold);
    if (selling_price != 0)
        discount = sale_price / selling_price;
    return *this;
}

Sales_data operator + (const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data ret(lhs);//把hs的内容拷贝到临时变量ret中，这种做法便于运算
    ret += rhs; //把rhs的内容加入其中
    return ret; //返回ret
}

std::istream& operator >> (std::istream& in, Sales_data& s) {
    in >> s.bookNo >> s.units_sold >> s.selling_price >> s.sale_price;
    if (in && s.selling_price != 0)
        s.discount = s.sale_price / s.selling_price;
    else
        s = Sales_data();//输入错误，重置输入的数据
        return in;
}

std::ostream& operator << (std::ostream& out,const Sales_data& s)
{
    out << s.isbn();
//    out << s.isbn() <<" " << s.units_sold << " "<< s.selling_price <<""<< s.sale_price <<""<< s.discount;
    return out;
}

#endif //PAT_SALES_DATA_H
