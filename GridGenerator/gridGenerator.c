#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#define SIZE_OF_ALPHABET 26


char** generateRandomGrid(int gridSize){

    char* letters = (char*) malloc(SIZE_OF_ALPHABET*sizeof(char));
    char** grid = (char**) malloc(gridSize*sizeof(char*));
    for(int i = 0; i<gridSize; i++){
        grid[i] = (char*) malloc(gridSize*sizeof(char));
    }   
    
    char letter = 'A';
    for(int i = 0; letter <= 'Z'; letter++, i++){
        letters[i] = letter;
    }

    srand(time(NULL));
    int index;
    for(int i = 0; i<gridSize; i++){
        for(int j = 0; j<gridSize; j++){
            index = rand() % SIZE_OF_ALPHABET;
            grid[i][j] = letters[index];
        }
    }

    return grid;
}


int main(int argc, char* argv[]){

    if(argc == 1){
        printf("Enter parameters :  [gridSize] [words to search] \n");
        return 0;
    }

    for(int i = 0; i < strlen(argv[1]); i++){
        if(!isdigit(argv[1][i])){
            printf("Enter size of grid as the first parameter!\n");
            return 0;
        }
    }
    

    int gridSize = atoi(argv[1]);
    
    //print into a file
    FILE* file = fopen("GRID.txt", "w");
    char** grid = generateRandomGrid(gridSize);
    for(int i = 0; i<gridSize; i++){
        fprintf(file, "%s\n", grid[i]);
    }

    
    for(int i = 2; i < argc; i++){
        fprintf(file, "%s\n", argv[i]);
    }

    fclose(file);

    return 0;
}