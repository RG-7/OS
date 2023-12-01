#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


void FIFO(int pages[], int n, int f) {
    int frame[f];
    int pf = 0, tf = 0;
    memset(frame, -1, sizeof(frame));
    for (int i = 0; i < n; i++) {
        if (find(frame, frame + f, pages[i]) == frame + f) {
            frame[tf % f] = pages[i];
            tf++;
            pf++;
        }
    }
    cout << "FIFO Page Faults = " << pf << "\n";
}

void LRU(int pages[], int n, int f) {
    int frame[f];
    int pf = 0, tf = 0;
    memset(frame, -1, sizeof(frame));
    for (int i = 0; i < n; i++) {
        if (find(frame, frame + f, pages[i]) == frame + f) {
            int pos = -1;
            for (int j = 0; j < f; j++)
                if (frame[j] == -1)
                    pos = j;
            frame[pos] = pages[i];
            pf++;
        } else {
            int pos = find(frame, frame + f, pages[i]) - frame;
            for (int j = pos; j > 0; j--)
                frame[j] = frame[j - 1];
            frame[0] = pages[i];
        }
    }
    cout << "LRU Page Faults = " << pf << "\n";
}

void OPT(int pages[], int n, int f) {
    int frame[f];
    int pf = 0, tf = 0;
    memset(frame, -1, sizeof(frame));
    int f_pos[n], count = 0;
    for (int i = 0; i < n; i++) {
        int pos = -1;
        for (int j = 0; j < f; j++)
            if (frame[j] == pages[i])
                pos = j;
        if (pos == -1) {
            for (int j = 0; j < f; j++)
                if (frame[j] == -1)
                    pos = j;
            frame[pos] = pages[i];
            pf++;
        }
        f_pos[i] = pos;
    }
    cout << "OPT Page Faults = " << pf << "\n";
}

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int n = sizeof(pages) / sizeof(pages[0]);
    int f = 3;
    FIFO(pages, n, f);
    LRU(pages, n, f);
    OPT(pages, n, f);

    return 0;
}