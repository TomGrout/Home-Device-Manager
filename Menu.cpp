#include "SystemManager.h"

#include <chrono>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <thread>

using namespace std;

const static string& devices_file = "C:\\Users\\tomgr\\OneDrive - Sheffield Hallam University\\Documents\\modules\\C, C++\\year 2\\coursework\\coursework - y2s1\\DEVICES.txt";
static int menuDelay = 1;


class Menu {
private:

public:

    void displayAll() {                    // list all
        SystemManager::getSystemManager()->displayAll();
    }
    void sortDevicesByName() {                    // sort name using <algorithms>
        SystemManager::getSystemManager()->sortDevicesByName();
    }

    void sortDevicesByType() {                    // sort type
        SystemManager::getSystemManager()->sortDevicesByType();
    }

    void quickList() {
        // see all a devices actions

        string displayDeviceChoice;
        Device* displayDevice;

        cout << "select a device:" << endl;
        SystemManager::getSystemManager()->quickList();

        cin >> displayDeviceChoice;
        displayDevice = SystemManager::getSystemManager()->findDeviceByName(displayDeviceChoice);

        if (displayDevice != nullptr) {                 //if find not null
            cout << "\nSelect an option to adjust setting: " << endl; // enter setting, go to edit (set) function
            displayDevice->editProperty();

        }
        cin.clear(); cin.ignore();
    }

    void addDevice() {
        //take user input and pass to sys mgr function addDevice

        string name, type;
        cout << "Enter device type: ";
        cin >> type;
        cout << "Enter device name: ";
        cin >> name;

        SystemManager::getSystemManager()->addDevice(type, name);
        cin.clear(); cin.ignore();
    }

    void settingsHelp() {
        int settingChoice;
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
        else if (settingChoice == 2) {
            if (menuDelay == 1) menuDelay = 0;
            else menuDelay = 1;

            cout << "Menu delay turned " << ((menuDelay == 1) ? "on" : "off") << endl;
        }
        else if (settingChoice == 3) {
            //delete device
            SystemManager::getSystemManager()->deleteSpecificDevice();
        }
        cin.clear(); cin.ignore();
    }
    void saveDevicesToFile() {
        SystemManager::getSystemManager()->saveDevicesToFile(devices_file);
        cout << "\nExiting and saving data..." << endl;
    }

};

void filestuff() {
    cout << "file";
}

int main() {

    //#ifdef _DEBUG
    //    onexit(_CrtDumpMemoryLeaks);
    //#endif

    auto SysMgr = SystemManager::getSystemManager();

    SysMgr->loadDevicesFromFile(devices_file);
    SysMgr->displayAll();

    string menuChoiceStr;
    int menuChoiceInt;

    void (Menu:: * options[7])() = { &Menu::displayAll, &Menu::sortDevicesByName, &Menu::sortDevicesByType, &Menu::quickList, &Menu::addDevice, &Menu::settingsHelp, &Menu::saveDevicesToFile };


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
        unique_ptr<Menu> menu = make_unique<Menu>();

        istringstream inttest(menuChoiceStr);
        if (inttest >> menuChoiceInt) {
            //its an integer

            if (menuChoiceInt == 9) {
                (*menu.*options[6])();
            }
            else if (menuChoiceInt > 0 && menuChoiceInt < 7) {
                (*menu.*options[menuChoiceInt - 1])();
            }
            else {
                cout << "Invalid choice. Please select a valid menu option.\n";
            }

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;

        }
        else {
            //its a string
            //devices one click action
            Device* oneClickDevice = SysMgr->findDeviceByName(menuChoiceStr);

            if (oneClickDevice != nullptr) {
                oneClickDevice->oneClick();
                oneClickDevice->quickView();
            }
            else {
                cout << "Couldn't find that device." << endl;
            }
        }

    } while (menuChoiceInt != 9);

    return 0;
}
