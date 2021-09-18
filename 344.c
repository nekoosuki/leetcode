#include <stdio.h>
void reverseString(char* s, int sSize) {
    char *p, *q;
    char t = '\0';
    p = s;
    q = s + sSize - 1;
    while (p < q) {
        t = *p;
        *p = *q;
        *q = t;
        p++;
        q--;
    }
}

int main() {
    char s[] = "test";
    reverseString(s, 4);
    printf("%s", s);
    return 0;
}