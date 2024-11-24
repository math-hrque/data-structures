#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int stringHash(char *s) {
    char c;
    int p = 31, m = 97;
    int hashValue = 0, pPow = 1;

    while ((c = *s++)) {
        hashValue = (hashValue + (c - 'a' + 1) * pPow) % m;
        pPow = (pPow * p) % m;
    }
    return hashValue;
}

int main() {
    char s[255];

    printf("Enter a string to calculate its hash: ");
    fgets(s, 255, stdin);
    s[strcspn(s, "\n")] = '\0';

    printf("The hash value of '%s' is: %d\n", s, stringHash(s));
    return 0;
}
