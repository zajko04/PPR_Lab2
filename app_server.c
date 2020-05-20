#include "app.h"

int *
add_1_svc(arguments *argp, struct svc_req *rqstp)
{
	static int  result;

	result = argp->a + argp->b;

	return &result;
}
