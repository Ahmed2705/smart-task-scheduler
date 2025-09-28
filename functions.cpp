#include <iostream>
#include <vector>
#include <algorithm>
#include "functions.h"
using namespace std;

vector<Task> tasks;
int taskID = 1;

bool compareTasks(const Task &a, const Task &b) {
    if (a.priority == b.priority)
        return a.deadline < b.deadline;
    return a.priority < b.priority;
}

void sortTasks() {
    sort(tasks.begin(), tasks.end(), compareTasks);
}

void addTask() {
    Task t;
    t.id = taskID++;

    cout << "Enter task title: ";
    cin.ignore();
    getline(cin, t.title);

    cout << "Enter priority (1 = highest): ";
    cin >> t.priority;

    cout << "Enter deadline (YYYY-MM-DD): ";
    cin >> t.deadline;

    tasks.push_back(t);
    cout << "✅ Task added successfully.\n";
}

void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks to show.\n";
        return;
    }

    sortTasks();
    cout << "\n📋 Task List:\n";
    for (const auto &t : tasks) {
        cout << "ID: " << t.id
             << " | Title: " << t.title
             << " | Priority: " << t.priority
             << " | Deadline: " << t.deadline << "\n";
    }
}

void deleteTask() {
    int id;
    cout << "Enter ID of task to delete: ";
    cin >> id;

    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->id == id) {
            tasks.erase(it);
            cout << "🗑️ Task deleted.\n";
            return;
        }
    }

    cout << "⚠️ Task not found.\n";
}