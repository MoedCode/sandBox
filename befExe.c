#include "main.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char  *isNullTrm(char **arr)
{
	size_t i;
	for (i = 0; arr[i] ; i++ )
		if (!arr[i +1])
				return ("ARRAY NULL YERMINATED");

return (0);
}

char *mrgCmdAndPath(char *currPath ,char *cmdName)
{

	size_t i, lnaloc =(strlen(cmdName) + strlen(currPath) + 2) ;
	char *mergedPath;

	mergedPath =malloc( lnaloc * sizeof(char) );
	if (!mergedPath)
		{
			fprintf(stderr, "mergedPath Allocation %s%d",__FILE__,__LINE__);
			return (NULL);
		}
	strcpy(mergedPath, currPath);
	strcat(mergedPath,"/");
	strcat(mergedPath,cmdName);
	if (access(mergedPath , X_OK)  == 0)
			return (mergedPath);
	free(mergedPath);

	// printf("\n>>>>>>>mergedPath<<<<< %s \n",mergedPath);

	return (NULL);

}
char *isExecuteable(char **PathArr ,char **argv)
{
	size_t i = 0, j = 0,k = 0;
	char* isPathExe = NULL;

	while (PathArr[j])
		j++;

	for (; i < j; i++)

			{
				char *isPathExe = mrgCmdAndPath(PathArr[i], argv[0]);
				k++;
				if (isPathExe)
					return (isPathExe);
			}
			// printf("k[%zu],j[%zu],%s%d\n",k,j,__FILE__,__LINE__);

	return (NULL);
}

