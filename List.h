#ifndef GROUP_ASSIGNMENT_LIST_H
#define GROUP_ASSIGNMENT_LIST_H

#include "List.h"
#include "Item.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXWORD 50

typedef struct node{
    TASK data;
    struct node *next;
}LISTNODE, *PLISTNODE;

typedef struct taskmanager{
    PLISTNODE managerList;
    char managerName[MAXWORD];
}MANAGER;

MANAGER CreateTaskManager(char* ManagerName);

bool Add(PLISTNODE* list, TASK task);

bool AddTaskToManager(PLISTNODE* taskmanager, TASK task);

void DisplayTaskManagerWhole(PLISTNODE taskmanager);

int GetTaskCountFromList(PLISTNODE list);

PLISTNODE SearchForTaskInList(PLISTNODE list, const char* SearchedTask);

#endif //GROUP_ASSIGNMENT_LIST_H
