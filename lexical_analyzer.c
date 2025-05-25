#include <stdio.h>
#include <string.h>
#include <ctype.h>

char keywords[10][10] = {
    "int", "float", "if", "else", "while",
    "do", "return", "break", "for", "char"
};

int isKeyword(char *word) {
    for (int i = 0; i < 10; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int isNumber(char *word) {
    int dotCount = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] == '.') {
            dotCount++;
            if (dotCount > 1) return 0;
        } else if (!isdigit(word[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    FILE *fp;
    char ch, buffer[50];
    int i = 0;

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error: Cannot open input.txt\n");
        return 1;
    }

    printf("Lexical Analysis Output:\n\n");

    while ((ch = fgetc(fp)) != EOF) {
       
        if (isalnum(ch) || ch == '.') {
            buffer[i++] = ch;
        } else {
            buffer[i] = '\0';
            i = 0;
          
            if (strlen(buffer) > 0) {
                if (isKeyword(buffer))
                    printf("%s : Keyword\n", buffer);
                else if (isNumber(buffer))
                    printf("%s : Number\n", buffer);
                else
                    printf("%s : Identifier\n", buffer);
            }

            if (ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
                ch == '=' || ch == '<' || ch == '>' || ch == '%') {
                printf("%c : Operator\n", ch);
            }
        }
    }

    buffer[i] = '\0';
    if (strlen(buffer) > 0) {
        if (isKeyword(buffer))
            printf("%s : Keyword\n", buffer);
        else if (isNumber(buffer))
            printf("%s : Number\n", buffer);
        else
            printf("%s : Identifier\n", buffer);
    }

    fclose(fp);
    return 0;
}
