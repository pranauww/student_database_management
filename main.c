#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <string.h>

union REGS i, o;

void login_window();
void password_input();
void draw_screen();
void initialize_mouse();
void show_mouse();
void get_mouse();
void add_window();
void add_student_record();
void search_student_record();
void display_data();
void delete_student_record();
void modify_student_record();
void list_records();
void backup_database();
void progress();
void exit_system();

struct ADDRESS {
    char STREET[25];
    char IM[25];
    char CITY[15];
    char COUNTRY[15];
    char PIN[10];
};

struct STUDENT {
    int ROLL_NO;
    float MARKS;
    char MOBILE_NO[12];
    char F_NAME[20];
    char L_NAME[20];
    char COURSE_NAME[10];
    char SEX[7];
    char FEES[5];
    int DAY;
    int MONTH;
    int YEAR;
    struct ADDRESS A;
};

void main() {
    int gd = DETECT, gm;

    registerfarbgidriver(EGAVGA_driver_far);
    registerfarbgifont(sansserif_font_far);
    registerfarbgifont(small_font_far);
    registerfarbgifont(gothic_font_far);
    registerfarbgifont(triplex_font_far);

    initgraph(&gd, &gm, "C:\\turboc3\\bgi");

    login_window();
    password_input();

start:
    cleardevice();
    draw_screen();
    initialize_mouse();

    setcolor(3);
    setfillstyle(1, 8);
    rectangle(390, 55, 200, 88);
    rectangle(395, 50, 195, 94);
    floodfill(393, 52, 3);
    gotoxy(27, 5);
    printf("1. ADD STUDENT RECORD ");

    /* FOLLOWING IS SEARCH RECORD */
    gotoxy(27, 8);
    setcolor(3);
    setfillstyle(1, 8);
    rectangle(390, 135, 200, 105);
    rectangle(395, 140, 195, 100);
    floodfill(394, 139, 3);
    printf("2. SEARCH RECORD ");

    /* FOLLOWING IS DELETE RECORD */
    gotoxy(27, 11);
    setcolor(3);
    setfillstyle(1, 8);
    rectangle(390, 180, 200, 152);
    rectangle(395, 185, 195, 146);
    floodfill(394, 184, 3);
    printf("3. DELETE RECORD ");

    /* FOLLOWING CODE IS TO MODIFY RECORD */
    gotoxy(27, 14);
    setcolor(3);
    setfillstyle(1, 8);
    rectangle(390, 229, 200, 199);
    rectangle(395, 234, 195, 194);
    floodfill(394, 233, 3);
    printf("4. MODIFY RECORD ");

    /* FOLLOWING IS FOR LISTING RECORD */
    gotoxy(27, 17);
    setcolor(3);
    setfillstyle(1, 8);
    rectangle(390, 275, 200, 248);
    rectangle(395, 282, 195, 242);
    floodfill(394, 281, 3);
    printf("5. LIST RECORDS ");

    /* FOLLOWING CODE IS TO BACKUP RECORDS */
    gotoxy(27, 20);
    setcolor(3);
    rectangle(390, 325, 200, 295);
    rectangle(395, 330, 195, 290);
    floodfill(394, 329, 3);
    printf("6. BACKUP DATABASE ");

    /* FOLLOWING IS FOR EXITING SYSTEM */
    gotoxy(27, 23);
    setcolor(3);
    setfillstyle(1, 8);
    rectangle(390, 372, 200, 345);
    rectangle(395, 377, 195, 340);
    floodfill(394, 376, 3);
    printf("7. EXIT SYSTEM ");

    show_mouse();

    while (!kbhit()) {
        draw_screen();
        show_mouse();
        get_mouse();

        if (o.x.bx == 1 && o.x.cx < 395 && o.x.cx > 195 && o.x.dx < 94 && o.x.dx > 50) {
            add_student_record();
            delay(500);
            goto start;
        }

        if (o.x.bx == 1 && o.x.cx < 395 && o.x.cx > 195 && o.x.dx < 140 && o.x.dx > 100) {
            search_student_record();
            goto start;
        }

        if (o.x.bx == 1 && o.x.cx < 395 && o.x.cx > 195 && o.x.dx < 185 && o.x.dx > 146) {
            delete_student_record();
            goto start;
        }

        if (o.x.bx == 1 && o.x.cx < 395 && o.x.cx > 195 && o.x.dx < 234 && o.x.dx > 194) {
            modify_student_record();
            goto start;
        }

        if (o.x.bx == 1 && o.x.cx < 395 && o.x.cx > 195 && o.x.dx < 282 && o.x.dx > 242) {
            list_records();
            delay(1000);
            goto start;
        }

        if (o.x.bx == 1 && o.x.cx < 395 && o.x.cx > 195 && o.x.dx < 330 && o.x.dx > 290) {
            backup_database();
            goto start;
        }

        if (o.x.bx == 1 && o.x.cx < 395 && o.x.cx > 195 && o.x.dx < 377 && o.x.dx > 340) {
            exit_system();
        }
    }

    getch();
    closegraph();
}

