#pragma once

#include <iostream>
#include <msclr/marshal_cppstd.h>
#include "../Debug/Pet.h"

using namespace msclr::interop;

namespace CppCliDll {
	public ref class PetWrapper
	{
	public:
		// C++/CLIの列挙体定義 https://msdn.microsoft.com/ja-jp/library/tzz3794d.aspx?f=255&MSPPError=-2147217396
		enum class PetTypeWrap { WDog, WCat, WUnknown };

	private:
		Pet* pet;

	public:
		// コンストラクタ
		PetWrapper() {
			std::cout << "PetTypeWrap: Call Constractor" << std::endl;
			pet = new Pet(Pet::Dog, "Pochi", 12);
		}

		// デストラクタ(マネージド/アンマネージド両方とも解放)
		~PetWrapper()
		{
			std::cout << "PetTypeWrap: Call Destractor" << std::endl;
			// (以下でマネージドリソースを解放)

			this->!PetWrapper();
		}

		// ファイナライザ(アンマネージドリソースのみ解放)
		!PetWrapper()
		{
			std::cout << "PetTypeWrap: Call Finalizer" << std::endl;

			// (以下でアンマネージドリソースを解放)
			delete pet;
		}

		Pet* GetPetClass() { return pet; }
		PetTypeWrap GetPetType();
		System::String^ GetPetName() { return marshal_as<System::String^>(pet->GetName()); }
		int GetPetAge() { return pet->GetAge(); }

	};
}
