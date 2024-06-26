#include "Figura.h"
#include "Tauler.h"
#include<iostream>

void Figura::getMax()
{
	if (m_type==FIGURA_I)
	{
		max_alcada = 4;
		max_amplada = 4;
	}
	else
	{
		if (m_type==FIGURA_O)
		{
			max_alcada = 2;
			max_amplada = 2;
		}
		else
		{
			max_alcada = 3;
			max_amplada = 3;
		}
	}
}

void Figura::setFigura(const int figura[MAX_AMPLADA][MAX_ALCADA])
{
	for (int i = 0; i < MAX_AMPLADA; i++)
	{
		for (int j = 0; j < MAX_ALCADA; j++)
		{
			m_figura[j][i] = figura[i][j];
		}
	}
}

void Figura::girar_figura(DireccioGir gir )
{

	int matriu_tmp[MAX_ALCADA][MAX_AMPLADA];

	for (int i = 0; i < max_alcada; i++)
	{
		for (int j = 0; j < max_amplada; j++)
		{
			matriu_tmp[j][i] = m_figura[i][j];
		}
	}

	if (gir==GIR_ANTI_HORARI)
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
	getMax();
	int i = 0;
	//gir legal
	girar_figura(gir);
	for (int i = 0; i < max_amplada; i++)
	{
		for (int j = 0; j < max_alcada; j++)
		{

			if (tauler->getPixel(m_y + i, m_x + j) != COLOR_NEGRE && m_figura[j][i] != COLOR_NEGRE)
			{
				resultat = false;
			}
			if (m_figura[i][j]!=COLOR_NEGRE&& (m_x < 0) || (m_x + j >= MAX_COL))
			{
				resultat = false;
			}

		}

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
	getMax();
	bool resultat = true;

	for (int i = 0; i < max_amplada; i++)
	{
		for (int j = 0; j < max_alcada; j++)
		{

			if (tauler->getPixel(m_y + i, m_x + j+dirX) != COLOR_NEGRE && m_figura[j][i] != COLOR_NEGRE)
			{
				resultat = false;
			}
		}

	}

	if (dirX==1)//derehca
	{
		
		for (int i = 0; i < max_alcada; i++)
		{
			
			if ((m_x+max_amplada>=MAX_COL)&&m_figura[(MAX_COL - m_x-1)][i] != COLOR_NEGRE)
			{
				resultat = false;
			}
		}
	}
	else
	{
		for (int i = 0; i < max_alcada; i++)
		{

			if ((m_x < 0) && m_figura[m_x-0+1][i] != COLOR_NEGRE)
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

	for (int i = 0; i < max_amplada; i++)
	{
		for (int j = 0; j < max_alcada; j++)
		{
			
			if (taula->getPixel(m_y+i+1,m_x+j)!=COLOR_NEGRE&&m_figura[j][i]!=COLOR_NEGRE)
			{
				resultat = false;
			}
		}

	}

	for (int i = 0; i < max_amplada; i++)
	{

		if ((m_y + max_alcada>= MAX_FILA) && m_figura[i][MAX_FILA-m_y-1] != COLOR_NEGRE)
		{
			resultat = false;
		}
	}

	return resultat;
}
