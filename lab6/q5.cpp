#include <iostream>
#include <ctime>

using namespace std;

struct Song
{
    string name;
    string artist;
    int duration;

    Song()
    {
        name = "";
        artist = "";
        duration = 0;
    }

    Song(string name, string artist, int duration)
    {
        this->name = name;
        this->artist = artist;
        this->duration = duration;
    }
};

class DoublyList
{
private:
    struct Node
    {
        Song data;
        Node *next;
        Node *prev;
    };
    Node *head;
    Node *tail;
    Node *current;
    bool loop;

public:
    DoublyList()
    {
        head = nullptr;
        tail = nullptr;
        current = nullptr;
        loop = false;
    }

    // Adds a new song in the list
    void addSong(Song song)
    {
        Node *newNode = new Node;
        newNode->data = song;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }

        cout << song.name << " added to the playlist!" << endl;
    }

    // Remove a song in the list by name
    void removeSong(string name)
    {
        if (isEmpty())
        {
            cout << "Playlist is empty!" << endl;
            return;
        }

        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data.name == name)
            {
                cout << "Removed " << temp->data.name << " from the playlist!" << endl;

                if (temp == current)
                {
                    if (current->prev != nullptr)
                        current = current->prev;
                    else
                        current = current->next;
                }
                if (temp == head)
                {
                    Node *deleted = head;
                    head = head->next;
                    head->prev = nullptr;
                    deleted->next = nullptr;
                    delete deleted;
                }
                else if (temp == tail)
                {
                    Node *deleted = tail;
                    tail = tail->prev;
                    tail->next = nullptr;
                    deleted->prev = nullptr;
                    delete deleted;
                }
                else
                {
                    Node *deleted = temp;
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    delete deleted;
                }

                return;
            }
            temp = temp->next;
        }
    }

    // Plays the next song in the list
    void playNext()
    {
        if (current == nullptr)
            current = head;
        else
        {
            if (current->next != nullptr)
                current = current->next;
            else
            {
                if (loop)
                    current = head;
                else
                {
                    cout << endl
                         << "No more songs in the playlist!" << endl;
                    return;
                }
            }
        }

        cout << endl
             << "Playing next song!" << endl;
        displayCurrentSong();
    }

    // Plays the previous song in the list
    void playPrevious()
    {
        if (current == nullptr)
            current = head;
        else
        {
            if (current->prev != nullptr)
                current = current->prev;
            else
            {
                if (loop)
                    current = tail;
                else
                {
                    cout << endl
                         << "No more songs in the playlist!" << endl;
                    return;
                }
            }
        }

        cout << "Playing previous song!" << endl;
        displayCurrentSong();
    }

    // Display the current song
    void displayCurrentSong()
    {
        if (current != nullptr)
            cout << endl
                 << "--------------------------------" << endl
                 << "Currently Playing:" << endl
                 << "Song: " << current->data.name << endl
                 << "Artist: " << current->data.artist << endl
                 << "Duration: " << current->data.duration << endl
                 << "--------------------------------" << endl;
        else
            cout
                << "--------------------------------" << endl
                << "No song in the playlist!" << endl
                << "--------------------------------" << endl;
    }

    // Shuffles the list
    void shufflePlaylist()
    {
        if (isEmpty())
        {
            cout << "Playlist is empty!" << endl;
            return;
        }
        srand(time(nullptr));

        int count = 0;
        Node *temp = head;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }

        for (int i = 0; i < count; i++)
        {
            int randIndex1 = rand() % count;
            int randIndex2 = rand() % count;

            Node *temp1 = head;
            Node *temp2 = head;

            for (int j = 0; j < randIndex1; j++)
                temp1 = temp1->next;
            for (int j = 0; j < randIndex2; j++)
                temp2 = temp2->next;

            Song tempData = temp1->data;
            temp1->data = temp2->data;
            temp2->data = tempData;
        }

        cout << endl
             << "Playlist Shuffled!" << endl;

        current = head;
        displayCurrentSong();
    }

    // Replays the current song
    void replayCurrent()
    {
        cout << "Replaying the current song!" << endl;
        displayCurrentSong();
    }

    // Toggles loop the playlist
    void loopPlaylist()
    {
        loop = !loop;

        if (loop)
            cout << "Playlist is now looping!" << endl;
        else
            cout << "Playlist is no longer looping!" << endl;
    }

    // Returns if the list is empty
    bool isEmpty()
    {
        return head == nullptr;
    }

    // Prints all the songs in the list
    void print()
    {
        if (isEmpty())
        {
            cout << "The playlist is empty!" << endl;
            return;
        }

        Node *current = head;
        cout << endl
             << "Songs in the playlist: " << endl
             << "--------------------------------" << endl;
        while (current != nullptr)
        {
            cout << endl
                 << "Song: " << current->data.name << endl
                 << "Artist: " << current->data.artist << endl
                 << "Duration: " << current->data.duration << endl;
            current = current->next;
        }
        cout << "--------------------------------" << endl;

        cout << endl;
    }
};

int main()
{
    DoublyList playlist;

    playlist.addSong(Song("Tu Hai Kahan", "AUR", 5));
    playlist.addSong(Song("Siyah", "Abdul Hannan, BAIG", 5));
    playlist.addSong(Song("Chal Diye Tum Kahan", "AUR", 5));
    playlist.addSong(Song("Gul", "Anuv Jain", 5));
    playlist.addSong(Song("Faasle", "Aditya Rikhari", 5));
    playlist.addSong(Song("Tere Sang Yara", "Atif Aslam", 5));
    playlist.addSong(Song("Tum Hi Ho", "Arijit Singh", 5));

    playlist.playNext();
    playlist.replayCurrent();

    playlist.shufflePlaylist();
    playlist.playNext();
    playlist.playPrevious();
    playlist.playPrevious();
    playlist.playPrevious();

    playlist.loopPlaylist();
    playlist.playPrevious();
    playlist.playPrevious();

    return 0;
}