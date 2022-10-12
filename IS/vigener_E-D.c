#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

char key[1000]="";



void encrypt()
{
    // headings("VIGENERE CIPHER ENCRYPTION");
    char text[1000] = "", key[1000] = "", enctext[1000] = "", mkey[1000] = "";
    int lent, lenk, diff, i=0, j=0;
    printf("Enter text to be encrypted: ");
    scanf("%s", text);
    printf("Enter key for encryption: ");
    scanf("%s", key);

    lent = strlen(text);
    lenk = strlen(key);
    diff = lent - lenk;
    strcpy(mkey, key);
    while(diff != 0)
    {
        mkey[lenk+i++] = key[j];
        j = (j+1) % lenk;
        diff--;
    }
    printf("----------------------------------------------\n");
    printf("Modified Key: %s\n", mkey);
    int k[lent], txt[lent];
    for(i = 0; i < lent; i++)
    {
        k[i] = ((int)(mkey[i]) - 65);
        txt[i] = ((int)(text[i]) - 65);
        enctext[i] = (char)(((txt[i] + k[i]) % 26) + 65);
    }
    printf("Encrypted Text: %s\n", enctext);


    printf("\n");
    printf("----------------------------------------------\n");
}

void decrypt()
{
    // headings("VIGENERE CIPHER DECRYPTION");
    char text[1000] = "", key[1000] = "", enctext[1000] = "", mkey[1000] = "";
    int lent, lenk, diff, i=0, j=0;
    printf("Enter the encrypted text: ");
    scanf("%s", enctext);
    printf("Enter key for encryption: ");
    scanf("%s", key);
  
    lent = strlen(enctext);
    lenk = strlen(key);
    diff = lent - lenk;
    strcpy(mkey, key);
    while(diff != 0)
    {
        mkey[lenk+i++] = key[j];
        j = (j+1) % lenk;
        diff--;
    }
    printf("----------------------------------------------\n");
    printf("Modified Key: %s\n", mkey);
    int k[lent], txt[lent];
    for(i = 0; i < lent; i++)
    {
        k[i] = ((int)(mkey[i]) - 65);
        txt[i] = ((int)(enctext[i]) - 65);
        text[i] = (char)(((txt[i] - k[i] + 26) % 26) + 65);
    }
    printf("Decrypted Text: %s\n", text);

    printf("\n");
    printf("----------------------------------------------\n");
}


int main()
{
    char ans = 'y';
    while(ans == 'Y' || ans == 'y')
    {
        // clrscr();
        int op;
        // headings("VIGENERE CIPHER");
        // subheadings("Menu");
        printf("\n1. Encryption using Vigenere Cipher technique.\n");
        printf("2. Decryption using Vigenere Cipher technique.\n");

        printf("\nEnter your choice: ");
        scanf("%d", &op);
        switch(op)
        {
        case 1:
            {
                // clrscr();
                encrypt();
                break;
            }
        case 2:
            {
                // clrscr();
                decrypt();
                break;
            }
        default:
            {
                printf("Invalid option !!!\n");
                break;
            }
        }
        printf("Continue ?(y/n): ");
        scanf("%c", &ans);
        while(ans == ' ' || ans == '\n')
            scanf("%c", &ans);
    }
    return 0;
}