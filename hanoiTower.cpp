#include <stack>
#include <iostream>
using namespace std;
int cont = 0;
stack <int> torre1;
stack <int> torre2;
stack <int> torre3;

int Movimenta(int de, int para)
{	
	switch (de)                                // a jogada soh eh validada se a torre nao estiver vazia
	{                                          // e se a peça de origem for menor que a do destino.
	case 1:
		if (!torre1.empty())
		{
			if (para == 2)
			{
				if (torre2.size() == 0)
				{
					torre2.push(torre1.top());
					torre1.pop();
					cont++;

				}
				else if (torre1.top() < torre2.top())
				{
					torre2.push(torre1.top());
					torre1.pop();
					cont++;
				}
				else
				{
					cout << " n eh possvivel" << endl;
				}

			}

			if (para == 3 && !torre1.empty())
			{
				if (torre3.size() == 0)
				{
					torre3.push(torre1.top());
					torre1.pop();
					cont++;
				}
				else if (torre1.top() < torre3.top())
				{
					torre3.push(torre1.top());
					torre1.pop();
					cont++;
				}
				else
				{
					cout << " n eh possvivel" << endl;
				}
			}
		}

		
		
		break;

	case 2:
		if (!torre2.empty())
		{

			if (para == 1)
			{
				if (torre1.size() == 0)
				{
					torre1.push(torre2.top());
					torre2.pop();
					cont++;
				}
				else if (torre2.top() < torre1.top())
				{
					torre1.push(torre2.top());
					torre2.pop();
					cont++;
				}
				else
				{
					cout << "nao eh possivel" << endl;
				}
			}

			if (para == 3)
			{
				if (torre3.size() == 0)
				{
					torre3.push(torre2.top());
					torre2.pop();
					cont++;
				}
				else if (torre2.top() < torre3.top())
				{
					torre3.push(torre2.top());
					torre2.pop();
					cont++;
				}
				
			}

			break;
		}
		else
		{
			cout << "nao eh possivel" << endl;
		}
	case 3:
		if (!torre3.empty())
		{
			if (para == 1)
			{
				if (torre1.size() == 0)
				{
					torre1.push(torre3.top());
					torre3.pop();
					cont++;
				}
				else if (torre3.top() < torre1.top())
				{
					torre1.push(torre3.top());
					torre3.pop();
					cont++;
				}
				else
				{
					cout << "nao eh possivel" << endl;
				}
			}
			if (para == 2)
			{
				if (torre2.size() == 0)
				{
					torre2.push(torre3.top());
					torre3.pop();
					cont++;
				}
				else if (torre3.top() < torre2.top())
				{
					torre2.push(torre3.top());
					torre3.pop();
					cont++;
				}
				else
				{
					cout << "nao eh possivel" << endl;
				}
			}
		}

		

	default:
		break;
	}
	return cont;                             // retorna o numero de jogadas
}

void Imprime()
{
	stack <int> temp1;
	stack <int> temp2;
	stack <int> temp3;
	int i = 0;

	//----------------------------------------------------------------- imprime torre 1 

	while (!torre1.empty())
	{
			for (int j = torre1.size() -1; j >= 0; j--)
			{
				cout << " ";
			}
			
			for (int k = torre1.top() - 1; k >= 0; k--)
			{
				cout << "* ";				
			}
			i++;
			cout << endl;
			temp1.push(torre1.top());
			torre1.pop();
			i++;			
		}
		cout << "-----------------------------" << endl << endl;
		while (!temp1.empty())
		{
			torre1.push(temp1.top());
			temp1.pop();
		}

	//----------------------------------------------------------------- imprime torre 2
		if (!torre2.empty())
		{
			while (!torre2.empty())
			{
				for (int j = torre2.size() - 1; j >= 0; j--)
				{
					cout << " ";
				}

				for (int k = torre2.top() - 1; k >= 0; k--)
				{
					cout << "* ";
				}
				i++;
				cout << endl;
				temp2.push(torre2.top());
				torre2.pop();
				i++;

			}
			cout << "-----------------------------" << endl << endl;
			while (!temp2.empty())
			{
				torre2.push(temp2.top());
				temp2.pop();
			}
		}
		else
		{
			for (int i = 0; i < 5; i++)
			{
				cout << "     |" << endl;
			}
			cout << "-----------------------------" << endl << endl;
		}		

		//----------------------------------------------------------------- imprime torre 3

		if (!torre3.empty())
		{
			while (!torre3.empty())
			{
				for (int j = torre3.size() - 1; j >= 0; j--)
				{
					cout << " ";
				}

				for (int k = torre3.top() - 1; k >= 0; k--)
				{
					cout << "* ";
				}
				i++;
				cout << endl;
				temp3.push(torre3.top());
				torre3.pop();
				i++;

			}
			cout << "-----------------------------" << endl << endl;
			while (!temp3.empty())
			{
				torre3.push(temp3.top());
				temp3.pop();
			}
		}
		else
		{
			for (int i = 0; i < 5; i++)
			{
				cout << "     |" << endl;
			}
			cout << "-----------------------------" << endl << endl;
		}
}

void Preenche(int qnt)                // Preenche a torre 1 com a quantidade de discos
{
	for (int i = qnt; i > 0; i--)
	{
		torre1.push(i);
	}
}

void Jogo()
{
	int de, para;
	int discos;
	int cont = 0;
	bool continua = true;

	cout << "insira a quantidade de discos: ";
	cin >> discos;
	Preenche(discos);	
	while (continua)
	{				
		Imprime();
		cout << "insira a torre que de origem: ";
		cin >> de;
		cout << "insira a torre de destino: ";
		cin >>para;
		Movimenta(de, para);		
		if (torre1.empty())
		{
			if (torre2.size() == discos)
			{
				continua = false;
			}
			if (torre3.size() == discos)
			{
				continua = false;
			}			
		}	
		system("cls");
	}
	cout << "Parabens, voce terminou utilizando apenas: " << Movimenta(de,para) << " turnos";
}

int main()
{
	Jogo();
}

