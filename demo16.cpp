// c++数组2
/*
// 多维数组
C++ 支持多维数组。多维数组最简单的形式是二维数组。

// 指向数组的指针
可以通过指定不带索引的数组名称来生成一个指向数组中第一个元素的指针

// 传递数组给函数
可以通过指定不带索引的数组名称来给函数传递一个指向数组的指针

// 从函数返回数组
C++ 允许从函数返回数组。
*/


// 多维数组
/*
C++ 支持多维数组。多维数组最简单的形式是二维数组。
多维数组声明: 数据类型 数组名[整型常量][整型常量]  int threedim[5][10];
一个二维数组，在本质上，是一个一维数组的列表。声明一个 x 行 y 列的二维整型数组
二维数组中的每个元素是使用形式为 a[ i , j ] 的元素名称来标识的，其中 a 是数组名称，i 和 j 是唯一标识 a 中每个元素的下标。

// 初始化二维数组
int seconddim[3][4] = {
	{0, 1, 2, 3},  初始化索引号为 0 的行
	{4, 5, 6, 7},  初始化索引号为 1 的行
	{8, 9, 10, 11} 初始化索引号为 2 的行
};
内部嵌套的括号是可选的，下面的初始化与上面是等同的：
int a[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};

// 访问二维数组元素
二维数组中的元素是通过使用下标（即数组的行索引和列索引）来访问的 int val = a[2][3];

*/
#include <iostream>

using namespace std;
int main()
{
	// 一个带有 5 行 2 列的数组
	int a[5][2] = { { 0, 1 }, { 2, 3 }, { 4, 5 }, { 6, 7 }, { 8, 9 } };
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << "a[" << i << "][" << j << "]: " << a[i][j] << endl;
		}
	}
	return 0;

}
