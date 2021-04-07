// https://developerinsider.co/big-o-notation-explained-with-examples/
#include <iostream>
using namespace std;

void printFirstElementOfArray(int arr[]) {
  printf("First element of array = %d", arr[0]);
}

void printAllElementOfArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d\n", arr[i]);
  }
}

void printAllPossibleOrderedPairs(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%d = %d\n", arr[i], arr[j]);
    }
  }
}

int fibonacci(int num) {
  if (num <= 1)
    return num;
  return fibonacci(num - 2) + fibonacci(num - 1);
}

/**
 * What is the most significant?
 */
void printAllItemsTwice(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d\n", arr[i]);
  }

  for (int i = 0; i < size; i++) {
    printf("%d\n", arr[i]);
  }
}

/**
 * What is the most significant?
 */
void printFirstItemThenFirstHalfThenSayHi100Times(int arr[], int size) {
  printf("First element of array = %d\n", arr[0]);

  for (int i = 0; i < size / 2; i++) {
    printf("%d\n", arr[i]);
  }

  for (int i = 0; i < 100; i++) {
    printf("Hi\n");
  }
}

/**
 * What is the most significant?
 */
void printAllNumbersThenAllPairSums(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d\n", arr[i]);
  }

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%d\n", arr[i] + arr[j]);
    }
  }
}

/**
 * Consider worst case
 */
bool arrayContainsElement(int arr[], int size, int element) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == element)
      return true;
  }
  return false;
}

int main() {
  int numbers[] = {2, 4, 7, 10, 11, 32, 45, 87};
  int numbersSize = sizeof(numbers) / sizeof(numbers[0]);

  printFirstElementOfArray(numbers);

  printAllElementOfArray(numbers, numbersSize);

  printAllPossibleOrderedPairs(numbers, numbersSize);

  int fib = 7;
  fibonacci(fib);

  printAllItemsTwice(numbers, numbersSize);

  printFirstItemThenFirstHalfThenSayHi100Times(numbers, numbersSize);

  printAllNumbersThenAllPairSums(numbers, numbersSize);

  int search = 17;
  arrayContainsElement(numbers, numbersSize, search);

  return 0;
}