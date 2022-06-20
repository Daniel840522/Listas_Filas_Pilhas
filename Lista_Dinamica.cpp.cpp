#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct no {
	int date;
	struct no *next;
};

typedef no *ptr_no;
ptr_no stack;
int op;

void menu();
void select(int op);
void push(ptr_no stack);
void pop(ptr_no stack);
void show(ptr_no stack);

int main(){
	
	srand(time(NULL));
	op = 1;
	stack = (ptr_no) malloc(sizeof(no));
	stack->date = 0;
	stack->next = NULL;
	while (op != 0){
		system("cls");
		menu();
		scanf("%d", &op);
		select(op);
	}
	system("Pause");
	return(0);
}
void menu(){
	show(stack);
	printf("\n\nChoose an option:\n");
	printf("1 - Insert a value:\n");
	printf("2 - Delete a value:\n");
	printf("0 - Exit\n\n");
}
void select (int op){
	switch(op){
		case 1:
			push(stack);
		break;
		case 2:
			pop(stack);
		break;
	}
}
void push(ptr_no stack){
	while(stack->next != NULL){
		stack = stack->next;
	}
	stack->next = (ptr_no) malloc(sizeof(no));
	stack = stack->next;
	stack->date = rand()%100;
	stack->next = NULL;
}
void pop(ptr_no stack){
	int date;
	ptr_no curret;
	curret = (ptr_no) malloc(sizeof(no));
	printf("\nChoose an value:\n");
	scanf("%d", &date);
	while((stack->date != date)){
		if (stack->next == NULL){
			break;
		}
		curret = stack;
		stack = stack->next;
	}
	if (stack->date == date){
		curret->next = stack->next;
	}
}
void show(ptr_no stack){
	system("cls");
	while(1) {
		printf("%d, ", stack->date);
		if (stack->next == NULL){
			break;
		}
		stack = stack->next;
	}
}
void show_2(ptr_no stack){
	system("cls");
	while(stack->next != NULL){
		printf("%d, ", stack->date);
		stack = stack->next;
	}
	printf("%d, ", stack->date);
}


