#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int getNumVocales(const std::string& str) {
    int cont = 0;
    string lowerStr = str;

    for (char& c : lowerStr) {
        c = tolower(c);
        if (isalpha(c)) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                cont++;
            }
        }
    }
    return cont;
}

string descodificar(const string& codificada, int desplazamiento) {
    string decodificada = "";
    int letterValue;
    char c, newLetter;

    for (size_t i = 1; i < codificada.length(); i++) {
        c = tolower(codificada[i]);

        if (isalpha(c)) {
            letterValue = c + desplazamiento;
            if (letterValue < 97) {
                letterValue = 123 - (97 - letterValue);
            }
            else if (letterValue > 122) {
                letterValue = 96 + (letterValue - 122);
            }

            newLetter = static_cast<char>(letterValue);
            if (isupper(codificada[i])) {
                newLetter = toupper(newLetter);
            }

            decodificada += newLetter;
        }
        else {
            decodificada += c;
        }
    }

    return decodificada;
}

int calcularDesplazamiento(char codigo) {
    codigo = tolower(codigo);

    int left, right;
    if (codigo < 'p') {
        left = -((codigo - 'a') + (123 - 'p'));
    }
    else {
        left = -(codigo - 'p');
    }
    if (codigo > 'p') {
        right = (('z' - codigo) + ('p' - 96));
    }
    else {
        right = ('p' - codigo);
    }

    return (abs(left) <= right) ? left : right;
}

int main() {
    bool keep = true;
    string codificada, decodificada;
    int desplazamiento, vocales;

    while (keep) {
        getline(cin, codificada);
        desplazamiento = calcularDesplazamiento(codificada[0]);

        decodificada = descodificar(codificada, desplazamiento);

        if (decodificada == "FIN") {
            keep = false;
        }
        else {
            vocales = getNumVocales(decodificada);
            cout << vocales << endl;
        }
    }

    return 0;
}
