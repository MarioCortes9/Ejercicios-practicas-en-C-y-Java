import javax.swing.*;
import java.util.Random;
import java.util.Scanner;

public class Main {

    private static int MAX_DIMENSION = 10;
    private static String[][] tablero1 = new String[MAX_DIMENSION][MAX_DIMENSION];
    private static String[][] tablero2 = new String[MAX_DIMENSION][MAX_DIMENSION];

    private static int FilaAl, ColumnaAl;

    private static int filaA, columnaA;
    private static int filaB, columnaB;

    private static Random al = new Random();
    private static Scanner sc = new Scanner(System.in);

    private static int vidas1 = 3;
    private static int vidas2 = 3;


    public static void inicializarTablero(String[][] tablero) {
        for (int i = 0; i < MAX_DIMENSION; i++) {
            for (int j = 0; j < MAX_DIMENSION; j++) {
                tablero[i][j] = ".";
            }
        }
    }

    private static void rellenarPersonajes(String[][] tablero, String personaje, int cantidad) {
        for (int i = 0; i < cantidad; i++) {
            int fila, columna;
            do {
                fila = al.nextInt(MAX_DIMENSION);
                columna = al.nextInt(MAX_DIMENSION);
            } while (tablero[fila][columna] != ".");

            if (personaje.equals("A")) {
                filaA = fila;
                columnaA = columna;
            }
            if (personaje.equals("B")) {
                filaB = fila;
                columnaB = columna;
            }
            tablero[fila][columna] = personaje;
        }
    }

