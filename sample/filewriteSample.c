#include <stdio.h>

// �t�@�C���������݊֐�
int filewriteSample(char* pOutFileName)
{
	int ret = 0;

	// �t�@�C���|�C���^�̏�����
	FILE _fp = { NULL };
	FILE* fp = &_fp;

	// �������݃��[�h�uw�v�Ńt�@�C�����J���B
	// �t�@�C���������ꍇ�͐V�K�쐬�����B
	// VisualStudio�ł̃f�o�b�O���s���̑��΃p�X��exe�𒼐ڎ��s�������ƈႢ�A
	// �\�[�X�t�@�C���Acvxproj�Ɠ����K�w�ɂȂ邽�ߒ���
	// === �Z�L�����e�B�����Ŋ֐��ɂ��� === 
	// C99(1999�N)��C����ł�fopen���W�����������A
	// C11(2011�N)�ȍ~��C����ł�fopen_s��W���Ƃ��Ă���B
	// _s����������Ă���֐���_s���g���悤�ɁB
	// �Q�l https://docs.microsoft.com/ja-jp/cpp/c-runtime-library/security-features-in-the-crt?view=vs-2019
	errno_t errCode = fopen_s(&fp, pOutFileName, "w");
	if (0 != errCode)
	{
		// �t�@�C���쐬�G���[
		ret = errCode;
	}
	else if (fp == NULL)
	{
		ret = -99;
	}

	if (0 == ret)
	{
		// �t�@�C���쐬�ɐ��������ꍇ
		// 20�s��������
		// fwrite�Afputc�Afputs�Afprintf�ȂǁA�F�X�������ޕ��@�͂���
		for (int i = 1; i <= 20; i++)
		{
			fprintf(fp, "%d\n", i);
		}

		// �t�@�C���͕K������
		fclose(fp);
	}

	return ret;
}
