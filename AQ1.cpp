#include <iostream>
using namespace std;

const int MAX = 50;
void CREATE(int arr[], int &size) {
    if (size <= 0 || size > MAX) {
        cout << "Invalid size\n";
        size = 0;
        return;
    }
    cout << "-----Array Creation-----" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Index " << i << " : ";
        cin >> arr[i];
        if (cin.fail()) {
            cout << "Invalid input\n";
            cin.clear();
            while (cin.get() != '\n'); // Clear input buffer
            size = 0;
            return;
        }
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

void INSERT(int arr[], int &size) {
    if (size >= MAX) {
        cout << "Array is full, cannot insert.\n";
        return;
    }

    int ele, index;
    cout << "Enter element to be inserted: ";
    cin >> ele;
    if (cin.fail()) {
        cout << "Invalid input\n";
        cin.clear();
        while (cin.get() != '\n');
        return;
    }
    cout << "Enter position (1 to " << size + 1 << "): ";
    cin >> index;
    if (cin.fail()) {
        cout << "Invalid input\n";
        cin.clear();
        while (cin.get() != '\n');
        return;
    }

    if (index < 1 || index > size + 1) {
        cout << "Invalid position\n";
        return;
    }

    for (int i = size - 1; i >= index - 1; i--) {
        arr[i + 1] = arr[i];
    }
    arr[index - 1] = ele;
    size++;
    cout << "Element inserted successfully\n";
}

bool LINEAR(int arr[], int size) {
    int ele;
    cout << "Enter element to be searched: ";
    cin >> ele;
    if (cin.fail()) {
        cout << "Invalid input\n";
        cin.clear();
        while (cin.get() != '\n');
        return false;
    }

    for (int i = 0; i < size; i++) {
        if (arr[i] == ele) {
            cout << "Element found at index: " << i << endl;
            return true;
        }
    }
    cout << "Element not found\n";
    return false;
}

bool DELETE(int arr[], int &size) {
    if (size == 0) {
        cout << "Array is empty\n";
        return false;
    }

    int ele;
    cout << "Enter element to be deleted: ";
    cin >> ele;
    if (cin.fail()) {
        cout << "Invalid input\n";
        cin.clear();
        while (cin.get() != '\n');
        return false;
    }

    for (int i = 0; i < size; i++) {
        if (arr[i] == ele) {
            cout << "Found element " << ele << " at index " << i << endl;
            for (int j = i; j < size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            size--;
            cout << "Deleted successfully\n";
            return true;
        }
    }
    cout << "Element not found\n";
    return false;
}

int main() {
    cout << "------MENU------" << endl;
    cout << "1. CREATE\n2. DISPLAY\n3. INSERT\n4. DELETE\n5. LINEAR SEARCH\n6. EXIT\n";
    cout << "------Start operations------" << endl;

    int size = 0; // Initialize size
    int arr[MAX];
    cout << "Enter size of Array: ";
    cin >> size;
    if (cin.fail() || size <= 0 || size > MAX) {
        cout << "Invalid size\n";
        cin.clear();
        while (cin.get() != '\n');
        size = 0;
    }

    int opno;
    char ch;
    do {
        cout << "\nEnter operation no.: ";
        cin >> opno;
        if (cin.fail()) {
            cout << "Invalid input\n";
            cin.clear();
            while (cin.get() != '\n');
            continue;
        }

        switch (opno) {
            case 1: CREATE(arr, size); break;
            case 2: DISPLAY(arr, size); break;
            case 3: INSERT(arr, size); break;
            case 4: DELETE(arr, size); break;
            case 5: LINEAR(arr, size); break;
            case 6: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid operation\n";
        }
        cout << "Do you want to continue (y/n): ";
        cin >> ch;
        while (cin.fail() || (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N')) {
            cout << "Invalid input, enter y/n: ";
            cin.clear();
            while (cin.get() != '\n');
            cin >> ch;
        }
    } while (ch == 'y' || ch == 'Y');

    return 0;
}