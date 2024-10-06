#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

int binaryToDecimal(const std::string& binary) {
    int decimal = 0;
    for (size_t i = 0; i < binary.size(); ++i) {
        if (binary[binary.size() - 1 - i] == '1') {
            decimal += pow(2, i);
        }
    }
    return decimal;
}

int octalToDecimal(const std::string& octal) {
    int decimal = 0;
    for (size_t i = 0; i < octal.size(); ++i) {
        decimal += (octal[octal.size() - 1 - i] - '0') * pow(8, i);
    }
    return decimal;
}

int hexToDecimal(const std::string& hex) {
    int decimal = 0;
    for (size_t i = 0; i < hex.size(); ++i) {
        int value;
        if (hex[hex.size() - 1 - i] >= '0' && hex[hex.size() - 1 - i] <= '9') {
            value = hex[hex.size() - 1 - i] - '0';
        } else {
            value = hex[hex.size() - 1 - i] - 'A' + 10;
        }
        decimal += value * pow(16, i);
    }
    return decimal;
}

std::string decimalToBinary(int decimal) {
    std::string binary;
    do {
        binary += (decimal % 2) ? '1' : '0';
        decimal /= 2;
    } while (decimal > 0);
    std::reverse(binary.begin(), binary.end());
    return binary.empty() ? "0" : binary;
}

std::string decimalToOctal(int decimal) {
    std::string octal;
    do {
        octal += (decimal % 8) + '0';
        decimal /= 8;
    } while (decimal > 0);
    std::reverse(octal.begin(), octal.end());
    return octal.empty() ? "0" : octal;
}

std::string decimalToHexadecimal(int decimal) {
    std::string hexadecimal;
    do {
        int remainder = decimal % 16;
        if (remainder < 10)
            hexadecimal += (remainder + '0');
        else
            hexadecimal += (remainder - 10 + 'A');
        decimal /= 16;
    } while (decimal > 0);
    std::reverse(hexadecimal.begin(), hexadecimal.end());
    return hexadecimal.empty() ? "0" : hexadecimal;
}

int main() {
    std::string input;
    int choice;
    
    std::cout << "Choose input number system:\n1. Binary\n2. Octal\n3. Decimal\n4. Hexadecimal\n";
    std::cin >> choice;
    
    std::cout << "Enter the number: ";
    std::cin >> input;

    int decimalValue = 0;

    
    switch (choice) {
        case 1: decimalValue = binaryToDecimal(input); break;
        case 2: decimalValue = octalToDecimal(input); break;
        case 3: decimalValue = std::stoi(input); break; 
        case 4: decimalValue = hexToDecimal(input); break;
        default: std::cout << "Invalid choice!\n"; return 1;
    }

    
    std::cout << "Decimal: " << decimalValue << std::endl;
    std::cout << "Binary: " << decimalToBinary(decimalValue) << std::endl;
    std::cout << "Octal: " << decimalToOctal(decimalValue) << std::endl;
    std::cout << "Hexadecimal: " << decimalToHexadecimal(decimalValue) << std::endl;

    return 0;
}

