---
sort: 1
---

# 条款1：型别推导

**学习目标：** 模板型别推导如何运作，`auto `的型别推导如何构建在此运作规则之上，以及`decltype`独特的型别推导规则，如何迫使编译器来展示其型别推导的结果。

## 条款1：理解模板型别推导

* 模板型别推导是 `auto` 的基础，但部分特殊情况下，模板型别推导机制不适用于 `auto`
* 模板的形式可以看成如下伪代码

```cpp
template <typename T>
void f(ParamType x);  // ParamType 即 x 的类型
```

* 调用可看成

```cpp
f(expr);
```

* 编译期间，编译器用 `expr` 推断 `T` 和 `ParamType` ，实际上两者通常不一致，比如

```cpp
template <typename T>
void f(const T& x);

int x;  // 为方便演示，只指定类型不初始化，后续同理
f(x);   // T 被推断为 int，ParamType 被推断为 const int&
```

* T 的类型推断与 expr 和 ParamType 相关


### 情形 1：ParamType 是个引用或指针，但不是万能引用

最简单的情况是当`ParamType`是一个引用类型或者是一个指针，但并非是万能引用。在这种情况下，类型推导的过程如下：

* 如果`expr`的类型是个引用，忽略引用的部分。
* 然后利用`expr`的类型和`ParamType`对比去判断`T`的类型。

举一个例子，如果这个是我们的模板，

```cpp
template<typename T>
void f(T& param);           // param是一个引用类型
```

我们有这样的代码变量声明：

```cpp
int x = 27;                 // x是一个int
const int cx = x;           // cx是一个const int
const int& rx = x;          // rx是const int的引用
```

`param`和`T`在不同的调用下面的类型推导如下：

```cpp
f(x);                       // T是int，param的类型时int&

f(cx);                      // T是const int，
                            // param的类型是const int&
f(rx);                      // T是const int
                            // param的类型时const int&
```

在第二和第三部分的调用，注意`cx`和`rx`由于被指定为`const`类型变量，`T`被推导成`const int`，这也就导致了参数的类型被推导为`const int&`。这对调用者非常重要。

当传递一个`const`对象给一个引用参数，他们期望对象会保留常量特性，也就是说，参数变成了`const`的引用。这也就是为什么给一个以`T&`为参数的模板传递一个`const`对象是安全的：对象的`const`特性是`T`类型推导的一部分。

在第三个例子中，注意尽管`rx`的类型是一个引用，`T`仍然被推导成了一个非引用的。这是因为`rx`的引用特性会被类型推导所忽略。

这些例子展示了左值引用参数的处理方式，但是类型推导在右值引用上也是如此。当然，右值参数只可能传递给右值引用参数，但是这个限制和类型推导没有关系。

如果我们把`f`的参数类型从`T&`变成`const T&`，情况就会发生变化，但是并不会令人惊讶。由于`param`的声明是`const`引用的，`cx`和`rx`的`const`特性会被保留，这样的话`T`的`const`特性就没有必要了。

```cpp
template<typename T>
void f(const T& param);     // param现在是const的引用

int x = 27;                 // 和之前一样
const int cx = x;           // 和之前一样
const int& rx = x;          // 和之前一样

f(x);                       // T是int，param的类型是const int&

f(cx);                      // T是int，param的类型是const int&

f(rx);                      // T是int，param的类型是const int&
```

和之前一样，`rx`的引用特性在类型推导的过程中会被忽略。

如果`param`是一个指针（或者指向`const`的指针）而不是引用，情况也是类似：

```cpp
template<typename T>
void f(T* param);           // param是一个指针

int x = 27;                 // 和之前一样
const int *px = &x;         // px是一个指向const int x的指针

f(&x);                      // T是int，param的类型是int*

f(px);                      // T是const int
                            // param的类型时const int*
```



### 情形2：`ParamType`是个万能引用（Universal Reference）

对于通用的引用参数，情况就变得不是那么明显了。这些参数被声明成右值引用（也就是函数模板使用一个类型参数`T`，一个通用的引用参数的申明类型是`T&&`），但是当传递进去右值参数情况变得不一样。完整的讨论请参考条款24，这里是先行版本。

- 如果`expr`是一个左值，`T`和`ParamType`都会被推导成左值引用。这有些不同寻常。第一，这是模板类型`T`被推导成一个引用的唯一情况。第二，尽管`ParamType`利用右值引用的语法来进行推导，但是他最终推导出来的类型是左值引用。
- 如果`expr`是一个右值，那么就执行“普通”的法则（第一种情况）

