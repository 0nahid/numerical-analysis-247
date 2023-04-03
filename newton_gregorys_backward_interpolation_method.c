#include <stdio.h>

float u_cal(float u, int n)
{
    float temp = u;
    for (int i = 1; i < n; i++)
        temp *= (u + i);
    return temp;
}

int fact(int n)
{
    int f = 1;
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}

int main()
{
    int n = 5;
    float x[] = {80, 85, 90, 95, 100};
    float y[][5] = {{5026, 0, 0, 0, 0}, {5674, 0, 0, 0, 0}, {6362, 0, 0, 0, 0}, {7088, 0, 0, 0, 0}, {7854, 0, 0, 0, 0}};
    float value = 98;
    printf("GIVEN TABLE:\n\n");
    for (int i = 0; i < n; i++)
        printf("%.5f\t", x[i]);
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%.5f\t", y[i][0]);
    printf("\n\nVALUE = %.5f\n", value);
    for (int i = 1; i < n; i++)
        for (int j = n - 1; j >= i; j--)
            y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
    printf("\nTHE BACKWARD DIFFERENCE TABLE:\n\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            printf("%.5f\t", y[i][j]);
        printf("\n");
    }
    float sum = y[n - 1][0];
    float u = (value - x[n - 1]) / (x[1] - x[0]);
    for (int i = 1; i < n; i++)
        sum += (u_cal(u, i) * y[n - 1][i]) / fact(i);
    printf("\nVALUE AT %.5f IS %.5f\n", value, sum);
    return 0;
}
