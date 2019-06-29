#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include "define.h"
#include "struct.h"

#define LINE_MAX 256

// ファイルの行数を取得する
int getFileLineCount(const char* filePath)
{
    int count = 0;

    FILE* fp = fopen(filePath, "r");

    if (fp == NULL) {
        printf("%sが存在しません。", filePath);
        return IN_FILE_OPEN_ERROR;
    }

    // ファイルを読み込み行数を取得
    char buf[LINE_MAX] = { '\0' };
    while (fgets(buf, sizeof(buf), fp) != NULL)
    {
        count++;
    }

    fclose(fp);

    // 読み込んだ行数を返却
    return count;
}

// ファイル読込
int readInputFile(const char* filePath, PERSON* arrPerson, int maxSize)
{
    //ファイルオープン
    FILE* fp = fopen(filePath, "r");

    if (fp == NULL) {
        //ファイルが無い場合
        printf("%sが存在しません。", filePath);
        return IN_FILE_OPEN_ERROR;
    }

    // csvデータを読み込み配列に格納
    int dataCount = 0;
    for (int i = 0; i < maxSize; i++) {
        // ID,名称,Lv,HP,MP,ATK,DEF,SPD
        if (fscanf(fp, "%d,%[^,],%d,%d,%d,%d,%d,%d\n"
            , &(arrPerson + i)->id
            , (arrPerson + i)->name
            , &(arrPerson + i)->lv
            , &(arrPerson + i)->hp
            , &(arrPerson + i)->mp
            , &(arrPerson + i)->atk
            , &(arrPerson + i)->def
            , &(arrPerson + i)->spd) == 8)
        {
            // 読み込んだ数が正常な場合
            dataCount++;
        }
        else {
            //上記以外は読込処理を抜ける
            break;
        }
    }

    fclose(fp);

    // 読み込んだ行数を返却
    return dataCount;
}