举个例子：

```cpp
template<typename T>
void f(T&& param);            // param现在是一个通用的引用

int x = 27;                 // 和之前一样
const int cx = x;           // 和之前一样
const int& rx = x;          // 和之前一样

f(x);                        // x是左值，所以T是int&
                            // param的类型也是int&

f(cx);                        // cx是左值，所以T是const int&
                            // param的类型也是const int&

f(rx);                        // rx是左值，所以T是const int&
                            // param的类型也是const int&

f(27);                        // 27是右值，所以T是int
                            // 所以param的类型是int&&
```

条款23解释了这个例子推导的原因。关键的地方在于通用引用的类型推导法则和左值引用或者右值引用的法则大不相同。特殊的情况下，当使用了通用的引用，左值参数和右值参数的类型推导大不相同。这在非通用的类型推到上面绝对不会发生。



### 情形3：`ParamType`既不是指针也不是引用

当`ParamType`既不是指针也不是引用时，我们通过传值（pass-by-value）的方式处理：

```
template<typename T>
void f(T param);                //以传值的方式处理param
```

这意味着无论传递什么`param`都会成为它的一份拷贝——一个完整的新对象。事实上`param`成为一个新对象这一行为会影响`T`如何从`expr`中推导出结果。

1. 和之前一样，如果`expr`的类型是一个引用，忽略这个引用部分
2. 如果忽略`expr`的引用性（reference-ness）之后，`expr`是一个`const`，那就再忽略`const`。如果它是`volatile`，也忽略`volatile`（`volatile`对象不常见，它通常用于驱动程序的开发中。关于`volatile`的细节请参见[Item40](./item40.md)）

因此

```
int x=27;                       //如之前一样
const int cx=x;                 //如之前一样
const int & rx=cx;              //如之前一样

f(x);                           //T和param的类型都是int
f(cx);                          //T和param的类型都是int
f(rx);                          //T和param的类型都是int
```

注意即使`cx`和`rx`表示`const`值，`param`也不是`const`。这是有意义的。`param`是一个完全独立于`cx`和`rx`的对象——是`cx`或`rx`的一个拷贝。具有常量性的`cx`和`rx`不可修改并不代表`param`也是一样。这就是为什么`expr`的常量性`const`ness（或易变性`volatile`ness)在推导`param`类型时会被忽略：因为`expr`不可修改并不意味着它的拷贝也不能被修改。

认识到只有在传值给形参时才会忽略`const`（和`volatile`）这一点很重要，正如我们看到的，对于reference-to-`const`和pointer-to-`const`形参来说，`expr`的常量性`const`ness在推导时会被保留。但是考虑这样的情况，`expr`是一个`const`指针，指向`const`对象，`expr`通过传值传递给`param`：

```
template<typename T>
void f(T param);                //仍然以传值的方式处理param

const char* const ptr =         //ptr是一个常量指针，指向常量对象 
    "Fun with pointers";

f(ptr);                         //传递const char * const类型的实参
```

在这里，解引用符号（*）的右边的`const`表示`ptr`本身是一个`const`：`ptr`不能被修改为指向其它地址，也不能被设置为null（解引用符号左边的`const`表示`ptr`指向一个字符串，这个字符串是`const`，因此字符串不能被修改）。当`ptr`作为实参传给`f`，组成这个指针的每一比特都被拷贝进`param`。像这种情况，`ptr`**自身的值会被传给形参**，根据类型推导的第三条规则，`ptr`自身的常量性`const`ness将会被省略，所以`param`是`const char*`，也就是一个可变指针指向`const`字符串。在类型推导中，这个指针指向的数据的常量性`const`ness将会被保留，但是当拷贝`ptr`来创造一个新指针`param`时，`ptr`自身的常量性`const`ness将会被忽略。

### 数组实参

上面的内容几乎覆盖了模板类型推导的大部分内容，但这里还有一些小细节值得注意，比如数组类型不同于指针类型，虽然它们两个有时候是可互换的。关于这个错觉最常见的例子是，在很多上下文中数组会退化为指向它的第一个元素的指针。这样的退化允许像这样的代码可以被编译：

```
const char name[] = "J. P. Briggs";     //name的类型是const char[13]

const char * ptrToName = name;          //数组退化为指针
```

