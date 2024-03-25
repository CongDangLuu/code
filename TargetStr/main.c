#include <stdio.h>
#include <conio.h>
#include <stdint.h>
#include <string.h>

#define MAX_STRING 1000

char Inputstr[MAX_STRING];
char Outputstr[MAX_STRING];
char TargetStr[] = "DLSVN";

uint16_t inputlen = 0;

uint8_t CheckTargetStr(char *str, uint16_t len)
{
    return !(strncmp(str + len - 5, TargetStr, sizeof(TargetStr)));
}

int main()
{
    printf("start\n");
    while (inputlen < MAX_STRING)
    {
        char ch = getch();
        printf("%c", ch);
        Inputstr[inputlen++] = ch;
        if (ch == 'N')
        {
            if (CheckTargetStr(Inputstr, inputlen))
            {
                strncpy(Outputstr, Inputstr, inputlen - 5);
                printf("\nOutputstr: %s", Outputstr);
                return 1;
            }
        }
    }
    return 1;
}