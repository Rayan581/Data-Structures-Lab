<<<<<<< HEAD
#include <iostream>

using namespace std;

struct Song
{
    int songID;
    string songName;

    Song() {}
    Song(int id, string name)
    {
        songID = id;
        songName = name;
    }
};

class CircularList
{
private:
    class Node
    {
    public:
        Song data;
        Node *next;
    };
    Node *head;
    Node *tail;
    Node *currentSong;
    int size;

public:
    CircularList()
    {
        head = nullptr;
        tail = nullptr;
        currentSong = nullptr;
        size = 0;
    }

    // Add a song to the playlist
    void addSong(int songID, string songName)
    {
        Node *newNode = new Node;
        newNode->data = Song(songID, songName);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            newNode->next = head;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            newNode->next = head;
        }
        currentSong = newNode;
        size++;
    }

    // Remove a song from the playlist
    void removeSong(int songID)
    {
        if (head == nullptr)
        {
            cout << "Playlist is empty!";
            return;
        }

        Node *current = head;
        Node *temp = head;
        do
        {
            if (current->data.songID == songID)
            {
                if (current == head && tail == head)
                {
                    head = nullptr;
                    tail = nullptr;
                    delete current;
                }
                else if (current == head)
                {
                    head = head->next;
                    delete current;
                }
                else if (current == tail)
                {
                    tail = temp;
                    tail->next = head;
                    delete current;
                }
                else
                {
                    temp->next = current->next;
                    delete current;
                }

                size--;
                return;
            }
            temp = current;
            current = current->next;
        } while (current != head);
    }

    // Play the next song
    void playNextSong()
    {
        if (head == nullptr)
        {
            cout << "Playlist is empty!";
            return;
        }

        if (currentSong == nullptr)
        {
            currentSong = head;
            return;
        }

        currentSong = currentSong->next;
        cout << "Currently Playing: " << currentSong->data.songName << endl;
    }

    // Print the songs in the playlist
    void displayPlaylist()
    {
        cout << "Playlist Size: " << size << endl;
        Node *current = head;
        for (int i = 0; i < size; i++)
        {
            cout << current->data.songID << " - " << current->data.songName << endl;
            current = current->next;
        }
    }
};

int main()
{
    CircularList playlist;
    playlist.addSong(1, "Song 1");
    playlist.addSong(2, "Song 2");
    playlist.addSong(3, "Song 3");

    playlist.playNextSong();
    playlist.playNextSong();
    playlist.playNextSong();
    playlist.playNextSong();
    playlist.playNextSong();

    playlist.displayPlaylist();

    return 0;
=======
#include <iostream>

using namespace std;

struct Song
{
    int songID;
    string songName;

    Song() {}
    Song(int id, string name)
    {
        songID = id;
        songName = name;
    }
};

class CircularList
{
private:
    class Node
    {
    public:
        Song data;
        Node *next;
    };
    Node *head;
    Node *tail;
    Node *currentSong;
    int size;

public:
    CircularList()
    {
        head = nullptr;
        tail = nullptr;
        currentSong = nullptr;
        size = 0;
    }

    // Add a song to the playlist
    void addSong(int songID, string songName)
    {
        Node *newNode = new Node;
        newNode->data = Song(songID, songName);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            newNode->next = head;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            newNode->next = head;
        }
        currentSong = newNode;
        size++;
    }

    // Remove a song from the playlist
    void removeSong(int songID)
    {
        if (head == nullptr)
        {
            cout << "Playlist is empty!";
            return;
        }

        Node *current = head;
        Node *temp = head;
        do
        {
            if (current->data.songID == songID)
            {
                if (current == head && tail == head)
                {
                    head = nullptr;
                    tail = nullptr;
                    delete current;
                }
                else if (current == head)
                {
                    head = head->next;
                    delete current;
                }
                else if (current == tail)
                {
                    tail = temp;
                    tail->next = head;
                    delete current;
                }
                else
                {
                    temp->next = current->next;
                    delete current;
                }

                size--;
                return;
            }
            temp = current;
            current = current->next;
        } while (current != head);
    }

    // Play the next song
    void playNextSong()
    {
        if (head == nullptr)
        {
            cout << "Playlist is empty!";
            return;
        }

        if (currentSong == nullptr)
        {
            currentSong = head;
            return;
        }

        currentSong = currentSong->next;
        cout << "Currently Playing: " << currentSong->data.songName << endl;
    }

    // Print the songs in the playlist
    void displayPlaylist()
    {
        cout << "Playlist Size: " << size << endl;
        Node *current = head;
        for (int i = 0; i < size; i++)
        {
            cout << current->data.songID << " - " << current->data.songName << endl;
            current = current->next;
        }
    }
};

int main()
{
    CircularList playlist;
    playlist.addSong(1, "Song 1");
    playlist.addSong(2, "Song 2");
    playlist.addSong(3, "Song 3");

    playlist.playNextSong();
    playlist.playNextSong();
    playlist.playNextSong();
    playlist.playNextSong();
    playlist.playNextSong();

    playlist.displayPlaylist();

    return 0;
>>>>>>> 024ee8a402256c42f9642b2e0d96e8cae3b9e0c5
}