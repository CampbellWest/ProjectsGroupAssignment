#include "List.h"
#include "Functionality.h"

//Tyler
// Add, Delete, UI, and a display
//Me
// Update, Search, Load, and Save
// If we have time
// the other 2 display

int main(void)
{
    MANAGER manager = LoadManagerFromDisk("TaskManager.txt");

    DisplayTaskManagerWhole(manager.managerList);

    //AddTaskToManager(&manager, task);

    //DisplayTaskManagerWhole(manager.managerList);

    int i = 0;
    do{

        char buff[MAXSTRING];
        printf("Enter Task Title: ");
        fgets(buff, MAXSTRING, stdin);
        fflush(stdin);

        int rating;
        printf("Enter Urgency Rating: ");
        scanf("%i", &rating);
        fflush(stdin);

        TASK task = CreateTask(buff, rating);
        AddTaskToManager(&(manager.managerList), task);

        i++;
    }while(i<3);

    printf("%s\n", manager.managerName);

    DisplayTaskManagerWhole(manager.managerList);

    SaveManagerToDisk(manager, "TaskManager.txt");

    return 0;
}
