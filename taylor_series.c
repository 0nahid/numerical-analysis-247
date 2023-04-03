#include <stdio.h>
#include <math.h>

double polynomial(double x, double y)
{
    return pow(y, 2) + x; // y' = y^2 + x
}
double factorial(int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}
int main()
{
    double x0, y0, xn, y, yp, ypp, yppp, ypppp, yppppp;
    int n = 5; // number of terms in Taylor series

    printf("ENTER THE INITIAL VALUE OF X (X0): ");
    scanf("%lf", &x0);
    printf("\nENTER THE INITIAL VALUE OF X (Y0): ");
    scanf("%lf", &y0);
    printf("\nENTER THE VALUE OF X AT WHICH Y IS TO BE CALCULATED: ");
    scanf("%lf", &xn);

    y = y0;
    yp = polynomial(x0, y0);
    ypp = 2 * y0 * yp + 1;
    yppp = 2 * yp * ypp + 2 * y0 * pow(yp, 2);
    ypppp = 2 * pow(yp, 2) + 6 * y0 * yp * ypp + 2 * pow(y0, 2) * ypp + 2 * y0 * yp * yppp;
    yppppp = 6 * y0 * yp * yppp + 6 * pow(yp, 2) * ypp + 8 * y0 * yp * ypppp + 2 * pow(y0, 2) * yppp;

    double h = xn - x0;
    double taylor_series = y + h * yp + (pow(h, 2) * ypp) / factorial(2) + (pow(h, 3) * yppp) / factorial(3) + (pow(h, 4) * ypppp) / factorial(4) + (pow(h, 5) * yppppp) / factorial(5);
    y += h * yp + (pow(h, 2) * ypp) / factorial(2) + (pow(h, 3) * yppp) / factorial(3) + (pow(h, 4) * ypppp) / factorial(4) + (pow(h, 5) * yppppp) / factorial(5);

    printf("\nThe value of y at x = %lf is: %.5lf\n", xn, y);

    return 0;
}
