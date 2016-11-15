#include <map>
#include <fstream>

#include <table.h>


class Calculator
{
	private:

		char* readAsCharArray(char* fileName)
		{
			std::ifstream ifs(fileName, std::ios::binary|std::ios::ate);
			std::ifstream::pos_type pos = ifs.tellg();

			char* result = (char*) malloc(sizeof(char) * pos);

			ifs.seekg(std::ios::beg);
			ifs.read(result, pos);

			return result;
		}


	public:
		std::map<std::string ,Table*> tableMap; //DODAJ: getMetoda
		Table* resultTable = NULL;

		Calculator(){}
		~Calculator()
		{
			//dodaj loop skozi map in deletaj posamezne vectorje
		}
		void parseFile(char* csv_fileName) //preberi datoteko kot char in jo shrani v Table.values <- 2D vector<int>
		{
			char* content = readAsCharArray(csv_fileName);
			char* parsedContent = strtok (content,",\n");

			Table *t = NULL;
			int row = -1;

			char* tableName = "";

			while (parsedContent != NULL)
			{
				if (!strcmp(parsedContent, "table"))
				{	
					if (t != NULL)
					{
						tableMap[tableName] = t;
						// delete[] t;
					}

					tableName = strtok (NULL, ",\n");

					t = new Table(tableName);
					row = -1;
				}
				else if (!strcmp(parsedContent, "row"))
				{
					std::vector<int> v;
					t->values.push_back(v);
					row++;
				}
				else
				{
					t->values[row].push_back(atoi(parsedContent));
				}

				parsedContent = strtok (NULL, ",\n");
			}
			tableMap[tableName] = t;
			// delete[] t;
			// free(content);

		}

		void printActiveTables()
		{
			std::string tableNameList = "Table list:\n";
			for(auto iterator = tableMap.begin(); iterator != tableMap.end(); ++iterator)
			{
				tableNameList += "-" + iterator->first + "\n";
			}
			mvprintw(0, 0, tableNameList.c_str());
		}

		void printTableByName(std::string tableName)
		{
			tableMap[tableName]->print();
		}

		bool tableMapContains(std::string tableMapKey) //preverimo če tableMap vsebuje key
		{
			std::map<std::string,Table*>::iterator it = tableMap.find(tableMapKey);
			return (it == tableMap.end() ? false : true);
		}

		void sumTables(std::string tableName1, std::string tableName2)
		{
			//DODAJ preverjanje za velikost
			delete resultTable;
			resultTable = new Table("rezultat");

			for(int i = 0; i<tableMap[tableName1]->values.size(); ++i)
			{
				std::vector<int> v;
				resultTable->values.push_back(v);

				for(int j = 0; j < tableMap[tableName1]->values[i].size(); ++j)
				{
					//int dafuq = tableMap[tableName1]->values[i].size();

					resultTable->values[i].push_back(tableMap[tableName1]->values[i][j] + tableMap[tableName2]->values[i][j]);
				}
			}
		}

		void substractTables(std::string tableName1, std::string tableName2)
		{
			//DODAJ preverjanje za velikost
			delete resultTable;
			resultTable = new Table("rezultat");

			for(int i = 0; i<tableMap[tableName1]->values.size(); ++i)
			{
				std::vector<int> v;
				resultTable->values.push_back(v);
				for(int j = 0; j < tableMap[tableName1]->values[i].size(); ++j)
				{
					resultTable->values[i].push_back(tableMap[tableName1]->values[i][j] - tableMap[tableName2]->values[i][j]);
				}
			}
		}

		void prodTables(std::string tableName1, std::string tableName2)
		{
			//DODAJ preverjanje za velikost
			delete resultTable;
			resultTable = new Table("rezultat");

			for(int i = 0; i<tableMap[tableName1]->values.size(); ++i)
			{
				std::vector<int> v;
				resultTable->values.push_back(v);
				for(int j = 0; j < tableMap[tableName1]->values[i].size(); ++j)
				{
					resultTable->values[i].push_back(tableMap[tableName1]->values[i][j] * tableMap[tableName2]->values[i][j]);
				}
			}
		}

		void divideTables(std::string tableName1, std::string tableName2)
		{
			//DODAJ preverjanje za velikost
			delete resultTable;
			resultTable = new Table("rezultat");

			for(int i = 0; i<tableMap[tableName1]->values.size(); ++i)
			{
				std::vector<int> v;
				resultTable->values.push_back(v);
				for(int j = 0; j < tableMap[tableName1]->values[i].size(); ++j)
				{
					if(tableMap[tableName2]->values[i][j] != 0)
					{
						resultTable->values[i].push_back(tableMap[tableName1]->values[i][j] / tableMap[tableName2]->values[i][j]);						
					}
					else
					{
						resultTable->values[i].push_back(tableMap[tableName1]->values[i][j]);
					}
				}
			}
		}

		void writeActiveTablesToFile(std::string fileName)
		{
			std::string tablesString = "";
			for(auto iterator = tableMap.begin(); iterator != tableMap.end(); ++iterator)
			{
				tablesString += tableMap[iterator->first]->toString();
			}
			// mvprintw(0, 0, tablesString.c_str());

			std::ofstream myFile;
			myFile.open(fileName, std::ios::app);
			myFile << tablesString;
		}

		void writeTableToFile(std::string fileName, std::string tableName)
		{
			std::ofstream myFile;
			myFile.open(fileName, std::ios::app);
			myFile << tableMap[tableName]->toString();
		}

		inline bool getNextUserInput(char** parsedContent)
		{
			*parsedContent = strtok (NULL," ");

			if(*parsedContent != NULL){
				return true;
			}
			return false;
		}


};