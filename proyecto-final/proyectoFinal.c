#include "mecc.h"

int main(void) {
	confTerm();
	srand(time(NULL));
	int pX, pY;
	int notfTam = 2;
	getmaxyx(stdscr, pY, pX);

	char nombre[15];
    int puntos;
	double pre[6];
    int rep;
	int i=0;
    Leccion leccion;
    Caracter usuario[FILAS][COLUMNAS];

	WINDOW *campPtr = newwin(pY - notfTam, pX, 0, 0);
	WINDOW *notfPtr = newwin(notfTam, pX, pY - notfTam, 0);
	do{
		puntos = nombreLeccion(nombre, campPtr);
		leccion = cargarLeccion(nombre, campPtr);
		imprimirLeccion(leccion, usuario, campPtr, pre);
		demoDeltaT(campPtr, notfPtr, usuario, pre);
		calcularResultados(pre, leccion);
		rep = reporte(pre, leccion, campPtr);
		if(rep==1){
			asignarPuntos(puntos, rep);
		}
		wclear(notfPtr);
		wattron(notfPtr, A_REVERSE);
		mvwprintw(notfPtr, 1, 0, "Desea continuar? Sí: marque 0, No: marque 1");
		wattron(notfPtr, A_REVERSE);
		wscanw(notfPtr, "%d", &i);
		wclear(notfPtr);
	}while(i==0);
	
	finTerm(campPtr, notfPtr);
	return 0;
}

void confTerm(void){
	setlocale(LC_ALL, "");
	initscr();
	cbreak();
	noecho();

	if (has_colors() == FALSE)
	{
		endwin();
		puts("Tu terminal no soporta color");
		exit(EXIT_FAILURE);
	}

	start_color(); 
	init_pair(PAR_OK, COLOR_GREEN, COLOR_BLACK);
	init_pair(PAR_WAR, COLOR_YELLOW, COLOR_BLACK);
	init_pair(PAR_ERR, COLOR_RED, COLOR_BLACK);
}

void demoDeltaT(WINDOW *campPtr, WINDOW *notfPtr, Caracter usuario[][COLUMNAS], double p[]){
	struct timeval begin, end;
	char c;
	p[0]=0;
	p[3]=p[1];

	wclear(notfPtr);
	wattron(notfPtr, A_REVERSE);
	wprintw(notfPtr, "Escriba texto, pulse Esc para salir...");
	wattroff(notfPtr, A_REVERSE);
	
	wmove(campPtr, 0, 0);
	wnoutrefresh(campPtr);
	wnoutrefresh(notfPtr);
	doupdate();

	for (unsigned i = 0; i < FILAS; i++){
		for (int j = 0; j < COLUMNAS; j++) {
			usuario[i][j].acierto = 1;
			
			gettimeofday(&begin, 0);
			c = wgetch(campPtr);
			gettimeofday(&end, 0);

			ParColor selColor;
			double deltaT = end.tv_sec - begin.tv_sec + ((end.tv_usec - begin.tv_usec) * 1e-6);
			p[0] += deltaT;
			usuario[i][j].tiempo = deltaT;
	        wmove(campPtr, (i * 2) + 9, j + 10);

			if (c != usuario[i][j].letra) {
				selColor = PAR_ERR;
				wattron(campPtr, A_REVERSE | COLOR_PAIR(selColor));
			    mvwaddch(campPtr, (i * 2) + 9, j + 10, c);
				usuario[i][j].acierto = 0;
			}
			else if (c == usuario[i][j].letra && deltaT >= 0.8) {
				selColor = PAR_WAR;
				wattron(campPtr, A_REVERSE | COLOR_PAIR(selColor));
			    mvwaddch(campPtr, (i * 2) + 9, j + 10, c);
				p[3]--;
			}
			else if (c == usuario[i][j].letra && deltaT < 0.8) {
				selColor = PAR_OK;
				wattron(campPtr, A_REVERSE | COLOR_PAIR(selColor));
			    mvwaddch(campPtr, (i * 2) + 9, j + 10, c);
				p[3]--;
			}

			if (c == 27) {
                exit(EXIT_FAILURE);
			}

			if (usuario[i][j + 1].letra == '\n' && i < FILAS - 1) {
				i++;
				j = -1;
	            wmove(campPtr, (i * 2) + 9, j + 11);
			}

			if ((usuario[i][j + 1].letra == '\n' && i + 1 >= FILAS)) {
				i = FILAS;
				j = COLUMNAS;
			}

			wattron(notfPtr, A_REVERSE | COLOR_PAIR(selColor));
			mvwprintw(notfPtr, 1, 0, "Δt: %.3f", deltaT);
			wattroff(notfPtr, A_REVERSE);
			wnoutrefresh(campPtr);
			wnoutrefresh(notfPtr);
			doupdate();
		}
	}
}

