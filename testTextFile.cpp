#include <iostream>
#include <fstream>
#include <list>
#include <sstream>

class Person {
public:
    std::string Name;
    int Age;
    std::string DateOfBirth;
    double Salary;

    // Constructor
    Person(const std::string& name, int age, const std::string& dob, double salary)
        : Name(name), Age(age), DateOfBirth(dob), Salary(salary) {}

    // Default constructor
    Person() : Age(0), Salary(0.0) {}
};

// Function to write a list of objects to a text file
void writeToFile(const std::list<Person>& people, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Error opening file for writing." << std::endl;
        return;
    }

    for (const auto& person : people) {
        outFile << person.Name << ',' << person.Age << ',' << person.DateOfBirth << ',' << person.Salary << '\n';
    }

    outFile.close();
}

// Function to read a list of objects from a text file
std::list<Person> readFromFile(const std::string& filename) {
    std::list<Person> people;

    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "Error opening file for reading." << std::endl;
        return people;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        std::string name, dob;
        int age;
        double salary;

        if (std::getline(iss, name, ',') && iss >> age >> std::ws &&
            std::getline(iss, dob, ',') && iss >> salary) {
            people.emplace_back(name, age, dob, salary);
        } else {
            std::cerr << "Error reading line: " << line << std::endl;
        }
    }

    inFile.close();

    return people;
}

int main() {
    // Create a list of Person objects
    std::list<Person> people;
    people.emplace_back("John Doe", 25, "1998-05-15", 50000.0);
    people.emplace_back("Jane Smith", 30, "1992-09-22", 60000.0);
    people.emplace_back("Bob Johnson", 22, "2001-02-10", 45000.0);

    // Write the list to a file
    writeToFile(people, "people.txt");

    // Read the list from the file
    std::list<Person> readPeople = readFromFile("people.txt");

    // Display the read data
    for (const auto& person : readPeople) {
        std::cout << "Name: " << person.Name << ", Age: " << person.Age
                  << ", Date of Birth: " << person.DateOfBirth << ", Salary: " << person.Salary << std::endl;
    }

    return 0;
}

