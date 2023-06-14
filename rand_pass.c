#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    int length, ch;
    char s[100];

    FILE* fp;
    
    fp = fopen("passwords.txt", "a");

    printf("Enter the Lenght: ");
    scanf("%d", &length);
    getchar();

    printf("Enter the Name of site(max. characters 100): ");
    scanf("%[^\n]", s, 100);
    
    if (length < 8)
    {
        printf("The Lenght is too short.\n");
        return 1;
    }
    char *pass = malloc(length + 1);

    char* digits = "01234568789";
    int digits_length = strlen(digits);

    char* lowerCase = "abcdefghijklmnopqrstuvwxyz";
    int lowerCase_length = strlen(lowerCase);

    char* upperCase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int upperCase_length = strlen(upperCase);

    char* symbols = "!@#$^&*()";
    int symbols_length = strlen(symbols);

    srand(time(NULL));

    for (int i = 0; i < length; i++)
    {
        int char_type = rand() % 4;

        switch (char_type)
        {
        case 0: pass[i] = digits[rand() % digits_length]; break;
        case 1: pass[i] = lowerCase[rand() % lowerCase_length]; break;
        case 2: pass[i] = upperCase[rand()% upperCase_length]; break;
        case 3: pass[i] = symbols[rand() % symbols_length]; break;
        }
    }
    
    pass[length] = '\0';

    fprintf(fp, "%s %s: %s\n", "Password", s, pass);

    free(pass);
    fclose(fp);
    
    return 0;
}