/*
Ignacio Daniel Barrio Escudero(757235)
Mario Cortes Cantin(869493)
Nombre: mediciones.cpp
Fecha : 25 de abril de 2023
Descrip.:Se trata de un programa que genera mediciones aleatorias y calcula de
las siguientes,la media y la desviación de velocidades y temperaturas.
*/
 #include <iostream>
  #include <vector>
    #include <cmath>
      #include <ctime>
        #include <iomanip>
 using namespace std;

 struct tpMedicion{ /* definimos el tpmedicion*/
    float velocidad; /* mm/seg*/
    float temperatura; /* Cº */
 };
 
 
 
 void pideMediciones(int &longitud){ /* pedimos las mediciones del enunciado*/
  do{
      cout << "Introduce el numero de mediciones a generar (de 3 a 15): ";
        cin>>longitud; /* esperamos que estas mediciones ocurran durante el intervalo de longitud por ello:*/
    }while(longitud <3||longitud >15);
}
 
 
 void inicializar(int longitud,vector<tpMedicion> &v1){
  for(int i=0; i<longitud;i++){
    v1[i].velocidad= 1+((double)rand()/RAND_MAX)*9; /* intervalo de las velocidades*/
      v1[i].temperatura= 15+((double)rand()/RAND_MAX)*5; /*intervalo temperaturas de medicion*/
  }
};
 
 
 void mostrar(int longitud,vector<tpMedicion> v1){
      cout<<"Vector de mediciones(velocidad,temperatura):"<<endl;
  for(int i=0; i<longitud;i++){
        cout<<"Medicion"<<fixed<<setprecision(2)<<i + 1<<": ( "<<
          v1[i].velocidad<<", "<< v1[i].temperatura<<" )"<<endl;
  } /*este paso sirve para mostrar correctamente el valor de las mediciones con los 2 decimales*/
      cout<<endl;
};
 
 
void estadisticas(int longitud,vector<tpMedicion> v1,tpMedicion &med /*media*/ ,tpMedicion
&desv /*desviacion*/ ){
      med.velocidad= 0.0;
        med.temperatura= 0.0;
      desv.velocidad= 0.0;
        desv.temperatura= 0.0;
  for(int i=0; i<longitud;i++){
      med.velocidad= med.velocidad+v1[i].velocidad;
        med.temperatura= med.temperatura+v1[i].temperatura; /*suma de todas las temperaturas*/
}
    med.velocidad= med.velocidad/v1.size(); /* dividimos la suma de elementos entre la cantidad de los mismos en el vector*/
      med.temperatura= med.temperatura/v1.size();
  for(int i =0; i<longitud;i++){
    desv.velocidad= desv.velocidad+((v1[i].velocidad-med.velocidad)*(v1[i].velocidad-med.velocidad)); /* calculo de la suma de las diferencias entre las velocidades de las mediciones(v1) y la media de las velocidades(med)*/
      desv.temperatura= desv.temperatura+((v1[i].temperatura-med.temperatura)*(v1[i].temperatura-med.temperatura));
} 
    desv.velocidad= sqrt(desv.velocidad/v1.size());
      desv.temperatura= sqrt(desv.temperatura/v1.size()); /* calculamos la desviacion mrdiante la raiz cuadrada de la desviacion entre la cantidad que tenemos*/
      /*en estas ultimas filas hemos realizado todos los calculos para las medias y desviaciones a calcular para obtener bien el jercicio*/
};
 
 
void mostrarEstadisticas(int longitud,vector<tpMedicion> v1,tpMedicion &med,
tpMedicion &desv){
  cout <<"Estadisticas de las mediciones:"<<endl;
    estadisticas(longitud,v1,med,desv);
      cout <<"Media de velocidades:"<<med.velocidad<<endl;
        cout <<"Media de temperaturas:"<<med.temperatura<<endl;
          cout <<"Desviacion de velocidades:"<<desv.velocidad<<endl;
              cout <<"Desviacion de temperaturas:"<<desv.temperatura<<endl;
 /*cargamos todos las interacciones esperadas segun los datos*/
};
 
 
int main (){ /*ahora vamos a declarar todas las variables en el int main*/
 tpMedicion med,desv;
  srand(time (0)); /* comando para generar los resultados que hace que cada vez que ejecute genere resultados aleatorios*/
    int longitud;
      pideMediciones(longitud);
        vector<tpMedicion> v1(longitud);
          inicializar(longitud,v1);
            mostrar(longitud,v1);
              mostrarEstadisticas(longitud,v1,med,desv);
  return 0;
}

