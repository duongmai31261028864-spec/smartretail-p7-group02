#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: p7 <data_folder> [store_id] [pick_list]" << endl;
        return 1;
    }

    string dataFolder = argv[1];
    string storeId = (argc >= 3) ? argv[2] : "S001";
    string pickListStr = (argc >= 4) ? argv[3] : "P005,P001,P008";

    cout << "Data folder: " << dataFolder << endl;
    cout << "Store ID: " << storeId << endl;
    cout << "Pick list: " << pickListStr << endl;

    return 0;
}