
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <TCB.h>
#define _GNU_SOURCE

/*struct queue {
	int payload; // The element our queue carries
	struct queue* next;  // Pointer to next queue struct
	struct queue* prev; // Pointer to previous queue struct
};*/

struct TCB_t* h; // Head of the TCB_t

struct TCB_t* NewItem() { // returns a pointer to a new q-element
	struct TCB_t* node = (struct TCB_t*)malloc(sizeof(struct TCB_t));
	return node;
}

void InitQueue(struct TCB_t** head) { // creates an empty TCB_t, pointed to by the variable head.
	h = NewItem();
	h = NULL;
	*head = h;
}

void AddQueue(struct TCB_t** head, struct TCB_t* item) { // adds a TCB_t item, pointed to by “item”, to the TCB_t pointed to by head.
	h = *head;
	if (h == NULL) {
		h = item;
		item->next = h;
		item->prev = h;
	}
	else {
		struct TCB_t* temp = NewItem();
		temp = h;
		while (temp->next != h) {
			temp = temp->next;
		}
		temp->next = item;			// temp is the second to last element, item is the last element now
		temp->next->prev = temp;	// item's previous is temp
		h->prev = temp->next;		// head's previous is item.
		temp->next->next = h;		// item's next is head.
	}
	*head = h;
}

struct TCB_t* DelQueue(struct TCB_t** head) { // deletes an item from head and returns a pointer to the deleted item. If this is the last element…
	struct TCB_t* temp = NewItem();
	h = *head;
	if (h == NULL) {
		printf("TCB_t is empty. Can not remove anything.\n");
	}
	else if (h->next == h) {
		temp = h;
		h->next = NULL;
		h->prev = NULL;
		h = NULL;
	}
	else {
		temp = h;
		h->prev->next = h->next;
		h->next->prev = h->prev;
		h = h->next;
	}
	*head = h;
	return temp;
}

void RotateQ(struct TCB_t** head) { // Moves the header pointer to the next element in the TCB_t.
	struct TCB_t* tail = NewItem();
	h = *head;
	if (h == NULL) {
		printf("TCB_t is empty. Cannot rotate.\n");
	}
	else {
		h = h->next;
	}
	*head = h;
}
