#include <iostream>
#include <iomanip>

using namespace std;

void pedirNumeros(float &a, float &b, float&c){
    cout<<"Introduce tres numeros reales:";
	cin>>a>>b>>c;
}; /*pides 3 numeros reales*/

void intercambiarNumeros(float &n1 , float &n2){
    float aux = n1;
	n1= aux; /*nombrar variables*/
	    n2=n1;
		aux = n2;
};

void ordenarNumeros(float &a, float &b, float &c){
    if(a>b && b>c){
}else if(b>a && a>c){
    intercambiarNumeros(a,b);
}else if (b>c && c>a){
    a=b;
	b=c;
	    c=a;
}else if (a>c && c>b){
    intercambiarNumeros(b,c);
}else if (c>a && a>b){
    a=c;
	b=a;
	    c=b;
}else if ( c>b && b>a){
    intercambiarNumeros(a,c);
    }    
};    
       
    
void mostrarNumeros(float a, float b, float c){
    cout<<"Valores de los numeros:";
    cout<<scientific<<a<<'\t'<<b<<'\t'<<c<<endl;
} /* para dar valor a los numeros que seran mostrados por pantalla*/
    
int main(){
    float a,b,c;
	pedirNumeros(a,b,c);
	    ordenarNumeros(a,b,c);
		mostrarNumeros(a,b,c);
    /*para cargar los diferentes casos empleados*/
    return 0;
}
    
    
    
    

