/*
Ignacio Daniel Barrio Escudero(757235)
Mario Cortes Cantin(869493)
Nombre: matrizTC.cpp
Fecha : 25 de abril de 2023
Descrip.:Pide dimensión al usuario y lee los valores 
introducidos,comprobando si la matriz es Toepliz.
Si lo es,informar al usuario que es Toepliz y comprobar si es
circulante.Si no es Toepliz también se informa.
*/
#include <iostream>
    #include <vector>
	#include <cstdlib>
	    #include <ctime>
/*cargamos los paquetes a utilizar*/

using namespace std;

int pideDimension(){ 
    int dimension;
	do{
		cout<<"Introduzca la dimension de la matriz:";
	    cin>>dimension;
	}while(dimension<1 || dimension>5); /*requisitos dimension */
    return dimension;
}


int rellenaMatriz(int &componente,int &i,int &j,vector<vector<int>> &matriz){
	do{
		cout<<"Introduzca componente("<<i<< ',' <<j<<"):";
	    cin >> componente;
	}while(componente<-3 || componente>3); /*intervalo matriz*/
    return componente;
}



void mostrarMatriz(int dimension,vector<vector<int>> &matriz){
    for(int i =0; i<dimension;i++){
	for(int y= 0; y<dimension;y++){
	    cout<<matriz[i][y]<< ' ';
	}
	    cout<<endl;
    }
}




bool esToepliz(int dimension,vector<vector<int>> matriz){
    bool toepliz=true;
	for(int i =0; i<dimension - 1;i++){
	    for(int y= 0; y< dimension - 1;y++){
		if(matriz[i][y]!= matriz[i + 1][y + 1]){
		    toepliz=false;
		} /* aqui se demuestran los calculos a seguir para ver si es true o false*/
	    }
	}
		    return toepliz;
}  /*En este caso miramos si la matriz es de toepliz lo cual te lo dira el bool mediante true o false */



bool esCirculante(int dimension,vector<vector<int>> matriz){
    bool circulante = true;
	int z,t;
	    for(int i =0; i<dimension;i++){
		z=(i + 1)%matriz.size();
	    for(int y= 0; y<dimension - 1;y++){
		t=(y + 1)%matriz[0].size();
	if(matriz[i][y]!= matriz[z][t]){
		circulante=false;
		    }
	    }
    }
		return circulante;
} /* devuelve true o false al igual que antes si la matriz cumple o no */




int main(){
    int componente;
	int dimension;
bool toepliz;
    bool circulante;
		dimension=pideDimension();
		    vector<vector<int>> matriz(dimension,vector<int> (dimension));
	for(int i =0; i<dimension;i++){
	for(int y= 0; y<dimension;y++){
		rellenaMatriz(componente,i,y,matriz);
		    matriz[i][y]=componente;
		}
	    }
		mostrarMatriz(dimension,matriz);
		    toepliz=esToepliz(dimension,matriz);
	if(toepliz){
		cout<<"La matriz dada es Toepliz!"<<endl;
		    circulante=esCirculante(dimension,matriz);
	if(circulante){
		cout<<"La matriz dada es circulante!";
	}else{
		cout<<"La matriz dada NO es circulante";
    }
	}else{
		cout<<"La matriz dada NO es de Toepliz"<<endl;
    }
	return 0;
} /* finalmente aqui caragmso toddos los casos posibles que tiene la matriz (circulante o no, de torpliz o no)


