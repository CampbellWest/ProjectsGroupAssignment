#ifndef GROUP_ASSIGNMENT_ITEM_H
#define GROUP_ASSIGNMENT_ITEM_H

#include <stdbool.h>
#include <string.h>

#define MAXSTRING 500
#define MAXWORD 50

typedef struct task{
    char title[MAXWORD];
    char description[MAXSTRING];
    int urgencyRank;
}TASK;

TASK CreateTask(char* title, int urgencyRank);

char* GetTaskDescription(char* title);

bool CopyTask(TASK* dest, TASK src);

#endif //GROUP_ASSIGNMENT_ITEM_H

//Title is for the name of the task for something to search for and
//display
//
//description is what you have to do in the task for something to edit
//
//urgencyRank is a number between 1-5 so when youre display the range you can
//say display 3-5 or something like that