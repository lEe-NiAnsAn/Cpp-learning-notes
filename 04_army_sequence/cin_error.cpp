#include "cin_error.h"
#include "sclear.h"

int cin_error()
{
	cout << "error!\n\n";
	sclear();
	cout << "（重新输入)\n";
	cin.clear();
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	int temp = 0;
	cin >> temp;
	system("cls");
	return temp;
}
void cin_error(int v)
{
	
	cout << "error!\n\n";
	sclear();
	cout << "（重新输入)\n";
	cin.clear();
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
}