{
* marcos algás sancho 821089
* mario cortes cantin 869493 
* 23/12/2023 pokemon}

program pokemon;

//APARTADO A

type //registro tpMov (puntos y nombre)
    tpMov = record
	puntos: integer;
	nom: string;
end;

    tpMovimiento = array[1..4] of tpMov;//4 datos
    
    tpPokemon = record //dentro del pokemon aparecen estos datos
	nombre: string;
	salud: integer;
	ataque: integer;
	defensa: integer;
	velocidad: integer;
	mov: tpMovimiento;
end;

//APARTADO B

procedure leerPokemon(const nombreFichero:string; var pokemon:tpPokemon);

var
    fichero:text;//fichero
begin    
    assign(fichero,nombreFichero); //abrimos fichero
    reset(fichero);
    
    readln(fichero,pokemon.nombre);//relativo a datos
    read(fichero,pokemon.salud);
    read(fichero,pokemon.ataque);
    read(fichero,pokemon.defensa);
    readln(fichero,pokemon.velocidad);
    
    read(fichero,pokemon.mov[1].puntos);//movimiento 1
    readln(fichero,pokemon.mov[1].nom);
    
    read(fichero,pokemon.mov[2].puntos);//movimiento 2
    readln(fichero,pokemon.mov[2].nom);
    
    read(fichero,pokemon.mov[3].puntos);//movimiento 3
    readln(fichero,pokemon.mov[3].nom);
    
    read(fichero,pokemon.mov[4].puntos);//movimiento 4
    readln(fichero,pokemon.mov[4].nom);
    
    close(fichero);//cerramos fichero donde guardamos estos procesos
end;

//APARTADO C

procedure mostrarPokemon(pokemon: tpPokemon);

begin//procedimeinto que muestra los atributos del pokemon y rellenas proximamente en la interaccion
    writeln(pokemon.nombre);
    writeln('Ataque:',pokemon.ataque);
    writeln('Defensa:',pokemon.defensa);
    writeln('Velocidad:',pokemon.velocidad);
    writeln('Salud:',pokemon.salud);
end;

//APARTADO D

procedure batallaPokemon(var pokemon1,pokemon2:tpPokemon);
var
    n1,n2:integer;
    dano1,dano_recibido1,valor_salud1:integer;//ataque 1
    dano2,dano_recibido2,valor_salud2:integer;//ataque 2
    m,n:tpPokemon;
    
begin

    if (pokemon1.velocidad > pokemon2.velocidad) then
    
begin
	m:= pokemon1;
	n:= pokemon2;
end

    else
    
begin
	m:= pokemon2;
	n:= pokemon1;
end;

	writeln(m.nombre,'ataca primero.');//interaccion charizard
	n1:= 2;
	
	writeln(m.nombre,'usa',m.mov[n1].nom,'.');//ataca
	dano1:= (m.ataque) + (m.mov[n1].puntos);//daño ataque charizard
	dano_recibido1:= dano1 - (n.defensa);
	
	writeln(n.nombre,'recibe ',dano_recibido1,'de dano.');//swampert recibe daño de x cifra
	valor_salud1:= (n.salud) - dano_recibido1;
	n.salud:= valor_salud1;
	writeln();
	
	writeln(n.nombre,'ataca despues.');//atauqe pokemon 2
	n2:= 3;
	
	writeln(n.nombre,'usa',n.mov[n2].nom,'.');//utiliza tal atauqe
	dano2:= (n.ataque) + (n.mov[n2].puntos);
	dano_recibido2:= dano2 - (m.defensa);
	
	writeln(m.nombre,'recibe',dano_recibido2,'de dano.');// en el cual el pokemon 1 recibe tal daño
	valor_salud2:= (m.salud) - dano_recibido2;	
	m.salud:= valor_salud2;
	writeln();
	
	writeln('Estado de los pokemon:');//estado pokemon post recibir ataque
	mostrarPokemon(m);
	writeln();
	mostrarPokemon(n);
	writeln();
	
	if (m.salud > n.salud) then //el que mas salud de los dos tiene gana la batalla pok 2 gana
	    writeln(m.nombre,'gana la batalla.')
	else
	    writeln(n.nombre,'gana la batalla.');
end;

//APARTADO E PROGRAMA PRINCIPAL

var 
    pokemon1,pokemon2:tpPokemon;
    fichero1,fichero2:string;
begin
    write('Introduce nombre del fichero con el primer pokemon:');//interaccion pokemon 1
    readln(fichero1);
    leerPokemon(fichero1,pokemon1);
    
    write('Introduce nombre del fichero con el segundo pokemon:');//interaccion pokemon 2
    readln(fichero2);
    leerPokemon(fichero2,pokemon2);
    writeln();
    batallaPokemon(pokemon1,pokemon2);
    
end.
