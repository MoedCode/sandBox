#include "main.h"

size_t freeDoubleArray(char **argv)
{
	size_t i, j;

	for (j = 0; argv[j]; j++)
			;
	for (i = 0; i < j; i++)
		if(argv[i])
		{

			free(argv[i]);
			DEBUG("argv[i] ");
			argv[i] = NULL;
 		}


	if(argv)
	{
	free(argv);
	DEBUG("argv ");
	argv = NULL;
	}
	return (i);
}