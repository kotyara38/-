#include <iostream>
#include <cmath>
using namespace std;

int current_time;
double g = 9.80665;

double height_t(double t, double H, bool f) // функция для измерения высоты. аргументы: время, начальная высота
{											// и указание как движется шарик: вниз или вверх
	if (f) return H - (g * t * t) / 2;
	else return (g * t * t) / 2;
}

double velocity_t(double t, double V, bool f)//функция измерерия скорости: время, нач.скорость, пометка вверх/вниз
{
	if (f) return -g * t;
	else return V - g * t;
}

int main()
{
	setlocale(LC_ALL, "rus");
	double height, time, dt;

	cout << "Высота - ";
	cin >> height;

	cout << "Интервал времени между измерениями - ";
	cin >> dt;

	cout << "Время проведения симуляции процесса - ";
	cin >> time;

	double current_velocity = 0, current_height = height, touch_time = sqrt(2 * height / g), last_touch = 0, velocity = sqrt(2 * g * height);
	bool falls = 1;
	// переменные для вычислений - текущая скорость, текущая высота, расчетное время касания земли, время от последнего касания
	//скорость
	cout << endl << "=================================СТАРТ СИМУЛЯЦИИ================================" << endl;

	while (current_time < time)
	{
		cout << "Прошло времени " << current_time << " секунд" << endl;
		cout << "Текущая высота " << current_height << " метров" << endl;
		cout << "Текущая скорость " << current_velocity << " метров в секунду" << endl << endl << endl;

		current_time += dt;
		current_height = height_t(current_time - last_touch, height, falls);
		current_velocity = velocity_t(current_time - last_touch, velocity, falls);

		while (current_time > touch_time)	//пока текущее время больше времени касания
		{
			if (falls) height *= 0.7;	//если шарик падает вниз, остается только 70% высоты
			velocity = sqrt(2 * g * height);	//вычисляем новую скорость
			falls = !falls;	//ставим пометку, что шар летит вверх
			current_height = height_t(current_time - touch_time, height, falls); //вычитаем из текущего времени время 
			current_velocity = velocity_t(current_time - touch_time, velocity, falls); //касания и считаем высоту и скорость
			last_touch = touch_time; //присваиваем последнему касанию время ожидаемого касания
			touch_time = sqrt(2 * height / g) + last_touch; //вычисляем новое время ожидаемого касания
		}
	}

	cout << "=================================КОНЕЦ СИМУЛЯЦИИ================================" << endl << endl;
	return 0;
}