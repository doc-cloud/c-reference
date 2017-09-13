
/*
 * The exit() function causes normal process termination and the value of status & 0377 is returned to the parent (see wait(2)).
 * 
 * All  functions  registered with atexit(3) and on_exit(3) are called, in the reverse order of their registration.  (It is possible for one of these functions
 * to use atexit(3) or on_exit(3) to register an additional function to be executed during exit processing; the new registration is added to the front  of	the
 * list  of functions that remain to be called.)  If one of these functions does not return (e.g., it calls _exit(2), or kills itself with a signal), then none
 * of the remaining functions is called, and further exit processing (in particular, flushing of stdio(3) streams) is abandoned.  If a function has been regis‐
 * tered multiple times using atexit(3) or on_exit(3), then it is called as many times as it was registered.
 * 
 * All open stdio(3) streams are flushed and closed.  Files created by tmpfile(3) are removed.
 * 
 * The  C  standard  specifies  two  constants, EXIT_SUCCESS and EXIT_FAILURE, that may be passed to exit() to indicate successful or unsuccessful termination,
 * respectively.
 */

#include <stdio.h>
#include <stdlib.h>

int main ()
{
	printf("Start of the program....\n");

	printf("Exiting the program....\n");
 	/* exit status code, it can be detected in shell */
	exit(0);

	printf("End of the program....\n");

	return(0);
}

/*
exit encapsulate _exit SC, and do some final work. eg: clear user I/O buffer, store the content into disk,
after these, get into kernel _exit, release user process space.
*/

