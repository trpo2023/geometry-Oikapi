#pragma once 
#include <stdio.h>

typedef struct Figure {
    char figure_firstx[20];
    char secondx[20];
    char thirdx[20];
};





int check_real_lenght(struct Figure main_check_circle);
int check_x(char string[], int n,int *main_error);
int check_loss(struct Figure main_check_circle, char str[],int*main_error);
int check_comma(struct Figure main_check_circle,int *main_error);
int check_last_bracket(struct Figure main_check_circle,int *main_error);
int check_name(struct Figure main_check_circle,int *main_error);
void print_error(struct Figure main_check_circle, int pointer,int *main_error);
double mainCheck(struct Figure main_check_circle);  
