#include <stdio.h>
#include <stdlib.h>
#include <direct.h>

// �J�����g�f�B���N�g����\������
// #include <direct.h>
int printCurrentDir()
{
	char* buf = _getcwd(NULL, 0);
	if (buf == NULL)
	{
		// _getcwd error
		return -1;
	}
	else
	{
		printf("�J�����g�f�B���N�g��[%s]\r\n", buf);
		free(buf);
	}
	return 0;
}

int convertCharArrayToInt(char* text)
{
	// ������𐔒l�ɕϊ�����
	int num = atoi(text);
	return num;
}

// https://docs.microsoft.com/ja-jp/cpp/c-runtime-library/reference/sprintf-s-sprintf-s-l-swprintf-s-swprintf-s-l?view=vs-2019
int convertIntToCharArray(int num, char text[],int len)
{
	int ret = sprintf_s(text, len, "%d", num);
	if (ret < 0)
	{
		// �ϊ��G���[
		return ret;
	}
	else
	{
		// ����
		return 0;
	}
}
