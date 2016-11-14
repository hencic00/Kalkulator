#pragma once

class Table
{
	public:
		std::string name;
		std::vector<std::vector<int>> values;

		Table(std::string tableName)
		{
			name = tableName;
		};

		void print()
		{
			std::string tableContent =  name + "\n";
			for (unsigned int i = 0; i < values.size(); ++i)
			{
				for (unsigned int j = 0; j < values[i].size(); ++j)
				{
					tableContent += std::to_string(values[i][j]) + " ";
				}
				tableContent += "\n";
			}
			mvprintw(0, 0, tableContent.c_str());
		}

		//DODAJ template <typename T> inline T const&         nareji s template?
		int maxElement() //najdi max element
		{
			int maxElement = values[0][0]; //kinda ni safe samo boljše kot settat na numberic limits min
			for(int i = 0; i < values.size(); ++i)
			{
				for(int j = 0; j < values[i].size(); ++j)
				{
					if(maxElement < values[i][j])
					{
						maxElement = values[i][j];
					}
				}
			}
			return maxElement;
		}

		int minElement() //najdi max element
		{
			int minElement = values[0][0]; //kinda ni safe samo boljše kot settat na numberic limits min
			for(int i = 0; i < values.size(); ++i)
			{
				for(int j = 0; j < values[i].size(); ++j)
				{
					if(minElement > values[i][j])
					{
						minElement = values[i][j];
					}
				}
			}
			return minElement;
		}

		int sumElements()
		{
			int sum = 0;
			for(int i = 0; i < values.size(); ++i)
			{
				for(int j = 0; j < values.size(); ++j)
				{
					sum += values[i][j];
				}
			}
			return sum;
		}

		long prodElements()
		{
			long prod = 1;
			for(int i = 0; i < values.size(); ++i)
			{
				for(int j = 0; j < values.size(); ++j)
				{
					prod *= values[i][j];
				}
			}
			return prod;
		}

};
