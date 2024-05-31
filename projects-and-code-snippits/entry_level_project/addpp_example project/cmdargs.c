/**
 * @file
 */

#include "cmdargs.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmdargs_parse(struct cmdargs *cmdargs, int argc, char *argv[])
{
	/* Initialize default values */
	*cmdargs = (struct cmdargs){0};

	/* Represents the current positional index */
	int positional_index = 0;

	/* We go though each argument in argv exept the first one (which normally
	 * is the program's relative path) and and try to make something out of it.
	 */
	for (int i = 1; i < argc; i++)
	{
		if (!strcmp(argv[i],"--verbose"))
		{
			cmdargs->verbose = 1;
		} else if (!strncmp(argv[i], "--", 2))
		{
			fprintf(stderr, "Unknown flag %s\n", argv[i]);
			return 0;
		} else
		{
			switch (positional_index)
			{
				case 0:
					/* FIXME: Use proper error checkng function here */
					cmdargs->x = atoi(argv[i]);
					break;

				case 1:
					/* FIXME: Use proper error checkng function here */
					cmdargs->y = atoi(argv[i]);
					break;
			}
			positional_index++;
		}
	}

	if (positional_index < 2)
	{
		/* Too few mandatory positional arguments */
		fprintf(stderr,"Not enough arguments given!\n");
		return 0;
	}
	if (positional_index > 2)
	{
		/* Too many positional arguments */
		fprintf(stderr,"Too many arguments given!\n");
		return 0;
	}
	return 1;
}
