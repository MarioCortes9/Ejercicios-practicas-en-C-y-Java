program aparicionesMax;
{
* marcos algás sancho 821089
* mario cortés cantín 869493
* 30/11/2023 aparicionesMax}

type 
	tpApariciones = array['a'..'z'] of integer;//enunciado
	
function convertirMinus(letra:char):char;//para que mayus y minus sea lo mismo

begin
    if (ord(letra) >= ord('A')) and (ord(letra) <=ord('Z')) then
	letra:=chr(ord(letra)+ord('a')-ord('A'))//para que salga la letra que queremos en minuscula(ej: de B a b en codigo ASCII)
    else if (ord(letra) >= ord('a')) and (ord(letra) <= ord('z'))then//lo mismo que antes en minusucula(de b a B)
	letra:=letra; 	
	convertirMinus:=letra;//minuscula aparezca como letra
	           //acordarme corregir letra D mayusucula
end;

procedure inicializadoVector (var vector:tpApariciones);
var
    x:char;
begin
    for x := 'a' to 'z' do
	vector[x]:=0;
end;

procedure sumaLetras (var vector:tpApariciones; x:char);//PARTE 1 procedimiento para que se guarden las letras aparecidas y su numero de repeticiones si la hay
begin
    if (ord(x) >= ord('a')) and (ord(x) <= ord('z')) then
	vector[x]:=vector[x]+1;
end;

procedure letrasMasFrecuencia(var vector:tpApariciones);//PARTE 2 procedimiento para escribir las dos letras que han aparecido en la frase con mas frecuencia
var
    x,y,pos1,pos2:char;//variables y posiciones
    max1,max2:integer;//letras mas aparecidas(max)
begin
    max1:=0;// primera mas frecuente (letra1)
    for x := 'a' to 'z' do
	if (vector[x] > max1) then
	begin
	    max1 := vector[x];
	    pos1 := x;
	end;
	    vector[pos1] := 0;
	
	
	max2 := 0;//segunda mas frecuente (letra2)
	for y := 'a' to 'z' do
	if (vector[y] > max2) then
	begin
	    max2 := vector[y];
	    pos2 := y;
	end;
	    writeln('Letras mas frecuentes:',pos1,' ',pos2);
end;

var
    z:char;
    vector:tpApariciones;
	
begin
    inicializadoVector(vector);
    writeln('Introduce una frase:');
    while not eoln do
    begin
	read(z);
	z := convertirMinus(z);
	sumaLetras(vector,z);//proceso lee caracteres convierte las mayus a minus para contar y suma repetciones
    end;
	
    for z := 'a' to 'z' do//mostrar frecuencia
    if (vector[z] > 0)then
    begin
	writeln(z,' ',vector[z]);
    end;
	letrasMasFrecuencia(vector);
end.
