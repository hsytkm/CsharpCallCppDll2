#pragma once

class BinReader {
private:
	std::string inputFilePath;
	int binarySize = 0;
	char* binaryBuf = nullptr;

public:
	BinReader() {}
	~BinReader()
	{
		delete[] binaryBuf;
		binaryBuf = nullptr;
	}

	void SetFilePath(std::string path);
	void ReadFileBinary();
	int GetBinarySize() const;
	const char* GetBinaryPointer() const;
};
