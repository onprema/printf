#include <stdio.h>
#include "holberton.h"

int main(void)
{
	char c = '9';
	char *s = "Linds";
	char *name = "Lee";
	int n;
	int x;

	n = 5;
	_printf("%d\n", n);
	x = _printf("Hi %s, my name is %s.\nChar: %c\nPercent: %%\n", s, name, c);
	printf("count (echo $?) = %d\n", x);
	return (x);
}
