#pragma once

#define MAX_ROW_SIZE 256
#define MAX_LINE 256

// �֐��̃v���g�^�C�v�錾
// ���̃t�@�C���Œ�`����Ă���֐����g���ɂ�extern���g�p����
extern int printCurrentDir();
extern int filewriteSample(char* pOutFilePath);
extern int filereadSample(char* pInFilePath);
