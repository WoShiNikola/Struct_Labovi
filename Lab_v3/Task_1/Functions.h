#pragma once

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<Windows.h>

#define MAX_SIZE (1024)
#define NAME_LENGTH (255)

typedef struct _studenti {
	char name[NAME_LENGTH];
	char surname[NAME_LENGTH];
	int evaluation;
}Students;

Students* dynamicAllocationAndRead(int numberOfStudents, char* fileName);
int returnNumberOfStudents(char* fileName);
int forDelay(size_t timer);
int printStudents(int numberOfStudents, Students* scoped);

