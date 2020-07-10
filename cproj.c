
#include "q.h"

int main(void) {
	// Initializing queue
	struct queue** myQ = (struct queue**)malloc(sizeof(struct queue*));
	InitQueue(myQ);
	struct queue* temp;

	// Putting items inside the struct queue
	for (int i = 0; i < 10; i++) {
		temp = NewItem();
		temp->payload = i;
		AddQueue(myQ, temp);
	}

	// Printing items inside the struct queue
	printf("Printing items in a queue: \n");
	while (*myQ != NULL) {
		temp = DelQueue(myQ);
		printf("Payload: %d \n", temp->payload);
	}

	// Printing items when the struct queue is empty.
	printf("\nPrinting when the queue is empty: \n");
	temp = DelQueue(myQ); // error message
	printf("Payload: %d \n", temp->payload); // payload should be null

	// Using Rotate queue when its empty.
	printf("\nWhat happens when RotateQ is used when queue is empty:\n");
	RotateQ(myQ); 		// should print error message
	printf("\n");	// newline

	// Putting items inside the struct queue
	for (int i = 0; i < 6; i++) {
		temp = NewItem();
		temp->payload = i;
		AddQueue(myQ, temp);
	}
	// Rotate queue when not empty
	RotateQ(myQ);

	// Printing items inside the struct queue
	printf("Printing after RotateQ with a queue that has elements:\n");
	while (*myQ != NULL) {
		temp = DelQueue(myQ);
		printf("Payload: %d\n", temp->payload);
	}

	// Suggested test case:
	printf("\nSuggested case: ");
	struct queue** Q1 = (struct queue**)malloc(sizeof(struct queue*));
	InitQueue(Q1);
	struct queue** Q2 = (struct queue**)malloc(sizeof(struct queue*));
	InitQueue(Q2);

	for (int i = 1; i <= 3; i++) {
		temp = NewItem();
		temp->payload = i;
		AddQueue(Q1, temp);	//should be 1 -> 2 -> 3

		temp = NewItem();
		temp->payload = i + 3;
		AddQueue(Q2, temp);	//should be 4 -> 5 -> 6
	}

	printf("\n"); // newline

	for (int i = 0; i < 3; i++) { //should print 1 -> 4 -> 2 -> 5 -> 3 -> 6
		temp = DelQueue(Q1);
		printf("Payload Q1: %d \n", temp->payload);
		temp = DelQueue(Q2);
		printf("Payload Q2: %d \n", temp->payload);
	}

}
