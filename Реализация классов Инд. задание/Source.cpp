#include <iostream>
#include <conio.h>
#include <cmath>

using namespace std;

class RoundRings
{
private:
	double innerDiameter;
	double externalDiameter;
public:
	RoundRings() { innerDiameter = 0; externalDiameter = 0; };
	RoundRings(double inner, double external)
	{
		innerDiameter = inner;
		externalDiameter = external;
	}
	void setID();
	void setED();
	double getID();
	double getED();
	void enlargment()
	{
		int amount;
		cout << "Enter the number to multiply rings: ";
		cin >> amount;
		innerDiameter *= amount;
		externalDiameter *= amount;
	}
	void decrease()
	{
		int amount;
		cout << "Enter the number to split rings: ";
		cin >> amount;
		innerDiameter /= amount;
		externalDiameter /= amount;
	}
	void space()
	{
		double Space;
		Space = 3.14*pow(externalDiameter / 2, 2) - 3.14*pow(innerDiameter / 2, 2);
		cout << "Space of round ring is " << Space << endl;
	}
	void avgRadius()
	{
		double avgRad;
		avgRad = (externalDiameter / 2 + innerDiameter / 2) / 2;
		cout << "Average radius is " << avgRad << endl;
	}
	void ringThickness()
	{
		double ringThick;
		ringThick = (externalDiameter - innerDiameter) / 2;
		cout << "Ring thickness is " << ringThick << endl;
	}

	friend ostream& operator<<(ostream& os, RoundRings& rr)
	{
		return os << "Inner diameter = " << rr.innerDiameter << "\nExternal diameter = " << rr.externalDiameter << endl;
	};
	friend istream& operator>>(istream& is, RoundRings& rr)
	{
		cout << "Inner diameter = ";
		is >> rr.innerDiameter;
		cout << "\nExternal diameter = ";
		is >> rr.externalDiameter;
		return is;
	};

	~RoundRings() {};
};

double RoundRings::getID() { return innerDiameter; }
double RoundRings::getED() { return externalDiameter; }
void RoundRings::setID() {
	double value = 0;
	do {
	try
	{
		if (!(cin >> value))
		{
			throw - 1;
		}
	}
	catch (int)
	{
		value = 0;
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(),'\n');
		cout << "Wrong type of data\n";	
	}
	} while (value == 0);
	innerDiameter = value;
}
void RoundRings::setED() {
	double value = 0;
	do {
		try
		{
			if (!(cin >> value))
			{
				value = 0;
				throw - 1;
			}
		}
		catch (int)
		{
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "Wrong type of data\n";
		}
	} while (value == 0);
	externalDiameter = value;
}

enum operation { ENLARG, DECREASE, SPACE, RADIUS, THICKNESS, STOP } procedure;

istream& operator>>(istream& is, operation& p)
{
	int tmp;
	if (is >> tmp)
		p = static_cast<operation>(tmp);
	return is;
}

int main()
{
	int amount;
	char ch = 'a';
	bool trigger = true;
	cout << "Enter amount of the round rings: ";
	cin >> amount;
	RoundRings *rr = new RoundRings[amount]();
	for (int i = 0; i < amount; i++)
	{
		cout << "Enter value of inner ring for " << i + 1 << " ring\n";
		rr[i].setID();
		cout << "Enter value of external ring for " << i + 1 << " ring\n";
		rr[i].setED();
	}
	amount = 0;
	while (trigger)
	{
		cout << "\n***************************************\n";
		cout << "*0 = Enlargment                       *\n";
		cout << "*1 = Decrease                         *\n";
		cout << "*2 = Space                            *\n";
		cout << "*3 = Radius                           *\n";
		cout << "*4 = Thickness                        *\n";
		cout << "*5 = Stop                             *\n";
		cout << "***************************************\n";
		cin >> procedure;
		switch (procedure)
		{
		case ENLARG:
			system("cls");
			cout << "Enter the number of round ring: ";
			cin >> amount;
			rr[amount].enlargment();
			cout << "Now inner diameter is " << rr[amount].getID() << " and external diameter is " << rr[amount].getED() << endl;
			break;
		case DECREASE:
			system("cls");
			cout << "Enter the number of round ring: ";
			cin >> amount;
			rr[amount].decrease();
			cout << "Now inner diameter is " << rr[amount].getID() << " and external diameter is " << rr[amount].getED() << endl;
			break;
		case SPACE:
			system("cls");
			cout << "Enter the number of round ring: ";
			cin >> amount;
			rr[amount].space();
			break;
		case RADIUS:
			system("cls");
			cout << "Enter the number of round ring: ";
			cin >> amount;
			rr[amount].avgRadius();
			break;
		case THICKNESS:
			system("cls");
			cout << "Enter the number of round ring: ";
			cin >> amount;
			rr[amount].ringThickness();
			break;
		case STOP:
			system("cls");
			trigger = false;
			break;
		default:
			break;
		}

	}
	system("pause");
	return 0;
}