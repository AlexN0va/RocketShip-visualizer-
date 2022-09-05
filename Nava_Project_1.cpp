// Nava_Project_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//7/15/2022

/*The purpose of this program is to take user input and make a rocketship according to the values the user inputted, 
for example the user chooses characters of the rocketship like the dimensions, whther its filled or empty, and number of modules within the rocketship.
this porgram uses functions to keep the code orginazed and make it easier to undestadn this menu driven program.
We use only non-returning functions or void functions to display seperate parts of the rocketship. In total we have 10 functions including main. 
*/

#include <iostream>	//console

using namespace std;

//Function prototypes
//program interface in main
void programInfo();	//displays information about the program for user to see
void getRocketSpecs(/*inout*/ int& moduleWidth, /*inout*/ int& moduleHeight,  /*inout*/ int& numModules, /*inout*/ char& moduleSpace);	//prompts user input, and also checks invalid input with a pre-test while loop for each question asked
void drawRocket(/*in*/ int moduleWidth, /*in*/ int moduleHeight, /*in*/ int numModules, /* in*/ char moduleSpace);	//Draws parts of Rocket witht he information given fromt he getRocketSpecs function

//function prototypes
// rocket module build
void drawRocketHollowConeType(int moduleWidth);	//displays the hollow cone 
void drawRocketFilledConeType(int moduleWidth, int moduleHeight);	//displays filled cone
void drawFilledRocketModule(int moduleWidth, int moduleHeight);		//displays filled rocket module or filled sqaure
void drawEmptyRocketModule(int moduleWidth, int moduleHeight);		//displays empty or hollow module or sqaure
void drawRocketBoosters(int moduleWidth);	//Displays the rocket boosters
void rocketBoosterSpacer( /*in*/int spacer);	//creates spaces for the rocket booster text image

int main()
{
	int moduleWidth;    // the width of each rocket module
	int moduleHeight;   // the height of each rocket module
	int numModules;     // the number of modules docked in the rocket
	char moduleSpace;   // empty of filled modules
	char choice = 'N';	//post-test while loop choice

	programInfo();	//function call

	do {

		getRocketSpecs(moduleWidth, moduleHeight, numModules, moduleSpace);	//function call

		//displays text 
		cout << "-------------------------------- " << endl;
		cout << "Rocket Build program " << endl;
		cout << "pattern generating algorithms " << endl;
		cout << "-------------------------------- " << endl;

		drawRocket(moduleWidth, moduleHeight, numModules, moduleSpace);	//drawRocket function call

		//displays choice to try again
		cout << "\n\n---------------------------------------------------------" << endl;
		cout << " Try the ROCKET BUILD pattern generating algorithms again?" << endl;
		cout << "---------------------------------------------------------" << endl;
		cout << "Type 'Y' for yes or 'N' for no: ";
		cin >> choice;

	} while (choice == 'Y' || choice == 'y');

	cout << "\nNow exiting the ROCKET BUILD program ...." << endl;

	return 0;
}

//This function creates a hollow triangle
void drawRocketHollowConeType(int moduleWidth)
{
	int row;            // the row number of the current position
	int col;            // the column number of the current position

	row = 1;
	while (row <= (moduleWidth + 1) / 2) //this checks the max height values and automatically sets it to width + 1 /2 
	{
		col = 1;
		while (col <= moduleWidth)	//while the columns are less than max width
		{
			if (col - moduleWidth / 2 == row || ((moduleWidth + 1) / 2 + 1) - col == row) //if the current character equals the ouuter spaces, or if currect character equals innerspaces
			{
				cout << "*";
			}
			else {
				cout << " ";
			}
			col++;
		}
		cout << endl;
		row++;
	}
}

//creates filled cone
void drawRocketFilledConeType(int moduleWidth, int moduleHeight)
{
	int width = moduleWidth, ccount, rcount = 0, whitespace = 0, charcount = 0;
	int rows = moduleHeight;
	int scount = rows;

	while (rcount <= rows)	//max row or height value
	{

		
		while (whitespace < scount)	//checks whether it has reache the side of triangle
		{
			cout << " ";
			whitespace++;
		}
		while (charcount < width - scount * 2)	//checks how many times the current character should print a star
		{
			cout << "*";
			charcount++;
		}

		scount = scount - 1;
		whitespace = 0;
		cout << endl;
		charcount = 0;

		rcount++;
	}



}

//creates filled rocket module
void drawFilledRocketModule(int moduleWidth, int moduleHeight)
{
	for (int row = 0; row < moduleHeight; row++) //Simple for loop that will display rows until it has reached max height
	{
		for (int col = 0; col < moduleWidth; col++)	//displays each column, will print an star until reached max width value
		{

			cout << '*';

		}
		cout << '\n';//make new line after each row is donw
	}
	

}

//creates empty or hollow Rocket Module
void drawEmptyRocketModule(int moduleWidth, int moduleHeight)
{

	for (int row = 0; row < moduleHeight; row++)  //Simple for loop that will display rows until it has reached max height,but also checks whether row is at the end or in begining
	{
		for (int col = 0; col < moduleWidth; col++)		//Makes each row display a sqaure with star sides
		{
			if (row == 0 || row == moduleHeight - 1)	//if row is the first or the last
				cout << '*';
			else //displays one star then displays whitespace until it has reaches column - 2 
			{
				cout << '*';
				while (col < moduleWidth - 2)
				{
					cout << " ";
					col++;
				}
			}
		}
		cout << endl;	//make new line after each row is donw
	}

}

