#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "binaryTree.h"
using namespace std;

int Post::ID_COUNTER = 1; //set the 1st value of the static ID_COUNTER

string EXPRESSIONS[10] = { //posts picked randomly from stack overflow
"Is there a clearcase command that do that ?",
"Or should I use psexec or something similar that will run the command on each machine ?",
"On the above example B, C and D are all children of A?",
"From A's perspective there is no difference between B, C and D?",
"From the components' perspective Country is a grand grand child of Travel.",
"All components that lie inside return of component A are children of A even if there is nested structure?",
"How can we set the googlesheets package to use the initial googleAuthR credentials as well?",
"Can you try using service account token instead for authentication?",
"I have read that a press and release action can change halfway because it becomes a swipe action. But how do I detect this so I can cancel the action I started by the Pressed event?",
"I also tried adding positions: undefined, however none of the above changes had any affect on the node positioning. How can I achive this with fCose?",
};

string USERNAMES[10] = {   //random usernames
"user001234",
"user001235",
"user001236",
"user001237",
"user001238",
"user001239",
"user001240",
"user001241",
"user001242",
"user001243",
};

string TITLES[10] = {    //post titles randomly picked from reddit
	"Algorithm for Tower of Hanoi",
	"Recursion Time Complexity",
	"Exercise help",
	"Quick Sort (best/worst)",
	"Kattis Classrooms",
	"Graph marking with lives",
	"O(1) integer search",
	"SELECT Algorithm Recurrence Relation",
	"Binary search-like algorithm",
	"Grid Math Question"
};

string SUBJECTS[10] = {      //random thread subjects
	"Excercise 1",
	"Excercise 2",
	"Excercise 3",
	"Excercise 4",
	"Lab 1",
	"Lab 2",
	"Lab 3",
	"Exam 1",
	"Exam 2",
	"Exam 3",
};

void printTime(date curDate){   //arbitrary function to print time in the proper format
	cout << curDate.day << "/" << curDate.month << "/" 
	<< curDate.year << " " << curDate.hour << ":";
	if (curDate.min < 10) cout << 0; //print 12:05 instead of 12:5
	cout << curDate.min;
}


//default values of the constructor are random
Post::Post(string t = TITLES[rand()%10], string a = USERNAMES[rand()%10], string txt = EXPRESSIONS[rand()%10])    //constructor with arguments title,author,text
	: title(t),author(a),text(txt),id(ID_COUNTER++)
{

	time_t curTime = time(NULL);   //get current time
	creation_date.day = localtime(&curTime)->tm_mday;   
	creation_date.month = 1 + localtime(&curTime)->tm_mon;
	creation_date.year = 1900 + localtime(&curTime)->tm_year;
	creation_date.hour = localtime(&curTime)->tm_hour;
	creation_date.min = localtime(&curTime)->tm_min;
	
	cout << "Post with title '" << title << "' and id "<< id 
	<< " was created by " << author << " at "; 
	printTime(creation_date); 
	cout << endl;
}

Post::~Post(){
	if (id!=0) cout << "Post number " << id << " is about to be destroyed." << endl;  //id 0 means empty post so don't print anything
}


int Post::get_id() { return id; }

string Post::get_author() { return author; }

void Post::print(){
	cout << "Title: " << title << endl;
	cout << "ID: " << id << endl;
	cout << "Author: " << author << endl;
	cout << "Creation date: " ; printTime(creation_date) ; cout << endl;
	cout << "Content: " << text << endl << endl;
}

Thread::Thread()   //default constructor used to initialize Thread array of class 'Forum'
	:author(USERNAMES[rand()%10]),subject(SUBJECTS[rand()%10])
{  
	time_t curTime = time(NULL);   //get current time and assign to creation_date data member
	creation_date.day = localtime(&curTime)->tm_mday;   
	creation_date.month = 1 + localtime(&curTime)->tm_mon;
	creation_date.year = 1900 + localtime(&curTime)->tm_year;
	creation_date.hour = localtime(&curTime)->tm_hour;
	creation_date.min = localtime(&curTime)->tm_min;
	
	cout << "Thread with subject '" << subject << "' has just been created." << endl;
}


Thread::Thread(string s, string a)
	: author(a),subject(s)
{
	time_t curTime = time(NULL);   //get current time and assign to creation_date data member
	creation_date.day = localtime(&curTime)->tm_mday;   
	creation_date.month = 1 + localtime(&curTime)->tm_mon;
	creation_date.year = 1900 + localtime(&curTime)->tm_year;
	creation_date.hour = localtime(&curTime)->tm_hour;
	creation_date.min = localtime(&curTime)->tm_min;
	
	
	cout << "Thread with subject '" << subject << "' has just been created." << endl;
}

Thread::~Thread(){
	if (subject != "") cout << "Thread with subject '" << subject << "' is about to be destroyed." << endl;    //empty subject means empty thread so don't print anything 
}


void Thread::print(){
	cout << "Subject: " << subject << endl;
	cout << "Author: " << author << endl;
	cout << "Creation date: "; printTime(creation_date); cout << endl;
	cout <<"Posts"<< "--------------------------------------" << endl;
	for (int i=0;i<5;i++){  //5 posts per thread
		posts[i].print();
	}
	cout << "--------------------------------------------" << endl;
}

string Thread::get_subject() { return subject; }

Post* Thread::getPosts() { return posts; }

Forum::Forum(string t)
	:title(t)
{
	cout << "Forum with title '" << title << "' has just been created." << endl;
}

Forum::~Forum(){
	cout << "Forum with title '" << title << "' is about to be destroyed." << endl;
}

void Forum::print(){
	cout << "-------------------------------------------------" << endl;
	cout << "Forum '" << title << "' contains the following threads: "<< endl;
	for(int i=0; i<5; i++){  //5 threads per forum
		cout << threads[i].get_subject() << endl;
	}
	cout << "-------------------------------------------------" << endl;
}

void Forum::select(string subject){
	for (int i=0; i<5;i++){   //serial search for thread subject in forum thread list
		if(threads[i].get_subject() == subject) {   //if it is found
			threads[i].print();     //print the thread
			return;   //end the search
		}
	}
	cout << "Thread with subject '" << subject << "' not found in forum '" << title << "'" << endl;    //if thread subject not found in forum thread list
}

void Forum::select(int post_id){
	for (int i=0;i<5;i++){  //for every thread in the forum (5 threads)
		Post *pposts = threads[i].getPosts();   //pointer to posts[] array of current thread
		for (int j=0; j<5; j++){  //for every post in the thread (5 posts)
			if (pposts[j].get_id()==post_id){ 
				pposts[j].print();  //if the post is found print it and exit
				return;
			}
		}
	}
	cout << "Post with id " << post_id << " not found in forum '" << title << "'" << endl;
}

#ifdef USE_BT   
//this function is only used in excercise2
//excercise1 does not require including binary trees

void Forum::print_sorted(){
	BinaryTree *bst[5];
	for (int i=0; i<5; i++) bst[i] = new BinaryTree(threads[i]); //create a binary tree for each thread
	for (int i=1; i<5; i++) bst[0]->enhance(*bst[i]);  //add every tree to the first tree
	bst[0]->printInOrder();
	for (int i=0; i<5; i++) delete bst[i];  //delete every tree
}

#endif

