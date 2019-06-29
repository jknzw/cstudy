#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

int add(LIST_PERSON** list, PERSON person)
{
    LIST_PERSON* newlist = (LIST_PERSON*)malloc(sizeof(LIST_PERSON));
    if (newlist == NULL)
    {
        return -1;
    }
    newlist->person = person;
    newlist->next = NULL;

    while (*list != NULL) {
        list = &((*list)->next);
    }
    *list = newlist;

    return 0;
}

int release(LIST_PERSON** list)
{
    LIST_PERSON* next;
    LIST_PERSON* del;

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
}
