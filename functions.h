#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
using namespace std;

struct Task {
    int id;
    string title;
    int priority;      // Lower = higher priority
    string deadline;   // Format: YYYY-MM-DD
};

void addTask();
void viewTasks();
void deleteTask();
void sortTasks();

#endif