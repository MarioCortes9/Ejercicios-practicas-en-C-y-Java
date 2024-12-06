/* 
 Ignacio Barrio Escudero (757235)
 Mario Cortes Cantin (869493)
 Nombre:pi.cpp
 Fecha: 7 de Marzo de 2023
 Descripcion: Calcular sumatorio de Leibniz mediante serie con el numero
 de terminos requerido.
*/
 #include <iostream>
 #include <iomanip>
 
 using namespace std;
 int main(){
     
 int terminos;
 float pi=0, suma=0;
 do{
	cout <<"Introduzca el numero de terminos(>= 1):";
    cin>>terminos;
 }while(terminos<1);
 float signo =1 ;
 for(int i = 0;i<terminos;i++){
   
	    suma=signo/((2*i)+1); /* estos 3 pasos se realizan para completar
	    el sumatorio del enunciado*/
	    pi=pi+suma;
	    signo=signo*(-1); 
   }
	cout<<"Numero pi aproximado con:"<<terminos<<"terminos:"<<fixed<<
    setprecision(6)<<pi*4;
    
     return 0;
 }
