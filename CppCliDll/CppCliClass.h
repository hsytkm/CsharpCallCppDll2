#pragma once
#include "Person.h"

namespace CppCliDll {
	public ref class CppCliClass
	{
	private:
		Person^ person;

	public:
		CppCliClass();			// コンストラクタ
		~CppCliClass();			// デストラクタ(マネージド/アンマネージド両方とも解放)
		!CppCliClass();			// ファイナライザ(アンマネージドリソースのみ解放)

		// テスト関数
		int Multi(int x, int y);
		System::String^ ToUpper(System::String^ lower);

		// 自作クラス操作
		System::String^ GetPersonName() { return person->GetName(); }
		int GetPersonAge() { return person->GetAge(); }
		Person^ GetPersonClass() { return person; }

	};
}
