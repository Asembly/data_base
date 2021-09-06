#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class DataBase {
private:
	ifstream inputBase_ = {};
	ofstream outputBase_ = {};

	const string PATH_name = "dataTeacher";
	const string PATH_number = "numbersTeacher";
	string password_;
	string names_;
	string numbers_;

	int numberTeacher_ = 0;
	int dataout_ = 0;

	int checkPassword();
	void setDate();
public:
	void dataout();
	void getDateName();
	void getDateNumber();
	void select();
	DataBase() {
	    cout << "База данных 9 Б" << endl;
		checkPassword();
	}
};

void DataBase::getDateName() {
	inputBase_.open(PATH_name);
	if (!inputBase_.is_open()) {
		exit(1);
	}
	else {
		}
	}

void DataBase::getDateNumber() {
	inputBase_.open(PATH_number);
	if (!inputBase_.is_open()) {
		exit(2);
	}
	else {
	}
}

void DataBase::setDate() {
	
}

int DataBase::checkPassword() {
	cout << "Введите пароль >> ";
	cin >> password_;

    if(password_ == "Mirror")
		cout<< "Доступ разрешён" <<endl;
	else {
		cout << "Доступ закрыт" << endl;
		exit(1);
	}
}

void DataBase::select()
{
	int indexer_ = 1;
	getDateName();
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
	int a = 0;
	int b = 0;
	getDateName();
	for (a; a < dataout_; a++)
	{
		getline(inputBase_, names_);
	}
	cout << endl << "<< " << names_ << " >>" << endl;
	inputBase_.close();
	getDateNumber();
	for (b; b < dataout_; b++)
	{
		getline(inputBase_, numbers_);
	}
	cout << "<< " << numbers_ << " >>" << "\n\n";
	inputBase_.close();
	dataout_ = 0;
}

int main() 
{
	setlocale(LC_ALL, "ru");
	DataBase dataBase = {};
	while (true)
	{
		dataBase.select();
		dataBase.dataout();
	}
	return 0;
}
