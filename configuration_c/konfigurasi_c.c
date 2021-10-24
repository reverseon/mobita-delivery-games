#include "charmachine.h"
#include "konfigurasi_c.h"
#include <stdlib.h>

jumlahPesanan* konfigurasiC(int* arrlen)
{
    int t;
    start();
    t = 0;
    while(true)
    {
        adv();
        if (currentChar!='\n')
        {
            t = t * 10;
            t += (currentChar - '0');
        }
        else
        {
            break;
        }
    }

    jumlahPesanan* array = malloc(sizeof(jumlahPesanan)*t);
    int len = t;
    int index = 0;

    while(t--)
    {
        array[index].time = 0;
        while(true)
        {
            adv();
            if (currentChar!= ' ')
            {
                array[index].time = array[index].time * 10;
                array[index].time += (currentChar - '0');
            }
            else
            {
                break;
            }
        }

        adv();
        array[index].pickup = currentChar;

        adv();
        adv();
        array[index].dropoff = currentChar;

        adv();
        adv();
        array[index].itemtype = currentChar;

        adv();
        if (array[index].itemtype=='P')
        {
            array[index].timelimit = 0;
            while(true)
            {
                adv();
                if (currentChar!= '\n')
                {
                    array[index].timelimit = array[index].timelimit * 10;
                    array[index].timelimit += (currentChar - '0');
                }
                else
                {
                    break;
                }
            }
        }
        /// Apabila bukan perishable ditandai dengan -1 biar gampang aja
        else
        {
            array[index].timelimit = -1;
        }

        index += 1;
    }

    *arrlen = len;
    return array;
}
