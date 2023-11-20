#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

//---------Global arrays-----------
int time_data[3];
char nameplate[8];
//---------Struct-------------
typedef struct subjects{
    char nameplate[8];
    char name[32];
    char entertime[9];
    char exittime[9];
    int paid;
    int stayed;
    };

void case_select(){
    char selected;
    printf("     **       *******   ****     ****\n    ****     **/////** /**/**   **/**\n   **//**   **     //**/**//** ** /**\n  **  //** /**      /**/** //***  /**\n **********/**      /**/**  //*   /**\n/**//////**//**     ** /**   /    /**\n/**     /** //*******  /**        /**\n//      //   ///////   //         //\n ");
    printf("                                      Welcome to Arkad Omni Managment program\n");
    wait('-');
    printf("Select one of the list item numbers:\n\n");
    printf("1: New Subject\t\t2: List selector\t3: Readme!\t4: Quit program\t\n");

    wait('-');
    printf("Your input:");


    selected = num_check();
    loadbar();

    switch(selected){

        case '1' :
            system("cls");
            new_subject();
            break;

        case '2' :
            system("cls");
            read_from_file();
            break;

        case '3' :
            system("cls");
            readme();
            break;

        case '4' :
            system("cls");
            exit(0);
            break;

        default:
            system("cls"); case_select();
            break;

    }

}

void new_subject(){

    char name[32], enter_time[9], exit_time[9];
    int enter_time_number, exit_time_number, paid = 0, yesno;
    struct subjects s;
    printf("  __                                                    \n (_   _  _. ._  ._  o ._   _     _     |_  o  _   _ _|_ \n __) (_ (_| | | | | | | | (_|   _> |_| |_) | (/_ (_  |_ \n                           _|             _|            \n");

    wait('_');

    printf("\n        Subject Name: ");
    scanf("%s", name);
    strcpy(s.name , name);

    wait('_');
    get_rand_plate();
    printf("\n        Nameplate: %s\n", nameplate);
   // printf("\n");
    strcpy(s.nameplate , nameplate);

    wait('_');
    get_rand_time();
    sprintf(enter_time, "%d:%d:%d", time_data[0], time_data[1], time_data[2]);
    enter_time_number = time_to_number();
    //printf("%d", enter_time_number);
    printf("\n        Subject entered the Facility at: ");
    printf("%s\n", enter_time);
    strcpy(s.entertime , enter_time);

    do{
        get_rand_time();
        exit_time_number = time_to_number();
        //printf("%d\n", exit_time_number);
    }
    while(enter_time_number > exit_time_number);

    wait('_');
    sprintf(exit_time, "%d:%d:%d", time_data[0], time_data[1], time_data[2]);
    printf("\n        Subject exited the Facility at: ");
    printf("%s\n", exit_time);
    strcpy(s.exittime , exit_time);


    wait('_');
    yesno = generate_int(0, 1);
    if(yesno == 1){
            printf("\n        Stayed in Facility: YES\n");
    }
    else{
            printf("\n        Stayed in Facility: NO\n");
            paid = paid +500;
    }
    s.stayed = yesno;

    wait('_');
    paid = paid + (exit_time_number - enter_time_number) / 10;
    printf("\n        Paid amount: %d HUF\n", paid);
    s.paid = paid;

    wait('_');

    //printf("\n%s %s %s %s %d %d\n", s.name, s.nameplate, s.entertime, s.exittime, s.paid[0], s.stayed[0]);
    char redo;
    printf("\n\tIf you would like to save subject details and add it to library press 'Y'");
    scanf(" %c", &redo);
    if( redo == 'Y' ){
        to_file(s);
        loadbar();
    }

}

