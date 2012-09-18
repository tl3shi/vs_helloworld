// helloworld.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;
void myout(int);
template <class T>
T my_max(T t1, T t2)
{
	return t1 > t2 ? t1 : t2;
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "hello world" << endl;
	int n = 5;
	int m = 9;
	list<int> test_list;
	int t_array[] = {1, 2, 3, 4};
	test_list.insert(test_list.end(), 4, 3);
	for_each(test_list.begin(), test_list.end(), myout);
	cout << my_max(1, 4) << endl;
	cout << my_max(1.4, 4.8) << endl;
	max(1,3);
	return 0;
}
void myout(int a)
{
	cout << a << " ";
}
