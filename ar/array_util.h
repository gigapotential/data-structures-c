#ifndef _ARRAY_UTIL_H
#define _ARRAY_UTIL_H
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define max(a,b) ( ((a) > (b)) ? (a) : (b) )

int * random_array(int size, int min, int max)
{
	int i ;
	srand(time(NULL));
	int *a = (int *) malloc(size * sizeof(int));
	for( i = 0; i < size; ++i)
		a[i] = (int) (((float)rand()/(float)RAND_MAX)*(max-min) + min);
	return a;	
}

void print(int *a, int size)
{
	int i;
	for( i = 0; i < size; ++i)
		printf("%d ", a[i]);
	printf("\n");
}

int max_contiguous_subarray_sum(int *a, int size, int *start, int *end)
{
	int	maxsofar = 0;
	int	maxendinghere = 0;
	int maxendinghere_begin = 0;
	int maxsofar_begin = -1, maxsofar_end = -1;
	int i;

	for( i = 0 ; i < size ; ++i)
	{
		//maxendinghere = max(0, maxendinghere + a[i]);
		if( 0 > (maxendinghere + a[i])) {
			maxendinghere_begin = -1;
			maxendinghere = 0;
		} else {
			//  udpate maxendinghere_begin when maxendinghere is transitioning from 
			//  0 to a +ve value
			if( maxendinghere == 0 && (maxendinghere + a[i] > 0))
				maxendinghere_begin = i;
			maxendinghere = maxendinghere + a[i];
		}
	
		//maxsofar = max(maxsofar, maxendinghere);
		if( maxsofar < maxendinghere ) {
			maxsofar_begin = maxendinghere_begin;
			maxsofar_end = i;
			maxsofar = maxendinghere;
		}
	}
	
	*start = maxsofar_begin;
	*end = maxsofar_end;
	return maxsofar;
}

// Knuth's Shuffle
void shuffle(int *a, int size)
{
	if( a != NULL && size > 1 )
	{
		int i, random_idx, temp;

		srand(time(NULL));
		for ( i = 0; i < size -1 ; ++i)
		{
			random_idx =  (int)(((float)rand()/(float)RAND_MAX)*( (size -1) - (i+1) )  + (i+1));
			temp = a[i];
			a[i] = a[random_idx];
			a[random_idx] = temp;
		}
	}
}

#endif