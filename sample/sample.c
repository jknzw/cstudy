//C����̃o�O��������邽�߂̏K�� 
//�@�ǂ�ł����ׂ�
//    https://qiita.com/Ki4mTaria/items/b6ab0bcbe9c87d4dc071


#include <stdio.h>

// malloc free
#include <stdlib.h>

#include "sample.h"

// ���C�� �v���O�����͂���������s�����
int main(int argc, char* argv[])
{
	int ret = -1;

	// �t�@�C���w��
	// ��΃p�X���w�肷��ꍇ�A\��\\�ɂ���K�v������
	//char* pOutFilePath = "C:\\work\\sample\\sample\\test.csv";
	char* pOutFilePath = "test.csv";
	char* pInFilePath = "test.csv";


	ret = printCurrentDir();
	if (ret != 0) {
		// ���s�����ꍇ�A�㑱�������s�킸��return
		printf("�J�����g�f�B���N�g���擾���s\r\n");
		return ret;
	}

	ret = filewriteSample(pOutFilePath);
	if (ret != 0) {
		// ���s�����ꍇ�A�㑱�������s�킸��return
		printf("�t�@�C���������ݎ��s\r\n");
		return ret;
	}

	ret = filereadSample(pInFilePath);
	if (ret != 0) {
		// ���s�����ꍇ�A�㑱�������s�킸��return
		printf("�t�@�C���ǂݍ��ݎ��s\r\n");
		return ret;
	}

	ret = filereadSample2(pInFilePath);
	if (ret != 0) {
		// ���s�����ꍇ�A�㑱�������s�킸��return
		printf("�t�@�C���ǂݍ��ݎ��s\r\n");
		return ret;
	}

	// ������(char�^�̔z��)�𐔒l�ɕϊ�����
	int i = convertCharArrayToInt("500");
	printf("%d\r\n", i);

	// ���l�𕶎���(char�^�̔z��)�ɕϊ�����
	// ����Ȏg�����ŗǂ��񂾂����E�E�E�H�H�H
	char text[MAX_TEXT_SIZE] = { '\0' };
	ret = convertIntToCharArray(1000, text, MAX_TEXT_SIZE);
	if (ret != 0) {
		// ���s�����ꍇ�A�㑱�������s�킸��return
		printf("������ϊ����s\r\n");
		return ret;
	}
	printf("%s\r\n", text);

	structSample();

	return ret;
}
