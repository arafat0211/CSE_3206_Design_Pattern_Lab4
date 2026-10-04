#include <iostream>
#include <string>
using namespace std;

// Implementor
class Display {
public:
	virtual ~Display() = default;
	virtual void render(const string& text) = 0;
};

// Concrete Implementor A
class ConsoleDisplay : public Display {
public:
	void render(const string& text) override {
    	cout << "[Console] " << text << endl;
	}
};

// Concrete Implementor B
class HtmlDisplay : public Display {
public:
	void render(const string& text) override {
    	cout << "<p>" << text << "</p>" << endl;
	}
};

// Abstraction (holds the bridge to the implementor)
class FileViewer {
protected:
	Display* display;   // the "bridge"
public:
	FileViewer(Display* d) : display(d) {}
	virtual ~FileViewer() = default;
	virtual void show(const string& name) = 0;
};

// Refined Abstraction A
class SimpleViewer : public FileViewer {
public:
	SimpleViewer(Display* d) : FileViewer(d) {}
	void show(const string& name) override {
    	display->render("File: " + name);
	}
};

// Refined Abstraction B
class DetailedViewer : public FileViewer {
private:
	int sizeKB;
public:
	DetailedViewer(Display* d, int size) : FileViewer(d), sizeKB(size) {}
	void show(const string& name) override {
    	display->render("File: " + name + " | Size: " + to_string(sizeKB) + " KB");
	}
};

int main() {
	ConsoleDisplay console;
	HtmlDisplay html;

	SimpleViewer v1(&console);
	SimpleViewer v2(&html);
	DetailedViewer v3(&console, 120);
	DetailedViewer v4(&html, 250);

	v1.show("data.txt");
	v2.show("data.txt");
	v3.show("pic.png");
	v4.show("pic.png");
	return 0;
}