#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char alan[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

struct bilgi
{
    char ad[30];
    char soyad[30];
    int galibiyet;

};
struct bilgi oyuncu1;

struct bilgi2
{
    char ad2[30];
    char soyad2[30];
    int galibiyet2;

};
struct bilgi2 oyuncu2;

void oyuncu_bilgi();
int kazananKontrol();
void tablo();

int main()
{
    printf("\n                                        ---Tic Tac Toe Oyununa Hosgeldiniz---                    \n\n");
    oyuncu_bilgi();

    int oyuncu = 1, i, secim;
    int toplamOyunSayisi;

    char isaret;
    do
    {
        tablo();
        oyuncu = (oyuncu % 2) ? 1 : 2;

        printf("Oyuncu %d, 1-9 arasi tablodan sayi girin:  ", oyuncu);
        scanf("%d", &secim);

        isaret = (oyuncu == 1) ? 'X' : 'O';

        if (secim == 1 && alan[1] == '1')
            alan[1] = isaret;

        else if (secim == 2 && alan[2] == '2')
            alan[2] = isaret;

        else if (secim == 3 && alan[3] == '3')
            alan[3] = isaret;

        else if (secim == 4 && alan[4] == '4')
            alan[4] = isaret;

        else if (secim == 5 && alan[5] == '5')
            alan[5] = isaret;

        else if (secim == 6 && alan[6] == '6')
            alan[6] = isaret;

        else if (secim == 7 && alan[7] == '7')
            alan[7] = isaret;

        else if (secim == 8 && alan[8] == '8')
            alan[8] = isaret;

        else if (secim == 9 && alan[9] == '9')
            alan[9] = isaret;

        else
        {
            printf("Gecersiz Hamle! ");

            oyuncu--;
            getch();
        }
        i = kazananKontrol();

        oyuncu++;
    }while (i ==  - 1);

    tablo();

    if (i == 1)
        printf("\nOYUNCU %d KAZANDI! ", --oyuncu);
    else
        printf("\nOYUN BERABERE!");

    getch();

    FILE*fp=fopen("oyuncuBilgisi.txt", "w+");
    if (fp==NULL){
    	printf("Oyuncu Bilgisi dosyasi acilamadi!"); exit(1);}

    	fprintf(fp,"\nOyuncu 1: %s %s\n",oyuncu1.ad,oyuncu1.soyad);
    	fprintf(fp,"\nOyuncu 2: %s %s\n",oyuncu2.ad2,oyuncu2.soyad2);

    	fclose(fp);

    	printf("\nOyuncu 1 in toplam galibiyet sayisi giriniz: ");
    	scanf("%d",&oyuncu1.galibiyet);
        printf("\nOyuncu 2 nin toplam galibiyet sayisi giriniz: ");
    	scanf("%d",&oyuncu2.galibiyet2);
		printf("\nToplam oyun sayisi giriniz: ");
    	scanf("%d",&toplamOyunSayisi);

    	fp=fopen("oyuncuBilgisi.txt", "w");
        fprintf(fp,"\nOyuncu %s %s galibiyet sayisi %d", oyuncu1.ad, oyuncu1.soyad, oyuncu1.galibiyet);
        fprintf(fp,"\nOyuncu %s %s galibiyet sayisi %d", oyuncu2.ad2, oyuncu2.soyad2, oyuncu2.galibiyet2);

    	if(oyuncu1.galibiyet>oyuncu2.galibiyet2){
    		printf("\nToplam oyunlar sonucu kazanan %s %s tebrikler!", oyuncu1.ad, oyuncu1.soyad);
    		fprintf(fp,"\nOyuncu %s %s kazanmistir.", oyuncu1.ad, oyuncu1.soyad);
		}
    	else if(oyuncu1.galibiyet<oyuncu2.galibiyet2){
    		printf("\nToplam oyunlar sonucu kazanan %s %s tebrikler!", oyuncu2.ad2, oyuncu2.soyad2);
    		fprintf(fp,"\nOyuncu %s %s kazanmistir.", oyuncu2.ad2, oyuncu2.soyad2);
		}
    	else{
    		printf("\nToplam oyunlar sonucu beraberlik olmustur.");
    		fprintf(fp,"\nOyun berabere bitmistir.");
		}

    	return 0;

}


void oyuncu_bilgi()
 {
     printf("Oyuncu 1 ad ve soyadini giriniz: ");
     scanf ("%s %s",oyuncu1.ad,oyuncu1.soyad);

     printf("\nOyuncu 2 ad ve soyadini giriniz: ");
     scanf ("%s %s",oyuncu2.ad2,oyuncu2.soyad2);

 }

int kazananKontrol()
{
    if (alan[1] == alan[2] && alan[2] == alan[3])
        return 1;

    else if (alan[4] == alan[5] && alan[5] == alan[6])
        return 1;

    else if (alan[7] == alan[8] && alan[8] == alan[9])
        return 1;

    else if (alan[1] == alan[4] && alan[4] == alan[7])
        return 1;

    else if (alan[2] == alan[5] && alan[5] == alan[8])
        return 1;

    else if (alan[3] == alan[6] && alan[6] == alan[9])
        return 1;

    else if (alan[1] == alan[5] && alan[5] == alan[9])
        return 1;

    else if (alan[3] == alan[5] && alan[5] == alan[7])
        return 1;

    else if (alan[1] != '1' && alan[2] != '2' && alan[3] != '3' && alan[4] != '4' && alan[5] != '5' && alan[6] != '6' && alan[7] != '7' && alan[8] != '8' && alan[9] != '9')

        return 0;
    else
        return -1;
}

void tablo()
{
    system("cls");
    printf("\n                                        ---Tic Tac Toe Oyununa Hosgeldiniz---                    \n\n");

    printf("Oyuncu 1 (X)  -  Oyuncu 2 (O)\n\n\n");


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", alan[1], alan[2], alan[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", alan[4], alan[5], alan[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", alan[7], alan[8], alan[9]);

    printf("     |     |     \n\n");
}
