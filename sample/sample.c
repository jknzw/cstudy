//C言語のバグ回避をするための習慣 
//　読んでおくべし
//    https://qiita.com/Ki4mTaria/items/b6ab0bcbe9c87d4dc071


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sample.h"

int test1();

// メイン プログラムはここから実行される
int main(int argc, char* argv[])
{
	int ret = -1;

	ret = test1();
	if (ret != 0) {
		// 失敗した場合、後続処理を行わずにreturn
		printf("test1失敗\r\n");
		return ret;
	}

	// ファイル指定
	// 絶対パスを指定する場合、\は\\にする必要がある
	//char* pOutFilePath = "C:\\work\\sample\\sample\\test.csv";
	char* pOutFilePath = "test.csv";
	char* pInFilePath = "test.csv";


	ret = printCurrentDir();
	if (ret != 0) {
		// 失敗した場合、後続処理を行わずにreturn
		printf("カレントディレクトリ取得失敗\r\n");
		return ret;
	}

	ret = filewriteSample(pOutFilePath);
	if (ret != 0) {
		// 失敗した場合、後続処理を行わずにreturn
		printf("ファイル書き込み失敗\r\n");
		return ret;
	}

	ret = filereadSample(pInFilePath);
	if (ret != 0) {
		// 失敗した場合、後続処理を行わずにreturn
		printf("ファイル読み込み失敗\r\n");
		return ret;
	}

	ret = filereadSample2(pInFilePath);
	if (ret != 0) {
		// 失敗した場合、後続処理を行わずにreturn
		printf("ファイル読み込み失敗\r\n");
		return ret;
	}

	// 文字列(char型の配列)を数値に変換する
	int i = convertCharArrayToInt("500");
	printf("%d\r\n", i);

	// 数値を文字列(char型の配列)に変換する
	// こんな使い方で良いんだっけ・・・？？？
	char text[MAX_TEXT_SIZE] = { '\0' };
	ret = convertIntToCharArray(1000, text, MAX_TEXT_SIZE);
	if (ret != 0) {
		// 失敗した場合、後続処理を行わずにreturn
		printf("文字列変換失敗\r\n");
		return ret;
	}
	printf("%s\r\n", text);

	structSample();

	return ret;
}

int test1()
{
	printf("年齢を入力して下さい。>");

	char str[16] = { '\0' };
	scanf_s("%s", str, sizeof(str));
	int nenrei = atoi(str);

	char out[16] = { '\0' };

	if (nenrei >= 20)
	{
		strcpy_s(out, sizeof(out), "成人");
	}
	else
	{
		strcpy_s(out, sizeof(out), "未成年");
	}

	printf("%s\r\n", out);

	return 0;
}
