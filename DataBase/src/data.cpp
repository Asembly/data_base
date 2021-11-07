#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class DataBase {
private:
	ifstream inputBase_ = {};
	ofstream outputBase_ = {};

	int numberTeacher_ = 0;
	int dataout_ = 0;
	int adddataTeacher_ = 0;
	string password;
	const string PATH_name = "dataTeacher";
	const string PATH_number = "numbersTeacher";
	const string PATH_addinfo = "addinfoTeacher";
	const string password_ = "Mirror";
	string names_;
	string numbers_;
	string addinfo_;
public:
	int checkPassword();
	void dataout();
	void getDataName();
	void getDataNumber();
	void getAddData();
	void select();
	DataBase() {
	    cout << "База данных 9 Б" << endl;
		checkPassword();
	}
};

void DataBase::getDataName() {
	inputBase_.open(PATH_name);
	if (!inputBase_.is_open()) {
		exit(1);
	}
	else {
		}
	}

void DataBase::getDataNumber() {
	inputBase_.open(PATH_number);
	if (!inputBase_.is_open()) {
		exit(2);
	}
	else {
	}
}

void DataBase::getAddData() {
	inputBase_.open(PATH_addinfo);
	if (!inputBase_.is_open()) {
		exit(3);
	}
	else {
	}
}

int DataBase::checkPassword() {
	cout << "Введите пароль >> ";
	cin >> password;

    if(password == password_)
		cout<< "Доступ разрешён" <<endl;
	else {
		cout << "Доступ закрыт" << endl;
		exit(10);
	}
}

void DataBase::select()
{
	int indexer_ = 1;
	getDataName();
	while (!inputBase_.eof()) 
	{
		getline(inputBase_, names_);
		cout << indexer_++ << " " << names_ << endl;
	}
	inputBase_.close();
	cin >> dataout_;
}

void DataBase::dataout()
{
	getDataName();
	for (int a = 0 ; a < dataout_; a++)
	{
		getline(inputBase_, names_);
	}
	cout << endl << "<< " << names_ << " >>" << endl;
	inputBase_.close();
	getDataNumber();
	for (int b = 0; b < dataout_; b++)
	{
		getline(inputBase_, numbers_);
	}
	cout << "<< " << numbers_ << " >>" << endl;
	inputBase_.close();
	getAddData();
	for (int c = 0; c < dataout_; c++)
	{
		getline(inputBase_, addinfo_);
	}
	cout << "<< " << addinfo_ << " >>" << "\n\n";
	inputBase_.close();
	dataout_ = 0;
}

int main() 
{
	setlocale(LC_ALL, "");
	DataBase dataBase = {};
	while (true)
	{
		dataBase.select();
		dataBase.dataout();
	}
	return 0;
}
