#include <iostream>
#include <fstream>
#include <cstdlib>
#include <windows.h>
#include <shlobj.h> 

int main() {
    char desktopPath[MAX_PATH];
    if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_DESKTOPDIRECTORY, NULL, 0, desktopPath))) {
        std::string filePath = std::string(desktopPath) + "\\Get Shutdown'ed.txt";

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

    std::cout << "Get shutdown'ed";
    system("shutdown /r /t 10");

    return 0;
}
