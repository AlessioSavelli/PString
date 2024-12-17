#ifndef PString_H
#define PString_H

#include <Arduino.h> // Inclusione per ambiente Arduino

class PString {
private:
    char* data;    // Puntatore alla stringa
    size_t length; // Lunghezza della stringa (escluso '\0')

    void allocateAndCopy(const char* src); // Metodo interno per allocare e copiare

public:
    // Costruttori e distruttore
    PString();                     // Costruttore di default
    PString(const char* str);      // Costruttore con stringa C
    PString(const PString& other); // Costruttore di copia
	PString(const String& str);    // Costruttore per cast da String
    ~PString();                    // Distruttore

    // Operatori di assegnamento
    PString& operator=(const char* str);
    PString& operator=(const PString& other);
	PString& operator=(const String& str); // Operatore per assegnare un oggetto String

	// Operatori di confronto
	bool operator==(const PString& other) const;      // Confronto con PString
	bool operator!=(const PString& other) const;

	bool operator==(const char* str) const;           // Confronto con const char*
	bool operator!=(const char* str) const;

	bool operator==(const String& str) const;         // Confronto con String
	bool operator!=(const String& str) const;

	bool operator==(char c) const;                    // Confronto con singolo carattere
	bool operator!=(char c) const;

    // Operatore di concatenazione
    PString operator+(const char* str) const;
    PString operator+(const PString& other) const;
	PString operator+(char c) const; // Concatenazione con un singolo carattere

	// Operatori di concatenazione e assegnamento
	PString& operator+=(const char* str);   // Concatenazione con const char*
	PString& operator+=(const PString& other); // Concatenazione con PString
	PString& operator+=(char c);            // Concatenazione con un singolo carattere




    // Metodi di utilità
    const char* c_str() const; // Restituisce il puntatore alla stringa
    size_t lengthStr() const;  // Restituisce la lunghezza della stringa
	void print() const;        // Stampa la stringa sulla Serial
	void trimEnd(); // Rimuove spazi o caratteri invisibili dalla fine della stringa



    // Ricerca
    char* findChar(char c) const;         // Usa strchr per cercare un carattere
    char* findSubstring(const char* substr) const; // Usa strstr per sottostringa
	
	bool endsWith(const PString& suffix) const;          // Controlla se termina con PString
    bool endsWith(const char* suffix) const;             // Controlla se termina con const char*
    bool endsWith(const String& suffix) const;           // Controlla se termina con String

    bool startsWith(const PString& prefix) const;        // Controlla se inizia con PString
    bool startsWith(const char* prefix) const;           // Controlla se inizia con const char*
    bool startsWith(const String& prefix) const;         // Controlla se inizia con String

    bool contains(const PString& substring) const;       // Controlla se contiene PString
    bool contains(const char* substring) const;          // Controlla se contiene const char*
    bool contains(const String& substring) const;        // Controlla se contiene String
	
	// Split con copie
    PString* split(char delimiter, int& tokenCount) const;

    // Split con puntatori
    const char** splitPtr(char delimiter, int& tokenCount) const;
};

#endif // PString_H
