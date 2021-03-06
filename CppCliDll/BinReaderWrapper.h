#pragma once

#include <iostream>
#include <msclr/marshal_cppstd.h>
#include "../Debug/BinReader.h"

using namespace msclr::interop;

namespace CppCliDll {
	public ref class BinReaderWrapper
	{
	private:
		BinReader* binReader;

	public:
		// コンストラクタ
		BinReaderWrapper()
		{
			std::cout << "BinReaderWrapper: Call Constractor" << std::endl;
			binReader = new BinReader();
		}

		// デストラクタ(マネージド/アンマネージド両方とも解放)
		~BinReaderWrapper()
		{
			std::cout << "BinReaderWrapper: Call Destractor" << std::endl;
			// (以下でマネージドリソースを解放)

			this->!BinReaderWrapper();
		}

		// ファイナライザ(アンマネージドリソースのみ解放)
		!BinReaderWrapper()
		{
			std::cout << "BinReaderWrapper: Call Finalizer" << std::endl;

			// (以下でアンマネージドリソースを解放)
			delete binReader;
		}

		// 読み込むファイルPATHを文字列で渡す
		void WrapSetFilePath(System::String^ inputPath1) {
			std::string inStr = marshal_as<std::string>(inputPath1);
			binReader->SetFilePath(inStr);
		}

		// 設定済みファイルパスの読み込み
		void WrapReadFileBinary() { binReader->ReadFileBinary(); }

		// 読み込み済みのバイナリサイズを返す
		int WrapGetBinarySize() { return binReader->GetBinarySize(); }

		// 読み込み済みのバイナリポインタを返す
		System::IntPtr WrapGetBinaryPointer() {
			void *bin = (void*)binReader->GetBinaryPointer();
			return System::IntPtr(bin);
		}

	};
}
