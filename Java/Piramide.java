import java.util.Scanner;

public class Piramide {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            long bloques = scanner.nextLong();
            if (bloques == 0) break; // Termina al recibir 0

            int niveles = 0; // Contador de niveles
            long totalBloques = 0; // Suma total de bloques usados

            while (true) {
                // Cálculo del número de bloques necesarios para el siguiente nivel
                long bloquesParaNivel = (2 * niveles + 1) * (2 * niveles + 1);
                if (totalBloques + bloquesParaNivel > bloques) {
                    break; // Si no hay suficientes bloques, salir
                }
                totalBloques += bloquesParaNivel; // Sumar bloques al total
                niveles++; // Incrementar el contador de niveles
            }

            System.out.println(niveles); // Imprimir el número de niveles construidos
        }

        scanner.close(); // Cerrar el escáner
    }
}