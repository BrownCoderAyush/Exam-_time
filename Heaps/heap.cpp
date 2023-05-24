
#include <bits/stdc++.h>

using namespace std;

class heap
{
private:
    int arr[100];
    int size = 0;

public:
    // O(log(n))
    void insert(int val)
    {
        size++;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;

            if (arr[parent] < val)
            {

                swap(arr[index], arr[parent]);
                index /= 2;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    // O(log(n))
    void Delete()
    {
        if (size < 1)
        {
            cout << "EMPTY" << endl;
            return;
        }
        int i = 1;

        swap(arr[1], arr[size]);

        size--;

        while (i < size)
        {
            int left = 2 * i;
            int right = 2 * i + 1;
            if (left < size && right < size && arr[left] < arr[right])
            {
                if (arr[right] > arr[i])
                {
                    swap(arr[i], arr[right]);
                    i = right;
                }
            }
            else if (left < size && right < size && arr[left] > arr[right])
            {
                if (arr[left] > arr[i])
                {
                    swap(arr[left], arr[i]);
                    i = left;
                }
            }
            else
            {
                return;
            }
        }
    }

    
};
// t.c O(logn)
void heapify(int arr[] , int n , int i){
        int largest = i;
        int lftChld = i*2;
        int rgtChld = i*2+1;
        if(lftChld <= n && arr[lftChld]>arr[largest]){
            largest = lftChld;
        }
        if(rgtChld <= n && arr[rgtChld]>arr[largest]){
            largest = rgtChld;
        }

    if(largest !=i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }    
}
// O(nlogn)
// Heap Sort comprises of making heap O(n) and then using the logic written in heapSort function below hence  t.c(nlogn)
void heapSort(int arr[] , int n ){
    int size = n;
    while(size>1){
        // step1:swap
        swap(arr[1],arr[size]);
        size--;

        // step2:heapify
        heapify(arr,size,1);
    }
}
int main()
{
    // heap h;
    // h.insert(50);
    // h.insert(55);
    // h.insert(53);
    // h.insert(52);
    // h.insert(54);
    // h.print();
    // h.Delete();
    // h.print();
    int arr[] = {-1,54,55,50,52,53};
    int n = 5;
    // time complexity for building a heap is O(n)
    for(int i = n/2; i>0 ; i--){
        heapify(arr,n,i);
    }
    for(int i = 1; i <=5 ; i++){
        cout<<arr[i]<<" "   ;
    }
    heapSort(arr,n);
    cout<<endl;
    for(int i = 1; i <=5 ; i++){
        cout<<arr[i]<<" "   ;
    }
    return 0;
}