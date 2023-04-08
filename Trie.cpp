#include <iostream>
using namespace std;

//! STRUCTURE OF A TRIENODE
class TrieNode
{
public:
    char val;
    TrieNode *children[26];
    bool isTerminal;

public:
    TrieNode(char ch)
    {
        this->val = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    //! INSERTION IN TRIE;
    void insertUtil(TrieNode *root, string word)
    {
        //* base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        //* Assuming word will be in Caps
        int index = word[0] - 'A';
        TrieNode *child;

        //*IF CHAR IS ALREADY PRESENT..
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        //*IF CHAR IS NOT PRESENT;
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        //* Recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    //! SEARCHING IN TRIE;

    bool searchUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'A';

        TrieNode *child;

        //*IF PRESENT
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        //*IF ABSENT
        else
        {
            return false;
        }

        //*RECURION
        return searchUtil(child, word.substr(1));
    }

    bool search(string word)
    {
        return searchUtil(root, word);
    }
};

int main()
{
    Trie *t = new Trie();
    t->insertWord("ARM");
    t->insertWord("DO");
    t->insertWord("TIME");
    cout << "Present or Not " << t->search("TIM") << endl;

    return 0;
}
