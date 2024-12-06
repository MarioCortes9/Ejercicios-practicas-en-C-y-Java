program sudoku;
{
* marcos algás sancho 821089
* mario cortes cantin 869493 
* 20/12/2023 sudoku}

//APARTADO A

const

	N = 9; //CREAMOS UNa constante para referirnos al numero de filas y columnas
    
type

	tpSudoku = array[1..N,1..N] of char;//tamañao matriz
    
//APARTADO B

procedure leerSudoku(var nombrefichero:string;var sudoku:tpSudoku); 

var
    filas,columnas: integer;
    fichero: text; 
    letra: char;
    
begin

    write('Introduzca el nombre de fichero a leer:');//interaccion
    readln(nombrefichero);
    assign(fichero,nombrefichero);
    reset(fichero);
    
    while not eoln(fichero) do
        read(fichero,letra);
        readln(fichero);
    while not eoln(fichero) do
        read(fichero,letra);
        readln(fichero);
    
    while not eof(fichero) do
    begin
        for filas:= 1 to N do
        for columnas:= 1 to N do
            read(fichero,sudoku[filas,columnas]);
    end;
    close(fichero);
end;

//APARTADO C

procedure escribirSudoku(var nombrefichero:string;var sudoku:tpSudoku);

var
    fichero1: text;
    filas,columnas: integer;
    
begin

    write('Introduzca el nombre de fichero a escribir:');//interaccion
    readln(nombrefichero);
    assign(fichero1,nombrefichero);
    rewrite(fichero1);
    
     begin
        for filas:= 1 to N do
        for columnas:= 1 to N do
            write(fichero1,sudoku[filas,columnas]);
     end;
     close(fichero1);
end;

//APARTADO D

procedure escribirDigito(var sudoku:tpSudoku;digito:integer;f,c:integer);

var
	x,y,z,t: integer;
	m,n: boolean;
    
begin

	m:= true;
	n:= true;
	z:= 1;t:= 1;
    
	for x:= 1 to 9 do
	begin
		if(sudoku[f,z] = chr(digito)) then 
			m:= false
            
		else
        
		begin
			z:= z + 1;
			m:= true;
		end;
	end;
    
	for y:= 1 to 9 do
     
	begin
		if (sudoku[t,c] = chr(digito)) then
			n:= false
            
		else
        
		begin
			t:= t + 1;
			n:= true;
		end;
	end;
    
	if m and n then 
		writeln('Digito almacenado.')
	else if not m or n then//si no corresponde a m o n no sera valida
		writeln('No es valido.');
end;

//APARTADO E PROGRAMA PRIMCIPAL

var
	fichero1,fichero2: string;
    sudoku1: tpSudoku;
    digito,f,c: integer;
    
begin

    leerSudoku(fichero1,sudoku1);
    escribirSudoku(fichero2,sudoku1);
    
    write('Introduce digito, fila y columna:');//interaccion final
    read(digito);
    read(f);
    read(c);
    escribirDigito(sudoku1,digito,f,c);
end.
