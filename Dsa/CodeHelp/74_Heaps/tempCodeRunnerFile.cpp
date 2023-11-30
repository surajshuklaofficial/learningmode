    // here it becomes O(n)
    for (int i = n/2; i > 0; i--) {
        heapify(arr, n, i);
    }