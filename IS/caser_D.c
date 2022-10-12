#include<stdio.h>
#include<conio.h>
#include<string.h>

void main()
{
    int key;  
    char ciphertext[100],c;

    printf("\n-------- Caesar Cipher - Decryption --------\n");
    
    printf("\nEnter Cipher Text To Decrypt : ");
    
    fgets(ciphertext, sizeof(ciphertext), stdin);
    
    printf("\nEnter Key : ");
    scanf("%d", &key);
    
    
    for(int i=0;ciphertext[i]!='\0';++i)
    {
        c=ciphertext[i];
        
        
        if(c>='a' && c<='z'){
            c=c-key;
            
            if(c>'z'){
                c=c-'z'+'a'-1;
            }         
            
            ciphertext[i]=c;
        }
        
        else if(c>='A'&&c<='Z'){
            c=c-key;
            
            if(c>'Z'){
                c=c+'Z'-'A'+1;
            }
                
            ciphertext[i]=c;
        }
        
        else if(c>='0'&&c<='9'){
            c=c-key;
            
            if(c>'9'){
                c=c+'9'-'0'+1;
            }
                
            ciphertext[i]=c;
        }
    }
    
    printf("___________________________________________\n");
    printf("\nDecrypted Message : %s", ciphertext);
    printf("___________________________________________");
    getch();
}