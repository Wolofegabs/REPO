#include <stdio.h>
#include <stdlib.h>
int main( int argc, char* argv[])
{
    // Déclaration de deux pointeurs de type fichier pour recueillir l'adresse du fichier_source et celui du fichier_destination

    FILE *fichier_souce, *fichier_destination;

    // Verification du nombre de paramètres d'entrées
    if (argc!=3)
        {
            printf("Le nombre de parametres n'est pas respecte \n");
            printf("Utilisez le format <./prog1 fichier_source fichier_destination > \n");
        }
    // Ouverture des fichiers après verification
    else
    {

        fichier_souce = fopen(argv[1], "rb");
        if (fichier_souce == NULL)
            {
                printf("Erreur lors de l'ouverture de %s \n", argv[1]);
                exit(0);
            }


        fichier_destination = fopen(argv[2], "wb");
        if (fichier_destination == NULL)
            {
                printf("Erreur lors de l'ouverture de %s \n", argv[2]);
                exit(1);
            }

    // Ecriture dans le fichier

    fwrite (&fichier_souce, sizeof (fichier_souce), 1 ,fichier_destination);

    printf("\nLe contenu a ete copie dans le fichier %s \n", argv[2]);

        // Fermeture des fichiers après vérification


        fclose(fichier_souce);
        if (fclose(fichier_souce) == EOF)
            {
                printf("\nErreur lors de la fermeture du flux source");
                return (EXIT_FAILURE) ;
            }

        fclose(fichier_destination);
        if (fclose(fichier_destination) == EOF)
            {
                printf("\nErreur lors de la fermeture du flux destination");
                return (EXIT_FAILURE);
            }
    }

    return 0;
}
