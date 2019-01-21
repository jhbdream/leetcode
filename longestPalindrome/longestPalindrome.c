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


// string s start from to right 
// the max length of expand palidrome
int getPalindromeLength(char * s,int left,int right)
{
	int strLength = strlen(s);
	int l = 0;
	while( left>=0 && right <=strLength && s[left] == s[right])
	{
		left--;
		right++;
	}

	return right - left - 1;

}


char* longestPalindrome(char* s) {
	int len1;
	int len2;
	int start=0;
	int end=0;
	int i;
	int len;

	int length = strlen(s);

	if(length == 0 || length == 1) return s;

	for(i = 0; i < length; i++){
		len1 = getPalindromeLength(s,i,i);
		len2 = getPalindromeLength(s,i,i+1);

		len = (len1>len2)?len1:len2;

		if(len > (end - start)){
			start = i - (len - 1) / 2;
			end = start + len - 1;
		}
	}

	s[end+1] = '\0';
	return s+start;
}
int main(int argc, char const *argv[])
{

	char A[] = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
	//char A[] = "bb";
	char * R;
	//R = lcs(A,B,strlen(A),strlen(B));

	R = longestPalindrome(A);
	printf("%s\n",R);
	/* code */
	return 0;
}

