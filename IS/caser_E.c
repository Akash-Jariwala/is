#include<stdio.h>
#include<conio.h>
#include<string.h>

void main()
{
    int key;  
    char plaintext[100],c;

    printf("\n-------- Caesar Cipher - Encryption --------\n");
    
    printf("\nEnter plain text To Encrypt : ");
    
    fgets(plaintext, sizeof(plaintext), stdin);
    
    printf("\nEnter Key : ");
    scanf("%d", &key);
    
    
    for(int i=0;plaintext[i]!='\0';++i)
    {
        c=plaintext[i];
        
        
        if(c>='a' && c<='z'){
            c=c+key;
            
            if(c>'z'){
                c=c-'z'+'a'-1;
            }         
            
            plaintext[i]=c;
        }
        
        else if(c>='A'&&c<='Z'){
            c=c+key;
            
            if(c>'Z'){
                c=c-'Z'+'A'-1;
            }
                
            plaintext[i]=c;
        }
        
        else if(c>='0'&&c<='9'){
            c=c+key;
            
            if(c>'9'){
                c=c-'9'+'0'-1;
            }
                
            plaintext[i]=c;
        }
    }
    printf("___________________________________________\n");
    printf("\nEncrypted Message : %s", plaintext);
    printf("___________________________________________");
    getch();
}