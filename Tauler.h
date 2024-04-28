#ifndef TAULER_H
#define TAULER_H
#include "Figura.h"

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
private:
	int m_taula[MAX_FILA][MAX_COL];
	int m_filesFet=0;

	void fila_a_eliminar();
	void eliminar_fila(int x,int y);
	
};
#endif
