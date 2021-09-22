#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdio.h>
#include "l_list.h"
#include "quiz.h"
#include "generate_clues.h"


/*
Student name: Aidas Karpavcius
Student number: R00171054
generate_clues.c
stores functions declarations that makes a clue from valid sting.
*/

//shuffle_letters - mixes letters randomly in char array
void shuffle_letters( char *input ){
    //len - length of the char array
    int len = strlen( input );
    //creating array for positions same lenght
    int positions[len], i;
    //setting values 1..len in positions
    for (i = 0; i < len; i++)
        positions[i] = i;
    //calling function to shuffle on positions
    shuffle( positions, len);
    //cyling throught 1.. len 
    for (i = 0; i < len; i++){
        //printing out upper char at position[i]
        putchar( toupper(input[ positions[i]]));
        //adding space
        putchar(' ');
    }
}

//reveals 2 chars at random positions
void random2( char * input){
    //saves lenght of the char array
    int len = strlen(input);
    //declares l2 and sets l1 to 1..len random
    int l2, l1 = rand_int( 0, len);
    //while l1 and l2 equal, keep rolling l2
    while ( l1 == ( l2 = rand_int(0, len)));
    //cycle through the *input
    for ( int i = 0; i < len; i++){
        //if current char is in l1 or l2 position
        if ( i == l1 || i == l2)
        //put upper char
            putchar(toupper(input[i]));
        else
        //else underscore
            putchar('_');
        putchar(' ');
    }
}

//prints out 1st and last char of the input
void first_last( char * input ){
    //cycles through input chars
    for(int letter = 0; input[letter]; letter++){
        //if 1st or last
        if ((letter == 0) || !input[letter+1] )
        //put character to std
            putchar(toupper(input[letter]));
        else
            putchar('_');
        putchar(' ');
    }
}


//letter_count output undercores instead of chars
void letter_count( char * input ){
    for(int letter = 0; input[letter]; letter++){
        putchar('_');
        putchar(' ');
    }
}
//returns random in between =>min and <max
int rand_int( int min, int max){
    return min + rand() % ( max - min );
}

//swaps two pointer values
void swap (int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//shuffles positions of the values in the array
void shuffle( int * arr, int size){
    int i;
    //cycles throught the array
    for( i = 0; i < size; i++)
        //and swaps two elements at random in the array
        swap( arr + rand_int(0, size) , arr + rand_int(0, size));
}
