#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>

void bruteForce(int leng, const std::string& charset) {
    std::vector<int> indices(leng, 0);  // counting each string to not get error
    std::string current(leng, charset[0]); // current password

    while (true) {
        std::cout << current << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(25));
        int pos = leng - 1; // index to start
        while (pos >= 0) {
            indices[pos]++;
            if (indices[pos] < charset.size()) {
                current[pos] = charset[indices[pos]];
                break;
            } 
            else {
                indices[pos] = 0;
                current[pos] = charset[0];
                pos--;
            }
        }

        if (pos < 0) {
            break;
        }
    }
}

int main() {
    int maxLen;
    int option;
    std::cout << "Enter method to crack password: \n";
    std::cout << "1. Only numbers \n";
    std::cout << "2. Only letters \n";
    std::cout << "3. Leeters and numbers \n";
    std::cout << "Choise(number): ";
    std::cin >> option;
    if (!std::cin) {
        return 1;
        std::exit(1);
    }
    std::cout << "Enter password length: ";
    std::cin >> maxLen;
    printf("\n");
    switch (option) {
        case 1:
            for (int len1 = 1; len1 <= maxLen; len1++) {
                bruteForce(len1, "0123456789");
            }
            break;
        case 2:
            for (int len2 = 1; len2 <= maxLen; len2++) {
                bruteForce(len2, "abcdefghijklmnopqrstuvwxyz");
            }
            break;
        case 3:
            for (int len3 = 1; len3 <= maxLen; len3++) {
                bruteForce(len3, "abcdefghijklmnopqrstuvwxyz0123456789");
            }
            break;
        default:
            break;
    }

    return 0;
}
