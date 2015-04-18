#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisci le costanti
#define N 3
#define MAX_STRLEN 30

// Definisci il tipo di dato struct s_studente
struct s_studente{
    char nome[MAX_STRLEN+1];
    char cognome[MAX_STRLEN+1];
    unsigned int eta;
    char classe[MAX_STRLEN+1];
};

// Definisci studente come struct s_studente
typedef struct s_studente studente;

int main(int argc, char** argv) {
    // Dichiara le variabili locali
    studente alunno;
    int i;
    FILE *pfile;
    
    // Codice per l'inserimento, da parte dell'utente, dei dati e del salvataggio
    // nel file
    pfile=fopen("elenco.dat","wb");
    
    if(pfile){
        for(i=0;i<N;i++){
            printf("Inserisci il nome del %d° alunno: ",i+1);
            scanf("%s", alunno.nome);
            printf("Inserisci il cognome del %d° alunno: ",i+1);
            scanf("%s", alunno.cognome);
            printf("Inserisci l'eta' del %d° alunno: ",i+1);
            scanf("%d", &alunno.eta);
            printf("Inserisci la classe del %d° alunno: ",i+1);
            scanf("%s", alunno.classe);
            printf("\n");
            
            fwrite(&alunno, sizeof(studente), 1, pfile);
        }
        
        fclose(pfile);
        
        pfile=fopen("elenco.dat","rb");
        
        printf("Adesso procedo alla stampa\n\n");
        
        for(i=0;i<N;i++){
            fread(&alunno, sizeof(studente), 1, pfile);
            
            printf("Nome: %s\n",alunno.nome);
            printf("Cognome: %s\n",alunno.cognome);
            printf("Eta': %d\n",alunno.eta);
            printf("Classe: %s\n\n",alunno.classe);            
        }
        
        fclose(pfile);
    }
    else
        printf("Non sono riuscito ad aprire il file");
    return (EXIT_SUCCESS);
}