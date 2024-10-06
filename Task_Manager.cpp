#include <iostream>
#include <vector>
#include <string>

class Task {
private:
    std::string title;
    std::string description;
    bool completed;

public:
    Task(const std::string &t, const std::string &d)
        : title(t), description(d), completed(false) {}

    void markAsCompleted() {
        completed = true;
    }

    std::string getTitle() const {
        return title;
    }

    std::string getDescription() const {
        return description;
    }

    bool isCompleted() const {
        return completed;
    }

    void display() const {
        std::cout << "[ " << (completed ? "X" : " ") << " ] " << title 
                  << ": " << description << std::endl;
    }
};

class TaskManager {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string &title, const std::string &description) {
        tasks.emplace_back(title, description);
        std::cout << "Task added: " << title << std::endl;
    }

    void completeTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].markAsCompleted();
            std::cout << "Task completed: " << tasks[index].getTitle() << std::endl;
        } else {
            std::cout << "Invalid task index!" << std::endl;
        }
    }

    void deleteTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            std::cout << "Deleting task: " << tasks[index].getTitle() << std::endl;
            tasks.erase(tasks.begin() + index);
        } else {
            std::cout << "Invalid task index!" << std::endl;
        }
    }

    void viewTasks() const {
        std::cout << "\n--- Task List ---\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i << ". ";
            tasks[i].display();
        }
        if (tasks.empty()) {
            std::cout << "No tasks available." << std::endl;
        }
    }
};

int main() {
    TaskManager taskManager;
    int choice;

    do {
        std::cout << "\n--- Task Management System ---\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. Complete Task\n";
        std::cout << "3. Delete Task\n";
        std::cout << "4. View Tasks\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // To ignore the newline character left in the buffer

        std::string title, description;
        int index;

        switch (choice) {
            case 1:
                std::cout << "Enter task title: ";
                std::getline(std::cin, title);
                std::cout << "Enter task description: ";
                std::getline(std::cin, description);
                taskManager.addTask(title, description);
                break;

            case 2:
                taskManager.viewTasks();
                std::cout << "Enter task index to complete: ";
                std::cin >> index;
                taskManager.completeTask(index);
                break;

            case 3:
                taskManager.viewTasks();
                std::cout << "Enter task index to delete: ";
                std::cin >> index;
                taskManager.deleteTask(index);
                break;

            case 4:
                taskManager.viewTasks();
                break;

            case 5:
                std::cout << "Exiting the system. Goodbye!" << std::endl;
                break;

            default:
                std::cout << "Invalid choice! Please try again." << std::endl;
        }
    } while (choice != 5);

    return 0;
}
