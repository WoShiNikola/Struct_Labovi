#define _CRT_SECURE_NO_WARNINGS


#include"Functions.h"



int main() {

	Students* students = dynamicAllocationAndRead(returnNumberOfStudents("Milf_List.txt"), "Milf_List.txt");
	printStudents(returnNumberOfStudents("Milf_List.txt"), students);
	return 0;
}