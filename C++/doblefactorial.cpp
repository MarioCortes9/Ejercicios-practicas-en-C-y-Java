/* 
 Ignacio Barrio Escudero (757235)
 Mario Cortes Cantin (869493)
 Nombre:doblefactorial.cpp
 Fecha: 7 de Marzo de 2023
 Descripcion:Programa que calcule el doble factorial de un
 numero n impar dado por el usuario
*/
 
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    
    int num;
	    cout<<"Introduzca un numero (impar y positivo):";
	cin>>num;
    do
    {
	    cout << "Introduzca un numero (impar y positivo): ";
	cin>>num;
    }while((num%2 == 0) || (num<0));
	/*si la condición del while se cumple 	
			no hace la operacion del factorial
			y vuelve al "do"*/
    {
    for(int i=num; i<num; i= (2*i-1)) //no te fijes en esto que está mal
	{
	    cout<<""<<num<<"!!:"<<num;
	}
    }
	
    
    
    
    
    
    
    
   ; return 0;

}
