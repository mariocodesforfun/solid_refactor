#include <iostream>

// create a base class for the input devices
// then children classes for the keyboard and mouse


class InputDevice {
public:
    virtual std::string getInput() = 0;
    
    virtual ~InputDevice() {}
};

class Keyboard : public InputDevice {
public:
    std::string getInput() {
        return "User input from keyboard";
    }
};

class Mouse : public InputDevice {
public:
    std::string getInput() {
        return "User input from mouse";
    }
};

// Right now this code assumes that input will come from the keyboard, 
// but we would like to be able to create an InputProcessor that 
// accepts input from the mouse (and potentially other input devices
// in the future). Note that each InputProcessor only needs to deal
// with one device.
class InputProcessor {
private:
    InputDevice& device;
    
public:
    InputProcessor(InputDevice& inputDevice) : device(inputDevice) {
    }
    
    void processInput() {
        std::string input = device.getInput();
        std::cout << "Processing: " << input << std::endl;
    }
};

// For demonstration
int main() {
    Keyboard keyboard;
    Mouse mouse;
    
    InputProcessor keyboardProcessor(keyboard);
    InputProcessor mouseProcessor(mouse);
    
    keyboardProcessor.processInput();
    mouseProcessor.processInput();
}
