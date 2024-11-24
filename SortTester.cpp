#include <vector>

class SortTester {
 public:
  SortTester() = default;

  const int THRESHOLD = 15;

  double TestMergeSort(const std::vector<int>& A, int repeat = 10) {
    double totalTime = 0.0;
    int size = A.size();
    for (int i = 0; i < repeat; ++i) {
      std::vector<int> array = A;
      std::vector<int> tmp(size);

      auto start = std::chrono::high_resolution_clock::now();
      mergeSort(array, 0, size - 1, tmp);
      auto end = std::chrono::high_resolution_clock::now();

      std::chrono::duration<double, std::milli> duration = end - start;
      totalTime += duration.count();
    }
    return totalTime / repeat;
  }

  double TestHybridMergeSort(const std::vector<int>& A, int repeat = 10) {
    double totalTime = 0.0;
    int size = A.size();
    for (int i = 0; i < repeat; ++i) {
      std::vector<int> array = A;
      std::vector<int> tmp(size);

      auto start = std::chrono::high_resolution_clock::now();
      hybridMergeSort(array, 0, size - 1, tmp);
      auto end = std::chrono::high_resolution_clock::now();

      std::chrono::duration<double, std::milli> duration = end - start;
      totalTime += duration.count();
    }
    return totalTime / repeat;
  }

 private:
  void mergeSort(std::vector<int>& array, int first, int last,
                 std::vector<int>& tmp) {
    if (first >= last) {
      return;
    }
    int middle = first + (last - first) / 2;
    mergeSort(array, first, middle, tmp);
    mergeSort(array, middle + 1, last, tmp);
    merge(array, first, middle, last, tmp);
  }

  void hybridMergeSort(std::vector<int>& array, int first, int last,
                       std::vector<int>& tmp) {
    if (last - first + 1 <= THRESHOLD) {
      insertionSort(array, first, last);
      return;
    }
    int middle = first + (last - first) / 2;
    hybridMergeSort(array, first, middle, tmp);
    hybridMergeSort(array, middle + 1, last, tmp);
    merge(array, first, middle, last, tmp);
  }

  void merge(std::vector<int>& array, int first, int middle, int last,
             std::vector<int>& tmp) {
    int i = first;
    int j = middle + 1;
    int k = first;

    while (i <= middle && j <= last) {
      if (array[i] <= array[j]) {
        tmp[k] = array[i];
        ++i;
        ++k;
      } else {
        tmp[k] = array[j];
        ++j;
        ++k;
      }
    }

    while (i <= middle) {
      tmp[k] = array[i];
      ++i;
      ++k;
    }

    while (j <= last) {
      tmp[k] = array[j];
      ++j;
      ++k;
    }

    for (int l = first; l <= last; ++l) {
      array[l] = tmp[l];
    }
  }

  void insertionSort(std::vector<int>& array, int first, int last) {
    for (int i = first + 1; i <= last; ++i) {
      int key = array[i];
      int j = i - 1;

      while (j >= first && array[j] > key) {
        array[j + 1] = array[j];
        --j;
      }
      array[j + 1] = key;
    }
  }
};