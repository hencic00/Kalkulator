#pragma once

class Table
{
	public:
		Table(std::string tableName)
		{
			name = tableName;
		};

		void print()
		{
			// std::cout << name << std::endl;
			for (unsigned int i = 0; i < values.size(); ++i)
			{
				for (unsigned int j = 0; j < values[i].size(); ++j)
				{
					std::cout << values[i][j] << " ";
				}
				std::cout << std::endl;
			}
			std::cout << values.size();
		}

		std::string name;
		std::vector<std::vector<int>> values;
};
