#include "SystemManager.h"

#include <chrono>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <thread>

using namespace std;

int main() {

#ifdef _DEBUG
    onexit(_CrtDumpMemoryLeaks);
#endif
    
    const static string& devices_file = "C:\\Users\\tomgr\\OneDrive - Sheffield Hallam University\\Documents\\modules\\C, C++\\year 2\\coursework\\coursework - y2s1\\DEVICES.txt";
    SystemManager::getSystemManager()->loadDevicesFromFile(devices_file);
    SystemManager::getSystemManager()->displayAll();

    string menuChoiceStr, displayDeviceChoice, type, name;
    static int menuDelay = 1;
    int menuChoiceInt, settingChoice;
    Device* displayDevice;

    do {
        this_thread::sleep_for(chrono::seconds(menuDelay));
        cout << "\n[device name]: Perform that device's one-click action\n" <<
            "1: List devices\n" <<
            "2 : Sort by name\n" <<
            "3 : Sort by device type (by name as secondary order)\n" <<
            "4 : Select device to interact with it's full feature set\n" <<
            "5 : Add device\n" <<
            "6 : Settings & help\n" <<
            "9 : Exit" << endl;
        cout << "Select a function: " << endl;

        getline(cin, menuChoiceStr);

        istringstream inttest(menuChoiceStr);
        if (inttest >> menuChoiceInt) {
            //its an integer

            switch (menuChoiceInt) {
            case 1:
                // list all
                SystemManager::getSystemManager()->displayAll();
                break;

            case 2:
                // sort name using <algorithms>
                SystemManager::getSystemManager()->sortDevicesByName();
                break;

            case 3:
                // sort type
                SystemManager::getSystemManager()->sortDevicesByType();
                break;

            case 4:
                // see all a devices actions
                cout << "select a device:" << endl;
                SystemManager::getSystemManager()->quickList();

                cin >> displayDeviceChoice;
                displayDevice = SystemManager::getSystemManager()->findDeviceByName(displayDeviceChoice);

                if (displayDevice != nullptr) {                 //if find not null
                    cout << "\nSelect an option to adjust setting: " << endl; // enter setting, go to edit (set) function
                    displayDevice->editProperty();

                }
                break;

            case 5:
                //take user input and pass to sys mgr function addDevice
                cout << "Enter device type: ";
                cin >> type;

                cout << "Enter device name: ";
                getline(cin, name);
                cin >> name;
                SystemManager::getSystemManager()->addDevice(type, name);
                cin.clear();

                break;

            case 6:
                cout << "1 - view device types \n2 - toggle menu load delay \n3- delete a device" << endl;
                cin >> settingChoice;
                if (settingChoice == 1) {
                    cout << "Devices and their functions: \n"
                        << "Light(on / off, adjust brightness, sleep timer) \n"
                        << "Temperature & Humidity Sensor(live and historic data) \n"
                        << "Speaker(volume, play / stop) \n"
                        << "Heating Thermostat(on / off, schedule, heating boost) \n"
                        << "Socket / Plugs(on / off, schedule, sleep timer, live and historic energy usage) \n"
                        << "Radiator valve(on / off, current temperature, schedule) \n" << endl;
                }
                else if(settingChoice == 2){
                       if (menuDelay == 1) menuDelay = 0;
                       else menuDelay = 1;

                       cout << "Menu delay turned " << ((menuDelay == 1) ? "on" : "off") << endl;
                }
                else if(settingChoice == 3){
                    //delete device

                }
                cin.clear(); cin.ignore();
                break;
                    
            case 9:
                SystemManager::getSystemManager()->saveDevicesToFile(devices_file);
                cout << "\nExiting and saving data..." << endl;
                break;

            default:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
        }
        else {
            //its a string
            //devices one click action
            Device* oneClickDevice = SystemManager::getSystemManager()->findDeviceByName(menuChoiceStr);

            if (oneClickDevice != nullptr) {
                oneClickDevice->quickView();
                oneClickDevice->oneClick();
            }
            else {
                cout << "Couldn't find that device.\a" << endl;
            }
        }

    } while (menuChoiceInt != 9);

    return 0;
}
