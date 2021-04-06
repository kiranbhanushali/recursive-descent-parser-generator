#include "utils.h"
#include<stdio.h>


// finding the terminal 
int isTerminal(char c){
    if( c>='A' && c<='Z') return 0;
    return 1 ;
}


// function for printing messages
void print_message(const char * s){

    printf("Message: %s",s);

}



