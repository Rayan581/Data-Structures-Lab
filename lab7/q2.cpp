#include <iostream>

using namespace std;

// Implementing browser history using doubly circular linked list
class BrowserHistory
{
private:
    class Node
    {
    public:
        string url;
        Node *next;
        Node *prev;
    };
    Node *head;
    Node *tail;
    Node *currentUrl;

public:
    BrowserHistory()
    {
        head = nullptr;
        tail = nullptr;
        currentUrl = nullptr;
    }

    // Visit a new url
    void visitNewSite(string url)
    {
        Node *newNode = new Node();
        newNode->url = url;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            currentUrl = newNode;

            newNode->next = newNode;
            newNode->prev = newNode;
        }
        else
        {
            newNode->prev = currentUrl;
            newNode->next = currentUrl->next;
            currentUrl->next->prev = newNode;
            currentUrl->next = newNode;
            if (currentUrl == tail)
                tail = newNode;
        }
        currentUrl = newNode;
    }

    // Go back in history
    void goBack()
    {
        currentUrl = currentUrl->prev;
        cout << currentUrl->url << endl;
    }

    void goForward()
    {
        currentUrl = currentUrl->next;
        cout << currentUrl->url << endl;
    }

    // Print the browser history
    void displayHistory()
    {
        Node *temp = head;
        do
        {
            cout << temp->url << " <-> ";
            temp = temp->next;
        } while (temp != head);
        cout << head->url;
        cout << endl;
    }
};

int main()
{
    BrowserHistory history;

    history.visitNewSite("google.com");
    history.visitNewSite("stackoverflow.com");
    history.visitNewSite("github.com");
    history.visitNewSite("reddit.com");
    history.visitNewSite("medium.com");
    history.goBack();
    history.goBack();
    history.visitNewSite("news.com");
    history.goForward();

    history.displayHistory();
    return 0;
}