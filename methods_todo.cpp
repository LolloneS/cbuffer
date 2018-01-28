// PRIMA COSA provare la insert l'operator= e il costruttore copia!!!
// AGGIUNGI TRY CATCH nella insert! potrebbe non esserci spazio per un nodo!
// CONTROLLA ITERATOR!!!!

// forward iterator
	// cbuffer[0] è l'elemento più vecchio
	// cbuffer.begin() è l'iteratore all'elemento più vecchio

// 4) l’accesso in lettura e scrittura dell'elemento i-esimo tramite operatore []

// se inserisco in posizione 10 in un cbuffer grande 6, è errore? scegli tu basta che argomenti

// cbuffer[0] è l'elemento più vecchio
// cbuffer.begin() è l'iteratore all'elemento più vecchio

/*
Scrivere anche una funzione globale evaluate_if che, dati un cbuffer
generico cb e un predicato unario generico P (cioè che prende un solo valore),
per ogni elemento cb[i] contenuto nel cbuffer, stampa a console:
"[i]: true" quando P(cb[i]) è vero
oppure
"[i]: false" quando P(cb[i]) è falso
con i l'indice dell'elemento.
Testale la classe sia su tipi primitivi che su tipi custom e con diversi predicati P.
*/


// in scrittura è possibile accedere a cbuffer[occupied+1] per consentire l'inserimento di un nuovo nodo. in lettura no, ritorneremmo null