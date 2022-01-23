#ifndef SEARCHING_FUNCTIONS_C
#define SEARCHING_FUNCTIONS_C

#include <stdlib.h>
#include <string.h>
#include "structures.h"

int searchHorizontallyRight(char* wordToFind, char** board, Coordinates coordinates, int squareSize){
    int len = strlen(wordToFind) -1;
    if(len + coordinates.mY > squareSize - 1) return 0;
    for(int i = 0; i<=len; i++){
        if(board[coordinates.mX][i + coordinates.mY] != wordToFind[i]) return 0;
    }
    return 1;
}

int searchHorizontallyLeft(char* wordToFind, char** board, Coordinates coordinates, int squareSize){
    int len = strlen(wordToFind) -1;
    if (len == 0 && board[coordinates.mX][coordinates.mY] == wordToFind[len]) return 1;
    if(0 > coordinates.mY - len) return 0;
    for(int i = 0; i<=len; i++){
        if(board[coordinates.mX][coordinates.mY - i] != wordToFind[i]){
            return 0;
        } 
    }
    return 1;
}

int searchVerticallyUp(char* wordToFind, char** board, Coordinates coordinates, int squareSize){
    int len = strlen(wordToFind) -1;
    if(0 > coordinates.mX - len) return 0;
    for(int i = 0; i<=len; i++){
        if(board[coordinates.mX - i][coordinates.mY] != wordToFind[i]){
            return 0;
        } 
    }
    return 1;
}

int searchVerticallyDown(char* wordToFind, char** board, Coordinates coordinates, int squareSize){
    int len = strlen(wordToFind) -1;
    if(len > squareSize - 1 - coordinates.mX) return 0;
    for(int i = 0; i<=len; i++){
        if(board[coordinates.mX + i][coordinates.mY] != wordToFind[i]){
            return 0;
        } 
    }
    return 1;
}

int search1QuadrantUp(char* wordToFind, char** board, Coordinates coordinates, int squareSize){
    int len = strlen(wordToFind) -1;
    if(len + coordinates.mY > squareSize - 1 || coordinates.mX - len < 0 ) return 0;
    for(int i = 0; i<=len; i++){
        if(board[coordinates.mX - i][coordinates.mY + i] != wordToFind[i]) return 0;
    }
    return 1;
}

int search1QuadrantDown(char* wordToFind, char** board, Coordinates coordinates, int squareSize){
    int len = strlen(wordToFind) -1;
    if(0 > coordinates.mY - len || coordinates.mX + len > squareSize - 1) return 0;
    for(int i = 0; i<=len; i++){
        if(board[coordinates.mX + i][coordinates.mY - i] != wordToFind[i]) return 0;
    }
    return 1;
}

int search2QuadrantUp(char* wordToFind, char** board, Coordinates coordinates, int squareSize){
    int len = strlen(wordToFind) -1;
    if(0 > coordinates.mY - len || coordinates.mX - len < 0) return 0;
    for(int i = 0; i<=len; i++){
        if(board[coordinates.mX - i][coordinates.mY - i] != wordToFind[i]) return 0;
    }
    return 1;
}

int search2QuadrantDown(char* wordToFind, char** board, Coordinates coordinates, int squareSize){
    int len = strlen(wordToFind) -1;
    if(len + coordinates.mY > squareSize || coordinates.mX + len > squareSize - 1) return 0;
    for(int i = 0; i<=len; i++){
        if(board[coordinates.mX + i][coordinates.mY + i] != wordToFind[i]) return 0;
    }
    return 1;
}

int getCountWordInBoard(char* wordToFind, char** board, Coordinates coordinates, int squareSize){
    int isHorizontallyRight = searchHorizontallyRight(wordToFind, board, coordinates, squareSize);
    if(strlen(wordToFind) == 1) return 1;
    int isHorizontallyLeft = searchHorizontallyLeft(wordToFind, board, coordinates, squareSize);
    int isVerticallyUp = searchVerticallyUp(wordToFind, board, coordinates, squareSize);
    int isVerticallyDown = searchVerticallyDown(wordToFind, board, coordinates, squareSize);
    int is1QuadrantDown = search1QuadrantDown(wordToFind, board, coordinates, squareSize);
    int is1QuadrantUp = search1QuadrantUp(wordToFind, board, coordinates, squareSize);
    int is2QuadrantDown = search2QuadrantDown(wordToFind, board, coordinates, squareSize);
    int is2QuadrantUp = search2QuadrantUp(wordToFind, board, coordinates, squareSize);

    return 
    isHorizontallyLeft
    + isHorizontallyRight
    + isVerticallyUp
    + isVerticallyDown
    + is1QuadrantUp
    + is1QuadrantDown
    + is2QuadrantUp
    + is2QuadrantDown;
}

void findWords(Letter* arrInput,int* arrWordsOccurance, char** board, char** arrWordsToSearch, int numOfWordsToSearch, int squareSize){
    
    for(int i = 0 ; i<numOfWordsToSearch; i++){
        char firstLetter = arrWordsToSearch[i][0];
        int index = firstLetter - 'A';
        for(int j = 0; j<arrInput[index].mLetterOccurance; j++){ 
            arrWordsOccurance[i]+=getCountWordInBoard(arrWordsToSearch[i], board, arrInput[index].mCoordinates[j],squareSize);      
        }
    }
}

#endif