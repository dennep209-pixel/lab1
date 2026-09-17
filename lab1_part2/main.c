#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    // оголошення змінних, які будуть використовуватися в програмі
    unsigned int variant; // 1 або 2 — допустимі значення змінної variant
    int N;
    int n;

    double start, end, delta, x, y;

    // виконуємо введення змінної variant
    // При введені недопустимих значень відбувається повторне введення
    // за допомогою циклу while()

    printf("Enter variant (1 or 2): ");
    scanf("%u", &variant);

    while (variant != 1 && variant != 2)
    {
        printf("Variant not valid\n");
        printf("Enter variant (1 or 2): ");
        scanf("%u", &variant);
    }
    printf("Enter X1: ");
    scanf("%lf", &start);

    printf("Enter X2: ");
    scanf("%lf", &end);

    if (variant == 1)
    {
         printf("Enter N: ");
        scanf("%d", &N);
        delta = (end - start) / (N - 1);
    }
    else if (variant == 2)
    {
        printf("Enter delta: ");
        scanf("%lf", &delta);
        N = (int)((end - start) / delta) + 1;
    }

    printf("X1 = %.2lf\n", start);
    printf("X2 = %.2lf\n", end);
    printf("N = %d\n", N);
    printf("delta = %.2lf\n", delta);

    printf("+-------+---------------------+---------------------+\n");
printf("| Point |          X          |        F(X)         |\n");
printf("+-------+---------------------+---------------------+\n");

    for (n = 0; n < N; n++)
    {
    x = start + n * delta;

    y = 0.25 * (x - 25) * (x - 25)
        + ((x + 25) * (x + 25) * (x + 25)) / 100
        + 1;

    printf("|%7d|%21.2lf|%21.2lf|\n", n + 1, x, y);
}
    printf("+-------+---------------------+---------------------+\n");
    printf("Program finished\n");

    return 0;
}
