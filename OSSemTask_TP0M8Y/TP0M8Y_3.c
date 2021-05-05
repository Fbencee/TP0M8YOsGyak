#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

/*
3. Irjon C nyelvu programot, ami:
    letrehoz ket gyermekprocesszt
    ezek a gyermekprocesszek letrehoznak 3-3 tovabbi gyereket
    ezek az unokak varakoznak nehany masodpercet es szunjenek meg
    a szulok varjak meg a gyerekek befejezodeset es csak utana szunjenek meg

*/

int main()
{
    printf("Szülő vagyok\n");

    for(int i = 0; i < 2;i++) // ciklus amiben létrehozzuk a 2 gyereket
    {
        if(fork() == 0) // Gyermek processz létrehozása, és amennyiben a fork() visszatérési értéke 0 (azaz a gyermek processzben vagyunk) lefutnak az if-ben leírtak
        {
            printf("Gyerek vagyok!\n");

            for(int i = 0; i < 3 ;i++) // ciklus amiben létrehozzuk az unokákat
            {
                if(fork() == 0) //Gyermek (Unoka) processz létrehozása, és amennyiben a fork() visszatérési értéke 0 (azaz a gyermek processzben vagyunk) lefutnak az if-ben leírtak
                {
                    printf("Unoka vagyok!\n");
                    sleep(5); // 5 másodperces várakozás, mielőtt meghalnak az unokák
                    printf("Unoka halott!\n");
                    return 0;
                }
            }

            wait(NULL); // Várakozás az unokákra
            printf("Gyerek halott!\n");    
            return 0;
            
        }      
    }
    
    wait(NULL); // Várakozás a gyerekekre
    printf("Szülő halott!\n");

    return 0;
}