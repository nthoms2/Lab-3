/*
Nolan Thoms
C++ Fall 2019
Lab 3
Using interactive files to find mean and standard deviation
*/

// gains acceses to the different libraries needed
#include <iostream>
#include <math.h>
#include <string>
#include <fstream>

using namespace std;

// these are the function prototypes for mean and standard deviation
float mean(int one, int two, int three, int four);
float sd(int one, int two, int three, int four, float mean);

int main()
{
	//creates intergers for the user input
	int one, two, three, four;
	
	// declares that ther are files being used
	ifstream inFile;
	ofstream outFile;

	//creates integers for the input file
	int fInput1, fInput2, fInput3, fInput4;

	//gives the location for input files and output files
	string inputFileName = "C:/Users/THOMS3/Documents/C++/Lab 3 using inputs and interactive files/inMeanStd.dat";
	string outputFileName = "C:/Users/THOMS3/Documents/C++/Lab 3 using inputs and interactive files/outMeanStd.dat";

	// opens files
	inFile.open(inputFileName);
	outFile.open(outputFileName);

	//brings the file input and puts in into the integers
	inFile >> fInput1 >> fInput2 >> fInput3 >> fInput4;

	// outputs directions to the screen
	cout << "please input four numbers, with a space in between each nmber" << endl;
	cin >> one >> two >> three >> four; // assigns integers to the input

	/* displays the mean and standard deviation from the input and and input file 
	on the screen, the first three lines refer to user input and the second three lines 
	refer to the file input*/
	cout << "The mean of your numbers is:" << " " << mean(one, two, three, four) << endl;
	cout << "The standard deviation of your numbers is:" << " " << sd(one, two, three, four, mean(one, two, three, four)) << endl;
	cout << "\n" << "The numbers inputed by the file are:" << " " << fInput1 << "," << " " << fInput2 << "," << " " << fInput3 << "," << " " << fInput4 << endl;
	cout << "The mean of the file input is:" << " " << mean(fInput1, fInput2, fInput3, fInput4) << endl;
	cout << "The standard deviation of the file input is:" << " " << sd(fInput1, fInput2, fInput3, fInput4, mean(fInput1, fInput2, fInput3, fInput4)) << endl;
	
	/* displays the mean and standard deviation from the input and and input file
	to the out put file, the first three lines refer to the file input and the second 
	three lines refer to the user input */
	outFile << "The numbers inputed by the file are:" << " " << fInput1 << "," << " " << fInput2 << "," << " " << fInput3 << "," << " " << fInput4 << endl;
	outFile << "The mean of these numbers is:" << " " << mean(fInput1, fInput2, fInput3, fInput4) << endl;
	outFile << "The standard deviation of these numbers is:" << " " << sd(fInput1, fInput2, fInput3, fInput4, mean(fInput1, fInput2, fInput3, fInput4)) << endl;
	outFile << "\n" << "The numbers inputed by the user are:" << " " << one << "," << " " << two << "," << " " << three << "," << " " << four << endl;
	outFile << "The mean of these numbers is:" << " " << mean(one, two, three, four) << endl;
	outFile << "The standard deviation of these numbers is" << " " << sd(one, two, three, four, mean(one, two, three, four)) << endl;

	// closes the input and out put files
	inFile.close();
	outFile.close();

	return 0;
}

// this is the function definiton for the mean
float mean(int one, int two, int three, int four) 
{
	return float(one + two + three + four) / float(4);
}
// this is the function definition for the standard deviation
float sd(int one, int two, int three, int four, float mean)
{
	return sqrt((pow((one - mean), 2) + pow((two - mean), 2) + pow((three - mean), 2) + pow((four - mean), 2)) / 4);
}