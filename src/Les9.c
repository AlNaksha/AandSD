//---------------------------------------------------------------
//	code in UTF-8
//	Autor - Alexey Farnakeev (GU_C++_1438 11.05.2021).
//---------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
// #include "../sourse/dynamic.h"
//---------------------------------------------------------------
// Описать очередь(первым вошел - первый вышел)(добавляется в конец, удаление с начала) 
// с приоритетным (ключ(приоритет)-значение(данные)) исключением (добавляется в конец, удаляется наиболее приоритетный)
// Самым приоритетным будет наименьшее число

#define SZ 10

typedef struct {
	int pr; 		// приоритет
	int data;		// данные
} pq;

pq* que[SZ]; 	// очередь
int front;		// начало(голова) очереди
int end;		// конец(хвост) очереди
int items;		// Число элементов
int len = SZ;

void initq(){						// Инициализация(задание начального состояния)
	for (int i = 0; i < len; ++i)
		que[i] = NULL;
	front = 0;
	end = 0;
	items = 0;
}

void enqueue(int pr, int data){ 	// добавление в очередь
	
	if (items == len){
		printf("%s \n", "Queue is full");
		return;
		
	} else{
		pq *node = (pq*) malloc(sizeof(pq));
		node->data = data;
		node->pr = pr;
		
		if (items == 0){
			que[end++] = node;
			items++;
		} else{
			
			int flag;
			int i = 0;
			int idx = 0;
			pq* tmp;
			for (i = front; i < end; ++i){
				idx = i%len;
				if (que[idx]->pr > pr)
					break;
				else
					idx++;
			}
			flag = idx % len;
			i++;
			while (i <= end){
				idx = i % len;
				tmp = que[idx];
				que[idx] = que[flag];
				que[flag] = tmp;
				i++;
			}
			que[flag] = node;
			items++;
			end++;
			if (front > len){
				front -= len;
				end -= len;
			}
		}
	}
}

pq* dequeue(){						// Удаление приоритетного элемента
	if (items == 0){
		return NULL;
	} else {
		int idx = front++ % len;
		pq* tmp = que[idx];
		que[idx] = NULL;
		items--;
		return tmp;
	}
	
}

void peekq(){						// Чтение содержимого
	printf("[ ");
	for (int i = 0; i < len; ++i){
		if (que[i] == NULL)
			printf("[ *, *] ");
		else
			printf("[ %d, %d] ", que[i]->pr, que[i]->data);
	}
	printf(" ]\n");
	
}

void les9_1(){ 						// Пример использования
	
	initq();
	
	enqueue(1,51);
	enqueue(2,264);
	enqueue(4,24);
	enqueue(2,37);
	enqueue(6,489);
	enqueue(4,358);
	enqueue(8,695);
	enqueue(6,25);
	enqueue(1,2487);
	enqueue(7,89);
	
	peekq();
	
	for (int i = 0; i < 7; ++i){
		pq* n = dequeue();
		printf("pr = %d, dat = %d \n", n->pr, n->data);
	}
	
	peekq();
	
}

//---------------------------------------------------------------
// Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.

// Существительные

#define T char
#define DP 100						// размер
T Stack[DP];						// Стек(массив заданного размера)
int cursor = -1;					// текущее число элементов

// действия

int push(T data){ 			// добавление элемента
	
	if (cursor < DP){
		Stack[++cursor] = data;
		return 1;
	} else{
		printf("%s \n", "Stack overflow");
		return 0;
	}
	
}

T pop(){					// удаление элемента
	
	if (cursor != -1){
		return Stack[cursor--];
	} else{
		printf("%s \n", "Stack is empty");
		return -1;
	}
}

void les9_2(){
	
	int num = 15;
	
	for (int i = num; i > 0; i /= 2 )
		push(i % 2);
	
	while (cursor > -1){
		printf("%d", pop());
	}
	
}


int main(int args, const char** argv){
	
	les9_1();
	
	les9_2();
	return 0;
}