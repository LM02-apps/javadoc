#include <iostream>
#include <string.h>

using namespace std;

struct Stock
{
	char casa[26];
	char nomeFarmaco[26];
	float prezzo;
	char data[26];
	int quant;
	char forma[2];
}stock[100];


bool ricerca(Stock stock[], Stock nuovostock, int ll, int& pos)
{
	pos = 0;

	for (pos = 0; pos < ll; pos++)
	{
		if (strcmp(nuovostock.data, stock[pos].data) < 0)
		{
			return false;
		}
	}
	return false;

}

int inserimento(Stock stock[], int ll, int lf, Stock nuovostock)
{
	int i = 0;
	int j = 0;
	int pos = 0;
	int controllo = false;


	controllo = ricerca(stock, nuovostock, ll, pos);
	ll++;
	if (controllo == false)
	{
		for (j = ll; j > pos; j--)
		{
			stock[j] = stock[j - 1];
		}
	}
	stock[pos] = nuovostock;
	return ll;
}


float totale(Stock stock[], int ll)
{
	int i = 0;
	float somma = 0;
	for (i = 0; i < ll; i++)
	{
		somma =somma+ stock[i].quant;
		
	}
	return somma;
}



void visualizzaScadenza(Stock stock[], int ll, char data[])
{
	int i = 0;
	for (i = 0; i < ll; i++)
	{
		if (strcmp(stock[i].data, data) < 0)
		{
			cout << "Casa Produttrice: " << stock[i].casa << endl;
			cout << "Nome: " << stock[i].nomeFarmaco << endl;
			cout << "Forma " << stock[i].forma << endl;
			cout << "Prezzo: " << stock[i].prezzo << endl;
			cout << "Scadenza: " << stock[i].data << endl;
			cout << "Quantita: " << stock[i].quant << endl;
			cout << "____________" << endl;
		}
	}
}


void visualizzaCosto(Stock stock[], int ll, float min, float max)
{
	int i = 0;
	for (i = 0; i < ll; i++)
	{
		if (stock[i].prezzo<max && stock[i].prezzo > min)
		{
			cout << "Casa Produttrice: " << stock[i].casa << endl;
			cout << "Nome: " << stock[i].nomeFarmaco << endl;
			cout << "Forma " << stock[i].forma << endl;
			cout << "Prezzo: " << stock[i].prezzo << endl;
			cout << "Scadenza: " << stock[i].data << endl;
			cout << "Quantita: " << stock[i].quant << endl;
			cout << "____________" << endl;
		}
	}
}


void visualizzaCasa(Stock stock[], int ll, char casa[])
{
	int i = 0;
	for (i = 0; i < ll ;i++)
	{
		if (strcmp(stock[i].casa, casa) == 0)
		{
			cout << "Casa Produttrice: " << stock[i].casa << endl;
			cout << "Nome: " << stock[i].nomeFarmaco << endl;
			cout << "Forma " << stock[i].forma << endl;
			cout << "Prezzo: " << stock[i].prezzo << endl;
			cout << "Scadenza: " << stock[i].data << endl;
			cout << "Quantita: " << stock[i].quant << endl;
			cout << "____________" << endl;
		}
	}
}


bool decrementa(Stock stock[], int ll, char nomeFarmaco[], int quant)
{
	int i = 0;
	float sottrazione = 0;
	for (i = 0; i < ll; i++)
	{
		if (strcmp(stock[i].nomeFarmaco, nomeFarmaco) == 0)
		{
			stock[i].quant= stock[i].quant - quant;
			return true;
		}
	}
}


int elimina(Stock stock[], int ll)
{
	int i = 0;
	
	for (i = 0; i < ll; i++)
	{
		if (stock[i].quant == 0)
		{
			for (int j = i; j < ll; j++)
			{
				stock[j] = stock[j + 1];
			}
			ll--;
		}
	}
	return ll;
}



void main()
{
	const int lf = 100;
	int ll=0;
	float min=0;
	float max=0;
	Stock stock[lf];
	Stock nuovostock;
	int scelta=0;
	int i = 0;
	char casa[10];
	char data[26];
	float somma = 0;
	char Farmaco[10];
	char nomeFarmaco[10];
	int quant;
	bool decremento;
	do
	{

		cout << "\n1-Inserimento" << endl;
		cout << "2-Calcolo" << endl;
		cout << "3-Visualizzazione per data di scadenza" << endl;
		cout << "4-Visualizzazione tra valori" << endl;
		cout << "5-Visualizzazione prodotti casa produttrice" << endl;
		cout << "6-Decremento" << endl;
		cout << "7-Eliminazione" << endl;
		cout << "8-Esci" << endl;
		cin >> scelta;
		switch (scelta)
		{
			case 1:
				
				cout << "Inserire la casa produttrice" << endl;
				cin >> nuovostock.casa;
				cout << "Inserire il nome del farmaco" << endl;
				cin >> nuovostock.nomeFarmaco;
				cout << "Inserire la forma" << endl;
				cin >> nuovostock.forma;
				cout << "Inserire il prezzo" << endl;
				cin >> nuovostock.prezzo;
				cout << "Inserire la data di scadenza" << endl;
				cin >> nuovostock.data;
				cout << "Inserire la quantita'"<<endl;
				cin >> nuovostock.quant;
				ll = inserimento(stock, ll, lf, nuovostock);
				break;
			
			case 2:
	
				somma=totale (stock, ll);
				cout << "la somma totale dei prodotti e': " << endl<<somma;
				break;
			
			case 3:
				/*
				for (i = 0; i < ll; i++)
				{
					cout << "Casa Produttrice: " << stock[i].casa << endl;
					cout << "Nome: " << stock[i].NomeFarmaco << endl;
					cout << "Forma " << stock[i].forma << endl;
					cout << "Prezzo: " << stock[i].prezzo << endl;
					cout << "Scadenza: " << stock[i].data << endl;
					cout << "Quantita: " << stock[i].quant << endl;
					cout << "____________" << endl;
				}
				*/
				cout << "Inserire la data di scadenza" << endl;
				cin >> data;
				visualizzaScadenza(stock, ll, data);
				break;
			
			case 4:
				cout << "Inserire il valore minore" << endl;
				cin >> min;
				cout << "Inserire il valore maggiore" << endl;
				cin >> max;
				visualizzaCosto(stock, ll, min, max);
				break;
			
			case 5:
				cout << "Inserire la casa produttrice:" << endl;
				cin >> casa;
				visualizzaCasa(stock, ll, casa);
				break;
			
			case 6:
				cout << "Inserire il nome del farmaco:" << endl;
				cin >> nomeFarmaco;
				cout << "Inserire la quantita' da decrementare:" << endl;
				cin >> quant;
				decremento=decrementa(stock, ll, nomeFarmaco, quant);
				if (decremento == true)
				{
					cout << "Il decremento e' andato a buon fine";
				}
				else
				{
					cout << "Il nome del farmaco non e' stato trovato" << endl;
				}
				break;
			
			case 7:
				ll = elimina(stock, ll);
				break;

		}
	} while (scelta != 8);
}