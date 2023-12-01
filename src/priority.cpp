#include "../header/priority.h"

void Priority::view(string choice) const {
    if (choice == "Complete") {
        priorityComplete();
    }
    else if (choice == "Uncomplete") {
        priorityUncomplete();
    }
    else if (choice == "All") {
        priorityAll();
    }
}