#include <iostream>

using namespace std;

int siguienteDigito(int &num){/*primera de todas porque la utilizan ambas*/
    int digito =num%10;
	num=num/10;
	    if(digito==0&&num==0){  /*parametros enunciado*/
		digito=-1; /* en caso de que num sea 0 devolvera el valor a -1*/
	    }
    return digito;
}

int sumaDigitos(int x){
    int digito, suma=0;
	digito = siguienteDigito(x);
    do{
	    suma=suma+digito;
	    digito = siguienteDigito(x);
    }
    while (digito!=-1); /* funcion devuelve valor -1 (digito)*/
	return suma;/*devuelve el parametro suma*/
}

 int multiplicaDigitos( int x){  
     int multiplicacion = 1, digito;
	digito=siguienteDigito(x);
    do{
	multiplicacion=multiplicacion*digito;
	digito= siguienteDigito(x);
    }
    while(digito!=-1); /*mismos pasos que en sumaDigitos*/
	return multiplicacion;
}

int main(){
    int a,b,multiplicacion,suma;
	cout<<"Introduce valores para intervalo [a,b];";
	cin>>a>>b;
    while(a>b){
	cout<<"Error! El intervalo no es valido:";
	cout<<"Introduce valores para intervalo [a,b];";
	cin>>a>>b;
    }
    cout<<"Numeros espia en el intervalo[a,b]:=";/*interacciones esperadas*/
	for( int x=a;x<=b;x++){
	    suma= sumaDigitos(x);
	    multiplicacion=multiplicaDigitos(x); /*dado enunciado para estos parametros pasa x*/
	if(suma==multiplicacion){
	    cout<<x<<' ';
	}
    }
    return 0;
}
