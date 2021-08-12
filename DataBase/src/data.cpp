#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "");

	string names[] = { "Арген Артёмовна","Тузова (Математика)","Валентина Олеговна (Географиня)",
	"Анастасия Сергеевна(Биология)","Елена Юрьевна (Физика)","Татьяна Александровна (Химия)",
	"Любовь Владимировна (ИЗО)","Владимир Георгиевич (Обществознание)","Артём Петрович (ОБЖ)",
	"Инесса Николаевна (Англ)","Ольга Викторовна (Англ)","Олеся Сергеевна (Информатика)",
	"Куликова Татьяна (История)" };

	string numbers[] = { "+7 (908) 178-80-84","+7 (909) 421-35-09"," ? ",
	"+7 (909) 400-64-81","+7 (928) 192-35-76"," ? ",
	" ? ","+7 (906) 185-81-15"," ? ",
	"+7 (903) 474-00-54","+7 (908) 506-76-81"," ? ",
	" ? " };

	string VK[] = { "https://vk.com/id620982794", "https://vk.com/id41859536", "https://vk.com/id5142366",
	"https://vk.com/id144990443", " ? ", "https://vk.com/id20288866",
	"https://vk.com/id332735730", "https://vk.com/id54454443", " ? ",
	"https://vk.com/id234546389", "https://vk.com/o.kupreeva", "https://vk.com/id32999955",
	" ? " };

	string password;
	int who;
	cout << "Введите пароль >> ";
	cin >> password;
	if (password == "Mirror")
	{
		cout << "Доступ разрешён" << endl << endl;
	}
	else
	{
		return 1;
	}
	cout << "База данных 8 Б << Upd 2 >>" << endl;

	while (true)
	{
		for (int a = 0; a <= 12; a++)
		{
			cout << a + 1 << " - " << names[a] << endl;
		}
		cout << "0 - Выйти\n--------------------------\n> ";
		cin >> who;
		if (14 > who > 0)
		{
			who -= 1;
			cout << "\n<< " << names[who] << " >>\n"
				<< "<< " << numbers[who] << " >>\n"
				<< "<< " << VK[who] << " >>\n\n";
			continue;
		}
		else if (who == 0)
		{
			return 2;
		}
		else
		{
			continue;
		}
	}
	return 0;
}