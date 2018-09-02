/** mystring.h
 * @author Mike Ciaraldi
 * @author Fivos Kavassalis
*/
#include <string.h>
#include <stdlib.h>

// Function prototype(s):
char* mystrdup1(const char* src);
char* mystrdup2(const char* src);
size_t mystrlen1(const char *str);
size_t mystrlen2(const char *str);
char* mystrcpy(char* dest, const char* src);
char* mystrcat(char* dest, const char* s);
char* mystrncat(char* dest, const char* s, size_t n);
char* mystrncpy(char* dest, const char* s, size_t n);
char* mystrndup(const char* s, size_t n);
