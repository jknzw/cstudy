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
		printf("�J�����g�f�B���N�g��[%s]\n", buf);
		free(buf);
	}
	return 0;
}
