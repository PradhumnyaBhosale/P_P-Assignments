#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

class DataOperations {
public:
    virtual void createDataFile() {
        std::ofstream file("data.txt");
        file.close();
        std::cout << "Data file created successfully!\n";
    }

    virtual void displayData() {
        std::ifstream file("data.txt");
        if (file.is_open()) {
            std::string line;
            while (getline(file, line)) {
                std::cout << line << std::endl;
            }
            file.close();
        } else {
            throw std::runtime_error("Unable to open file!");
        }
    }

    virtual void searchData(const std::string &item) {
        std::ifstream file("data.txt");
        if (file.is_open()) {
            std::string line;
            bool found = false;
            while (getline(file, line)) {
                if (line.find(item) != std::string::npos) {
                    std::cout << "Item found: " << line << std::endl;
                    found = true;
                    break;
                }
            }
            file.close();
            if (!found) {
                throw std::invalid_argument("Item not found!");
            }
        } else {
            throw std::runtime_error("Unable to open file!");
        }
    }

    virtual void updateData(const std::string &oldItem, const std::string &newItem) {
        std::ifstream file("data.txt");
        if (file.is_open()) {
            std::string line;
            std::string content;
            bool found = false;
            while (getline(file, line)) {
                if (line.find(oldItem) != std::string::npos) {
                    content += newItem + "\n";
                    found = true;
                } else {
                    content += line + "\n";
                }
            }
            file.close();

            if (!found) {
                throw std::invalid_argument("Item to update not found!");
            }

            std::ofstream outFile("data.txt");
            if (outFile.is_open()) {
                outFile << content;
                outFile.close();
                std::cout << "Item updated successfully!\n";
            } else {
                throw std::runtime_error("Unable to open file for updating!");
            }
        } else {
            throw std::runtime_error("Unable to open file!");
        }
    }

    virtual ~DataOperations() {}
};

int main() {
    DataOperations obj;
    char choice;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "a. Create Data File\n";
        std::cout << "b. Display Data\n";
        std::cout << "c. Search Specific Item\n";
        std::cout << "d. Update Item\n";
        std::cout << "e. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 'a': {
                try {
                    obj.createDataFile();
                } catch (const std::exception &e) {
                    std::cerr << "Exception: " << e.what() << std::endl;
                }
                break;
            }
            case 'b': {
                try {
                    obj.displayData();
                } catch (const std::exception &e) {
                    std::cerr << "Exception: " << e.what() << std::endl;
                }
                break;
            }
            case 'c': {
                try {
                    std::string searchTerm;
                    std::cout << "Enter the item to search: ";
                    std::cin >> searchTerm;
                    obj.searchData(searchTerm);
                } catch (const std::exception &e) {
                    std::cerr << "Exception: " << e.what() << std::endl;
                }
                break;
            }
            case 'd': {
                try {
                    std::string oldItem, newItem;
                    std::cout << "Enter the item to update: ";
                    std::cin >> oldItem;
                    std::cout << "Enter the new item: ";
                    std::cin >> newItem;
                    obj.updateData(oldItem, newItem);
                } catch (const std::exception &e) {
                    std::cerr << "Exception: " << e.what() << std::endl;
                }
                break;
            }
            case 'e':
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice!\n";
        }
    } while (choice != 'e');

    return 0;
}
