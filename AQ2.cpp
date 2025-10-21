#include<iostream>
using namespace std;

void CREATE(int arr[], int &size) {
    cout << "-----Array Creation-----" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Index " << i << " : ";
        cin >> arr[i];
    }
    cout << "Array Created Successfully\n";
}
void DISPLAY(int arr[], int size) {
    if (size == 0) {
        cout << "Array is empty\n";
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main(){
    int size;
    cout << "enter size : ";
    cin >> size;

    int arr[size];

    CREATE(arr,size);
    DISPLAY(arr,size);

    for(int i = 0; i < size; i++){ //0 to 6

        for(int j = i+1; j < size; j++){ // 1 tp 6 then 2 to 6 then 3 to 6 and so on ..

            if(arr[i] == arr[j]){// check if same

                for(int k = i; k < size-1; k++){ // starts from dulicate element to 6...
                    arr[k] = arr[k+1]; // shifts the element after duplicate one index back
                }
                size--; // decreases size by 1 after removing dulpicate
                j--; // checks the current element at i index again as j = i+1 and j-- = i
            }
            else{
                continue;
            }
        }
    }
    DISPLAY(arr,size);
    return 0;
}