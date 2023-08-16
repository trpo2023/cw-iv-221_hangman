#include "Game.h"
#include "checks.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void game(char str1[])
{
    char z;
    int misses = 0; // количество попыток
    int true = 0, i;
    int str1Len = strlen(str1); // длина слова
    char* str2 = (char*)calloc(
            str1Len,
            sizeof(char)); // динамически задаём второй массив, в котором будут
                           // показываться отгаданные буквы
    memset(str2, '_', str1Len);
    int length = str1Len;
    while (misses < MAX_MISSES && true < length) {
        printf("\nВведите букву: %s\n", str2);
        scanf(" %c", &z);
        int flag = 0;
        for (i = 0; i < str1Len; i++) {
            if (str1[i] == z && str2[i] != z) {
                str2[i] = z;
                true ++;
                flag = 1;
            }
        }
        if (flag == 0) {
            misses++;
            printf("Неправильная буква! Осталось попыток: %d\n",
                   MAX_MISSES - misses);
            checkmaxmisses(misses);
        }

        switch (misses) {
        case 1:
            printf("\n+---+   ");
            printf("\n|   |   ");
            printf("\n|   @   ");
            printf("\n|       ");
            printf("\n|       ");
            printf("\n|       ");
            printf("\n=========");
            break;
        case 2:
            printf("\n+---+   ");
            printf("\n|   |   ");
            printf("\n|   @   ");
            printf("\n|   |  ");
            printf("\n|       ");
            printf("\n|       ");
            printf("\n=========");
            break;
        case 3:
            printf("\n+---+   ");
            printf("\n|   |   ");
            printf("\n|   @   ");
            printf("\n|  /|   ");
            printf("\n|       ");
            printf("\n|       ");
            printf("\n=========");
            break;
        case 4:
            printf("\n+---+   ");
            printf("\n|   |   ");
            printf("\n|   @   ");
            printf("\n|  /|\\  ");
            printf("\n|        ");
            printf("\n|       ");
            printf("\n=========");
            break;
        case 5:
            printf("\n+---+   ");
            printf("\n|   |   ");
            printf("\n|   @   ");
            printf("\n|  /|\\  ");
            printf("\n|  /     ");
            printf("\n|       ");
            printf("\n=========");
            break;
        case 6:
            printf("\n+---+   ");
            printf("\n|   |   ");
            printf("\n|   @   ");
            printf("\n|  /|\\  ");
            printf("\n|  / \\  ");
            printf("\n|       ");
            printf("\n=========");
            break;
        default:
            break;
        }
        if (str1Len == true) {
            printf("\nВы победили! %s\n", str1);
            free(str2);
        }
        if (misses == MAX_MISSES) {
            printf("\nВы проиграли! %s\n", str1);
            free(str2);
        }
    }
}
