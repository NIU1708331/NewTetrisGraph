#include "Tauler.h"

Tauler::Tauler()
{
	for (int i = 0; i < MAX_COL; i++)
	{
		
		for (int j = 0; j < MAX_FILA; j++)
		{
			m_taula[i][j] = 0;
		}
	}
}

void Tauler::fila_a_eliminar()
{
	bool trobat = false;
	int i = MAX_FILA - 1,j = 0;
	while (!trobat&&i>0)
	{
		while (m_taula[i][j]!=0)
		{
			j++;
			if (j==MAX_COL)
			{	
				m_filesFet++;
				trobat = true;
				eliminar_fila(i,j);
			}
		}
		i--;
	}
	
}

void Tauler::eliminar_fila(int x,int y)//X=fila Y=col
{
	//eliminar
	for (int i = 0; i < MAX_COL; i++)
	{
		m_taula[x][i] = 0;
	}

	//baixar taula
	for (int i = MAX_FILA-1; i >= x; i--)
	{
		
		for (int j = 0; j < MAX_COL; j++)
		{
			m_taula[i][j] = m_taula[i + 1][j];
		}
	}
	//comprovar de nou
	fila_a_eliminar();

}
