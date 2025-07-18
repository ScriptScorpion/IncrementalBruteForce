#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <fstream>

void bruteForce(int leng, const std::string& charset, const char answer, std::ofstream &out, const std::string &savedir = "") {
    std::vector<int> indices(leng, 0);  // counts like counter
    std::string current(leng, charset[0]);

    while (true) {
        if (answer == 'Y') {
            out << current << std::endl;
        }
        else {
            std::cout << current << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(25)); // can change this value if you want faster or slower output
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
    std::string savedir = "";
    char answer;
    std::ofstream out;
    std::string logo =
        "  ▗▄▄▖▗▄▄▄▖▗▖  ▗▖▗▄▄▖ ▗▖   ▗▄▄▄▖    ▗▄▄▖ ▗▄▄▖ ▗▖ ▗▖▗▄▄▄▖▗▄▄▄▖▗▄▄▄▖ ▗▄▖ ▗▄▄▖  ▗▄▄▖▗▄▄▄▖\n"
        " ▐▌     █  ▐▛▚▞▜▌▐▌ ▐▌▐▌   ▐▌       ▐▌ ▐▌▐▌ ▐▌▐▌ ▐▌  █  ▐▌   ▐▌   ▐▌ ▐▌▐▌ ▐▌▐▌   ▐▌\n"
        "  ▝▀▚▖  █  ▐▌  ▐▌▐▛▀▘ ▐▌   ▐▛▀▀▘    ▐▛▀▚▖▐▛▀▚▖▐▌ ▐▌  █  ▐▛▀▀▘▐▛▀▀▘▐▌ ▐▌▐▛▀▚▖▐▌   ▐▛▀▀▘\n"
        " ▗▄▄▞▘▗▄█▄▖▐▌  ▐▌▐▌   ▐▙▄▄▖▐▙▄▄▖    ▐▙▄▞▘▐▌ ▐▌▝▚▄▞▘  █  ▐▙▄▄▖▐▌   ▝▚▄▞▘▐▌ ▐▌▝▚▄▄▖▐▙▄▄▖\n"
        "                                                                                     ";

    std::cout << logo << std::endl;
    std::cout << "Wanna save output to file(Y/n): ";
    std::cin >> answer;
    if (!std::cin) {
        return 1;
        std::exit(1);
    }
    answer = std::toupper(answer);
    if (answer == 'Y') {
        std::cout << "Enter directory name you want to save output: ";
        std::cin >> savedir;
        if (!std::cin) {
            return 1;
            std::exit(1);
        }
        out.open("passwords.txt");
        if (!out.is_open()) {
            std::cout << "Failed to open file" << std::endl;
            return 1;
	    std::exit(1);
        }

    }
    std::cout << "Enter method to crack password: \n";
    std::cout << "1. Only numbers \n";
    std::cout << "2. Only letters \n";
    std::cout << "3. Letters and numbers \n";
    std::cout << "4. Ultimate cracker: Numbers, lowercase and uppercase letters \n";
    std::cout << "Choice(number): ";
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
                bruteForce(len1, "0123456789", answer, out, savedir);
            }
            break;
        case 2:
            for (int len2 = 1; len2 <= maxLen; len2++) {
                bruteForce(len2, "abcdefghijklmnopqrstuvwxyz", answer, out, savedir);
            }
            break;
        case 3:
            for (int len3 = 1; len3 <= maxLen; len3++) {
                bruteForce(len3, "abcdefghijklmnopqrstuvwxyz0123456789", answer, out, savedir);
            }
            break;
        case 4:
            for (int len4 = 1; len4 <= maxLen; len4++) {
                bruteForce(len4, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789", answer, out, savedir);
            }
            break;
        default:
            break;
    	
    }
    if (out.is_open()) {
        out.close();
    }

    return 0;
}
