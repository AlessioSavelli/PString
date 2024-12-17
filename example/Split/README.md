
# 🚀 Classe PString per Arduino

### Autore: Alessio Savelli  
### Descrizione:  
Questa classe `PString` è progettata per manipolare stringhe in modo efficiente su dispositivi con risorse limitate come Arduino.  
Supporta due metodi avanzati per dividere una stringa:  

1. **`split`**: Restituisce un array di oggetti `PString` (crea copie delle sottostringhe).  
2. **`splitPtr`**: Restituisce un array di puntatori alle sottostringhe nella stringa originale.

---

## 📋 **Come Funziona**

### Metodo `split`
- **Restituisce**: Un array di **oggetti `PString`** con copie indipendenti delle sottostringhe.  
- **Utilizzo**: Sicuro se la stringa originale verrà modificata successivamente.  
- **Pulizia**: È necessario liberare la memoria con `delete[]`.

### Metodo `splitPtr`
- **Restituisce**: Un array di **puntatori** alle sottostringhe originali.  
- **Utilizzo**: Estremamente efficiente in termini di memoria e velocità.  
- **Limite**: I token dipendono dalla stringa originale, che non può essere modificata.

---

## 💻 **Esempio d'Uso**

### Codice Arduino:
```cpp
#include "PString.h"

void setup() {
    Serial.begin(115200);

    PString str = "Ciao:Mondo:Arduino:OPTA";

    // Split con copie
    int tokenCount = 0;
    PString* tokens = str.split(':', tokenCount);
    Serial.println("Split con copie:");
    for (int i = 0; i < tokenCount; i++) {
        Serial.print("Token ");
        Serial.print(i);
        Serial.print(": ");
        tokens[i].print();
        Serial.println();
    }
    delete[] tokens;

    // Split con puntatori
    int ptrCount = 0;
    const char** tokensPtr = str.splitPtr(':', ptrCount);
    Serial.println("\nSplit con puntatori:");
    for (int i = 0; i < ptrCount; i++) {
        Serial.print("Token ");
        Serial.print(i);
        Serial.print(": ");
        Serial.println(tokensPtr[i]);
    }
    delete[] tokensPtr;
}

void loop() {
    // Nulla
}
```

---

## 📊 **Output**

```
Split con copie:
Token 0: Ciao
Token 1: Mondo
Token 2: Arduino
Token 3: OPTA

Split con puntatori:
Token 0: Ciao
Token 1: Mondo
Token 2: Arduino
Token 3: OPTA
```

---

## 🎯 **Pro e Contro**

| Metodo       | Vantaggi                           | Svantaggi                           |
|--------------|------------------------------------|------------------------------------|
| **split**    | ✅ Token indipendenti dalla stringa | ❌ Maggiore uso di memoria          |
| **splitPtr** | ✅ Alta efficienza e velocità       | ❌ Dipendente dalla stringa originale |

---

## 🛠 **Come Usarlo**
1. Scarica `PString.h` e `PString.cpp` e includili nel tuo progetto Arduino.
2. Usa `split` o `splitPtr` per dividere le stringhe.
3. Ricordati di liberare la memoria dinamica con `delete[]`.

---

## 📌 **Conclusione**
La classe `PString` è pensata per essere efficiente e versatile su dispositivi con memoria limitata come Arduino.  
- Usa **`split`** se ti serve sicurezza e indipendenza.  
- Usa **`splitPtr`** se vuoi efficienza e velocità.

Buon lavoro e buona programmazione! 🚀