int nombreLeccion(char nombre[], WINDOW *campPtr){
    wclear(campPtr);
	int puntaje;
	wnoutrefresh(campPtr);
	doupdate();
	wattrset(campPtr, A_REVERSE|COLOR_PAIR(0));

    FILE *cfPtr;  
    if ((cfPtr = fopen("progreso.txt", "r")) == NULL) {
        EXIT_FAILURE;
    } 
    else { 
      fscanf(cfPtr, "%d ", &puntaje);
	  wattron(campPtr, A_REVERSE);
	  mvwprintw(campPtr, 0, 0, "Puntaje actual: %d", puntaje);
	  wattroff(campPtr, A_REVERSE);
	  
	  if(puntaje<100){
            sprintf(nombre, "0%d.txt", (puntaje/10)+1);
          }
            else if(puntaje>=100 && puntaje<130){
            sprintf(nombre, "%d.txt", (puntaje/10)+1);
            }
            else if(puntaje>=130){
                int opcion;
				wattron(campPtr, A_REVERSE);
				mvwprintw(campPtr, 1, 0, "ESC Salir");
				mvwprintw(campPtr, 2, 0, "1 filaCentralI");
				mvwprintw(campPtr, 3, 0, "2 filaCentralII");
				mvwprintw(campPtr, 4, 0, "3 filaCentralIII");
				mvwprintw(campPtr, 5, 0, "4 filaSuperiorI");
				mvwprintw(campPtr, 6, 0, "5 filaSuperiorII");
				mvwprintw(campPtr, 7, 0, "6 filaSuperiorIII");
				mvwprintw(campPtr, 8, 0, "7 filaInferiorI");
				mvwprintw(campPtr, 9, 0, "8 filaInferiorII");
				mvwprintw(campPtr, 10, 0, "9 filaInferiorIII");
				mvwprintw(campPtr, 11, 0, "10 filaNumerosI");
				mvwprintw(campPtr, 12, 0, "11 filaNumerosII");
				mvwprintw(campPtr, 13, 0, "12 filaNumerosIII");
				wattroff(campPtr, A_REVERSE);

                wscanw(campPtr, "%d", &opcion);
				wattron(campPtr, A_REVERSE);
				mvwprintw(campPtr, 15, 0, "Opción: %d", opcion); 
				wattroff(campPtr, A_REVERSE);
				wscanw(campPtr, "%d", &opcion);
				mvwprintw(campPtr, 16, 0, "Opción: %d", opcion);
				
				if (opcion == 27) {
					exit(EXIT_SUCCESS); 
					}

                else if(opcion < 0 || opcion > 12){
                    wattron(campPtr, A_REVERSE);
					mvwprintw(campPtr, 14, 0, "No es una opción válida.");
					wattroff(campPtr, A_REVERSE);
                }
                else if(opcion<10){
                sprintf(nombre, "0%d.txt", opcion);
                }
                else if(opcion>=10){
                sprintf(nombre, "%d.txt", opcion);
                }
				wattroff(campPtr, A_REVERSE);
				wnoutrefresh(campPtr);
				doupdate();
			}
	}
	fclose(cfPtr);
	wnoutrefresh(campPtr);
	doupdate();
	return puntaje;	
}

Leccion cargarLeccion(char nombre[], WINDOW *campPtr){
  Leccion lec;
  wnoutrefresh(campPtr);
  doupdate();

  FILE *cfPtr;
    if ((cfPtr = fopen(nombre, "r")) == NULL){
		EXIT_FAILURE;
	}
	else{
		if ((fscanf(cfPtr, "%s %u %u %u", lec.nombre, &lec.AdjWPM, &lec.a, &lec.cantWord) != 4)){
			fprintf(stderr, "fscanf: error al leer los datos.");
			fclose(cfPtr);
			exit(EXIT_FAILURE);
		}

		for (unsigned i = 0; i < lec.cantWord; i++){
			fscanf(cfPtr, "%s", lec.palabras[i]);
		}
	}
	fclose(cfPtr);
	wnoutrefresh(campPtr);
	doupdate();
	return lec;
}

