
/*
	*	Name: Joanna Lopez			NetID: jjl369
	*	Date: January 30,2023		Due Date: February 3, 2023
	*	Description: Program receives input from user specifically two coordinate points,
	*				 starting and ending. Afterwards, a while loop and nested for loops ouput 
	*				 coordinates counting down to the ending points. In which all coordinate
	*				 points are in the format of (x,y).
*/

#include <iostream>
using namespace std;


int main()
{
	int xStartPoint;
	int yStartPoint;
	int xEndPoint;
	int yEndPoint;
	int i;
	int j;

	cout << "Enter your starting x: ";
	cin >> xStartPoint;
	cout << "Enter your starting y: ";
	cin >> yStartPoint;

	cout << endl << "Enter your ending x: ";
	cin >> xEndPoint;
	cout << "Enter your ending y: ";
	cin >> yEndPoint;
	cout << endl;

	// either the x or y value is greater than or equal to its corresponding start point
	while (xEndPoint >= xStartPoint || yEndPoint >= yStartPoint)
	{

		if (xEndPoint >= xStartPoint)
		{
			cout << "That's not a valid x value. Please try again." << endl;
			cout << "Enter your ending x: ";
			cin >> xEndPoint;		// needs to input again
			cout << endl;
		}
		else if (yEndPoint >= yStartPoint)
		{
			cout << "That's not a valid y value. Please try again." << endl;
			cout << "Enter your ending y: ";
			cin >> yEndPoint;
			cout << endl;
		}
	}
	// columns = xEndPoint #
	// rows = yEndPoint #
	
	for (i = yStartPoint; i >= yEndPoint; --i)
	{
		for (j = xStartPoint; j >= xEndPoint; --j)
		{
			cout << "(" << j << ", " << i << ") ";
		}
		cout << endl;
	}

	return 0;
}
	



