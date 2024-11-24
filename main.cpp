#include <fstream>
#include <iostream>
#include <vector>

#include "ArrayGenerator.cpp"
#include "SortTester.cpp"

int main() {
  ArrayGenerator generator;
  SortTester tester;

  std::ofstream mergeSortRandom("mergeSort_random.csv");
  std::ofstream mergeSortReverse("mergeSort_reverseSorted.csv");
  std::ofstream mergeSortAlmostSorted("mergeSort_almostSorted.csv");
  std::ofstream hybridMergeSortRandom("hybridMergeSort_random.csv");
  std::ofstream hybridMergeSortReverse("hybridMergeSort_reverseSorted.csv");
  std::ofstream hybridMergeSortAlmostSorted("hybridMergeSort_almostSorted.csv");

  mergeSortRandom << "Time;Array Size\n";
  mergeSortReverse << "Time;Array Size\n";
  mergeSortAlmostSorted << "Time;Array Size\n";
  hybridMergeSortRandom << "Time;Array Size\n";
  hybridMergeSortReverse << "Time;Array Size\n";
  hybridMergeSortAlmostSorted << "Time;Array Size\n";

  for (int size = 500; size <= 10000; size += 100) {
    std::vector<int> randomArray = generator.getRandomArray(size);
    std::vector<int> reverseSortedArray = generator.getReverseSortedArray(size);
    std::vector<int> almostSortedArray = generator.getAlmostSortedArray(size);

    double timeMergeSortRandom = tester.TestMergeSort(randomArray);
    mergeSortRandom << timeMergeSortRandom << ";" << size << "\n";

    double timeHybridMergeSortRandom = tester.TestHybridMergeSort(randomArray);
    hybridMergeSortRandom << timeHybridMergeSortRandom << ";" << size << "\n";

    double timeMergeSortReverse = tester.TestMergeSort(reverseSortedArray);
    mergeSortReverse << timeMergeSortReverse << ";" << size << "\n";

    double timeHybridMergeSortReverse =
        tester.TestHybridMergeSort(reverseSortedArray);
    hybridMergeSortReverse << timeHybridMergeSortReverse << ";" << size << "\n";

    double timeMergeSortAlmostSorted = tester.TestMergeSort(almostSortedArray);
    mergeSortAlmostSorted << timeMergeSortAlmostSorted << ";" << size << "\n";

    double timeHybridMergeSortAlmostSorted =
        tester.TestHybridMergeSort(almostSortedArray);
    hybridMergeSortAlmostSorted << timeHybridMergeSortAlmostSorted << ";"
                                << size << "\n";
  }

  mergeSortRandom.close();
  mergeSortReverse.close();
  mergeSortAlmostSorted.close();
  hybridMergeSortRandom.close();
  hybridMergeSortReverse.close();
  hybridMergeSortAlmostSorted.close();
  return 0;
}