void read_from_file(){
    char name[32], enter_time[9], exit_time[9], name_plate[8];
    int i = 0, paid = 0, stayed = 0;
    struct subjects *s;
    printf("Subject name:  Nameplate:  Entered at:  Exited at:  Payed amount(HUF):  Stayed in store(1=Yes,0=No):");
    FILE *fp;
    fp=fopen("stored_subjects.txt","r");
    while(fscanf(fp, "%s %s %s %s %d %d\n", name, name_plate, enter_time, exit_time, &paid, &stayed) !=EOF){
    //%s %s %s %s %d %d\n ",name, name_plate, enter_time, exit_time, paid, stayed);
    ++i;
    }
    fclose(fp);
    fp=fopen("stored_subjects.txt","r");
    s = (struct subjects*)malloc(i*sizeof(struct subjects));
    i = 0;
    while(fscanf(fp, "%s %s %s %s %d %d\n", name, name_plate, enter_time, exit_time, &paid, &stayed) !=EOF){
        strcpy(s[i].name ,name );
        strcpy(s[i].nameplate ,name_plate );
        strcpy(s[i].entertime ,enter_time );
        strcpy(s[i].exittime, exit_time );
        s[i].paid = paid;
        s[i].stayed = stayed;
        printf("\n %s %s %s %s %d %d\n", s[i].name ,s[i].nameplate ,s[i].entertime ,s[i].exittime , s[i].paid, s[i].stayed);
        i++;
    }
    fclose(fp);


    free(s);
    char back;
    printf("\n");
    wait('x');
    printf("\nPress any key to return to the main menu\n");
    scanf(" %c", &back);

}

int num_check(){
    char c;

    scanf(" %c",&c);
    if (c < '1' || c > '5' ){

         printf("Not valid! try something else: ");
    }
    else{
            return c;
    }
    return num_check();
    }

void to_file(struct subjects s){

    FILE *fp;
    fp=fopen("stored_subjects.txt","a");
    fprintf(fp,"%s %s %s %s %d %d\n", s.name, s.nameplate, s.entertime, s.exittime, s.paid, s.stayed);
    fflush(fp);
    fclose(fp);
}

void wait(char div){

    for(int i=0 ; i<120 ; i++){
        usleep(1500);
        printf("%c", div);
    }
    printf("\n");

}

void loadbar(){

    printf("\n                                     <<<                                        >>>                                     \n");
    printf("                                        ");

    for(int i=0 ; i<40 ; i++){
        usleep(20000);
        printf("-");
    }
    printf("\n");

}

int get_rand_time(){


    time_data[0] = generate_int(8, 19);

    time_data[1] = generate_int(0, 59);

    time_data[2] = generate_int(0, 59);

    //printf("%d : %d : %d    ", time_data[0], time_data[1], time_data[2]);
}

int time_to_number(){

    return time_data[0] * 3600 + time_data[1] * 60 + time_data[2];

}

void get_rand_plate(){

    char c1, c2, c3;
    int  n1, n2, n3;



    c1= generate_int(65, 90);     //ascii; 65 = A --> 90 = Z

    c2= generate_int(65, 90);

    c3= generate_int(65, 90);

    n1= generate_int(0, 9);            // 3*9 szam generalas

    n2= generate_int(0, 9);

    n3= generate_int(0, 9);


    sprintf(nameplate, "%c%c%c-%d%d%d",c1, c2, c3, n1, n2, n3 ); //osszefuzes
}

int generate_int(lower, upper){

    return (rand() % (upper - lower + 1)) + lower;
}

void readme(){

    printf("_|          _|                                _|                      \n_|          _|    _|_|_|  _|  _|_|  _|_|_|        _|_|_|      _|_|_|  \n_|    _|    _|  _|    _|  _|_|      _|    _|  _|  _|    _|  _|    _|  \n  _|  _|  _|    _|    _|  _|        _|    _|  _|  _|    _|  _|    _|  \n    _|  _|        _|_|_|  _|        _|    _|  _|  _|    _|    _|_|_|  \n                                                                  _|  \n                                                               _|_|    \n");
    wait('~');
    printf("When entering the subject name use '_' where there is a ' ' !\n");
    printf("In the choice selection don't enter more than one character!\n");
    wait('~');



    char back;
        printf("\n");
        printf("\nPress any key to return to the main menu\n");
        scanf(" %c", &back);
}

int main(){
    srand(time(NULL)); //radnomizalo randomizalasa
    while(1){
    system("cls");
    case_select();
    }
    return 0;
}
