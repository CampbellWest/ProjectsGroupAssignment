#include "List.h"

int main(void)
{
    MANAGER managerTest = CreateTaskManager("My Tasks");
    TASK taskTest = CreateTask("Do Laundry", 3);

    AddTaskToManager(&managerTest, taskTest);

    DisplayTaskManagerWhole(managerTest.managerList);

    int i = 0;
    do{
        char buff[MAXWORD];
        int rating;
        printf("Enter Task Title: ");
        fgets(buff, MAXWORD, stdin);
        fflush(stdin);
        printf("Enter Urgency Rating: ");
        scanf("%i", &rating);                //This is a test to show how the input is gonna work
        fflush(stdin);                      // i got no clue how itll look in the funcitonality thing though

        TASK task = CreateTask(buff, rating);
        AddTaskToManager(&managerTest, task);

        i++;
    }while(i<4);

    DisplayTaskManagerWhole(managerTest.managerList);

    return 0;
}
