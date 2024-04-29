#include "Figura.h"
#include "Tauler.h"

void Figura::getMax()
{
	if (m_type=FIGURA_I)
	{
		max_alcada = 4;
		max_amplada = 4;
	}
}

void Figura::setFigura(int figura[MAX_AMPLADA][MAX_ALCADA])
{
	for (int i = 0; i < MAX_AMPLADA; i++)
	{
		for (int j = 0; j < MAX_ALCADA; j++)
		{
			m_figura[i][j] = figura[i][j];
		}
	}
}

void Figura::girar_figura(DireccioGir gir )
{
	getMax();

	int matriu_tmp[MAX_ALCADA][MAX_AMPLADA];

	for (int i = 0; i < max_alcada; i++)
	{
		for (int j = 0; j < max_amplada; j++)
		{
			matriu_tmp[j][i] = m_figura[i][j];
		}
	}

	if (gir==GIR_HORARI)
	{
		for (int i = 0; i < max_alcada; i++)
		{
			
			for (int j = 0; j < max_amplada; j++)
			{
				m_figura[i][j] = matriu_tmp[i][max_amplada - j - 1];
			}
		}
	}
	else
	{

		for (int i = 0; i < max_alcada; i++)
		{

			for (int j = 0; j < max_amplada; j++)
			{
				m_figura[j][i] = matriu_tmp[max_amplada - j - 1][i];
			}
		}

	}
}

void Figura::mov_figura(int dirx, int dirY)
{
	m_x += dirx;
	m_y += dirY;
}

bool Figura::gir_legal(DireccioGir gir, Tauler* tauler)
{
	bool resultat = true;
	int i = 0;
	//gir legal
	girar_figura(gir);
	while (resultat&&i<MAX_ALCADA)
	{
		for (int j = 0; i < MAX_AMPLADA; i++)//i->Columna, j->Fila
		{

			if (getPixel(i,j) != COLOR_NEGRE && tauler->getPixel(i + m_y,j + m_x) != COLOR_NEGRE)
			{
				resultat = false;
			}
		}
		i++;
	}

	if (!resultat)
	{
		if (gir==GIR_HORARI)
		{
			girar_figura(GIR_ANTI_HORARI);
		}
		else
		{
			girar_figura(GIR_HORARI);
		}
	}

	return resultat;
}

bool Figura::mov_legal(int dirX, Tauler* tauler)
{
	bool resultat = true;
	//mov en X
	if (dirX==1)//derehca
	{
		
		for (int i = 0; i < max_alcada; i++)
		{
			
			if ((m_x+max_amplada==MAX_COL)&&m_figura[i][max_alcada]==COLOR_NEGRE)
			{
				resultat = false;
			}
		}
	}
	else
	{
		for (int i = 0; i < max_alcada; i++)
		{

			if ((m_x == 0) && m_figura[i][0] == COLOR_NEGRE)
			{
				resultat = false;
			}
		}
	}
	return resultat;
	//mov en Y

}

bool Figura::baixar(int dirY, Tauler* taula)
{
	bool resultat=true;

	for (int i = 1; i <= max_amplada; i++)
	{
		for (int j = 1; j <= max_alcada; j++)
		{
			
			if (taula->getPixel(m_x+i,m_y+j)!=COLOR_NEGRE&&m_figura[i][j]!=COLOR_NEGRE)
			{
				resultat = false;
			}
		}

	}
	return resultat;
}
