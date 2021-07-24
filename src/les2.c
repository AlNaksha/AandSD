#include <stdio.h>


int issimple(long long n){
	
	
	if(n > 0){
		int j = 0; // инкримент итерации
		long long i = 0;
		int t; // 1 - простое, 0 - натуральное
		if (n > 3){
			
			if( n % 2 != 0){
				
				for (i = 3; i*i < n; i+= 2) {
					
					if (n % i == 0) {
						t = 0;
						break;
					}	 
					j++;
				}
				
				
				if( i*i > n ){
					t = 1;
				} else t = 0;
				
				
			} else t = 0;
			
			
		} else if (n > 0){
			t = 1;
		}	
		
		printf("Number of iterations = %i; NOD = %d\n", &j, &i);
		if (t){
			return 1;
		} else{
			return 0;
		}
		
		
	} else{
		printf("number < 0\n");
		return 0;
	}
	printf("\n");
	
	return 1;
}


int main () {
	
	long long n;
	printf("Input number = ");
	scanf("%d",&n);
	printf("\n");
	
	if (issimple(n)) printf("Simple\n");
	else printf("Natural\n");
	
	return 0;
}