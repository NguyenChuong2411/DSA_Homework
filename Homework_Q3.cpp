// STT: 22520165
// Full Name: Nguyễn Chu Nguyên Chương
// Homework
// Notes or Remarks: ......
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Node structure for the doubly linked list
struct TokenNode
{
    string tokenId;
    int expirationTime;
    TokenNode *prev;
    TokenNode *next;

    TokenNode(string id, int expTime) : tokenId(id), expirationTime(expTime), prev(nullptr), next(nullptr) {}
};

// AuthenticationManager class
class AuthenticationManager
{
private:
    TokenNode *head; // Head of the linked list
    TokenNode *tail; // Tail of the linked list
    int timeToLive;  // Time-to-live duration for tokens

public:
    // Constructor: Initialize the manager with the timeToLive value
    AuthenticationManager(int ttl) : timeToLive(ttl), head(nullptr), tail(nullptr) {}

    // Token Generation: Create a new token with the current time
    void generate(string tokenId, int currentTime)
    {
        // Create a new token node with the expiration time
        TokenNode *newToken = new TokenNode(tokenId, currentTime + timeToLive);

        // Insert the new token at the end of the linked list
        if (tail)
        {
            tail->next = newToken;
            newToken->prev = tail;
            tail = newToken;
        }
        else
        {
            head = tail = newToken; // First token
        }
    }

    // Token Renewal: Renew the token if it's still valid (not expired)
    void renew(string tokenId, int currentTime)
    {
        TokenNode *current = head;
        while (current)
        {
            if (current->tokenId == tokenId && current->expirationTime > currentTime)
            {
                current->expirationTime = currentTime + timeToLive; // Reset the expiration time
                return;
            }
            current = current->next;
        }
    }

    // Counting Unexpired Tokens: Count tokens that have not yet expired
    int countUnexpiredTokens(int currentTime)
    {
        int count = 0;
        TokenNode *current = head;

        while (current)
        {
            // Check if the token is unexpired
            if (current->expirationTime > currentTime)
            {
                count++;
            }
            else
            {
                // Remove expired token from the list
                TokenNode *toDelete = current;
                if (current->prev)
                {
                    current->prev->next = current->next; // Bypass current node
                }
                else
                {
                    head = current->next; // Update head if needed
                }
                if (current->next)
                {
                    current->next->prev = current->prev; // Bypass current node
                }
                else
                {
                    tail = current->prev; // Update tail if needed
                }
                current = current->next; // Move to the next node
                delete toDelete;         // Free memory
                continue;                // Skip the increment of current
            }
            current = current->next; // Move to the next token
        }
        return count;
    }

    // Destructor to clean up the linked list
    ~AuthenticationManager()
    {
        TokenNode *current = head;
        while (current)
        {
            TokenNode *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

// Driver code to take input from the user
int main()
{
    cout << "STT: 22520165\n";
    cout << "Full Name : Nguyen Chu Nguyen Chuong\n";
    cout << "Homework\n";
    cout << "Notes or Remarks: ......\n";
    cout << "\n";
    int timeToLive;
    cout << "Enter the timeToLive value: ";
    cin >> timeToLive;

    AuthenticationManager auth(timeToLive); // Initialize with user-defined timeToLive

    int n;
    cout << "Enter the number of operations: ";
    cin >> n;

    vector<string> results; // To store the output of operations

    for (int i = 0; i < n; ++i)
    {
        string operation;
        cout << "Enter operation (generate/renew/countUnexpiredTokens): ";
        cin >> operation;

        if (operation == "generate")
        {
            string tokenId;
            int currentTime;
            cout << "Enter tokenId and currentTime: ";
            cin >> tokenId >> currentTime;
            auth.generate(tokenId, currentTime);
            results.push_back("null"); // No output for generate
        }
        else if (operation == "renew")
        {
            string tokenId;
            int currentTime;
            cout << "Enter tokenId and currentTime: ";
            cin >> tokenId >> currentTime;
            auth.renew(tokenId, currentTime);
            results.push_back("null"); // No output for renew
        }
        else if (operation == "countUnexpiredTokens")
        {
            int currentTime;
            cout << "Enter currentTime: ";
            cin >> currentTime;
            int count = auth.countUnexpiredTokens(currentTime);
            results.push_back(to_string(count)); // Store the count of unexpired tokens
        }
        else
        {
            cout << "Invalid operation." << endl;
            --i; // Decrement i to retry the same step
        }
    }

    // Output the results of the operations
    cout << "Results of operations: " << endl;
    for (const string &res : results)
    {
        cout << res << endl;
    }

    system("pause");
    return 0;
}
