#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<Windows.h>

#define MAX_SIZE (255)

typedef struct _students {
	char name[MAX_SIZE];
	char surname[MAX_SIZE];
	int year_of_birth;
	struct _students* next;
}Students;

Students* createStudent();
int addToList(Students* first);
int printList(Students* firstItem);
int addToEnd(Students* first);
Students* findItem(Students* first, char* surname);
int eraseElement(Students* first, char* target);

//Lab_3_Addition

int addAfter(Students* first, char* target);
int addBefore(Students* first, char* surname);
int sortList(Students* first);
int printIntoFile(char* fileName, Students* first);
