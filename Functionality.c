#include <string.h>
#include "Functionality.h"

void RemoveNewLine(char* buffer)
{
    for(int i = 0; i < strlen(buffer); i++)
        if (buffer[i] == '\n')
            buffer[i] = '\0';
}

bool SaveManagerToDisk(MANAGER manager, char* filename)
{
    FILE* fp = fopen(filename, "w");
    if(fp == NULL)
        return false;

    fprintf(fp, "%s\n", manager.managerName);
    fprintf(fp, "%i\n", GetTaskCountFromList(manager.managerList));
    SaveListToDisk(manager.managerList, fp);

    return true;
}

bool SaveListToDisk(PLISTNODE list, FILE* fp)
{
    PLISTNODE current = list;
    int i = 0;
    while (i < GetTaskCountFromList(list)){
        SaveTaskToDisk(current->data, fp);
        current = current->next;
        i++;
    }
    return true;
}

bool SaveTaskToDisk(TASK task, FILE* fp)
{
    fprintf(fp, "%s\n", task.title);
    fprintf(fp, "%i\n", task.urgencyRank);
    return true;
}

char* GetTaskManagerName(char* buff)
{
    printf("Enter name of task manager: ");
    fgets(buff, MAXSTRING, stdin);
    RemoveNewLine(buff);

    return buff;
}

MANAGER LoadManagerFromDisk(char* filename)
{
    char buffer[MAXWORD];
    FileMade:;
    FILE* fp = fopen(filename, "r");
    if(fp == NULL){
        fclose(fp);

        FILE* fp = fopen(filename, "w");
        fprintf(fp, "%s\n", GetTaskManagerName(buffer));
        fclose(fp);
        goto FileMade;
    }

    fgets(buffer, MAXWORD, fp);

    if(!isalpha(buffer[0]))
        return CreateTaskManager(GetTaskManagerName(buffer));

    RemoveNewLine(buffer);
    MANAGER taskManager = CreateTaskManager(buffer);

    int NumberOfTasks;
    fscanf(fp, "%i\n", &NumberOfTasks);

    for(int i = 0; i < NumberOfTasks; i++){
        TASK task = LoadTaskFromDisk(fp);
        AddTaskToManager(&(taskManager.managerList), task);
    }
    fclose(fp);
    return taskManager;
}

TASK LoadTaskFromDisk(FILE* fp)
{
    char title[MAXWORD];
    fgets(title, MAXWORD, fp);

    int urgency;
    fscanf(fp, "%i\n", &urgency);

    return CreateTask(title, urgency);
}