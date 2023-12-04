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

bool AddTaskToManager(MANAGER* taskmanager, TASK task)
{
    if(taskmanager == NULL)
        return false;

    return Add(&(taskmanager->managerList), task);
}

void DisplayTaskManagerWhole(PLISTNODE taskmanager){
    PLISTNODE current = taskmanager;
    if (current == NULL)
        return;

    do {
        printf("%s\n", current->data.title);
        current = current->next;
    } while (current != NULL);
}