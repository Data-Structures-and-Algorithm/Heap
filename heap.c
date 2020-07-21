#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

#define SENTINAL_VALUE 	99999
#define MAX_SIZE		50

void insert(int heap[], int value, int *size);
int delete_root(int heap[], int *size);
void restore_up(int heap[], int i);
void restore_down(int heap[], int i, int size);
void display(int heap[], int size);
void build_heap_top_down(int a[], int size);
void build_heap_bottom_up(int a[], int size);



int main() {

	int choice;

	int size = 0;

	int heap[MAX_SIZE];

	heap[size] = SENTINAL_VALUE;




	int a1[] = {SENTINAL_VALUE, 20, 33, 15, 6, 40, 60, 45, 16, 75, 10, 80, 12};
	int a2[] = {SENTINAL_VALUE, 20, 33, 15, 6, 40, 60, 45, 16, 75, 10, 80, 12};

	int size_a1 = 13 - 1;
	int size_a2 = 13 - 1;

	
	printf("Top Down\n");
	
	build_heap_top_down(a1, size_a1);

	display(a1, size_a1);

	printf("Bottom Up\n");

	build_heap_bottom_up(a2, size_a2);

	display(a2, size_a2);
	


	while(true) {
		printf("1. Insert\n2. Delete Root\n3. Display\n4. Exit\n"
			   "Enter your choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1: {
				int value;
				printf("\nEnter value tobe inserted: ");
				scanf("%d", &value);
				insert(heap, value, &size);
				break;
			}
			case 2: {
				printf("Deleted %d...\n", 
					   delete_root(heap, &size));		
				break;
			}
			case 3:
				display(heap, size);
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("\nInvalid choice\n");
		}
		
		printf("\nPress any key to continue...\n");
		getchar();

		while (getchar() != '\n');
		system("clear");
	}


	printf("\n");
	
	return 0;
}


void insert(int heap[], int value, int *size)
{
	if (*size >= MAX_SIZE - 1) {
		printf("Heap Full...\n");
		return;
	}

	heap[++(*size)] = value;
	restore_up(heap, *size);
}



int delete_root(int heap[], int *size)
{
	if (*size == 0) {
		printf("Empty heap...\n");
		return -1;
	}

	int max_val = heap[1];

	heap[1] = heap[(*size)--];

	restore_down(heap, 1, *size);

	return max_val;
}



void restore_up(int heap[], int i)
{

	int restore_val = heap[i];

	int parent = i / 2;

	/***************************************************
	 *
	 * In case of no sentinal : 
	 *
	 * while (parent >= 1 && heap[parent] < restore_val)
	 * 
	 ****************************************************/

	while (heap[parent] < restore_val) {
			heap[i] = heap[parent];
			i = parent;
			parent = i / 2;
	}

	heap[i] = restore_val;

}



void restore_down(int heap[], int i, int size)
{
	int temp = heap[i];

	int lchild = 2 * i;

	int rchild = lchild + 1;

	while (rchild <= size) {

		if (temp >= heap[lchild] && temp >= heap[rchild]) {
			heap[i] = temp;
			return;
		} else if (heap[lchild] > heap[rchild]) {
			heap[i] = heap[lchild];
			i = lchild;
		} else {
			heap[i] = heap[rchild];
			i = rchild;
		}

		lchild = 2 * i;
		rchild = lchild + 1;
	}


	//If no.of node = odd all nodes are leaf or has 2 children
	//If no.of node = even hen there exist a node without rchild

	if (lchild == size && temp < heap[lchild]) {
		heap[i] = heap[lchild];
		i = lchild;
	}

	heap[i] = temp;
}



void display(int heap[], int size)
{
	

	for (int i = 1; i <= size; i++) {
		printf("%d --> ", heap[i]); 
	}

	printf("\n\n");

}



void build_heap_top_down(int a[], int size)
{
	for (int i = 2; i <= size; i++) {
		restore_up(a, i);
	}
}



void build_heap_bottom_up(int a[], int size)
{
	for (int i = size / 2; i >= 1; i--) {
		restore_down(a, i, size);
	}

}
