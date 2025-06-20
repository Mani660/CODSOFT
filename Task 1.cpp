#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Structure to store a task
struct Task {
    string description;
    bool completed;
};

// Function to display the list of tasks
void viewTasks(const vector<Task>& tasks) {
    cout << "\n--- TO-DO LIST ---\n";
    if (tasks.empty()) {
        cout << "No tasks found.\n";
        return;
    }

    for (int i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". [" << (tasks[i].completed ? "?" : "?") << "] " << tasks[i].description << endl;
    }
}

// Function to add a new task
void addTask(vector<Task>& tasks) {
    Task newTask;
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, newTask.description);
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Task added successfully.\n";
}

// Function to mark a task as completed
void markTaskCompleted(vector<Task>& tasks) {
    int index;
    viewTasks(tasks);
    cout << "Enter task number to mark as completed: ";
    cin >> index;
    if (index >= 1 && index <= tasks.size()) {
        tasks[index - 1].completed = true;
        cout << "Task marked as completed.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

// Function to remove a task
void removeTask(vector<Task>& tasks) {
    int index;
    viewTasks(tasks);
    cout << "Enter task number to remove: ";
    cin >> index;
    if (index >= 1 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task removed successfully.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

int main() {
    vector<Task> tasks;
    int choice;

    while (true) {
        cout << "\n--- TO-DO LIST MANAGER ---\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addTask(tasks); break;
            case 2: viewTasks(tasks); break;
            case 3: markTaskCompleted(tasks); break;
            case 4: removeTask(tasks); break;
            case 5: cout << "Goodbye!\n"; return 0;
            default: cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
