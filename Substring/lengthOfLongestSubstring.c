#include<stdio.h>

int lengthOfLongestSubstring(char* s) 
{
    
    int hash[256];
    
    char * end = s;

    int maxlen = 0;
    
    int len = 0;
    int poa = 0;

    for(int i = 0; i < 256; i++)
    {
        hash[i] = -1;
    }
    
    while(*end)
    {
        if( hash[*end] == -1 )
        {
            len++;
            hash[*end] = end - s ;   
            end++;
            
        }
        else
        {
            if( len > maxlen )
            maxlen = len;
            
            len = 0;
            
            end = s + hash[*(end)] + 1 ;
            
            for(int i = 0; i < 256; i++)
            {
                hash[i] = -1;
            }
            
        }
    }
    
         if( len > maxlen )
        maxlen = len;
    return maxlen;   
}

int main(int argc, char const *argv[])
{
    /* code */

    char * str="abcabcbb";
    int len;
    len = lengthOfLongestSubstring(str);

    printf("len %d\n",len);
    return 0;
}