void login_window() {
    /* Rectangle for password input */
    setcolor(3);
    setfillstyle(1, WHITE);
    rectangle(426, 288, 201, 259);
    rectangle(425, 287, 202, 260);
    floodfill(419, 262, 3);

    /* RECTANGLE FOR LOGO */
    setcolor(WHITE);
    setfillstyle(10, 4);
    rectangle(402, 142, 224, 222);
    rectangle(403, 141, 223, 223);
    rectangle(404, 140, 222, 224);
    floodfill(400, 218, WHITE);

    /* Draws 1st body */
    setcolor(WHITE);
    setfillstyle(1, 2);
    ellipse(270, 190, 0, 360, 10, 18);
    ellipse(270, 190, 0, 360, 11, 19);
    floodfill(271, 191, WHITE);

    /* Draws and fills 2nd body */
    setfillstyle(1, 2);
    ellipse(300, 195, 0, 360, 10, 18);
    ellipse(300, 195, 0, 360, 9, 17);
    floodfill(301, 196, WHITE);

    /* Draws 3rd body */
    setfillstyle(1, 2);
    ellipse(320, 199, 0, 360, 8, 12);
    ellipse(320, 199, 0, 360, 7, 11);
    floodfill(321, 200, WHITE);

    /* Draws 4th body */
    setfillstyle(1, 2);
    ellipse(340, 190, 0, 360, 11, 25);
    ellipse(340, 190, 0, 360, 10, 24);
    floodfill(341, 191, WHITE);

    /* Draws head for 1st body */
    setcolor(WHITE);
    setfillstyle(1, 2);
    circle(270, 152, 9);
    circle(270, 152, 8);
    floodfill(271, 153, WHITE);

    /* Draws head for 2nd body */
    setcolor(WHITE);
    setfillstyle(1, 2);
    circle(300, 160, 9);
    circle(300, 160, 8);
    floodfill(301, 161, WHITE);

    /* Draws head for 3rd body */
    setcolor(WHITE);
    setfillstyle(1, 2);
    circle(320, 180, 4);
    circle(320, 180, 3);
    floodfill(321, 181, WHITE);

    /* Draws head for 4th body */
    setcolor(WHITE);
    setfillstyle(1, 2);
    circle(340, 152, 9);
    circle(340, 152, 8);
    floodfill(341, 153, WHITE);

    gotoxy(23, 16);
    printf("STUDENT DATABASE MANAGEMENT SYSTEM !");

    /* Draws the circle Enter Button */
    setcolor(WHITE);
    setfillstyle(1, 4);
    circle(442, 272, 12);
    circle(442, 272, 11);
    circle(442, 272, 10);
    floodfill(442, 272, WHITE);
}

void password_input() {
    /* Function to input password */
    char pass[20];
    int i = 0;
    
    gotoxy(23, 21);
    printf("Enter Password: ");
    while ((pass[i] = getch()) != 13) {
        if (pass[i] == 8) { /* Backspace */
            if (i > 0) {
                i--;
                printf("\b \b");
            }
        } else {
            printf("*");
            i++;
        }
    }
    pass[i] = '\0';
    
    if (strcmp(pass, "admin") == 0) {
        clrscr();
        printf("Access Granted!\n");
        delay(1000);
    } else {
        clrscr();
        printf("Access Denied! Try Again.\n");
        delay(1000);
        login_window();
        password_input();
    }
}

void draw_screen() {
    /* Draws the main menu screen */
    setcolor(WHITE);
    setfillstyle(1, BLUE);
    rectangle(0, 0, getmaxx(), getmaxy());
    floodfill(getmaxx() / 2, getmaxy() / 2, WHITE);
}

void initialize_mouse() {
    i.x.ax = 0;
    int86(0x33, &i, &o);
}

