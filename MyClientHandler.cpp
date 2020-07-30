// Created by sheina on 10/01/19.
//

#include "MyClientHandler.h"
#include "BFS.h"
#include "DFS.h"
#include "Astar.h"
#include "BestFirstSearch.h"

void MyClientHandler ::handleClient(int socketID) {
    string line, sol;
    int i=0, j;
    double cost;
    State<Point>* node;
    vector<string> row;
    vector<string> stringMatrix;
    string matrixProblem;
    vector<State<Point>*> tempR;
    vector<State<Point>*> initGoalNode;
    vector<vector<State<Point>*>> tempMatrix;
    Point p;
    do {
        char buffer[1024];
        bzero(&buffer, sizeof(buffer));
        read(socketID, &buffer, sizeof(buffer));
        string s = buffer;
        size_t pos = s.find('\n');
        line = s.substr(0, pos);
        if (line.empty() || line == "end") {
            continue;
        }
        stringMatrix.push_back(line);
    }
    while (line != "end");

    for(i=0; i<stringMatrix.size()-2; i++){
        matrixProblem += stringMatrix.at(i);
        matrixProblem += "\n";
        row = split(stringMatrix.at(i), ',');
        for (j=0; j<row.size(); j++) {
            p.setX(i);
            p.setY(j);
            cost = stod(row.at(j));
            node = new State<Point>(p, cost);
            this->deleteVect.push_back(node);
            tempR.push_back(node);
        }
        tempMatrix.push_back(tempR);
        tempR.clear();
    }
    for(i=stringMatrix.size()-2; i<stringMatrix.size(); i++){
        matrixProblem += stringMatrix.at(i);
        matrixProblem += "\n";
        row = split(stringMatrix.at(i), ',');
        int x = stoi(row.at(0));
        int y = stoi(row.at(1));
        p.setX(x);
        p.setY(y);
        cost = tempMatrix.at(x).at(y)->getCost();
        node = new State<Point>(p, cost);
        this->deleteVect.push_back(node);
        initGoalNode.push_back(node);
    }
    Searchable<Point>* matrix = new Matrix(tempMatrix, initGoalNode.at(0), initGoalNode.at(1));
    if (cacheManager->checkProblemExist(matrixProblem)) {
        sol = cacheManager->getSolution(matrixProblem);
    } else {
        Searcher<Point>* searcher = new Astar<Point>();
        this->solver = new SearcherSolver<Point>(searcher);
        Result resulat = this->solver->solve(matrix);
        sol = resulat.getSolution();
        cacheManager->saveSolution(matrixProblem, sol);
        delete(searcher);
    }
    this->set(sol, socketID);
    tempMatrix.clear();
    stringMatrix.clear();
    initGoalNode.clear();
    matrixProblem.clear();
    delete(matrix);
}

void MyClientHandler:: set (string sol, int socketID) {
    sol += '\n';
    const char *buffer = sol.c_str();
    if (::send(socketID, buffer, strlen(buffer), 0) < 0) {
        perror("ERROR writting to socket");
        exit(1);
    }
}

vector<string> split(string line, char c) {
    stringstream ss( line );
    vector<string> resultat;
    while( ss.good() )
    {
        string substr;
        getline( ss, substr, c );
        resultat.push_back( substr );
    }
    return resultat;
}