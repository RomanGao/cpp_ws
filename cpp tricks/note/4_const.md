### 1.Cpp中的常量
- 常量是固定值，在程序执行期间不会改变。这些固定的值，又叫做字面量。
- 常量可以是任何的基本数据类型，可分为整型数字、浮点数字、字符、字符串和布尔值。
- 常量就像是常规的变量，只不过常量的值在定义后不能进行修改。
### 2.整型常量
- 整数常量可以是十进制、八进制或十六进制的常量。前缀指定基数：0x 或 0X 表示十六进制，0 表示八进制，不带前缀则默认表示十进制。
- 整数常量也可以带一个后缀，后缀是 U 和 L 的组合，U 表示无符号整数（unsigned），L 表示长整数（long）。后缀可以是大写，也可以是小写，U 和 L 的顺序任意。
- 整型常量的例子:
```
212         // 合法的
215u        // 合法的
0xFeeL      // 合法的
078         // 非法的：8 不是八进制的数字
032UU       // 非法的：不能重复后缀
//----------------------------------------------------------//
85         // 十进制
0213       // 八进制 
0x4b       // 十六进制 
30         // 整数 
30u        // 无符号整数 
30l        // 长整数 
30ul       // 无符号长整数
```
### 3.浮点常量
- 浮点常量由整数部分、小数点、小数部分和指数部分组成。您可以使用小数形式或者指数形式来表示浮点常量。
- 当使用小数形式表示时，必须包含整数部分、小数部分，或同时包含两者;当使用指数形式表示时，必须包含小数点、指数，或同时包含两者。带符号的指数是用e或E引入的。
- 浮点常量实例如下：
```
3.14159       // 合法的 
314159E-5L    // 合法的 
510E          // 非法的：不完整的指数
210f          // 非法的：没有小数或指数
.e55          // 非法的：缺少整数或分数
```
### 4.bool常量
- 布尔常量共有两个，它们都是标准的 C++ 关键字,不应把true的值看成1，把false的值看成0：
    - true 值代表真
    - false 值代表假
### 5.字符常量
- 字符常量是括在单引号''中。如果常量以 L（仅当大写时）开头，则表示它是一个宽字符常量（例如 L'x'），此时它必须存储在 wchar_t 类型的变量中。否则，它就是一个窄字符常量（例如 'x'），此时它可以存储在 char 类型的简单变量中。
- 字符常量可以是一个普通的字符（例如 'x'）、一个转义序列（例如 '\t'），或一个通用的字符（例如 '\u02C0'）
- 在 C++ 中，有一些特定的字符，当它们前面有反斜杠时，它们就具有特殊的含义，被用来表示如换行符（\n）或制表符（\t）等。下表列出了一些这样的转义序列码：
![常见转义字符.png](https://upload-images.jianshu.io/upload_images/13407176-1ea487b23fa6bd2a.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
- 转义字符代码：
```
int main()
{
   cout << "Hello\tWorld\n\n";
   return 0;
}
```
### 6.字符串常量
- 字符串字面值或常量是括在双引号" "中的。一个字符串包含类似于字符常量的字符：普通的字符、转义序列和通用的字符。
- 可以使用空格做分隔符，把一个很长的字符串常量进行分行。下面的实例显示了一些字符串常量。下面这三种形式所显示的字符串是相同的。
    ```
    "hello, dear"

    "hello, \

    dear"

    "hello, " "d" "ear"
    ```
### 7.定义常量
- 在 C++ 中，有两种简单的定义常量的方式：
    - 使用\#define 预处理器。
    - 使用 const 关键字。
- \#define 预处理器,使用#define预处理定义常量的形式：
```
格式：#define identifier value  
如下面的例子：
#include <iostream>
using namespace std;
 
#define LENGTH 10     // 不要加分号结尾！！！
#define WIDTH  5
#define NEWLINE '\n'
 
int main()
{
 
   int area;  
   
   area = LENGTH * WIDTH;
   cout << area;
   cout << NEWLINE;
   return 0;
}
```
- const关键字,可以使用 const 前缀声明指定类型的常量，如下所示：
```
格式：const typename variable = value;

#include <iostream>
using namespace std;
 
int main()
{
   const int  LENGTH = 10;
   const int  WIDTH  = 5;
   const char NEWLINE = '\n';
   int area;  
   
   area = LENGTH * WIDTH;
   cout << area;
   cout << NEWLINE;
   return 0;
}
```
- const限定符定以后是不可以改变的，所以在定义时必须赋初始值，要不然是错误的，除非这个变量是用extern修饰的外部变量！下面就是一个错误的例子
```
#include "iostream"
using namespace std;

int main(){
    const double PI;
    PI = 3.1415;  // 错误!
    const double PI = 3.1415;  // 正确！
    const int A=10;       // 正确
    const int A;          // 错误，没有赋初始值 
    extern const int A;   //正确，使用extern的外部变量
    cout << "圆周率: " << PI  << endl;  
    return 0;
}

```
### 8.宏定义\#define与const修饰符的对比
- 8.1 类型和安全检查不同
    - 宏定义是字符替换，没有数据类型的区别，同时这种替换没有类型安全检查，可能产生边际效应等错误；
    - const常量是常量的声明，有类型区别，需要在编译阶段进行类型检查
- 8.2 编译器处理不同
    - 宏定义是一个"编译时"概念，在预处理阶段展开，不能对宏定义进行调试，生命周期结束与编译时期；
    - const常量是一个"运行时"概念，在程序运行使用，类似于一个只读行数据
- 8.3 存储方式不同
    - 宏定义是直接替换，不会分配内存，存储与程序的代码段中；
    - const常量需要进行内存分配，存储与程序的数据段中
- 8.4 定义域不同
    ```
        void f1 ()
        {
            #define N 12
            const int n 12;
        }
        void f2 ()
        {
            cout<<N <<endl; //正确，N已经定义过，不受定义域限制
            cout<<n <<endl; //错误，n定义域只在f1函数中
        }
    ```
- 8.5 定义后能否取消
    - 宏定义可以通过#undef来使之前的宏定义失效
    - const常量定义后将在定义域内永久有效
    ```
        void f1()
        {
        #define N 12
        const int n = 12;

        #undef N //取消宏定义后，即使在f1函数中，N也无效了
        #define N 21//取消后可以重新定义
        }
    ```
- 8.6 是否可以做函数参数
    - 宏定义不能作为参数传递给函数
    - const常量可以在函数的参数列表中出现