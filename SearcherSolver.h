//
// Created by herold55 on 1/10/19.
//

#ifndef PROJ2_SEARCHERSOLVER_H
#define PROJ2_SEARCHERSOLVER_H
#include "Solver.h"
#include "Searcher.h"
template <class T>
class SearcherSolver : public Solver<Searchable<T>*,Result> {
    Searcher<T>* searcher;
public:
    SearcherSolver(Searcher<T>* search) {
        this->searcher = search;
    }
    Result solve(Searchable<T>* problem);
};
template <class T> Result SearcherSolver<T> ::solve(Searchable<T> *problem) {
    return searcher->search(problem);
}
#endif //PROJ2_SEARCHERSOLVER_H
