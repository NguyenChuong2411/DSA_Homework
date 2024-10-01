// STT: 22520165
// Full Name: Nguyễn Chu Nguyên Chương
// Homework
// Notes or Remarks: ......
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BrowserHistory
{
private:
    vector<string> history; // Stores the URLs visited
    int current;            // Index pointing to the current page in the history

public:
    // Constructor to initialize with the homepage
    BrowserHistory(string homepage)
    {
        history.push_back(homepage); // Add the homepage to the history
        current = 0;                 // Set current index to the homepage
    }

    // Visit a new URL and clear any forward history
    void visit(string url)
    {
        history.resize(current + 1); // Clear forward history
        history.push_back(url);      // Add the new URL to the history
        current++;                   // Move current index to the new page
    }

    // Move back a specified number of steps and return the current URL
    string back(int steps)
    {
        current = max(0, current - steps); // Calculate the new current position
        return history[current];           // Return the URL at the new position
    }

    // Move forward a specified number of steps and return the current URL
    string forward(int steps)
    {
        current = min((int)history.size() - 1, current + steps); // Calculate the new current position
        return history[current];                                 // Return the URL at the new position
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

    // Output the results of the operations
    cout << "Results of operations: " << endl;
    for (const string &url : result)
    {
        cout << url << endl;
    }
    system("pause");
    return 0;
}
