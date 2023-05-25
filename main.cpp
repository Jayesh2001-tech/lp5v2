1.	#include <mpi.h>
2.	#include <iostream>
3.	using namespace std;
4.
5.	int main() {
6.	int rank, size;
7.	MPI_Init(NULL, NULL);
8.	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
9.	MPI_Comm_size(MPI_COMM_WORLD, &size);
10.	int arr[8] = {9, 6, 3, 7, 2, 12, 5, 1};
11.
12.	if (rank == 0) {
13.	cout << "Input array:" << endl;
14.	for (int i = 0; i < 8; i++) {
15.	cout << array[i] << " ";
16.	}
17.	cout << endl;
18.	}
19.	quicksort(array, 0, 7);
20.	if (rank == 0) {
21.	cout << "Sorted array:" << endl;
22.	for (int i = 0; i < 8; i++) {
23.	cout << array[i] << " ";
24.	}
25.	cout << endl;
26.	}
27.
28.	MPI_Finalize();
29.	return 0;
30.	}
31.
32.	void quicksort(int array[], int low, int high) {
33.	if (low < high) {
34.	int pivot = array[high];
35.	int i = low - 1;
36.	for (int j = low; j < high; j++) {
37.	if (array[j] < pivot) {
38.	i++;
39.	int temp = array[i];
40.	array[i] = array[j];
41.	array[j] = temp;
42.	}
43.	}
44.	quicksort(array, low, i);
45.	quicksort(array, i + 1, high);
46.	}
47.	}
