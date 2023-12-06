#include "List.h"
#include "Functionality.h"

bool Add(PLISTNODE* list, TASK task)
{
    PLISTNODE newTask = (PLISTNODE)malloc(sizeof(LISTNODE));
    if (newTask == NULL)
        return false;

    if (!CopyTask(&(newTask->data), task)) {
        free(newTask);
        return false;
    }
    newTask->data = task;

    newTask->next = *list;

    *list = newTask;
    return true;
}

MANAGER CreateTaskManager(char* ManagerName)
{
    MANAGER newManager = { 0 };
    newManager.managerList = NULL;
    RemoveNewLine(ManagerName);
    strcpy(newManager.managerName, ManagerName);
    return newManager;
}

bool AddTaskToManager(PLISTNODE* taskmanager, TASK task)
{
    if(taskmanager == NULL)
        return false;

    return Add(taskmanager, task);
}

void DisplayTaskManagerWhole(PLISTNODE taskmanager){
    PLISTNODE current = taskmanager;
    if (current == NULL)
        return;

    do {
        printf("Task: %s\nUrgency: %i\n\n", current->data.title, current->data.urgencyRank);
        current = current->next;
    }while(current != NULL);
}

int GetTaskCountFromList(PLISTNODE list)
{
    int count = 0;
    PLISTNODE current = list;
    while(current != NULL){
        count++;
        current = current->next;
    }
    return count;
}

PLISTNODE SearchForTaskInList(PLISTNODE list, const char* SearchedTask)
{
    PLISTNODE current = list;

    while(current != NULL)
        if(CompareTasks(current->data, SearchedTask))
            return current;
        else
            current = current->next;

    return (PLISTNODE)NULL;
}