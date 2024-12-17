#include "PString.h"
#include <cstring> // Include le funzioni standard C: strlen, strcpy, strcmp, ecc.

// Funzione interna per allocare e copiare stringa
void PString::allocateAndCopy(const char* src) {
    if (src) {
        length = strlen(src);
        data = new char[length + 1]; // +1 per il terminatore '\0'
        strcpy(data, src);
    } else {
        length = 0;
        data = new char[1];
        data[0] = '\0';
    }
}

// Costruttore di default
PString::PString() : data(nullptr), length(0) {
    allocateAndCopy("");
}

// Costruttore con stringa C
PString::PString(const char* str) {
    allocateAndCopy(str);
}

// Costruttore di copia
PString::PString(const PString& other) {
    allocateAndCopy(other.data);
}

// Costruttore da String
PString::PString(const String& str) {
    allocateAndCopy(str.c_str());
}

// Distruttore
PString::~PString() {
    delete[] data;
}

// Operatore di assegnamento da const char*
PString& PString::operator=(const char* str) {
    if (data != str) { // Evita auto-assegnazione
        delete[] data;
        allocateAndCopy(str);
    }
    return *this;
}

// Operatore di assegnamento tra PString
PString& PString::operator=(const PString& other) {
    if (this != &other) {
        delete[] data;
        allocateAndCopy(other.data);
    }
    return *this;
}

// Operatore di assegnamento da String
PString& PString::operator=(const String& str) {
    return *this = str.c_str();
}

// Operatore == con PString
bool PString::operator==(const PString& other) const {
    return strcmp(data, other.c_str()) == 0;
}

bool PString::operator!=(const PString& other) const {
    return !(*this == other);
}

// Operatore == con const char*
bool PString::operator==(const char* str) const {
    if (!str) return false; // Gestisce puntatore nullo
    return strcmp(data, str) == 0;
}

bool PString::operator!=(const char* str) const {
    return !(*this == str);
}

// Operatore == con String
bool PString::operator==(const String& str) const {
    return *this == str.c_str();
}

bool PString::operator!=(const String& str) const {
    return !(*this == str);
}

// Operatore == con singolo char
bool PString::operator==(char c) const {
    return length == 1 && data[0] == c;
}

bool PString::operator!=(char c) const {
    return !(*this == c);
}


// Operatore + per concatenazione con char*
PString PString::operator+(const char* str) const {
    size_t newLength = length + strlen(str);
    char* newData = new char[newLength + 1];

    strcpy(newData, data);
    strcat(newData, str);

    PString result(newData);
    delete[] newData;
    return result;
}

// Operatore + per concatenazione con PString
PString PString::operator+(const PString& other) const {
    return *this + other.data;
}

// Operatore + con char: restituisce una nuova stringa con il carattere aggiunto
PString PString::operator+(char c) const {
    size_t newLength = length + 1; // Lunghezza aumentata di 1 per il nuovo carattere

    char* newData = new char[newLength + 1]; // Alloca nuova memoria (+1 per '\0')
    if (data) {
        strcpy(newData, data); // Copia i dati esistenti
    }
    newData[length] = c;       // Aggiunge il nuovo carattere alla fine
    newData[newLength] = '\0'; // Aggiunge il terminatore

    PString result(newData);   // Crea un nuovo oggetto PString
    delete[] newData;          // Libera la memoria temporanea

    return result;
}


// Operatore += con const char*
PString& PString::operator+=(const char* str) {
    if (!str) return *this; // Controlla se il puntatore è nullo

    size_t strLen = strlen(str);
    size_t newLength = length + strLen;

    char* newData = new char[newLength + 1]; // Alloca nuova memoria
    if (data) {
        strcpy(newData, data); // Copia i dati esistenti
    }
    strcat(newData, str);      // Concatena i nuovi dati

    delete[] data;             // Libera la memoria precedente
    data = newData;            // Aggiorna il puntatore ai dati
    length = newLength;        // Aggiorna la lunghezza

    return *this;
}

// Operatore += con PString
PString& PString::operator+=(const PString& other) {
    return *this += other.c_str(); // Riutilizza l'operatore con const char*
}

// Operatore += con char
PString& PString::operator+=(char c) {
    size_t newLength = length + 1;

    char* newData = new char[newLength + 1]; // Alloca nuova memoria
    if (data) {
        strcpy(newData, data); // Copia i dati esistenti
    }
    newData[length] = c;       // Aggiunge il nuovo carattere
    newData[newLength] = '\0'; // Termina la stringa

    delete[] data;             // Libera la memoria precedente
    data = newData;            // Aggiorna il puntatore ai dati
    length = newLength;        // Aggiorna la lunghezza

    return *this;
}


