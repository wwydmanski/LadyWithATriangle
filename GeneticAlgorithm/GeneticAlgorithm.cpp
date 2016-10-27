#include "stdafx.h"
#include "Population.h"
#include "Evolve.h"

#include <iostream>
#include <cstdio>
#include <ctime>

int main()
{
	srand(10);
	int j = 0;
	int sum = 0;
	std::clock_t start;

	Fitness * solution;
	Population * test;
	Evolve * evolution;

	//Test variables
	int eliteNumbers[4] = { 3,3,3,3 };
	int populationNumbers[2] = { 10,50 };
	int repetitions = 20;

	for (int e = 0;e < 4;e++)
	{
		for (int p = 0; p < 2; p++)
		{
			for (j; j < repetitions; j++)
			{
				string solutionGenes;
				for (int i = 0;i < 64;i++)
					if (rand() % 2 == 0)
						solutionGenes += '0';
					else
						solutionGenes += '1';

				srand(rand());

				start = std::clock();

				solution = new Fitness(solutionGenes);
				test = new Population(populationNumbers[p], true);
				evolution = new Evolve(*test, *solution, eliteNumbers[e]);

				int i = 0;
				for (i; (*test).getFittest(*solution).fitness(*solution) != 64; i++)
					(*evolution).EvolvePop();

				sum += i;
				if (j % 5 == 0)
					printf("\rRepetitions: %i", j);
				delete solution;
				delete test;
				delete evolution;
			}
			float average = sum / repetitions;
			double timer = (std::clock() - start) / (double)CLOCKS_PER_SEC;
			
			sum = 0;
			start = clock();

			printf("\rElites: %i, Population: %i\n", eliteNumbers[e], populationNumbers[p]);
			printf("Average of generations needed: %2f\n", average);
			printf("Time needed: %4.1f s\n\n", timer);
			j = 0;
		}
	}

	cin.get();
}

