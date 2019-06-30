#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

// LIST_PERSONにPERSONを追加
int add(LIST_PERSON** list, PERSON person)
{
    // 必要なメモリを確保
    LIST_PERSON* newlist = (LIST_PERSON*)malloc(sizeof(LIST_PERSON));
    if (newlist == NULL)
    {
        // メモリ確保失敗
        return -1;
    }

    // 値を設定
    newlist->person = person;
    // 次のポインタにNULLを設定
    newlist->next = NULL;

    // LIST末尾のポインタのnextをシークして取得
    while (*list != NULL) {
        list = &((*list)->next);
    }
    // LIST末尾のポインタのnextに追加データのポインタを設定(アドレスを連結することで追加する)
    *list = newlist;

    return 0;
}

// LIST_PERSONのメモリ解放
int release(LIST_PERSON** list)
{
    if (*list == NULL)
    {
        // LISTがNULLの場合解放対象が無いため終了
        return -1;
    }

    LIST_PERSON* next;
    LIST_PERSON* del;

    // 次のポインタを取得
    next = (*list)->next;

    // 全ポインタの領域を解放
    while (next != NULL) {
        // 次のアドレスがある場合
        // 次のアドレスを削除対象として取得
        del = next;
        // 次の次のアドレスを保持
        next = next->next;
        // 次のアドレスのメモリを解放する
        free(del);
    }
    // 最初のメモリを解放する
    free(*list);

    return 0;
}
