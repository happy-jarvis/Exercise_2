#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

bool check(const string& line); 

int main() 
{
	setlocale(LC_ALL, "Rus");
	ifstream in("input.txt");
	string line;
	stringstream ss;

	try
	{
		if (in.is_open())
		{
			while (getline(in, line))
			{
				if (check(line))
				{
					ss << line << '\n';
				}
			}
		}
		else throw exception("Не удалось открыть файл!");

		cout << ss.str();
	}
	catch (const exception &err)
	{
		cerr << err.what() << endl;
	}
	in.close();		

	system("pause");
}

bool check(const string& line)
{
	for (int i = 0; i < line.size(); ++i) 
	{
		if (line[i] == ',') return false;
	}
	return true;
}