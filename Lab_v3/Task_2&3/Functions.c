#pragma once

#include"Functions.h"

Students* createStudent() {

	Students* newStudent = (Students*)malloc(sizeof(Students));
	
	if(!newStudent){
		printf("Didnt't allocate memory for that sorry amigo\n");
		return newStudent;
	}

	printf("Enter your name please: \n");
	scanf(" %s", newStudent->name);
	printf("Enter your surname please: \n");
	scanf(" %s", newStudent->surname);
	printf("Enter year of birth: \n");
	scanf(" %d", &newStudent->year_of_birth);
	system("cls");
	newStudent->next = NULL;

	return newStudent;
}

int addToList(Students* first) {

	Students* Student = createStudent();

	if (!Student) {
		printf("Whoopsie didn't create shit\n");
		return EXIT_FAILURE;
	}

	Student->next = first->next;
	first->next = Student;
	return EXIT_SUCCESS;
}

int printList(Students* firstItem) {

	Students* temp = firstItem;
	if (!temp) {
		printf("Empty List bruh\n");
		return EXIT_SUCCESS;
	}
	while (temp) {

		printf("Name:\t\t%s\nSurname:\t%s\nYear of birth:\t%d\n", temp->name, temp->surname, temp->year_of_birth);
		printf("-------------------------------\n");
		temp = temp->next;
	}
	free(temp);
	return EXIT_SUCCESS;
}

int addToEnd(Students* first) {

	Students* temp = first;
	while (temp->next)
		temp = temp->next;

	addToList(temp);

	return EXIT_SUCCESS;
}

Students* findItem(Students* first, char* surname) {

	Students* temp = first;
	if (!temp) {
		printf("Empty_List_Cunt\n");
		return temp;
	}

	

	while (temp && (strcmp(surname, temp->surname) != 0)) {
		temp = temp->next;
	}
	if (!temp) {
		printf("Couldn't find that person my man\n");
		return temp;
	}
	return temp;
}

int eraseElement(Students* first, char* target) {

	Students* q = first;
	Students* p = first;

	while (q->next && strcmp(q->name, target) != 0) {
		p = q;
		q = q->next;
	}
	if (!q->next){ 
		printf("Didn't find it sorry\n");
		return EXIT_SUCCESS;
	}
	p->next = q->next;
	free(q);

	return EXIT_SUCCESS;
}

//Lab_3_Addition

int addAfter(Students* first, char* target) {

	Students* temp = NULL;
	temp = findItem(first, target);

	addToList(temp);

	return EXIT_SUCCESS;
} 

// Maybe if I send the Students* target instead of char* target then call addAfter the findItem(target.next) it will yield me the result
// swapping nodes or swapping data?

int addBefore(Students* first, char* surname) {

	Students* temp = first;
	while (temp && strcmp(temp->next->surname,surname) != 0) {
		temp = temp->next;
	}
	if (!temp) {
		printf("Can't addBefore\n");
		return EXIT_FAILURE;
	}

	addToList(temp);
	
	return EXIT_SUCCESS;
}

int sortList(Students* first) {

	Students* curr = first;
	Students* prev = NULL;
	char tempBuff[MAX_SIZE] = { '\0' };
	int tmp = 0;

	//Students* temp = NULL;
	int swapped = 0;

	do {
		curr = first;
		swapped = 0;
		
		while (curr->next != prev) {
			if (strcmp(curr->surname, curr->next->surname) > 0) {

				strcpy(tempBuff, curr->next->name);
				strcpy(curr->next->name, curr->name);
				strcpy(curr->name, tempBuff);

				strcpy(tempBuff, curr->next->surname);
				strcpy(curr->next->surname, curr->surname);
				strcpy(curr->surname, tempBuff);

				tmp = curr->next->year_of_birth;
				curr->next->year_of_birth = curr->year_of_birth;
				curr->year_of_birth = tmp;

				swapped = 1;
			}
			curr = curr->next;
		}

		prev = curr;

	} while (swapped);

	return EXIT_SUCCESS;
}

int printIntoFile(char* fileName, Students* first) {

	return 0;
}