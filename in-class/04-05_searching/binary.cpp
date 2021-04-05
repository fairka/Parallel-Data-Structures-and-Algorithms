#include <iostream>
using namespace std;

int BinarySearch(int *numbers, int numbersSize, int key) {
  // Variables to hold the low and high indices of the area being searched.
  // Starts with entire range.
  int low = 0;
  int high = numbersSize - 1;

  // Loop until "low" passes "high"
  while (high >= low) {
    // Calculate the middle index
    int mid = (high + low) / 2;

    // Cut the range to either the left or right half,
    // unless numbers[mid] is the key
    if (numbers[mid] < key) {
      low = mid + 1;
    } else if (numbers[mid] > key) {
      high = mid - 1;
    } else {
      return mid;
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

  int keyIndex = BinarySearch(numbers, numbersSize, key);
  if (keyIndex == -1) {
    cout << key << " was not found." << endl;
  } else {
    cout << "Found " << key << " at index ";
    cout << keyIndex << "." << endl;
  }
}
