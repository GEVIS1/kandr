#include<stdio.h>

main() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    celsius = lower;

    printf("Celsius\tFahrenheit\n");
    while (celsius <= upper) {
        fahr = (celsius / (5.0 / 9.0)) + 32;
        printf("%7.0f %10.0f\n", celsius, fahr);
        celsius = celsius + step;
    }
}