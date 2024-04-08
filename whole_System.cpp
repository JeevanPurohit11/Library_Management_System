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
// Deriving class Book from Class Item
class Book : public Item
{
public:
    int numOfPages;
    int numOfCopies;
    string publisher;

    // Default constructor
    Book(string title = "", string author = "", string genre = "", string isbn_identifier = "", int numOfPages = 0, int numOfCopies = 0, string publisher = "") : Item(title, author, genre, isbn_identifier)
    {
        this->numOfPages = numOfPages;
        this->numOfCopies = numOfCopies;
        this->publisher = publisher;
    }
};

class User;
class Admin
{
private:
    // This maps the book title with the other attributes
    unordered_map<string, Book> books;
    // This maps the name of student to the book which he/she has issued.
    unordered_map<string, string> userRecord;

public:
    friend void searchBook(User &obj1, Admin &obj2);  // friend function to search any book used by both user and admin.
    friend void issueBook(User &obj1, Admin &obj2);   // friend function to issue any book by user and to make entry to admin about it.
    friend void returnBook(User &obj1, Admin &obj2);  // friend function to return any book by user and to make entry to admin about it.
    friend void displayBook(User &obj1, Admin &obj2); // friend function to display all the books.

    void bookStock();   // This function indicates the total books available in the library
    void userdetails(); // This function gives the details of which user has issued which book.

    // This function is for the admin to add new books to the Library
    void addBook()
    {
        string title_of_book;
        string author_of_book;
        string genre_of_book;
        string isbn_of_book;
        int pages_in_book;
        int copies_of_book;
        string publisher_of_book;

        cout << "Enter Title of Book: ";
        cin.ignore();
        getline(cin, title_of_book);
        cout << "Enter Author of Book: ";
        getline(cin, author_of_book);
        cout << "Enter Genre of Book: ";
        getline(cin, genre_of_book);
        cout << "Enter ISBN of Book: ";
        getline(cin, isbn_of_book);
        cout << "Enter Number of Pages in Book: ";
        cin >> pages_in_book;
        cout << "Enter total number of copies of Book: ";
        cin >> copies_of_book;

        cin.ignore();

        cout << "Enter Publisher of book: ";
        getline(cin, publisher_of_book);
        Book obj(title_of_book, author_of_book, genre_of_book, isbn_of_book, pages_in_book, copies_of_book, publisher_of_book);
        // inserting the book into unordered map
        books[title_of_book] = obj;
        cout << "Book added to Library Successfully.\n";
    }

  // This funciton is for admin to remove books from the Library
    void removeBook()
    {
        string title_of_book;
        cin.ignore();
        getline(cin, title_of_book);
        auto it = books.find(title_of_book);
        // finding the book into the unordered map using iterator and erasing it if found.
        if (it != books.end())
        {
            books.erase(it);
            cout << "Book removed from Library Successfully.\n";
        }
        else
        {
            cout << "There does not exist any book with bookname " << title_of_book << endl;
        }
    }
};

class User
{
public:
    friend class Admin;                               // Admin class can access userRecord.
    friend void searchBook(User &obj1, Admin &obj2);  // friend function to search any book used by both user and admin.
    friend void issueBook(User &obj1, Admin &obj2);   // friend function to issue any book by user and to make entry to admin about it.
    friend void returnBook(User &obj1, Admin &obj2);  // friend function to return any book by user and to make entry to admin about it.
    friend void displayBook(User &obj1, Admin &obj2); // friend function to display all the books.
};

void Admin::bookStock()
{
    // Made a vector of class Book to add some books into the library.
    vector<Book> booksToAdd;

    booksToAdd.push_back(Book("The Great Gatsby", "F. Scott Fitzgerald", "Fiction", "ISBN123", 320, 5, "Penguin Books"));
    booksToAdd.push_back(Book("1984", "George Orwell", "Science Fiction", "ISBN012", 328, 5, "Penguin Books"));
    booksToAdd.push_back(Book("The Hobbit", "J.R.R. Tolkien", "Fantasy", "ISBN901", 310, 4, "Allen & Unwin"));
    booksToAdd.push_back(Book("The Lord of the Rings", "J.R.R. Tolkien", "Fantasy", "ISBN234", 1178, 2, "Allen & Unwin"));
    booksToAdd.push_back(Book("The Hunger Games", "Suzanne Collins", "Young Adult", "ISBN890", 374, 7, "Scholastic"));
    booksToAdd.push_back(Book("Brave New World", "Aldous Huxley", "Science Fiction", "ISBN5678", 311, 3, "Chatto & Windus"));
    booksToAdd.push_back(Book("The Alchemist", "Paulo Coelho", "Fiction", "ISBN9012", 208, 2, "HarperOne"));
    booksToAdd.push_back(Book("Moby-Dick", "Herman Melville", "Classic", "ISBN3456", 585, 4, "Richard Bentley"));
    booksToAdd.push_back(Book("The Kite Runner", "Khaled Hosseini", "Fiction", "ISBN7890", 371, 1, "Riverhead Books"));
    booksToAdd.push_back(Book("The Great Expectations", "Charles Dickens", "Classic", "ISBN0123", 544, 1, "Chapman & Hall"));
    booksToAdd.push_back(Book("The Odyssey", "Homer", "Epic Poetry", "ISBN4567", 442, 1, "Chapman & Hall"));

    for (auto &itr : booksToAdd)
    {
        books[itr.title] = itr;
    }
}
