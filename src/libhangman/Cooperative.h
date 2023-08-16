#ifndef COOPERATIVE_H
#define COOPERATIVE_H
#define MAX_WORDS 10
typedef struct {
    char topic[50];            // тема
    char words[MAX_WORDS][50]; // слова связанные с темой
    int numWords;              // кол слов в словаре
} TopicDictionary;
void initTopicDictionary(TopicDictionary* topicDictionary);
void addWordToTopic(
        TopicDictionary* topicDictionary, const char* topic, const char* word);
void cooperative1(char str1[]);
void cooperative();
#endif