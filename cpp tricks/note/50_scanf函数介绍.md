### 1.scanf函数:读取从键盘输入的数据
- 在C语言中，有多个函数可以从键盘获得用户输入：
    - scanf()：和 printf() 类似，scanf() 可以输入多种类型的数据
    - getchar()、getche()、getch()：这三个函数都用于输入单个字符
    - gets()：获取一行数据，并作为字符串处理
- scanf函数详解:意思是格式化扫描，也就是从键盘获得用户输入,和printf的功能正好相反。实例如下:
    ```
        #include "iostream"
        #include "cstdio"
        #include "cstdlib"


        using namespace std;



        int main(){
            // scanf函数介绍
            int a = 0, b = 0, c = 0, d=0;
            scanf("%d", &a);
            scanf("%d", &b);

            printf("a+b = %d\n", a+b);

            scanf("%d %d", &c, &d);
            printf("c*d = %d\n", c*d);
            return 0;
        }
    ```
- 从键盘输入12，按下回车键，scanf()就会读取输入数据并赋值给变量 a；本次输入结束，接着执行下一个 scanf()函数，再从键盘输入 60，按下回车键，就会将60赋值给变量b，都是同样的道理。scanf("%d %d", &c, &d);**scanf()有两个以空格分隔的%d，后面还跟着两个变量，这要求我们一次性输入两个整数，并分别赋值给c和d。注意"%d %d"之间是有空格的，所以输入数据时也要有空格。对于scanf()，输入数据的格式要和控制字符串的格式保持一致**。
- 其实scanf和printf非常相似，只是功能相反罢了。它们都有格式控制字符串，都有变量列表。**不同的是，scanf的变量前要带一个&符号。&称为取地址符，也就是获取变量在内存中的地址**。
    ```
        scanf("%d %d", &a, &b);  // 获取用户输入的两个整数，分别赋值给变量 a 和 b
        print("%d %d", a, b);  // 将变量 a 和 b 的值在显示器上输出
    ```
- 再来看一个scanf函数的例子:
    ```
        #include "iostream"
        #include "cstdio"
        #include "cstdlib"


        using namespace std;



        int main(){
            // scanf函数的实例2
            int a_, b_, c_;
            scanf("%d %d", &a_, &b_);
            printf("a_+b_=%d\n", a_+b_);

            scanf("%d   %d", &a_, &b_);
            printf("a_+b_=%d\n", a_+b_);

            scanf("%d, %d, %d", &a_, &b_, &c_);
            printf("a_+b_+c_=%d\n", a_+b_+c_);

            scanf("%d is bigger than %d", &a_, &b_);
            printf("a_-b_=%d\n", a_- b_);
            return 0;
        }
    ```
- 第一个scanf()的格式控制字符串为"%d %d"，中间有一个空格，而我们却输入了10    20，中间有多个空格。第二个scanf()的格式控制字符串为"%d   %d"，中间有多个空格，而我们却输入了100 200，中间只有一个空格。**这说明scanf()对输入数据之间的空格的处理比较宽松，并不要求空格数严格对应，多几个少几个无所谓，只要有空格就行**。
- 第三个scanf()的控制字符串为"%d, %d, %d"，**中间以逗号分隔，所以输入的整数也要以逗号分隔**。第四个scanf()要求整数之间以is bigger than分隔。用户每次按下回车键，程序就会认为完成了一次输入操作，scanf()开始读取用户输入的内容，并根据格式控制字符串从中提取有效数据，只要用户输入的内容和格式控制字符串匹配，就能够正确提取。**本质上讲，用户输入的内容都是字符串，scanf()完成的是从字符串中提取有效数据的过程**。
### 2.连续输入
- 第一个实例中都是一个一个地输入变量 a、b、c、d 的值，每输入一个值就按一次回车键。现在改变输入方式，将四个变量的值一次性输入，如下所示：
    ```
        12 60 10 23↙
        a+b=72
        c*d=230
    ```
- 可以发现，两个scanf()都能正确读取。合情合理的猜测是，第一个scanf()读取完毕后没有抛弃多余的值，而是将它们保存在了某个地方，下次接着使用。如果多输入一个整数，会怎样呢？
    ```
        12 60 10 23 99↙
        a+b=72
        c*d=230
    ```
- 这次多输入了一个 99，发现scanf()仍然能够正确读取，只是99没用罢了。如果少输入一个整数，又会怎样呢？
    ```
        12 60 10↙
        a+b=72
        23↙
        c*d=230
    ```
- 输入三个整数后，前两个scanf()把前两个整数给读取了，剩下一个整数10，而第三个scanf()要求输入两个整数，一个单独的10并不能满足要求，所以还得继续输入，凑够两个整数以后，第三个scanf()才能读取完毕。
- **从本质上讲，从键盘输入的数据并没有直接交给scanf()，而是放入了缓冲区中，直到按下回车键，scanf()才到缓冲区中读取数据。如果缓冲区中的数据符合scanf()的要求，那么就读取结束；如果不符合要求，那么就继续等待用户输入，或者干脆读取失败**。注意，如果缓冲区中的数据不符合scanf()的要求，要么继续等待用户输入，要么就干脆读取失败，上面演示了“继续等待用户输入”的情形，下面对代码稍作修改，演示“读取失败”的情形。
    ```
        #include "iostream"
        #include "cstdio"
        #include "cstdlib"


        using namespace std;


        int main(){
            // scanf函数实例3
            int a2 = 2, b2 = 3,c2 = 4, d2 = 5;  // 给变量赋予不同的初始值
            scanf("%d", &a2);
            scanf("%d", &b2);
            printf("a2=%d,b2=%d\n", a2, b2);

            scanf("%d", &c2);
            scanf("%d", &d2);
            printf("c2=%d, d2=%d\n", c2, d2);
            return 0;
        }
    ```
