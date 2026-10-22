#include <stdio.h>
#include <stdlib.h>

int main(){
    int hh12, mm, converted_hh24, smallest_time = 1000, i_temp = 1;
    char am_pm;
    start:
    printf("Enter a time in the 12 hour forum (12:00 PM): ");
    scanf("%d : %d %c",&hh12, &mm, &am_pm);  //entering the first letter of either pm or am is enough

    int t[9] = {0};

    t[1] = 8 * 60;       // 08:00 AM
    t[2] = 9 * 60 + 43;  // 09:43 AM
    t[3] = 11 * 60 + 19; // 11:19 AM
    t[4] = 12 * 60 + 47; // 12:47 PM
    t[5] = 14 * 60;      // 02:00 PM
    t[6] = 15 * 60 + 45; // 03:45 PM
    t[7] = 19 * 60 ;     // 07:00 PM
    t[8] = 21 * 60 + 45; // 09:45 PM


    if(am_pm == 'p' || am_pm == 'P'){
        if(hh12 != 12)
            converted_hh24 = (hh12 + 12) * 60 + mm;
        else
            converted_hh24 = hh12 * 60 + mm;
    }else{
        if(hh12 != 12)
            converted_hh24 = hh12 * 60 + mm;
        else{
            converted_hh24 = (hh12 - 12) * 60 + mm;
        }
    }
    //converted_hh24 = hh24 * 60 + mm;

    for(int i = 1; i <= 8; i++){
        if(t[i] - converted_hh24 <= 0)
            continue;
        if(smallest_time > t[i] - converted_hh24){
            smallest_time = t[i] - converted_hh24;
            i_temp = i;
        }
    }

    printf("Closest departure time is ");
    switch(i_temp){
        case 1: printf("8:00 A.M., arriving at 10:16 A.M.\n");break;
        case 2: printf("9:43 A.M., arriving at 11:52 A.M.\n");break;
        case 3: printf("11:19 A.M., arriving at 1:31 P.M.\n");break;
        case 4: printf("12:47 P.M., arriving at 3:00 P.M.\n");break;
        case 5: printf("2:00 P.M., arriving at 4:08 P.M.\n");break;
        case 6: printf("3:45 P.M., arriving at 5:55 P.M.\n");break;
        case 7: printf("7:00 P.M., arriving at 9:20 P.M.\n");break;
        case 8: printf("9:45 P.M., arriving at 11:58 P.M.\n");break;
    }

    return 0;
}
