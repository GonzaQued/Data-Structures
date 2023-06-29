//
// Created by Gonzalo Quedena on 29/06/2023.
//

#ifndef __CFILE__CSV_H__
#define __CFILE__CSV_H__

#include <iostream>
#include <functional>
#include <vector>

//para manipulación de archivos.
#include <fstream>
//para manipulación de cadenas
#include <sstream>

using std::endl;
using std::vector;

using std::string;
using std::getline;
using std::istringstream;

using std::ios;
using std::cerr;
using std::fstream;

using std::function;

//implementación de clase CSVRow.
class CSVRow {

public:
    //atributos de clase CSVRow.
    vector<string> row;

    //métodos de clase CSVRow.
    string& operator[](size_t index) {  //sobrecargando operador "[]".
        return row.at(index);
    }
    size_t size() const {  //retornando valor del tam. del vector "row".
        return row.size();
    }
};

//implementación de clase CFileCSV.
class CFileCSV {

private:

    //métodos PRIVADOS.
    vector<string> split(const string& line, char separator) { //para dividir línea de texto en campos separados por "separator".

        //para almacenar palabras de cada línea.
        vector<string>words;
        //para almacenar palabra temporalmente en la lectura.
        string word;
        //objeto para manipular línea leía.
        istringstream wordStream(line);

        //obteniendo lectura de cada línea csv.
        //mientras se pueda extraer líneas del objeto wordStream.
        while (getline(wordStream, word, separator)) {
            words.push_back(word);
        }

        return words;
    }

public:
    //constructor de clase CFileCSV.
    CFileCSV(const string& address="")
        : address(address) {
    }
    //métodos PÚBLICOS.
    vector<CSVRow> loadCSV() { //para cargar desde un csv.

        vector<CSVRow> rows;
        //creando objeto con referencia al archivo  manipular.
        fstream file(address, ios::in);

        //verificando si hubo error en carga de archivo.
        if (!file.is_open()) {
            //cerr: usado específicamente para mostrar mensaje de error.
            cerr << "ERROR AL ABRIR ARCHIVO: " << address << endl;
        }
        else {
            //var. para obtener linea de texto.
            string line;
            //recorriendo cada linea del archivo "filename".
            while (getline(file, line)) {

                CSVRow row;
                row.row = split(line, ',');

                rows.push_back(row);
            }
        }

        file.close();
        return rows;
    }

private:
    string address;
};



#endif //__CFILE__CSV_H__
