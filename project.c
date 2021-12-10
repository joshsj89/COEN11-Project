/*
*****************************************************************
*
*                  Project   Encryption Tool              
*                     COEN 11 -- Fall 2021
*
*****************************************************************
*/

#include <stdio.h>
#include <stdlib.h> //for atoi

void encrypt_decrypt(char *key, char *name1, char *name2);

int main(int argc, char *argv[])
{
    if (argc <= 3) //If 3 arguments (key & 2 file names) aren't given
    {
        printf("The key or the file names were not given.\n");
        return 0;
    }

    encrypt_decrypt(argv[1], argv[2], argv[3]);
}

void encrypt_decrypt(char *key, char *name1, char *name2) //Encrypt/Decrypt function
{
    FILE *fp1, *fp2;

    fp1 = fopen(name1, "rb"); //Reading from first file
    fp2 = fopen(name2, "wb"); //Writing to second file

    if (fp1 == NULL || fp2 == NULL) //The file does not exist and will be created upon save
        return;

    int i, ret;
    char buffer[100];

    while ((ret = fread(buffer, sizeof(char), 100, fp1)) > 0)
        for (i = 0; i < ret; ++i)
        {
            buffer[i] ^= atoi(key); //Each byte (8 bits) of the first file XOR-ed with the 8-bit key (0-255)
            fwrite(&buffer[i], sizeof(char), 1, fp2); //Writes the newly encrypted/decrypted byte (8 bits) to the second file
        }

    fclose(fp1);
    fclose(fp2);
    return;
}