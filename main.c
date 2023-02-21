#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main_error;
struct figure {
    char name_x1[20];
    char x2_check[20];
    char x3_check[20];
    float x1;
    float x2;
    float x3;
};

int check_x(char string[], int n) {
    char dot[] = ".";

    for (int i = 0; i < n - 1; i++) {
        //        printf("%d\n",(int)string[i]);
        if (((int) string[i] > 57 || (int) string[i] < 48) && (int) string[i] != (int) (dot[0])) {
            main_error = 3;
            return i;
        }
    }
    return 0;
}
int find_read_length_x2_x3(char string[], int n) {
    char dot[] = ".";
    int k = 0;
    for (int i = 0; i < n; i++) {
        //        printf("%d\n",(int)string[i]);
        if (((int) string[i] > 57 || (int) string[i] < 48) && (int) string[i] != (int) (dot[0])) {
            return k;
        }
        k++;
    }
    return k;
}
int check_comma(struct figure main_check_circle) {
    if (main_check_circle.x2_check[strlen(main_check_circle.x2_check) - 1] != 44) {
        main_error = 5;
        return 3;
    }
    return 0;
}
int check_last_bracket(struct figure main_check_circle) {
    if (main_check_circle.x3_check[strlen(main_check_circle.x3_check) - 1] != 41) {
        main_error = 7;
        return 3;
    }
    return 0;
}
void make_x1_to_str(char s[], int length, struct figure main_check_circle) {
    //    char s[] = "";
    strcpy(s, main_check_circle.name_x1 + strlen(main_check_circle.name_x1) - length);
    //    return s ;
}
int check_name(struct figure main_check_circle) {
    char check_name[] = "circle(";
    for (int i = 1; i < 7; i++) {
        if (strncmp(check_name, main_check_circle.name_x1, i) != 0) {
            //            printf("%d ",i);
            if (i == 6) {
                main_error = 4;
            } else {
                main_error = 2;
            }

            return i;
        }
    }
    return 0;
}

void print_error(struct figure main_check_circle, int pointer) {
    printf("%s ", main_check_circle.name_x1);
    printf("%s ", main_check_circle.x2_check);
    printf("%s\n", main_check_circle.x3_check);
    for (int i = 0; i < pointer; i++) {
        printf(" ");
    }
    printf("^\n");
    printf("Error at colum %d: ", pointer);
    if (main_error == 2) printf("expected 'circle', 'triangle' or 'polygon'");
    if (main_error == 3) printf("expected '<double>");
    if (main_error == 4) printf("expected '('");
    if (main_error == 5) printf("expected ','");
    if (main_error == 6) printf("expected '<double>");
    if (main_error == 7) printf("expected ')");
}
float mainCheck(struct figure main_check_circle) {
    if (check_name(main_check_circle) != 0) {
        print_error(main_check_circle, check_name(main_check_circle));
        return 0;
    }
    int length_name_x1 = strlen(main_check_circle.name_x1);
    char x1[20] = "";
    char x2[20] = "";
    char x3[20] = "";
    char check_name[] = "circle(";
    int length_name = strlen(check_name);
    strcpy(x1, main_check_circle.name_x1 + strlen(main_check_circle.name_x1) - length_name_x1 + length_name + 1);
    strncpy(x2, main_check_circle.x2_check, find_read_length_x2_x3(main_check_circle.x2_check, strlen(main_check_circle.x2_check)));
    strncpy(x3, main_check_circle.x3_check, find_read_length_x2_x3(main_check_circle.x3_check, strlen(main_check_circle.x3_check)));
    //    printf("%s\n",main_check_circle.x3_check);

    if (check_x(x1, strlen(x1)) != 0) {
        print_error(main_check_circle, (check_x(x1, strlen(x1))) + strlen(check_name) + 1);
        return 0;
    }
    if (check_x(main_check_circle.x2_check, strlen(main_check_circle.x2_check)) != 0) {
        print_error(main_check_circle, (check_x(x2, strlen(main_check_circle.x2_check))) + strlen(check_name) + strlen(x1) + 2);
        return 0;
    }
    if (check_comma(main_check_circle) != 0) {
        print_error(main_check_circle, +strlen(check_name) + strlen(x1) + 2 + strlen(main_check_circle.x2_check));
        return 0;
    }
    if (check_x(main_check_circle.x3_check, strlen(main_check_circle.x3_check)) != 0) {
        print_error(main_check_circle, (check_x(x3, strlen(main_check_circle.x3_check))) + strlen(check_name) + strlen(x1) + 2 + strlen(main_check_circle.x3_check));
        return 0;
    }
    if (check_last_bracket(main_check_circle) != 0) {
        print_error(main_check_circle, +strlen(check_name) + strlen(x1) + 2 + strlen(main_check_circle.x2_check) + strlen(main_check_circle.x3_check));
        return 0;
    }
    return atof(x3);
    //    strcpy(x1,main_check_circle.name_x1+strlen(main_check_circle.name_x1)-length_name_x1+length_name+1);
    //    printf("%s\n",main_check_circle.x2_check);


    //    for(int i = 7; main_check_circle.name_x1[i] != "")
    //    if(check_x)
}
int main() {
    FILE *file;

    struct figure circle[10];
    int i = 0;

    file = fopen("geometry.txt", "r");
    int r;
    while (fscanf(file, "%s %s %s",
                  circle[i].name_x1, circle[i].x2_check, circle[i].x3_check) != EOF) {
        //        printf("%s",circle[i].x3_check);

        if (mainCheck(circle[i]) != 0) {
            r = mainCheck(circle[i]);
            //            printf("%f\n",mainCheck(circle[i]));
            printf("%s %s %s\n", circle[i].name_x1, circle[i].x2_check, circle[i].x3_check);
            printf("   perimetr = %.3f\n", r * 2 * 3.14);
            printf("   area = %.3f\n", r * r * 3.14);
        }

        i++;
    }
}
