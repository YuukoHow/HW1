#include <iostream>
using namespace std;

const int MAX_SIZE = 100;  // �w�q���X���̤j�j�p

// ���U��ơA�Ψӥ��L�l��
void printSubset(int subset[], int subsetSize, char set[]) {
    cout << "{";
    for (int i = 0; i < subsetSize; i++) {
        if (i > 0) cout << ", ";  // �b���������[�r��
        cout << set[subset[i]];
    }
    cout << "}";  // �����l�����A��
}

// ���j��ƥͦ��l��
void generateSubset(int setSize, int subset[], int subsetSize, int index, char set[]) {
    // ��B�z���Ҧ������ɡA�C�L�l��
    if (index == setSize) {
        printSubset(subset, subsetSize, set);
        return;
    }

    // 1. ���N��e�����[�J�l��
    generateSubset(setSize, subset, subsetSize, index + 1, set);

    // 2. �N��e�����[�J�l��
    subset[subsetSize] = index;
    if (subsetSize > 0 || index > 0) cout << ", ";  // �b�l�������[�r��
    generateSubset(setSize, subset, subsetSize + 1, index + 1, set);
}

int main() {
    char set[] = {'a', 'b', 'c'};  // ���X����
    int setSize = sizeof(set) / sizeof(set[0]);  // ���X�j�p
    
    int subset[MAX_SIZE];  // �ΨӦs�x��e�ͦ����l��
    
    // �}�l��X����
    cout << "{ ";
    generateSubset(setSize, subset, 0, 0, set);
    cout << " }" << endl;
    
    return 0;
}

