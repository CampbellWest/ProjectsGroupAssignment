#include "Item.h"
#include "Functionality.h"

#include <stdio.h>

TASK CreateTask(char* title, int urgencyRank)
{
    TASK task = {0};
    RemoveNewLine(title);
    strcpy(task.title, title);
    task.urgencyRank = urgencyRank;

    return task;
}

bool CopyTask(TASK* dest, TASK src)
{
    if(dest == NULL)
        return false;
    strcpy(dest->title, src.title);
    dest->urgencyRank = src.urgencyRank;
    return true;
}




