#pragma once

#define MAX_TEXT_SIZE 256
#define MAX_LINE 256

// 関数のプロトタイプ宣言
// 他のファイルで定義されている関数を使うにはexternを使用する
extern int printCurrentDir();
extern int filewriteSample(char* pOutFilePath);
extern int filereadSample(char* pInFilePath);
extern int convertCharArrayToInt(char* text);
extern void convertIntToCharArray(int num, char text[],int len);
