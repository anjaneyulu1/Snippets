class Solution {
public:
    
    
/*TIME LIMIT*/
    /*
    int partition (vector<int> &A, int low, int high) 
    { 
        int pivot = A[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) 
        {
            if (A[j] < pivot) 
            { 
                i++;
                swap(A[i], A[j]); 
            } 
        } 
        swap(A[i + 1], A[high]); 
        return (i + 1); 
    } 

    void quickSort(vector<int> &A, int low, int high) 
    { 
        if (low < high) 
        {
            int pi = partition(A, low, high); 

            quickSort(A, low, pi - 1); 
            quickSort(A, pi + 1, high); 
        } 
    } */
    
    /* LAGGING IN TIME*/
    /*
    int GetPovitPos(int low, int high, vector<int> &A)
    {
        int povit = A[high];
        int i = low-1;
        for(int j=low; j < high; j++)
        {
            if(A[j] < povit)
            {
                i++;
                swap(A[i], A[j]);
            }
        }
        swap(A[i+1], A[high]);
        return i+1;
    }
    
    void quickSort(const int low, int high, vector<int> &A)
    {
        if(low < high)
        {
            int povitPos = GetPovitPos(low, high, A);
            quickSort(low, povitPos-1, A);
            quickSort(povitPos+1, high, A);
        }
    }*/
    
    int partition(vector<int> &values, int left, int right) {
        int pivotIndex = left + (right - left) / 2;
        int pivotValue = values[pivotIndex];
        int i = left, j = right;
        int temp;
        while(i <= j) {
            while(values[i] < pivotValue) {
                i++;
            }
            while(values[j] > pivotValue) {
                j--;
            }
            if(i <= j) {
                temp = values[i];
                values[i] = values[j];
                values[j] = temp;
                i++;
                j--;
            }
        }
        return i;
    }
    
    void quicksort(vector<int> &values, int left, int right) {
        if(left < right) {
            int pivotIndex = partition(values, left, right);
            quicksort(values, left, pivotIndex - 1);
            quicksort(values, pivotIndex, right);
        }
    }
    
    vector<int> sortedSquares(vector<int>& A) {
        for_each(A.begin(), A.end(), [](int &i){ i= i*i; });
        sort(A.begin(), A.end());
        //quicksort(A, 0, A.size() - 1);
        return A;
    }
};
