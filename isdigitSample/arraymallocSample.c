#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "define.h"

// 動的メモリとmallocのサンプル
int arrayMallocSample()
{
    //char文字列を使用してinfnameの中にファイルパスを代入
    char infname[] = IN_FILE_PATH;

    //char文字列を使用してoutfnameの中にファイルパスを代入
    char outfname[] = OUT_FILE_PATH;

    // 動的にメモリを確保
    char* str;
    str = (char*)malloc(sizeof(char) * MAX_LEN);
    if (str == NULL)
    {
        // メモリ確保失敗
        return -1;
    }

    // 初期化
    memset(str, '\0', sizeof(char) * MAX_LEN);

    // データを設定
    strcpy(str, "test data");

    // 出力
    printf("%s\n", str);

    // 解放
    free(str);

    return SUCCESS;
}