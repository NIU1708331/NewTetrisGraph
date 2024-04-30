#ifndef JOC_H
#define JOC_H
#include "Tauler.h"
#include "Figura.h"
#include <string>
using namespace std;

class Joc
{
public:
	Joc();
	void inicialitza(const string& nomFitxer);
	bool giraFigura(DireccioGir direccio);
	bool mouFigura(int dirX);
	int baixaFigura();
	void escriuTauler(const string& nomFitxer);
    Figura *getFigura() { return &m_figura; }

	bool mouFigura2(int dirX, int dirY);
	Tauler* getTauler() { return &m_tauler; };
private:
	Figura m_figura;
	Tauler m_tauler;
	int tipusFigura, fila, columna, tipusGir;
};

#endif

/*
switch (tipusFigura) {
case 0:
    tipus = NO_FIGURA;
    break;
case 1:
    tipus = FIGURA_O;
    c_x = 0;
    c_y = 0;
    break;
case 2:
    tipus = FIGURA_I;
    c_x = -2;
case 3:
    tipus = FIGURA_T;
    break;
case 4:
    tipus = FIGURA_L;
    break;
case 5:
    tipus = FIGURA_J;
    break;
case 6:
    tipus = FIGURA_Z;
    break;
case 7:
    tipus = FIGURA_S;
    break;
default:
    tipus = NO_FIGURA;
    break;
}
*/

