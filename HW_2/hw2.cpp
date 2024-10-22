#include <iostream>
using namespace std;

void generateCombinations(const string& str, int index, string current) {
    if (index == str.size()) {
        if (!current.empty()) {
            cout<<"("<<current<<")";
        }
        return;
    }

    generateCombinations(str, index + 1, current);
    
    generateCombinations(str, index + 1, current + str[index]);
}

int main() {
    string input = "ABC";
    cout<<"{";
    generateCombinations(input, 0, "");
    cout<<"}";
	return 0;
}
