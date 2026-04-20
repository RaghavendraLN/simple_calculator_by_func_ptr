
#include <stdio.h>
#include <stdlib.h>


/*		
 * SIMPLE BASIC CALCULTOR 
 * supports addition,multiplication,
 * substaction and divisions of floats.
 */

#define MAX_OPERATIONS 5
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

float modulo_func(float a, float b)
{
	return ((int)a % (int)b);
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
	puts("     MODULO : ' % ' ");
	puts("----------- | -----");

	puts("Enter Your Operation 'Key'");
	scanf("%c",&key);
	*val_a = atof(arg_a);
	*val_b = atof(arg_b);
	return key;

}

typedef float (*calci_func_ptr)(float, float);

void calci_operation_execute_cb(char key, const char *operation, calci_func_ptr cb_fn, float a, float b)
{
	float result;
	int found = -1, i;

	if(cb_fn == NULL) {
		printf("cb_fn error\n");
		return; 
	}
	result = cb_fn(a, b);
	printf("The %s of (%.2f) %c (%.2f) = %.3f\n",operation, a, key, b, result);
	
}
typedef struct {
	char key;
	const char *name;
	calci_func_ptr cb_fn;
}operation ;

int main(int argc, char **argv)
{
	float a, b; 
	char chosen_key;
	operation ops[MAX_OPERATIONS] = {
		{'+', "sum", sum_func},	
		{'-', "sub", sub_func},	
		{'*', "mul", mult_func},
		{'/', "div", div_func},	
		{'%', "modulo", modulo_func}	
	};

	puts("$$welcome to Basic Calulator$$");
	if(argc != 3) {
		printf("Invalid arguments\nUsage: ./app a b\n");
		return -1;
	}

	chosen_key = calci_info_helper(argv[1], argv[2], &a, &b);
	for( char i = 0; i < MAX_OPERATIONS; i++) {
		if(chosen_key == ops[i].key) {
			calci_operation_execute_cb(ops[i].key, ops[i].name, ops[i].cb_fn, a, b);
		}
	}
	
}
