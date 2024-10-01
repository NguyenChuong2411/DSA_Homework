// STT: 22520165
// Full Name: Nguyễn Chu Nguyên Chương
// Homework
// Notes or Remarks: ......
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class AuthenticationManager
{
private:
    unordered_map<string, int> tokenMap; // Maps tokenId to its expiration time
    int timeToLive;                      // Time-to-live duration for tokens

public:
    // Constructor: Initialize the manager with the timeToLive value
    AuthenticationManager(int ttl)
    {
        timeToLive = ttl;
    }

    // Token Generation: Create a new token with the current time
    void generate(string tokenId, int currentTime)
    {
        tokenMap[tokenId] = currentTime + timeToLive; // Set expiration time
    }

    // Token Renewal: Renew the token if it's still valid (not expired)
    void renew(string tokenId, int currentTime)
    {
        if (tokenMap.find(tokenId) != tokenMap.end() && tokenMap[tokenId] > currentTime)
        {
            tokenMap[tokenId] = currentTime + timeToLive; // Reset the expiration time
        }
    }

    // Counting Unexpired Tokens: Count tokens that have not yet expired
    int countUnexpiredTokens(int currentTime)
    {
        int count = 0;
        for (auto it = tokenMap.begin(); it != tokenMap.end();)
        {
            if (it->second > currentTime)
            {
                count++;
                ++it;
            }
            else
            {
                // Remove expired tokens
                it = tokenMap.erase(it);
            }
        }
        return count;
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

    vector<string> result; // To store the output of operations

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
            result.push_back("null"); // No output for generate
        }
        else if (operation == "renew")
        {
            string tokenId;
            int currentTime;
            cout << "Enter tokenId and currentTime: ";
            cin >> tokenId >> currentTime;
            auth.renew(tokenId, currentTime);
            result.push_back("null"); // No output for renew
        }
        else if (operation == "countUnexpiredTokens")
        {
            int currentTime;
            cout << "Enter currentTime: ";
            cin >> currentTime;
            int count = auth.countUnexpiredTokens(currentTime);
            result.push_back(to_string(count)); // Store the count of unexpired tokens
        }
        else
        {
            cout << "Invalid operation." << endl;
            --i; // Decrement i to retry the same step
        }
    }

    // Output the results of the operations
    cout << "Results of operations: " << endl;
    for (const string &res : result)
    {
        if (res == "null")
        {
            cout << "null" << endl;
        }
        else
        {
            cout << res << endl;
        }
    }
    system("pause");
    return 0;
}
