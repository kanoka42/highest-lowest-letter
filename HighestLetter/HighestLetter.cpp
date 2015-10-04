// HighestLetter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;





int main()
{

	int min;

	int total[26] = { 0 };

	ifstream infile("Letters.txt"); // this has to be in the same location as the source, I had it to where
	if (!infile)					// you could put in an address but it was too confusing.
	{
		cout << "Error opening input file" << endl;

		system("PAUSE");
		return 0;
	}

	char c;
	while (infile.get(c))         // read characters one at a time
	{
		if (isalpha(c))           // check it is a-z or A-Z
		{
			c = toupper(c);       // make it always A-Z

								  // char A-Z has ascii code  65 to 90
								  // Subtract 'A' to get
			int index = c - 'A';  // index in range 0 to 25;

			total[index]++;       // increment corresponding total

		}
	}


	min = total[0];
	for (int i = 1; i < 26; ++i)
	{															/*WHY IS DOING THIS PART SO BRAIN MELTING??*/ 
		if (min > total[i])
		{
			min = total[i];
		}


		int top = total[0];
		for (int i = 1; i < 27; i++)
		{
			if (top < total[i])
			{
				top = total[i];
			}



			for (int i = 0; i < 26; i++)
			{

				if (total[i] == 0)
				{
					cout << "";
				}
				else if (total[i] == min)
				{
					cout << "The letter ", cout << char(i + 'A') << " appears " << total[i] << " times." << endl;
				}
				else {
					cout << "";
				}
			}

			for (int i = 0; i < 26; i++)
			{
				if (total[i] == 0)
				{
					cout << "";
				}
				else if (total[i] == top)
				{
					cout << "The letter ", cout << char(i + 'A') << " appears " << total[i] << " times." << endl;
				}
				else
				{
					cout << "";
				}															//Eh not too bad


				cout << min;


				system("PAUSE");


				return 0;
			}


		}
	}
}