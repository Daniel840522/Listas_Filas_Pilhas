#include <stdio.h>
#include <stdlib.h>

#define size 5

struct _row{
	int date[size];
	int start;
	int end;
};

struct _row row;
int op;

void push_back();
void pop();
void show();
void menu();

int main(){
	op = 1;
	row.start = 0;
	row.end = 0; 
	while (op != 0){
		system("cls");
		show();
		menu();
		scanf("%d", &op);
		switch (op){
			case 1:
				push_back();
			break;
			case 2:
				pop();
			break;
		}
	}
	return (0);
}

void push_back(){
	if(row.end == size){
		printf("\nThe row is full!\n\n");
		system("pause");
	}
	else{
		printf("\n Enter the value: ");
		scanf("%d", &row.date[row.end]);
		row.end++;
	}	
}

void pop(){
	if(row.start == row.end){
		printf("\nRow empyt!\n\n");
		system("pause");
	}
	else{
		for (int i = 0; i < size; i++){
			row.date[i] = row.date[i + 1];
		}
		row.date[row.end] = 0;
		row.end--; 
	}
}

void show(){
	printf("[ ");
	for (int i = 0; i < size; i++){
		printf ("%d", row.date[i]);
	}
	printf(" ]\n\n");
}

void menu(){
	printf("\nChoose an option:\n");
	printf("1 - Include a value\n");
	printf("2 - Delete a value\n");
	printf("0 - Exit\n\n");
}
