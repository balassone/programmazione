int binarySearch(vector<int> &A, int num) {
    int n = A.size();
    int left = 0;
    int right = n-1;
    cout << "length: " << n << endl;
    while(left <=right){
        int mid = (right+left)/2;

//BS         conditions             results
        if(A[mid] == num)           return mid;
        else if(A[mid] < num)       left = mid+1;
        else                        right = mid -1;
    }

    return -1; //binary search failed
}

int binarySearchRecursive(vector<int> &A, int num, int left, int right) {
    int mid = (left + right) /2;
//BS         conditions         results
    if(A[mid] == num)           return mid;
    else if(A[mid] < num)       binarySearchRecursive(A, num, mid+1, right);
    else if(A[mid] > num)       binarySearchRecursive(A, num, left, mid-1);
    else                        return -1; // binary search failed
    
}