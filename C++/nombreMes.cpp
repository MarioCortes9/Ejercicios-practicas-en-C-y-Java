/* 
 Ignacio Barrio Escudero (757235)
 Mario Cortes Cantin (869493)
 Nombre:nombreMes.cpp
 Fecha: 7 de Marzo de 2023
 Descripcion: introducir un numero de mes y que se muestre el numero de mes 
 correspondiente
*/
#include<iostream>
using namespace std;

int main(){
    int num;
            cout<<"Introducir un mes valido entre el 1 y el 12:";
        cin>>num;
    switch(num){
    /*el comando switch se emplea para producir un valor numerico concreto y 
    casarlo con los meses(case) */   
    case 1:
            cout<<"El mes introducido es enero:";
    break;
    /* el comando break finaliza la ejecución del bucle o la instrucción 
       condicional*/
    case 2:
            cout<<"El mes introducido es febrero:";
    break;
    case 3:
            cout<<"El mes introducido es marzo:";
    break;
    case 4:
            cout<<"El mes introducido es abril:";
    break;
    case 5:
            cout<<"El mes introducido es mayo:";
    break;
    case 6:
            cout<<"El mes introducido es junio:";
    break;
    case 7:
            cout<<"El mes introducido es julio:";
    break;
    case 8:
            cout<<"El mes introducido es agosto:";
    break;
    case 9:
            cout<<"El mes introducido es septiembre:";
    break;
    case 10:
            cout<<"El mes introducido es octubre:";
    break;
    case 11:
            cout<<"El mes introducido es noviembre:";
    break;
    case 12:
            cout<<"El mes introducido es diciembre:";
    break;
    default:
            cout<<"ERROR: El mes introducido no es valido." << endl;
    
    
    
    
    
    
    
 }   
    return 0;
}
