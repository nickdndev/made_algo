#include <iostream>

void quicksort(int array[], int leftBorder, int rightBoarder) {
  int n = rand();
  int middlePointer = leftBorder + n % (rightBoarder - leftBorder + 1);
  int bearingValue = array[middlePointer];
  int leftPoint = leftBorder;
  int rightPoint = rightBoarder;

  if (leftBorder >= rightBoarder)
    return;

  while (leftPoint <= rightPoint) {

    while (array[rightPoint] > bearingValue)
      rightPoint--;

    while (array[leftPoint] < bearingValue)
      leftPoint++;

    if (leftPoint <= rightPoint) {
      int tmp = array[rightPoint];
      array[rightPoint] = array[leftPoint];
      array[leftPoint] = tmp;
      rightPoint--;
      leftPoint++;
    }
  }

  if (leftPoint < rightBoarder)
    quicksort(array, leftPoint, rightBoarder);
  if (rightPoint > leftBorder)
    quicksort(array, leftBorder, rightPoint);
}

int main() {
  using namespace std;

  int arraySize;

  cin >> arraySize;

  int array[arraySize];

  for (int i = 0; i < arraySize; i++)
    cin >> array[i];

  quicksort(array, 0, arraySize - 1);

  for (int i = 0; i < arraySize; i++)
    cout << array[i] << ' ';

  return 0;
}