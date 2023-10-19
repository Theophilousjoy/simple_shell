#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <limits.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/stat.h>

/* get-looping.c */
int hsh(info_t *, char **);
int search_builtin(info_t *);
void search_cmd(info_t *);
void fork_cmd(info_t *);

/* let_par-sec.c */
int if_cmd(info_t *, char *);
char *chars_cp(char *, int, int);
char *search_path(info_t *, char *, char *);
int loop_hsh(char **);

/* errors.c */
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);


/* first_strings.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);
int _strlen(char *);
int _strcmp(char *, char *);
char *begin_with(const char *, const char *);
char *_strcat(char *, char *);


/* exit.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/* get_token.c */
char **strtow(char *, char *);
char **strtow2(char *, char);

/* alloc.c */
char *_memset(char *, char, unsigned int);
void fr_free(char **);
void *_re_alloc(void *, unsigned int, unsigned int);

/* used-memor.c */
int bwfree(void **);

/* main.c */
int interaction(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

/* the-errors.c */
int _error_atoi(char *);
void prt_error(info_t *, char *);
int prt_d(int, int);
char *change_number(long int, int, int);
void clear_comments(char *);

/* the_builtin.c */
int _grpexit(info_t *);
int _grpcd(info_t *);
int _grphelp(info_t *);

/* the-builtin-exit.c */
int _grphistory(info_t *);
int _grpalias(info_t *);

/* get_line_file.c */
ssize_t get_input_of_file(info_t *);
int _get_line_input(info_t *, char **, size_t *);
void int_Handler_signal(int);

/* let_info.c */
void delete_info(info_t *);
void assign_info(info_t *, char **);
void fr_info(info_t *, int);

/* env.c */
char *_getenv(info_t *, const char *);
int _grpenv(info_t *);
int _grpsetenv(info_t *);
int _grpunsetenv(info_t *);
int envn_list_pop(info_t *);

/* let_environ.c */
char **get_environ_file(info_t *);
int _un_environ(info_t *, char *);
int _set_environ(info_t *, char *, char *);

/* history.c */
char *history_path_file(info_t *info);
int wrt_history(info_t *info);
int rd_history(info_t *info);
int history_list_build(info_t *info, char *buf, int linecount);
int re_history_number(info_t *info);

/* first_listing.c */
list_t *sum_node(list_t **, const char *, int);
list_t *sum_node_end(list_t **, const char *, int);
size_t print_list_of_strns(const list_t *);
int clear_index_node(list_t **, unsigned int);
void fr_list(list_t **);
size_t list_lgth(const list_t *);
char **list_of_strg(list_t *);
size_t pr_list(const list_t *);
list_t *start_node(list_t *, char *, char);
ssize_t *index_node(list_t *, list_t *);

/* get_variable.c functions */
int info_file(info_t *, char *, size_t *);
void verify_info(info_t *, char *, size_t *, size_t, size_t);
int substitute_alias(info_t *);
int substitute_vars(info_t *);
int subtsitute_string(char **, char *);

#endif

