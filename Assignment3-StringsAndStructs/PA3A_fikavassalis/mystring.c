/** mystring.c
 * @author Mike Ciaraldi
 * @author Fivos Kavassalis
 */

#include <string.h>
#include <stdlib.h>
// Have to #include stdlib.h because it is needed to use malloc()
#include "mystring.h"

/** Duplicates a C-style string.
 * @param src Pointer to string to be copied
 * @return Pointer to freshly-allocated string containing a duplicate of src
 * or null if no memory is available
 */

char* mystrdup1(const char* src) {
	int length; // Length of the source string
	char* newstr; // Pointer to memory which will hold new string

	length = mystrlen1(src) + 1;  // Leave space for the terminator
	newstr = (char*) malloc(length); // Must cast!

	// If no memory was available, return null pointer immediately
	if (newstr == 0)
		return (char *) 0;

	// Otherwise, copy the string and return pointer to new string
	strcpy(newstr, src);
	return newstr;
}

/** Duplicates a C-style string.
 * @param src Pointer to string to be copied
 * @return Pointer to freshly-allocated string containing a duplicate of src
 * or null if no memory is available
 */

char* mystrdup2(const char* src) {
	int length; // Length of the source string
	char* newstr; // Pointer to memory which will hold new string

	length = mystrlen2(src) + 1;  // Leave space for the terminator
	newstr = (char*) malloc(length); // Must cast!

	// If no memory was available, return null pointer immediately
	if (newstr == 0)
		return (char *) 0;

	// Otherwise, copy the string and return pointer to new string
	strcpy(newstr, src);
	return newstr;
}

/** Calculates the length of a C-style string.
 *@param p Pointer to string to be copied
 *@return Length of string
 */
size_t mystrlen1(const char *p) {
	size_t len = 0;
	int i;

	for (i = 0; p[i] != 0; i++) {
		len++;      // while p[i] i not the null-terminaor
	}

	return (len);
}

/** Calculates the length of a C-style string.
 *@param s Pointer to string to be copied
 *@return Length of string
 */

size_t mystrlen2(const char *s) {
	const char *p = s;

	while (*p)    
		++p;   // while p is not pointing to the null-terminator, add 1

	return p - s;

}

/** Copies source string to destination.
 * @param dest Destination pointer
 * @param s    Source string
 * @return Pointer to dest
 */

char* mystrcpy(char* dest, const char* s) {

	char* strTransition = dest;

	while (*s != '\0') {  // while value pointed to by pointer s is not the null-terminator
		*dest = *s;   
		dest++;
		s++;

	}

	*dest = '\0'; // insert null terminator in the end

	return strTransition;

}

/**  Concatenate source string to destination.
 * @param dest Destination pointer
 * @param s    Source string
 * @return Pointer to dest

 */

char* mystrcat(char* dest, const char* s) {
	char* strConcat = dest;

	while (*dest != '\0') { // while value that pointer dest points to, is not the null-terminator
		dest++;
	}

	while (*s != '\0') { // while value that pointer s points to, is not the null-terminator
		*dest = *s;
		dest++;
		s++;
	}

	*dest = '\0';

	return strConcat;
}

/**  Concatenate no more than the requested amount of characters of the source string to destination.
 *@param dest Destination pointer
 *@param s    Source string
 *@param n    Number of characters to concatenate
 *@return Pointer to dest
 */

char* mystrncat(char* dest, const char* s, size_t n) {
	int count = 0;
	char* strConcat = dest;

	while (*dest != '\0') { // while value that pointer dest points to, is not the null-terminator
		dest++;
	}

	while (*s != '\0' && count++ < n) { // while value that s points to, is not the null-terminator
		*dest = *s;
		dest++;
		s++;
	}

	*dest = '\0';

	return strConcat;
}

/**  Copies no more than the requested amount of characters of the source string to destination.
 *@param dest Destination pointer
 *@param s    Source string
 *@param n    Number of characters to copy
 *@return Pointer to dest
 *If length of s is >= n, only copies first n characters, and does not null-terminate!
 *If length of s is < n, padds with nulls at after copying source string
 */

char* mystrncpy(char* dest, const char* s, size_t n) {
	char* strCp = dest;

	if (mystrlen1(s) >= n) { // mystrlen1 does not include null terminator when finding length
		for (int i = 0; i < n; i++) { // do n times
			*dest = *s;
			dest++;
			s++;
		}

	} else {
		mystrcpy(dest, s);
	}

	return strCp;
}

/** Duplicates a C-style string, but copies at most n bytes.
 * @param s Pointer to string to be copied
 * @return Pointer to freshly-allocated string containing a duplicate of src
 * or null if no memory is available
 *  If s is longer than n, only n bytes are copied and a terminating null byte is added
 */
char* mystrndup(const char* s, size_t n) {
	if (n < mystrlen1(s)) {
		int len; // Length of the source string
		char* dupS; // Pointer to memory which will hold new string

		len = n + 1;  // Leave space for the terminator
		dupS = (char*) malloc(len * sizeof(char)); // Must cast!
		char* returnP = dupS;

		// If no memory was available, return null pointer
		if (dupS == 0)
			return (char *) 0;

		for (int i = 0; i < n; i++) { // do n times
			*dupS = *s; // assign value pointed by s, to the value pointed by dupS 
			dupS++;
			s++;
		}
		*dupS = '\0';

		return returnP;
	} else {
		return mystrdup1(s);
	}

}
