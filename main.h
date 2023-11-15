#ifndef MANI_SH
#define MAIN_SH




/** BUILTIN COMMAND HABDKERS****/

void exit_bul(char **cmd, char *input, char **argv, int x, int stat);



/** GETLINE FUNCTION **/

char *_getline();
void hastag_handler(char *buf);
char *enter(char *str);

/*** ENVIRONMENTAL HADNLER ****/
void create_env(char **env);
void free_env(char **env);


/*** HANDLE error **/
void print_error(char *in, int count, char *argv);
void _perror(char *8argv, int i, char **cmd);
voi error_file(char **argv, int i);

/** MEMORY ****/
void *_realloc(void *ptr, unsigned int o_size, unsigned int n_size);
void *_calloc(unsigned int size);
void free_all(char **cmd, char *line);

/** PRINT NUMBRE ***/
void print_number(unsigned int num);
void print_number_int(int num);
int print_echo(char **cmd);

/** SEPARATOR ***/
char **separator(int in);

/** stdin command executoin **/
int check_cmd(char **cmd, char *in, int i, char **argv);


#endif
