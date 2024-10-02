// STT: 22520165
// Full Name: Nguyễn Chu Nguyên Chương
// Homework
// Notes or Remarks: ......
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node
{
public:
    string url;
    Node *prev;
    Node *next;

    Node(const string &url) : url(url), prev(nullptr), next(nullptr) {}
};

class BrowserHistory
{
private:
    Node *current; // Pointer to the current page in the history

public:
    // Constructor to initialize with the homepage
    BrowserHistory(string homepage)
    {
        current = new Node(homepage); // Create the homepage node and set it as the current page
    }

    // Visit a new URL and clear any forward history
    void visit(string url)
    {
        Node *newNode = new Node(url);
        current->next = newNode; // Clear forward history by linking current to the new node
        newNode->prev = current; // Link back to the current page
        current = newNode;       // Move current to the new page
    }

    // Move back a specified number of steps and return the current URL
    string back(int steps)
    {
        while (steps > 0 && current->prev != nullptr)
        {
            current = current->prev;
            steps--;
        }
        return current->url; // Return the URL at the new current position
    }

    // Move forward a specified number of steps and return the current URL
    string forward(int steps)
    {
        while (steps > 0 && current->next != nullptr)
        {
            current = current->next;
            steps--;
        }
        return current->url; // Return the URL at the new current position
    }
};

// Driver code to simulate user input for operations
int main()
{
    cout << "STT: 22520165\n";
    cout << "Full Name : Nguyen Chu Nguyen Chuong\n";
    cout << "Homework\n";
    cout << "Notes or Remarks: ......\n";
    cout << "\n";
    string homepage;
    cout << "Enter the homepage URL: ";
    cin >> homepage;

    BrowserHistory browser(homepage); // Initialize browser with homepage

    int n;
    cout << "Enter the number of operations: ";
    cin >> n;

    vector<string> result; // To store the output of the operations

    for (int i = 0; i < n; ++i)
    {
        string operation;
        cout << "Enter operation (visit/back/forward): ";
        cin >> operation;

        if (operation == "visit")
        {
            string url;
            cout << "Enter the URL to visit: ";
            cin >> url;
            browser.visit(url);
            result.push_back("null"); // 'visit' operation doesn't return anything
        }
        else if (operation == "back")
        {
            int steps;
            cout << "Enter the number of steps to go back: ";
            cin >> steps;
            result.push_back(browser.back(steps)); // Store the current URL after going back
        }
        else if (operation == "forward")
        {
            int steps;
            cout << "Enter the number of steps to go forward: ";
            cin >> steps;
            result.push_back(browser.forward(steps)); // Store the current URL after going forward
        }
        else
        {
            cout << "Invalid operation. Please enter 'visit', 'back', or 'forward'." << endl;
        }
    }

    // Output the results of the operations at the end
    cout << "Results of operations: " << endl;
    cout << "[";
    for (int i = 0; i < result.size(); ++i)
    {
        cout << "\"" << result[i] << "\"";
        if (i != result.size() - 1) // To avoid printing an extra comma after the last result
            cout << ", ";
    }
    cout << "]" << endl;
    system("pause");
    return 0;
}
