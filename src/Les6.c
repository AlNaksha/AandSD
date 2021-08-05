//---------------------------------------------------------------
//	code in UTF-8
//	Autor - Alexey Farnakeev (GU_C++_1438 11.05.2021).
//---------------------------------------------------------------
#include <stdio.h>
#include <math.h>

//---------------------------------------------------------------
//	1) ����������� ���������� ����������� ��������� �������
//	������ ������� (len<0) - ���������� �� ��������, (len>0) - �� �����������
//	�������� ����� 

void swap(int *a, int *b){ 				// ������ ������� ��� �����
	
						// 1 � 4 (����� ���������� ��� ��������������� ����������)
	*a = *a + *b;		// 5 � 4
	*b = *a - *b;		// 5 � 1
	*a = *a - *b;		// 4 � 1
}

void printarr(int *arr, int len){ 		// ����� ��������� �������
	
	for ( int i = 0; i < len; i++){
		printf(" %d", arr[i]);
	}
	printf("\n");
	
}

int BubbleSort(int *arr, int len){ 		// ����������� ����������
	
	for (int j = 0; j < len; j++){
		
		for (int i = 0; i < len-1; i++){
			
			if (arr[i]>arr[i+1])
				swap( &arr[i], &arr[i+1] );
		}
	}
	
	return 0;
}

//---------------------------------------------------------------

void revarr(int *arr, int len){ 		// ������ ��������� ������� (��������, ������������ -> ���������)
	
	len--;
	for (int i = 0; i < len; i++){
		
		swap(&arr[i],&arr[len]);
		len--;
	}
	
}

void scanarr(int *arr, int len){ 		// ������ �� ���� ��������� �������
	
	printf("  Input %d numbers\n", len);
	fflush(stdout);
	
	for ( int i = 0; i < len; i++){
		scanf("%d", &arr[i]);
	}
	fflush(stdin);
	
}

int formula0(int x){ 					// ���������� ���������� ����������
	return sqrt(fabs(x)) + 5 * pow(x,3);
}
	
void TPK(){ 							// TPK- ��������
	
	int P[11];
	int len = sizeof(P)/sizeof(int);	// ������� ����� ��������� �������
	
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