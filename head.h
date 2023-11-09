#ifndef MAIN_SHELL
#define MAIN_SHELL




typedef struct built
{
	char *commnad;
	int (*funcitno)(char **line, int st);
} builtin;


#endif
