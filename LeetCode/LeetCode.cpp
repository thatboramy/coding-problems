// LeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

 string encode(string test_data) {
	string answer = "";


	if (test_data.length() == 1) {
		answer = "1" + test_data;
	}
	else {

		for (int i = 0; i < test_data.length(); i++) {
			char c = test_data.at(i);
			printf("Testing out character: %c\n", c);
			for (int j = i + 1; j < test_data.length(); j++) {

				//printf("Reading character: %c\n", test_data.at(j));

				if (j == (test_data.length() - 1)) {
					//printf("Finished reading the last character %d. Final Length is %d\n", test_data.at(i), j - i + 1);
					answer = answer + to_string(j - i + 1) + c;
					i = j;
					break;
				}

				if (test_data.at(j) != test_data.at(i)) {
					//printf("Finished reading character %c. Lenghth is %d\n", test_data.at(i), j - i);
					int length = j - i;
					answer = answer + to_string(length) + c;
					i = j - 1;
					break;
				}

			}
		}
	}

	return answer;
}

 string decode(string test_data) {
	 string answer = "";

	 for (int i = 0; i < test_data.length(); i++) {
		 int iteration = atoi(&(test_data.at(i)));
		 char c = test_data.at(i + 1);

		 for (int j = 0; j < iteration; j++) {
			 answer = answer + c;
		 }

		 i = i + 1;
	 }

	 return answer;
 }
int main()
{
    std::cout << "Hello World!\n"; 

	string test = encode("AAAABBCCCADDD");

	string test2 = decode(test);
	cout << test << endl;
	printf("Done with all the code");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
