# CBuffer
## Lorenzo Soligo - 806954 - Febbraio 2018

### Introduzione
La traccia del progetto richiede di scrivere un buffer circolare di dimensione data in fase di costruzione.
In poche parole, bisogna aggiungere elementi al buffer "finché c'è spazio", e successivamente bisogna sovrascrivere gli elementi in ordine di inserimento crescente (i.e. dal più vecchio al più nuovo).

### Scelte implementative
#### Implementazione del cbuffer
Il progetto, alla luce di quanto studiato durante il corso, si prestava a due diverse implementazioni:
1. nodi concatenati
    * si definisce una `struct node` templata, contenente il valore e il puntatore al `next`
2. array di tipo `T` templato

L'implementazione da me scelta è la prima, in particolare perché la trovo più facilmente riutilizzabile ed estendibile. 
Inoltre, sfruttando i `node`, possiamo posticipare l'allocazione della memoria fino a quando questa non sarà certamente necessaria; a scapito di una potenziale perdita di località dovuta a puntatori a `next`, abbiamo un vantaggio non indifferente in caso venga istanziato un `cbuffer` di grosse dimensioni e vengano inseriti solo pochi elementi.
Tutto sommato, comunque, entrambe le implementazioni risultano valide, ed oserei dire che la scelta di una in contrapposizione all'altra sia una semplice questione di gusti.

#### Implementazione di base
Di seguito, le mie scelte progettuali per quanto riguarda il cuore della classe, con giustificazioni a riguardo.

* `struct node`:
    * il cbuffer si appoggia ad una `struct node` molto semplice. Questa consiste in:
        * un puntatore ad un altro `node`, il `next` del nodo attuale
        * valore templato `T value`
        * costruttore di default
        * costruttore dati `value` e `next` [quest'ultimo, impostato di default a NULL] 
* **campi della classe**:
    * ho scelto di utilizzare 4 campi:
        * `_size`, la dimensione del cbuffer
        * `_occupied`, il numero di elementi occupati del cbuffer
        * `node* _head`, il puntatore alla testa del cbuffer
        * `node* _tail`, il puntatore alla coda del cbuffer
    * la scelta è dovuta al fatto che questi campi sono sufficienti a svolgere tutte le operazioni necessarie e si prestano bene alla manipolazione del cbuffer (inserimento in coda, rimozione della testa, ...)


#### Implementazione di metodi, operatori, iteratori, ...
1. `operator[]`
    * ho deciso di implementare l'`operator[]` nel seguente modo: 
        * l'accesso è consentito solo alle cellette del cbuffer che sono già state istanziate. 
        Ho inoltre implementato due `operator[]`, uno `const` per la lettura e uno standard in scrittura.
        È quindi consentita la *modifica* di cellette esistenti, ma non l'inserimento di nuove cellette, che richiede l'utilizzo di `insert`.
