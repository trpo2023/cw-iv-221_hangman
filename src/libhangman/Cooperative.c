#include "Cooperative.h"
#include "Game.h"
#include "checks.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void initTopicDictionary(TopicDictionary* topicDictionary)
{
    topicDictionary->numWords = 0;
}

void addWordToTopic(
        TopicDictionary* topicDictionary, const char* topic, const char* word)
{
    if (checkMaxWords(topicDictionary->numWords)) {
        printf("Максимум слов для этой темы '%s'\n", topic);
        return;
    }
    strcpy(topicDictionary->topic, topic);
    strcpy(topicDictionary->words[topicDictionary->numWords], word);
    topicDictionary->numWords++;
}
void cooperative()
{
    int p;
    TopicDictionary topic1;
    initTopicDictionary(&topic1);

    addWordToTopic(&topic1, "Animals", "dog");
    addWordToTopic(&topic1, "Animals", "cat");

    TopicDictionary topic2;
    initTopicDictionary(&topic2);

    addWordToTopic(&topic2, "Fruits", "apple");
    addWordToTopic(&topic2, "Fruits", "banana");
    addWordToTopic(&topic2, "Fruits", "orange");
    printf("Выберите тему. \n1 - животные.\n2-фрукты.\n");
    scanf("%d", &p);
    while (p != 1 && p != 2) {
        printf("Неправильный ввод. Повторите попытку.\n");
        scanf("%d", &p);
    }
    srand(time(NULL));
    if (p == 1) {
        int randword = rand() % topic1.numWords;
        game(topic1.words[randword]);
    }
    if (p == 2) {
        int randword = rand() % topic1.numWords;
        game(topic2.words[randword]);
    }
}