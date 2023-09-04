/*
Date: 2022-01-27
Lab 3: Part 1——Substance Test
Description: takes the threshold and the observed boiling point temperautre,
             and identifies the substance of interest
*/

/*
Assumptions:
- all inputs are valid integers within the range allowed by the int type
- all threshold values are sufficiently small to yield unique ansers
*/

#include <stdio.h>

int main(){
    
    /* Initializing~ */
    int threshold = 0, ob_point = 0;  // (threshold) temperature, and (ob_point) observed boiling point
    int low_water = 0, up_water = 0;
    int low_mercury = 0, up_mercury = 0; 
    int low_copper = 0, up_copper = 0;
    int low_silver = 0, up_silver = 0;
    int low_gold = 0, up_gold = 0;

    /* Defining~ */
    const int water = 100;  // normal boiling point for: Water
    const int mercury = 357;  // normal boiling point for: Mercury
    const int copper = 1187;  // normal boiling point for: Copper
    const int silver = 2193;  // normal boiling point for: Silver
    const int gold = 2660;  // normal boiling point for: Gold


    /* 1. Collect threshold and ob_point  */
    printf("Enter the threshold in Celsius: ");
        scanf("%d", &threshold);
    printf("Enter the observed boiling point in Celsius: ");
        scanf("%d", &ob_point);
    

    /* 2. Comparing the observed and normal boiling points of substances  */
    
    /* the upper and lower bounds of the targeted substances */
    low_water = water - threshold; up_water = water + threshold;
    low_mercury = mercury - threshold; up_mercury = mercury + threshold;   
    low_copper = copper - threshold; up_copper = copper + threshold;  
    low_silver = silver - threshold; up_silver = silver + threshold;  
    low_gold = gold - threshold; up_gold = gold + threshold;
    
    /*
      Main logic: compare if observed boiling point stays below the upper bound "AND" higher the lower bound
    */
    if ( (ob_point <= up_water) && (ob_point >= low_water) ){
        printf("The substance you tested is: Water");
    }

    else if ( (ob_point <= up_mercury) && (ob_point >= low_mercury) ){
        printf("The substance you tested is: Mercury");
    }

    else if ( (ob_point <= up_copper) && (ob_point >= low_copper) ){
        printf("The substance you tested is: Copper");
    }

    else if ( (ob_point <= up_silver) && (ob_point >= low_silver) ){
        printf("The substance you tested is: Silver");
    }

    else if ( (ob_point <= up_gold) && (ob_point >= low_gold) ){
        printf("The substance you tested is: Gold");
    }

    else {
        printf("Substance unknown.");
    }

    // testing~
    //printf("\n\n%d  %d", threshold, ob_point);

    return 0;
}