#include <iostream>

void mergeSubArray(long long *inversionNumber, int array[], int leftPoint,
                   int rightPoint, int middlePoint) {

  int sizeRightTempArray = rightPoint - middlePoint;
  int sizeLeftTempArray = middlePoint - leftPoint + 1;

  int leftTempArray[sizeLeftTempArray], rightTempArray[sizeRightTempArray];

  for (int i = 0; i < sizeLeftTempArray; i++)
    leftTempArray[i] = array[i + leftPoint];

  for (int i = 0; i < sizeRightTempArray; i++)
    rightTempArray[i] = array[i + middlePoint + 1];

  int i = 0;
  int j = 0;
  int subArrayPoint = leftPoint;

  while (i < sizeLeftTempArray && j < sizeRightTempArray) {
    if (leftTempArray[i] <= rightTempArray[j]) {
      array[subArrayPoint] = leftTempArray[i];
      i++;
    } else {
      array[subArrayPoint] = rightTempArray[j];
      j++;
      (*inversionNumber) += sizeLeftTempArray - i;
    }

    subArrayPoint++;
  }

  while (i < sizeLeftTempArray) {
    array[subArrayPoint] = leftTempArray[i];
    subArrayPoint++;
    i++;
  }

  while (j < sizeRightTempArray) {
    array[subArrayPoint] = rightTempArray[j];
    subArrayPoint++;
    j++;
  }
}

void mergeSort(long long *inversionNumber, int array[], int leftPoint,
               int rightPoint) {
  if (rightPoint > leftPoint) {
    int middlePoint = leftPoint + (rightPoint - leftPoint) / 2;

    mergeSort(inversionNumber, array, leftPoint, middlePoint);
    mergeSort(inversionNumber, array, middlePoint + 1, rightPoint);

    mergeSubArray(inversionNumber, array, leftPoint, rightPoint, middlePoint);
  }
}

int main() {
  using namespace std;

  int arraySize;

  cin >> arraySize;

  int array[arraySize];
  auto *inversionNumber = new long long(0);

  for (int i = 0; i < arraySize; i++)
    cin >> array[i];

  mergeSort(inversionNumber, array, 0, arraySize - 1);

  cout << *inversionNumber;

  return 0;
}
