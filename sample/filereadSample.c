#include <stdio.h>
#include <string.h>

#include "sample.h"

// ファイル読込関数
int filereadSample(char* pInFilePath)
{
	int ret = 0;

	// ファイルポインタの初期化
	FILE _fp = { NULL };
	FILE* fp = &_fp;

	// 読込みモード「r」でファイルを開く。
	// ファイルが無い場合はエラー
	// VisualStudioでのデバッグ実行時の相対パスはexeを直接実行した時と違い、
	// ソースファイル、cvxprojと同じ階層になるため注意
	// === セキュリティ強化版関数について === 
	// C99(1999年)のC言語ではfopenが標準だったが、
	// C11(2011年)以降のC言語ではfopen_sを標準としている。
	// _sが準備されている関数は_sを使うように。
	// 参考 https://docs.microsoft.com/ja-jp/cpp/c-runtime-library/security-features-in-the-crt?view=vs-2019
	errno_t errCode = fopen_s(&fp, pInFilePath, "r");
	if (0 != errCode)
	{
		// ファイル読込エラー
		ret = errCode;
	}
	else if (fp == NULL)
	{
		ret = -99;
	}

	if (0 == ret)
	{
		// ファイルオープンに成功した場合
		// EOFまで読み込む
		int idx = 0;

		// 初期化＋宣言
		char line[MAX_TEXT_SIZE] = { '\0' };
		// memsetで初期化する事もできる
		// memset(line, '\0', sizeof(line));

		while (NULL == fgets(line, sizeof(line), fp))
		{
			idx++;
			printf("[%d]%s", idx, line);
		}

		// ファイルは必ず閉じる
		fclose(fp);
	}

	return ret;
}
