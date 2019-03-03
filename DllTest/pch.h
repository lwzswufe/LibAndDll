#ifndef PCH_H
#define PCH_H
#ifndef DLL_EXPORTS
#define DEMO_API _declspec(dllimport)   // 加载
#else
#define DEMO_API _declspec(dllexport)   // 生成
#endif
// TODO: 添加要在此处预编译的标头
#include <string>
using std::string;
#endif //PCH_H
