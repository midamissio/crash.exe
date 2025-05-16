#include <iostream>
#include <fstream>
#include <cstdlib>
#include <windows.h>
#include <shlobj.h> 

int main() {
    // Pobranie ścieżki do pulpitu
    char desktopPath[MAX_PATH];
    if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_DESKTOPDIRECTORY, NULL, 0, desktopPath))) {
        std::string filePath = std::string(desktopPath) + "\\Get Shutdown'ed.txt";

        // Tworzenie pliku i wpisanie "Hehe"
        std::ofstream outFile(filePath);
        if (outFile.is_open()) {
            outFile << "Hehe";
            outFile.close();
            std::cout << "Plik utworzony na pulpicie.\n";
        } else {
            std::cerr << "Nie udało się utworzyć pliku.\n";
        }
    } else {
        std::cerr << "Nie udało się pobrać ścieżki pulpitu.\n";
    }

    // Restart komputera
    std::cout << "Get shutdown'ed";
    system("shutdown /r /t 10");

    return 0;
}
