/*
Student name: Aidas Karpavicius
Student number: R00171054
l_list.h
contains declarations for linked list.
*/
//Stucture for single quiz question
#ifndef LINKED_LIST
	#define LINKED_LIST
	#define OUTPUT_FILE "quiz_history.txt"
	#define MAX_QUESTION_LENGTH 50
	struct quiz_question
	{
	    char question[MAX_QUESTION_LENGTH + 1 ];
	    char answer[MAX_QUESTION_LENGTH + 1];
	    int is_correct;
	    struct quiz_question* pNext;
	};

	typedef struct quiz_question question_t;


	int readLine(char *file_name, int line_no, char* question, char * answer);
	int loadFromFile( question_t **ppList, char * nameOfFile);
	question_t * find_entry( question_t * lList, int number);
#endif
