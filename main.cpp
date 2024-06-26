#include "Joc.h"
#include <fstream>
#include <iostream>
#include <string>
#include "Figura.h"
using namespace std;

#include <SDL.h>

#undef main
string tipusToString(int tipus)
{
	string tipusString;

	switch (tipus)
	{
	case 1:
		tipusString = "FIGURA_O";
		break;
	case 2:
		tipusString = "FIGURA_I";
		break;
	case 3:
		tipusString = "FIGURA_T";
		break;
	case 4:
		tipusString = "FIGURA_L";
		break;
	case 5:
		tipusString = "FIGURA_J";
		break;
	case 6:
		tipusString = "FIGURA_Z";
		break;
	case 7:
		tipusString = "FIGURA_S";
		break;
	}
	return tipusString;
}


void mostraFitxerInicial(const string& nomFitxerInicial)
{
	ifstream fitxerInicial;
	fitxerInicial.open(nomFitxerInicial);
	if (!fitxerInicial.is_open())
		cout << "Comment :=>> Error obrint els fitxers de resultat" << endl;
	else
	{
		cout << "Comment :=>> ----------------------------------" << endl;
		cout << "Comment :=>> Configuracio inicial de la partida" << endl;
		cout << "Comment :=>> ----------------------------------" << endl;
		int tipus, fila, columna, gir;
		fitxerInicial >> tipus >> fila >> columna >> gir;
		string tipusFigura = tipusToString(tipus);
		cout << "Comment :=>> Tipus de la figura: " << tipusFigura << endl;
		cout << "Comment :=>> Posicio inicial de la figura: (" << fila << "," << columna << ")" << endl;
		cout << "Comment :=>> Gir inicial de la figura: " << gir << endl;
		cout << "Comment :=>> ------------" << endl;
		cout << "Comment :=>> Contingut inicial del tauler: "<< endl;
		cout << "Comment :=>> -----------------------------" << endl;

		string linia;
		getline(fitxerInicial, linia);
		while (!fitxerInicial.eof())
		{
			cout << "Comment :=>> " << linia << endl;
			getline(fitxerInicial, linia);
		}
		cout << "Comment :=>> ----------------------------" << endl;
		cout << "Comment :=>> " << endl;
	}
}

void llegeixTauler(ifstream& fitxer, char tauler[MAX_FILA][MAX_COL])
{
	char c;
	int i = 0;
	fitxer >> c;
	while (!fitxer.eof() && (i < MAX_FILA))
	{
		int j = 0;
		cout << "Comment :=>>";
		while (!fitxer.eof() && (j < MAX_COL))
		{
			cout << " " << c;
			tauler[i][j] = c;
			j++;
			fitxer >> c;
		}
		cout << endl;
		i++;
	}
	fitxer.close();
}


bool comparaTaulers(char taulerResultat[MAX_FILA][MAX_COL], char taulerEsperat[MAX_FILA][MAX_COL])
{
	bool iguals = true;
	int i = 0;
	while (iguals && (i < MAX_FILA))
	{
		int j = 0;
		while (iguals && (j < MAX_COL))
		{
			if (taulerResultat[i][j] != taulerEsperat[i][j])
				iguals = false;
			else
				j++;
		}
		i++;
	}
	return iguals;
}


bool comparaResultatPartida(const string& nomFitxerResultat, const string& nomFitxerEsperat)
{
	bool correcte = false;
	ifstream fitxerEsperat, fitxerResultat;
	char taulerResultat[MAX_FILA][MAX_COL];
	char taulerEsperat[MAX_FILA][MAX_COL];

	fitxerEsperat.open(nomFitxerEsperat);
	fitxerResultat.open(nomFitxerResultat);
	if ((!fitxerEsperat.is_open()) || (!fitxerResultat.is_open()))
		cout << "Comment :=>> Error obrint els fitxers de resultat" << endl;
	else
	{
		cout << "Comment :=>> RESULTAT ESPERAT" << endl;
		cout << "Comment :=>> ----------------------------" << endl;
		llegeixTauler(fitxerEsperat, taulerEsperat);
		cout << "Comment :=>> ----------------------------" << endl;
		cout << "Comment :=>> " << endl;
		cout << "Comment :=>> RESULTAT OBTINGUT" << endl;
		cout << "Comment :=>> ----------------------------" << endl;
		llegeixTauler(fitxerResultat, taulerResultat);
		cout << "Comment :=>> ----------------------------" << endl;
		cout << "Comment :=>> " << endl;
		if (comparaTaulers(taulerResultat, taulerEsperat))
		{
			cout << "Comment :=>> RESULTAT CORRECTE" << endl;
			cout << "Comment :=>> " << endl;
			correcte = true;
		}
		else
		{
			cout << "Comment :=>> ERROR. El tauler final no es igual al tauler esperat" << endl;
			cout << "Comment :=>> " << endl;
			correcte = false;
		}
	}
	return correcte;



}


