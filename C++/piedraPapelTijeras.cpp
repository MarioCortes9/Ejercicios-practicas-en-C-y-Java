/* 
 Ignacio Barrio Escudero (757235)
 Mario Cortes Cantin (869493)
 Nombre:piedraPapelTijeras.cpp
 Fecha: 7 de Marzo de 2023
 Descripcion: Desarrolla un programa que permita jugar al juego de “piedra, 
 papel o tijeras”
*/
#include<iostream>
using namespace std;

int main(){
int jug1, jug2;
 bool si1, si2;
        cout << "Jugador 1: piedra(1) papel(2) o tijeras(3)? ";
    cin >> jug1;
    si1 = (jug1 >= 1 && jug1 <= 3);
 if(si1 == false)
 {
        cout << "ERROR: opcion elegida por el jugador 1 no valida";
 }
 else {
        cout << "Jugador 2: piedra(1) papel(2) o tijeras(3)? ";
    cin >> jug2;
    si2 = (jug2 >= 1 && jug2 <= 3);
 }
 if(si1 == true && si2 == false){
        cout << "ERROR: opcion elegida por el jugador 2 no valida";
 }
 if(si1 == true && si2 == true){
 if((jug1 == 1) && (jug2 == 3)){
        cout << "Ganador: JUGADOR 1" << endl;
 }
 else if((jug1 == 1) && (jug2 == 2)){
        cout << "Ganador: JUGADOR 2" << endl;
 }
 else if((jug1 == 2) && (jug2 == 1)){
        cout << "Ganador: JUGADOR 1" << endl;
 }
 else if((jug1 == 2) && (jug2 == 3)){
        cout << "Ganador: JUGADOR 2" << endl;
 }
 else if((jug1 == 3) && (jug2 == 2)){
        cout << "Ganador: JUGADOR 1" << endl;
 }
 else if((jug1 == 3) && (jug2 == 1)){
        cout << "Ganador: JUGADOR 2" << endl;
 }
 else if(jug1 == jug2){		
        cout << "EMPATE! nadie gana" << endl;
 }
 }
 return 0;
 }
/* primero hemos puesto las diferentes opciones para los jugadores y luego 
   para finalizar los diferentes casos que podrian aparecer y cual seria su 
   ganador dado "x" caso. */