void imprimirLeccion(Leccion lec, Caracter usuario[][COLUMNAS], WINDOW *campPtr, double p[]){
  wclear(campPtr);
  int pos, tam;
  int i=0;
  p[1]=0;
  wattrset(campPtr, A_REVERSE|COLOR_PAIR(0));

	while (i < FILAS) {
		int j = 0;

		while (j < COLUMNAS) {
			pos = rand() % (lec.cantWord);
			tam = strlen(lec.palabras[pos]);

			if ((j + tam + 1) < COLUMNAS) {

				for (int k = 0; k < tam; k++) {
					usuario[i][j].letra = lec.palabras[pos][k];
					wattron(campPtr, A_REVERSE);
					mvwprintw(campPtr, (i * 2) + 8, j + 10, "%c", usuario[i][j].letra);
					wattroff(campPtr, A_REVERSE);
					j++;
					p[1]++;
				}

				if (j + 3 < COLUMNAS){
				    usuario[i][j].letra = ' ';
				    wattron(campPtr, A_REVERSE);
				    mvwprintw(campPtr, (i * 2) + 8, j + 10, "%c", usuario[i][j].letra);
				    wattroff(campPtr, A_REVERSE);
				    j++;
				    p[1]++;
				}
			}
			else if ((j + tam + 1) >= COLUMNAS) {
                usuario[i][j].letra = '\n';

				if ((i + 1) < FILAS) {
					j = 0;
					i++;

					for (int k = j; k < tam; k++) {
						usuario[i][j].letra = lec.palabras[pos][k];
						wattron(campPtr, A_REVERSE);
						mvwprintw(campPtr, (i * 2) + 8, j + 10, "%c", usuario[i][j].letra);
						wattroff(campPtr, A_REVERSE);
						j++;
						p[1]++;
					}

					usuario[i][j].letra = ' ';
					wattron(campPtr, A_REVERSE);
					mvwprintw(campPtr, (i * 2) + 8, j + 10, "%c", usuario[i][j].letra);
					wattroff(campPtr, A_REVERSE);
					j++;
					p[1]++;
				}
				else if (i + 1 >= FILAS) {
					break;
				}
			}
		}
		i++;
	}
}


void finTerm(WINDOW *campPtr, WINDOW *notfPtr){
	delwin(campPtr);
	delwin(notfPtr);
	endwin();
}

void calcularResultados(double p[], Leccion lec){
	p[2] = ((p[1]-1)/p[0]) * 60 * 1/5;
	p[4] = p[3] / p[1];
	p[5] = p[2] * pow((1-p[4]), lec.a);
}

int reporte(double p[], Leccion lec, WINDOW *campPtr){
	int r;
	wclear(campPtr);
	wattrset(campPtr, A_REVERSE|COLOR_PAIR(0));

	wattron(campPtr, A_REVERSE);
    mvwprintw(campPtr, 0, 0, "Lección evaluada: %s", lec.nombre);
	mvwprintw(campPtr, 1, 0, "Tiempo total: %lf", p[0]);
	mvwprintw(campPtr, 2, 0, "Palabras por minuto: %lf", p[2]);
	mvwprintw(campPtr, 3, 0, "Cantidad de errores: %lf", p[3]);
	mvwprintw(campPtr, 4, 0, "Proporcion de error: %lf%", p[4]*100);
	mvwprintw(campPtr, 5, 0, "Palabras por minuto ajustado: %lf", p[5]);
	wattroff(campPtr, A_REVERSE);

	if(p[4] < 0.1 && p[5] > lec.AdjWPM){
		wattron(campPtr, A_REVERSE);
		mvwprintw(campPtr, 7, 0, "Lección aprobada");
		wattroff(campPtr, A_REVERSE);
		r=1;
	}
	else if (p[4] >= 0.1 || p[5] <= lec.AdjWPM){
		r=0;
		wattron(campPtr, A_REVERSE);
    	mvwprintw(campPtr, 7, 0, "Lección no aprobada");
		wattroff(campPtr, A_REVERSE);
	}
	wnoutrefresh(campPtr);
	doupdate();
	return r;
}

void asignarPuntos(int puntos, int r){
	if(r == 1){
		puntos += 10;
		FILE *cfPtr;
		if ((cfPtr = fopen("progreso.txt", "w")) == NULL) {
			EXIT_FAILURE;
			} 
		else { 
			fprintf(cfPtr, "%d", puntos);
			fclose(cfPtr); 
			}
   }
} 								