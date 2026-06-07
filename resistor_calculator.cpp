#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
    // Resistor color codes
    string colors[] = {"Black", "Brown", "Red", "Orange", "Yellow", "Green", "Blue", "Violet", "Grey", "White"};
    int values[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    int choice;
    cout << "===== RESISTOR COLOR CODE CALCULATOR =====" << endl;
    
    while (true) {
        cout << "\n1. Convert Color to Value" << endl;
        cout << "2. Convert Value to Color" << endl;
        cout << "3. View Color Chart" << endl;
        cout << "4. Save Resistor Info to File" << endl;
        cout << "5. Exit" << endl;
        cout << "Choose option: ";
        cin >> choice;
        cin.ignore();
        
        if (choice == 1) {
            cout << "\nEnter resistor color (e.g., Brown): ";
            string color;
            getline(cin, color);
            
            bool found = false;
            for (int i = 0; i < 10; i++) {
                if (colors[i] == color) {
                    cout << "Color " << color << " = Value: " << values[i] << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Color not found. Please check spelling." << endl;
            }
        }
        
        else if (choice == 2) {
            cout << "\nEnter resistor value (0-9): ";
            int val;
            cin >> val;
            cin.ignore();
            
            if (val >= 0 && val <= 9) {
                cout << "Value " << val << " = Color: " << colors[val] << endl;
            } else {
                cout << "Invalid value. Enter between 0-9." << endl;
            }
        }
        
        else if (choice == 3) {
            cout << "\n--- COLOR CODE CHART ---" << endl;
            cout << "Value | Color" << endl;
            cout << "------|----------" << endl;
            for (int i = 0; i < 10; i++) {
                cout << "  " << values[i] << "   | " << colors[i] << endl;
            }
        }
        
        else if (choice == 4) {
            ofstream file("resistor_info.txt");
            file << "===== RESISTOR COLOR CODE REFERENCE =====" << endl;
            file << "Value | Color\n";
            file << "------|----------\n";
            for (int i = 0; i < 10; i++) {
                file << "  " << values[i] << "   | " << colors[i] << "\n";
            }
            file.close();
            cout << "Information saved to 'resistor_info.txt'" << endl;
        }
        
        else if (choice == 5) {
            cout << "Goodbye!" << endl;
            break;
        }
        
        else {
            cout << "Invalid option. Try again." << endl;
        }
    }
    
    return 0;
}
