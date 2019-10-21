/* Project 2 main
*
*	Do not submit this file
*
*/

// MS VS does not like cstring functions, this is to tell it to chill out.
#ifdef _MSC_VER  //  Microsoft Visual C++

#define _CRT_SECURE_NO_DEPRECATE

#else  // not Microsoft Visual C++, so assume UNIX interface

#endif



/* Main functions
*
*	you may make any changes you want to main to test your functions.
*	We will be using our own to grade.
*
*	I'm using preprocessor directives to layout different mains to test
*	various functions.  I have 5 example mains.  You can add or replace, 
*	these are here just to illustrate the technique. Cleaner than 
*	commenting/uncommenting blocks of code.
*
*/

// Choose which run to compile
#define RUN0 //RUN1 RUN2 RUN3 RUN4


#ifdef RUN0 

// Make sure you understand and tools being used prior to building anything with them.  
// In this case, the functions to manipulate cstrings will be part of your tool set.  

// It is also important to get in the habit of being able to think/implement/test incrementally.
// Break up your tasks into smaller componenets and test as much as possible.  You can think of
// this as a universal law of programming: "The number of bugs grows exponentially with amount of 
// code typed between testing." 

#include"studentinfo.h"

#include<iostream>
using std::cout;
using std::endl;

#include<cstring>
using std::strcat;
using std::strcmp;
using std::strcpy;
using std::strlen;

int main() {
	//** Setup initial state 

	cout << StudentInfo::name() << endl;
	cout << StudentInfo::id() << endl;

	int max = 5, // Keep track of the max number words	
		num = 0; // Number of words we can currently store
	//Allocate rows, to point to words
	char ** testlist = new char*[max];
	// for each row, allocate space for words
	for (int i = 0; i < max; i++) {
		testlist[i] = new char[20];
	}
	
	// Initialize words
	strcpy(testlist[0], "harry");
	strcpy(testlist[1], "ron");
	strcpy(testlist[2], "hermione");
	num = 3;	// Must be consistent with intended state, 
				// e.g. there are three currently three words.

	//*** Begin code for function
	 
	//STEP 1  of Algorithm
	//...

	//Test STEP 1
	//...

	//STEP 2 of Algorithm
	//...

	//Test STEP 2
	//...

	return 0;
}

#elif defined RUN1  //Test constructor 


#define MAKE_MEMBERS_PUBLIC // This constant will be checked in worlist.h

#include"wordlist.h"
#include<iostream>

#include<assert.h>
using std::cout;
using std::endl;

int main() {

	WordList wordlist(5);

	// Assuming we made our member variables public:
	cout << "Count: " << wordlist.m_count << endl; // Expect 0

	cout << "Capacity: " << wordlist.m_max_words << endl; // Expect 5


	return 0;
} 
#elif defined RUN2 


#define MAKE_MEMBERS_PUBLIC
#include"wordlist.h"


#include<assert.h>



// Same as above but using asserts instead of cout
//
// asserts are a way to check conditions, they will gracefully crash
// the program if the condition is not met.  
//
// This assumes you know what the end state after the function call
// should be.  Effective programmers have in mind test cases prior to 
// implmentation.  You should know what the end state should be after
// any function call.
int main() {
	WordList *wordlist = new WordList(5);

	// Assuming we made our member variables public:
	// If we failed to set our member variables correctly 
	// These assertions will fail
	assert(wordlist->m_count == 0);
	assert(wordlist->m_max_words == 5);
	

	return 0;
}
#elif defined RUN3


#define MAKE_MEMBERS_PUBLIC
#include"wordlist.h"
#include<iostream>
using std::cout;
using std::endl;

// Test addWord: Both Constructor and addWord must be
// implmented prior to running this code, otherwise
// it will crash.
int main() {
	WordList *wordlist = new WordList(5);
	wordlist->addWord("harry");
	wordlist->addWord("ron");
	wordlist->addWord("hermione");

	// Assuming we made our member variables public:
	cout  << wordlist->m_list[0][2] << endl; // Expect 'r'

	cout  << wordlist->m_list[1] << endl; // Expect "ron"

	return 0;
}

#elif defined RUN4

#define MAKE_MEMBERS_PUBLIC
#include"wordlist.h"
#include<assert.h>
#include<cstring>

using std::strcmp;
// Test addWord: same as RUN3 but with asserts. Both Constructor and addWord 
// must be implmented prior to running this code, otherwise it will crash.
int main() {

	WordList *wordlist = new WordList(5);
	wordlist->addWord("harry");
	wordlist->addWord("ron");
	wordlist->addWord("hermione");
	
	// Assuming we made our member variables public:
	assert(wordlist->m_list[0][2] == 'r' ); // Individual character, can use == 

	assert(strcmp(wordlist->m_list[1], "ron") == 0); // cstring, must use strcmp
	
	return 0;
}
#else


//#define MAKE_MEMBERS_PUBLIC
#include"wordlist.h"

// Test: printList(): Constructor, addWord, printList must be implmented prior to 
// running this code, otherwise it will crash.
int main() {

	WordList *wordlist = new WordList(5);
	wordlist->addWord("harry");
	wordlist->addWord("ron");
	wordlist->addWord("hermione");

	wordlist->printList();

	return 0;
}

#endif