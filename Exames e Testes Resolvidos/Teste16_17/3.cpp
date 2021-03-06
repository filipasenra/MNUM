// 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

/**
* @brief operacoes entre linhas da matriz
* 
* @param matriz
* @param linha que irá ser alvo da operacao
* @param linha a subtrair
* @param quociente a retirar
*/
void rowop(vector<vector<double>> & m, unsigned int a, unsigned int b, double k) {
	for (unsigned int i = 0; i < m[a].size(); i++)
	{
		m[a][i] -= k * m[b][i];
	}
}

void gauss(vector<vector<double>> & m)
{
	//ira percorrer cada linha para encontrar o pivo
	for (unsigned int i = 0; i < m.size(); i++)
	{
		//colocar pivo a 1
		rowop(m, i, i, 1 - 1 / m[i][i]);

		//de acordo com o pivo, modifica todas as outras linhas
		for (unsigned int j = 0; j < m.size(); j++)
		{
			if (j != i)
				rowop(m, j, i, m[j][i]);
		}
	}
}

void printmatrix(vector<vector<double>> m)
{
	for (unsigned int i = 0; i < m.size(); i++)
	{
		for (unsigned int j = 0; j < m[i].size(); j++)
			cout << m[i][j] << "    ";

		cout << endl;
	}
}

int main()
{
    cout << "Gauss\n"; 

	vector<vector<double>> m = { {0.7, 8, 3, 12} , {-6, 0.45, -0.25, 15},
								{8, -3.1, 1.05, 23} };

	gauss(m);
	printmatrix(m);

	return 0;
}
