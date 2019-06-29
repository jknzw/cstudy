#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include "define.h"
#include "struct.h"
#include "extern.h"

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
int readInputFile(const char* filePath, LIST_PERSON** arrPerson)
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
    while (1) {
        PERSON person = { 0 };

        // ID,名称,Lv,HP,MP,ATK,DEF,SPD
        if (fscanf(fp, "%d,%[^,],%d,%d,%d,%d,%d,%d\n"
            , &person.id
            , person.name
            , &person.lv
            , &person.hp
            , &person.mp
            , &person.atk
            , &person.def
            , &person.spd) == 8)
        {
            // 読み込んだ数が正常な場合
            printf("%d,%s,%d,%d,%d,%d,%d,%d\n"
                , person.id
                , person.name
                , person.lv
                , person.hp
                , person.mp
                , person.atk
                , person.def
                , person.spd);
            dataCount++;
        }
        else {
            //上記以外は読込処理を抜ける
            printf("break\n");
            break;
        }

        add(arrPerson, person);
    }

    fclose(fp);

    // 読み込んだ行数を返却
    return dataCount;
}
