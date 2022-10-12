#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

static int mnl = 100, snl = 75;
char key[1000] = "";

void lines(int nl)
{
    for (int i = 0; i < nl; i++)
        printf("-");
    printf("\n");
}
void centerText(int nl, char *str)
{
    int len = (int)(strlen(str) / 2);
    nl = nl / 2;
    for (int i = 0; i < nl - len; i++)
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

void HillCipherEncryption()
{
    headings("HILL CIPHER ENCRYPTION");
    char text[1000] = "", restext[1000] = "";
    int len, key[3][3], append, i, j, arr[3][1], k = 0, result[3][1], l = 0;
    printf("Enter text: ");
    scanf("%s", text);
    while (strcmp(text, "\n") == 0)
        scanf("%s", text);
    len = strlen(text);
    if (len % 3 != 0)
    {
        append = 3 - (len % 3);
        for (i = 0; i < append; i++)
        {
            text[len + i] = 'X';
        }
        text[len++ + i] = '\0';
        len = strlen(text);
    }
    printf("Modified Input Text: %s of length: %d\n", text, len);
    lines(snl);
    printf("You can now enter the Key in 3x3 matrix form.\n");
    for (i = 0; i < 3; i++)
    {
        printf("Enter row %d, comma seperated: ", i + 1);
        scanf("%d,%d,%d", &key[i][0], &key[i][1], &key[i][2]);
    }
    printf("\nEntered 3x3 matrix for key:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", key[i][j]);
        }
        printf("\n");
    }
    lines(snl);
    for (i = 0; i < len; i += 3)
    {
        k = 0;
        for (j = i; j < i + 3; j++)
        {
            arr[k++][0] = (int)(text[j]) - 65;
            // printf("%d ", arr[0][k-1]);
        }
        // printf("\n");
        for (j = 0; j < 3; j++)
        {
            result[j][0] = 0;
            for (k = 0; k < 3; k++)
            {
                result[j][0] += key[j][k] * arr[k][0];
            }
            restext[l++] = (char)((result[j][0] % 26) + 65);
            // printf("%d\n", result[j][0]);
        }
    }
    printf("The encrypted text: %s\n", restext);
    lines(snl);
}

int negativeModulo(num)
{
    if (num >= 0)
        return num;
    else
        num = 26 + num;
    return num;
}

void HillCipherDecryption()
{
    headings("HILL CIPHER DECRYPTION");
    char text[1000] = "", restext[1000] = "";
    int len, key[3][3], append, i, j, arr[3][1], k = 0, result[3][1], l = 0, det, mulinv, adj[3][3];
    printf("Enter encrypted text: ");
    scanf("%s", text);
    while (strcmp(text, "\n") == 0)
        scanf("%s", text);
    len = strlen(text);
    lines(snl);
    printf("You can now enter the Key in 3x3 matrix form.(We would compute inverse for you.)\n");
    for (i = 0; i < 3; i++)
    {
        printf("Enter row %d, comma seperated: ", i + 1);
        scanf("%d,%d,%d", &key[i][0], &key[i][1], &key[i][2]);
    }
    printf("\nEntered 3x3 matrix for key:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", key[i][j]);
        }
        printf("\n");
    }
    det = (int)(((key[0][0] * ((key[1][1] * key[2][2]) - (key[1][2] * key[2][1]))) - (key[0][1] * ((key[1][0] * key[2][2]) - (key[1][2] * key[2][0]))) + (key[0][2] * ((key[1][0] * key[2][1]) - (key[1][1] * key[2][0])))) % 26);
    if (det == 0)
    {
        printf("Inverse of Key matrix doesn't exist.");
        exit(1);
    }
    printf("Determinant of the matrix: %d\n", det);
    for (i = 1; i <= 25; i++)
    {
        if (((det * i) % 26) == 1)
        {
            mulinv = i;
            break;
        }
    }
    printf("Multiplicative Inverse found: %d", mulinv);
    adj[0][0] = negativeModulo(((key[1][1] * key[2][2]) - (key[1][2] * key[2][1])) % 26);
    adj[1][0] = negativeModulo((-1 * ((key[1][0] * key[2][2]) - (key[1][2] * key[2][0]))) % 26);
    adj[2][0] = negativeModulo(((key[1][0] * key[2][1]) - (key[1][1] * key[2][0])) % 26);

    adj[0][1] = negativeModulo((-1 * ((key[0][1] * key[2][2]) - (key[0][2] * key[2][1]))) % 26);
    adj[1][1] = negativeModulo(((key[0][0] * key[2][2]) - (key[0][2] * key[2][0])) % 26);
    adj[2][1] = negativeModulo((-1 * ((key[0][0] * key[2][1]) - (key[0][1] * key[2][0]))) % 26);

    adj[0][2] = negativeModulo(((key[0][1] * key[1][2]) - (key[0][2] * key[1][1])) % 26);
    adj[1][2] = negativeModulo((-1 * ((key[0][0] * key[1][2]) - (key[0][2] * key[1][0]))) % 26);
    adj[2][2] = negativeModulo(((key[0][0] * key[1][1]) - (key[0][1] * key[1][0])) % 26);
    printf("\nInverse of the given Key matrix is:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            adj[i][j] = (adj[i][j] * mulinv) % 26;
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
    lines(snl);
    l = 0;
    for (i = 0; i < len; i += 3)
    {
        k = 0;
        for (j = i; j < i + 3; j++)
        {
            arr[k++][0] = (int)(text[j]) - 65;
        }

        for (j = 0; j < 3; j++)
        {
            result[j][0] = 0;
            for (k = 0; k < 3; k++)
            {
                result[j][0] += adj[j][k] * arr[k][0];
            }
            restext[l++] = (char)((result[j][0] % 26) + 65);
            // printf("%d\n", result[j][0]);
        }
    }
    printf("The decrypted text: %s\n", restext);
}

int main()
{
    char ans = 'y';
    while (ans == 'y' || ans == 'Y')
    {
        clrscr();
        int op;
        headings("HILL CIPHER");
        subheadings("Menu");
        printf("1. Encrypt text using key.\n");
        printf("2. Decrypt encrypted text using key.\n");
        lines(snl);
        printf("Enter your choice: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
        {
            clrscr();
            HillCipherEncryption();
            break;
        }
        case 2:
        {
            clrscr();
            HillCipherDecryption();
            break;
        }
        default:
        {
            printf("Invalid option chosen\n");
        }
        }
        printf("Do you want to perform another task ?(y/n): ");
        scanf("%c", &ans);
        while (ans == ' ' || ans == '\n')
            scanf("%c", &ans);
    }
    return 0;
}