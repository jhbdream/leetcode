#include<stdio.h>
#include<string.h>
#include <stdlib.h>

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

char * lcs(char * A,char * B,int m,int n)
{
	int i = 0,j=0,l=0;
	char * substring = (char *)malloc(6);

	int * L = (int *)malloc((m+1)*(n+1)*sizeof(int));
	int * P = L;


	/*1*/
	for( i=m; i >= 0; i-- )
		for( j = n; j >=0; j--)
		{
			if( A[i] == '\0' || B[j] == '\0') L[i*m+j] = 0;
			else if(A[i] == B[j] ) L[i*m+j] = 1 + L[(i+1)*m+j+1];
			else L[i*m+j] = max(L[(i+1)*m+j],L[i*m+j+1]);  

		}
	/*2*/

	i = 0; j = 0;l=0;
	while(i < m && j < n)
	{
		if(A[i] == B[j])
		{
			substring[l++] = A[i];
			i++;
			j++;
		}
		else if(L[(i+1)*m+j]>L[(i*m+j+1)])
		{
			i++;
		}
		else
		{
			j++;
		}
	}

	substring[l] = '\0';

	return substring;

}

char* longestPalindrome(char* s) {

	char * A = s;
    int start;
	int length = strlen(s);
	int m,n;
	m = length;
	n = length;
	int k = 0;
	char *B = (char *)malloc(length+1);
	
	for( k = 0; k < length ; k++ )
	{
		B[k] = A[length-k-1];
	}

	int i = 0,j=0,l=0;
//	char * substring = (char *)malloc(max(m,n)+1);
//    static char  substring[10000];
	int * L = (int *)malloc((m+1)*(n+1)*sizeof(int));
//	static int L[8000000];	


	int * P = L;


	/*1*/
	for( i=m; i >= 0; i-- )
		for( j = n; j >=0; j--)
		{
			if( A[i] == '\0' || B[j] == '\0') L[i*(m+1)+j] = 0;
			else if(A[i] == B[j] ) L[i*(m+1)+j] = 1 + L[(i+1)*(m+1)+j+1];
			else L[i*(m+1)+j] = max(L[(i+1)*(m+1)+j],L[i*(m+1)+j+1]);  

		}



	for(i=0;i<=m;i++)
	{
		for(j=0;j<=n;j++)
		{
			printf("%d ",L[i*(m+1)+j]);
		}
		printf("\n");
	}
	// /*2*/

	i = 0; j = 0;l=0;start = -1;
	while(i < m && j < n)
	{
		if(A[i] == B[j] )
		{
            if(start == -1)
                start = i;
            if(i-start > 1)
            	start = i;
            l++;
            i++;
			j++;
		}
		else if(L[(i+1)*(m+1)+j]>L[(i*(m+1)+j+1)])
		{
			i++;
		}
		else
		{
			j++;
		}
	}

	s[l+1] = '\0';

    free(B);
    free(L);
    L = NULL;
    B = NULL;
	return s+start;
	
}
int main(int argc, char const *argv[])
{

	//char A[] = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
	char A[] = "ABCBC";
	char * R;
	//R = lcs(A,B,strlen(A),strlen(B));

	R = longestPalindrome(A);
	printf("%s\n",R);
	/* code */
	return 0;
}