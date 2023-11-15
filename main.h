#ifndef MANI_SH
#define MAIN_SH




/** BUILTIN COMMAND HABDKERS****/

void exit_bul(char **cmd, char *input, char **argv, int x, int stat);
int check_builtin(char **cmd);
int handle_bultin(char **cmd, int st);



/** BUILTIN HELP HANDLER ***/
void help_env(void);
void help_setenv(void);
void help_unsetenv(void);
int display_help(char **cmd, int stat);

/** BUILT COMMAND EXECUTE ***/
int change_dir(char **cmd, int st);




/** GETLINE FUNCTION **/

char *_getline();
void hastag_handler(char *buf);
char *enter(char *str);
char *space(char *ptr);

/*** ENVIRONMENTAL HADNLER ****/
void create_env(char **env);
void free_env(char **env);


/*** HANDLE error **/
void print_error(char *in, int counter, char *argv);
void _perror(char **argv, int i, char **cmd);
void error_file(char **argv, int i);

/** MEMORY ****/
void *_realloc(void *ptr, unsigned int o_size, unsigned int n_size);
void *_calloc(unsigned int size);
void free_all(char **cmd, char *input);
void *fill_an_array(void *a, int el, unsigned int len);
char *_memcpy(char *dest, char *src, unsigned int n);

/** PARSE CMD **/
char **parse_cmd(char *in);

/** PATH FIND **/
int path_cmd(char *cmd);
char *getenv(char *name);
char *build(char *token, char *value);


/** PRINT NUMBRE ***/
void print_number(unsigned int num);
void print_number_int(int num);
int print_echo(char **cmd);


/** PROMP **/
void prompt(void);

/** SEPARATOR ***/
char **separator(int in);

/** stdin command executoin **/
int check_cmd(char **cmd, char *in, int i, char **argv);
void signal_to_handle(int signal);


/** STRING HANDLER 2**/
char *_strcpy(char *dest, char *stc);
int _strcmp(char *ptr, char *str);
int _strncmp(const char *pt, const char *str, size_t n );
char *_strdup(char *str);
char *_strcat(char *dest, char *src);


/** STRING HANDLER 3 **/
int _isalpha(int c);
char *_itoa(unsigned in n);
int intlen(int num);
void array_rev(char *arr, int len);



/** STRING TOKENIZE **/
unsigned int check_delim(char k, char *str);
char *_strtok(const char *str, const char *delim);

#endif
