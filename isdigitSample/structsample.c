#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h> // malloc

#define GENDER_MAN 0
#define GENDER_WOMAN 1

typedef struct _HUMAN {
    int id;
    char name[64];
    int age;
    int gender;
} HUMAN;

int structsample()
{
    // 構造体の配列の宣言
    HUMAN shain[20] = { 0 };

    // 値を設定
    shain[0].id = 0;
    strcpy(shain[0].name, "山田");
    shain[0].age = 20;
    shain[0].gender = GENDER_MAN;

    // 構造体のポインタの宣言
    HUMAN* pShain;
    // 構造体の配列の先頭のアドレスを設定
    pShain = shain;

    // indexを0から1に移動(ポインタのアドレスを移動)
    pShain++;

    // 値を設定
    pShain->id = 1;
    strcpy(pShain->name, "佐藤");
    pShain->age = 25;
    pShain->gender = GENDER_WOMAN;

    // 出力
    printf("出力①[%d][%s][%d][%d]\n", shain[0].id, shain[0].name, shain[0].age, shain[0].gender);
    printf("出力②[%d][%s][%d][%d]\n", shain[1].id, shain[1].name, shain[1].age, shain[1].gender);

    // アドレスを先頭に戻す
    pShain = shain;

    // 出力
    printf("出力③[%d][%s][%d][%d]\n", pShain->id, pShain->name, pShain->age, pShain->gender);
    pShain++;
    printf("出力④[%d][%s][%d][%d]\n", pShain->id, pShain->name, pShain->age, pShain->gender);

    return 0;
}


// 参考：http://www9.plala.or.jp/sgwr-t/c/sec15-3.html
int structsample2()
{
    // 構造体のポインタの宣言
    HUMAN* pShain;

    // メモリ確保
    pShain = (HUMAN*)malloc(sizeof(HUMAN) * 20);
    if (pShain == NULL)
    {
        return -1;
    }

    // 値を設定
    pShain->id = 0;
    strcpy(pShain->name, "山田");
    pShain->age = 20;
    pShain->gender = GENDER_MAN;

    // ポインタを値を変えずに参照アドレスをずらし次のポインタのデータを設定
    // ※値を変えてしまうとfreeする対象がわからなくなってしまうため。

    // ※他の方法として、以下のように先頭アドレスを保持しておく方法もある。
    //   HUMAN* firstShain = pShain;
    //   pShain++;
    //   ...(中略)...
    //   pShain = firstShain;

    (pShain + 1)->id = 1;
    strcpy((pShain + 1)->name, "佐藤");
    (pShain + 1)->age = 25;
    (pShain + 1)->gender = GENDER_WOMAN;

    // 出力
    printf("出力①[%d][%s][%d][%d]\n", pShain[0].id, pShain[0].name, pShain[0].age, pShain[0].gender);
    printf("出力②[%d][%s][%d][%d]\n", pShain[1].id, pShain[1].name, pShain[1].age, pShain[1].gender);
    printf("出力③[%d][%s][%d][%d]\n", pShain->id, pShain->name, pShain->age, pShain->gender);
    printf("出力④[%d][%s][%d][%d]\n", (pShain + 1)->id, (pShain + 1)->name, (pShain + 1)->age, (pShain + 1)->gender);

    // 解放
    free(pShain);

    return 0;
}
