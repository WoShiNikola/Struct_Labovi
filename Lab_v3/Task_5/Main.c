#define _CRT_SECURE_NO_WARNINGS

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define MAX_SIZE (128)


struct _express;
typedef struct _express* next;
typedef struct _express {
	int operand;
	next next;
}Expression;



next createList();
int push(next head, int x);
int pop(next head);
int isEmpty(next head);
int printList(next head);
int readFromFile(char* fileName, next head);


int main(int argc, char* argv[]) {

	Expression head = { .operand = 0, .next = NULL };

	printf("Answer is: %d\n", readFromFile("expression.txt", &head));
	if(!isEmpty(&head))
		printf("Is empty\n");

	return 0;
}

next createList() {

	next newList = (next)malloc(sizeof(Expression));

	if (!newList)
		return newList;

	newList->operand = 0;

	newList->next = NULL;

	return newList;
}


int push(next head, int x) {

	next newOne = createList();

	newOne->operand = x;
	newOne->next = head->next;
	head->next = newOne;

	return EXIT_SUCCESS;
}

int printList(next head) {

	next temp = head;

	while (temp) {
		printf("%d ", temp->operand);
		temp = temp->next;
	}

	return EXIT_SUCCESS;
}

int pop(next head) {

	int data = 0;
	next temp = head->next;
	data = temp->operand;
	head->next = head->next->next;
	free(temp);

	return data;
}

int isEmpty(next head) {

	if (!head->next)
		return 0;
	return 1;
}

int readFromFile(char* fileName, next head) {

	FILE* fp = fopen(fileName, "r");

	int temp = 0;

	int minus = 0;

	int counter = 0;

	char buffer[MAX_SIZE] = { '\0' };

	if (!fp)
		return -1;
	
	fgets(buffer, MAX_SIZE, fp);

	char* token = buffer;

	token = strtok(buffer, " ");
	
	while (token) {
		
	
		switch (*token) {
		case '-':
			minus = 0;
			if( (minus = pop(head) - pop(head)) < 0)
				push(head, -minus);
			else	
				push(head, minus);
			break;
		case '+':

			push(head, pop(head) + pop(head));
			
			break;
		case '*':
			if (!counter)
				counter = 1;

			push(head, pop(head) * pop(head));
			break;
		default:
			temp = atoi(token);
			push(head, temp);
			break;
		}
		token = strtok(NULL, " ");
	}

	return pop(head);
}