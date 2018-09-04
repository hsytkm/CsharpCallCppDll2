#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "BinReader.h"

// ファイルパスの設定
void BinReader::SetFilePath(std::string path) {
	inputFilePath = path;
}

// 設定済みファイルパスの読み込み
void BinReader::ReadFileBinary() {
	using namespace std;

	string path = inputFilePath;

#if false
	// string -> char*
	char* outPath = new char[path.size() + 1];
	std::char_traits<char>::copy(outPath, path.c_str(), path.size() + 1);

	// ファイルを開く (ios::in は読み込み専用, ios::binary はバイナリ形式)
	ifstream file(outPath, ios::in | ios::binary);

	delete[] outPath; // メモリ解放
#else
	// ファイルを開く (ios::in は読み込み専用, ios::binary はバイナリ形式)
	// string を直で char* に入れても行けた。◆OKな理由を調べてない。
	ifstream file(path, ios::in | ios::binary);
#endif

	//  ファイルが開けなかったときの対策
	if (!file.is_open()) {
		cout << "ファイルが開けません";
		return;
	}

#if false
	// バイナリのコンソール表示
	char buf[16];
	while (!file.eof()) {
		file.read(buf, sizeof(buf));

		for (int i = 0, size = (int)file.gcount(); i < size; ++i) {
			cout << buf[i] << std::flush;
		}
	}
	cout << endl;
#endif

	// ファイルサイズの取得 (終端までシークして、現在位置を取得)
	file.seekg(0, ios::end);
	size_t size = static_cast<size_t>(file.tellg());	// static_castに意味なし(お試し)

	// 配列にバイナリを読み出し
	char* buf = new char[size];
	file.seekg(0, 0);
	file.read(buf, size);

	// 確保済みかもしれんから解放してから設定 (delereはnullで読んでも何も起きない)
	delete[] binaryBuf;
	binaryBuf = buf;
	binarySize = size;

	file.close();  //ファイルを閉じる
}

// 読み込み済みのバイナリを返す
int BinReader::GetBinarySize() const {

	return binarySize;
}

// 読み込み済みのバイナリを返す
const char* BinReader::GetBinaryPointer() const {

	if (binaryBuf == nullptr) return nullptr;

	return (const char*)binaryBuf;
}
