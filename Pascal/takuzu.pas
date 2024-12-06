program takuzu;
{
* marcos algás sancho 821089
* mario cortés cantín 869493
* 30/11/2023 takuzu}
//no puede haber ni fila ni columna con mas de dos del mismo color seguidas

const//primero de todo creamos dos constantes para el numero de filas y de columnas que tiene
    maxFIL=20;
    maxCOL=20;
type
    tpCasillas = record // creamos un registro en donde guardaremos los datos del tablero
	numCol : integer;
	numFil : integer;
	fichas : array [1..maxFIL,1..maxCOL] of char;
end;

procedure lecturaTablero(var tab{TABLERO}:tpCasillas);//procedimiento que se encarga de lerr dimensiones y fichas del tablero
var
    filas,columnas,x : integer;
    
begin
    write('Introduce lado del tablero:');//tamaño tablero 
    readln(x);
    tab.numFil := x;
    tab.numCol := x;
	write('Introduce las fichas:');//pedir fichas
	for filas := 1 to tab.numFil do
	for columnas := 1 to tab.numCol do
	read(tab.fichas[filas,columnas]);//almacena ficha en su posicion del tablero dada la fila y columna
end;

procedure cumplicionReglas(var matriz:tpCasillas);//PROCEDIMIENTO PARA CUMPLICION REGLAS ENUNCIADO
var
    x,y,fallofil,fallocol:integer;//creamos fallofil y fallocol para numerizar los fallos en columnas y filas
begin
    fallofil := 0;//contador fallofil
    fallocol := 0;//contador fallocol
    //proceso fallos en filas
    for x := 1 to matriz.numFil do
    for y := 1 to (matriz.numCol-2) do //Verifica si hay tres fichas seguidas iguales en la misma fila
	if (matriz.fichas[x,y]{POS1} = matriz.fichas[x,y+1]){POS2} and (matriz.fichas[x,y+1]{POS2} = matriz.fichas[x,y+2]{POS3}) then//comprobar si las tres seguidas son iguales Y ASI SER INCORRECTO
	    begin 
		writeln('Fila ',x,' es incorrecta');
		fallofil := fallofil+1;//si es incorrecta suma los fallos
	    end;
    //proceso fallos en columnas // son los mimso pasos a seguir que arriba
    for y :=1 to matriz.numCol do
    for x :=1 to (matriz.numFil-2) do
	if (matriz.fichas[x,y] = matriz.fichas[x,y+1]) and (matriz.fichas[x,y+1] = matriz.fichas[x,y+2]) then
	    begin
		writeln('Columna ',y,' es incorrecta');
		fallocol := fallocol+1;
	    end;
		if (fallofil=0) and (fallocol=0)  then // si no aparece ningun fallo...
		writeln('El tablero es correcto');
end;

var//creamos una ultima variable
    v:tpCasillas;

begin //ejecucuion procesos creados para que salga bien
	lecturaTablero(v);
	cumplicionReglas(v);
end.
//revisar porque me repite dos veces un dato antes de entregarlo
