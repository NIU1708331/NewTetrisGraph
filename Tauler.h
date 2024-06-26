#ifndef TAULER_H
#define TAULER_H
#include "Figura.h"
#include <fstream>

const int MAX_FILA = 8;
const int MAX_COL = 8;

class Tauler
{
public:
	Tauler();

	int getPixel(int i, int j) { return m_taula[i][j]; }
	int files_fet() { return m_filesFet; }
	void setTaula(int taula[MAX_FILA][MAX_COL]);
	friend std::ifstream& operator>>(std::ifstream& is, Tauler& tauler);
	void fila_a_eliminar();
	void desatFigura(Figura figura);
	void iniFilesFetes() { m_filesFet = 0; }

	void NEW_fila_a_eliminar();

private:
	int m_taula[MAX_FILA][MAX_COL];
	int m_filesFet=0;

	
	void eliminar_fila(int x);
	void eliminaYDesplaza(int y);
	
};
#endif
