#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void){
    int length;
    int width;
    int stitches, rows;
    double truelength;
    double truewidth;

        printf("Enter your pattern gauge:");
        printf("\nStitches: ");
            scanf("%d", &stitches);
        printf("\nLength: ");
            scanf("%d", &length);

        printf("\nRows: ");
            scanf("%d", &rows);
        printf("\nWidth: ");
            scanf("%d", &width);

    double rowsperu;
    double stitchperu;

        rowsperu = (double)rows/width;
        stitchperu = (double)stitches/width;

    int userrows;
    int userstitches;
    
        printf("Enter your gauge measurements, in the same units as the prior measurements:\n");
        printf("Stitches: ");
            scanf("%d", &userstitches);
        printf("Length: ");
            scanf("%lf", &truelength);
    
        printf("Rows: ");
            scanf("%d", &userrows);
        printf("Width: ");
            scanf("%lf", &truewidth);

    double userrowsu;
    double userstitchu;

        userrowsu = (double)userrows/truewidth;
        userstitchu = (double)userstitches/truelength;

    double diffs;
    double diffr;
    double percent;

        diffs = (double)userstitchu - stitchperu;
        diffr = (double)userrowsu - rowsperu;
        percent = (fabs(diffs)/stitchperu) * 100;

    int needle;

        needle = fabs(diffs)/0.5;

        if(fabs(diffs) == 0){
            printf("Your gauge stitches are perfect! Make no changes.");
        }else if(diffs < 0){
            printf("Your gauge is %.1lf percent too loose. Try going up %d needle/hook size.", percent, needle);
        }else{
            printf("Your gauge is %.1lf percent too tight. Try going down %d needle/hook size.", percent, needle);
        }

        if(fabs(diffr) < 0.01){
            printf("Your gauge rows are perfect! Make no changes.");
        }else if(diffr < 0){
            printf("\nYour rows are too tall.");
        }else{
            printf("\nYour rows are too short.");
        }

    return 0;
}