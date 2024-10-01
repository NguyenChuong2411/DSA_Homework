// STT: 22520165
// Full Name: Nguyễn Chu Nguyên Chương
// Homework
// Notes or Remarks: ......
#include <iostream>
#include <list>
#include <string>
#include <unordered_map>

using namespace std;

class MusicPlayer
{
    list<string> playlist;
    unordered_map<string, list<string>::iterator> songMap;
    list<string>::iterator currentSong;

public:
    MusicPlayer() : currentSong(playlist.end()) {}

    void addSong(const string &song)
    {
        playlist.push_back(song);
        songMap[song] = prev(playlist.end());
        if (currentSong == playlist.end())
        {
            currentSong = playlist.begin();
        }
    }

    void playNext()
    {
        if (playlist.empty())
            return;
        currentSong = next(currentSong) == playlist.end() ? playlist.begin() : next(currentSong);
    }

    void playPrevious()
    {
        if (playlist.empty())
            return;
        currentSong = currentSong == playlist.begin() ? prev(playlist.end()) : prev(currentSong);
    }

    void removeSong(const string &song)
    {
        if (songMap.find(song) != songMap.end())
        {
            auto it = songMap[song];
            if (currentSong == it)
            {
                playNext(); // Move to the next song before removing current
            }
            playlist.erase(it);
            songMap.erase(song);
            if (playlist.empty())
            {
                currentSong = playlist.end();
            }
        }
    }

    void displayPlaylist()
    {
        if (playlist.empty())
        {
            cout << endl;
            return;
        }
        for (const auto &song : playlist)
        {
            cout << song << " ";
        }
        cout << endl;
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
