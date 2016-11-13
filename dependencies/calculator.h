#include <map>

#include <table.h>

class Calculator
{
	private:
		std::map<std::string ,Table*> tableMap;

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
		void parseFile(char* csv_fileName)
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
			for(auto iterator = tableMap.begin(); iterator != tableMap.end(); ++iterator)
			{
				std::cout << iterator->first << " ";
			}
			std::cout << std::endl;
		}

		Calculator(){}
};