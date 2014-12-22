#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;



int main() {
    int total_goats = 0, total_cars = 0;
    srand (time(NULL));
    for (int i = 0; i < 1000000; i++) {
        int rand_num = rand();
        int doors[3];
        doors[0] = rand_num++ % 3;
        doors[1] = rand_num++ % 3;
        doors[2] = rand_num++ % 3;
        int choice = rand() % 3;
        int opened = (choice + 1) % 3;
        while (doors[opened] == 2) {
            opened++;
            opened = opened % 3;
        }
        int picked = 0;
        while (picked == opened || picked == choice) {
            picked++;
            picked = picked % 3;
        }
        if (doors[picked] == 2) {
            total_cars++;
        } else {
            total_goats++;
        }        

    }
    cout << endl;
    cout << "Switching Method" << endl;
    cout << "total cars: " << total_cars << endl;
    cout << "total goats: " << total_goats << endl;
    cout << endl;
    
    total_cars = 0;
    total_goats = 0;
    for(int i = 0; i < 1000000; i++) {
        int choice = rand() % 3;
        if (choice == 2) {
            total_cars++;
        } else {
            total_goats++;
        }
    }
    cout << "Not Switching Method" << endl;
    cout << "total cars: " << total_cars << endl;
    cout << "total goats: " << total_goats << endl;
    cout << endl;
}
