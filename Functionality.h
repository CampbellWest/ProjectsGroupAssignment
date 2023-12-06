#ifndef GROUP_ASSIGNMENT_FUNCTIONALITY_H
#define GROUP_ASSIGNMENT_FUNCTIONALITY_H

#include <stdio.h>
#include <ctype.h>
#include "List.h"

void RemoveNewLine(char* buffer);

MANAGER LoadManagerFromDisk(char* filename);

TASK LoadTaskFromDisk(FILE* fp);

bool SaveManagerToDisk(MANAGER manager, char* filename);

bool SaveListToDisk(PLISTNODE list, FILE* fp);

bool SaveTaskToDisk(TASK task, FILE* fp);

#endif //GROUP_ASSIGNMENT_FUNCTIONALITY_H
