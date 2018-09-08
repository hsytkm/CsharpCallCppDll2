#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "BinReader.h"

// �t�@�C���p�X�̐ݒ�
void BinReader::SetFilePath(std::string path) {
	inputFilePath = path;
}

// �ݒ�ς݃t�@�C���p�X�̓ǂݍ���
void BinReader::ReadFileBinary() {
	using namespace std;

	string path = inputFilePath;

#if false
	// string -> char*
	char* outPath = new char[path.size() + 1];
	std::char_traits<char>::copy(outPath, path.c_str(), path.size() + 1);

	// �t�@�C�����J�� (ios::in �͓ǂݍ��ݐ�p, ios::binary �̓o�C�i���`��)
	ifstream file(outPath, ios::in | ios::binary);

	delete[] outPath; // ���������
#else
	// �t�@�C�����J�� (ios::in �͓ǂݍ��ݐ�p, ios::binary �̓o�C�i���`��)
	// string �𒼂� char* �ɓ���Ă��s�����B��OK�ȗ��R�𒲂ׂĂȂ��B
	ifstream file(path, ios::in | ios::binary);
#endif

	//  �t�@�C�����J���Ȃ������Ƃ��̑΍�
	if (!file.is_open()) {
		cout << "�t�@�C�����J���܂���";
		return;
	}

#if false
	// �o�C�i���̃R���\�[���\��
	char buf[16];
	while (!file.eof()) {
		file.read(buf, sizeof(buf));

		for (int i = 0, size = (int)file.gcount(); i < size; ++i) {
			cout << buf[i] << std::flush;
		}
	}
	cout << endl;
#endif

	// �t�@�C���T�C�Y�̎擾 (�I�[�܂ŃV�[�N���āA���݈ʒu���擾)
	file.seekg(0, ios::end);
	size_t size = static_cast<size_t>(file.tellg());	// static_cast�ɈӖ��Ȃ�(������)

	// �z��Ƀo�C�i����ǂݏo��
	char* buf = new char[size];
	file.seekg(0, 0);
	file.read(buf, size);

	// �m�ۍς݂�������񂩂������Ă���ݒ� (delere��null�œǂ�ł������N���Ȃ�)
	delete[] binaryBuf;
	binaryBuf = buf;
	binarySize = size;

	file.close();  //�t�@�C�������
}

// �ǂݍ��ݍς݂̃o�C�i���T�C�Y��Ԃ�
int BinReader::GetBinarySize() const {

	return binarySize;
}

// �ǂݍ��ݍς݂̃o�C�i����Ԃ�
const char* BinReader::GetBinaryPointer() const {

	if (binaryBuf == nullptr) return nullptr;
	return (const char*)binaryBuf;
}
