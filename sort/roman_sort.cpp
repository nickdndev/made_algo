#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

static map<char, int> mappingRomToNumber = {
    {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}};

vector<string> split(const string &input, const string &delimiter) {
  size_t pos_start = 0, pos_end, delim_len = delimiter.length();
  string token;
  vector<string> res;

  while ((pos_end = input.find(delimiter, pos_start)) != string::npos) {
    token = input.substr(pos_start, pos_end - pos_start);
    pos_start = pos_end + delim_len;
    res.push_back(token);
  }

  res.push_back(input.substr(pos_start));
  return res;
}

int decode(string romNumber) {
  int total = 0;
  int prevValue = 0;
  int i = romNumber.size() - 1;

  while (i >= 0) {
    if (prevValue <= mappingRomToNumber[romNumber[i]]) {
      total += mappingRomToNumber[romNumber[i]];
    } else {
      total -= mappingRomToNumber[romNumber[i]];
    }
    prevValue = mappingRomToNumber[romNumber[i]];
    i--;
  }
  return total;
}

void sort(vector<string> &names) {
  for (int i = 0; i < names.size(); i++) {
    for (int j = i + 1; j < names.size(); j++) {
      if (i != j) {

        vector<string> splitNameLeft = split(names[i], " ");
        vector<string> splitNameRight = split(names[j], " ");

        string nameLeft = splitNameLeft[0];
        string nameRight = splitNameRight[0];

        int numberLeft = decode(splitNameLeft[1]);
        int numberRight = decode(splitNameRight[1]);

        if (nameLeft > nameRight) {
          swap(names[i], names[j]);
        } else if (nameLeft == nameRight) {
          if (numberLeft > numberRight) {
            swap(names[i], names[j]);
          }
        }
      }
    }
  }
}

int main() {

  string arraySizeStr;

  getline(cin, arraySizeStr);

  int arraySize = stoi(arraySizeStr);

  vector<string> inputVector(arraySize);

  for (int i = 0; i < arraySize; i++)
    getline(cin, inputVector[i]);

  sort(inputVector);

  for (const string &item : inputVector) {
    cout << item;
    cout << endl;
  }

  return 0;
}