    private static void imprimirTablero(String[][] tablero) {
        for (int i = 0; i < MAX_DIMENSION; i++) {
            for (int j = 0; j < MAX_DIMENSION; j++) {
                System.out.print(tablero[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void jugar(String[][] tablero, String personaje, String enemigo, String muro) {
        int fila = 0;
        int columna = 0;

        if (personaje.equals("A")) {
            fila = filaA;
            columna = columnaA;
        } else if (personaje.equals("B")) {
            fila = filaB;
            columna = columnaB;
        }

        String movimiento;
        System.out.println("Dime un desplazamiento WASDQEZC");
        movimiento = sc.nextLine().toUpperCase();

        switch (movimiento) {
            case "W":
                //INFINITO
                tablero[fila][columna] = ".";
                if (fila == 0) {
                    fila = MAX_DIMENSION - 1;
                } else {
                    fila--;
                }

                if (tablero[fila][columna].equals("E")) {
                    if (personaje.equals("A")) {
                        vidas1--;
                    } else {
                        vidas2--;
                    }

                    //MURO

                } else if (tablero[fila][columna].equals("M")) {
                    System.out.println("No se puede pasar, hay un muro");
                    fila = (fila + 1) % MAX_DIMENSION; // Restaurar posición
                }

                //ACTUALIZAR POSICION

                tablero[fila][columna] = personaje;

                break;
            case "A":
                //INFINITO
                tablero[fila][columna] = ".";
                if (columna == 0) {
                    columna = MAX_DIMENSION - 1;
                } else {
                    columna--;
                }

                if (tablero[fila][columna].equals("E")) {
                    if (personaje.equals("A")) {
                        vidas1--;
                    } else {
                        vidas2--;
                    }

                    //MURO

                } else if (tablero[fila][columna].equals("M")) {
                    System.out.println("No se puede pasar, hay un muro");
                    columna = (columna + 1) % MAX_DIMENSION; // Restaurar posición
                }

                //ACTUALIZAR POSICION

                tablero[fila][columna] = personaje;
                break;


            case "S":
                //INFINITO
                tablero[fila][columna] = ".";
                if (fila == MAX_DIMENSION - 1) {
                    fila = 0;
                } else {
                    fila++;
                }

                if (tablero[fila][columna].equals(enemigo)) {
                    if (personaje.equals("A")) {
                        vidas1--;
                    } else {
                        vidas2--;
                    }

                    //MURO

                } else if (tablero[fila][columna].equals(muro)) {
                    System.out.println("No se puede pasar, hay un muro");
                    fila = (fila - 1 + MAX_DIMENSION) % MAX_DIMENSION; // Restaurar posición
                }

                //ACTUALIZAR POSICION

                tablero[fila][columna] = personaje;
                break;


            case "D":
                //INFINITO
                tablero[fila][columna] = ".";
                if (columna == MAX_DIMENSION - 1) {
                    columna = 0;
                } else {
                    columna++;
                }

                if (tablero[fila][columna].equals("E")) {
                    if (personaje.equals("A")) {
                        vidas1--;
                    } else {
                        vidas2--;
                    }

                    //MURO

                } else if (tablero[fila][columna].equals("M")) {
                    System.out.println("No se puede pasar, hay un muro");
                    columna = (columna - 1 + MAX_DIMENSION) % MAX_DIMENSION; // Restaurar posición
                }

                //ACTUALIZAR POSICION

                tablero[fila][columna] = personaje;


                break;

            case "Q":
                // MOVER HACIA ARRIBA-IZQUIERDA (INFINITO)
                tablero[fila][columna] = ".";
                if (fila == 0) {
                    fila = MAX_DIMENSION - 1;
                } else {
                    fila--;
                }
                if (columna == 0) {
                    columna = MAX_DIMENSION - 1;
                } else {
                    columna--;
                }

                if (tablero[fila][columna].equals("E")) { // Enemigo
                    if (personaje.equals("A")) {
                        vidas1--;
                    } else {
                        vidas2--;
                    }
                } else if (tablero[fila][columna].equals("M")) { // Muro
                    System.out.println("No se puede pasar, hay un muro");
                    fila = (fila + 1) % MAX_DIMENSION; // Restaurar posición
                    columna = (columna + 1) % MAX_DIMENSION;
                }

                // ACTUALIZAR POSICIÓN
                tablero[fila][columna] = personaje;
                break;

            case "E":
                // MOVER HACIA ARRIBA-DERECHA (INFINITO)
                tablero[fila][columna] = ".";
                if (fila == 0) {
                    fila = MAX_DIMENSION - 1;
                } else {
                    fila--;
                }
                if (columna == MAX_DIMENSION - 1) {
                    columna = 0;
                } else {
                    columna++;
                }

                if (tablero[fila][columna].equals("E")) { // Enemigo
                    if (personaje.equals("A")) {
                        vidas1--;
                    } else {
                        vidas2--;
                    }
                } else if (tablero[fila][columna].equals("M")) { // Muro
                    System.out.println("No se puede pasar, hay un muro");
                    fila = (fila + 1) % MAX_DIMENSION; // Restaurar posición
                    columna = (columna - 1 + MAX_DIMENSION) % MAX_DIMENSION;
                }

                // ACTUALIZAR POSICIÓN
                tablero[fila][columna] = personaje;
                break;

            case "Z":
                // MOVER HACIA ABAJO-IZQUIERDA (INFINITO)
                tablero[fila][columna] = ".";
                if (fila == MAX_DIMENSION - 1) {
                    fila = 0;
                } else {
                    fila++;
                }
                if (columna == 0) {
                    columna = MAX_DIMENSION - 1;
                } else {
                    columna--;
                }

                if (tablero[fila][columna].equals("E")) { // Enemigo
                    if (personaje.equals("A")) {
                        vidas1--;
                    } else {
                        vidas2--;
                    }
                } else if (tablero[fila][columna].equals("M")) { // Muro
                    System.out.println("No se puede pasar, hay un muro");
                    fila = (fila - 1 + MAX_DIMENSION) % MAX_DIMENSION; // Restaurar posición
                    columna = (columna + 1) % MAX_DIMENSION;
                }

                // ACTUALIZAR POSICIÓN
                tablero[fila][columna] = personaje;
                break;

            case "C":
                // MOVER HACIA ABAJO-DERECHA (INFINITO)
                tablero[fila][columna] = ".";
                if (fila == MAX_DIMENSION - 1) {
                    fila = 0;
                } else {
                    fila++;
                }
                if (columna == MAX_DIMENSION - 1) {
                    columna = 0;
                } else {
                    columna++;
                }

                if (tablero[fila][columna].equals("E")) { // Enemigo
                    if (personaje.equals("A")) {
                        vidas1--;
                    } else {
                        vidas2--;
                    }
                } else if (tablero[fila][columna].equals("M")) { // Muro
                    System.out.println("No se puede pasar, hay un muro");
                    fila = (fila - 1 + MAX_DIMENSION) % MAX_DIMENSION; // Restaurar posición
                    columna = (columna - 1 + MAX_DIMENSION) % MAX_DIMENSION;
                }

                // ACTUALIZAR POSICIÓN
                tablero[fila][columna] = personaje;


                if (vidas1 <= 0) {
                    System.out.println("El personaje A ha perdido todas sus vidas. ¡Vader gana!");
                    // Finaliza el juego
                    break;
                } else if (vidas2 <= 0) {
                    System.out.println("El personaje B ha perdido todas sus vidas. ¡Yoda gana!");
                    // Finaliza el juego
                    break;
                }
                break;
        }
    }


        public static void main (String[]args){
            inicializarTablero(tablero1);
            inicializarTablero(tablero2);
            rellenarPersonajes(tablero1, "A", 1);
            rellenarPersonajes(tablero2, "B", 1);
            rellenarPersonajes(tablero1, "E", 3);
            rellenarPersonajes(tablero2, "E", 3);
            rellenarPersonajes(tablero1, "M", 5);
            rellenarPersonajes(tablero2, "M", 5);
            imprimirTablero(tablero1);
            System.out.println();
            System.out.println();
            imprimirTablero(tablero2);


            


        }

}