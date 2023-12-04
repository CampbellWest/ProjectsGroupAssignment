#include <string.h>

void RemoveNewLine(char* buffer)
{
    for(int i = 0; i < strlen(buffer); i++)
        if (buffer[i] == '\n')
            buffer[i] = '\0';
}

//This is for the add and remove and displays or whatever is in the
//requirements

