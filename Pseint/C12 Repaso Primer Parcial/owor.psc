Proceso opciones
	definir x como entero;
	definir z como caracter;
	escribir "Elija las siguientes opciones:";
	escribir "1";
	escribir "2";
	escribir "3";
	leer x;
	Repetir
		Segun x Hacer
			1:
				escribir "opci�n 1";
			2:
				escribir "opci�n 2";
			3:
				escribir "opci�n 3";
			De Otro Modo:
				escribir "no es una opci�n v�lida";
		Fin Segun
		escribir "desea continuar con el algoritmo?";
		escribir "S. S�, para continuar";
		escribir "N. No, para salir";
		leer z;
		Si z = "s" Entonces
			escribir "Elija las siguientes opciones:";
			escribir "1";
			escribir "2";
			escribir "3";
			leer x;	
		Fin Si
		si z = "n" Entonces
			escribir "gracias noob";
		FinSi
	Mientras Que z != "n" y z = "s";
	
FinProceso
