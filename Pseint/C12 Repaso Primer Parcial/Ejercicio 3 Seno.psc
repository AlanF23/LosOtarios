Proceso calcular_seno
	definir n, imp, step, m, f, trans como entero;
	definir x, s, r como real;
	escribir "Ingrese el �ngulo a calcular:";
	leer x;
	//La variable x es� expresada en degree, pero el programa s�lo entiende en radianes
	//El programa empieza a perder presici�n a medida que nos alejamos del 0
	r = x * pi / 180;
	//Usamos un traductor que calcula el equivalende en radianes del resultado ingresado en degree
	escribir "Ingrese la cantidad de pasos:";
	escribir "(N�mero m�ximo de pasos aceptados 5)";
	leer n;
	//"n" es la cantidad de pasos
	imp = 3;
	//"imp" es la variable impar inicializada en 3 para que se cumpla la funci�n del seno
	trans = (-1);
	//La variable "trans" transforma los resultados en negativos y positivos entre pasos
	s = r;
	Para step<-1 Hasta n Con Paso 1 Hacer
	//"step" es el orden de los pasos a partir de 1
		escribir "Step: ", step;
		escribir "Impar: ", imp, ".";
		m = 1;
		f = 1;
		Repetir
			f = f * (m + 1);
			m = m + 1;
		mientras que m < imp;
		f = f * trans;
		//"F" es el factorial de un impar
		escribir "Factorial de ", imp, ": ", f;
		escribir "";
		s = s + (r ^ imp) / f;
		//"S" se va pisando a s� mismo a medida que se va aproximando al valor real
		escribir "El seno de ", x, " se aproxima a ", s, ".";
		escribir "";
		imp = imp + 2;
		//"imp" cuenta los impares a partir del 3 hasta el 11 como m�ximo
		trans = trans * (-1);
		//Suma impares a partir del 3 de dos en dos
	fin para
FinProceso