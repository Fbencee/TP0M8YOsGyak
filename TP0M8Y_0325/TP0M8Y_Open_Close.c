#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>               //elõfordító direktívák a futtatáshoz
#include <fcntl.h>
#include <string.h>

int main()
{
    int fd, vissza;
    char buffer[100];               //változók létrehozása

    buffer[0] = 0;

    fd = open("TP0M8Y.txt", O_RDWR);  //fájl megnyitása opn()-el

    if (fd == -1) {
        perror("Fajl megnyitas [open()] hiba! \n"); //hibaellenõrzés
        exit(-1);
    }

    vissza = read(fd, buffer, 100);
    printf("A read() %d byteot olvasott.\n\n", vissza);    //read()-el beolvasás,output kiírás
    strcpy(buffer, "TP0M8Y");


    vissza = lseek(fd, 0, SEEK_SET);                             //Iseek() kurzor mozgatás, output kiírás
    printf("Az lseek() beallt a %d. helyre, és ide ", vissza);

    vissza = write(fd, buffer, 6);                                  //write()-al kurzor adott adat írása, output kiírás
    printf("a write() %d byteot irt: %s\n\n", vissza, buffer);
    strcpy(buffer, "TP0M8Y");

    close(fd);                                      //fájl lezárás

    return 0;
}

