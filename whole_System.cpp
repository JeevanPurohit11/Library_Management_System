#include <bits/stdc++.h>
using namespace std;

class Item
{
public:
    string title;
    string author;
    string genre;
    string isbn_identifier;

    // Default constructor for descriminate local and global variable.
    Item(string title = "", string author = "", string genre = "", string isbn_identifier = "")
    {
        this->title = title;
        this->author = author;
        this->genre = genre;
        this->isbn_identifier = isbn_identifier;
    }
};
