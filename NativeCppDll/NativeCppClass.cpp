// NativeCppClass.cpp : DLL アプリケーション用にエクスポートされる関数を定義します。
//

#include "stdafx.h"
#include <iostream>
#include "NativeCppClass.h"

NativeCppClass::NativeCppClass(int x) : param(x) {}

void NativeCppClass::SetParam(int x) {
	param = x;
}

std::string NativeCppClass::GetString(std::string inStr) const
{
	std::string str = "文字見えてますか？";
	return inStr.append(str);
}