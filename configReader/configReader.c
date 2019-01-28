#include <stdio.h>

//this function is reading the input of the config file
int main()
{
    FILE *file;
    file = fopen("fileIO.conf","r"); //file input with reading permission


    char line[256];
    int linenum=0;

    while(fgets(line, 256, file) != NULL)
{
        char ip[256], mac[256];

        linenum++;
        if(line[0] == '#') continue;

        if(sscanf(line, "%s %s", ip, mac) != 2) //takes the first string and stores it in ip -> second string in mac
        {
                fprintf(stderr, "Syntax error, line %d\n", linenum);
                continue;
        }

        printf("Line %d:  IP %s MAC %s\n", linenum, ip, mac);
}

    return 0;
}
