#include <iostream>
#include <iomanip>


using namespace std;

    
    bool esPrimo(int num){
	if (num <=2){
    return true;
    
    }else{
	int divisor=2;
     while(num%divisor!=0){
				    divisor++;}
if (divisor==num){
	return true;
}else{   /* si n es primo aparece el return true pero en cambio sin este numero no lo es aparece el false*/
	return false;
	    }
 }
}

int main (){
int num;

	do{
	    cout<<"Introduzca un numero positivo:";/*interaccion sugerida*/
	    cin>>num;
 }  while(num<=0);
	if(esPrimo(num)){
	    cout<<num<<"No se puede expresar como la suma de dos numeros primos:"; /*interaccion 2*/
	}else{
	for (int x=1;x<=num/2;x++){
	    for (int y=num-1;y>=num/2;y--){
		if(esPrimo(x)&&esPrimo(y)&& x+y==num){
			cout<<num<<"="<<x<<"+"<<y<<endl;
		}
	      }
	     }
    return 0;
 }
}
