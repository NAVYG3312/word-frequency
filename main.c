#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PARAGRAPH_LENGTH 1000
#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

void toLowerCase(char str[]);
void removePunctuation(char str[]);
void countWordFrequencies(char paragraph[], int wordCount[], char words[][MAX_WORD_LENGTH], int *totalWords);
int findWordIndex(char words[][MAX_WORD_LENGTH], int totalWords, char word[]);

int main() {
    char paragraph[MAX_PARAGRAPH_LENGTH];
    char words[MAX_WORDS][MAX_WORD_LENGTH] = {0};
    int wordCount[MAX_WORDS] = {0};
    int totalWords = 0;

    printf("Enter a paragraph: ");
    fgets(paragraph, MAX_PARAGRAPH_LENGTH, stdin);

    removePunctuation(paragraph);
    toLowerCase(paragraph);
    countWordFrequencies(paragraph, wordCount, words, &totalWords);

    printf("Word frequencies:\n");
    for (int i = 0; i < totalWords; i++) {
        printf("%s: %d\n", words[i], wordCount[i]);
    }

    return 0;
}

void toLowerCase(char str[]) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void removePunctuation(char str[]) {
    int i, j;
    for (i = 0, j = 0; str[i] != '\0'; i++) {
        if (!ispunct(str[i])) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

void countWordFrequencies(char paragraph[], int wordCount[], char words[][MAX_WORD_LENGTH], int *totalWords) {
    char *word = strtok(paragraph, " \n");
    while (word != NULL) {
        int index = findWordIndex(words, *totalWords, word);
        if (index == -1) {
            strcpy(words[*totalWords], word);
            wordCount[*totalWords]++;
            (*totalWords)++;
        } else {
            wordCount[index]++;
        }
        word = strtok(NULL, " \n");
    }
}

int findWordIndex(char words[][MAX_WORD_LENGTH], int totalWords, char word[]) {
    for (int i = 0; i < totalWords; i++) {
        if (strcmp(words[i], word) == 0) {
            return i;
        }
    }
    return -1;
}
