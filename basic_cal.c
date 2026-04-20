#include <stdio.h>
#include <stdlib.h>

#define MAX_OPERATIONS 4

float sum_func(float a, float b)
{
	return (a+b);
}

float sub_func(float a, float b)
{
	return (a-b);
}

float mult_func(float a, float b) 
{
	return (a*b);
}

float div_func(float a, float b)
{
	return (a/b);
}
char calci_info_helper(char *arg_a, char *arg_b, float *val_a, float *val_b)
{
	char key;
	puts("The supoorted operations are");
	puts("-------------------");
	puts("  Operation : 'Key'");
	puts("----------- | -----");
	puts("	SUM : ' + ' ");puts("	SUB : ' - ' ");
	puts("	MUL : ' * ' ");puts("	DIV : ' / ' ");
	puts("----------- | -----");

	puts("Enter Your Operation 'Key'");
	scanf("%c",&key);
	*val_a = atof(arg_a);
	*val_b = atof(arg_b);
	return key;

}

typedef float (*calci_func_ptr)(float, float);

int main(int argc, char **argv)
{
	float a = 15, b = 5; //default values
	float result;
	char operation;
	calci_func_ptr calci_func_array[MAX_OPERATIONS] = {sum_func, sub_func, mult_func, div_func};
	calci_func_ptr chosen_calci_func;

	puts("$$welcome to Basic Calulator$$");
	if(argc != 3) {
		printf("Invalid arguments\nUsage: ./app a b\n");
		return -1;
	}
	operation = calci_info_helper(argv[1],argv[2], &a, &b);
	switch(operation) {
		case '+':
			chosen_calci_func = calci_func_array[0];
			break;
		case '-':
			chosen_calci_func = calci_func_array[1];
			break;
		case '*':
			chosen_calci_func = calci_func_array[2];
			break;
		case '/':
			chosen_calci_func = calci_func_array[3];
			break;
		default:
			printf(" Invalid operatior: ' %c '\n",operation);
			break;
	}
	result = chosen_calci_func(a,b);
	printf("The result = %.3f\n",result);

}
