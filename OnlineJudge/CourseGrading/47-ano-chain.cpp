#include <iostream>
#include <string>

int bruteForceSearch(const std::string &text, const std::string &pattern) {
    int n = text.length();
    int m = pattern.length();
    
    for (int i = 0; i <= n - m; ++i) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) {
            ++j;
        }
        if (j == m) {
            return i;
        }
    }
    return -1;
}

int main() {
    std::string text;
    std::string pattern = "ano";
    int n;
    std::cin >> n >> text;
    
    int result = bruteForceSearch(text, pattern);
    
    if (result != -1) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    
    return 0;
}
