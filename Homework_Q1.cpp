// STT: 22520165
// Full Name: Nguyễn Chu Nguyên Chương
// Homework
// Notes or Remarks: ......
#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
    string song;
    Node *next;
    Node *prev;

    Node(const string &song) : song(song), next(nullptr), prev(nullptr) {}
};

class LinkedList
{
public:
    Node *head;
    Node *tail;

    LinkedList() : head(nullptr), tail(nullptr) {}

    void addSong(const string &song)
    {
        Node *newNode = new Node(song);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void removeSong(Node *node)
    {
        if (!node)
            return;

        if (node == head && node == tail)
        {
            head = tail = nullptr;
        }
        else if (node == head)
        {
            head = head->next;
            head->prev = nullptr;
        }
        else if (node == tail)
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else
        {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        delete node;
    }

    void displayPlaylist()
    {
        Node *current = head;
        while (current)
        {
            cout << current->song << " ";
            current = current->next;
        }
        cout << endl;
    }
};

class MusicPlayer
{
    LinkedList playlist;
    Node *currentSong;

public:
    MusicPlayer() : currentSong(nullptr) {}

    void addSong(const string &song)
    {
        playlist.addSong(song);
        if (!currentSong)
        {
            currentSong = playlist.head;
        }
    }

    void playNext()
    {
        if (!currentSong || !playlist.head)
            return;

        currentSong = currentSong->next ? currentSong->next : playlist.head;
    }

    void playPrevious()
    {
        if (!currentSong || !playlist.head)
            return;

        currentSong = currentSong->prev ? currentSong->prev : playlist.tail;
    }

    void removeSong(const string &song)
    {
        Node *current = playlist.head;
        while (current)
        {
            if (current->song == song)
            {
                if (current == currentSong)
                {
                    playNext(); // Move to the next song before removing current
                }
                playlist.removeSong(current);
                if (!playlist.head)
                {
                    currentSong = nullptr;
                }
                break;
            }
            current = current->next;
        }
    }

    void displayPlaylist()
    {
        playlist.displayPlaylist();
    }
};

int main()
{
    cout << "STT: 22520165\n";
    cout << "Full Name : Nguyen Chu Nguyen Chuong\n";
    cout << "Homework\n";
    cout << "Notes or Remarks: ......\n";
    cout << "\n";
    int n;
    cin >> n;

    MusicPlayer player;

    string command, song;
    for (int i = 0; i < n; ++i)
    {
        cin >> command;
        if (command == "ADD")
        {
            cin >> song;
            player.addSong(song);
        }
        else if (command == "NEXT")
        {
            player.playNext();
        }
        else if (command == "PREV")
        {
            player.playPrevious();
        }
        else if (command == "REMOVE")
        {
            cin >> song;
            player.removeSong(song);
        }
        else if (command == "DISPLAY")
        {
            player.displayPlaylist();
        }
    }
    system("pause");
    return 0;
}
