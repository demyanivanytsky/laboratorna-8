#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
using namespace std;
int main() {
	SetConsoleOutputCP(1251);
	int n;
	// Введення розміру масиву
	cout << "Введіть розмір масиву: ";
	cin >> n;
	// Ініціалізація масиву та введення його елементів
	vector<int> arr(n);
	cout << "Введіть елементи масиву: ";
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	// Обчислення суми додатніх елементів
	int sumPositive = 0;
	for (int i = 0; i < n; ++i) {
		if (arr[i] > 0) {
			sumPositive += arr[i];
		}
	}
	cout << "Сума додатніх елементів: " << sumPositive << endl;
	// Обчислення добутку елементів масиву
	int product = 1;
	for (int i = 0; i < n; ++i) {
		product *= arr[i];
	}
	cout << "Добуток елементів масиву: " << product << endl;
	// Знаходження максимального та мінімального елементів по модулю
	int maxAbs = *max_element(arr.begin(), arr.end(), [](int a, int b) {
		return abs(a) < abs(b);
		});
	int minAbs = *min_element(arr.begin(), arr.end(), [](int a, int b) {
		return abs(a) < abs(b);
		});
	// Знаходження індексів максимального та мінімального елементів по модулю
	int maxIndex = find(arr.begin(), arr.end(), maxAbs) - arr.begin();
	int minIndex = find(arr.begin(), arr.end(), minAbs) - arr.begin();
	// Визначення початкового та кінцевого індексів для елементів між максимальним і мінімальним по модулю
	int start = min(minIndex, maxIndex);
	int end = max(minIndex, maxIndex);
	// Обчислення добутку елементів між максимальним і мінімальним по модулю
	int productBetween = 1;
	for (int i = start + 1; i < end; ++i) {
		productBetween *= arr[i];
	}
	cout << "Добуток елементів між максимальним і мінімальним по модулю: " << productBetween << endl; // Впорядкування елементів масиву по спаданню
	sort(arr.begin(), arr.end(), greater<int>());
	// Виведення впорядкованого масиву (task2)
	cout << "Масив, впорядкований по спаданню: ";
	for (int i = 0; i < n; ++i) {
		cout << arr[i] << " ";
	}
	return 0;
}