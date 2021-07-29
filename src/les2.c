#include <stdio.h>


int issimple(long int n){ // проверка на простоту подаваемого числа (результат "1" - простое, "0" - натуральное, "-1" - целое)
	
	if(n > 0){ // простые числа не имеют знака
		
		switch(n%10){
			
			case 1:
			case 3:
			case 7:
			case 9:{
				
				int j = 0; // инкримент итерации
				for ( long int i = 3 ; i < n/i ; i = i + 2) { // то можно с шагом 2 идти до корня из n 
					
					// printf("\n%d || %d | %d | %d | %d\n", j, n, i, n/i, n%i); // 
					
					if (n%i == 0) { // в поисках числа на которое делится число n
						// printf("Number of iterations = %i; NOD = %d | %d\n", j, i, n%i);
						return 0; // если число найдено то выходим из цикла и функции со значением 0
					}	 
					
					j++; // счетчик вхождения в цикл
				}
				
				return 1;
			}
			default:
			
				if ( ( n == 2 ) || ( n == 5 ) ) return 1;
				else return 0;
				
		}
		
	} else{
		return -1;
	}
	
	return 0;
}


int main () {
	
	printf("Input number = ");
	fflush(stdout);
	long int n;
	scanf("%ld",&n);
	
	// printf("\n%d\n", 3%10);
	
	if (issimple(n)>0) {printf("Simple\n");}
	else printf("Integer\n");
	
	return 0;
}