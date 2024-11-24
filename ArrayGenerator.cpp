#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

class ArrayGenerator {
 public:
  ArrayGenerator(int maxSize = 10000, int minValue = 0, int maxValue = 6000)
      : maxSize(maxSize), minValue(minValue), maxValue(maxValue) {
    rng.seed(static_cast<unsigned>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));
    generateMaxArrays();
  }

  std::vector<int> getRandomArray(int size) {
    if (size > maxSize) size = maxSize;
    return {randomArray.begin(), randomArray.begin() + size};
  }

  std::vector<int> getReverseSortedArray(int size) {
    if (size > maxSize) size = maxSize;
    return {reverseSortedArray.begin(), reverseSortedArray.begin() + size};
  }

  std::vector<int> getAlmostSortedArray(int size) {
    if (size > maxSize) size = maxSize;
    return {almostSortedArray.begin(), almostSortedArray.begin() + size};
  }

 private:
  int maxSize;
  int minValue;
  int maxValue;
  std::mt19937 rng;

  std::vector<int> randomArray;
  std::vector<int> reverseSortedArray;
  std::vector<int> almostSortedArray;

  void generateMaxArrays() {
    randomArray.resize(maxSize);
    std::uniform_int_distribution<int> dist(minValue, maxValue);
    for (int i = 0; i < maxSize; ++i) {
      randomArray[i] = dist(rng);
    }

    reverseSortedArray.resize(maxSize);
    for (int i = 0; i < maxSize; ++i) {
      reverseSortedArray[i] = maxValue - (i % (maxValue - minValue + 1));
    }

    almostSortedArray = randomArray;
    std::sort(almostSortedArray.begin(), almostSortedArray.end());
    int swaps = 500;
    std::uniform_int_distribution<int> indexDistance(0, maxSize - 1);
    for (int i = 0; i < swaps; ++i) {
      int index1 = indexDistance(rng);
      int index2 = indexDistance(rng);
      std::swap(almostSortedArray[index1], almostSortedArray[index2]);
    }
  }
};