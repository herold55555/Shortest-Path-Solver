//
// Created by herold55 on 1/2/19.
//

#ifndef PROJ2_SEARCHER_H
#define PROJ2_SEARCHER_H
#include <vector>
#include "Searchable.h"
#include "Result.h"

template <class T> class Searcher {
public:
    virtual Result search(Searchable<T>* searchable) = 0;
};
#endif //PROJ2_SEARCHER_H
