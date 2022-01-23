#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "searchingFunctions.h"
#include "inputOutput.h"

int main(){

    int INPUT_OK = 1;

    //get letters in the grid
    int squareSize = 0;
    Letter* arrLetters = (Letter*) malloc(SIZE_OF_ALPHABET * sizeof(Letter));
    char** board;
    readInput(arrLetters, &board, &squareSize, &INPUT_OK);
    if(!INPUT_OK){
        for(int i = 0; i<squareSize; i++){
            free(board[i]);
        }
        free(board);
        return 0;
    }
    
    //get words to find from the user
    int numOfWordsToSearch = 0;
    char** arrWordsToSearch = (char**) malloc(squareSize*WORDS_LIMIT_PER_ROW_LENGTH*sizeof(char*));
    printf("\n**** ENTER WORDS TO SEARCH. ****\n");
    readSearchedWords(arrWordsToSearch, squareSize, &numOfWordsToSearch, &INPUT_OK);
    if(!INPUT_OK){
        for(int i = 0; i<squareSize; i++){
            free(board[i]);
        }
        free(board);
        for(int i = 0; i<numOfWordsToSearch; i++){ 
            free(arrWordsToSearch[i]);
        }
        free(arrWordsToSearch);
        for(int i = 0; i<SIZE_OF_ALPHABET; i++){
            free( arrLetters[i].mCoordinates );
        }
        free(arrLetters);
        return 0;
    }

    //find words and print results
    int* arrWordsOccurance = (int*) calloc(numOfWordsToSearch, sizeof(int));
    findWords(arrLetters, arrWordsOccurance, board, arrWordsToSearch, numOfWordsToSearch, squareSize);
    printFoundWords(numOfWordsToSearch, arrWordsOccurance, arrWordsToSearch);
    free(arrWordsOccurance);

    // free 
    for(int i = 0; i<squareSize; i++){
        free(board[i]);
    }
    free(board);
    for(int i = 0; i<numOfWordsToSearch; i++){ 
        free(arrWordsToSearch[i]);
    }
    free(arrWordsToSearch);
    for(int i = 0; i<SIZE_OF_ALPHABET; i++){
        free( arrLetters[i].mCoordinates );
    }
    free(arrLetters);

    return 0;
}
