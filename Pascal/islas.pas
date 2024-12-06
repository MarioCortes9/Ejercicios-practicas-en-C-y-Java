{
* marcos algás sancho 821089
* mario cortes cantin 869493 
* 01/12/2023 islas}

program islas;

const

    MAX= 100;

type

tpIsla = record //primer registro enunciado

    nom: string;
    longitud:real;
    latitud:real;
    valor:integer;
end;

tpGrupoIslas= record //segundo registro enunciado

    data:array [1..MAX] of tpIsla;
    n:integer;
end;

tpPosicionInicial = record //tercer registro enunciado
    longitudinicial:real;
    latitudinicial:real;
end;

tpDistancia = record //ultimo regustro enunciado
    dist:array[1..MAX] of real;
end;

procedure  PedirYleerIslas ( var a:tpGrupoIslas);//procedimiento 1 enunciado para pedir una isla y que lea datos

var
    isla:tpIsla;
    i :integer;

begin
    write('Introduce el numero de islas a almacenar: ' );
    read (a.n);
    
    for i:=1 to a.n do
    begin
        writeln('Datos de la isla ',i,':');
        write('Nombre de la isla: ');
            readln();
            read (isla.nom);
        write('Posicion de la isla (longitud y latitud): ');
            read (isla.longitud,isla.latitud);
        write ('Valor del tesoro (monedas): ');
            read ( isla.valor );
            a.data[i]:=isla;
    end;
end;

procedure distancia( var b:tpPosicionInicial ; g : tpGrupoIslas; var d:tpDistancia);

var
    c : integer;
begin
    for c:=1 to 2 do 
        d.dist[c]:= sqrt((sqr(b.longitudinicial - g.data[c].longitud))+ (sqr(b.latitudinicial - g.data[c].latitud)));
//formula enunciado calculo
end;

function encontrarIslaMasCercana ( d:tpDistancia ; g:tpGrupoIslas):integer; //isla mas cercana al usuario
var
    cerca,c:integer;


begin
    cerca:=1;
    for c:=2 to g.n do
begin
    if ( d.dist[1] < d.dist[cerca]) then
        cerca:=c;
    end;
        encontrarIslaMasCercana := cerca;
end;

var 
    g:tpGrupoIslas;
    b: tpPosicionInicial;
    d: tpDistancia;
    cerca:integer;
    
begin//salida final por pantalla
    write('Introduce tu posicion (longitud y latitud): ');
        read(b.longitudinicial,b.latitudinicial);
    PedirYleerIslas (g);
        distancia(b,g,d);
    cerca:=encontrarIslaMasCercana(d,g);
        writeln('La isla mas cercana a ti es : ');
        writeln ('Nombre: ',g.data[cerca].nom);

        writeln('Posicion (longitud y latitud): ',g.data[cerca].longitud:0:2 , g.data[cerca].latitud:0:2);

        writeln('Tesoro: ',g.data[cerca].valor,' monedas');

        writeln( 'Distancia (en grados) : ',d.dist[cerca]:0:3);

end.

    //acordarnos de la tabulacion

