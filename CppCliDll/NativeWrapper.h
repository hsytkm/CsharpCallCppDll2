#pragma once

#include "../Debug/Pet.h"
#include "../Debug/BinReader.h"

namespace CppCliDll {
	public ref class NativeWrapper
	{
	public:
		// C++/CLIの列挙体定義 https://msdn.microsoft.com/ja-jp/library/tzz3794d.aspx?f=255&MSPPError=-2147217396
		enum class PetTypeWrap { WDog, WCat, WUnknown };

	private:
		Pet* pet;
		BinReader* binReader;

	public:
		NativeWrapper();			// コンストラクタ
		NativeWrapper(int, int);	// コンストラクタ

		~NativeWrapper();			// デストラクタ(マネージド/アンマネージド両方とも解放)
		!NativeWrapper();			// ファイナライザ(アンマネージドリソースのみ解放)

		// Pet
		Pet* GetPetClass() { return pet; }
		PetTypeWrap GetPetType();
		System::String^ GetPetName();
		int GetPetAge() { return pet->GetAge(); }

		// BinReader
		void WrapSetFilePath(System::String^);
		void WrapReadFileBinary();
		int WrapGetBinarySize();
		System::IntPtr WrapGetBinaryPointer();
	};
}
