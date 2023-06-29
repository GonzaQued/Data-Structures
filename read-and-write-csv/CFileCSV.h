//
// Created by zqued on 29/06/2023.
//

#ifndef __CFILE__CSV_H__
#define __CFILE__CSV_H__

#include <iostream>
#include <functional>
#include <vector>

//para manipulaci�n de archivos.
#include <fstream>
//para manipulaci�n de cadenas
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

//implementaci�n de clase CSVRow.
class CSVRow {

public:
    //atributos de clase CSVRow.
    vector<string> row;

    //m�todos de clase CSVRow.
    string& operator[](size_t index) {  //sobrecargando operador "[]".
        return row.at(index);
    }
    size_t size() const {  //retornando valor del tam. del vector "row".
        return row.size();
    }
};

//implementaci�n de clase CFileCSV.
class CFileCSV {

private:

    //m�todos PRIVADOS.
    vector<string> split(const string& line, char separator) { //para dividir l�nea de texto en campos separados por "separator".

        //para almacenar palabras de cada l�nea.
        vector<string>words;
        //para almacenar palabra temporalmente en la lectura.
        string word;
        //objeto para manipular l�nea le�a.
        istringstream wordStream(line);

        //obteniendo lectura de cada l�nea csv.
        //mientras se pueda extraer l�neas del objeto wordStream.
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
    //m�todos P�BLICOS.
    vector<CSVRow> loadCSV() { //para cargar desde un csv.

        vector<CSVRow> rows;
        //creando objeto con referencia al archivo  manipular.
        fstream file(address, ios::in);

        //verificando si hubo error en carga de archivo.
        if (!file.is_open()) {
            //cerr: usado espec�ficamente para mostrar mensaje de error.
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
