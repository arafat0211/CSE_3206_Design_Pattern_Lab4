#include <iostream>
using namespace std;

// Target
class USBTypeC {
public:
    virtual void plugInTypeC() = 0;
    virtual ~USBTypeC() {}
};

// Adaptee
class MicroUSB {
public:
    void plugInMicro() {
        cout << "MicroUSB connected." << endl;
    }
};

// Adapter
class USBAdapter : public USBTypeC {
private:
    MicroUSB* microUSB;

public:
    USBAdapter(MicroUSB* m) {
        microUSB = m;
    }

    void plugInTypeC() override {
        cout << "Adapter converting Type-C to MicroUSB..." << endl;
        microUSB->plugInMicro();
    }
};

// Client
int main() {

    MicroUSB oldPhone;

    USBAdapter adapter(&oldPhone);

    adapter.plugInTypeC();

    return 0;
}