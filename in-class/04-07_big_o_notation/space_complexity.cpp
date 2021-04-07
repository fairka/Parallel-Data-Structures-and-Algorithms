// https://www.codingninjas.com/blog/2021/01/05/what-is-big-o-notation/
#include <iostream>
using namespace std;

void printMessage() {
  for (int i = 1; i <= 5; i++) {
    cout << "Hey there! " << i;
  }
}

void collectNumbers() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    arr[i] = i;
  }
}

int main() {
    
  printMessage();
  
  collectNumbers();

  return 0;
}