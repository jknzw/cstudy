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

void convertIntToCharArray(int num, char text[],int len)
{
	sprintf_s(text, len, "%d", num);
}
