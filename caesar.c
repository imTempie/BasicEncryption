#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, const char* argv[])
{
    // If there is 2 arguments
    if (argc == 2)
    {
        // Assign the second argument to keyString
        const char* keyString = argv[1];

        // Calculate the length of the key
        int len = strlen(keyString);

        // Check if there are alphabetical characters in the key, if so return 1
        for (int x = 0; x < len; x++)
        {
            if (isalpha(keyString[x]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

        // Convert the string key to an int
        int key = atoi(keyString);

        // Get the plaintext
        printf("Enter Plaintext:  ");
        char plaintext[20];
        scanf("%[^\n]%*c", plaintext);

        // Calculate the length of the plaintext
        int length = strlen(plaintext);

        // For the length of the plaintext
        for (int i = 0; i < length; i++)
        {
            // Check the character is alphanumerical
            if (isalpha(plaintext[i]))
            {
                // If it is uppercase
                if (isupper(plaintext[i]))
                {
                    // For the value of the key
                    for (int j = 0; j < key; j++)
                    {
                        // If the plaintext[i] is bigger than or equal to Z
                        if (plaintext[i] >= 90)
                        {
                            // Set it to A
                            plaintext[i] = 'A';
                        }
                        // Otherwise + 1
                        else
                        {
                            plaintext[i] += 1;
                        }
                    }
                }
                // If it is lowercase
                else if (islower(plaintext[i]))
                {
                    // For the value of the key
                    for (int l = 0; l < key; l++)
                    {
                        // If the plaintext[i] is bigger than or equal to z
                        if (plaintext[i] >= 122)
                        {
                            // Set it to a
                            plaintext[i] = 'a';
                        }
                        // Otherwise + 1
                        else
                        {
                            plaintext[i] += 1;
                        }
                    }
                }
            }
            // If the plaintext[i] is not alphabetical, then leave it the same
            else
            {
                plaintext[i] += 0;
            }
        }
        // Print out the now ciphered plaintext
        printf("ciphertext: %s\n", plaintext);
    }
    // If there are more than 2 arguments, then return 1
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}