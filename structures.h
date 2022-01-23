#ifndef STRUCTURES_MACROS_H
#define STRUCTURES_MACROS_H

#define END_PROGRAM -1
#define SIZE_OF_ALPHABET 26
#define WORDS_LIMIT_PER_ROW_LENGTH 10
//int INPUT_OK = 1;

typedef struct COORDINATES{
    int mX;
    int mY;
}Coordinates;

typedef struct LETTER{
    char mLetter;
    int mLetterOccurance = 0;
    Coordinates* mCoordinates = NULL;
}Letter;

#endif