#include <stdio.h>

//---------------------------------------------------------------

void dectobin(int n){
	
	if ( n < 2 )
		printf("%d", n);
	else {
		dectobin(n/2);
		printf("%d", n%2);
	}
}

//---------------------------------------------------------------

long int rdegree(int n, int d) {
	if (d>0) 
		return n * rdegree(n, d-1);
	else return 1;
}

long int degree(int n, int d){
	long int k=1;
	while(d>0){	
		k *= n;
		d--;
	}
	return k;
}

long int altdegree(long int n, int d){
	
	if (d==1) 
		return n;
	else{
		if ( d % 2 != 0)
			return n * altdegree(n, d-1);
		else 
			return altdegree(n*n, d/2);
	}
}

int task(int *n, int *d){
	
	printf("  Enter number = ");
	fflush(stdout);
	fflush(stdin);
	scanf("%i", n);
	
	fflush(stdin);
	do{
		printf("  Enter degree(>0) = ");
		fflush(stdout);
		scanf("%i", d);
	}while( *d < 0);
	
	return 0;
}

void Expon(int i){
	
	int n, d;
	long int k=1;
	task( &n, &d);
	
	switch(i){
		case 1:{
			k = degree(n,d);
			break;
		}
		
		case 2:{
			k = rdegree(n,d);
			break;
		}
		
		case 3:{
			k = altdegree(n,d);
			break;
		}
	}
	printf("  %d^%d = %d", n, d, k);
	
}

//---------------------------------------------------------------

	
const int sizex = 8;
const int sizey = 8;

int desk[8][8] = {0}; // пустое поле

int move(int x, int y){
	
	if ( (( x==0 ) && ( y==0 )) || ( desk[x][y]!=0 ) ) 
		return 0;		
	else if ( ( ( x<0 ) ^ ( y<0 ) ) || ( ( x-1<0 ) ^ ( y-1<0 ) ) ) 
		return 1;
	else if (( x-1==0 ) && ( y-1==0 ))
		return move(x-1,y) + move(x,y-1) + 1;
	else
		return move(x-1,y) + move(x,y-1) + move(x-1,y-1);
	
}

void ChessKing(){
	
	desk[1][3]=1; // препятствия
	desk[5][4]=1;
	desk[3][6]=1;
	
	for(int y = 0; y < sizey; ++y){
		for (int x = 0; x < sizex; ++x){
			printf("%6d", move(x,y));
			
		}
		printf("\n");
	}
	
	
}

//---------------------------------------------------------------

int main(int args, const char** argv){
	
	if(args>1){  // при вызове программы необходимо указать номер функции через пробел
		switch(argv[1][0]){
			
			case '1':{  
				printf( "-------------------------------------------------\n"
						"   Сonverting a number from decimal to binary\n"
						"-------------------------------------------------\n");
				int n, o;
				printf("  Enter number = ");
				fflush(stdout);
				fflush(stdin);
				scanf("%i", &n);
				printf("  Dec = %d | Bin = ", n);
				dectobin(n);
				break;
			}
				
			case '2':{
				printf( "-------------------------------------------------\n"
						"                  Exponentiation\n"
						"-------------------------------------------------\n");
						
				Expon(1);
				
				break;
			}
			
			case '3':{
				printf( "-------------------------------------------------\n"
						"              Recursive exponentiation\n"
						"-------------------------------------------------\n");
				
				Expon(2);
				
				break;
			}
			
			case '4':{
				printf( "-------------------------------------------------\n"
						"        Alternative recursive exponentiation\n"
						"-------------------------------------------------\n");
						
				Expon(3);
				
				break;
			}
			
			case '5':{
				printf( "-------------------------------------------------\n"
						"                   Chess king\n"
						"-------------------------------------------------\n");
				
				ChessKing();
				
				break;
			}
			
			default:printf("  Undefined call");			
			
		}
	} else{
		printf("  Wrong call");
	}
		
	return 0;
}