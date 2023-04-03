#include <stdio.h>
#include <math.h>

float f(float x) { return pow(x, 4) - x - 10; }

int main()
{
    float a, b, c;
    printf("THE GIVEN EQUATION IS X^4 - X - 10\n");
    printf("ENTER LOWER LIMIT: ");
    scanf("%f", &a);
    printf("ENTER UPPER LIMIT: ");
    scanf("%f", &b);
    if (f(a) * f(b) > 0 || a >= b)
        printf("INITIAL GUESS IS WRONG\n");
    else
    {
        do
            c = (a * f(b) - b * f(a)) / (f(b) - f(a)), a = b, b = c;
        while (fabs(f(c)) > 0.00001);
        printf("THE REQUIRED ROOT IS %.5f\n", c);
    }
    return 0;
}
