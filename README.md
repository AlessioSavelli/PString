
# 📚 **Libreria PString per PLC Opta**

### Autore: Alessio Savelli  
### Versione: 1.0.0  
### Descrizione  
La libreria **PString** è progettata per fornire un'alternativa più efficiente alla classe `String` di Arduino, ottimizzata specificamente per il **PLC Opta**.  
Grazie a questa libreria è possibile manipolare stringhe in modo dinamico, mantenendo un controllo accurato sull'uso della memoria e migliorando le prestazioni nei dispositivi con risorse limitate.

---

## 🔧 **Funzionalità della Classe PString**

### **Costruttori**
1. **`PString()`**  
   - Costruttore di default che inizializza una stringa vuota.  
   **Esempio**:  
   ```cpp
   PString str;
   ```

2. **`PString(const char* str)`**  
   - Costruttore che inizializza l'oggetto con una stringa C (`const char*`).  
   **Esempio**:  
   ```cpp
   PString str = "Ciao";
   ```

3. **`PString(const PString& other)`**  
   - Costruttore di copia.  
   **Esempio**:  
   ```cpp
   PString str1 = "Ciao";
   PString str2 = str1;
   ```

4. **`PString(const String& str)`**  
   - Costruttore che permette il **cast da `String` a `PString`**.  
   **Esempio**:  
   ```cpp
   String strArduino = "Ciao Arduino";
   PString str = strArduino;
   ```

---

### **Operatori**
1. **`operator=`**  
   - Permette di assegnare una stringa `const char*`, un oggetto `PString` o un oggetto `String`.  
   **Esempio**:  
   ```cpp
   PString str;
   str = "Ciao";
   str = String("Test Arduino");
   ```

2. **`operator+`**  
   - Consente di concatenare stringhe. Supporta `const char*` e `PString`.  
   **Esempio**:  
   ```cpp
   PString str1 = "Ciao";
   PString str2 = str1 + " Mondo!";
   ```

3. **`operator==` e `operator!=`**  
   - Permettono il confronto tra due stringhe `PString`.  
   **Esempio**:  
   ```cpp
   PString str1 = "Ciao";
   PString str2 = "Ciao";
   if (str1 == str2) {
       Serial.println("Le stringhe sono uguali");
   }
   ```

---

### **Metodi di Utilità**
1. **`c_str()`**  
   - Restituisce il puntatore alla stringa.  
   **Esempio**:  
   ```cpp
   PString str = "Ciao";
   Serial.println(str.c_str());
   ```

2. **`lengthStr()`**  
   - Restituisce la lunghezza della stringa.  
   **Esempio**:  
   ```cpp
   PString str = "Ciao";
   Serial.println(str.lengthStr()); // Output: 4
   ```

3. **`print()`**  
   - Stampa la stringa sulla Serial.  
   **Esempio**:  
   ```cpp
   PString str = "Ciao";
   str.print();
   ```

---

### **Metodi di Ricerca**
1. **`findChar(char c)`**  
   - Trova il primo carattere `c` nella stringa.  
   **Esempio**:  
   ```cpp
   PString str = "Arduino";
   char* result = str.findChar('d');
   if (result) Serial.println("Carattere trovato");
   ```

2. **`findSubstring(const char* substr)`**  
   - Trova una sottostringa all'interno della stringa.  
   **Esempio**:  
   ```cpp
   PString str = "Ciao Arduino";
   if (str.findSubstring("Arduino")) {
       Serial.println("Sottostringa trovata");
   }
   ```

---

### **Metodi di Validazione**
1. **`startsWith`**  
   - Controlla se la stringa inizia con un prefisso specifico. Supporta `PString`, `const char*` e `String`.  
   **Esempio**:  
   ```cpp
   PString str = "Ciao Mondo";
   if (str.startsWith("Ciao")) {
       Serial.println("Inizia con 'Ciao'");
   }
   ```

2. **`endsWith`**  
   - Controlla se la stringa termina con un suffisso specifico. Supporta `PString`, `const char*` e `String`.  
   **Esempio**:  
   ```cpp
   PString str = "Test Arduino/*";
   if (str.endsWith("/*")) {
       Serial.println("Termina con '/*'");
   }
   ```

3. **`contains`**  
   - Verifica se la stringa contiene una sottostringa. Supporta `PString`, `const char*` e `String`.  
   **Esempio**:  
   ```cpp
   PString str = "Ciao Arduino";
   if (str.contains("Arduino")) {
       Serial.println("Contiene 'Arduino'");
   }
   ```

---

### **Metodi di Split**
1. **`split(char delimiter, int& tokenCount)`**  
   - Divide la stringa in **copie** utilizzando un delimitatore.  
   **Esempio**:  
   ```cpp
   PString str = "Ciao:Mondo:Arduino";
   int count;
   PString* tokens = str.split(':', count);
   for (int i = 0; i < count; i++) {
       tokens[i].print();
   }
   delete[] tokens;
   ```

2. **`splitPtr(char delimiter, int& tokenCount)`**  
   - Divide la stringa utilizzando un delimitatore e restituisce **puntatori** ai token nella stringa originale.  
   **Esempio**:  
   ```cpp
   PString str = "Ciao:Mondo:Arduino";
   int count;
   const char** tokens = str.splitPtr(':', count);
   for (int i = 0; i < count; i++) {
       Serial.println(tokens[i]);
   }
   delete[] tokens;
   ```

---

## 💡 **Esempio Completo**

```cpp
#include "PString.h"

PString buffer;

void setup() {
    Serial.begin(115200);

    buffer = "Ciao Arduino/*";

    // Test startsWith, endsWith, contains
    if (buffer.startsWith("Ciao")) Serial.println("La stringa inizia con 'Ciao'");
    if (buffer.endsWith("/*")) Serial.println("La stringa termina con '/*'");
    if (buffer.contains("Arduino")) Serial.println("La stringa contiene 'Arduino'");

    // Test split
    int count;
    PString* tokens = buffer.split(' ', count);
    for (int i = 0; i < count; i++) {
        tokens[i].print();
        Serial.println();
    }
    delete[] tokens;
}

void loop() {
    // Vuoto
}
```

---

## 🎯 **Conclusione**
La libreria **PString** fornisce un'alternativa leggera e ottimizzata alla classe `String`, ideale per dispositivi come il **PLC Opta**. Grazie alle sue funzionalità avanzate, è possibile manipolare e validare stringhe in modo semplice ed efficiente.

Buona programmazione! 🚀
