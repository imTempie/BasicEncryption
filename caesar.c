#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, const char* argv[])
{
    // If there is 2 arguments
    if (argc == 2)
    {
        // assign the second argument to keyString
        const char* keyString = argv[1];

        // calculate the length of the key
        int len = strlen(keyString);

        // check if there are alphabetical characters in the key, if so return 1
        for (int x = 0; x < len; x++)
        {
            if (isalpha(keyString[x]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

        // convert the string key to an int
        int key = atoi(keyString);

        // get the plaintext
        printf("Enter Plaintext:  ");
        char plaintext[20];
        scanf("%[^\n]%*c", plaintext);

        // calculate the length of the plaintext
        int length = strlen(plaintext);

        // for the length of the plaintext
        for (int i = 0; i < length; i++)
        {
            // check the character is alphanumerical
            if (isalpha(plaintext[i]))
            {
                // if it is uppercase
                if (isupper(plaintext[i]))
                {
                    // for the value of the key
                    for (int j = 0; j < key; j++)
                    {
                        // if the plaintext[i] is bigger than or equal to Z
                        if (plaintext[i] >= 90)
                        {
                            // set it to A
                            plaintext[i] = 'A';
                        }
                        // otherwise + 1
                        else
                        {
                            plaintext[i] += 1;
                        }
                    }
                }
                // if it is lowercase
                else if (islower(plaintext[i]))
                {
                    // for the value of the key
                    for (int l = 0; l < key; l++)
                    {
                        // if the plaintext[i] is bigger than or equal to z
                        if (plaintext[i] >= 122)
                        {
                            // set it to a
                            plaintext[i] = 'a';
                        }
                        // otherwise + 1
                        else
                        {
                            plaintext[i] += 1;
                        }
                    }
                }
            }
            // if the plaintext[i] is not alphabetical, then leave it the same
            else
            {
                plaintext[i] += 0;
            }
        }
        // print out the now ciphered plaintext
        printf("ciphertext: %s\n", plaintext);
    }
    // if there are more than 2 arguments, then return 1
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}