/*
*****************************************************************
*
*                   Project   Encryption                
*                   COEN 11 -- Fall 2021
*
*****************************************************************
*/

#include <stdio.h>
#include <stdlib.h> //for atoi

void read_binary(char *key, char *name1, char *name2);

int main(int argc, char *argv[])
{
    if (argc <= 3) //If 3 arguments (key & 2 file names) aren't given
    {
        printf("The key or the file names were not given.\n");
        return 0;
    }

    read_binary(argv[1], argv[2], argv[3]);
}

void read_binary(char *key, char *name1, char *name2)
{
    FILE *fp1, *fp2;

    fp1 = fopen(name1, "rb");
    fp2 = fopen(name2, "wb");

    if (fp1 == NULL || fp2 == NULL) //The file does not exist and will be created upon save
        return;

    int i, ret;
    char encrypted;
    char buffer[100];

    while ((ret = fread(buffer, sizeof(char), 100, fp1)) > 0)
    {
        for (i = 0; i < ret; ++i)
        {
            encrypted = buffer[i] ^ atoi(key);
            fwrite(&encrypted, sizeof(char), 1, fp2);
        }
    }

    fclose(fp1);
    fclose(fp2);
    return;
}