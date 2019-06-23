#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "define.h"

/*** IN_FILE サンプルデータ ***
2
4
6
8

10
008
13A
1a5
b40
******************************/

int main(int argc,char* argv[])
{
	//入力ファイルポインタ型の定義
	FILE* infp;

	//出力ファイルポインタの定義
	FILE* outfp;

	//char文字列を使用してinfnameの中にファイルパスを代入
	char infname[] = IN_FILE_PATH;

	//char文字列を使用してoutfnameの中にファイルパスを代入
	char outfname[] = OUT_FILE_PATH;

	char str[MAX_LEN] = { '\0' };
	char inText[MAX_LINE][MAX_LEN] = { '\0' };

	//infp = 入力ファイルオープン(ファイルを読込モードで開く)
	infp = fopen(infname, "r");

	//入力ファイルポインタにファイルが無い場合NULLを返す
	if (infp == NULL) {
		//入力ファイルが開けないエラー表示
		printf("入力ファイルが存在しません\n");
		//エラー発生の場合-1を返す
		return IN_FILE_OPEN_ERROR;
	}

	int count = 0;
	// 【C言語入門】ファイルの読み込み方法まとめ(fopen, fgets)
	// https://www.sejuku.net/blog/24615
	while (fgets(str, sizeof(str), infp) != NULL) {
		printf("=== ▼▼▼ 1行読み込み処理 ▼▼▼ ===\n");

		// fgetsは改行も読み込むため、改行を削除
		// strlenは末尾の\0までの長さを求める
		int len = strlen(str);
		if (str[len - 1] == '\n')
		{
			str[len - 1] = '\0';
		}

		printf("読み込んだ文字列:[%s]\n", str);

		if (str[0] == '\0')
		{
			// 空行の場合読み飛ばす
			continue;
		}

		// 配列に格納
		strcpy(inText[count], str);
		count++;

		// ▼▼▼ 数値判定処理 ▼▼▼
		// ※整数のみの判定。小数を判定する場合は別途小数点の位置や数を判定しないといけない
		printf("=== ▼▼▼ 数値判定ループ ▼▼▼ ===\n");
		bool isNum = true;
		for (int i = 0; i < (int)strlen(str); i++)
		{
			if (isdigit((int)str[i])) {
				// 数値
				printf("[%d][%c]は数値\n", i, str[i]);
			}
			else
			{
				// 数値以外の文字
				printf("[%d][%c]は数値以外\n", i, str[i]);
				isNum = false;

				// 数値以外の文字を見つけた判定を抜ける
				break;
			}
		}
		printf("=== ▲▲▲ 数値判定ループ ▲▲▲ ===\n");

		// 結果
		if (isNum)
		{
			printf("%sは数値\n", str);
		}
		else
		{
			printf("%sは数値以外\n", str);
		}
		// ▲▲▲ 数値判定処理 ▲▲▲

		printf("=== ▲▲▲ 1行読み込み処理 ▲▲▲ ===\n");
	}

	//outfp = 出力ファイルオープン(ファイルを書き込みモードで開く)
	outfp = fopen(outfname, "w");

	//出力ファイルポインタにファイルが無い場合NULLを返す
	if (outfp == NULL) {
		//出力ファイルが開けないエラー表示
		printf("出力ファイルが存在しません\n");
		//入力ファイルを閉じる
		fclose(infp);
		//エラー発生の場合-2を返す
		return OUT_FILE_OPEN_ERROR;
	}

	printf("=== ▼▼▼ 出力処理 ▼▼▼ ===\n");

	// sizeof(inText) / sizeof(inText[i])
	// 二次元配列全体のサイズを配列1行のサイズで割って列のサイズを求める
	for (int i = 0; i < sizeof(inText) / sizeof(inText[i]); i++)
	{
		printf("%s\n", inText[i]);
		if (strlen(inText[i]) == 0)
		{
			// 空要素を見つけたら出力せずに抜ける
			break;
		}
		fprintf(outfp, "%s\n", inText[i]);
	}

	printf("=== ▲▲▲ 出力処理 ▲▲▲ ===\n");


	//ファイルを閉じる
	fclose(infp);
	fclose(outfp);

	return 0;
}
