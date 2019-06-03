#include <stdio.h>
#include <string.h>

#include "sample.h"

// �t�@�C���Ǎ��֐�
int filereadSample(char* pInFilePath)
{
	int ret = 0;

	// �t�@�C���|�C���^�̏�����
	FILE _fp = { NULL };
	FILE* fp = &_fp;

	// �Ǎ��݃��[�h�ur�v�Ńt�@�C�����J���B
	// �t�@�C���������ꍇ�̓G���[
	// VisualStudio�ł̃f�o�b�O���s���̑��΃p�X��exe�𒼐ڎ��s�������ƈႢ�A
	// �\�[�X�t�@�C���Acvxproj�Ɠ����K�w�ɂȂ邽�ߒ���
	// === �Z�L�����e�B�����Ŋ֐��ɂ��� === 
	// C99(1999�N)��C����ł�fopen���W�����������A
	// C11(2011�N)�ȍ~��C����ł�fopen_s��W���Ƃ��Ă���B
	// _s����������Ă���֐���_s���g���悤�ɁB
	// �Q�l https://docs.microsoft.com/ja-jp/cpp/c-runtime-library/security-features-in-the-crt?view=vs-2019
	errno_t errCode = fopen_s(&fp, pInFilePath, "r");
	if (0 != errCode)
	{
		// �t�@�C���Ǎ��G���[
		ret = errCode;
	}
	else if (fp == NULL)
	{
		ret = -99;
	}

	if (0 == ret)
	{
		// �t�@�C���I�[�v���ɐ��������ꍇ
		// EOF�܂œǂݍ���
		int idx = 0;

		// �������{�錾
		char line[MAX_TEXT_SIZE] = { '\0' };
		// memset�ŏ��������鎖���ł���
		// memset(line, '\0', sizeof(line));

		while (NULL == fgets(line, sizeof(line), fp))
		{
			idx++;
			printf("[%d]%s", idx, line);
		}

		// �t�@�C���͕K������
		fclose(fp);
	}

	return ret;
}
