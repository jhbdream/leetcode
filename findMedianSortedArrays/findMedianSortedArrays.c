#include<stdio.h>
/*
          left_part          |        right_part
    A[0], A[1], ..., A[i-1]  |  A[i], A[i+1], ..., A[m-1]
    B[0], B[1], ..., B[j-1]  |  B[j], B[j+1], ..., B[n-1]
*/
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int i,j;
	double mid;
	int m = nums1Size;
	int n = nums2Size;

	//ensure m is < n
	if( m > n )
	{
		int * temp = nums1;
		nums1 = nums2;
		nums2 = temp;

		int tmp = m;
		m = n;
		n =tmp;

	} 

	int iMin = 0;
	int iMax = m;

	//
	while(iMin <= iMax  )
	{
		i = (iMax + iMin) / 2;
		j = (m+n+1)/2 - i;

		if( nums1[i-1] > nums2[j] && i > iMin )
		{
			iMax = i - 1 ;
		}
		else if( nums2[j-1] > nums1[i] && i < iMax )
		{
			iMin = i + 1;
		}
		else
		{
			int maxleft,minright;
			if( i==0 )
				maxleft = nums2[j-1];
			else if( j==0 )
				maxleft = nums1[i-1];
			else 
				maxleft = nums1[i-1]>nums2[j-1]?nums1[i-1]:nums2[j-1];

			if( i==m )
			{
				minright = nums2[j];
			}
			else if(j==n)
			{
				minright = nums1[i];
			}
			else
			{
				minright = nums1[i]<nums2[j]?nums1[i]:nums2[j];
			}

			if( (m+n)%2 == 1 )
			{
				return (double)maxleft;
			}  

			return (double)(maxleft+minright) / 2.0 ;

		}
	}

	return 0.0;


}

int main(int argc, char const *argv[])
{
    /* code */

	// int A[4] = {1,3,5,7};
	// int B[4] = {2,4,6,8};
	int A[4] = {1,3};
	int B[4] = {2};
	double val;

	val = findMedianSortedArrays(A,2,B,1);

	printf("val is %lf\n",val);


    return 0;
}

