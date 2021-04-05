#include <iostream>
using namespace std;

int LinearSearch(int *numbers, int numbersSize, int key) {
  for (int i = 0; i < numbersSize; i++) {
    if (numbers[i] == key) {
      return i;
    }
  }
  return -1; // not found
}

int main() {
  // TODO Change numbers to play with input size
  int numbers[] = {2, 4, 7, 10, 11, 32, 45, 87};
  int numbersSize = sizeof(numbers) / sizeof(numbers[0]);
  cout << "NUMBERS: [" << numbers[0];
  for (int i = 1; i < numbersSize; i++) {
    cout << ", " << numbers[i];
  }
  cout << "]" << endl;

  // Prompt for an integer to search for
  cout << "Enter an integer value: ";
  int key = 0;
  cin >> key;

  int keyIndex = LinearSearch(numbers, numbersSize, key);
  if (keyIndex == -1) {
    cout << key << " was not found." << endl;
  } else {
    cout << "Found " << key << " at index ";
    cout << keyIndex << "." << endl;
  }
}
