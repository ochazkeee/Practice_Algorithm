#include <stdio.h>

int main()
{
    int a, b;
    int cnt = 1;
    int point = 0;
    double result; 

    scanf("%d %d", &a, &b);

    result = (double)a / b; 

    while (result * cnt - (int)(result * cnt) > 0.1) {
        point++;
        cnt *= 10;
    }

    if (point == 0) {
        printf("%d", (int)result); 
    } else {
        printf("%.*f", point, result);  
    }

    return 0;
}
