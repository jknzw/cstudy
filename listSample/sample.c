#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

// ファイルからデータを読み込み、
// 加工して出力するプログラムのサンプル

/* input.csv ID,名称,Lv,HP,MP,ATK,DEF,SPD
1,山田,20,120,0,100,50,10
2,鈴木,22,100,20,80,55,12
3,佐藤,18,80,50,30,40,8
*/

/* out.txt
--- 1 ---
山田
HP 120
MP 0
--- 2 ---
鈴木
HP 100
MP 20
--- 3 ---
佐藤
HP 80
MP 50
*/

// ファイルパス定義
#define IN_FILE_PATH "C:\\work\\input.csv"
#define OUT_FILE_PATH "C:\\work\\out.txt"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "define.h"
#include "extern.h"

int main(int argc, char* argv[])
{
    // ファイル名を読み取り専用の変数で宣言する
    const char* inFile = IN_FILE_PATH;

    // List変数をNULLで定義
    LIST_PERSON* listp = NULL;

    printf("▼▼▼ INファイル読込 ▼▼▼\n");
    // ファイルからデータを読み込む
    int inDataCount = readInputFile(inFile, &listp);
    if (inDataCount < 0)
    {
        // ファイルの読み込みに失敗
        release(&listp);
        return inDataCount;
    }
    printf("▲▲▲ INファイル読込 ▲▲▲\n");

    printf("▼▼▼ データ出力処理 ▼▼▼\n");
    //出力ファイルオープン
    FILE* outfp = fopen(OUT_FILE_PATH, "w");
    if (outfp == NULL) {
        printf("出力ファイルの作成に失敗しました。\n");
        return OUT_FILE_OPEN_ERROR;
    }

    for (LIST_PERSON* now = listp; now != NULL; now = now->next)
    {
        // コンソール出力
        // printfではなく、fprintfを使う方法もある
        fprintf(stdout, "--- %d ---\n", now->person.id);
        fprintf(stdout, "%s\n", now->person.name);
        fprintf(stdout, "HP %d\n", now->person.hp);
        fprintf(stdout, "MP %d\n", now->person.mp);

        // ファイル出力
        fprintf(outfp, "--- %d ---\n", now->person.id);
        fprintf(outfp, "%s\n", now->person.name);
        fprintf(outfp, "HP %d\n", now->person.hp);
        fprintf(outfp, "MP %d\n", now->person.mp);
    }

    fclose(outfp);
    printf("▲▲▲ データ出力処理 ▲▲▲\n");

    release(&listp);
    return SUCCESS;
}
