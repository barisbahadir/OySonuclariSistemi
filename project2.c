#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PARTI_SAYISI 5
#define MAKSIMUM_OY_SAYISI 1499

int i,j;

struct partiler
{
    char parti_isim[15];
    char kisa_isim;
    int oy_sayisi;
    float oy_yuzdesi;
    int grafikselOran;

}parti[PARTI_SAYISI],temp;

struct secim
{
    int toplamOySayisi;
}secim2019;

void parti_isimleri()
{
    char isimler[PARTI_SAYISI] = {'A','B','C','D','E'};
//    char uzun_isimler[PARTI_SAYISI] = {'IYIPARTI','MHP','CHP','SAADET','DSP'};

    for(i=0; i<PARTI_SAYISI; i++)
    {
        parti[i].kisa_isim = isimler[i];
    }
}

void randomOySayilari()
{
    for(i=0; i<PARTI_SAYISI; i++)
    {
        parti[i].oy_sayisi = 1+rand()%MAKSIMUM_OY_SAYISI;
        sleep(0.1);
    }
}

int toplamOySayisi()
{
    int toplam_oy;
    for(i=0; i<PARTI_SAYISI; i++)
    {
        secim2019.toplamOySayisi += parti[i].oy_sayisi;
    }
}

void oyYuzdesiHesapla()
{
    for(i=0; i<PARTI_SAYISI; i++)
    {
        parti[i].oy_yuzdesi = (float)(100*parti[i].oy_sayisi)/(secim2019.toplamOySayisi);
    }
}

void partileriSirala()
{

     for(i=0; i<PARTI_SAYISI-1;i++){
        for(j=i+1; j<PARTI_SAYISI; j++){
            if(parti[i].oy_sayisi < parti[j].oy_sayisi){
                temp = parti[i];
                parti[i] = parti[j];
                parti[j] = temp;
            }
        }
    }

    printf("*** KAZANAN PARTI: %c ***\n\n",parti[0].kisa_isim);

}

void secimSonuclariDokumu()
{
    printf("\n");
    for(i=0; i<PARTI_SAYISI; i++)
    {
        printf("[PARTi %c] Aldigi Oy: %d - Oy Yuzdesi: (%.2f)\n",parti[i].kisa_isim,parti[i].oy_sayisi,parti[i].oy_yuzdesi);
    }
}

void secimEkrani()
{
    int j;
    for(i=0; i<PARTI_SAYISI; i++)
    {
        parti[i].grafikselOran = parti[i].oy_yuzdesi * 2;
        printf("PARTI %c = %.2f =>\t",parti[i].kisa_isim,parti[i].oy_yuzdesi);
            for(j=0; j<parti[i].grafikselOran; j++)
            {
                printf("#");
            }
        printf("(%d)\n",parti[i].oy_sayisi);
    }

    printf("\nTOPLAM KULLANILAN OY SAYISI: %d\n",secim2019.toplamOySayisi);
}

void secimSonuclariAcikla()
{
    parti_isimleri();
    randomOySayilari();
    toplamOySayisi();
    oyYuzdesiHesapla();
    partileriSirala();
    secimEkrani();
    secimSonuclariDokumu();
}

int main()
{
    secimSonuclariAcikla();

    return 0;
}
