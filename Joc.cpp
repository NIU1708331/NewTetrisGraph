#include "Joc.h"
#include <iostream>
#include <fstream>
using namespace std;

Joc::Joc()
{
    tipusFigura = 0;
    fila = 0; 
    columna = 0; 
    tipusGir = 0;
}
void Joc::inicialitza(const string& nomFitxer)
{
    ifstream fitxerInit(nomFitxer); 

    if (fitxerInit.is_open())
    {
        fitxerInit >> tipusFigura >> fila >> columna >> tipusGir;

        m_figura.setTipus((TipusFigura)tipusFigura);
        m_figura.getMax();
        m_figura.setPosicio(columna-1, fila-1);
        m_figura.setFigura(*matriuFigures[tipusFigura]);

        for (int i = 0; i < tipusGir; i++)
        {
           m_figura.girar_figura(GIR_HORARI);
        }

        fitxerInit >> m_tauler;
        fitxerInit.close();
    }
}

bool Joc::giraFigura(DireccioGir direccio) 
{
    if (m_figura.gettype()==FIGURA_O)
    {
        return true;
    }
    else
    {
        return m_figura.gir_legal(direccio,&m_tauler);
    }
   
}
bool Joc::mouFigura(int dirX)
{
    bool resultat = m_figura.mov_legal(dirX, &m_tauler);
    if (resultat)
    {
        m_figura.mov_figura(dirX, 0);
    }
    return resultat;

}

int Joc::baixaFigura()
{
    if(!m_figura.baixar(1 ,&m_tauler))
    {
        m_tauler.desatFigura(m_figura);
        m_figura.setFigura(*matriuFigures[0]);
        m_tauler.iniFilesFetes();
        m_tauler.fila_a_eliminar();
        //m_figura.setPosicio(0,0);
        //cout << "Eliminar";
    }
    else
    {
        m_figura.mov_figura(0, 1);
    }
    return m_tauler.files_fet();
}

void Joc::escriuTauler(const string& nomFitxer)
{
    ofstream fitxerTauler;
    fitxerTauler.open(nomFitxer);

    if (fitxerTauler.is_open())
    {
        for (int i = 0; i < MAX_FILA; ++i)
        {
            for (int j = 0; j < MAX_COL; ++j)
            { 
              
                if ((i >= m_figura.getY()) &&
                    (i < (m_figura.getY() + m_figura.getSize())) &&
                    (j >= m_figura.getX()) &&
                    (j < (m_figura.getX() + m_figura.getSize())) &&
                    m_figura.getPixel(j - m_figura.getX(), i - m_figura.getY()) != COLOR_NEGRE)
                {
                    fitxerTauler << m_figura.getPixel(j - m_figura.getX(), i - m_figura.getY());
                }
                else
                {
                    fitxerTauler << m_tauler.getPixel(i, j);
                }
            }
            fitxerTauler << endl; 
        }

        fitxerTauler.close();
    }
}

bool Joc::mouFigura2(int dirX, int dirY)
{
    bool resultat = m_figura.mov_legal(dirX, &m_tauler);
    if (resultat)
    {
        m_figura.mov_figura(dirX, dirY);
    }
    return resultat;
	
}
