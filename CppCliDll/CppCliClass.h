#pragma once

namespace CppCliDll {
	public ref class CppCliClass
	{
	private:


	public:
		CppCliClass();			// コンストラクタ
		~CppCliClass();			// デストラクタ(マネージド/アンマネージド両方とも解放)
		!CppCliClass();			// ファイナライザ(アンマネージドリソースのみ解放)

		// テスト関数
		int Multi(int x, int y);
		System::String^ ToUpper(System::String^ lower);


	};
}
