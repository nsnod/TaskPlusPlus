#ifndef PRIORITY_H
#define PRIORITY_H

#include <iostream>
#include "view.h"
#include "home.h"
#include "task.h"
#include "taskList.h"

using namespace std;

class Priority {
 public:
    void view(string choice) const;
    void priorityComplete() const;
    void priorityUncomplete() const;
    void priorityAll() const;
};

#endif