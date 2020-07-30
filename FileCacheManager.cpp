//
// Created by sheina on 1/1/19.
//
/*
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>
#include "FileCacheManager.h"

bool FileCacheManager::checkProblemExist(string file, string problem) {
    ifstream rFile;
    string line;
    if(!is_file_exist("CManager.txt")) {
        rFile.open("CManager.txt", ios::out | ios::app | ios::ate);
        rFile.close();
    }
    rFile.open(file);
    if(!rFile.good()) {
        throw "ERROR OPENING THE FILE";
    }
        while(getline(rFile, line)) {
            if(this->split(line, ':').at(0) == problem) {
                rFile.close();
                return true;
            }
        }
        rFile.close();
        return false;
}



string FileCacheManager::getSolution(string problem) {
    ifstream rFile;
    string line;
    string file = "CManager.txt";
    rFile.open(file.c_str());
    if(rFile.good()) {
        while(getline(rFile, line)) {
            if(this->split(line, ':').at(0) == problem) {
                rFile.close();
                return this->split(line, ':').at(1);
            }
        }
    }
    throw "Unable to open file.";
}

void FileCacheManager::saveSolution(string problem, string solution) {
    ofstream file;
    file.open("CManager.txt", ios::out | ios::app | ios::ate);
    file << problem << ":" << solution << endl;
    file.close();
}

vector<string> FileCacheManager::split(string line, char c) {
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

bool FileCacheManager:: is_file_exist(const char *fileName) {
    std::ifstream infile(fileName);
    return infile.good();
}
 */