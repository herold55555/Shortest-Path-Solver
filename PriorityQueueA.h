//
// Created by herold55 on 1/15/19.
//

#ifndef PROJ2_PRIORITYQUEUEA_H
#define PROJ2_PRIORITYQUEUEA_H

#include <queue>
using namespace std;
template <class T, class priority>
class PriorityQueueA {
public:
   typedef std::pair<priority, T> PriorityElement;
   std::priority_queue<PriorityElement, vector<PriorityElement>, greater<PriorityElement>> element;
   bool is_empty() const {
       return element.empty();
   }
   void put(T item, priority priority1) {
       this->element.emplace(priority1, item);
   }
   T get() {
       T bestItem = this->element.top().second;
       this->element.pop();
       return bestItem;
   }
};
#endif //PROJ2_PRIORITYQUEUEA_H
