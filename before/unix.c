/* ioccc.c */

/* IOCCC best one-liner winner 1987 by David Korn ---

main() { printf(&unix["\021%six\012\0"],(unix)["have"]+"fun"-0x60);}

from <http://www.ioccc.org/years.html#1987>
*/

/* A detailed set of samples to show how this works
   by David Ireland, copyright (C) 2002.
*/

#include <stdio.h>

main() 
{
	/* OK, 'unix' is an int by default. 
	   You may need to declare with fussy compilers (MSVC),
	   and perhaps explicitly not with others (gcc).
	*/

	//int unix;

	printf("unix=%d\n", unix); /* =1 */	
	
	/* Now why does this variable have the value one? */
	
	/* A. Because the first int declared in main is 'argc' in K&R C,
	   as in main(int argc, char *argv[]).
	   It will be set to one when main() is called by the OS
	   - try adding extra args to cmd line and see it increase.
	   (Or try declaring another variable before it like this:
	      int dummy;
	      int unix;
	   What value will 'unix' have now?)
	*/

	/* This prints the string "un", 
	   i.e. "fun" starting at offset [1] */
	printf("%s\n","fun"+1);

	/* This prints 97 = the int value of the 2nd char 'a' */
	printf("%d\n", "have"[1]);

	/* just like this */
	printf("%d\n", 'a');

	/* ditto because x[1] = 1[x] */
	printf("%d\n", (1)["have"]);

	/* 97 - 96 = 0x61 - 0x60 = 1 */
	printf("%d\n", (1)["have"] - 0x60);

	/* So this is the same as "fun" + 1, printing "un" */
	printf("%s\n", "fun" + ((1)["have"] - 0x60));

	/* Rearrange and use unix variable instead of 1 */
	printf("%s\n", (unix)["have"]+"fun"-0x60);

	/* ...thus we have the first argument in the printf call. */

	/* Both these print the string "bcde", ignoring the 'a' */
	printf("%s\n", "abcde" + 1);
	printf("%s\n", &"abcde"[1]);

	/* so does this */
	printf("%s\n", &(1)["abcde"]);

	/* and so does this (NB [] binds closer than &) */
	printf("%s\n", &unix["abcde"]);

	/* This prints "%six" + newline */
	printf("%s", &"?%six\n"[1]);

	/* So does this: note that
	   \012 = 0x0a = \n,
	   the first \021 char is ignored,
	   and the \0 is superfluous, probably just for symmetry */
	printf("%s", &"\021%six\012\0"[1]);

	/* and so does this */
	printf("%s", &unix["\021%six\012\0"]);

	/* Using this as a format string, we can print "ABix" */
	printf(&unix["\021%six\012\0"], "AB");

	/* just like this does */
	printf("%six\n", "AB");

	/* So, we can print "unix" like this */
	printf("%six\n", (unix)["have"]+"fun"-0x60);
	
	/* or, finally, like this */
	printf(&unix["\021%six\012\0"],(unix)["have"]+"fun"-0x60);

	return 0;
}


/* Korn winner, rearranged for fussier compliers  ---
#include <stdio.h>
int main() 
{
	int unix;
	printf(&unix["\021%six\012\0"],(unix)["have"]+"fun"-0x60);
	return 0;
}
*/
