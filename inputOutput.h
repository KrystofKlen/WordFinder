
#include <stdlib.h>
#include "structures.h"

void addLetter(char* line, Letter* arrInput, char*** board, int rowIndex, int squareSize, int* INPUT_OK);

void readInput(Letter* arrInput, char*** board, int* squareSize, int* INPUT_OK);

int lineIsUpperCase(char* line, int len);

void readSearchedWords(char** arrSearchedWords, int squareSize, int* numOfWordsToSearch, int* INPUT_OK);

void printFoundWords(int numOfWordsToSearch, int* arrWordsOccurance, char** arrWordsToSearch);