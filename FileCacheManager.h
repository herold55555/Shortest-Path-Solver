// Created by sheina on 1/1/19.
//

#ifndef PROJ2_FILECACHEMANAGER_H
#define PROJ2_FILECACHEMANAGER_H
#include "CacheManager.h"
#include "Matrix.h"
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <map>

template <class Problem, class Solution>
class FileCacheManager: public CacheManager<Problem, Solution> {
    map<Problem,Solution> cache;
public :
    FileCacheManager();
    bool checkProblemExist(Problem problem);
    Solution getSolution(Problem problem);
    void saveSolution(Problem problem, Solution solution);
    vector<string> split(string line, char c);
    bool is_file_exist(const char *fileName);
    void writeInFile(Problem prob, Solution sol);
    void loadFromFile();
};

template <class Problem, class Solution>
FileCacheManager<Problem,Solution>::FileCacheManager() {
    this->loadFromFile();
}

template <class Problem, class Solution>
void FileCacheManager<Problem,Solution>::loadFromFile() {
    ifstream rFile;
    string line, solution;
    string matrix;
    if(!is_file_exist("CManager.txt")) {
        rFile.open("CManager.txt", ios::out | ios::app | ios::ate);
        rFile.close();
    }
    rFile.open("CManager.txt");
    if(!rFile.good()) {
        throw "ERROR OPENING THE FILE";
    }
    while (getline(rFile, line)) {
        while(getline(rFile, line) && line != "SOL") {
            matrix += line;
            matrix += "\n";
        }
        while(getline(rFile, line) && line != "$$$") {
            solution = line;
        }
        this->cache[matrix] = solution;
    }
    rFile.close();
}

template <class Problem, class Solution>
bool FileCacheManager<Problem,Solution>:: checkProblemExist(Problem problem) {
    return !(this->cache.find(problem) == this->cache.end());
}

template <class Problem, class Solution>
Solution FileCacheManager<Problem,Solution>::getSolution(Problem problem) {
    return this->cache[problem];

}

template <class Problem, class Solution>
void FileCacheManager<Problem,Solution>::saveSolution(Problem problem, Solution solution) {
    this->cache[problem] = solution;
    this->writeInFile(problem, solution);
}

template <class Problem, class Solution>
vector<string> FileCacheManager<Problem,Solution>::split(string line, char c) {
    stringstream ss( line );
    vector<string> result;
    while( ss.good() )
    {
        string substr;
        getline( ss, substr, c );
        result.push_back( substr );
    }
    return result;
}

template <class Problem, class Solution>
bool FileCacheManager<Problem,Solution>::is_file_exist(const char *fileName) {
    std::ifstream infile(fileName);
    return infile.good();
}
template <class Problem, class Solution>
void FileCacheManager<Problem,Solution>::writeInFile(Problem prob, Solution sol) {
    ofstream file;
    file.open("CManager.txt", ios::out | ios::app | ios::ate);
    file << "$$$" << endl;
    file << prob;
    file << "SOL" << endl;
    file << sol << endl;
    file << "$$$" << endl;
    file.close();
}
#endif //PROJ2_FILECACHEMANAGER_H