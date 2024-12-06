{
* marcos algás sancho 821089
* mario cortes cantin 869493 
* 20/12/2023 generaFichero}

program generaFichero;

type

    tpFicheroReal = file of real;

var
    ficheReal:tpFicheroReal;
    valor : real;

begin 

    assign ( ficheReal,'velocidades.dat');
    rewrite (ficheReal);
    write ('Introduce secuencia de velocidades registradas por el anemometro: ');

    while not eoln do 
begin

    read(valor);
    write (ficheReal,valor);

end;

    close (ficheReal);
    write('Fichero velocidades.dat creado con exito.');

end.
