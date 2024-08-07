#include<stdio.h>

/* Rewrite the temperature conversion program of Section 1.2 (1.4.c) to use a 
function for conversion. */

float celsiustofahr(int celsius);

main() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    celsius = lower;

    printf("Celsius\tFahrenheit\n");
    while (celsius <= upper) {
        fahr = celsiustofahr(celsius);
        printf("%7.0f %10.0f\n", celsius, fahr);
        celsius = celsius + step;
    }
}

float celsiustofahr(int celsius) {
    return (celsius / (5.0 / 9.0)) + 32;
}