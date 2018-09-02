#pragma once

#include "../Debug/NativeCppClass.h"

using namespace System;

namespace CppCliDll {
	public ref class CliDll
	{
	private:
		NativeCppClass* nativeCppClass; // ネイティブクラスへのポインタ

	public:
		CliDll();			// コンストラクタ
		CliDll(int num);	// コンストラクタ
		CliDll(int, int);	// コンストラクタ

		~CliDll();			// デストラクタ(マネージド/アンマネージド両方とも解放)
		!CliDll();			// ファイナライザ(アンマネージドリソースのみ解放)

		int GetInt();
	};
}
