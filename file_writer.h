#ifndef FILE_WRITER_H
#define FILE_WRITER_H


#include <iostream>
#include <fstream>
#include <vector>
#include <string>


// Question 1: writes the maximum streak sum
void question1_writer(const std::string& file_path, long long output) {
    std::ofstream fout(file_path);
    if (!fout.is_open()) {
        std::cerr << "Error: Could not open file " << file_path << std::endl;
        return;
    }

    fout << output << "\n";

    fout.close();
}



// Question 2: writes the deepest twin-leaf depth (or -1)
void question2_writer(const std::string& file_path, int output) {
    std::ofstream fout(file_path);
    if (!fout.is_open()) {
        std::cerr << "Error opening file for writing: " << file_path << std::endl;
        return;
    }

    fout << output << "\n";

    fout.close();
}



// Question 3: writes the minimum total time for the mailroom robot
void question3_writer(const std::string& file_path, long long value) {
    std::ofstream fout(file_path);
    if (!fout.is_open()) {
        std::cerr << "Error opening file for writing: " << file_path << std::endl;
        return;
    }
    fout << value << "\n";
    fout.close();
}

#endif
