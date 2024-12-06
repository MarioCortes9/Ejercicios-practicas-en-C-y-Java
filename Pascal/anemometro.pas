{
* marcos algás sancho 821089
* mario cortes cantin 869493 
* 20/12/2023 anemometro}

program anemometro;

var 
    valor: real;
    entrada , salida : file of Real ;
    suma: real;
    contador:integer;

begin

    assign (entrada, 'velocidades.dat');
    reset(entrada);
    assign (salida, 'velocidadesfiltradas.dat');
    rewrite(salida);

    contador:=0;
    suma:=0;

while not eof(entrada) do begin
    read(entrada,valor);

    suma:= suma+valor;
    contador:= contador+1;

if contador = 3 then begin 
    write(salida,suma/3);
    suma:= suma - valor;
    contador:= contador-1;
end;
end;

    close (entrada);
    close(salida);

    writeln('Fichero velocidadesfiltradas.dat creado con exito.')
end.
