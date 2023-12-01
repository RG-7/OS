#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class VirtualMemory {
private:
    int frames;
    std::string reference_string;
    int faults;
    std::vector<int> memory;

public:
    VirtualMemory(int frames, std::string reference_string);
    void fifo();
    void displayMemory();
    void displayFaults();
};

VirtualMemory::VirtualMemory(int frames, std::string reference_string) {
    this->frames = frames;
    this->reference_string = reference_string;
    this->faults = 0;
    this->memory.resize(frames, -1);
}

void VirtualMemory::fifo() {
    for (char &c : reference_string) {
        int frame = -1;
        for (int i = 0; i < frames; i++) {
            if (memory[i] == c) {
                frame = i;
                break;
            }
        }
        if (frame == -1) {
            faults++;
            frame = rand() % frames;
            memory[frame] = c;
        }
    }
}

void VirtualMemory::displayMemory() {
    for (int i = 0; i < frames; i++) {
        std::cout << memory[i] << " ";
    }
    std::cout << std::endl;
}

void VirtualMemory::displayFaults() {
    std::cout << "Page Faults: " << faults << std::endl;
}

int main() {
    VirtualMemory vm(3, "ABBABBC");
    vm.fifo();
    vm.displayMemory();
    vm.displayFaults();
    return 0;
}