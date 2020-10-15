//***********************
//Jackson Moberly
//Lab 3 User and File IO
//September 28, 2020
//***********************

//Libraries that will be used for this code.
#include <iostream>
#include <string>
#include <fstream>

//Calculates Mean.
float meanCalc(float fileNum1, float fileNum2, float fileNum3, float fileNum4)
{
	float mean = ((fileNum1 + fileNum2 + fileNum3 + fileNum4) / 4);
	return mean;
}

//Next lines calculate standard deviation.
float stdDeviationCalc(float fileNum1, float fileNum2, float fileNum3, float fileNum4, float mean)
{
	float deviance1 = fileNum1 - mean;
	float deviance2 = fileNum2 - mean;
	float deviance3 = fileNum3 - mean;
	float deviance4 = fileNum4 - mean;
	float stdDeviation = sqrt(((deviance1 * deviance1) + (deviance2 * deviance2) + (deviance3 * deviance3) + (deviance4 * deviance4)) / 4);
	return stdDeviation;
}

using namespace std;

int main()
{
	//Necessary code for writing and reading files.
	ifstream infile;
	ofstream outfile;

	//Makes a place for the 4 numbers to be stored.
	int fileNum1, fileNum2, fileNum3, fileNum4;

	//Stores the files as a string.
	string inputfile = "inMeanStd.dat";
	string outputfile = "outMeanStd.dat";

	//Opens data file and makes a output file to store the data in.
	infile.open(inputfile);
	outfile.open(outputfile);

	//Reads integers from data file.
	infile >> fileNum1 >> fileNum2 >> fileNum3 >> fileNum4;

	//Makes mean an identifier.
	float mean = meanCalc(fileNum1, fileNum2, fileNum3, fileNum4);

	//Makes stdDeviation an identifier.
	float stdDeviation = stdDeviationCalc(fileNum1, fileNum2, fileNum3, fileNum4, mean);

	//Pausing to let the user make the words show up
	system("pause");

	//Outputs to the screen and also the output file.
	cout << "The mean of the numbers in the file is: " << mean << endl << endl;
	outfile << "The mean of the numbers in the file is: " << mean << endl << endl;

	//Pausing again.
	system("pause");

	//Same as the mean outputs but with standard deviation.
	cout << "The standard deviation of those numbers is " << stdDeviation << endl;
	outfile << "The standard deviation of those numbers is " << stdDeviation << endl;

	//Pausing again.
	system("pause");

	//Closes the input file.
	infile.close();

	//Same as above but for another data set.
	int num1, num2, num3, num4;

	//Getting data from the person behind the screen.
	cout << "Now to get some extra data from you. " << endl << "Think of four integers and type them out, pressing enter to confirm the integer. " << endl;
	outfile << "Now to get some extra data from you. " << endl << "Think of four integers and type them out, pressing enter to confirm the integer. " << endl;
	cin >> num1 >> num2 >> num3 >> num4;

	//Getting the numbers onto the other file.
	outfile << num1 << endl << num2 << endl << num3 << endl << num4 << endl;
	
	// Calculating mean.
	float meanUser = (num1 + num2 + num3 + num4) / 4;

	//Calculating standard deviation.
	float devianceUser1 = num1 - meanUser;
	float devianceUser2 = num2 - meanUser;
	float devianceUser3 = num3 - meanUser;
	float devianceUser4 = num4 - meanUser;
	float stdDeviationUser = sqrt(((devianceUser1 * devianceUser1) + (devianceUser2 * devianceUser2) + (devianceUser3 * devianceUser3) + (devianceUser4 * devianceUser4)) / 4);
	
	//Replying with the mean that was calculated.
	cout << "The mean of the data you provided is:" << meanUser << endl;
	outfile << "The mean of the data you provided is:" << meanUser << endl;

	//Replying with the standard deviation that was calculated.
	cout << "The standard deviation of the data you provided is: " << stdDeviationUser << endl;
	outfile << "The standard deviation of the data you provided is: " << stdDeviationUser << endl;

	//Closing the outfile finally.
	outfile.close();

	system("pause");
	return 0;
}

