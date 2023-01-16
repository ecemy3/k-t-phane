#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct kitap
{
    char ad[20];
    char yazar[20];
    char konu[30];
    int fiyat;
    int sayfa_sayisi;
    char yayinevi[20];
    int stok;
};

void hazir_kitaplari_ekle(struct kitap *kitap_pointer,int *mevcut_kitap_sayisi)
{

    char kitaplar_i[4][20] = {"Sefiller","Mai ve Siyah","Satranc","345 Ayt Mat"};
    char kitaplar_y[4][20] = {"Victor Hugo","Halit Ziya","Stefen Zweig","Mehmet Kivrak"};
    char kitaplar_k[4][30] = {"Sefil Insanlar","Mavi ve siyahin aski","Satranc oynayan insan","Mat Sorulari"};
    int fiyats[] = {30,45,10,250};
    int sayfa_sayilari[] = {150,200,60,350};
    char yayinevleri[4][20] = {"bkm","is bankasi","epsilon","palme"};
    int stoks[] = {23,12,20,15};

    for(int i = 0; i<4; i++)
    {
        struct kitap kitabim;
        strcpy(kitabim.ad,kitaplar_i[i]);
        strcpy(kitabim.yazar,kitaplar_y[i]);
        strcpy(kitabim.konu,kitaplar_k[i]);
        kitabim.fiyat = fiyats[i];
        kitabim.sayfa_sayisi = sayfa_sayilari[i];
        strcpy(kitabim.yayinevi,yayinevleri[i]);
        kitabim.stok = stoks[i];
        *kitap_pointer = kitabim;
        kitap_pointer++;
        *mevcut_kitap_sayisi = *mevcut_kitap_sayisi+1;
    }
}

void kitaplari_yazdir(int *mevcut_kitap_sayisi,struct kitap kitaplar[40])
{
    int i;
    char tablo_basi[] = "|Kitap Adi          | |Kitap Yazari          | |Kitap Yayinevi          | |Kitap Fiyati          | |Sayfa Sayisi          | |Kitabin Konusu          | |Kitabin Stogu          |\n";
    for(i=0; i<strlen(tablo_basi)-1; i++)
    {
        printf("-");
    }
    printf("\n");

    printf("%s",tablo_basi);
    for(i=0; i<strlen(tablo_basi)-1; i++)
    {
        printf("-");
    }
    printf("\n");


    for(i=0; i<*mevcut_kitap_sayisi; i++)
    {

        printf("|%s",kitaplar[i].ad);
        for(int j=0; j<19-strlen(kitaplar[i].ad); j++)
        {
            printf(" ");
        }

        printf("| |");
        printf("%s",kitaplar[i].yazar);
        for(int j = 0; j<22-strlen(kitaplar[i].yazar); j++)
        {
            printf(" ");
        }

        printf("| |");
        printf("%s",kitaplar[i].yayinevi);
        for(int j = 0; j<24-strlen(kitaplar[i].yayinevi); j++)
        {
            printf(" ");
        }

        printf("| |");
        printf("%d TL",kitaplar[i].fiyat);
        for(int j = 0; j<19-basamak_sayisi((int)kitaplar[i].fiyat); j++)
        {
            printf(" ");
        }

        printf("| |");
        printf("%d Sayfa",kitaplar[i].sayfa_sayisi);
        for(int j = 0; j<16-basamak_sayisi((int)kitaplar[i].sayfa_sayisi); j++)
        {
            printf(" ");
        }

        printf("| |");
        printf("%s",kitaplar[i].konu);
        for(int j = 0; j<24-strlen(kitaplar[i].konu); j++)
        {
            printf(" ");
        }

        printf("| |");
        printf("%d Tane",kitaplar[i].stok);
        for(int j = 0; j<18-basamak_sayisi((int)kitaplar[i].stok); j++)
        {
            printf(" ");
        }

        printf("|\n");
    }
    for(i=0; i<strlen(tablo_basi)-1; i++)
    {
        printf("-");
    }
    printf("\n\n\n");

}


int basamak_sayisi(int sayi)
{
    int basamak = 0;

    while(sayi > 0)
    {
        sayi = sayi / 10;
        basamak++;
    }
    return basamak;
}

