Proceso Calcular_Factoriales
	//En este programa se utiliza una secuencia "seg�n" para calcular un 
	// factorial en caso de que el n�mero N sea distinto de 0 y de 1
	definir n, f, m como entero;
	escribir "Ingrese el n�mero al que desea resolver el factorial";
	leer n;
	Segun n Hacer
		caso 0:
			f = 0;
		caso 1:
			f = 1;
	//En este caso se asignan dos variables M y F (de factorial) 
		De Otro Modo:
			m = 1;
			f = 1;
			Repetir
				f = f * (m + 1);
				m = m + 1;
			Mientras Que m < n;
	//Se repetir� la secuencia n-1 cantidad de veces
	//Ejemplo: n=5 se repite hasta m=4 pero como realiza un paso m�s,
	// multiplica f * m + 1 (que es igual a N) y cancela m = n.
	Fin Segun
	escribir "El factorial de ", n, " es igual a ", f;
FinProceso