在这里`const char*`指针`ptrToName`会由`name`初始化，而`name`的类型为`const char[13]`，这两种类型（`const char*`和`const char[13]`）是不一样的，但是由于数组退化为指针的规则，编译器允许这样的代码。

但要是一个数组传值给一个模板会怎样？会发生什么？

```
template<typename T>
void f(T param);                        //传值形参的模板

f(name);                                //T和param会推导成什么类型?
```

我们从一个简单的例子开始，这里有一个函数的形参是数组，是的，这样的语法是合法的，

```
void myFunc(int param[]);
```

但是数组声明会被视作指针声明，这意味着`myFunc`的声明和下面声明是等价的：

```
void myFunc(int* param);                //与上面相同的函数
```

数组与指针形参这样的等价是C语言的产物，C++又是建立在C语言的基础上，它让人产生了一种数组和指针是等价的的错觉。

因为数组形参会视作指针形参，所以传值给模板的一个数组类型会被推导为一个指针类型。这意味着在模板函数`f`的调用中，它的类型形参`T`会被推导为`const char*`：

```
f(name);                        //name是一个数组，但是T被推导为const char*
```

但是现在难题来了，虽然函数不能声明形参为真正的数组，但是**可以**接受指向数组的**引用**！所以我们修改`f`为传引用：

```
template<typename T>
void f(T& param);                       //传引用形参的模板
```

我们这样进行调用，

```
f(name);                                //传数组给f
```

`T`被推导为了真正的数组！这个类型包括了数组的大小，在这个例子中`T`被推导为`const char[13]`，`f`的形参（对这个数组的引用）的类型则为`const char (&)[13]`。是的，这种语法看起来简直有毒，但是知道它将会让你在关心这些问题的人的提问中获得大神的称号。

有趣的是，可声明指向数组的引用的能力，使得我们可以创建一个模板函数来推导出数组的大小：

```
//在编译期间返回一个数组大小的常量值（//数组形参没有名字，
//因为我们只关心数组的大小）
template<typename T, std::size_t N>                     //关于
constexpr std::size_t arraySize(T (&)[N]) noexcept      //constexpr
{                                                       //和noexcept
    return N;                                           //的信息
}                                                       //请看下面
```

在[Item15](./item15.md)提到将一个函数声明为`constexpr`使得结果在编译期间可用。这使得我们可以用一个花括号声明一个数组，然后第二个数组可以使用第一个数组的大小作为它的大小，就像这样：

```
int keyVals[] = { 1, 3, 7, 9, 11, 22, 35 };             //keyVals有七个元素

int mappedVals[arraySize(keyVals)];                     //mappedVals也有七个
```

当然作为一个现代C++程序员，你自然应该想到使用`std::array`而不是内置的数组：

```
std::array<int, arraySize(keyVals)> mappedVals;         //mappedVals的大小为7
```

至于`arraySize`被声明为`noexcept`，会使得编译器生成更好的代码，具体的细节请参见[Item14](./item14.md)。

### 函数实参

在C++中不只是数组会退化为指针，函数类型也会退化为一个函数指针，我们对于数组类型推导的全部讨论都可以应用到函数类型推导和退化为函数指针上来。结果是：

```
void someFunc(int, double);         //someFunc是一个函数，
                                    //类型是void(int, double)

template<typename T>
void f1(T param);                   //传值给f1

template<typename T>
void f2(T & param);                 //传引用给f2

f1(someFunc);                       //param被推导为指向函数的指针，
                                    //类型是void(*)(int, double)
f2(someFunc);                       //param被推导为指向函数的引用，
                                    //类型是void(&)(int, double)
```

这个实际上没有什么不同，但是如果你知道数组退化为指针，你也会知道函数退化为指针。

这里你需要知道：`auto`依赖于模板类型推导。正如我在开始谈论的，在大多数情况下它们的行为很直接。在通用引用中对于左值的特殊处理使得本来很直接的行为变得有些污点，然而，数组和函数退化为指针把这团水搅得更浑浊。有时你只需要编译器告诉你推导出的类型是什么。这种情况下，翻到[item4](./item4.md),它会告诉你如何让编译器这么做。

**总结：** 

- 在模板类型推导时，有引用的实参会被视为无引用，他们的引用会被忽略
- 对于通用引用的推导，左值实参会被特殊对待
- 对于传值类型推导，`const`和/或`volatile`实参会被认为是non-`const`的和non-`volatile`的
- 在模板类型推导时，数组名或者函数名实参会退化为指针，除非它们被用于初始化引用
