#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdio.h>
#include "l_list.h"
#include "generate_clues.h"
#include "quiz.h"
#include<time.h>

/*
Student name: Aidas Karpavcius
Student number: R00171054
quiz.c main file
*/
int main(int argc, char *argv[]){
    //creating random seed
    time_t t;
    srand((unsigned) time(&t));
    if (argc < 3){
        //if not enough arguments provided
        //printing out sample run
        printf("Please provide quiz file name, and difficulty level\n");
        printf("Example:\nquiz.exe questions.txt 6\n");
        //returning error and exiting program
        return 1;
    }
    else{
        //converting second argument to int
        int diff = atoi( argv[2]);
        //if its valid difficulty level
        if ( diff > 0 && diff < 7)
            //starting quiz set to that difficulty
            start_quiz( argv[1], diff );
        else{
            //if second argumen was not valid setting to
            //difficulty 1 and starting the quiz
            printf("Invalid difficulty level entered, setting difficulty to 1\n");
            start_quiz( argv[1], 1 ); 
        }
    }
    return 0;
}
//make_record records one line into OUTPUT_FILE
void make_record( char *file_name, char *quiz_name, int score, int amount, int diff){
    //sets file pointer
    FILE *f;
    //opens file for appending
    f = fopen( file_name, "a");
    //outputs formated string to it
    fprintf(f, "File name: %s, Score: %d/%d, Difficulty: %d\n", quiz_name, score, amount, diff);
    //closing file
    fclose(f);
}

//main logic of the quiz
//file_name - qui_questions.txt
void start_quiz( char *file_name, int difficulty){
    //head of linked list with questions
    question_t *quiz_start, *curr_question;
    //amount - amount of question in the file that weren't too long
    //also saving linked list and attaching head quiz_start
    int amount = loadFromFile( &quiz_start, file_name);
    //if there was question
    if ( amount > 0 ){
        printf("Quiz loaded -- %d number of questions detected\n", amount);
    }else{
        //if no questions found game over
        printf("Empty quiz file entered or file does not exist...\nGame Over\n");
        return;
    }
    //order will be used to shuffle questions
    int order[amount], i, score = 0;
    //setting values for order 1 to amount
    for(i=0; i < amount; i++)
        order[i] = i;
    //shuffling order positions
    shuffle(order, amount);
    //user input holder
    char answer[MAX_QUESTION_LENGTH];
    //looping through all the questions
    for(i=0; i < amount; i++){
        //curr_question assigned to match order[i]
        curr_question =  find_entry( quiz_start, order[i]);
        //displaying question and clue
        displayQuestion(curr_question, difficulty);
        //reading user input
        scanf("%s", answer); 
        //if input matches answer, ignoring case
        if( strcasecmp( curr_question->answer, answer )==0){
            //setting question is_correct, i think it was required in spec for assignment 2
            curr_question->is_correct =1;
            //incresing score
            score++;
            printf("Correct\n");
        }
        else{
            //otherwise if answer was wrong
            curr_question->is_correct =0;
            printf("Wrong\n");
        }
        //showing score and amount of total questions
        printf("Score: %d/%d\n", score, amount);
    }
    //game over making a record to the file
    make_record( OUTPUT_FILE, file_name, score, amount, difficulty);
    printf("Would you like to view correct answers for the questions answered incorrectly?(y/n)\n");
    scanf("%s", answer);
    if ( tolower(answer[0])=='y')
        showCorrect(quiz_start);
}

//display a wrongly answered questions in a quiz
void showCorrect( question_t * quiz){
    int question = 0;
    question_t * ques;
    while ( ques = find_entry(quiz, question++)){
        if ( !ques->is_correct){
            printf("Question:\n\t%s\n", ques->question);
            printf("Correct answer:\n\t%s\n", ques->answer);
        }
        if( !ques->pNext)
            break;
    }
}   


//displays a question and the clue
void displayQuestion( question_t * question, int difficulty){
    //prints a question
    printf("%s\n", question->question);
    //if difficulty level 6, sets random difficulty
    if( difficulty == 6 )
        difficulty = rand_int(1,6);
    //swithc calls generating_clue fucntion accordingly to difficulty setting
    switch ( difficulty )
    {
        case 1:
            printf("?\n");
            break;
        case 2:
            letter_count(question->answer);
            printf("\n");
            break;
        case 3:
            first_last(question->answer);
            printf("\n");
            break;
        case 4:
            random2(question->answer);
            printf("\n");
            break;
        case 5:
            shuffle_letters( question->answer);
            printf("\n");
            break;
    }
}
