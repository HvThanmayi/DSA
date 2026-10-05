#include <stdio.h>
#include <string.h>

int main()
{
    char str[100], out[100], ch;
    int top = -1;

    printf("Enter a string: ");
    scanf("%99s", str);

    printf("Enter a character: ");
    scanf(" %c", &ch);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            top = i;  // Keep the last occurrence
        }
    }

    if (top == -1) {
        printf("Character not found in the string.\n");
        return 0;
    }

    int s = 0;

    for (int j = top; j >= 0; j--) {
        out[s++] = str[j];
    }

    for (int j = top + 1; str[j] != '\0'; j++) {
        out[s++] = str[j];
    }

    out[s] = '\0';

    printf("The new string is: %s\n", out);
    return 0;
}