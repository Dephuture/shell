#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	int i;
	printf("av[] values\n:");

	while(*av != NULL)
	{
		printf("av = %s\n", *av);
		av++;
	}
	return(0);
}
