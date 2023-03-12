#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

int main()
{
	string output;
	stack <int> tupik;
	queue <int> sostav;
	int N;
	int stop = 1;
	int tik = 0;
	cin >> N;
	int temp;
	for (int i = 0; i < N; i++) { cin >> temp; sostav.push(temp); }
	//begin

	while (!sostav.empty()) //цикл забора вагонов из состава
	{
		temp = sostav.front(); //забор вагонов из состава в тупик
		sostav.pop();
		tik++;
		tupik.push(temp);
		if (temp == stop) //при нахождении минимального номера начинаем выгрузку
		{
			output += "1\t"; output += to_string(tik); output += '\n'; //кодировка входа в тупик
			tik = 0; //сброс счетчика входа
			while ((temp = tupik.top()) == stop) //выгрузка вагонов из тупика
			{
				tupik.pop();
				tik++;
				if (stop == N) break;
				stop++;
			}
			output += "2\t"; output += to_string(tik); output += '\n'; // кодировка выпуска из тупика
			tik = 0;

		}

	}
	cout << endl;
	if (sostav.empty() && tupik.empty()) cout << output; else cout << "0";
}


