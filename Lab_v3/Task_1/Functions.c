#pragma once

#define _CRT_SECURE_NO_WARNINGS


#include"Functions.h"

int forDelay(size_t timer) {
	int temp_1 = 0;
	int temp_2 = 0;
	for (int i = 0; i < 15; i++) {
		temp_1 = i;
		for (int j = 0; j < timer; j++)
			temp_2 = j;
		if(!(i % 5))
			printf(" . ");
	}
	return 0;
}
int returnNumberOfStudents(char* fileName) {

	char buffer[MAX_SIZE] = { '\0' };
	int counter = 0;

	FILE* fp = fopen(fileName, "r");
	if (!fp) {
		printf("Sorry about that can't help you there, since I can't open the file\n");
		forDelay(100000000);
		system("cls");
		return -1;
	}

	while (!feof(fp)) {
		fgets(buffer, MAX_SIZE, fp);
		counter++;
	}
	fclose(fp);

	return counter;
}
Students* dynamicAllocationAndRead(int numberOfStudents, char *fileName) {

	FILE* fp = fopen(fileName, "r");
	Students* students = (Students*)malloc(numberOfStudents * sizeof(Students));

	for(int i = 0; i < numberOfStudents - 1; i++){
		fscanf(fp, " %s %s %d", students[i].name, students[i].surname, &students[i].evaluation);
	}
	fclose(fp);
	return students;
}
int printStudents(int numberOfStudents, Students *scoped) {

	for (int f = 0; f < numberOfStudents - 1; f++) {
		
		printf("Name:\t\t\t%s\nSurname:\t\t%s\nAbsolute_points:\t%02d\nRelative_Points:\t%.2f%%\n", scoped[f].name, scoped[f].surname, scoped[f].evaluation, (((float)scoped[f].evaluation)/100)*100);
		printf("================================================\n");
		if (!(f % 5)) {
			forDelay(100000000);
			printf("\n");
			system("pause");
			system("cls");
			
		}
	}
	return 0;
}
