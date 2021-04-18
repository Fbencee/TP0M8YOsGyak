#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>               //el�ford�t� direkt�v�k a futtat�shoz
#include <fcntl.h>
#include <string.h>

int main()
{
    int fd, vissza;
    char buffer[100];               //v�ltoz�k l�trehoz�sa

    buffer[0] = 0;

    fd = open("TP0M8Y.txt", O_RDWR);  //f�jl megnyit�sa opn()-el

    if (fd == -1) {
        perror("Fajl megnyitas [open()] hiba! \n"); //hibaellen�rz�s
        exit(-1);
    }

    vissza = read(fd, buffer, 100);
    printf("A read() %d byteot olvasott.\n\n", vissza);    //read()-el beolvas�s,output ki�r�s
    strcpy(buffer, "TP0M8Y");


    vissza = lseek(fd, 0, SEEK_SET);                             //Iseek() kurzor mozgat�s, output ki�r�s
    printf("Az lseek() beallt a %d. helyre, �s ide ", vissza);

    vissza = write(fd, buffer, 6);                                  //write()-al kurzor adott adat �r�sa, output ki�r�s
    printf("a write() %d byteot irt: %s\n\n", vissza, buffer);
    strcpy(buffer, "TP0M8Y");

    close(fd);                                      //f�jl lez�r�s

    return 0;
}

