/*
** hw4_io.c:
**
** The source file implementing input and output functions.
**
** Author: Yakup Genc. (c) 2018
**
** Revision: 2018.03.27.08.19
** 
*/


#include "hw4_io.h"

int read_polynomial3(double * a0, double * a1, double * a2, double * a3){
	
	double sifir,bir,iki,uc;
	
	scanf("%lf",&sifir);
	scanf("%lf",&bir);
	scanf("%lf",&iki);
	scanf("%lf",&uc);
	
	*a0=sifir;
	*a1=bir;
	*a2=iki;
	*a3=uc;
	
	return 0;
}

int read_polynomial4(double * a0, double * a1, double * a2, double * a3, double * a4){

	double sifir4,bir4,iki4,uc4,dort4;
	
	scanf("%d",&sifir4);
	scanf("%d",&bir4);
	scanf("%d",&iki4);
	scanf("%d",&uc4);
	scanf("%d",&dort4);
	
	*a0=sifir4;
	*a1=bir4;
	*a2=iki4;
	*a3=uc4;
	*a4=dort4;
	
	return 0;
}

void write_polynomial3(double a0, double a1, double a2, double a3){
	
	if(a0>0){
		if(a0==1){
			printf("x^3");
		}
		else{
			printf("%dx^3",a0);
		}
		
	}
	else if(a0<0){
		printf("%dx^3",a0);
	}
	
	if(a1>0){
		if(a1==1){
			printf("+x^2");
		}
		else{
			printf("+%dx^2",a1);
		}
		
	}
	else if(a1<0){
		printf("%dx^2",a1);
	}
	
	if(a2>0){
		if(a2==1){
			printf("+x");
		}
		else{
			printf("+%dx",a2);
		}
		
	}
	else if(a2<0){
		printf("%dx",a2);
	}
	
	if(a3>0){
		printf("+%d",a2);
	}
	else if(a3<0){
		printf("%d",a2);
	}
	
}

void write_polynomial4(double a0, double a1, double a2, double a3, double a4){
	
	if(a0>0){
		if(a0==1){
			printf("x^4");
		}
		else{
			printf("%dx^4",a0);
		}
		
	}
	else if(a0<0){
		printf("%dx^4",a0);
	}
	
	if(a1>0){
		if(a1==1){
			printf("+x^3");
		}
		else{
			printf("+%dx^3",a1);
		}
		
	}
	else if(a1<0){
		printf("%dx^3",a1);
	}
	
	if(a2>0){
		if(a2==1){
			printf("+x^2");
		}
		else{
			printf("+%dx^2",a2);
		}
		
	}
	else if(a2<0){
		printf("%dx^2",a2);
	}
	
	if(a3>0){
		if(a3==1){
			printf("+x");
		}
		else{
			printf("+%dx",a3);
		}
		
	}
	else if(a3<0){
		printf("%dx",a2);
	}
	
		
	if(a4>0){
		printf("+%d",a4);
	}
	else if(a4<0){
		printf("%d",a4);
	}
}
