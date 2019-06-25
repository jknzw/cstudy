#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "sample.h"

// ファイル読込関数
int filereadSample(char* pInFilePath)
{
    int ret = 0;

    // ファイルポインタの初期化
    FILE* fp;

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

        while (NULL != fgets(line, sizeof(line), fp))
        {
            idx++;
            printf("[%d]%s", idx, line);
        }

        // ファイルは必ず閉じる
        fclose(fp);
    }

    return ret;
}

// 読み込んだデータを二次元配列に格納する
// https://tondol.hatenablog.jp/entry/20090713/1247426321
int filereadSample2(char* pInFilePath)
{
    int ret = 0;

    FILE* fp;

    // 読込みモード「r」でファイルを開く。
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

    // char*のアドレスを保持する領域を確保
    char** textArr = malloc(sizeof(char*) * MAX_LINE * MAX_TEXT_SIZE);
    if (NULL == textArr)
    {
        // メモリ確保失敗時はエラー
        printf("アドレスのメモリ確保に失敗");
        return -1;
    }

    // char配列を保持する領域を確保
    char* line = malloc(sizeof(char) * MAX_LINE * MAX_TEXT_SIZE);
    if (line == NULL)
    {
        // メモリ確保失敗時はエラー
        printf("実態のメモリ確保に失敗");
        return -2;
    }

    // memsetで初期化
    memset(line, '\0', sizeof(char) * MAX_LINE * MAX_TEXT_SIZE);

    for (int i = 0; i < MAX_LINE; i++)
    {
        // 各要素の先頭アドレスを設定
        textArr[i] = line + (__int64)i * MAX_TEXT_SIZE;
    }

    int readCount = 0;
    if (0 == ret)
    {
        // ファイルオープンに成功した場合
        // EOFまで読み込む
        while (0 == feof(fp))
        {
            // 1行読み込む
            char text[MAX_TEXT_SIZE] = { '\0' };
            fgets(text, MAX_TEXT_SIZE, fp);

            printf("[%d]%s", readCount, text);

            // 配列に格納
            strcpy_s(textArr[readCount], MAX_TEXT_SIZE, text);

            readCount++;
        }

        // 改行
        printf("\r\n");

        // ファイルは必ず閉じる
        fclose(fp);
    }

    // 不要になったらメモリを解放する
    // 配列の中身を先に解放する
    free(line);
    free(textArr);

    return ret;
}

