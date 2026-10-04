#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Component
class FileSystem
{
public:
    virtual ~FileSystem() = default;
    virtual void showDetails(int indent = 0) = 0;
};

// Leaf
class File : public FileSystem
{
private:
    string name;

public:
    File(string n) : name(n) {}
    void showDetails(int indent = 0) override
    {
        for (int i = 0; i < indent; i++)
            cout << "  ";
        cout << "- File: " << name << endl;
    }
};

// Composite
class Directory : public FileSystem
{
private:
    string name;
    vector<FileSystem *> children;

public:
    Directory(string n) : name(n) {}
    void add(FileSystem *f) { children.push_back(f); }

    void showDetails(int indent = 0) override
    {
        for (int i = 0; i < indent; i++)
            cout << "  ";
        cout << "+ Directory: " << name << endl;
        for (auto child : children)
        {
            child->showDetails(indent + 1);
        }
    }
};

int main()
{
    Directory root("root");
    File file1("data.txt");
    Directory subDir("images");
    File file2("pic.png");

    subDir.add(&file2);
    root.add(&file1);
    root.add(&subDir);

    root.showDetails();
    return 0;
}
