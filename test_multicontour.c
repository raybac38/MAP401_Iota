#include "multi_contour.h"
#include "module_ps.h"
#include <string.h>


/* Donne les contours d'une image ainsi que les informations*/
int main(int argc, char * argv[])
{
    if(argc != 2 && argc != 3)
    {
        printf("Argument invalide \n ./this <file> || <file.out>\n");
        exit(EXIT_SUCCESS);
    }

    Image image = lire_fichier_image(argv[1]);


    Liste * contours = ExtractAllOutline(image);

    printf("Information : \n");

    printf("Image de taille : %d x %d \n", largeur_image(image), hauteur_image(image));


    unsigned nombreContours =  ListeSize(contours);

    printf("Nombre de contours detecter : %d\n", nombreContours);

    for (unsigned i = 0; i < nombreContours; i++)
    {
        printf("Contour numero %ld\n", i);
        Tableau * t = ListeGet(contours, i);
        printf("hey");
        unsigned tabnbpoints = TableauGetSize(ListeGet(contours, i));
        printf("Nombre de points %d\n", tabnbpoints);
        printf("Nombre de segments : %d\n", tabnbpoints - 1);
        
    }

    

    printf("Fin du teste\n");
    
    if(argc == 3)
        {

            printf("Impression de l'image de contours \n");
            sortie_fichier(*ListeGet(contours, 0), argv[2]);
        }
    return 0;
    

}