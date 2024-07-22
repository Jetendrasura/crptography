#include <stdio.h>
#include <ctype.h>
#include <string.h>

void encipher();
void decipher();

int main()
{
    int choice;
    
    while(1)
    {
        printf("\n1. Encrypt Text");
        printf("\t2. Decrypt Text");
        printf("\t3. Exit");
        printf("\n\nEnter Your Choice : ");
        scanf("%d",&choice);
        
        if(choice == 3)
            break;
        else if(choice == 1)
            encipher();
        else if(choice == 2)
            decipher();
        else
            printf("Please Enter Valid Option.");
    }
    
    return 0;
}

void encipher()
{
    unsigned int i, j;
    char input[50], key[50]; // Increase size to accommodate longer keys
    
    printf("\n\nEnter Plain Text: ");
    scanf("%s", input);
    
    printf("\nEnter Key Value: ");
    scanf("%s", key);
    
    printf("\nResultant Cipher Text: ");
    for(i = 0, j = 0; i < strlen(input); i++, j++)
    {
        if(j >= strlen(key))
            j = 0;
        
        char plain_char = toupper(input[i]) - 'A';
        char key_char = toupper(key[j]) - 'A';
        
        char cipher_char = (plain_char + key_char) % 26 + 'A';
        
        printf("%c", cipher_char);
    }
    
    printf("\n");
}

void decipher()
{
    unsigned int i, j;
    char input[50], key[50]; // Increase size to accommodate longer keys
    
    printf("\n\nEnter Cipher Text: ");
    scanf("%s", input);
    
    printf("\n\nEnter the key value: ");
    scanf("%s", key);
    
    printf("\nDeciphered Text: ");
    for(i = 0, j = 0; i < strlen(input); i++, j++)
    {
        if(j >= strlen(key))
            j = 0;
        
        char cipher_char = toupper(input[i]) - 'A';
        char key_char = toupper(key[j]) - 'A';
        
        char plain_char = (cipher_char - key_char + 26) % 26 + 'A';
        
        printf("%c", plain_char);
    }
    
    printf("\n");
}

