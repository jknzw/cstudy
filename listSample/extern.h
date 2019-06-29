#pragma once
#include "struct.h"

// fileread.c
extern int getFileLineCount(const char* filePath);
extern int readInputFile(const char* filePath, LIST_PERSON** arrPerson);

// list.c
extern int add(LIST_PERSON** list, PERSON person);
extern int release(LIST_PERSON** list);
