#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

struct PasswordEntry {
    std::string website;
    std::string username;
    std::string password;
};

class PasswordManager {
private:
    std::vector<PasswordEntry> passwords;

public:
    void addPassword(const std::string& website, const std::string& username, const std::string& password) {
        PasswordEntry entry;
        entry.website = website;
        entry.username = username;
        entry.password = password;
        passwords.push_back(entry);
    }

    PasswordEntry getPassword(const std::string& website) {
        for (const auto& entry : passwords) {
            if (entry.website == website) {
                return entry;
            }
        }
        return PasswordEntry();  // Return an empty entry if not found
    }

    std::string generatePassword(int length) {
        const std::string validChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()";
        const int validCharsSize = validChars.size();
        std::string password;
        srand(time(nullptr));
        for (int i = 0; i < length; ++i) {
            password += validChars[rand() % validCharsSize];
        }
        return password;
    }
};

int main() {
    PasswordManager manager;

    // Add passwords
    manager.addPassword("example.com", "user1", "password123");
    manager.addPassword("gmail.com", "user2", "qwerty");

    // Retrieve passwords
    PasswordEntry entry1 = manager.getPassword("example.com");
    PasswordEntry entry2 = manager.getPassword("gmail.com");

    std::cout << "Password for example.com: " << entry1.password << std::endl;
    std::cout << "Password for gmail.com: " << entry2.password << std::endl;

    // Generate a random password
    std::string generatedPassword = manager.generatePassword(10);
    std::cout << "Generated password: " << generatedPassword << std::endl;

    return 0;
}
