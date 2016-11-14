#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <string.h>
#include <ncurses.h>

#include <calculator.h>

// #include <benchmark-master/include/benchmark/benchmark.h>



// static void bm(benchmark::State& state)
// {
// 	readAsCharArray("tables.csv");
// }

int main()
{
	// Calculator *t = NULL;
	// std::string userInput = "";
	char userInput[80] = "";
	// while(true)
	// {
	// 	std::cout << "Tabelni kalkulator: ";
	// 	std::cin >> userInput;

	// 	if(userInput == "init") //preberi datoteke in jih shrani
	// 	{
	// 		//delete t? ADD DA NEBO MEMORY LEAK!!
	// 		t = new Calculator();
	// 		t->parseFile("./tables.csv");
	// 		t->printActiveTables();
	// 		t->printTableByName("table1");
	// 	}
	// 	else if(userInput == "math") // if(table == NULL) shit goes crazy
	// 	{
	// 		std::cout << "S ~ single table operations\nM ~ multiple table operations\n";
	// 		std::cin >> userInput;

	// 		if(userInput == "S")				//seštevek, zmnožek vseh elementov
	// 		{
	// 			while(userInput != "exit")
	// 			{
	// 				std::cout << "\nSUM ~ sum,\nPROD ~ product,\nMAX ~ max element,\nMIN ~ min element\nexit ~ return to main\n";

	// 				std::cin >> userInput;
	// 				if(userInput == "MAX")
	// 				{
	// 					std::cout<<t->tableMap["table1"]->maxElement()<<std::endl;
	// 				}
	// 				else if(userInput == "MIN")
	// 				{
	// 					std::cout<<t->tableMap["table1"]->minElement()<<std::endl;
	// 				}
	// 				else if(userInput == "SUM")
	// 				{
	// 					std::cout<<t->tableMap["table1"]->sumElements()<<std::endl;
	// 				}
	// 				else if(userInput == "PROD")
	// 				{
	// 					std::cout<<t->tableMap["table1"]->prodElements()<<std::endl;
	// 				}
	// 			}
	// 			std::cout<<std::endl;

	// 		}
	// 		else if(userInput == "M")				//operacije nad več tabelami, celotni line naenkrat vzamemo in parsamo
	// 		{
	// 			while(userInput != "exit")
	// 			{
	// 				std::cout << "\nEnter data to be calculated (example:\tA + B * C)\n";
	// 				std::getline (std::cin, userInput);
	// 				std::cout<<userInput<<std::endl;	
	// 			}
	// 		}
	// 	}
	// 	else if(userInput == "help")
	// 	{
	// 		std::cout<<"init ~ initialize calculator\nmath ~ begin mathematical operations\nhelp ~ view help\nquit ~ exit the program\n\n";
	// 	}
	// 	else if(userInput == "quit")
	// 	{
	// 		std::cout << "Peace out!\n";
	// 		break;
	// 	}
	// 	else
	// 	{
	// 		std::cout<<"Wrong user input. Type \"help\" for more information or \"quit\" to quit.\n\n";
	// 	}
	// }

	initscr();
	cbreak();

	Calculator *t = NULL;
	t = new Calculator();
	t->parseFile("./tables.csv");

	while(true)
	{

		if(!strcmp(userInput, "help"))
		{
			mvprintw(0, 0, "init ~ initialize calculator\nmath ~ begin mathematical operations\nhelp ~ view help\nquit ~ exit the program\n\n");
		}
		else if (!strcmp(userInput, "quit"))
		{
			break;
		}
		else if (strcmp(userInput, ""))
		{
			char* parsedContent = strtok (userInput," ");
			if (!strcmp(parsedContent, "print"))
			{
				parsedContent = strtok (NULL," ");

				if (!strcmp(parsedContent, "tables"))
				{
					t->printActiveTables();
				}
				else if (strcmp(parsedContent, "tables"))
				{
					t->printTableByName(parsedContent);
				}

			}
			else if (!strcmp(parsedContent, "max"))
			{
				parsedContent = strtok (NULL," ");

				std::string maxElement = "Max Element of table " + std::string(parsedContent) + ":\n";
				maxElement += std::to_string(t->tableMap[parsedContent]->maxElement());

				mvprintw(0, 0, maxElement.c_str());;
			}
			else if (!strcmp(parsedContent, "min"))
			{
				parsedContent = strtok (NULL," ");

				std::string maxElement = "Min Element of table " + std::string(parsedContent) + ":\n";
				maxElement += std::to_string(t->tableMap[parsedContent]->minElement());

				mvprintw(0, 0, maxElement.c_str());;
			}
			else
			{
				mvprintw(0, 0, "Wrong user input");
			}
		}


		mvprintw(LINES-1, 0, ">>");
		clrtoeol();

		// std::cin >> userInput;
		getstr(userInput);


		


		clear();
		// refresh();
	}

	endwin();

	

   return 0;
}