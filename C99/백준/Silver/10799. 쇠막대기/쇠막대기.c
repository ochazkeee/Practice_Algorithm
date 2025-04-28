#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int stack = 0;
int pieces = 0;
int main() {
    char buff[100001];
    char pre;

    fgets(buff, 100001, stdin);

    for (int i = 0; buff[i] != '\0'; i++) {
        if (i==0){pre = buff[i];}
        if (buff[i] == '(') {
            pieces++;
            stack++;
        }
        if (buff[i] == ')') {
            if (stack == 0) {
                return -1;
            }

            if (pre == '(') {
                stack--;
                pieces--;
                pieces += stack;
            }

            if (pre == ')') {
                stack--;
            }

        }
        pre = buff[i];

    }

    printf("%d",pieces);
    return 0;
}