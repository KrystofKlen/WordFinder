
// HELPER FUNCTIONS FOR SEARCHING IN GRID

#include <stdlib.h>
#include "structures.h"

int searchHorizontallyRight(char* wordToFind, char** board, Coordinates coordinates, int squareSize);

int searchHorizontallyLeft(char* wordToFind, char** board, Coordinates coordinates, int squareSize);

int searchVerticallyUp(char* wordToFind, char** board, Coordinates coordinates, int squareSize);

int searchVerticallyDown(char* wordToFind, char** board, Coordinates coordinates, int squareSize);

int search1QuadrantUp(char* wordToFind, char** board, Coordinates coordinates, int squareSize);

int search1QuadrantDown(char* wordToFind, char** board, Coordinates coordinates, int squareSize);

int search2QuadrantUp(char* wordToFind, char** board, Coordinates coordinates, int squareSize);

int search2QuadrantDown(char* wordToFind, char** board, Coordinates coordinates, int squareSize);

void findWords(Letter* arrInput, int* arrWordsOccurance, char** board, char** arrWordsToSearch, int numOfWordsToSearch, int squareSize);

int getCountWordInBoard(char* wordToFind, char** board, Coordinates coordinates, int squareSize);