int main()
{
    system("color a");
    int kitap_sayisi = 0;
    int i,j;
    int mevcut_kitap_sayisi = 0;
    char siralama[10];

    struct kitap kitaplar[40];

    hazir_kitaplari_ekle(&kitaplar[0],&mevcut_kitap_sayisi);
    int islem = 0;


    do
    {
        printf("1. Kitap Ekle\n2. Kitaplari Goster\n3. Kitap Sirala\n4. cikis\nIslemi giriniz:");
        scanf("%d",&islem);

        switch(islem)
        {
        case 1:

            printf("Kac kitap giriceksin : ");
            scanf("%d",&kitap_sayisi);

            for(i = 0; i<kitap_sayisi; i++)
            {

                struct kitap kitapim;

                fflush(stdin);

                printf("%d. kitabin adi : ",i+1);
                gets(kitapim.ad);

                fflush(stdin);

                printf("%d. kitabin yazari : ",i+1);
                gets(kitapim.yazar);

                fflush(stdin);

                printf("%d. kitabin konusu : ",i+1);
                gets(kitapim.konu);

                fflush(stdin);

                printf("%d. kitabin fiyati : ",i+1);
                scanf("%d",&kitapim.fiyat);

                fflush(stdin);

                printf("%d. kitabin sayfa sayisi : ",i+1);
                scanf("%d",&kitapim.sayfa_sayisi);

                fflush(stdin);

                printf("%d. kitabin yayinevi : ",i+1);
                gets(kitapim.yayinevi);

                fflush(stdin);

                printf("%d. kitabin stogu : ",i+1);
                scanf("%d",&kitapim.stok);

                fflush(stdin);

                kitaplar[mevcut_kitap_sayisi] = kitapim;
                mevcut_kitap_sayisi++;
            }

            printf("Kitap Basariyla Eklendi...\n\n");

            break;
        case 2:
            kitaplari_yazdir(&mevcut_kitap_sayisi,&kitaplar[0]);
            break;

        case 3:
            printf("\nKitaplari neye gore siralayacaksiniz(stok,fiyat,sayfa) : ");
            scanf("%s",&siralama);

            if(strcmp(siralama,"stok")==0)
            {
                for(i=0; i<mevcut_kitap_sayisi-1; i++)
                {
                    for(j=0; j<mevcut_kitap_sayisi-1-i; j++)
                    {
                        if(kitaplar[j].stok<kitaplar[j+1].stok)
                        {
                            struct kitap kitabim = kitaplar[j];
                            kitaplar[j] = kitaplar[j+1];
                            kitaplar[j+1] = kitabim;
                        }
                    }
                }
                kitaplari_yazdir(&mevcut_kitap_sayisi,&kitaplar[0]);
            }
            if(strcmp(siralama,"fiyat")==0)
            {
                for(i=0; i<mevcut_kitap_sayisi-1; i++)
                {
                    for(j=0; j<mevcut_kitap_sayisi-1-i; j++)
                    {
                        if(kitaplar[j].fiyat<kitaplar[j+1].fiyat)
                        {
                            struct kitap kitabim = kitaplar[j];
                            kitaplar[j] = kitaplar[j+1];
                            kitaplar[j+1] = kitabim;
                        }
                    }
                }
                kitaplari_yazdir(&mevcut_kitap_sayisi,&kitaplar[0]);
            }
            if(strcmp(siralama,"sayfa")==0)
            {
                for(i=0; i<mevcut_kitap_sayisi-1; i++)
                {
                    for(j=0; j<mevcut_kitap_sayisi-1-i; j++)
                    {
                        if(kitaplar[j].sayfa_sayisi<kitaplar[j+1].sayfa_sayisi)
                        {
                            struct kitap kitabim = kitaplar[j];
                            kitaplar[j] = kitaplar[j+1];
                            kitaplar[j+1] = kitabim;
                        }
                    }
                }
                kitaplari_yazdir(&mevcut_kitap_sayisi,&kitaplar[0]);
            }
            break;
        }

    }
    while(1);
    return 0;
}
