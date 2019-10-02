/* Lab 1 - Bastien HUBERT */

#include "iplot.h"

int* askForBoundaries()
{
	int* boundaryList = calloc(2, sizeof(int));

	do {
		printf("Please enter the inferior boundary of the function :\n");
		scanf("%d", &boundaryList[0]);
		printf("Please enter the superior boundary of the function :\n");
		scanf("%d", &boundaryList[1]);
	} while(boundaryList[0] > boundaryList[1]);
  
	return boundaryList;
}

int writeCommands(int* boundaries)
{
	FILE * fp;
  
	fp = fopen ("./etc/commands.gp", "w");

	fprintf(fp, "%s%d%s%d%s", "set xrange [", boundaries[0], ":", boundaries[1], "]\n");
	fprintf(fp, "%s","set samples 500\nset title \"Sinc function\"\nset xlabel \"x\"\nset ylabel \"sin(x)/x\"\nset border\nset grid\nplot sin(x)/x");
  
	fclose(fp);

	return 0;
}

void manage_parent(int* boundaries)
{
	writeCommands(boundaries);
	sleep(0.5);
}

void manage_child()
{
	execlp("gnuplot", "gnuplot", "-persist", "./etc/commands.gp", NULL);
	/*  sleep(0.5);*/
	exit(EXIT_SUCCESS);
}
