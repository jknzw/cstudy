#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

// LIST_PERSON��PERSON��ǉ�
int add(LIST_PERSON** list, PERSON person)
{
    // �K�v�ȃ��������m��
    LIST_PERSON* newlist = (LIST_PERSON*)malloc(sizeof(LIST_PERSON));
    if (newlist == NULL)
    {
        // �������m�ێ��s
        return -1;
    }

    // �l��ݒ�
    newlist->person = person;
    // ���̃|�C���^��NULL��ݒ�
    newlist->next = NULL;

    // LIST�����̃|�C���^��next���V�[�N���Ď擾
    while (*list != NULL) {
        list = &((*list)->next);
    }
    // LIST�����̃|�C���^��next�ɒǉ��f�[�^�̃|�C���^��ݒ�(�A�h���X��A�����邱�ƂŒǉ�����)
    *list = newlist;

    return 0;
}

// LIST_PERSON�̃��������
int release(LIST_PERSON** list)
{
    if (*list == NULL)
    {
        // LIST��NULL�̏ꍇ����Ώۂ��������ߏI��
        return -1;
    }

    LIST_PERSON* next;
    LIST_PERSON* del;

    // ���̃|�C���^���擾
    next = (*list)->next;

    // �S�|�C���^�̗̈�����
    while (next != NULL) {
        // ���̃A�h���X������ꍇ
        // ���̃A�h���X���폜�ΏۂƂ��Ď擾
        del = next;
        // ���̎��̃A�h���X��ێ�
        next = next->next;
        // ���̃A�h���X�̃��������������
        free(del);
    }
    // �ŏ��̃��������������
    free(*list);

    return 0;
}
