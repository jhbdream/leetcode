#include "lcs.h"

int max(int A,int B)
{
	return A>B?A:B;
}

int lcs_length(char * A, char * B)
{
	if (*A == '\0' || *B == '\0') return 0;
	else if (*A == *B) return 1 + lcs_length(A+1, B+1);
	else return max(lcs_length(A+1,B), lcs_length(A,B+1));
}
