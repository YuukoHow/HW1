#include <iostream>
using namespace std;

const int MAX_SIZE = 100;  // 定義集合的最大大小

// 輔助函數，用來打印子集
void printSubset(int subset[], int subsetSize, char set[]) {
    cout << "{";
    for (int i = 0; i < subsetSize; i++) {
        if (i > 0) cout << ", ";  // 在元素之間加逗號
        cout << set[subset[i]];
    }
    cout << "}";  // 關閉子集的括號
}

// 遞迴函數生成子集
void generateSubset(int setSize, int subset[], int subsetSize, int index, char set[]) {
    // 當處理完所有元素時，列印子集
    if (index == setSize) {
        printSubset(subset, subsetSize, set);
        return;
    }

    // 1. 不將當前元素加入子集
    generateSubset(setSize, subset, subsetSize, index + 1, set);

    // 2. 將當前元素加入子集
    subset[subsetSize] = index;
    if (subsetSize > 0 || index > 0) cout << ", ";  // 在子集之間加逗號
    generateSubset(setSize, subset, subsetSize + 1, index + 1, set);
}

int main() {
    char set[] = {'a', 'b', 'c'};  // 集合元素
    int setSize = sizeof(set) / sizeof(set[0]);  // 集合大小
    
    int subset[MAX_SIZE];  // 用來存儲當前生成的子集
    
    // 開始輸出冪集
    cout << "{ ";
    generateSubset(setSize, subset, 0, 0, set);
    cout << " }" << endl;
    
    return 0;
}

