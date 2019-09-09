/*
** hw4_lib.c:
**
** The source file implementing library functions.
**
** Author: Yakup Genc. (c) 2018
**
** Revision: 2018.03.27.08.19
** 
*/

#include "hw4_lib.h"

double integral(double f(double x), double xs, double xe, double delta){
	
	int i;
	double x;
	double alan_toplam=0;
	double parca=(xe-xs)/delta;
	for(i=0; i<delta; i++){
		x = xs+i*parca;
		alan_toplam += f(x)*parca;
		/*fonksiyonun altýnda kalan alaný delta kadar dikdortgene boler
		*bu dýkdortgenlerýn her býrýnýn ený parca degiskeni uzunlugunda
		*uzunlugu ise dikdortgenin sol kosesinin orijine olan x uzaklýgýnýn f(x) fonksiyonunun
		*icine yazilmasi ile bulunur.Bu delta kadan dikdortgenin alanlarý toplami fonksiyonun
		*integralini verir.
		*/
	}
	return alan_toplam;
	
}

double integral2(double f(double x, double y), double xs, double xe, double ys, double ye, double delta){

	

}

int derivatives(double f(double a), double x, double eps, double * d1, double * d2){
	

	if(eps==0){
		return -1;
	}
	else{
		
		*d1=(f(x+eps)-f(x-eps))/(2*eps);
		
		*d2=(f(x+eps)-2*f(x)+f(x-eps))/(eps*eps);
		
		return 1;
		
	}
	
	
}

int compare_derivatives(double f(double a), double d1(double b), double d2(double b), double x, double eps, double * e1, double *e2){
	
	
}


int find_roots(double f(double x), double * x1, double * x2, double * x3, double * x4){
	
	
}
