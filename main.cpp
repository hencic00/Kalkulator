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
	Calculator *t = NULL;
	std::string userInput = "";
	while(true)
	{
		std::cout << "Tabelni kalkulator: ";
		std::cin >> userInput;

		if(userInput == "init") //preberi datoteke in jih shrani
		{
			//delete t? ADD DA NEBO MEMORY LEAK!!
			t = new Calculator();
			t->parseFile("./tables.csv");
			t->printActiveTables();
			t->printTableByName("table1");
		}
		else if(userInput == "tables")
		{
			t->printActiveTables();
		}
		else if(userInput == "asd")//TESTING ZBRISI POL
		{
			t->sumTables("table1", "table2fe");
			t->resultTable->print();

			t->substractTables("table1","table2fe");
			t->resultTable->print();

			t->divideTables("table1","table2fe");
			t->resultTable->print();

			t->prodTables("table1","table2fe");
			t->resultTable->print();
		}
		else if(userInput == "math") // if(table == NULL) shit goes crazy
		{
			std::cout << "S ~ single table operations\nM ~ multiple table operations\n";
			std::cin >> userInput;

			if(userInput == "S")				//seštevek, zmnožek vseh elementov
			{

				while(true)
				{
					std::cout << "\nUsage: tableName operator\nSUM ~ sum,\nPROD ~ product,\nMAX ~ max element,\nMIN ~ min element\nexit ~ return to main\n";
					std::string userInputTableName = "";
					std::cin >> userInputTableName;
					if(userInputTableName == "exit")
					{
						break;
					}
					std::cin >> userInput;

					if(!t->tableMapContains(userInputTableName))
					{
						std::cout << "\nPlease select a table from the list:\n";
						t->printActiveTables();
						continue;
					}
					else if(userInput != "MAX" && userInput != "MIN" && userInput != "SUM" && userInput != "PROD")
					{
						std::cout << "Invalid operator.";
					}


					if(userInput == "MAX")
					{
						std::cout<<t->tableMap[userInputTableName]->maxElement()<<std::endl;
					}
					else if(userInput == "MIN")
					{
						std::cout<<t->tableMap[userInputTableName]->minElement()<<std::endl;
					}
					else if(userInput == "SUM")
					{
						std::cout<<t->tableMap[userInputTableName]->sumElements()<<std::endl;
					}
					else if(userInput == "PROD")
					{
						std::cout<<t->tableMap[userInputTableName]->prodElements()<<std::endl;
					}
				}
				std::cout<<std::endl;

			}
			else if(userInput == "M")				//operacije nad več tabelami, celotni line naenkrat vzamemo in parsamo
			{
				while(userInput != "exit")
				{
					std::cout << "\nEnter data to be calculated (example:\tA + B * C)\n";
					std::getline (std::cin, userInput);
					std::cout<<userInput<<std::endl;	
				}
			}
		}
		else if(userInput == "help")
		{
			std::cout<<"init ~ initialize calculator\nmath ~ begin mathematical operations\ntables ~ print active tables\nhelp ~ view help\nquit ~ exit the program\n\n";
		}
		else if(userInput == "quit")
		{
			std::cout << "Peace out!\n";
			break;
		}
		else
		{
			std::cout<<"Wrong user input. Type \"help\" for more information or \"quit\" to quit.\n\n";
		}
	}

   return 0;
}