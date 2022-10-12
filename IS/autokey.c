#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>



void encrypt()
{
    char text[1000] = "", key[1000]="", enctext[1000]="";
    int i=0,j=0,k=0, lent, lenk, diff;

    // headings("AUTOKEY CIPHER ENCRYPTION");
    printf("Enter text to be encrypted: ");
    scanf("%s", text);
    printf("Enter key for encryption: ");
    scanf("%s", key);
    lent = strlen(text);
    lenk = strlen(key);
    diff = lent - lenk;
    while(diff != 0)
    {
        key[lenk+i++] = text[j];
        j = (j+1) % lent;
        diff--;
    }
    // lines(snl);
    printf("\n_______________________________________________________________\n");
    printf("\nText to be encrypted: %s of length: %d\n", text, strlen(text));
    printf("Modified Key: %s\n", key);
    // lines(snl);
    for(i = 0; i < lent; i++)
        enctext[i] = (char)((((int)(text[i]) + (int)(key[i]) - 130) % 26) + 65);
    printf("Encrypted text: %s\n", enctext);
    // lines(snl);
    printf("\n_______________________________________________________________\n");
}

void decrypt()
{
    char text[1000] = "", key[1000]="", enctext[1000]="";
    int i=0,j=0,k=0, lent, res;
    // headings("AUTOKEY CIPHER DECRYPTION");
    printf("Enter text to be decrypted: ");
    scanf("%s", enctext);
    printf("Enter key for decryption: ");
    scanf("%s", key);
    lent = strlen(enctext);
    // lines(snl);
    for(i = 0; i < lent; i++)
    {
        res = (int)(enctext[i]) - (int)(key[i]);
        if(res < 0)
            res += 26;
        text[i] = (char)((res % 26) + 65);
    }
    printf("\n_______________________________________________________________\n");
    printf("\nDecrypted text: %s\n", text);
    printf("\n_______________________________________________________________\n");
    // lines(snl);
}

int main()
{
    char ans = 'y';
    while(ans == 'Y' || ans == 'y')
    {
        int op;
        // clrscr();
        // headings("AUTOKEY CIPHER");
        // subheadings("Menu");
        printf("\n1. Encryption of text using Autokey Cipher.\n");
        printf("2. Decryption of encrypted text using Autokey Cipher.\n");
        // lines(snl);
        printf("\nEnter you choice: ");
        scanf("%d", &op);
        // lines(snl);
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
                printf("Invalid option !!! \n");
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