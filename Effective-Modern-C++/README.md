---
sort: 3
---

# Effective Modern C++ 笔记

![book](../images/Effective-Modern-C++.jpg)

## 目录

### 第一章 型别推导

[条款1：理解模板型别推导](./item1.md)

[条款2：理解auto型别推导](./item2.md)

[条款3：理解decltype](./item3.md)

[条款4：掌握查看型别推导结果的方法](./item4.md)


### 第二章 auto

[条款5：优先选用auto，而非显式型别声明](./item5.md)

[条款6：当auto推导的型别不符合要求时，使用带显式型别的初始化物习惯用法](./item6.md)


### 第三章 转向现代C++

[条款7：在创建对象时注意区分()和{}](./item7.md)

[条款8：优先选用nullptr,而非0或NULL](./item8.md)

[条款9：优先选用别名声明，而非typedef](./item9.md)

[条款10：优先选用限定作用域的枚举型别，而非不限作用域的枚举型别](./item10.md)

[条款11：优先选用删除函数，而非private未定义函数](./item11.md)

[条款12：为意在改写的函数添加override声明](./item12.md)

[条款13：优先选用const_iterator,而非iterator](./item13.md)

[条款14：只要函数不会发射异常，就为其加上noexcept声明](./item14.md)

[条款15：只要有可能使用constexpr，就使用它](./item15.md)

[条款16：保证const成员函数的线程安全性](./item16.md)

[条款17：理解特种成员函数的生成机制](./item17.md)

### 第四章 智能指针

[条款18：使用std::unique_ptr管理具备专属所有权的资源](./item18.md)

[条款19：使用std::shared_ptr管理具备共享所有权的资源](./item19.md)

[条款20：对于类似std::shared_ptr但有可能空悬的指针使用std::weak_ptr](./item20.md)

[条款21：优先选用std::make_unique和std::make_shared，而非直接使用new](./item21.md)

[条款22：使用Pimpl习惯用法时，将特殊成员函数的定义放在实现文件中](./item22.md)
### 第五章 右值引用、移动语义和完美转发

[条款23：理解std::move和std::forward](./item23.md)

[条款24：区分万能引用和右值引用](./item24.md)

[条款25：针对右值引用实施std::move，针对万能引用实施std::forward](./item25.md)

[条款26：避免依万能引用型别进行重载](./item26.md)

[条款27：熟悉依万能引用型别进行重载的替代方案](./item27.md)

[条款28：理解引用折叠](./item28.md)

[条款29：假定移动操作不存在、成本高、未使用](./item29.md)

[条款30：熟悉完美转发的失败情形](./item30.md)

### 第六章 lambda表达式

[条款31：避免默认捕获模式](./item31.md)

[条款32：使用初始化捕获将对象移入闭包](./item32.md)

[条款33：对auto&&型别的形参使用decltype，以std::forward之](./item33.md)

[条款34：优先选用lambda式，而非std::bind](./item34.md)

### 第七章 并发API

[35：优先选用基于任务而非基于线程的程序设计](./item35.md)

[36：如果异步是必要的，则指定std::lauch::async](./item36.md)

[37：使std::thread型别对象在所有路径皆不可联结](./item37.md)

[38：对变化多端的线程句柄析构函数行为保持关注](./item38.md)

[39：考虑针对一次性事件通信使用以void为模板性别实参的期值](./item39.md)

[40：对并发使用std::atomic，对特种内存使用volatile](./item40.md)
### 第8章 微调

[41：针对可复制的形参，在移动成本低并且一定会被复制的前提下，考虑将其按值传递](./item41.md)

[42：考虑置入而非插入](./item42.md)