void show_mouse() {
    i.x.ax = 1;
    int86(0x33, &i, &o);
}

void get_mouse() {
    i.x.ax = 3;
    int86(0x33, &i, &o);
}

void add_window() {
    setcolor(3);
    settextstyle(12, 0, 1);
    outtextxy(110, 50, "|||***** _ENTER STUDENT DATABASE MANUALLY_ *****|||");

    setcolor(3);
    setfillstyle(1, 8);
    rectangle(570, 400, 60, 100);
    rectangle(571, 401, 59, 99);
    rectangle(590, 420, 40, 80);
    rectangle(591, 421, 39, 79);
    floodfill(579, 418, 3);
}

void add_student_record() {
    char INPUT;
    struct STUDENT S;
    FILE *fp;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\turboc3\\bgi");
    cleardevice();
    draw_screen();
    add_window();

    fp = fopen("C:\\DATABASE.DAT", "a");

    if (fp == NULL) {
        clrscr();
        printf("FILE OPENING ERROR");
        delay(1000);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    fflush(stdin);
    INPUT = 'Y';

    while (INPUT == 'Y' || INPUT == 'y') {
        int gd = DETECT, gm;
        initgraph(&gd, &gm, "C:\\turboc3\\bgi");
        cleardevice();
        draw_screen();
        add_window();
        fflush(stdin);

        gotoxy(10, 8);
        printf("ROLL NO OF STUDENT :: ");
        scanf("%d", &S.ROLL_NO);

        gotoxy(10, 9);
        printf("ENTER FIRST NAME :: ");
        scanf("%s", S.F_NAME);

        gotoxy(10, 10);
        printf("ENTER LAST NAME :: ");
        scanf("%s", S.L_NAME);

        gotoxy(10, 11);
        printf("SEX MALE OR FEMALE :: ");
        scanf("%s", S.SEX);

        gotoxy(10, 12);
        printf("COURSE NAME :: ");
        scanf("%s", S.COURSE_NAME);

        gotoxy(10, 13);
        printf("ADMISSION DATE DD/MM/YY FORMAT :: ");
        gotoxy(49, 13);
        scanf("%d", &S.DAY);
        gotoxy(51, 13);
        printf("/");
        gotoxy(53, 13);
        scanf("%d", &S.MONTH);
        gotoxy(55, 13);
        printf("/");
        gotoxy(56, 13);
        scanf("%d", &S.YEAR);

        fflush(stdin);
        gotoxy(10, 14);
        printf("MOBILE NO :: ");
        scanf("%s", S.MOBILE_NO);

        gotoxy(10, 15);
        printf("FEES PAID :: ");
        scanf("%s", S.FEES);

        gotoxy(10, 16);
        printf("MARKS :: ");
        scanf("%f", &S.MARKS);

        gotoxy(10, 17);
        printf("STREET ADDRESS :: ");
        scanf("%s", S.A.STREET);

        gotoxy(10, 18);
        printf("IM :: ");
        scanf("%s", S.A.IM);

        gotoxy(10, 19);
        printf("CITY :: ");
        scanf("%s", S.A.CITY);

        gotoxy(10, 20);
        printf("COUNTRY :: ");
        scanf("%s", S.A.COUNTRY);

        gotoxy(10, 21);
        printf("PIN CODE :: ");
        scanf("%s", S.A.PIN);

        fwrite(&S, sizeof(S), 1, fp);
        fflush(fp);

        gotoxy(10, 22);
        printf("RECORD ADDED SUCCESSFULLY. DO YOU WANT TO ADD MORE RECORDS? (Y/N): ");
        INPUT = getch();
    }

    fclose(fp);
    clrscr();
    printf("RECORD ADDED SUCCESSFULLY");
    delay(1000);
}

void search_student_record() {
    /* Function to search student records */
    int roll_no;
    struct STUDENT S;
    FILE *fp;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\turboc3\\bgi");
    cleardevice();
    draw_screen();
    add_window();

    fp = fopen("C:\\DATABASE.DAT", "r");

    if (fp == NULL) {
        clrscr();
        printf("FILE OPENING ERROR");
        delay(1000);
        exit(1);
    }

    gotoxy(10, 8);
    printf("ENTER ROLL NO OF STUDENT TO BE SEARCHED :: ");
    scanf("%d", &roll_no);

    while (fread(&S, sizeof(S), 1, fp)) {
        if (S.ROLL_NO == roll_no) {
            gotoxy(10, 10);
            printf("STUDENT RECORD FOUND!");
            gotoxy(10, 11);
            printf("FIRST NAME: %s", S.F_NAME);
            gotoxy(10, 12);
            printf("LAST NAME: %s", S.L_NAME);
            gotoxy(10, 13);
            printf("COURSE NAME: %s", S.COURSE_NAME);
            gotoxy(10, 14);
            printf("SEX: %s", S.SEX);
            gotoxy(10, 15);
            printf("ADMISSION DATE: %d/%d/%d", S.DAY, S.MONTH, S.YEAR);
            gotoxy(10, 16);
            printf("MOBILE NO: %s", S.MOBILE_NO);
            gotoxy(10, 17);
            printf("FEES PAID: %s", S.FEES);
            gotoxy(10, 18);
            printf("MARKS: %.2f", S.MARKS);
            gotoxy(10, 19);
            printf("STREET: %s", S.A.STREET);
            gotoxy(10, 20);
            printf("IM: %s", S.A.IM);
            gotoxy(10, 21);
            printf("CITY: %s", S.A.CITY);
            gotoxy(10, 22);
            printf("COUNTRY: %s", S.A.COUNTRY);
            gotoxy(10, 23);
            printf("PIN CODE: %s", S.A.PIN);
            break;
        }
    }

    if (feof(fp)) {
        gotoxy(10, 10);
        printf("RECORD NOT FOUND!");
    }

    fclose(fp);
    delay(2000);
    clrscr();
}

void display_data() {
    /* Function to display student data */
    struct STUDENT S;
    FILE *fp;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\turboc3\\bgi");
    cleardevice();
    draw_screen();
    add_window();

    fp = fopen("C:\\DATABASE.DAT", "r");

    if (fp == NULL) {
        clrscr();
        printf("FILE OPENING ERROR");
        delay(1000);
        exit(1);
    }

    gotoxy(10, 8);
    printf("STUDENT RECORDS:");

    int row = 10;
    while (fread(&S, sizeof(S), 1, fp)) {
        gotoxy(10, row++);
        printf("ROLL NO: %d", S.ROLL_NO);
        gotoxy(10, row++);
        printf("FIRST NAME: %s", S.F_NAME);
        gotoxy(10, row++);
        printf("LAST NAME: %s", S.L_NAME);
        gotoxy(10, row++);
        printf("COURSE NAME: %s", S.COURSE_NAME);
        gotoxy(10, row++);
        printf("SEX: %s", S.SEX);
        gotoxy(10, row++);
        printf("ADMISSION DATE: %d/%d/%d", S.DAY, S.MONTH, S.YEAR);
        gotoxy(10, row++);
        printf("MOBILE NO: %s", S.MOBILE_NO);
        gotoxy(10, row++);
        printf("FEES PAID: %s", S.FEES);
        gotoxy(10, row++);
        printf("MARKS: %.2f", S.MARKS);
        gotoxy(10, row++);
        printf("STREET: %s", S.A.STREET);
        gotoxy(10, row++);
        printf("IM: %s", S.A.IM);
        gotoxy(10, row++);
        printf("CITY: %s", S.A.CITY);
        gotoxy(10, row++);
        printf("COUNTRY: %s", S.A.COUNTRY);
        gotoxy(10, row++);
        printf("PIN CODE: %s", S.A.PIN);
        gotoxy(10, row++);
        printf("----------------------------");
    }

    if (feof(fp)) {
        gotoxy(10, row);
        printf("NO MORE RECORDS");
    }

    fclose(fp);
    delay(3000);
    clrscr();
}

void delete_student_record() {
    /* Function to delete student record */
    int roll_no;
    struct STUDENT S;
    FILE *fp, *temp_fp;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\turboc3\\bgi");
    cleardevice();
    draw_screen();
    add_window();

    fp = fopen("C:\\DATABASE.DAT", "r");
    temp_fp = fopen("C:\\TEMP.DAT", "w");

    if (fp == NULL || temp_fp == NULL) {
        clrscr();
        printf("FILE OPENING ERROR");
        delay(1000);
        exit(1);
    }

    gotoxy(10, 8);
    printf("ENTER ROLL NO OF STUDENT TO BE DELETED :: ");
    scanf("%d", &roll_no);

    while (fread(&S, sizeof(S), 1, fp)) {
        if (S.ROLL_NO != roll_no) {
            fwrite(&S, sizeof(S), 1, temp_fp);
        }
    }

    fclose(fp);
    fclose(temp_fp);

    remove("C:\\DATABASE.DAT");
    rename("C:\\TEMP.DAT", "C:\\DATABASE.DAT");

    clrscr();
    printf("RECORD DELETED SUCCESSFULLY");
    delay(1000);
}

void modify_student_record() {
    /* Function to modify student record */
    int roll_no;
    struct STUDENT S;
    FILE *fp, *temp_fp;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\turboc3\\bgi");
    cleardevice();
    draw_screen();
    add_window();

    fp = fopen("C:\\DATABASE.DAT", "r");
    temp_fp = fopen("C:\\TEMP.DAT", "w");

    if (fp == NULL || temp_fp == NULL) {
        clrscr();
        printf("FILE OPENING ERROR");
        delay(1000);
        exit(1);
    }

    gotoxy(10, 8);
    printf("ENTER ROLL NO OF STUDENT TO BE MODIFIED :: ");
    scanf("%d", &roll_no);

    while (fread(&S, sizeof(S), 1, fp)) {
        if (S.ROLL_NO == roll_no) {
            gotoxy(10, 10);
            printf("ENTER NEW FIRST NAME :: ");
            scanf("%s", S.F_NAME);

            gotoxy(10, 11);
            printf("ENTER NEW LAST NAME :: ");
            scanf("%s", S.L_NAME);

            gotoxy(10, 12);
            printf("ENTER NEW SEX :: ");
            scanf("%s", S.SEX);

            gotoxy(10, 13);
            printf("ENTER NEW COURSE NAME :: ");
            scanf("%s", S.COURSE_NAME);

            gotoxy(10, 14);
            printf("ENTER NEW ADMISSION DATE DD/MM/YY FORMAT :: ");
            gotoxy(49, 14);
            scanf("%d", &S.DAY);
            gotoxy(51, 14);
            printf("/");
            gotoxy(53, 14);
            scanf("%d", &S.MONTH);
            gotoxy(55, 14);
            printf("/");
            gotoxy(56, 14);
            scanf("%d", &S.YEAR);

            fflush(stdin);
            gotoxy(10, 15);
            printf("ENTER NEW MOBILE NO :: ");
            scanf("%s", S.MOBILE_NO);

            gotoxy(10, 16);
            printf("ENTER NEW FEES PAID :: ");
            scanf("%s", S.FEES);

            gotoxy(10, 17);
            printf("ENTER NEW MARKS :: ");
            scanf("%f", &S.MARKS);

            gotoxy(10, 18);
            printf("ENTER NEW STREET ADDRESS :: ");
            scanf("%s", S.A.STREET);

            gotoxy(10, 19);
            printf("ENTER NEW IM :: ");
            scanf("%s", S.A.IM);

            gotoxy(10, 20);
            printf("ENTER NEW CITY :: ");
            scanf("%s", S.A.CITY);

            gotoxy(10, 21);
            printf("ENTER NEW COUNTRY :: ");
            scanf("%s", S.A.COUNTRY);

            gotoxy(10, 22);
            printf("ENTER NEW PIN CODE :: ");
            scanf("%s", S.A.PIN);
        }
        fwrite(&S, sizeof(S), 1, temp_fp);
    }

    fclose(fp);
    fclose(temp_fp);

    remove("C:\\DATABASE.DAT");
    rename("C:\\TEMP.DAT", "C:\\DATABASE.DAT");

    clrscr();
    printf("RECORD MODIFIED SUCCESSFULLY");
    delay(1000);
}

void list_records() {
    /* Function to list all student records */
    display_data();
}

void backup_database() {
    /* Function to backup database */
    FILE *source_fp, *backup_fp;
    char ch;

    source_fp = fopen("C:\\DATABASE.DAT", "r");
    backup_fp = fopen("C:\\BACKUP.DAT", "w");

    if (source_fp == NULL || backup_fp == NULL) {
        clrscr();
        printf("FILE OPENING ERROR");
        delay(1000);
        exit(1);
    }

    while ((ch = fgetc(source_fp)) != EOF) {
        fputc(ch, backup_fp);
    }

    fclose(source_fp);
    fclose(backup_fp);

    clrscr();
    printf("DATABASE BACKED UP SUCCESSFULLY");
    delay(1000);
}

void exit_system() {
    /* Function to exit the system */
    clrscr();
    printf("Thank you for using the Student Database Management System!");
    delay(2000);
    exit(0);
}