//C言語のバグ回避をするための習慣 
//　読んでおくべし
//    https://qiita.com/Ki4mTaria/items/b6ab0bcbe9c87d4dc071


#include <stdio.h>

// malloc free
#include <stdlib.h>

#include "sample.h"

// メイン プログラムはここから実行される
int main(int argc, char* argv[])
{
	int ret = -1;

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
