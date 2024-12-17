
# 📜 **Guida alla Classe PString per Arduino**

### Autore: Alessio Savelli  
### Descrizione  
Questo progetto implementa la classe **`PString`**, una gestione avanzata delle stringhe su **Arduino**, con funzioni di validazione e parsing dinamico.  
L'esempio fornito mostra come:
1. **Ricevere dati** dalla seriale.
2. **Validare** una stringa che **inizia** con `"Ciao"` e **termina** con `"/*"`.
3. Utilizzare le nuove funzioni della classe `PString` come **`startsWith`**, **`endsWith`**, e **`contains`**.

---

## 💻 **Come Usare il Codice**

### **Funzionalità Implementate**
- **Accumulo dati** ricevuti carattere per carattere dalla porta seriale.
- **Validazione della stringa**:  
   - Deve iniziare con `"Ciao"`.  
   - Deve terminare con `"/*"`.  

- **Reset automatico** del buffer per ricevere nuovi dati.

---

## 📊 **Diagramma di Flusso del Codice**

Ecco un diagramma ASCII che spiega il **flusso di esecuzione** del codice:

```ascii
+-----------------------------+
|   Avvio del Programma       |
+-------------+---------------+
              |
              v
+-------------+---------------+
| Ricezione di un carattere   |
| dalla Serial Monitor        |
+-------------+---------------+
              |
              v
+-------------+---------------+
| Aggiunta del carattere      |
| al buffer `PString`         |
+-------------+---------------+
              |
              v
+-------------+---------------+
| La stringa inizia con "Ciao"?|
+----+------------------------+
     | Sì                     | No
     v                        |
+-------------+               |
| Termina con "/*"?           |
+----+-----------+            |
     | Sì        | No         |
     v           v            |
+-------------+               |
|  Stringa valida             |
|  Stampa e reset buffer      |
+-------------+---------------+
              |
              v
+-------------+---------------+
|     Fine Iterazione         |
+-----------------------------+
```

---

## 📋 **Spiegazione Dettagliata**

### **1. Accumulo Dati**
- I dati vengono letti carattere per carattere utilizzando la funzione `Serial.read()`.
- Ogni carattere viene aggiunto dinamicamente al buffer `inputBuffer` tramite l'operatore `+` della classe `PString`.

### **2. Validazione**
La funzione `validateString` controlla due condizioni:
1. La stringa **inizia con `"Ciao"`** → Funzione **`startsWith`**.
2. La stringa **termina con `"/*"`** → Funzione **`endsWith`**.

Se entrambe le condizioni sono vere, la stringa è considerata valida.

### **3. Reset del Buffer**
Quando la stringa viene riconosciuta come valida, il buffer `inputBuffer` viene resettato assegnandogli una stringa vuota (`""`).

---

## 🔎 **Diagramma ASCII: Come il Codice Valida e Taglia la Stringa**

Ecco un diagramma che mostra come il codice verifica e valida una stringa ricevuta:

```ascii
Stringa Ricevuta: "Ciao Arduino/*"

Passaggi:
1. Controllo INIZIALE ("Ciao")
   +------------------------+
   | Inizio: "Ciao"         |
   | Risultato: TRUE        |
   +------------------------+

2. Controllo FINALE ("/*")
   +------------------------+
   | Fine: "/*"             |
   | Risultato: TRUE        |
   +------------------------+

Stringa Valida!
+------------------------+
| Stampa la stringa      |
| "Ciao Arduino/*"       |
| Reset del buffer       |
+------------------------+
```

---

## 💡 **Output Atteso**

Quando invii la stringa `Ciao Arduino/*` tramite il **Serial Monitor**, otterrai il seguente output:

```
Ciao Arduino/*
Stringa valida ricevuta:
Ciao Arduino/*
```

Se la stringa non soddisfa le condizioni (es. manca `"Ciao"` o `"/*"`), il buffer continuerà ad accumulare i dati finché una stringa valida non viene rilevata.

---

## 🔧 **Come Caricare e Testare il Codice**
1. Carica il codice sul tuo dispositivo Arduino.
2. Apri il **Serial Monitor** nell'IDE di Arduino.
3. Imposta la velocità a **115200 baud**.
4. Invia una stringa che:
   - Inizia con `"Ciao"`.
   - Termina con `"/*"`.

5. Osserva l'output sulla Serial Monitor.

---

## 🎯 **Conclusione**
Questa implementazione mostra come utilizzare la classe `PString` per gestire dati seriali dinamicamente e validare stringhe in modo efficiente su Arduino.  
Grazie ai metodi **`startsWith`**, **`endsWith`**, e **`contains`**, il codice è chiaro, modulare e facilmente estensibile.

Buona programmazione! 🚀