// Restituisce il puntatore alla stringa
const char* PString::c_str() const {
    return data;
}

// Restituisce la lunghezza della stringa
size_t PString::lengthStr() const {
    return length;
}

// Stampa la stringa sulla seriale
void PString::print() const {
    Serial.print(data);
}

// Cerca un carattere nella stringa
char* PString::findChar(char c) const {
    return strchr(data, c); // Usa strchr per trovare il carattere
}

// Cerca una sottostringa nella stringa
char* PString::findSubstring(const char* substr) const {
    return strstr(data, substr); // Usa strstr per trovare la sottostringa
}

// Split con **copie** della sottostringa
PString* PString::split(char delimiter, int& tokenCount) const {
    tokenCount = 0;

    // Conta i token
    for (size_t i = 0; i < length; i++) {
        if (data[i] == delimiter) {
            tokenCount++;
        }
    }
    tokenCount++;

    // Alloca array di oggetti PString
    PString* tokens = new PString[tokenCount];

    size_t start = 0, index = 0;
    for (size_t i = 0; i <= length; i++) {
        if (data[i] == delimiter || data[i] == '\0') {
            char temp[128] = {0};
            strncpy(temp, &data[start], i - start);
            tokens[index++] = temp;
            start = i + 1;
        }
    }

    return tokens;
}

// Split con **puntatori** alla stringa originale
const char** PString::splitPtr(char delimiter, int& tokenCount) const {
    tokenCount = 0;

    // Conta i token
    for (size_t i = 0; i < length; i++) {
        if (data[i] == delimiter) {
            tokenCount++;
        }
    }
    tokenCount++;

    // Alloca array di puntatori
    const char** tokens = new const char*[tokenCount];
    size_t start = 0, index = 0;

    for (size_t i = 0; i <= length; i++) {
        if (data[i] == delimiter || data[i] == '\0') {
            tokens[index++] = &data[start];
            start = i + 1;
        }
    }

    return tokens;
}

// Metodo endsWith
bool PString::endsWith(const PString& suffix) const {
    return endsWith(suffix.c_str());
}

bool PString::endsWith(const char* suffix) const {
    size_t suffixLen = strlen(suffix);
    if (suffixLen > length) return false; // Se il suffisso è più lungo della stringa, ritorna false

    // Primo controllo: confronto esatto dei caratteri finali
    bool res = strncmp(data + length - suffixLen, suffix, suffixLen) == 0;

    if (!res) {
        // Se il confronto fallisce, crea una copia temporanea con '\0' aggiunto
        char tempSuffix[suffixLen + 2]; // Alloca spazio per il suffisso + '\0'
        strcpy(tempSuffix, suffix);
        tempSuffix[suffixLen] = '\0'; // Aggiunge il terminatore esplicitamente

        res = strncmp(data + length - suffixLen, tempSuffix, suffixLen) == 0;
    }

    return res;
}

bool PString::endsWith(const String& suffix) const {
    return endsWith(suffix.c_str());
}

// Metodo trimEnd
void PString::trimEnd() {
    if (length == 0) return; // Se la stringa è vuota, non fare nulla

    size_t newLength = length; // Usa size_t al posto di int

    // Trova l'ultimo carattere non spazio
    while (newLength > 0 && isspace(data[newLength - 1])) {
        newLength--;
    }

    if (newLength < length) { // Confronto tra size_t
        data[newLength] = '\0'; // Aggiunge il terminatore '\0'
        length = newLength;     // Aggiorna la lunghezza della stringa
    }
}



// Metodo startsWith
bool PString::startsWith(const PString& prefix) const {
    return startsWith(prefix.c_str());
}

bool PString::startsWith(const char* prefix) const {
    size_t prefixLen = strlen(prefix);
    if (prefixLen > length) return false;
    return strncmp(data, prefix, prefixLen) == 0;
}

bool PString::startsWith(const String& prefix) const {
    return startsWith(prefix.c_str());
}

// Metodo contains
bool PString::contains(const PString& substring) const {
    return contains(substring.c_str());
}

bool PString::contains(const char* substring) const {
    return strstr(data, substring) != nullptr;
}

bool PString::contains(const String& substring) const {
    return contains(substring.c_str());
}