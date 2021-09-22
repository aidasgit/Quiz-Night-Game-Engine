#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdio.h>
#include "l_list.h"
#include "quiz.h"
#include "generate_clues.h"



/*
Student name: Aidas Karpavicius
Student number: R00171054
l_list.h
contains definition for linked list.
*/


//loadFromFile load all question and answers from the file
//if file is empty or non existing, returns 0
int loadFromFile( question_t **ppList, char * nameOfFile)
{
    //line - current line from file to be proccessed
    //valid_quesions - number of questions that does not exeed MAX_QUESTION_LENGTH 
    int line = 0, valid_questions=0;
    //pItem pointer to current question_t struct
    //also allocating space for it
    question_t * pItem = (question_t*) malloc( sizeof(question_t));
    //attaching head of linked list to that location 
    *ppList = pItem;
    //Cycle while there is more lines, readLine - description bellow
    while(readLine(nameOfFile, line++, pItem -> question, pItem -> answer)){
        //if quesion was valid 
        if(pItem->question[0]){
            valid_questions++;
            //allocating space for next question answer pair and other 2 stuct variables
            pItem -> pNext = (question_t*) malloc( sizeof(question_t));
            //setting current question_t to pNext
            pItem = pItem -> pNext;
        }
    }
    //last items pNext sets to NULL
    pItem->pNext = NULL;
    //returning valid question number inside file
    return valid_questions;
}

//readLine reads one line (line_num - number of the line that you want to read)
//from a file (file_name) and if question is not too long returning empty values for question and answer
//saves question to question and saves answer to answer
int readLine(char *file_name, int line_num, char *question, char *answer){
    //pointer to file
    FILE *f;
    // starting pointer for question and answer incase its too long
    char *ques, *ans;
    ques = question;
    ans = answer;
    //opening file for reading
    f = fopen( file_name, "r");
    //c - current char, line current line, done - flag when question is done being red
    //empty - flag if file is empty or not
    int c, line = 0, done = 1, empty = 0;
    //if file is empty exit
    if (!f)
        return 0;
    //reading one char at the time form the file until EOF
    while((c = getc(f)) != EOF){
        //if line matches the line of intrest 
        //and still question thats being red
        //and question is not longer then max lenght
        if ( line == line_num && done && (question - ques < MAX_QUESTION_LENGTH )){
            //setting empty to not empty because there is a question
            empty = 1;
            //if quesiton mark is being read set flag
            if ( c == '?')
                done = 0;
            //add '?' as a last char
            *question++ = c;
        //if line is the one that is to be red
        //and question is done
        //and we skipping ' ' after '?'
        }else if( line == line_num && !done && c !=' ')
            //writing answer to answer
            *answer++ = c;
        //counting lines
        if ( c == '\n')
            line++;
        //if we red pass the line of intrest we stop looping
        if ( line > line_num)
            break;
    }
    //closing file
    fclose(f);
    //if question was too long
    if (done){
        //deleting garbage
        question = ques; 
        answer = ans;
        *answer = '\0';
        *question = '\0';
    }
    //making question proper string
    *question = '\0';
    //same for answer exept getting rid of '\n'
    *(--answer) = '\0'; 
    //returning epmty as 1 if there was questions in a file
    return empty;
}
        
//find_enty - find entry in a linked list
question_t * find_entry( question_t * lList, int number){
    //while there is next structure and number is not equal to 0
    //reduce number by 1
    while( lList->pNext && number-- )
        //lList pointer being set to the one ahead
        lList = lList->pNext;
    //returning last question_t
    return lList; 
}
