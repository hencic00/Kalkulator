#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <string.h>

#include <calculator.h>

// #include <benchmark-master/include/benchmark/benchmark.h>



// static void bm(benchmark::State& state)
// {
// 	readAsCharArray("tables.csv");
// }

int main()
{
	Calculator *t = new Calculator();
	t->parseFile("./tables.csv");
	t->printActiveTables();
	t->printTableByName("table1");


	//commitment

   return 0;
}