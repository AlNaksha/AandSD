//---------------------------------------------------------------
//	code in UTF-8
//	Autor - Alexey Farnakeev (GU_C++_1438 11.05.2021).
//---------------------------------------------------------------
#include <stdio.h>
#include <math.h>

//---------------------------------------------------------------
//	1) ѕузырькова€ сортировка одномерного числового массива
//	длинна массива (len<0) - сортировка по убыванию, (len>0) - по возрастанию
//	реализую сразу 

void swap(int *a, int *b){ 				// мен€ет местами два числа
	
						// 1 и 4 (обмен значени€ми без вспомогательной переменной)
	*a = *a + *b;		// 5 и 4
	*b = *a - *b;		// 5 и 1
	*a = *a - *b;		// 4 и 1
}

void printarr(int *arr, int len){ 		// вывод линейного массива
	
	for ( int i = 0; i < len; i++){
		printf(" %d", arr[i]);
	}
	printf("\n");
	
}

int BubbleSort(int *arr, int len){ 		// ѕузырькова€ сортировка
	
	for (int j = 0; j < len; j++){
		
		for (int i = 0; i < len-1; i++){
			
			if (arr[i]>arr[i+1])
				swap( &arr[i], &arr[i+1] );
		}
	}
	
	return 0;
}

//---------------------------------------------------------------

void revarr(int *arr, int len){ 		// реверс элементов массива (например, возрастающий -> убывающий)
	
	len--;
	for (int i = 0; i < len; i++){
		
		swap(&arr[i],&arr[len]);
		len--;
	}
	
}

void scanarr(int *arr, int len){ 		// «апрос на ввод элементов массива
	
	printf("  Input %d numbers\n", len);
	fflush(stdout);
	
	for ( int i = 0; i < len; i++){
		scanf("%d", &arr[i]);
	}
	fflush(stdin);
	
}

int formula0(int x){ 					// ¬ыполнение некоторого вычислени€
	return sqrt(fabs(x)) + 5 * pow(x,3);
}
	
void TPK(){ 							// TPK- алгоритм
	
	int P[11];
	int len = sizeof(P)/sizeof(int);	// подсчет числа элементов массива
	
	scanarr(P, len);
	revarr(P, len);
	
	printarr(P, len);
	
	for (int i = 0; i < len; i++)
		if (formula0(P[i])>400) 
			printf(" Formula(P[%d]) > 400\n", i);
}

//---------------------------------------------------------------

int main(int args, const char** argv){
	
	int Array[] = {3,11,4,1,2,4,5,21,8,6,46,24,246,2};
	int len = sizeof(Array)/sizeof(int);
	
	printarr(Array, len);
	
	BubbleSort(Array, len);
	
	printarr(Array, len);
	
	TPK();
	
	return 0;
}