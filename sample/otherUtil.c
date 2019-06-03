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
		printf("カレントディレクトリ[%s]\r\n", buf);
		free(buf);
	}
	return 0;
}

int convertCharArrayToInt(char* text)
{
	// 文字列を数値に変換する
	int num = atoi(text);
	return num;
}

// https://docs.microsoft.com/ja-jp/cpp/c-runtime-library/reference/sprintf-s-sprintf-s-l-swprintf-s-swprintf-s-l?view=vs-2019
int convertIntToCharArray(int num, char text[],int len)
{
	int ret = sprintf_s(text, len, "%d", num);
	if (ret < 0)
	{
		// 変換エラー
		return ret;
	}
	else
	{
		// 正常
		return 0;
	}
}
