#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    //Déclaration des variables.
    int repeat = 0;
    int numberChoose = 0;
    int win = 1;
    int lifes = 0;
    int difficulty = 0;
    int MAX = 0, MIN = 1;
    int mysteryNumber = 0;
    //Affectation du nombre aléatoire à la variable "mysteryNumber".

    printf("\nBienvenue sur ce jeu de plus ou moins !");
    printf("\nDebut de la partie !");

    do {

        printf("\n\n[ROBOT] Tirage au sort du nombre par M.Robot.");
        //Boucle du jeu
        do {
            printf("\nQuelle difficultee voulez-vous ?");
            printf("\n 1 - entre 1 et 100");
            printf("\n 2 - entre 1 et 1000");
            printf("\n 3 - entre 1 et 10000");
            scanf("%d", &difficulty);

            //Choix de la difficultée
            switch(difficulty) {
                case 1:
                    printf("\nDifficultee 1 choisie avec succes !");
                    MAX = 100;
                    break;
                case 2:
                    printf("\nDifficultee 2 choisie avec succes !");
                    MAX = 1000;
                    break;
                case 3:
                    printf("\nDifficultee 3 choisie avec succes !");
                    MAX = 10000;
                    break;
                default:
                    printf("\nMerci de choisir entre 1, 2 et 3 !");
                    break;
            }

            //Génération du nombre aléatoire

        } while(difficulty < 1 || difficulty > 3);

        mysteryNumber = (rand() % (MAX - MIN + 1)) + MIN;
        do {
            win = 1;
            printf("\n\n\nIl est temps de choisir votre nombre !");
            scanf("%d", &numberChoose);

            //Si le nombre est autre que demandé
            if(numberChoose > 100 || numberChoose < 1)
                printf("ERREUR > Le nombre doit etre entre 1 ET 100 !");

                //Si le nombre mystère est supérieur
            else if(numberChoose < mysteryNumber)
                printf("[%d] C'est PLUS !", numberChoose), lifes++;

                //Si le nombre mystère est inférieur
            else if(numberChoose > mysteryNumber)
                printf("[%d] C'est MOINS", numberChoose), lifes++;

                //Si le nombre mystère est égal
            else if(numberChoose = mysteryNumber)
                win = 0;

        } while(win);

        printf("\n\nFELICITATIONS, tu as GAGNE ! Le nombre etait %d ! :D\n", mysteryNumber);
        printf("Nombres d'essais: %d.", lifes);
        printf("\n\nVoulez-vous relancer ?");
        printf("\n1 = OUI et 0 = NON");
        do {
            scanf("%d", &repeat);
        } while(!(repeat == 1 || repeat == 0));
        printf("%d", repeat);
    } while(repeat);
    return 0;
}