int test_main()
{
	Joc joc;

	float grade = 0.0;
	bool correcte = true;

	cout << "Grade :=>> " << grade << endl << endl;
	cout << "Comment :=>> " << endl;
	cout << "Comment :=>>  ==========================" << endl;
	cout << "Comment :=>> | Iniciant test            |" << endl;
	cout << "Comment :=>>  ==========================" << endl;
	cout << "Comment :=>> " << endl;

	cout << "Comment :=>>  =====================================" << endl;
	cout << "Comment :=>> | TEST D'INICIALITZACIO DEL TAULER    |" << endl;
	cout << "Comment :=>>  =====================================" << endl;
	cout << "Comment :=>> " << endl;

	float reduccio = 0.0;
	// Posar figura sense girar
	cout << "Comment :=>> ------------------------------------------------" << endl;
	cout << "Comment :=>> TEST 1" << endl;
	cout << "Comment :=>> Inicialitzacio del tauler amb figura sense girar" << endl;
	cout << "Comment :=>> ------------------------------------------------" << endl;
	cout << "Comment :=>> " << endl;
	joc.inicialitza("./data/test_inicialitzacio_tauler.txt");
	mostraFitxerInicial("./data/test_inicialitzacio_tauler.txt");
	joc.escriuTauler("./data/resultat_inicialitzacio_tauler.txt");
	correcte = comparaResultatPartida("./data/resultat_inicialitzacio_tauler.txt", "./data/resultat_esperat_inicialitzacio_tauler.txt");
	if (!correcte)
		reduccio += 0.5;

	// Inicialitzacio figura amb gir
	cout << "Comment :=>> ------------------------------------------------" << endl;
	cout << "Comment :=>> TEST 2" << endl;
	cout << "Comment :=>> Inicialitzacio del tauler amb figura amb gir" << endl;
	cout << "Comment :=>> ------------------------------------------------" << endl;
	cout << "Comment :=>> " << endl;
	joc.inicialitza("./data/test_inicialitzacio_gir.txt");
	mostraFitxerInicial("./data/test_inicialitzacio_gir.txt");
	joc.escriuTauler("./data/resultat_inicialitzacio_gir.txt");
	correcte = comparaResultatPartida("./data/resultat_inicialitzacio_gir.txt", "./data/resultat_esperat_inicialitzacio_gir.txt");
	if (!correcte)
		reduccio += 0.5;

	grade += (1.0 - reduccio);
	cout << "Comment :=>> ------------------------------------------------" << endl;
	cout << "Comment :=>> " << endl;
	cout << "Grade :=>> " << grade << endl << endl;
	cout << "Comment :=>> " << endl;






	cout << "Comment :=>>  =====================================" << endl;
	cout << "Comment :=>> | TEST MOVIMENTS FIGURES              |" << endl;
	cout << "Comment :=>>  =====================================" << endl;
	cout << "Comment :=>> " << endl;
	reduccio = 0.0;

	// Baixa figura
	cout << "Comment :=>> ------------------------------------------------" << endl;
	cout << "Comment :=>> TEST 1" << endl;
	joc.inicialitza("./data/test_baixa_figura.txt");
	mostraFitxerInicial("./data/test_baixa_figura.txt");
	cout << "Comment :=>> Moviments a partir de la configuracio inicial" << endl;
	cout << "Comment :=>>  - Baixa figura" << endl;
	cout << "Comment :=>> ------------------------------------------------" << endl;
	joc.baixaFigura();
	joc.escriuTauler("./data/resultat_baixa_figura.txt");
	correcte = comparaResultatPartida("./data/resultat_baixa_figura.txt", "./data/resultat_esperat_baixa_figura.txt");
	if (!correcte)
		reduccio += 0.5;

	// Baixa i col�loca figura al tauler
	cout << "Comment :=>> ------------------------------------------------" << endl;
	cout << "Comment :=>> TEST 2" << endl;
	joc.inicialitza("./data/test_baixa_figura.txt");
	mostraFitxerInicial("./data/test_baixa_figura.txt");
	cout << "Comment :=>> Moviments a partir de la configuracio inicial" << endl;
	cout << "Comment :=>>  - Baixa figura" << endl;
	cout << "Comment :=>>  - Baixa figura" << endl;
	cout << "Comment :=>> ------------------------------------------------" << endl;
	joc.baixaFigura();
	joc.baixaFigura();
	joc.escriuTauler("./data/resultat_baixa_coloca_figura.txt");
	correcte = comparaResultatPartida("./data/resultat_baixa_coloca_figura.txt", "./data/resultat_esperat_baixa_coloca_figura.txt");
	if (!correcte)
		reduccio += 0.5;

	// Mou figura esquerra i no pot
	cout << "Comment :=>> ------------------------------------------------" << endl;
	cout << "Comment :=>> TEST 3" << endl;
	joc.inicialitza("./data/test_mou_figura_1.txt");
	mostraFitxerInicial("./data/test_mou_figura_1.txt");
	cout << "Comment :=>> Moviments a partir de la configuracio inicial" << endl;
	cout << "Comment :=>>  - Mou figura esquerra" << endl;
	cout << "Comment :=>> ------------------------------------------------" << endl;
	joc.mouFigura(-1);
	joc.escriuTauler("./data/resultat_mou_figura_1.txt");
	correcte = comparaResultatPartida("./data/resultat_mou_figura_1.txt", "./data/resultat_esperat_mou_figura_1.txt");
	if (!correcte)
		reduccio += 0.5;
	
	// Mou figura esquerra i pot degut al gir
	cout << "Comment :=>> ------------------------------------------------" << endl;
	cout << "Comment :=>> TEST 4" << endl;
	joc.inicialitza("./data/test_mou_figura_2.txt");
	mostraFitxerInicial("./data/test_mou_figura_2.txt");
	cout << "Comment :=>> Moviments a partir de la configuracio inicial" << endl;
	cout << "Comment :=>>  - Mou figura esquerra" << endl;
	cout << "Comment :=>> ------------------------------------------------" << endl;
	joc.mouFigura(-1);
	joc.escriuTauler("./data/resultat_mou_figura_2.txt");
	correcte = comparaResultatPartida("./data/resultat_mou_figura_2.txt", "./data/resultat_esperat_mou_figura_2.txt");
	if (!correcte)
		reduccio += 0.5;

	// Mou figura esquerra, es pot un cop, pero no el segon
	cout << "Comment :=>> ------------------------------------------------" << endl;
	cout << "Comment :=>> TEST 5" << endl;
	joc.inicialitza("./data/test_mou_figura_3.txt");
	mostraFitxerInicial("./data/test_mou_figura_3.txt");
	cout << "Comment :=>> Moviments a partir de la configuracio inicial" << endl;
	cout << "Comment :=>>  - Mou figura esquerra" << endl;
	cout << "Comment :=>>  - Mou figura esquerra" << endl;
	cout << "Comment :=>> ------------------------------------------------" << endl;
	joc.mouFigura(-1);
	joc.mouFigura(-1);
	joc.escriuTauler("./data/resultat_mou_figura_3.txt");
	correcte = comparaResultatPartida("./data/resultat_mou_figura_3.txt", "./data/resultat_esperat_mou_figura_3.txt");
	if (!correcte)
		reduccio += 0.5;

	// Mou figura dreta un cop 
	cout << "Comment :=>> ------------------------------------------------" << endl;
	cout << "Comment :=>> TEST 6" << endl;
	joc.inicialitza("./data/test_mou_figura_4.txt");
	mostraFitxerInicial("./data/test_mou_figura_4.txt");
	cout << "Comment :=>> Moviments a partir de la configuracio inicial" << endl;
	cout << "Comment :=>>  - Mou figura dreta" << endl;
	cout << "Comment :=>> ------------------------------------------------" << endl;
	joc.mouFigura(1);
	joc.escriuTauler("./data/resultat_mou_figura_4.txt");
	correcte = comparaResultatPartida("./data/resultat_mou_figura_4.txt", "./data/resultat_esperat_mou_figura_4.txt");
	if (!correcte)
		reduccio += 0.5;

	// Mou figura girada dreta dos cops 
	cout << "Comment :=>> ------------------------------------------------" << endl;
	cout << "Comment :=>> TEST 7" << endl;
	joc.inicialitza("./data/test_mou_figura_5.txt");
	mostraFitxerInicial("./data/test_mou_figura_5.txt");
	cout << "Comment :=>> Moviments a partir de la configuracio inicial" << endl;
	cout << "Comment :=>>  - Mou figura dreta" << endl;
	cout << "Comment :=>>  - Mou figura dreta" << endl;
	cout << "Comment :=>> ------------------------------------------------" << endl;
	joc.mouFigura(1);
	joc.mouFigura(1);
	joc.escriuTauler("./data/resultat_mou_figura_5.txt");
	correcte = comparaResultatPartida("./data/resultat_mou_figura_5.txt", "./data/resultat_esperat_mou_figura_5.txt");
	if (!correcte)
		reduccio += 0.5;

	// Mou figura girada dreta tres cops, nomes pot dos
	cout << "Comment :=>> ------------------------------------------------" << endl;
	cout << "Comment :=>> TEST 8" << endl;
	joc.inicialitza("./data/test_mou_figura_6.txt");
	mostraFitxerInicial("./data/test_mou_figura_6.txt");
	cout << "Comment :=>> Moviments a partir de la configuracio inicial" << endl;
	cout << "Comment :=>>  - Mou figura dreta" << endl;
	cout << "Comment :=>>  - Mou figura dreta" << endl;
	cout << "Comment :=>>  - Mou figura dreta" << endl;
	cout << "Comment :=>> ------------------------------------------------" << endl;
	joc.mouFigura(1);
	joc.mouFigura(1);
	joc.mouFigura(1);
	joc.escriuTauler("./data/resultat_mou_figura_6.txt");
	correcte = comparaResultatPartida("./data/resultat_mou_figura_6.txt", "./data/resultat_esperat_mou_figura_6.txt");
	if (!correcte)
		reduccio += 0.5;

	// Mou figura dreta dos cops colisiona amb tauler el segon moviment
	cout << "Comment :=>> ------------------------------------------------" << endl;
	cout << "Comment :=>> TEST 9" << endl;
	joc.inicialitza("./data/test_mou_figura_7.txt");
	mostraFitxerInicial("./data/test_mou_figura_7.txt");
	cout << "Comment :=>> Moviments a partir de la configuracio inicial" << endl;
	cout << "Comment :=>>  - Mou figura dreta" << endl;
	cout << "Comment :=>>  - Mou figura dreta" << endl;
	cout << "Comment :=>> ------------------------------------------------" << endl;
	joc.mouFigura(1);
	joc.mouFigura(1);
	joc.escriuTauler("./data/resultat_mou_figura_7.txt");
	correcte = comparaResultatPartida("./data/resultat_mou_figura_7.txt", "./data/resultat_esperat_mou_figura_7.txt");
	if (!correcte)
		reduccio += 0.5;

	// Mou figura girada dreta 1 cop 
	cout << "Comment :=>> ------------------------------------------------" << endl;
	cout << "Comment :=>> TEST 10" << endl;
	joc.inicialitza("./data/test_mou_figura_8.txt");
	mostraFitxerInicial("./data/test_mou_figura_8.txt");
	cout << "Comment :=>> Moviments a partir de la configuracio inicial" << endl;
	cout << "Comment :=>>  - Mou figura dreta" << endl;
	cout << "Comment :=>> ------------------------------------------------" << endl;
	joc.mouFigura(1);
	joc.escriuTauler("./data/resultat_mou_figura_8.txt");
	correcte = comparaResultatPartida("./data/resultat_mou_figura_8.txt", "./data/resultat_esperat_mou_figura_8.txt");
	if (!correcte)
		reduccio += 0.5;

	// Mou figura girada dreta 2 cops, el segon colisiona amb el tauler 
	cout << "Comment :=>> ------------------------------------------------" << endl;
	cout << "Comment :=>> TEST 11" << endl;
	joc.inicialitza("./data/test_mou_figura_9.txt");
	mostraFitxerInicial("./data/test_mou_figura_9.txt");
	cout << "Comment :=>> Moviments a partir de la configuracio inicial" << endl;
	cout << "Comment :=>>  - Mou figura dreta" << endl;
	cout << "Comment :=>>  - Mou figura dreta" << endl;
	cout << "Comment :=>> ------------------------------------------------" << endl;
	joc.mouFigura(1);
	joc.mouFigura(1);
	joc.escriuTauler("./data/resultat_mou_figura_9.txt");
	correcte = comparaResultatPartida("./data/resultat_mou_figura_9.txt", "./data/resultat_esperat_mou_figura_9.txt");
	if (!correcte)
		reduccio += 0.5;

	// Mou figura I girada tres cops, nom�s pot moure un a l'esquerra
	cout << "Comment :=>> ------------------------------------------------" << endl;
	cout << "Comment :=>> TEST 12" << endl;
	joc.inicialitza("./data/test_mou_figura_10.txt");
	mostraFitxerInicial("./data/test_mou_figura_10.txt");
	cout << "Comment :=>> Moviments a partir de la configuracio inicial" << endl;
	cout << "Comment :=>>  - Mou figura esquerra" << endl;
	cout << "Comment :=>>  - Mou figura esquerra" << endl;
	cout << "Comment :=>> ------------------------------------------------" << endl;
	joc.mouFigura(-1);
	joc.mouFigura(-1);
	joc.escriuTauler("./data/resultat_mou_figura_10.txt");
	correcte = comparaResultatPartida("./data/resultat_mou_figura_10.txt", "./data/resultat_esperat_mou_figura_10.txt");
	if (!correcte)
		reduccio += 0.5;

	grade += (3.0 - reduccio);
	cout << "Comment :=>> ------------------------------------------------" << endl;
	cout << "Comment :=>> " << endl;
	cout << "Grade :=>> " << grade << endl << endl;
	cout << "Comment :=>> " << endl;





	cout << "Comment :=>>  =====================================" << endl;
	cout << "Comment :=>> | TEST GIRS FIGURES                   |" << endl;
	cout << "Comment :=>>  =====================================" << endl;
	cout << "Comment :=>> " << endl;
	reduccio = 0.0;

	// Gir antihorari
	cout << "Comment :=>> ------------------------------------------------" << endl;
	cout << "Comment :=>> TEST 1" << endl;
	joc.inicialitza("./data/test_gir_figura_1.txt");
	mostraFitxerInicial("./data/test_gir_figura_1.txt");
	cout << "Comment :=>> Moviments a partir de la configuracio inicial" << endl;
	cout << "Comment :=>>  - Gir anti-horari" << endl;
	cout << "Comment :=>> ------------------------------------------------" << endl;
	joc.giraFigura(GIR_ANTI_HORARI);
	joc.escriuTauler("./data/resultat_gir_figura_1.txt");
	correcte = comparaResultatPartida("./data/resultat_gir_figura_1.txt", "./data/resultat_esperat_gir_figura_1.txt");
	if (!correcte)
		reduccio += 0.5;

	// Gir antihorari prohibit limit esquerra
	cout << "Comment :=>> ------------------------------------------------" << endl;
	cout << "Comment :=>> TEST 2" << endl;
	joc.inicialitza("./data/test_gir_figura_2.txt");
	mostraFitxerInicial("./data/test_gir_figura_2.txt");
	cout << "Comment :=>> Moviments a partir de la configuracio inicial" << endl;
	cout << "Comment :=>>  - Mou figura esquerra" << endl;
	cout << "Comment :=>>  - Gir anti-horari" << endl;
	cout << "Comment :=>> ------------------------------------------------" << endl;
	joc.mouFigura(-1);
	joc.giraFigura(GIR_ANTI_HORARI);
	joc.escriuTauler("./data/resultat_gir_figura_2.txt");
	correcte = comparaResultatPartida("./data/resultat_gir_figura_2.txt", "./data/resultat_esperat_gir_figura_2.txt");
	if (!correcte)
		reduccio += 0.5;

	// Gir  prohibit limit dret
	cout << "Comment :=>> ------------------------------------------------" << endl;
	cout << "Comment :=>> TEST 3" << endl;
	joc.inicialitza("./data/test_gir_figura_3.txt");
	mostraFitxerInicial("./data/test_gir_figura_3.txt");
	cout << "Comment :=>> Moviments a partir de la configuracio inicial" << endl;
	cout << "Comment :=>>  - Gir anti-horari" << endl;
	cout << "Comment :=>>  - Mou figura dreta" << endl;
	cout << "Comment :=>>  - Gir horari" << endl;
	cout << "Comment :=>> ------------------------------------------------" << endl;
	joc.giraFigura(GIR_ANTI_HORARI);
	joc.mouFigura(1);
	joc.giraFigura(GIR_HORARI);
	joc.escriuTauler("./data/resultat_gir_figura_3.txt");
	correcte = comparaResultatPartida("./data/resultat_gir_figura_3.txt", "./data/resultat_esperat_gir_figura_3.txt");
	if (!correcte)
		reduccio += 0.5;

	// Gir  prohibit limit esquerra figura I 
	cout << "Comment :=>> ------------------------------------------------" << endl;
	cout << "Comment :=>> TEST 4" << endl;
	joc.inicialitza("./data/test_gir_figura_4.txt");
	mostraFitxerInicial("./data/test_gir_figura_4.txt");
	cout << "Comment :=>> Moviments a partir de la configuracio inicial" << endl;
	cout << "Comment :=>>  - Gir horari" << endl;
	cout << "Comment :=>>  - Mou figura esquerra" << endl;
	cout << "Comment :=>>  - Mou figura esquerra" << endl;
	cout << "Comment :=>>  - Gir horari" << endl;
	cout << "Comment :=>> ------------------------------------------------" << endl;
	joc.giraFigura(GIR_HORARI);
	joc.mouFigura(-1);
	joc.mouFigura(-1);
	joc.giraFigura(GIR_HORARI);
	joc.escriuTauler("./data/resultat_gir_figura_4.txt");
	correcte = comparaResultatPartida("./data/resultat_gir_figura_4.txt", "./data/resultat_esperat_gir_figura_4.txt");
	if (!correcte)
		reduccio += 0.5;

	// Gir  prohibit limit esquerra figura I nom�s una columna
	cout << "Comment :=>> ------------------------------------------------" << endl;
	cout << "Comment :=>> TEST 5" << endl;
	joc.inicialitza("./data/test_gir_figura_5.txt");
	mostraFitxerInicial("./data/test_gir_figura_5.txt");
	cout << "Comment :=>> Moviments a partir de la configuracio inicial" << endl;
	cout << "Comment :=>>  - Mou figura esquerra" << endl;
	cout << "Comment :=>>  - Gir anti-horari" << endl;
	cout << "Comment :=>> ------------------------------------------------" << endl;
	joc.mouFigura(-1);
	joc.giraFigura(GIR_ANTI_HORARI);
	joc.escriuTauler("./data/resultat_gir_figura_5.txt");
	correcte = comparaResultatPartida("./data/resultat_gir_figura_5.txt", "./data/resultat_esperat_gir_figura_5.txt");
	if (!correcte)
		reduccio += 0.5;

	// Gir prohibit limit dreta figura I
	cout << "Comment :=>> ------------------------------------------------" << endl;
	cout << "Comment :=>> TEST 6" << endl;
	joc.inicialitza("./data/test_gir_figura_6.txt");
	mostraFitxerInicial("./data/test_gir_figura_6.txt");
	cout << "Comment :=>> Moviments a partir de la configuracio inicial" << endl;
	cout << "Comment :=>>  - Gir horari" << endl;
	cout << "Comment :=>>  - Mou figura dreta" << endl;
	cout << "Comment :=>>  - Mou figura dreta" << endl;
	cout << "Comment :=>>  - Gir horari" << endl;
	cout << "Comment :=>> ------------------------------------------------" << endl;
	joc.giraFigura(GIR_HORARI);
	joc.mouFigura(1);
	joc.mouFigura(1);
	joc.giraFigura(GIR_HORARI);
	joc.escriuTauler("./data/resultat_gir_figura_6.txt");
	correcte = comparaResultatPartida("./data/resultat_gir_figura_6.txt", "./data/resultat_esperat_gir_figura_6.txt");
	if (!correcte)
		reduccio += 0.5;

	// Gir prohibit limit dreta figura I
	cout << "Comment :=>> ------------------------------------------------" << endl;
	cout << "Comment :=>> TEST 7" << endl;
	joc.inicialitza("./data/test_gir_figura_7.txt");
	mostraFitxerInicial("./data/test_gir_figura_7.txt");
	cout << "Comment :=>> Moviments a partir de la configuracio inicial" << endl;
	cout << "Comment :=>>  - Gir anti-horari" << endl;
	cout << "Comment :=>>  - Mou figura dreta" << endl;
	cout << "Comment :=>>  - Mou figura dreta" << endl;
	cout << "Comment :=>> ------------------------------------------------" << endl;
	joc.giraFigura(GIR_ANTI_HORARI);
	joc.mouFigura(1);
	joc.mouFigura(1);
	joc.escriuTauler("./data/resultat_gir_figura_7.txt");
	correcte = comparaResultatPartida("./data/resultat_gir_figura_7.txt", "./data/resultat_esperat_gir_figura_7.txt");
	if (!correcte)
		reduccio += 0.5;

	// Dos girs figura I
	cout << "Comment :=>> ------------------------------------------------" << endl;
	cout << "Comment :=>> TEST 8" << endl;
	joc.inicialitza("./data/test_gir_figura_8.txt");
	mostraFitxerInicial("./data/test_gir_figura_8.txt");
	cout << "Comment :=>> Moviments a partir de la configuracio inicial" << endl;
	cout << "Comment :=>>  - Gir anti-horari" << endl;
	cout << "Comment :=>>  - Gir anti-horari" << endl;
	cout << "Comment :=>> ------------------------------------------------" << endl;
	joc.giraFigura(GIR_ANTI_HORARI);
	joc.giraFigura(GIR_ANTI_HORARI);
	joc.escriuTauler("./data/resultat_gir_figura_8.txt");
	correcte = comparaResultatPartida("./data/resultat_gir_figura_8.txt", "./data/resultat_esperat_gir_figura_8.txt");
	if (!correcte)
		reduccio += 0.5;

	// Gir figura L enmig tauler valid
	cout << "Comment :=>> ------------------------------------------------" << endl;
	cout << "Comment :=>> TEST 9" << endl;
	joc.inicialitza("./data/test_gir_figura_9.txt");
	mostraFitxerInicial("./data/test_gir_figura_9.txt");
	cout << "Comment :=>> Moviments a partir de la configuracio inicial" << endl;
	cout << "Comment :=>>  - Gir horari" << endl;
	cout << "Comment :=>> ------------------------------------------------" << endl;
	joc.giraFigura(GIR_HORARI);
	joc.escriuTauler("./data/resultat_gir_figura_9.txt");
	correcte = comparaResultatPartida("./data/resultat_gir_figura_9.txt", "./data/resultat_esperat_gir_figura_9.txt");
	if (!correcte)
		reduccio += 0.5;

	// Gir figura L enmig tauler no valid
	cout << "Comment :=>> ------------------------------------------------" << endl;
	cout << "Comment :=>> TEST 10" << endl;
	joc.inicialitza("./data/test_gir_figura_10.txt");
	mostraFitxerInicial("./data/test_gir_figura_10.txt");
	cout << "Comment :=>> Moviments a partir de la configuracio inicial" << endl;
	cout << "Comment :=>>  - Mou figura dreta" << endl;
	cout << "Comment :=>>  - Gir horari" << endl;
	cout << "Comment :=>> ------------------------------------------------" << endl;
	joc.mouFigura(1);
	joc.giraFigura(GIR_HORARI);
	joc.escriuTauler("./data/resultat_gir_figura_10.txt");
	correcte = comparaResultatPartida("./data/resultat_gir_figura_10.txt", "./data/resultat_esperat_gir_figura_10.txt");
	if (!correcte)
		reduccio += 0.5;

	// Gir figura S enmig tauler valid
	cout << "Comment :=>> ------------------------------------------------" << endl;
	cout << "Comment :=>> TEST 11" << endl;
	joc.inicialitza("./data/test_gir_figura_11.txt");
	mostraFitxerInicial("./data/test_gir_figura_11.txt");
	cout << "Comment :=>> Moviments a partir de la configuracio inicial" << endl;
	cout << "Comment :=>>  - Gir horari" << endl;
	cout << "Comment :=>> ------------------------------------------------" << endl;
	joc.giraFigura(GIR_HORARI);
	joc.escriuTauler("./data/resultat_gir_figura_11.txt");
	correcte = comparaResultatPartida("./data/resultat_gir_figura_11.txt", "./data/resultat_esperat_gir_figura_11.txt");
	if (!correcte)
		reduccio += 0.5;

	// Gir figura S enmig tauler no valid
	cout << "Comment :=>> ------------------------------------------------" << endl;
	cout << "Comment :=>> TEST 12" << endl;
	joc.inicialitza("./data/test_gir_figura_12.txt");
	mostraFitxerInicial("./data/test_gir_figura_12.txt");
	cout << "Comment :=>> Moviments a partir de la configuracio inicial" << endl;
	cout << "Comment :=>>  - Gir anti-horari" << endl;
	cout << "Comment :=>> ------------------------------------------------" << endl;
	joc.giraFigura(GIR_ANTI_HORARI);
	joc.escriuTauler("./data/resultat_gir_figura_12.txt");
	correcte = comparaResultatPartida("./data/resultat_gir_figura_12.txt", "./data/resultat_esperat_gir_figura_12.txt");
	if (!correcte)
		reduccio += 0.5;

	// Gir figura J despres baixar no valid
	cout << "Comment :=>> ------------------------------------------------" << endl;
	cout << "Comment :=>> TEST 13" << endl;
	joc.inicialitza("./data/test_gir_figura_13.txt");
	mostraFitxerInicial("./data/test_gir_figura_13.txt");
	cout << "Comment :=>> Moviments a partir de la configuracio inicial" << endl;
	cout << "Comment :=>>  - Baixa figura" << endl;
	cout << "Comment :=>>  - Gir anti-horari" << endl;
	cout << "Comment :=>> ------------------------------------------------" << endl;
	joc.baixaFigura();
	joc.giraFigura(GIR_ANTI_HORARI);
	joc.escriuTauler("./data/resultat_gir_figura_13.txt");
	correcte = comparaResultatPartida("./data/resultat_gir_figura_13.txt", "./data/resultat_esperat_gir_figura_13.txt");
	if (!correcte)
		reduccio += 0.5;

	// Gir figura T despres baixar no valid
	cout << "Comment :=>> ------------------------------------------------" << endl;
	cout << "Comment :=>> TEST 14" << endl;
	joc.inicialitza("./data/test_gir_figura_14.txt");
	mostraFitxerInicial("./data/test_gir_figura_14.txt");
	cout << "Comment :=>> Moviments a partir de la configuracio inicial" << endl;
	cout << "Comment :=>>  - Baixa figura" << endl;
	cout << "Comment :=>>  - Gir anti-horari" << endl;
	cout << "Comment :=>> ------------------------------------------------" << endl;
	joc.baixaFigura();
	joc.giraFigura(GIR_ANTI_HORARI);
	joc.escriuTauler("./data/resultat_gir_figura_14.txt");
	correcte = comparaResultatPartida("./data/resultat_gir_figura_14.txt", "./data/resultat_esperat_gir_figura_14.txt");
	if (!correcte)
		reduccio += 0.5;

	// Gir figura O 
	cout << "Comment :=>> ------------------------------------------------" << endl;
	cout << "Comment :=>> TEST 15" << endl;
	joc.inicialitza("./data/test_gir_figura_15.txt");
	mostraFitxerInicial("./data/test_gir_figura_15.txt");
	cout << "Comment :=>> Moviments a partir de la configuracio inicial" << endl;
	cout << "Comment :=>>  - Mou figura dreta" << endl;
	cout << "Comment :=>>  - Gir horari" << endl;
	cout << "Comment :=>> ------------------------------------------------" << endl;
	joc.mouFigura(1);
	joc.giraFigura(GIR_HORARI);
	joc.escriuTauler("./data/resultat_gir_figura_15.txt");
	correcte = comparaResultatPartida("./data/resultat_gir_figura_15.txt", "./data/resultat_esperat_gir_figura_15.txt");
	if (!correcte)
		reduccio += 0.5;
	grade += (3.0 - reduccio);
	cout << "Comment :=>> ------------------------------------------------" << endl;
	cout << "Comment :=>> " << endl;
	cout << "Grade :=>> " << grade << endl << endl;
	cout << "Comment :=>> " << endl;





	cout << "Comment :=>>  =====================================" << endl;
	cout << "Comment :=>> | TEST ELIMINA FILES                  |" << endl;
	cout << "Comment :=>>  =====================================" << endl;
	cout << "Comment :=>> " << endl;
	reduccio = 0.0;
	// Elimina ultima fila
	cout << "Comment :=>> ------------------------------------------------" << endl;
	cout << "Comment :=>> TEST 1" << endl;
	joc.inicialitza("./data/test_elimina_files_1.txt");
	mostraFitxerInicial("./data/test_elimina_files_1.txt");
	cout << "Comment :=>> Moviments a partir de la configuracio inicial" << endl;
	cout << "Comment :=>>  - Baixa figura" << endl;
	cout << "Comment :=>>  - Baixa figura" << endl;
	cout << "Comment :=>> ------------------------------------------------" << endl;
	joc.baixaFigura();
	joc.baixaFigura();
	joc.escriuTauler("./data/resultat_elimina_files_1.txt");
	correcte = comparaResultatPartida("./data/resultat_elimina_files_1.txt", "./data/resultat_esperat_elimina_files_1.txt");
	if (!correcte)
		reduccio += 0.5;

	// Elimina penultima fila
	cout << "Comment :=>> ------------------------------------------------" << endl;
	cout << "Comment :=>> TEST 2" << endl;
	joc.inicialitza("./data/test_elimina_files_2.txt");
	mostraFitxerInicial("./data/test_elimina_files_2.txt");
	cout << "Comment :=>> Moviments a partir de la configuracio inicial" << endl;
	cout << "Comment :=>>  - Mou figura dreta" << endl;
	cout << "Comment :=>>  - Baixa figura" << endl;
	cout << "Comment :=>>  - Baixa figura" << endl;
	cout << "Comment :=>> ------------------------------------------------" << endl;
	joc.mouFigura(1);
	joc.baixaFigura();
	joc.baixaFigura();
	joc.escriuTauler("./data/resultat_elimina_files_2.txt");
	correcte = comparaResultatPartida("./data/resultat_elimina_files_2.txt", "./data/resultat_esperat_elimina_files_2.txt");
	if (!correcte)
		reduccio += 0.5;

	// Elimina fila dalt
	cout << "Comment :=>> ------------------------------------------------" << endl;
	cout << "Comment :=>> TEST 3" << endl;
	joc.inicialitza("./data/test_elimina_files_3.txt");
	mostraFitxerInicial("./data/test_elimina_files_3.txt");
	cout << "Comment :=>> Moviments a partir de la configuracio inicial" << endl;
	cout << "Comment :=>>  - Baixa figura" << endl;
	cout << "Comment :=>> ------------------------------------------------" << endl;
	joc.baixaFigura();
	joc.escriuTauler("./data/resultat_elimina_files_3.txt");
	correcte = comparaResultatPartida("./data/resultat_elimina_files_3.txt", "./data/resultat_esperat_elimina_files_3.txt");
	if (!correcte)
		reduccio += 0.5;

	// Elimina dues files seguides
	cout << "Comment :=>> ------------------------------------------------" << endl;
	cout << "Comment :=>> TEST 4" << endl;
	joc.inicialitza("./data/test_elimina_files_4.txt");
	mostraFitxerInicial("./data/test_elimina_files_4.txt");
	cout << "Comment :=>> Moviments a partir de la configuracio inicial" << endl;
	cout << "Comment :=>>  - Mou figura dreta" << endl;
	cout << "Comment :=>>  - Baixa figura" << endl;
	cout << "Comment :=>>  - Baixa figura" << endl;
	cout << "Comment :=>>  - Baixa figura" << endl;
	cout << "Comment :=>>  - Baixa figura" << endl;
	cout << "Comment :=>> ------------------------------------------------" << endl;
	joc.mouFigura(1);
	joc.baixaFigura();
	joc.baixaFigura();
	joc.baixaFigura();
	joc.baixaFigura();
	joc.escriuTauler("./data/resultat_elimina_files_4.txt");
	correcte = comparaResultatPartida("./data/resultat_elimina_files_4.txt", "./data/resultat_esperat_elimina_files_4.txt");
	if (!correcte)
		reduccio += 0.5;

	// Elimina dues files alternes
	cout << "Comment :=>> ------------------------------------------------" << endl;
	cout << "Comment :=>> TEST 5" << endl;
	joc.inicialitza("./data/test_elimina_files_5.txt");
	mostraFitxerInicial("./data/test_elimina_files_5.txt");
	cout << "Comment :=>> Moviments a partir de la configuracio inicial" << endl;
	cout << "Comment :=>>  - Mou figura dreta" << endl;
	cout << "Comment :=>>  - Baixa figura" << endl;
	cout << "Comment :=>>  - Baixa figura" << endl;
	cout << "Comment :=>>  - Baixa figura" << endl;
	cout << "Comment :=>>  - Baixa figura" << endl;
	cout << "Comment :=>> ------------------------------------------------" << endl;
	joc.mouFigura(1);
	joc.baixaFigura();
	joc.baixaFigura();
	joc.baixaFigura();
	joc.baixaFigura();
	joc.escriuTauler("./data/resultat_elimina_files_5.txt");
	correcte = comparaResultatPartida("./data/resultat_elimina_files_5.txt", "./data/resultat_esperat_elimina_files_5.txt");
	if (!correcte)
		reduccio += 0.5;

	// Elimina tres files
	cout << "Comment :=>> ------------------------------------------------" << endl;
	cout << "Comment :=>> TEST 6" << endl;
	joc.inicialitza("./data/test_elimina_files_6.txt");
	mostraFitxerInicial("./data/test_elimina_files_6.txt");
	cout << "Comment :=>> Moviments a partir de la configuracio inicial" << endl;
	cout << "Comment :=>>  - Mou figura dreta" << endl;
	cout << "Comment :=>>  - Baixa figura" << endl;
	cout << "Comment :=>>  - Baixa figura" << endl;
	cout << "Comment :=>>  - Baixa figura" << endl;
	cout << "Comment :=>>  - Baixa figura" << endl;
	cout << "Comment :=>> ------------------------------------------------" << endl;
	joc.mouFigura(1);
	joc.baixaFigura();
	joc.baixaFigura();
	joc.baixaFigura();
	joc.baixaFigura();
	joc.escriuTauler("./data/resultat_elimina_files_6.txt");
	correcte = comparaResultatPartida("./data/resultat_elimina_files_6.txt", "./data/resultat_esperat_elimina_files_6.txt");
	if (!correcte)
		reduccio += 0.5;

	// Elimina quatre files
	cout << "Comment :=>> ------------------------------------------------" << endl;
	cout << "Comment :=>> TEST 7" << endl;
	joc.inicialitza("./data/test_elimina_files_7.txt");
	mostraFitxerInicial("./data/test_elimina_files_7.txt");
	cout << "Comment :=>> Moviments a partir de la configuracio inicial" << endl;
	cout << "Comment :=>>  - Mou figura dreta" << endl;
	cout << "Comment :=>>  - Baixa figura" << endl;
	cout << "Comment :=>>  - Baixa figura" << endl;
	cout << "Comment :=>>  - Baixa figura" << endl;
	cout << "Comment :=>>  - Baixa figura" << endl;
	cout << "Comment :=>>  - Baixa figura" << endl;
	cout << "Comment :=>> ------------------------------------------------" << endl;
	joc.mouFigura(1);
	joc.baixaFigura();
	joc.baixaFigura();
	joc.baixaFigura();
	joc.baixaFigura();
	joc.baixaFigura();
	joc.escriuTauler("./data/resultat_elimina_files_7.txt");
	correcte = comparaResultatPartida("./data/resultat_elimina_files_7.txt", "./data/resultat_esperat_elimina_files_7.txt");
	if (!correcte)
		reduccio += 0.5;

	grade += (3.0 - reduccio);
	cout << "Comment :=>> ------------------------------------------------" << endl;
	cout << "Comment :=>> " << endl;
	if (grade < 0)
		grade = 0;
	cout << "Grade :=>> " << grade << endl << endl;
	cout << "Comment :=>> " << endl;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Comment :=>> " << endl;


	return 0;
}

