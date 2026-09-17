#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    // оголошення змінних, які будуть використовуватися в програмі
    unsigned int variant; // 1 або 2 — допустимі значення змінної variant
    int N;
    int n;
    int line;
    int firstpause;
    double start, end, delta, x, y;
    double oldX, oldY;

    // виконуємо введення змінної variant
    // При введені недопустимих значень відбувається повторне введення
    // за допомогою циклу while()

    // введення варіанту
    printf("Enter variant (1 or 2): ");
    scanf("%u", &variant);
    // перевірка правильності варіанту
    while (variant != 1 && variant != 2)
    {
        printf("Variant not valid\n");
        printf("Enter variant (1 or 2): ");
        scanf("%u", &variant);
    }
    // введення початкового та кінцевого значення
    printf("Enter X1: ");
    scanf("%lf", &start);

    printf("Enter X2: ");
    scanf("%lf", &end);
    // перший варіант введення
    if (variant == 1)
    {
         printf("Enter N: ");
        scanf("%d", &N);
        delta = (end - start) / (N - 1);
    }
    // другий варіант введення
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

    // шапка таблиці
    printf("+-------+---------------------+---------------------+\n");
printf("| Point |          X          |        F(X)         |\n");
printf("+-------+---------------------+---------------------+\n");

    line=0;
    firstpause=1;
    // побудова таблиці
    for (n = 0; n < N; n++)
    {
        x = start + n * delta;

        // функція варіанту 10
        y = 0.25 * (x - 25) * (x - 25)
            + ((x + 25) * (x + 25) * (x + 25)) / 100
            + 1;

        printf("|%7d|%21.2lf|%21.2lf|\n", n + 1, x, y);

        line = line + 1;

        // зупинка виведення при заповненні екрану
        if (line == 20 && n < N - 1)
        {
           if (firstpause==1)
            {
             printf("Press Any Key to Continue...");
            firstpause=0;
            }

            getch();

            line = 0;
        }
}
    printf("+-------+---------------------+---------------------+\n");

    // пошук проміжків зміни знаку функції

    oldX = start;

    oldY = 0.25 * (oldX - 25) * (oldX - 25)
           + ((oldX + 25) * (oldX + 25) * (oldX + 25)) / 100
           + 1;

    printf("\nIntervals where function changes sign:\n");

    for (n = 1; n < N; n++)
    {
        x = start + n * delta;

        y = 0.25 * (x - 25)* (x - 25)+ ((x + 25) * (x + 25) * (x + 25)) / 100+ 1;

        if ((oldY < 0 && y > 0) || (oldY > 0 && y < 0))
        {
            printf("[%.2lf ; %.2lf]\n", oldX, x);
        }

        oldX = x;
        oldY = y;
    }

    printf("Program finished\n");

    return 0;
}
