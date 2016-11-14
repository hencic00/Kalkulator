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
	

	initscr();
	cbreak();

	Calculator *t = NULL;
	t = new Calculator();
	// t->parseFile("./tables.csv");

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

				std::string minElement = "Min Element of table " + std::string(parsedContent) + ":\n";
				minElement += std::to_string(t->tableMap[parsedContent]->minElement());

				mvprintw(0, 0, minElement.c_str());;
			}
			else if (!strcmp(parsedContent, "sum"))
			{
				parsedContent = strtok (NULL," ");

				std::string sumOfElements = "Sum of table " + std::string(parsedContent) + ":\n";
				sumOfElements += std::to_string(t->tableMap[parsedContent]->sumElements());

				mvprintw(0, 0, sumOfElements.c_str());;
			}
			else if (!strcmp(parsedContent, "prod"))
			{
				parsedContent = strtok (NULL," ");

				std::string prodOfElements = "Prod of table " + std::string(parsedContent) + ":\n";
				prodOfElements += std::to_string(t->tableMap[parsedContent]->prodElements());

				mvprintw(0, 0, prodOfElements.c_str());;
			}
			else if (!strcmp(parsedContent, "load"))
			{
				parsedContent = strtok (NULL," ");
				std::string info = "Loaded file " + std::string(parsedContent) + "\n";

				t->parseFile(parsedContent);
				mvprintw(0, 0, info.c_str());
			}
			else if (!strcmp(parsedContent, "write"))
			{
				parsedContent = strtok (NULL," ");

				if (!strcmp(parsedContent, "tables"))
				{
					parsedContent = strtok (NULL," ");
					t->writeActiveTablesToFile(parsedContent);
				}
				else
				{
					t->writeTableToFile(parsedContent = strtok (NULL," "), parsedContent);
				}

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