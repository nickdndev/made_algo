#include <iostream>

int main() {
  using namespace std;

  int arraySize;

  cin >> arraySize;

  int array[arraySize];

  for (int i = 0; i < arraySize; i++)
    cin >> array[i];

  int j, tmp;

  for (int i = 1; i < arraySize; i++) {
    j = i - 1;

    while (j >= 0 && array[j] > array[j + 1]) {
      tmp = array[j];
      array[j] = array[j + 1];
      array[j + 1] = tmp;
      j--;
    }
  }

  for (int i = 0; i < arraySize; i++)
    cout << array[i] << ' ';

  return 0;
}
