#include<stdio.h>
char monocipher_encr(char);

char alpha[26][2] = { { 'a', 'f' }, { 'b', 'a' }, { 'c', 'g' }, { 'd', 'u' }, {
        'e', 'n' }, { 'f', 'i' }, { 'g', 'j' }, { 'h', 'k' }, { 'i', 'l' }, {
        'j', 'm' }, { 'k', 'o' }, { 'l', 'p' }, { 'm', 'q' }, { 'n', 'r' }, {
        'o', 's' }, { 'p', 't' }, { 'q', 'v' }, { 'r', 'w' }, { 's', 'x' }, {
        't', 'y' }, { 'u', 'z' }, { 'v', 'b' }, { 'w', 'c' }, { 'x', 'd' }, {
        'y', 'e' }, { 'z', 'h' } };

// char ciphertext[20];

char monocipher_encr(char a) {
    int i;
    
    for (i = 0; i < 26; i++) {
        if (a == alpha[i][1])   
            break;
    }
    return alpha[i][0];
}

int main() {
    char ciphertext[20], plaintext[20];
    
    int i;
    printf("\n-------- Monoalphabetic - Decryption --------\n");
    printf("\n Enter cipher Text To Decrypt: ");
    
    // gets(str);
    fgets(ciphertext, sizeof(ciphertext), stdin);
    
    for (i = 0; ciphertext[i]; i++) {
        plaintext[i] = monocipher_encr(ciphertext[i]);
    }
    
    plaintext[i] = '\0';

    printf("___________________________________________\n");
    printf("\nEncrypted Message : %s\n", plaintext);
    printf("___________________________________________");
}


