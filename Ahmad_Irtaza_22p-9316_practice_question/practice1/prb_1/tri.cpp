
#include<iostream>
int shape(int side1,int side2,int side3);

using namespace std;

enum triangle_type{Scalene, Isosceles, Equilateral, No_Triangle};
int main()
{

	int side1, side2, side3,chk;

	cout << "\nPlease Enter Three Sides of a Triangle =  ";
	
    cin >> side1 >> side2 >> side3;
	
    chk=shape(side1,side2,side3);
    
switch (chk)
{
    case Equilateral:

cout << "\nThis is an Equilateral Triangle";

break;

case Isosceles:

cout << "\nThis is an Isosceles Triangle";

break;

case Scalene :

cout << "\nThis is a Scalene Triangle";

    break;

    case No_Triangle:

cout << "not a triangle" <<endl;

 break;

 }

}


int shape(int side1,int side2,int side3)

{

if (side1+side2>side3||side3+side2>side1||side1+side3>side2)

    {

	  if(side1 == side2 && side2 == side3)
  	{
        return 2;
  	}

  	else if(side1 != side2 && side2 != side3 &&side1 != side3)

    { 
        return 0;
    }	

  	else 
    {
        return 1;
    }

    }

    else
    {
        return 3;
    }	
    
}