//creates the rocket boosters
void drawRocketBoosters(int moduleWidth)
{
	/* static Boosters
   cout << "  *    *\n";
   cout << " ***  ***\n";
   cout << "*   **   *\n";
   */

	int spacer = 0;

	switch (moduleWidth)
	{
	case 12:spacer = 11;
		break;
	case 13:spacer = 11;
		break;
	case 14:spacer = 12;
		break;
	case 15:spacer = 12;
		break;
	}

	rocketBoosterSpacer(spacer);
	cout << "  *    *\n";
	rocketBoosterSpacer(spacer);
	cout << " ***  ***\n";
	rocketBoosterSpacer(spacer);
	cout << "*   **   *\n";
}

//creates rocket boosters
void rocketBoosterSpacer( /*in*/int spacer)
{
	for (int spaceCount = 10; spaceCount < spacer; spaceCount++) {
		cout << " ";
	}
}

//prompts user for input about their RocketSship build, and also cheks for invlid input like input outside of range
void getRocketSpecs(/*inout*/ int& moduleWidth, /*inout*/ int& moduleHeight,  /*inout*/ int& numModules, /*inout*/ char& moduleSpace) {

	//display text
	cout << "\n\n---------------------------------------------------------" << endl;
	cout << "SHAPE BUILDER SPECIFICATION REQUEST: " << endl;
	cout << "---------------------------------------------------------" << endl;

	//Dimension 1
	cout << "\nDimension#1: Enter Rocket module width (a number between 10-15): ";
	cin >> moduleWidth;

	while (moduleWidth < 10 || moduleWidth > 15) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Error! Please Choose a number between 10 and 15" << endl;

		cout << "\nDimension#1: Enter Rocket module width (a number between 10-15): ";
		cin >> moduleWidth;

	}

	//Dimension 2
	cout << "\nDimension#2: Enter Rocket module height(a number between 5-10): ";
	cin >> moduleHeight;

	while (moduleHeight < 5 || moduleHeight > 10) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Error! Please choose a number between 5 and 10" << endl;

		cout << "\nDimension#2: Enter Rocket module height (a number between 5-10): ";
		cin >> moduleHeight;

	}

	//numModules
	cout << "\nRocket payload: Enter number of rocket body payload modules to dock together (a number between 2-5): ";
	cin >> numModules;

	while (numModules < 2 || numModules > 5) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Error! Please choose a number between 2 and 5" << endl;

		cout << "\nRocket payload: Enter number of rocket body payload modules to dock together (a number between 2-5):  ";
		cin >> numModules;

	}

	//moduleSpace
	cout << "\nRocket Body: Enter empty or filled cargo space or payload type in module / s(E - empty or F - filled): ";
	cin >> moduleSpace;

	while (moduleSpace != 'F' && moduleSpace != 'E' && moduleSpace != 'f' && moduleSpace != 'e') {
		cout << "Error! Please choose either E - empty or F - filled" << endl;

		cout << "\nRocket Body: Enter empty or filled cargo space or payload type in module / s(E - empty or F - filled):  ";
		cin >> moduleSpace;

	}


}

//Displays Rocketship according to users input
void drawRocket(/*in*/ int moduleWidth, /*in*/ int moduleHeight, /*in*/ int numModules, /* in*/ char moduleSpace) {

	//cout << numModules << " " << moduleWidth << " " << moduleHeight << " " << moduleSpace << endl;
	
	//checking cone
	if (moduleSpace == 'E' || moduleSpace == 'e') //if user chose empty then diplay a filled cone first
	{
		drawRocketFilledConeType(moduleWidth, moduleHeight);

	}
	else if (moduleSpace == 'F' || moduleSpace == 'f') //if user chose filled then diplay a empty cone first
	{
		drawRocketHollowConeType(moduleWidth);

	}

	int i = 1;	//we want to start at 1 

	//checking modules
	//pre-test while loop checks adn finds the number of moduels user want to make and displays them all
	while (i <= numModules) {
		if (moduleSpace == 'E' || moduleSpace == 'e') 
		{
			drawEmptyRocketModule(moduleWidth, moduleHeight);
			i++;

		}
		else if (moduleSpace == 'F' || moduleSpace == 'f') 
		{
			drawFilledRocketModule(moduleWidth, moduleHeight);
			i++;

		}
	}

	drawRocketBoosters(moduleWidth);	//display boosters at the very end

}

//displays program background and information
void programInfo() {

	cout << "****************************************************************************" << endl;
	cout << "                            ROCKET BUILD									 " << endl;
	cout << "The ROCKET BUILD program uses pattern generating algorithms to draw a rocket" << endl;
	cout << "based on four values entered by the user. The rocket will consist of a cone " << endl;
	cout << "followed by modules (empty or filled) that are docked together and ends with" << endl;
	cout << "two rocket boosters at the end. There are four rocket build pattern scenarios" << endl;
	cout << "that can be tested and assessed to meet the project requirements." << endl;
	cout << "Pattern algorithms: rectangles and cones shapes (hollow and filled), static" << endl;
	cout << "and parameter dependent." << endl;
	cout << " " << endl;
	cout << "Program focus: Functional decomposition, parameter passing with algorithms to" << endl;
	cout << "demonstrate proper program and data flow between pattern generating functions." << endl;
	cout << " " << endl;
	cout << "Program Assertions: (1) Non integer and range validation for all user inputs." << endl;
	cout << "(2) Project implementation includes 8 to 12 function algorithms with function" << endl;
	cout << "specific documentation." << endl;
	cout << "*****************************************************************************" << endl;

}



 