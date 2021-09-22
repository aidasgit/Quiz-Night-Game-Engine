/*
Student name: Aidas Karpavcius
Student number: R00171054
quiz.h declaring 
all functions for implementing quiz game
*/
//declrarations
#ifndef QUIZ
	#define QUIZ

	void displayQuestion( question_t * question, int difficulty);
	void start_quiz( char *file_name, int difficulty);
	void make_record( char *file_name, char *quiz_name, int score, int amount, int diff);
	void showCorrect( question_t *);
#endif

