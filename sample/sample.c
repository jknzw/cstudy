// �t�@�C���ւ̏�������
//   https://ylb.jp/2006b/proc/fileio/fileoutput.html
//

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
		return ret;
	}

	ret = filewriteSample(pOutFilePath);
	if (ret != 0) {
		return ret;
	}

	ret = filereadSample(pInFilePath);
	if (ret != 0) {
		return ret;
	}


	return ret;
}

