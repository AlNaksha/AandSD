//---------------------------------------------------------------
//	code in UTF-8
//	Autor - Alexey Farnakeev (GU_C++_1438 11.05.2021).
//---------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
// #include "../sourse/arrays.h"
//---------------------------------------------------------------

void fillrandarr (int *arr, int len, int bord){ 	// Заполнение массива псевдослучайными числами 
	for (int i = 0; i < len ; i++){
		*(arr + i) = rand() % bord;
	}
}
	
void printarr (int *arr, int len){ 					// вывод линейного массива
	
	for ( int i = 0; i < len; i++){
		printf(" %2d", *(arr + i));
	}
	printf("\n");
	
}

void swap (int* n, int* m){							// Меняет местами 2 целочисленных переменных
	int temp = *m;
	*m = *n;
	*n = temp;
	
	// *n += *m;
	// *m = *n - *m;
	// *n -= *m;
}

//---------------------------------------------------------------

void sortinsert (int *arr, int len){				// Сортировка методом вставки
	
	int temp, pos;
	
	for (int i = 1; i < len; ++i){
		temp = arr[i];
		pos = i - 1;
		while ((pos >= 0) && (arr[pos] > temp)){
			arr[pos+1] = arr[pos];
			pos--;
		}
		arr[pos+1] = temp;
	}
	
}

void sortquickH (int *arr, int first, int last){	// Быстрая сортировка с разбиением Хоара
	int i = first;
	int j = last;
	
	int x = arr[(first + last)/2];
	
	do{
		while (arr[i]<x) i++;
		while (arr[j]>x) j--;	
		
		if (i <= j){
			swap( &arr[i], &arr[j] );
			i++;
			j--;			
		}
		
	}	while (i < j);
	
	if (i < last) sortquickH(arr, i, last);
	if (first < j) sortquickH(arr, first, j);
	
	
}

void sortupdquick (int *arr, int first, int last){ 	// Улучшенная быстрая сортировка
	
	if (last-first <= 10){
		sortinsert(arr+first, last-first+1);
	} else{
		int mid = (first+last)/2;
		
		if ((arr[mid] > arr[first]) && (arr[mid] > arr[last]))
			swap(&arr[mid], &arr[last]);
		else if ((arr[mid] < arr[first]) && (arr[mid] < arr[last]))
			swap(&arr[first], &arr[mid]);
		
		sortquickH(arr, first, last);
	}
	
}

//---------------------------------------------------------------

void sortblocks (int *arr, int len){				// Блочная сортировка
	const int max = len;
	const int b = 10;
	
	int buckets[b][max+1];
	for (int i = 0; i < b; ++i){					//обнуление счетчиков заполнения
		buckets[i][max] = 0;		
	}
	
	for (int digit = 1; digit < 1000000000; digit *= 10){
		
		for (int i = 0; i < max; ++i){
			int d = (arr[i] / digit) % b;
			
			if (arr[i] % 2 == 0 && arr[i] >= 0)
				buckets[d][buckets[d][max]++] = arr[i];
			
		}
		
		int idx = 0;
		
		for (int i = 0; i < b; ++i){
			for (int j = 0; j < buckets[i][max]; ++j){
				
				while (idx < len && arr[idx]%2 != 0 )
					idx++;
				
				arr[idx++] = buckets[i][j];
			}
			buckets[i][max] = 0;
		}
		
	}
	
}
//---------------------------------------------------------------

int main(int args, const char** argv){
	int P[100];
	int len = sizeof(P)/sizeof(int);
	
	fillrandarr(P, len, 100);
	printarr(P, len);
	// sortupdquick(P, 0, len-1);
	sortblocks(P, len);
	printarr(P, len);
	
	return 0;
}