- 运行结果:
    ```
        12 60 a10↙
        a2=12, b2=60
        c2=3, d2=4
    ```
- 前两个整数被正确读取后，剩下了a10，而第三个scanf()要求输入两个十进制的整数，a10无论如何也不符合要求，所以只能读取失败。输出结果也证明了这一点，c2和d2的值并没有被改变。**这说明scanf()不会跳过不符合要求的数据，遇到不符合要求的数据会读取失败，而不是再继续等待用户输入。**
- **总而言之，正是由于缓冲区的存在，才使得我们能够多输入一些数据，或者一次性输入所有数据，这可以认为是缓冲区的一点优势。然而，缓冲区也带来了一定的负面影响，甚至会导致很奇怪的行为**，请看下面的代码：
    ```
        #include "iostream"
        #include "cstdio"
        #include "cstdlib"


        using namespace std;



        int main(){
            // scanf函数实例4
            int a1_ = 111, b1_=222;
            scanf("a1_=%d", &a1_);
            scanf("b1_=%d", &b1_);
            printf("a1_=%d, b1_=%d\n", a1_, b1_);
            return 0;
        }
    ```
- 输入示例：
    ```
        a1_=99↙
        a1_=99, b1_=222
    ```
- 输入a1_=99，按下回车键，程序竟然运行结束了，只有第一个scanf()成功读取了数据，第二个scanf()仿佛没有执行一样，根本没有给用户任何机会去输入数据。如果换一种输入方式呢？
    ```
        a1_=99b1_=200↙
        a1_=99, b1_=200
    ```
- 这样a1 和b1_都能够正确读取了,**注意：a1_=99b1_=200中间是没有任何空格的**。如果a1_=99b1_=200两个数据之间有空格又会怎么样呢？不妨试一下：
    ```
        a1_=99 b1_=200↙
        a1_=99, b1_=222  // 第二个 scanf() 又读取失败了！原因和缓冲区有关
    ```
### 3.输入其他数据
- 除了输入整数，scanf()还可以输入单个字符、字符串、小数等，请看下面的演示：
    ```
        #include "iostream"
        #include "cstdio"
        #include "cstdlib"


        using namespace std;



        int main(){
            // scanf函数实例5
            char name;
            int age;
            char url[30];
            float price;
            scanf("%c", &name);
            scanf("%d", &age);
            scanf("%s", url);  // 可以加&也可以不加&
            scanf("%f", &price);
            printf("26个英文字母的最后一个是%c\n", name);
            printf("博客已经写了%d月,网址是%s,赞赏是%f", age, url, price);
            return 0;
        }
    ```
- scanf()和printf()虽然功能相反，但是格式控制符是一样的，单个字符、整数、小数、字符串对应的格式控制符分别是 %c、%d、%f、%s。
### 4.对读取字符串的说明
- 字符串的两种定义形式，它们分别是：
    ```
        char str1[]="www.baidu.com";
        char *str2="百度";
    ```
- 这两种形式其实是有区别的，**第一种形式的字符串所在的内存既有读取权限又有写入权限，第二种形式的字符串所在的内存只有读取权限，没有写入权限**。printf()、puts()等字符串输出函数只要求字符串有读取权限，而scanf()、gets()等字符串输入函数要求字符串有写入权限，所以，第一种形式的字符串既可以用于输出函数又可以用于输入函数，而第二种形式的字符串只能用于输出函数。
- 另外，对于第一种形式的字符串，在[]里面要指明字符串的最大长度，如果不指明，也可以根据=后面的字符串来自动推算，此处，就是根据"www.baidu.com"的长度来推算的。但是在前一个例子中，开始只是定义了一个字符串，并没有立即给它赋值，所以没法自动推算，只能手动指明最大长度，这也就是为什么一定要写作char url[30]，而不能写作char url[]的原因。
- scanf("%s", url);这行代码用来输入字符串。上面说过，scanf()读取数据时需要的是数据的地址，整数、小数、单个字符都要加&取地址符，这很容易理解；但是对于此处的url字符串，并没有加&，这是因为，字符串的名字会自动转换为字符串的地址，所以不用再多此一举加&了。当然，你也可以加上，这样虽然不会导致错误，但是编译器会产生警告。
- **最后需要注意的一点是，scanf()读取字符串时以空格为分隔，遇到空格就认为当前字符串结束了，所以无法读取含有空格的字符串**，请看下面的例子：
    ```
        #include "iostream"
        #include "cstdio"
        #include "cstdlib"


        using namespace std;



        int main(){
            // scanf函数实例6
            char author[30], lang[30], urls[30];
            scanf("%s %s", author, lang);
            printf("author:%s\n lang:%s\n", author, lang);
            scanf("%s", urls);
            printf("urls:%s\n", urls);
            return 0;
        }
    ```
- 对于第一个scanf()，它将空格前边的字符串赋值给author，将空格后边的字符串赋值给lang；很显然，第一个字符串遇到空格就结束了，第二个字符串到了本行的末尾结束了。
### 5.scanf()格式控制符汇总
![scanf格式符汇总.png](https://upload-images.jianshu.io/upload_images/13407176-b396975f97304ac2.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
### 6.参考博客
[博客链接](https://blog.csdn.net/qq_43132512/article/details/85238528)
