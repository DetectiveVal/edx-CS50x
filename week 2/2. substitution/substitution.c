#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
void ValidatingSize(string key);
void ValidatingAlpha(string key);
void ValidatingSingle(string key);
void ValidantingArgAmm(int argc);

int main(int argc, string argv[])
{
    const string ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const int AlphaLen = 26;
    ValidantingArgAmm(argc);
    ValidatingSize(argv[1]);
    ValidatingAlpha(argv[1]);
    ValidatingSingle(argv[1]);

    string plaintext = get_string("Please type the message to be cyphered: ");
    int plaintextL = strlen(plaintext);
    char cyphertext [plaintextL + 1];

    for (int i = 0; i < plaintextL; i++)
    {
        if (isupper(plaintext[i]) != 0)
        {
            for (int j = 0; j < AlphaLen; j++)
            {
                if (plaintext[i] == ALPHA[j])
                {
                    cyphertext[i] = toupper(argv[1][j]);
                    break;
                }
            }
        }
        else if (islower(plaintext[i]) != 0)
        {
            for (int j = 0; j < AlphaLen; j++)
            {
                if (plaintext[i] == tolower(ALPHA[j]))
                {
                    cyphertext[i] = tolower(argv[1][j]);
                    break;
                }
            }
        }
        else
        {
            cyphertext[i] = plaintext[i];
        }
    }
    cyphertext[plaintextL] = '\0';
    printf("ciphertext: %s\n", cyphertext);
}

void ValidatingSize(string key)
{
    int userlength = strlen(key);
    if (userlength == 26)
    {
    }
    else
    {
        printf("Key must contain 26 characters.\n");
        exit(1);
    }
}

void ValidatingAlpha(string key)
{
    char letter;
    for (int i = 0; i < 26;)
    {
        letter = key[i];
        if (isalpha(letter))
        {
            i++;
        }
        else
        {
            printf("Key must only contain alphabetic characters.\n");
            i = 26;
            exit(1);
        }
    }
}
void ValidatingSingle(string key)
{
    char letter;
    int counter = 0;
    for (int i = 0; i < 26; i++)
    {
        letter = key[i];
        for (int j = 0; j < 26; j++)
        {
            if (letter == key[j])
            {
                counter++;
            }
            else if (counter >= 2)
            {5
                printf("Key must not contain repeated characters.\n");
                exit(1);
            }
        }
        counter = 0;
    }
}
void ValidantingArgAmm(int argc)
{
    if (argc != 2)
    {
        printf("Please write exactly 1 argument\n");
        exit(1);
    }
}
