#include "app.h"

void *
show_1_svc(myString *argp, struct svc_req *rqstp)
{
	static char * result;
	int i=0;
	while(i<256 && argp->text[i] != '\0'){
		printf("%.2x", argp->text[i]);
		i++;
	} 
	printf("\n");
	return (void *) &result;
}
