#include <stdio.h>
#include <string.h>
#include "../libgeometry/geom_parser.h"
#include <math.h>


int main() {
    FILE *file;
    struct Figure circle[10];
    int i = 0;
    file = fopen("geometry.txt","r");
    char str[100];
    double r;
    while (fgets(str, 100, file) != NULL) {
        char *token = strtok(str, " ");
        strcpy(circle[i].figure_firstx, token);
        strcpy(circle[i].secondx, strtok(NULL, " "));
        strcpy(circle[i].thirdx, strtok(NULL, "\n"));
        if (mainCheck(circle[i]) != 0) {
            r = mainCheck(circle[i]);
            printf("%s %s %s \n", circle[i].figure_firstx, circle[i].secondx, circle[i].thirdx);
            printf("   perimetr = %.3lf\n", r * 2 * M_PI);
            printf("   area = %.3lf\n", r * r * M_PI);
        }
        i++;
    }

}
