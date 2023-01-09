#include <stdlib.h>
#include <string.h>

int getSize(char data[])
{
    int c=0;
    while(data[c]!='\0'){
        c++;
    }
    return c;
}

void consoleWrite(char data[])
{
    write(1, '\n', 1);
    write(1, data, getSize(data));
}

void printInt(int value)
{
    char data[10];
    int size=sprintf(data, "%d", value);
    write(1, data, size);
}