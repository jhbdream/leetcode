#include <stdlib.h>
#include <string.h>
#include <stdio.h>
char* convert(char* s, int numRows) {
    int length = strlen(s);
    char * ret = malloc(length+10);
    ret[length] = '\0';
    int pos=0;
    int cycleLen = 2 * numRows - 2;

    if(1==numRows) return s;
    
    for(int i = 0; i < numRows; i++)
    {
    	for(int j = 0; j + i < length; j += cycleLen)
    	{
    		ret[pos++] = s[j+i];
    		if(i!=0 && i!=numRows-1 && j+cycleLen-i < length)
    			ret[pos++] = s[j + cycleLen - i];
    	}
    }

    return ret;

}
int  main(int argc, char const *argv[])
{
	/* code */

	char a[]="AB";
	char* B = convert(a, 1);
	printf("%s\n",B);

	return 0;
}