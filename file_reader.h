#ifndef FILE_READER_H
#define FILE_READER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <iterator>
#include <chrono>
using namespace std;

// Question 1: Mess Rotation Streak
// File format:
//   line 1        : n
//   line 2        : delta[0] delta[1] ... delta[n-1]
void question1_reader(const string& filename, vector<int>& delta) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    int n;
    file >> n;
    delta.resize(n);
    for (int i = 0; i < n; i++) {
        file >> delta[i];
    }

    file.close();
}




// Question 2: Deepest Twin Leaf Depth
// File format:
//   a single line containing the level-order representation of the tree,
//   space separated, where the literal token "null" marks a missing child.
//   e.g. 1 2 3 3 null null 2
//
// Output arrays:
//   values[i]  : value of the i-th node in level order (meaningless if present[i] is false)
//   present[i] : true if the i-th slot in the level order holds an actual node
void question2_reader(const string& file_path, vector<int>& values, vector<bool>& present) {
    ifstream infile(file_path);
    if (!infile.is_open()) {
        cerr << "Error: Cannot open file " << file_path << endl;
        return;
    }

    string token;
    while (infile >> token) {
        if (token == "null") {
            values.push_back(0);
            present.push_back(false);
        } else {
            values.push_back(stoi(token));
            present.push_back(true);
        }
    }

    infile.close();
}




// Question 3: Automated Mailroom Robot
// File format:
//   line 1        : N E C S
//   next E lines  : u v w
//   next line     : K
//   next line     : C integers (destination room ids, in conveyor/queue order)
void question3_reader(
    const string& file_path,
    int& N,
    vector<vector<int>>& edges,
    int& S,
    int& K,
    vector<int>& destinations
) {
    ifstream infile(file_path);
    if (!infile.is_open()) {
        cerr << "Error: Cannot open file " << file_path << endl;
        return;
    }

    int E, C;
    infile >> N >> E >> C >> S;

    edges.assign(E, vector<int>(3));
    for (int i = 0; i < E; i++) {
        infile >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    infile >> K;

    destinations.resize(C);
    for (int i = 0; i < C; i++) {
        infile >> destinations[i];
    }

    infile.close();
}




#endif
