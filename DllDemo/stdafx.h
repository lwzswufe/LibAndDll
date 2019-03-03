// stdafx.h: 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 项目特定的包含文件
//

#pragma once
#define DLL_EXPORTS
#ifndef DLL_EXPORTS
#define DEMO_API _declspec(dllimport)   // 加载
#else
#define DEMO_API _declspec(dllexport)   // 生成
#endif
#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 从 Windows 头文件中排除极少使用的内容
// Windows 头文件
#include <windows.h>
#include <string>
using std::string;

#include <cstdio>

#include <iostream>
using std::cout; using std::endl; using std::ostream;

#include <cmath>


// 在此处引用程序需要的其他标头
