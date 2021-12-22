#include"Functions.h"

int main(int argc, char* argv[]) {

	Students head = { .name = '\0', .surname = '\0', .year_of_birth = 0, .next = NULL };

	addToList(&head);
	addToList(&head);
	addToList(&head);

	////addAfter(&head, "Jack");
	////addBefore(&head, "Jack");
	
	addToEnd(&head);

	printList(head.next);
	printf("========================================\n");

	sortList(head.next);

	printList(head.next);
	
	//findItem(head.next, "Jack");
	//eraseElement(&head, "Jack");
	//printList(head.next);

	return 0;
}