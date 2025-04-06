#ifndef WORDLE_H
#define WORDLE_H

/*------------------------------------------------------------------------------------------------------------------*/
/*Include files*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>
#include <assert.h>
#include <errno.h>
/*------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------*/
/*Macro Definitions*/
/*Maximum available five letter words*/
#define MAX 5172
/*Colour macros*/
#define ResultGreen 1
#define ResultYellow 2
#define ResultRed 4
/*Colour definition macros*/
#define ClrGreen "\033[0;32m"
#define ClrYellow "\033[0;33m"
#define ClrRed "\033[0;31m"
#define ClrStop "\033[0m"
/*Input value validation macros*/
#define Valok 0
#define ValBadInput 1
#define ValNosuchword 2
/*------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------*/
/*Typedefs*/
typedef char ValResult;
typedef char Result;
/*------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------*/
/*Global variables*/
static char words[MAX][5]; // we have 5195 words of 5 letters each
bool continuation;
int rounds;
bool win;
bool corrects[5];
/*------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------*/
/*Function prototypes*/
int main(int, char **);                     /*Main function*/
void seed(void);                            /*Function to generate the seed value for random function*/
int readfile(char *);                       /*Function to access the 5 letters word in the given file and store it in an array*/
char *randomword(int);                      /*Function to get a random 5 letters word from the array*/
char *readline(void);                       /*Function to read the word input from the user(stdin)*/
ValResult validator(char *);                /*Function to validate the user input*/
void gameloop(char *);                      /*Main body of the game which looks after the rules and regulations*/
void prompt(char *);                        /*Function is used to check the user input word with the correct word*/
Result *cw(char *, char *);                 /*Function is used for word checking*/
Result cc(char, int, char *);               /*Function is used for character checking*/
bool isin(char, char *);                    /*Function is used to check if the letter are present in current word but in different position*/
void print_results(char *, char *, char *); /*Function to print the Final Results*/
/*------------------------------------------------------------------------------------------------------------------*/

#endif