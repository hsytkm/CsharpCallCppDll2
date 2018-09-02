#include "stdafx.h"
#include <iostream>

#include "CppCliDll.h"

CppCliDll::CliDll::CliDll()
{
	std::cout << "Call Constractor" << std::endl;
	nativeCppClass = new NativeCppClass();
}

CppCliDll::CliDll::CliDll(int num)
{
	std::cout << "Call Constractor(int)" << std::endl;
	nativeCppClass = new NativeCppClass(num);
}

CppCliDll::CliDll::CliDll(int x1, int x2)
{
	std::cout << "Call Constractor(int,int)" << std::endl;
	nativeCppClass = new NativeCppClass(x1 * x2);
}


// デストラクタ(マネージド/アンマネージド両方とも解放)
CppCliDll::CliDll::~CliDll()
{
	std::cout << "Call Destractor" << std::endl;
	// (ここでマネージドリソースを解放)

	this->!CliDll();
}

// ファイナライザ(アンマネージドリソースのみ解放)
CppCliDll::CliDll::!CliDll()
{
	std::cout << "Call Finalizer" << std::endl;

	// (ここでアンマネージドリソースを解放)
	delete nativeCppClass;
}

int CppCliDll::CliDll::GetInt()
{
	return nativeCppClass->GetParam();
}
