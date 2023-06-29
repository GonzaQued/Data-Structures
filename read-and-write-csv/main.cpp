#include <iostream>
#include <filesystem>

#include "CFileCSV.h"

using std::cout;

//creando alias para "std::filesystem"
namespace fs = std::filesystem;

string getPathFromCSV(string csvName) {
    //obteniendo ruta absoluta del directorio actual.
    fs::path currentPath = fs::current_path();
    //concatenando ruta absoluta con la ruta relativa(vuelos.csv).
    fs::path filePath = currentPath / csvName;
    //obteniendo ruta absoluta FINAL como string.
    string absolutePath = filePath.string();

    return absolutePath;
}

vector<CSVRow> loadCSV() {
    string csvPath = getPathFromCSV("vuelos.csv");

    //creando ref. a instancia de "CFileCSV"
    CFileCSV myFile(csvPath);

    return myFile.loadCSV();
}

int main() {

    vector<CSVRow> data = loadCSV();

    //imprimiendo datos cargados.
    for (CSVRow& row : data) {
        for (size_t i = 0; i < row.size(); ++i) {
            cout << row[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
