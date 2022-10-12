#include<stdio.h>
char monocipher_encr(char);

char alpha[26][2] = { { 'a', 'f' }, { 'b', 'a' }, { 'c', 'g' }, { 'd', 'u' }, {
        'e', 'n' }, { 'f', 'i' }, { 'g', 'j' }, { 'h', 'k' }, { 'i', 'l' }, {
        'j', 'm' }, { 'k', 'o' }, { 'l', 'p' }, { 'm', 'q' }, { 'n', 'r' }, {
        'o', 's' }, { 'p', 't' }, { 'q', 'v' }, { 'r', 'w' }, { 's', 'x' }, {
        't', 'y' }, { 'u', 'z' }, { 'v', 'b' }, { 'w', 'c' }, { 'x', 'd' }, {
        'y', 'e' }, { 'z', 'h' } };
        
//char plaintext[20];

char monocipher_encr(char a) {
    int i;
    
    for (i = 0; i < 27; i++) {
        if (a == alpha[i][0])
            break;
    }
    return alpha[i][1];
}

int main() {
    char plaintext[20], ciphertext[20];
    
    int i;
    printf("\n-------- Monoalphabetic - Encryption --------\n");
    printf("\n Enter Plain Text To Encrypt: ");
    
    // gets(str);
    fgets(plaintext, sizeof(plaintext), stdin);
    
    for (i = 0; plaintext[i]; i++) {
        ciphertext[i] = monocipher_encr(plaintext[i]);
    }
    
    ciphertext[i] = '\0';

    printf("___________________________________________\n");
    printf("\nEncrypted Message : %s\n", ciphertext);
    printf("___________________________________________");
}


