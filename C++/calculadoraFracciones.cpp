/* 
 Ignacio Barrio Escudero (757235)
 Mario Cortes Cantin (869493)
 Nombre:calculadoraFracciones.cpp
 Fecha: 7 de Marzo de 2023
 Descripcion: Programa que solicite cuatro valores enteros que
representan los numeradores y denominadores de 2 fracciones.
*/
 #include <iostream>
 #include <cmath>
 #include <iomanip>
 using namespace std;
 
 int main(){
     int a,b; /*primera fraccion*/
     int c,d; /*segunda fraccion*/
     char operador;
               cout<<"Introuce numerador y denominador de primera fraccion:";
          cin>>a>>b;
     if(b==0){ /*si denominador es 0 fraccion no valida*/
          cout<<"Alguna fraccion introducida no es valida:";
     }else{
               cout<<"Introduce numerador y denominador segunda fraccion:";
          cin>>c>>d;}
     if(d==0){
               cout<<"Alguna fraccion introducida no es valida:";
     }else{
               cout<<"Introduce una operacion valida(+,-,*,/):";
          cin>>operador;
     if((operador == '+')||(operador=='-')||(operador=='*')||(operador=='/')){
     if(operador== '+'){
               cout<<((a*d)+(c*b))<<"/"<<(b*d);
    }else{
     if(operador=='-'){
               cout<<(a*d)-(c*b)<<"/"<<(b*d);
     }else{
     if(operador=='*'){
               cout<<(a*c)<<"/"<<(b*d);
     }else{
     if(operador=='/'){
               cout<<(a*d)<<"/"<<(b*d);
               
               
                                   }
                         }
             }
               }
     }else{
         
         
          cout<<"ERROR operacion no valida:";
                         }
                    }
                    
} 