void globalConfigModul()
{
	string path;
	cout << "Paste here the path of Global config .txt\nLet the space blank for default configuration";
	getline(cin, path);//copyright Qiu,haocheng Daniel 2023-2024


}

SDL_Color PALETTE[9] = {
	SDL_Color{.r = 0,.g = 0,.b = 0,.a = 255},
	SDL_Color{.r = 255,.g = 255,.b = 0,.a = 255},
	SDL_Color{.r = 0,.g = 255,.b = 255,.a = 255},
	SDL_Color{.r = 128,.g = 0,.b = 128,.a = 255},
	SDL_Color{.r = 255,.g = 127,.b = 0,.a = 255},
	SDL_Color{.r = 0,.g = 0,.b = 255,.a = 255},
	SDL_Color{.r = 255,.g = 0,.b = 0,.a = 255},
	SDL_Color{.r = 0,.g = 255,.b = 0,.a = 255},
	SDL_Color{.r = 127,.g = 127,.b = 127,.a = 255},
};

inline SDL_Color paletteToRGB(int color) { return PALETTE[color]; }

int main() {
	bool testMode =0;
	if (testMode)
	{
		test_main();
	}
	else
	{
		//globalConfigModul();
		SDL_Init(SDL_INIT_EVERYTHING);
		SDL_Window* win = SDL_CreateWindow("tetris", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
		SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_PRESENTVSYNC);
		Joc joc;

		joc.inicialitza("./data/test_elimina_files_7.txt");

		SDL_Event e;
		bool running = true;
		SDL_SetRenderDrawColor(ren, 0, 255, 100, 255);
		while (running) {
			while (SDL_PollEvent(&e))
			{
				switch (e.type)
				{
				case SDL_QUIT:
					running = false;
					break;
				case SDL_KEYDOWN:
					switch (e.key.keysym.scancode)
					{
					case SDL_SCANCODE_SPACE:
						joc.escriuTauler("test.txt");
						break;
					case SDL_SCANCODE_R:
						joc.giraFigura(GIR_HORARI);
						break;
					case SDL_SCANCODE_E:
						joc.giraFigura(GIR_ANTI_HORARI);
						break;
					case SDL_SCANCODE_S:
						joc.baixaFigura();
						break;
					case SDL_SCANCODE_W:
						joc.mouFigura2(0, -1);
						break;
					case SDL_SCANCODE_A:
						joc.mouFigura2(-1, 0);
						break;
					case SDL_SCANCODE_D:
						joc.mouFigura2(1, 0);
						break;
					}
					break;
				}
			}
			SDL_SetRenderDrawColor(ren, 0, 255, 100, 255);
			SDL_RenderClear(ren);

			Tauler* tauler = joc.getTauler();
			for (int y = 0; y < MAX_FILA; ++y) {
				for (int x = 0; x < MAX_COL; ++x) {
					SDL_Rect rect;
					rect.x = x * 64;
					rect.y = y * 64;
					rect.w = 64;
					rect.h = 64;
					SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
					SDL_RenderFillRect(ren, &rect);

					rect.x = x * 64 + 2;
					rect.y = y * 64 + 2;
					rect.w = 64 - 4;
					rect.h = 64 - 4;
					SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
					SDL_RenderFillRect(ren, &rect);

					int color = tauler->getPixel(y, x);
					if (color != COLOR_NEGRE) {
						rect.x = x * 64;
						rect.y = y * 64;
						rect.w = 64;
						rect.h = 64;
						SDL_Color col = paletteToRGB(color);
						SDL_SetRenderDrawColor(ren, col.r, col.g,
							col.b, col.a);
						SDL_RenderFillRect(ren, &rect);


					}
				}
			}
			for (int y = 0; y < joc.getFigura()->getSize(); y++)
			{
				for (int x = 0; x < joc.getFigura()->getSize(); x++)
				{
					const int color =
						joc.getFigura()->getPixel(x, y);
					if (color != COLOR_NEGRE)
					{
						SDL_Rect rect;
						rect.x = (joc.getFigura()->getX() + x) * 64;
						rect.y = (joc.getFigura()->getY() + y) * 64;
						rect.w = 64;
						rect.h = 64;

						SDL_Color col = paletteToRGB(color);
						SDL_SetRenderDrawColor(ren, col.r,
							col.g, col.b
							,
							col.a);
						SDL_RenderFillRect(ren, &rect);

					}
				}
			}

			SDL_RenderPresent(ren);
		}

		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
		SDL_Quit();
	}
	return 0;
}
