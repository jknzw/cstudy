#include <stdio.h>

// ファイル書き込み関数
int filewriteSample(char* pOutFileName)
{
	int ret = 0;

	// ファイルポインタの初期化
	FILE _fp = { NULL };
	FILE* fp = &_fp;

	// 書き込みモード「w」でファイルを開く。
	// ファイルが無い場合は新規作成される。
	// VisualStudioでのデバッグ実行時の相対パスはexeを直接実行した時と違い、
	// ソースファイル、cvxprojと同じ階層になるため注意
	// === セキュリティ強化版関数について === 
	// C99(1999年)のC言語ではfopenが標準だったが、
	// C11(2011年)以降のC言語ではfopen_sを標準としている。
	// _sが準備されている関数は_sを使うように。
	// 参考 https://docs.microsoft.com/ja-jp/cpp/c-runtime-library/security-features-in-the-crt?view=vs-2019
	errno_t errCode = fopen_s(&fp, pOutFileName, "w");
	if (0 != errCode)
	{
		// ファイル作成エラー
		ret = errCode;
	}
	else if (fp == NULL)
	{
		ret = -99;
	}

	if (0 == ret)
	{
		// ファイル作成に成功した場合
		// 20行書き込む
		// fwrite、fputc、fputs、fprintfなど、色々書き込む方法はある
		for (int i = 1; i <= 20; i++)
		{
			fprintf(fp, "%d\n", i);
		}

		// ファイルは必ず閉じる
		fclose(fp);
	}

	return ret;
}
