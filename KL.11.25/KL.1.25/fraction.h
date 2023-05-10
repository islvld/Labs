struct fraction
{
	int first;
	int second;
	void Init(int, int); // метод инициализации полей
	void Read(); // метод для чтения значений полей
	void Show(); // метод для вывода значений полей
	int Minutes(); // приведение времени в минуты
};