//---------------------------------------------------------------
//	code in UTF-8
//	Autor - Alexey Farnakeev (GU_C++_1438 11.05.2021).
//---------------------------------------------------------------

#include <stdio.h>

//---------------------------------------------------------------

int BubbleSort(int **arr, int n, int m){ 		// Пузырьковая сортировка двумерного массива
	
	int len = n*m;
	
	for (int j = 0; j < len; j++){

		for (int i = 0; i < len-1; i++){

			if ( *(arr + i) > *(arr+i+1) )
				swap( &*(arr+i), &*(arr+i+1) );
		}
	}

	return 0;
}


int main(int args, const char** argv){
	
	int Array[][] = {
		{3,11,4,1},
		{2,4,5,21},
		{8,6,46,24},
		{246,2,4,7}
	};
	int len = sizeof(Array)/sizeof(int);
	
	return 0;
}