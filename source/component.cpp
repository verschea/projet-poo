#include "../include/component.h"
#include "../include/all.h"

using namespace std;

//Component::Component(string text_file)

// CPU
CPU::CPU(string text_file) : Component() 
{
    cout << "test" << endl;
    ifstream inputFile(text_file); // Try to open the file

    // Assert that the file was opened successfully
    assert(inputFile && "Unable to open the file: Check if the file exists and is accessible.");

    string line;

    // Read the file line by line
    while (getline(inputFile, line)) 
    {
        cout << line << endl; // Print each line to the console
    }

    inputFile.close(); // Close the file
}

void CPU::simulate() {
    // Implementation of the simulation logic for CPU
}