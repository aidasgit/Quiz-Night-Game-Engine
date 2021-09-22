/*
Student name: Aidas Karpavcius
Student number: R00171054
generate_clues.h 
stores functions declarations that makes a clue from valid sting.
*/
//declrarations
#ifndef GENERATOR
	#define GENERATOR
	int rand_int(int min, int max);
	void swap( int *, int *);
	void first_last( char * input);
	void random2( char * input);
	void shuffle_letters( char * input);
	void shuffle( int* arr, int size);
	void letter_count( char * input);
#endif
