/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "app.h"


void
zadanie_2_1(char *host,char text[256])
{
	CLIENT *clnt;
	void  *result_1;
	myString  show_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, ZADANIE_2, ZADANIE_2_VERSION, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
	strcpy(show_1_arg.text,text);
	result_1 = show_1(&show_1_arg, clnt);
	if (result_1 == (void *) NULL) {
		clnt_perror (clnt, "call failed");
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	while(1){
		char text[256];
		fgets(text,sizeof(text),stdin);
		zadanie_2_1 (host,text);
		fflush(stdin);
	}
exit (0);
}
