# COMPILER-DESIGN-BASICS.

*COMPANY*: CODTECH IT SOLUTIONS

*NAME*: NANDYALA NANDITHA

*INTERN ID*: CT04DN872

*DOMAIN*: C Programming

*DURATION*: 4 WEEKS

*MENTOR*: NEELA SANTHOSH KUMAR

*OVERVIEW OF THE PROJECT*

A lexical analyzer (or lexer) is the first phase of a compiler. It takes source code as input and breaks it down into meaningful units called tokens. Tokens can be keywords, identifiers, numbers, operators, punctuation, etc. The lexical analyzer simplifies the compiler's task by converting raw source code text into a structured stream of tokens.

The Input Program
 input program (stored in input.txt) is a short snippet of C-like code:

int a = b + 5;
float value = 10.25;
if (a < value) return;
This code declares variables, assigns values, and uses a conditional statement and return statement. The lexical analyzer reads this code, processes it, and identifies tokens like int (keyword), a (identifier), = (operator), b (identifier), + (operator), 5 (number), and so on.

Breakdown of lexical_analyzer.c
1. Keyword List
At the top, an array of keywords is defined:

char keywords[10][10] = {
    "int", "float", "if", "else", "while",
    "do", "return", "break", "for", "char"
};
These are common reserved words in C. The program will compare scanned tokens against this list to detect if a token is a keyword.

2. Keyword Detection (isKeyword function)

int isKeyword(char *word) {
    for (int i = 0; i < 10; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;  
    }
    return 0;  /
}
This function compares the given word with each keyword in the list. If it matches any, it returns 1 (true). Otherwise, it returns 0 (false).

3. Number Detection (isNumber function)

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
This function checks if the string is a valid numeric constant. It allows digits and at most one dot (.) for floating-point numbers.

4. Main Processing Loop
The program opens the file input.txt.

It reads characters one by one using fgetc.

If a character is alphanumeric (letters or digits) or a dot, it adds it to a temporary buffer.

When a non-alphanumeric character (like whitespace, punctuation, or operator) is encountered, it considers the accumulated buffer as a token.

The token is classified using isKeyword, isNumber, or else treated as an identifier.

Then the single character itself is checked if it is an operator (+, -, *, /, =, <, >, %) and printed.

This loop continues until the end of the file.

5. Final Buffer Check
At the end of the file, the program checks if there's any leftover token in the buffer and classifies it similarly.

How the Program Works With the Input
Given input program:

int a = b + 5;
float value = 10.25;
if (a < value) return;
The lexer reads "int" → detects it as a keyword.

Reads "a" → identifier.

Reads "=" → operator.

Reads "b" → identifier.

Reads "+" → operator.

Reads "5" → number.

Reads "float" → keyword.

Reads "value" → identifier.

Reads "=" → operator.

Reads "10.25" → number (valid float).

Reads "if" → keyword.

Reads "a" → identifier.

Reads "<" → operator.

Reads "value" → identifier.

Reads "return" → keyword.

**Conclusion**

This lexical analyzer serves as a basic example of the first phase of a compiler's front-end. It demonstrates how source code can be tokenized and classified efficiently. Your program successfully reads input source code from a file, breaks it down into meaningful components, and outputs the token type for each. This lays the foundation for further compiler stages such as syntax analysis and semantic analysis.

**OUTPUT**

![Image](https://github.com/user-attachments/assets/f7da8028-bec3-497b-b662-1963f70a0c27)
