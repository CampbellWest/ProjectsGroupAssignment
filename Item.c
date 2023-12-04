#include "Item.h"
#include "Functionality.h"

#include <stdio.h>

TASK CreateTask(char* title, int urgencyRank)
{
    TASK task = {0};
    RemoveNewLine(title);
    strcpy(task.title, title);
    strcpy(task.description, GetTaskDescription(task.title));
    task.urgencyRank = urgencyRank;

    return task;
}

char* GetTaskDescription(char* title)
{
    char buff[MAXSTRING];
    printf("Enter '%s' description: ", title);
    //scanf("%s", buff);
    fgets(buff, MAXSTRING, stdin);
    RemoveNewLine(buff);

    return buff;
}

bool CopyTask(TASK* dest, TASK src)
{
    if(dest == NULL)
        return false;
    strcpy(dest->title, src.title);
    strcpy(dest->description, src.description);
    dest->urgencyRank = src.urgencyRank;
    return true;
}




