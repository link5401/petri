#include <iostream>
#include <string>
#include "petri.h"


int main(int argc, char* argv[]) {
	int init_marking[argc];
	for (int i = 0; i < argc; i++) init_marking[i] = atoi(argv[i]);
	inArc inT1[1]   = { inArc(Place(1) , 1) };
	outArc outT1[1] = { outArc(Place(0), 1) };
	Transition T1(
		inT1
		
		,
		
		outT1
	);
	T1.print();

}