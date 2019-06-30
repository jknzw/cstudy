// WARNING C4996 抑止
// https://docs.microsoft.com/ja-jp/cpp/error-messages/compiler-warnings/compiler-warning-level-3-c4996?view=vs-2019
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

// include
// 標準ライブラリは <> で
// 自作ヘッダは "" で囲む
#include <stdio.h>
#include "define.h"
#include "struct.h"
#include "extern.h"

// ファイル読込関数
//   関数内部でptrPersonListを書き換えるため、LIST_PERSONのポインタのアドレスを引数に設定すること（ポインタのポインタ）
// filePath      : ファイルパス
// ptrPersonList : LIST_PERSONのポインタのポインタ
// return        : 読み込み行数
int readInputFile(const char* filePath, LIST_PERSON** ptrPersonList)
{
    // ファイルオープン
    FILE* fp = fopen(filePath, "r");

    // ファイルがオープンできたかチェック
    if (fp == NULL) {
        //ファイルが無い場合エラー
        printf("%sが存在しません。", filePath);
        return IN_FILE_OPEN_ERROR;
    }

    // csvデータを読み込み配列に格納
    int dataCount = 0;
    while (1) {

        // 構造体の変数を宣言＆0で初期化
        PERSON person = { 0 };

        // ファイルから1行読み込み構造体に格納する
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
            // ファイルの末尾またはフォーマット異常の場合
            // 正常に読み込めなかった場合は読込処理を抜ける
            printf("break\n");
            break;
        }

        // LIST_PERSONに追加する
        add(ptrPersonList, person);
    }

    // ファイルを閉じる
    fclose(fp);

    // 読み込んだ行数を返却
    return dataCount;
}
