#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	int i;
	int sum = 0;
	printf("ac : %d\n", ac);
	printf("av[] values\n:");

	for(i = 1; i < ac; i++)
	{
		printf("av[%d] = %s\n", i , av[i]);
		sum += atoi(av[i]);
	}
	printf("sum is: %d\n", sum);
	return(0);
}
