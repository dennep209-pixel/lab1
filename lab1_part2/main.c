#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    // оголошення змінних, які будуть використовуватися в програмі
    unsigned int variant; // 1 або 2 — допустимі значення змінної variant
    int N;
    int n;

    double start, end, delta, x;

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
    }
    else if (variant == 2)
    {
        printf("Enter delta: ");
        scanf("%lf", &delta);
    }

    printf("Program finished\n");

    return 0;
}
