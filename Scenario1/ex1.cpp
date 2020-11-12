#include <iostream>
#include <cstdlib>
#include "../modules/forum.h"
using namespace std;


int main(){
	
	Forum oop("Object Oriented Programming");
	
	oop.print();
	
	cout << "Selecting 'Rules and useful information'" << endl;
	oop.select("Rules and useful information");
	
	cout << "Selecting 5 random posts with id numbers from 1-30" << endl;
	oop.select(1+rand()%31);
	oop.select(1+rand()%31);
	oop.select(1+rand()%31);
	oop.select(1+rand()%31);
	oop.select(1+rand()%31);
	
}

