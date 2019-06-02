#include <stdio.h>
#include <stdlib.h>
#include <direct.h>

// カレントディレクトリを表示する
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
		printf("カレントディレクトリ[%s]\n", buf);
		free(buf);
	}
	return 0;
}
