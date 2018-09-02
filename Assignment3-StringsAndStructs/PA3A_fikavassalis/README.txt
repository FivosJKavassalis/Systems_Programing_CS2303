README – PA3A
Fivos Kavassalis/fikavassalis



The main() function of the PA3A program consists of  test cases for the functions in mystring.c . The program might test different cases for each function  to demonstrate what each function does, more clearly. The functions in mystring.c are mainly functions that already exist (built-in), and each definition is my interpretation of that built-in function. The function mystrdup1() was basically created by the professor. This function duplicates a C-style string. The only difference I was  assigned to do, was to implement the mystrlen1() function, which is my own version of strlen() (Calculates the length of the string without the null-terminator). The same thing was done for mystrlen2() and mystrdup2() which was my second version of strlen().  The next function is mystrcpy() which copies one string to another. I’m using pointer incrementation as requested, and it is also faster than incrementing subscripts. Then, mystrcat() is an imitation of strcat() which concatenates one string to another.  The next one is mystrncat() which  concatenates, from one string to another, no more than the requested amount of characters from the user (from source string). The last two functions are mystrncpy() and mystrndup(). The former, copies the requested amount of characters from the source string to the destination, at most. If the length of the source string is greater or equal to the requested amount, the function copies the requested amount but without a null-terminator (except if it is one of the characters copied). If the length of the string is less than the requested amount, the function copies all of the characters of the source string and pads null-terminators until the requested amount is matched. The latter, duplicates a string of no more than the requested amount of characters. This function always adds a null-terminator.  Nearly every function created, (except mystrlen1for () and mystrlen2()) return a character pointer to the string. 



SEE INSTRUCTIONS BELOW:

Instructions on how to open, compile, link, run and clean from the command line:
	After going to the specific directory,
1) unzip by:  unzip PA3A_fikavassalis;
2) change directory again: cd PA3A_fikavassalis
3)   make all
4)   run with  “./ctest” 
5)   make clean


Instructions on how to open, compile, link, run and clean from Eclipse:
1) Import zip by clicking File→Import
2) General→Existing Projects into Workspace
3) Then, click on Archive file and search for PA3A_fikavassalis.zip
4) Right-click on project, and select “Build Project”
5) Right-click again, but select “Run as→Local C/C++ Application ”
6) Click “Clean Project” by right-clicking on project

