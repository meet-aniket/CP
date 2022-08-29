#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;


class TrieNode {

  public:
    char data;
    TrieNode* children[ALPHABET_SIZE];
    bool isTerminal;

    TrieNode(char ch) {
      data = ch;
      for(int i=0; i < ALPHABET_SIZE; i++) {
        children[i] = NULL;
      }
      isTerminal = false;
    }
};

class Trie {

  public:
    TrieNode* root;

    Trie() {
      root = new TrieNode('\0');
    }

    // Insert Function
    void insertUtil(TrieNode* root, string word) {
      // base case
      if(word.length() == 0) {
        root->isTerminal = true;
        return;
      }

      // assumption, word will be in caps
      int index = word[0]-'A';
      TrieNode* child;

      // present 
      if(root->children[index] != NULL) {
        child = root->children[index];
      } else {
        // absent
        child = new TrieNode(word[index]);
        root->children[index] = child;
      }

      //RECURSION
      insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
      insertUtil(root, word);
    }

    // Search Function
    bool searchUtil(TrieNode* root, string word) {
      if(word.length() == 0) {
        return root->isTerminal;
      }

      int index = word[0]-'A';
      TrieNode* child;

      //present
      if(root->children[index] != NULL) {
        child = root->children[index];
      } else {
        // absent
        return false;
      }

      //RECURSION
      return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word) {
      return searchUtil(root, word);
    }
};

int main() {

  Trie* t = new Trie();
  t->insertWord("ARM");
  t->insertWord("DO");
  t->insertWord("TIME");
  t->insertWord("DOG");

  cout << "Present or not: " << t->searchWord("DO") << "\0";

  return 0;
}