#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

static int mnl = 100, snl = 75;

void lines(int nl)
{
    for(int i = 0; i < nl; i++)
        printf("-");
    printf("\n");
}

void centerText(int nl, char *str)
{
    int len = (int)(strlen(str) / 2);
    nl = nl / 2;
    for(int i = 0; i < nl - len; i++)
        printf(" ");
    printf("%s\n", str);
}

void headings(char *str)
{
    lines(mnl);
    centerText(mnl, str);
    lines(mnl);
}

void subheadings(char *str)
{
    lines(snl);
    centerText(snl, str);
    lines(snl);
}

void clrscr()
{
    system("cls");
}

void PlayFairCipherEncryption(int type)
{
    clrscr();
    headings("PLAYFAIR CIPHER TEXT ENCRYPTION");
    char pcmatrix[5][5], str[10000] = "", temp[10000] = "", s[2] = "", enc_text[10000] = "", ch;
    int i, j, k, l, end, loc1r, loc1c, loc2r, loc2c, p1r, p1c, p2r, p2c, enc = 0;
    printf("Enter Playfair Keyword for Encryption: ");
    scanf("%s", str);
    for(i = 0; i < strlen(str); i++)
    {
        str[i] = toupper(str[i]);
        if(str[i] == 'J')
            str[i] = 'I';
    }
    strcat(str, "ABCDEFGHIKLMNOPQRSTUVWXYZ");
    for(i = 0; i < strlen(str); i++)
    {
        for(j = i + 1; j < strlen(str);)
        {
            if(str[i] == str[j])
            {
                for(k = j; k < strlen(str); k++)
                {
                    str[k] = str[k+1];
                }
                str[k - 1] = '\0';

            }
            else
                j++;
        }
    }
    k = 0;
    j = 0;
    end = 5;
    printf("\n");
    subheadings("Digraph / Playfair Cipher Square");
    printf("  | 1 | 2 | 3 | 4 | 5 |\n");
    printf("-----------------------\n");
    for(i = 0; i < 5; i++)
    {
        strncpy(temp, str+j, end-j);
        strcpy(pcmatrix[i],temp);
        strcpy(temp, "");
        j = end;
        end = j + 5;
    }
    for(i = 0; i < 5; i++)
    {
        printf("%d | ", i+1);
        for(j = 0; j < 5; j++)
        {
            printf("%c | ", pcmatrix[i][j]);
        }
        printf("\n");
        printf("-----------------------\n");
    }
    if(type == 1)
    {
        printf("\n");
        printf("\n");
        subheadings("Encryption");
        printf("Enter the Plain Text: ");
        fgets(str, 100, stdin);
        if(strcmp(str, "") == 0 || strcmp(str, "\n") == 0)
        {
            fgets(str, 100, stdin);
            str[strlen(str)-1] = '\0';
        }
    }
    else if(type == 2)
    {
        i = 0;
        FILE *fr = fopen("./InputText.txt", "r");
        if(fr == NULL)
            exit(1);
        while(!feof(fr))
        {
            ch = fgetc(fr);
            str[i++] = ch;
        }
        fclose(fr);
    }
    for(i = strlen(str)-1; i >= 0; i--)
    {
        str[i] = toupper(str[i]);
        if(str[i] == ' ' || str[i] == '.' || str[i] == '~' || str[i] == '₹' || str[i] == '!' || str[i] == '@' || str[i] == '#' || str[i] == '$' || str[i] == '%' || str[i] == '^' || str[i] == '&' || str[i] == '*' || str[i] == '(' || str[i] == ')' || str[i] == '0' || str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9' || str[i] == '-' || str[i] == '_' || str[i] == '+' || str[i] == '=' || str[i] == '{' || str[i] == '}' || str[i] == '[' || str[i] == ']' || str[i] == ':' || str[i] == ';' || str[i] == '"' || str[i] == '|' || str[i] == '<' || str[i] == ',' || str[i] == '>' || str[i] == '/' || str[i] == '?' || isalpha(str[i]) == 0)
        {
            for(k = i; k < strlen(str)-1; k++)
            {
                str[k] = str[k+1];
            }
            str[strlen(str)-1]='\0';
        }
        if(str[i] == toupper(str[i-1]))
        {
            for(k = strlen(str); k > i; k--)
            {
                str[k] = str[k-1];
            }
            str[i] = 'X';
        }
    }
    if(type == 1)
    {
        if(strlen(str) % 2 != 0)
            str[strlen(str)] = 'X';
        str[strlen(str)] = '\0';
        printf("\n");
        subheadings("Formatted Input Message");
        centerText(snl, str);
    }
    j = 0;
    end = 2;
    for(i = 0; i < strlen(str)/2; i++)
    {
        strncpy(s, str+j, end-j);
        s[strlen(s)] = '\0';
        for(k = 0; k < 5; k++)
        {
            for(l = 0; l < 5; l++)
            {
                if(pcmatrix[k][l] == s[0])
                {
                    loc1r = k;
                    loc1c = l;
                }
                if(pcmatrix[k][l] == s[1])
                {
                    loc2r = k;
                    loc2c = l;
                }
            }
        }
        if(loc1r == loc2r)
        {
            p1c = ((loc1c + 1) <= 4)?loc1c + 1: 0;
            p2c = ((loc2c + 1) <= 4)?loc2c + 1: 0;
            p1r = loc1r;
            p2r = loc2r;
        }
        else if(loc1c == loc2c)
        {
            p1c = loc1c;
            p2c = loc2c;
            p1r = ((loc1r + 1) <= 4)?loc1r + 1:0;
            p2r = ((loc2r + 1) <= 4)?loc2r + 1:0;
        }
        else if(loc1r != loc2r && loc1c != loc2c)
        {
            p1r = loc1r;
            p1c = loc2c;
            p2r = loc2r;
            p2c = loc1c;
        }
        enc_text[enc++] = pcmatrix[p1r][p1c];
        enc_text[enc++] = pcmatrix[p2r][p2c];
        strcpy(s, "");
        j = end;
        end = j + 2;
    }
    enc_text[enc] = '\0';
    printf("\n");
    subheadings("Encrypted Text");
    if(type == 1)
    {
        centerText(snl, enc_text);
        printf("\n");
    }
    else
    if(type == 2)
    {
        centerText(snl, "The PlayFair encrypted text is written in 'PlayFairEncryptedText.txt' file.\n");
        FILE *fw = fopen("./PlayFairEncryptedText.txt", "w");
        if(fw == NULL)
            exit(1);
        fputs(enc_text, fw);
        fclose(fw);
    }
    lines(mnl);
}

void PlayFairCipherDecryption(int type)
{
    clrscr();
    headings("PLAYFAIR CIPHER TEXT DECRYPTION");
    char pcmatrix[5][5], str[100] = "", temp[100] = "", s[2] = "", dec_text[100] = "", ch;
    int i, j, k, l, end, loc1r, loc1c, loc2r, loc2c, p1r, p1c, p2r, p2c, enc = 0;
    printf("Enter Playfair Keyword for Decryption: ");
    scanf("%s", str);
    for(i = 0; i < strlen(str); i++)
    {
        str[i] = toupper(str[i]);
        if(str[i] == 'J')
            str[i] = 'I';
    }
    strcat(str, "ABCDEFGHIKLMNOPQRSTUVWXYZ");
    for(i = 0; i < strlen(str); i++)
    {
        for(j = i + 1; j < strlen(str);)
        {
            if(str[i] == str[j])
            {
                for(k = j; k < strlen(str); k++)
                {
                    str[k] = str[k+1];
                }
                str[k - 1] = '\0';

            }
            else
                j++;
        }
    }
    k = 0;
    j = 0;
    end = 5;
    printf("\n");
    subheadings("Digraph / Playfair Cipher Square");
    printf("  | 1 | 2 | 3 | 4 | 5 |\n");
    printf("-----------------------\n");
    for(i = 0; i < 5; i++)
    {
        strncpy(temp, str+j, end-j);
        strcpy(pcmatrix[i],temp);
        strcpy(temp, "");
        j = end;
        end = j + 5;
    }
    for(i = 0; i < 5; i++)
    {
        printf("%d | ", i+1);
        for(j = 0; j < 5; j++)
        {
            printf("%c | ", pcmatrix[i][j]);
        }
        printf("\n");
        printf("-----------------------\n");
    }
    if(type == 1)
    {
        printf("\n");
        printf("\n");
        subheadings("Decryption");
        printf("Enter the Encrypted Text: ");
        fgets(str, 100, stdin);
        if(strcmp(str, "") == 0 || strcmp(str, "\n") == 0)
        {
            fgets(str, 100, stdin);
            str[strlen(str)-1] = '\0';
        }
    }
    else
    if(type == 2)
    {
        i = 0;
        FILE *fr = fopen("./PlayFairEncryptedText.txt", "r");
        if(fr == NULL)
            exit(1);
        while(!feof(fr))
        {
            ch = fgetc(fr);
            str[i++] = ch;
        }
        fclose(fr);
    }
    j = 0;
    end = 2;
    for(i = 0; i < strlen(str)/2; i++)
    {
        strncpy(s, str+j, end-j);
        s[strlen(s)] = '\0';
        for(k = 0; k < 5; k++)
        {
            for(l = 0; l < 5; l++)
            {
                if(pcmatrix[k][l] == s[0])
                {
                    loc1r = k;
                    loc1c = l;
                }
                if(pcmatrix[k][l] == s[1])
                {
                    loc2r = k;
                    loc2c = l;
                }
            }
        }
        if(loc1r == loc2r)
        {
            p1c = ((loc1c - 1) <= -1)?4:loc1c - 1;
            p2c = ((loc2c - 1) <= -1)?4:loc2c - 1;
            p1r = loc1r;
            p2r = loc2r;
        }
        else if(loc1c == loc2c)
        {
            p1c = loc1c;
            p2c = loc2c;
            p1r = ((loc1r - 1) <= -1)?4:loc1r - 1;
            p2r = ((loc2r - 1) <= -1)?4:loc2r - 1;
        }
        else if(loc1r != loc2r && loc1c != loc2c)
        {
            p1r = loc1r;
            p1c = loc2c;
            p2r = loc2r;
            p2c = loc1c;
        }
        dec_text[enc++] = pcmatrix[p1r][p1c];
        dec_text[enc++] = pcmatrix[p2r][p2c];
        strcpy(s, "");
        j = end;
        end = j + 2;
    }
    dec_text[enc] = '\0';
    printf("\n");
    subheadings("Decrypted Text");
    if(type == 1)
    {
        centerText(snl, dec_text);
        printf("\n");
    }
    else
    if(type == 2)
    {
        centerText(snl, "The PlayFair decrypted text is written in 'PlayFairDecryptedText.txt' file.\n");
        FILE *fw = fopen("./PlayFairDecryptedText.txt", "w");
        if(fw == NULL)
            exit(1);
        fputs(dec_text, fw);
        fclose(fw);
    }
    lines(mnl);
}
int main()
{
    char ans = 'y';
    do
    {
        clrscr();
        int ch;
        headings("PLAYFAIR CIPHER");
        subheadings("Menu:");
        printf("1. Encryption using Playfair Cipher.\n");
        printf("2. Decryption using Playfair Cipher.\n");

        lines(snl);
        printf("Enter your choice: ");
        scanf("%d", &ch);
        lines(snl);
        switch(ch)
        {
        case 1:
        {
            PlayFairCipherEncryption(1);
            break;
        }
        case 2:
        {
            PlayFairCipherDecryption(1);
            break;
        }
        // case 3:
        // {
        //     PlayFairCipherEncryption(2);
        //     break;
        // }
        // case 4:
        // {
        //     PlayFairCipherDecryption(2);
        //     break;
        // }
        default:
        {
            printf("Invalid Option !!! .\n");
            lines(snl);
        }
        }
        printf("Want to perform other operation ?(y/n): ");
        scanf("%c", &ans);
        while(ans == ' ' || ans == '\n')
            scanf("%c", &ans);
        if(ans == 'Y' || ans == 'y')
            printf("\n\n\n\n\n");
    }
    while(ans == 'Y' || ans == 'y');
    if(ans != 'Y' ||ans != 'y')
    {
        clrscr();
        headings("PLAYFAIR CIPHER");
        centerText(mnl, "Terminating the Program.");
        lines(mnl);
    }
    return 0;
}
