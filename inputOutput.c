#ifndef INPUT_OUTPUT_C
#define INPUT_OUTPUT_C

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "structures.h"


void addLetter(char* line, Letter* arrInput, char*** board, int rowIndex, int squareSize, int* INPUT_OK){


    for(int columnIndex = 0; columnIndex<squareSize; columnIndex++){

            if(!isupper(line[columnIndex])){
                printf("\n**** ONLY UPPER LETTERS ALLOWED! ****\n");
                *INPUT_OK = 0;
                return;
            }
            char letter = line[columnIndex];
            int index = letter - 'A';
            arrInput[index].mLetter = letter;
            arrInput[index].mLetterOccurance++;

            if(!letter){
                arrInput[index].mCoordinates = (Coordinates*)malloc(sizeof(Coordinates));
            }else{
                arrInput[index].mCoordinates = (Coordinates*)realloc(arrInput[index].mCoordinates,
                 arrInput[index].mLetterOccurance * sizeof(Coordinates));
            }

            arrInput[index].mCoordinates[arrInput[index].mLetterOccurance - 1] = {rowIndex, columnIndex};
            (*board)[rowIndex][columnIndex] = letter;
    }
}

void readInput(Letter* arrInput, char*** board, int* squareSize, int* INPUT_OK){

    //get first line
    char* line = NULL;
    size_t size = 0;
    getline(&line, &size, stdin);
    *squareSize = strlen(line) - 1;
    line[*squareSize] = '\0';
    int rowIndex = 0; 

    //allocate board
    *board = (char**) malloc((*squareSize)*sizeof(char*));
    for(int i = 0; i<*squareSize; i++){
        (*board)[i] = (char*) malloc((*squareSize)*sizeof(char));
    }

    addLetter(line, arrInput, board, rowIndex, *squareSize, INPUT_OK);

    //get rest
    rowIndex++;

    while(rowIndex < *squareSize && *INPUT_OK){
        getline(&line, &size, stdin);
        //check if length matches the length of the grid
        if(strlen(line) - 1 != *squareSize){
            printf("\n**** WRONG LENGTH OF LINE! ****\n");
            *INPUT_OK = 0;
            return;
        }
        addLetter(line, arrInput, board, rowIndex, *squareSize, INPUT_OK);
        rowIndex++;
    }

    free(line);
}

int lineIsUpperCase(char* line, int len){
    for(int i = 0; i<len; i++){
        if(!isupper( line[i] )) return 0;
    }
    return 1;
}

void readSearchedWords(char** arrSearchedWords, int squareSize, int* numOfWordsToSearch, int* INPUT_OK){
    char* line = NULL;
    size_t size = 0;

    int indexOfWords = 0;
    while(getline(&line, &size, stdin) != -1 && *INPUT_OK){
        if(indexOfWords == WORDS_LIMIT_PER_ROW_LENGTH*squareSize - 1){
            printf("\n**** LIMIT OF WORDS TO SEARCH EXCEEDED! ****.\n");
            *INPUT_OK = 0;
            break;
        }
        int len = strlen(line) - 1;
        line[len] = '\0';
        if(!lineIsUpperCase(line, len)){
            printf("\n**** ONLY UPPER LETTERS ALLOWED! ****\n");
            *INPUT_OK = 0;
            break;
        }
        arrSearchedWords[indexOfWords] = (char*) malloc(len*sizeof(char));
        strncpy(arrSearchedWords[indexOfWords], line, len+1);
        indexOfWords++;
    }

    free(line);
    *numOfWordsToSearch = indexOfWords;   
}

void printFoundWords(int numOfWordsToSearch, int* arrWordsOccurance, char** arrWordsToSearch){

    printf("\n***** WORDS FOUND ****\n");
    for(int i = 0; i<numOfWordsToSearch; i++){
        if(arrWordsOccurance[i] != 0){
            printf("%s %d x\n", arrWordsToSearch[i], arrWordsOccurance[i]);
        }
    }
}

#endif