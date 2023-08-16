#include "Single.h"
#include "Game.h"
#include "checks.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void single()
{
    char str1[100];
    printf("Введите загаданное слово: ");
    scanf("%s", str1);
    if (checkLength(str1)) {
        printf("В слове должно быть не больше %d букв\n", MAX_LENGTH);
        exit(1);
    }
    if (!isWord(str1)) {
        printf("Введеная строка не является словом\n");
        exit(1);
    }
    game(str1);
}
