#include "Joc.h"
#include <iostream>
using namespace std;


void Joc::inicialitza(const string& nomFitxer)
{
	ifstream fitxerInit;
	fitxerInit.open(nomFitxer);
	if (fitxerInit.is_open())
	{

        fitxerInit >> tipusFigura >> fila >> columna >> tipusGir;

        m_figura.setTipus(static_cast<TipusFigura>(tipusFigura));
        m_figura.setPosicio(columna, fila);
        m_figura.setDir(tipusGir);

        int taula[MAX_FILA][MAX_COL];
        for (int i = 0; i < MAX_FILA; ++i)
        {
            for (int j = 0; j < MAX_COL; ++j)
            {
                fitxerInit >> taula[i][j];
            }
        }
        m_tauler.setTaula(taula);
        fitxerInit.close();
	}
}

bool Joc::giraFigura(DireccioGir direccio) 
{
	return 1;
}
bool Joc::mouFigura(int dirX)
{
	return 1;
}

int Joc::baixaFigura()
{
	return 1;
}

void Joc::escriuTauler(const string& nomFitxer)
{

}

bool Joc::mouFigura(int dirX, int dirY)
{
	return 1;
}
