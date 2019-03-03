// LibTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 将LibDemo.lib添加到 链接器 附加依赖项
// 将LibDemo.lib的目录 添加到 连接器 常规 附加库目录
// 将Vector.h 添加到资源文件 
// 将Vector.h的目录添加到  VC++目录包含目录
#include "pch.h"
#include "Vector.h"
#include <iostream>
using std::cout; using std::endl;
int main()
{
    std::cout << "Hello World!\n"; 
    Vector v1(5.1, 6);
    v1.show();

    Vector v2(3);
    v2.show();

    Vector v3 = v1 + v2;  
    v3.show();

    return 0;
}
