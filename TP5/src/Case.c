/* Auteur       : Bourennane Amine, Berthereau Thomas
*  Creation     : 03-03-2020
*  Modification : 03-03-2020   */
#include "Case.h"

int compare_case(Case pos1, Case pos2) {
    return (pos1.coord_x == pos2.coord_x
            && pos1.coord_y == pos2.coord_y);
}
