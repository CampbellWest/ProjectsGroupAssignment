#include "List.h"
#include "Functionality.h"

//Tyler
// Add, Delete, UI, and a display
//Me
// Update, Search, Load, and Save
// If we have time
// the other 2 display

void InputTest(PLISTNODE* manager);

int main(void)
{
    MANAGER manager = LoadManagerFromDisk("TaskManager.txt");

    //InputTest(&(manager.managerList));

    char buff[MAXWORD] = "Walk the dog";

    if(SearchForTaskInList(manager.managerList, buff))
        printf("Walk the dog is in the task manager\n");
    else
        printf("Walk the dog is not in the task manager\n");

    printf("\n%s\n", manager.managerName);

    DisplayTaskManagerWhole(manager.managerList);

    SaveManagerToDisk(manager, "TaskManager.txt");

    return 0;
}

void InputTest(PLISTNODE* manager)
{
    int i = 0;
    do{

        char buff[MAXSTRING];
        printf("Enter Task Title: ");
        fgets(buff, MAXSTRING, stdin);
        RemoveNewLine(buff);
        fflush(stdin);

        int rating;
        printf("Enter Urgency Rating: ");
        scanf("%i", &rating);
        fflush(stdin);

        TASK task = CreateTask(buff, rating);
        AddTaskToManager((manager), task);

        i++;
    }while(i<1);
}