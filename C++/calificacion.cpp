/* 
 Ignacio Barrio Escudero (757235)
 Mario Cortes Cantin (869493)
 Nombre:calificacion.cpp
 Fecha: 7 de Marzo de 2023
 Descripcion: Programa que solicite al usuario una nota numerica 
 perteneciente al intervalo [0.0, 10.0].
*/
#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    float nota;
            cout<<"Introduzca una nota numerica (entre 0.0 y 10.0):";
        cin>>nota;
    if (nota >= 0.0 && nota <= 10.0)
    {
            cout<<"La nota introducida es valida"<<endl;
    }
    else
    {
            cout<<"La nota introducida no es valida.";
    
    }
    if(nota<5.0){
            cout<<"La calificacion cualitativa obtenida es:SUSPENSO:";
    }
    
    else if((nota>=5.0)&&(nota<6.5)){
            cout << "La calificacion cualitativa obtenida es: APROBADO";
    }
    else if((nota >= 6.5) && (nota < 8)){
            cout << "La calificacion cualitativa obtenida es: BIEN";
    }
    else if((nota >= 8) && (nota < 9)){
            cout << "La calificacion cualitativa obtenida es: NOTABLE";
    }
    else{ 
            cout << "La calificacion cualitativa obtenida es: SOBRESALIENTE";
    if(nota >= 9.5){
            cout << " MATRICULA?";

}

}  return 0;
}
/* aparecen tantas enumeracion de else y de if debido a que tenemos varios casos
 de diferentes notas por lo cual estos son los comandos mas validos para
 este paso*/

 
 
 
 
 






















