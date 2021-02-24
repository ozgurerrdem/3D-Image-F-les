#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
struct Nokta
{
    float x;
    float y;
    float z;

    int r;
    int g;
    int b;
} Nokta[100000];
struct yakinuzak
{
    float yakinx;
    float yakiny;
    float yakinz;
    float uzakx;
    float uzaky;
    float uzakz;

} yakinuzak[100];
struct yakinuzak2
{
    float x;
    float y;
    float z;


} yakinuzak2[100];
struct kup
{
    float x;
    float y;
    float z;


} kup[8];

int main()
{
    int etiket=0;
LOOP:
    etiket;
    float kupmerkez[3],enbx=Nokta[0].x,enby=Nokta[0].y,enbz=Nokta[0].z;
    int sayac=0;
    double enb=0,enk=10000;
    double formul;
    double sonuzaklik[1000];
    double toplam1=0,sayac1=0;
    int buyuksira[2];
    int kucuksira[2];
    char dosyauzantisi[4]=".nkt";
    char kontrol[4];
    int boyut=0;
    char rgbkontrol[]="r g b";
    char kontroldizisi[5];
    int boyutkontroldizisi=0;
    char baslikbilgileri[5][25];//Baslik bilgileri
    int satir=0;
    double cx,cy,cz,r,formul2,yoksa=0;
    double cemberuzaklik[10000];
    int secim=0;
    char dosyaismi[50];
    double ort;



    printf("Dosyanin Adini Giriniz: ");
    scanf("%s",dosyaismi);
    printf("1)Dosya Kontrolu\n");
    printf("2)En Yakin/Uzak Noktalar\n");
    printf("3)Tum Noktalari Icine Alan Kupun Kose Bilgileri\n");
    printf("4)Bilgilerini Gireceginiz Kurenin Icinde Kalan Noktalar\n");
    printf("5)Noktalarin Birbirine Olan Uzakliklarinin Ortalamasi\n");
    printf("6)Yeni dosya oku\n");
    printf("7)Cikis \n\n");
    printf("Seciminiz: ");
    scanf("%d",&secim);
    FILE *dosya=fopen(dosyaismi,"r");
    FILE *output=fopen("output.nkt","a");

    if((dosya=fopen(dosyaismi,"r"))!=NULL)
    {

        for(int i=0 ; i <5 ; i++)
        {
            fgets(baslikbilgileri[i],25,dosya);
            //printf("%s",baslikbilgileri[i]);
        }
    }

    for(int i=14 ; i<19 ; i++)
    {
        kontroldizisi[boyutkontroldizisi]=baslikbilgileri[2][i];
        boyutkontroldizisi++;
    }
    //Noktalari diziye atma
    if(strncmp(kontroldizisi,rgbkontrol,3)==0)
    {
        char line[128];
        while(fgets(line,sizeof line,dosya)!=NULL)
        {
            char *pointer;
            int uzunluk=0;
            pointer=strtok(line," ");
            if(satir>=5)
            {
                Nokta[satir].x=atof(pointer);
            }
            while(pointer!=NULL)
            {
                uzunluk++;
                pointer= strtok(NULL," ");
                if(satir>=5)
                {
                    if(uzunluk==1)
                    {

                        Nokta[satir].y=atof(pointer);
                    }


                    else if(uzunluk==2)
                    {
                        Nokta[satir].z=atof(pointer);
                    }
                    else if (uzunluk==3)
                    {
                        Nokta[satir].r=atoi(pointer);
                    }
                    else if(uzunluk==4)
                    {
                        Nokta[satir].g=atoi(pointer);
                    }
                    else if (uzunluk==5)
                    {
                        Nokta[satir].b=atoi(pointer);
                    }

                }
            }
            if(satir>=5)
            {
                //printf("%f\n",Nokta[satir].x);
            }

            satir++;
            if(satir>5 && uzunluk!=6)
            {
                printf("%d. Satirda Hata Var\n",satir);
            }
        }

    }
    else
    {
        char line[128];
        while(fgets(line,sizeof line,dosya)!=NULL)
        {
            char *pointer;
            int uzunluk=0;
            pointer=strtok(line," ");
            if(satir>=5)
            {
                Nokta[satir].x=atof(pointer);
            }
            while(pointer!=NULL)
            {
                uzunluk++;
                pointer= strtok(NULL," ");
                if(satir>=5)
                {
                    if(uzunluk==1)
                    {
                        Nokta[satir].y=atof(pointer);
                    }
                    else if (uzunluk==2)
                    {
                        Nokta[satir].z=atof(pointer);
                    }



                }
            }
            if(satir>=5)
            {
                //printf("%f\n",Nokta[satir].x);
            }

            satir++;
            if(satir>5 && uzunluk!=3)
            {
                printf("%d. Satirda Hata Var\n",satir);
            }
        }
    }
    for(int i=5 ; i<satir; i++)
    {
        for(int j=i+1; j<satir; j++)
        {


            formul=pow((Nokta[i].x)-(Nokta[j].x),2)+pow((Nokta[i].y)-(Nokta[j].y),2)+pow((Nokta[i].z)-(Nokta[j].z),2);
            sonuzaklik[sayac]=sqrt(formul);

            if(enk>sonuzaklik[sayac])
            {
                enk=sonuzaklik[sayac];
                yakinuzak[0].yakinx=Nokta[i].x;
                yakinuzak[0].yakiny=Nokta[i].y;
                yakinuzak[0].yakinz=Nokta[i].z;
                kucuksira[0]=i+1;
                yakinuzak[1].yakinx=Nokta[j].x;
                yakinuzak[1].yakiny=Nokta[j].y;
                yakinuzak[1].yakinz=Nokta[j].z;
                kucuksira[1]=j+1;
            }
            if(enb<sonuzaklik[sayac])
            {
                enb=sonuzaklik[sayac];
                yakinuzak[0].uzakx=Nokta[i].x;
                yakinuzak[0].uzaky=Nokta[i].y;
                yakinuzak[0].uzakz=Nokta[i].z;
                buyuksira[0]=i+1;
                yakinuzak[1].uzakx=Nokta[j].x;
                yakinuzak[1].uzaky=Nokta[j].y;
                yakinuzak[1].uzakz=Nokta[j].z;
                buyuksira[1]=j+1;
            }
            if(sayac==1001)
            {
                sayac=0;


            }

            toplam1+=sonuzaklik[sayac];
            //printf("%lf\n",sonuzaklik[sayac]);

            sayac1++;
            sayac++;

        }
    }

    while (secim<7 && secim>0)
    {

        switch(secim)
        {
        case 1:

            //Dosya uzantisi kontrolü
            fputs("SECIM 1\n",output);

            for(int k=strlen(dosyaismi)-4 ; k<strlen(dosyaismi) ; k++)
            {
                kontrol[boyut]=dosyaismi[k];
                boyut++;
            }

            if(strncmp(kontrol,dosyauzantisi,4)==0)
            {
                printf("\nDosya Uzantisi Dogrudur\n");
                fputs("Dosya Uzantisi Dogrudur\n",output);
            }
            else
            {
                printf("\nDosya Uzantisi .nkt Degildir\n");
                fputs("Dosya Uzantisi .nkt Degildir\n",output);
                exit(0);
            }
            //Baslik bilgisinde rgb kontrolu

            if((dosya=fopen(dosyaismi,"r"))!=NULL)
            {

                for(int i=0 ; i <5 ; i++)
                {
                    fgets(baslikbilgileri[i],25,dosya);
                    //printf("%s",baslikbilgileri[i]);
                }
            }

            for(int i=14 ; i<19 ; i++)
            {
                kontroldizisi[boyutkontroldizisi]=baslikbilgileri[2][i];
                boyutkontroldizisi++;
            }
            //Baslik bilgisindeki nokta sayisi dogru mu kontrolu
            int noktasayisikontrolu=baslikbilgileri[3];
            char *ayrac=" ";
            char *noktalar=strtok(noktasayisikontrolu,ayrac);
            char *noktasayisi=strtok(NULL,ayrac);
            // printf("%s\n",noktasayisi);

            if(atoi(noktasayisi)==satir)
            {
                printf("Basliktaki Verilen Nokta Sayisi ile Dosyadaki Nokta Sayisi Esittir.");
                fputs("Basliktaki Verilen Nokta Sayisi ile Dosyadaki Nokta Sayisi Esittir.\n",output);
            }
            else
            {
                printf("Basliktaki Verilen Nokta Sayisi ile Dosyadaki Nokta Sayisi Esit Degildir.");
                fputs("Basliktaki Verilen Nokta Sayisi ile Dosyadaki Nokta Sayisi Esit Degildir.\n",output);
                exit(0);
            }


            break;


        case 2:


            //Noktalar arasý uzaklýk hesaplama
            fputs("\nSECIM 2\n",output);
            printf("\nEn Yakin Noktalar:\n");
            fputs("En Yakin Noktalar:\n",output);
            for(int i=0; i<2; i++)
            {
                printf("%d. nokta %f %f %f\n",kucuksira[i],yakinuzak[i].yakinx,yakinuzak[i].yakiny,yakinuzak[i].yakinz);
                fprintf(output,"%d. nokta %f %f %f\n",kucuksira[i],yakinuzak[i].yakinx,yakinuzak[i].yakiny,yakinuzak[i].yakinz);
            }
            printf("En Uzak Noktalar:\n");
            fputs("En Uzak Noktalar:\n",output);
            for(int i=0; i<2; i++)
            {
                printf("%d. nokta %f %f %f\n",buyuksira[i],yakinuzak[i].uzakx,yakinuzak[i].uzaky,yakinuzak[i].uzakz);
                fprintf(output,"%d. nokta %f %f %f\n",buyuksira[i],yakinuzak[i].uzakx,yakinuzak[i].uzaky,yakinuzak[i].uzakz);
            }

            break;


        case 3:
            // Kup hesaplari
            for(int i=1; i<satir; i++)
            {
                if(Nokta[i].x>enbx)
                {
                    enbx=Nokta[i].x;
                }
                if(Nokta[i].y>enby)
                {
                    enby=Nokta[i].y;
                }
                if(Nokta[i].z>enbz)
                {
                    enbz=Nokta[i].z;
                }
            }
            kupmerkez[0]=enbx/2;
            kupmerkez[1]=enby/2;
            kupmerkez[2]=enbz/2;
            float farkx=0;
            float farky=0;
            float farkz=0;

            for(int i=0; i<satir; i++)
            {
                for(int j=i+1; j<satir; j++)
                {
                    if(fabs((Nokta[i].x)-(Nokta[j].x))>farkx)
                    {
                        farkx=fabs((Nokta[i].x)-(Nokta[j].x));
                    }
                    if(fabs((Nokta[i].y)-(Nokta[j].y))>farky)
                    {
                        farky=fabs((Nokta[i].y)-(Nokta[j].y));
                    }
                    if(fabs((Nokta[i].z)-(Nokta[j].z))>farkz)
                    {
                        farkz=fabs((Nokta[i].z)-(Nokta[j].z));
                    }
                }
            }

            float xayrityari=farkx/2;
            float yayrityari=farky/2;
            float zayrityari=farkz/2;

            kup[0].x=kupmerkez[0]+xayrityari;
            kup[0].y=kupmerkez[1]+yayrityari;
            kup[0].z=kupmerkez[2]+zayrityari;

            kup[1].x=kupmerkez[0]+xayrityari;
            kup[1].y=kupmerkez[1]+yayrityari;
            kup[1].z=kupmerkez[2]-zayrityari;

            kup[2].x=kupmerkez[0]+xayrityari;
            kup[2].y=kupmerkez[1]-yayrityari;
            kup[2].z=kupmerkez[2]-zayrityari;

            kup[3].x=kupmerkez[0]+xayrityari;
            kup[3].y=kupmerkez[1]-yayrityari;
            kup[3].z=kupmerkez[2]+zayrityari;

            kup[4].x=kupmerkez[0]-xayrityari;
            kup[4].y=kupmerkez[1]-yayrityari;
            kup[4].z=kupmerkez[2]+zayrityari;

            kup[5].x=kupmerkez[0]-xayrityari;
            kup[5].y=kupmerkez[1]-yayrityari;
            kup[5].z=kupmerkez[2]-zayrityari;

            kup[6].x=kupmerkez[0]-xayrityari;
            kup[6].y=kupmerkez[1]+yayrityari;
            kup[6].z=kupmerkez[2]-zayrityari;

            kup[7].x=kupmerkez[0]-xayrityari;
            kup[7].y=kupmerkez[1]+yayrityari;
            kup[7].z=kupmerkez[2]+zayrityari;
            printf("\nKupun Koseleri:\n\n");
            fputs("\nSECIM 3\nKupun Koseleri:\n",output);
            for(int i=0; i<8; i++)
            {
                printf("%d. Kose= x:%f y:%f z:%f\n",i+1,kup[i].x,kup[i].y,kup[i].z);
                fprintf(output,"%d. Kose= x:%f y:%f z:%f\n",i+1,kup[i].x,kup[i].y,kup[i].z);
            }


            break;

        case 4:
            //küre ile ilgili hesaplamalar

            printf("Merkezin X Koordinatini Giriniz: ");
            scanf("%lf",&cx);
            fprintf(output,"\nSECIM 4\nX:%lf",cx);
            printf("Merkezin Y Koordinatini Giriniz: ");
            scanf("%lf",&cy);
            fprintf(output,"\nY:%lf",cy);
            printf("Merkezin Z Koordinatini Giriniz: ");
            scanf("%lf",&cz);
            fprintf(output,"\nZ:%lf",cz);
            printf("Merkezin Yaricapini Giriniz: ");
            scanf("%lf",&r);
            fprintf(output,"\nr:%lf",r);
            printf("Kurenin Icindeki Noktalar:\n");
            fputs("\nKurenin Icindeki Noktalar:\n",output);
            for(int i=0; i<satir; i++)
            {
                formul2=sqrt(pow((cx-Nokta[i].x),2)+pow((cy-Nokta[i].y),2)+pow((cz-Nokta[i].z),2));

                if(formul2<=r)
                {
                    printf("%d. Nokta: %lf %lf %lf\n",i+1,Nokta[i].x,Nokta[i].y,Nokta[i].z);
                    fprintf(output,"%d. Nokta: %lf %lf %lf\n",i+1,Nokta[i].x,Nokta[i].y,Nokta[i].z);
                    yoksa=1;

                }
            }
            if(yoksa!=1)
            {
                printf("Kurenin Icinde Nokta Yoktur!\n\n");
                fputs("Kurenin Icinde Nokta Yoktur!",output);
            }

            break;
        case 5:
            //ortalama hesaplama
            ort=toplam1/sayac1;
            printf("\nNoktalarin Birbirlerine Olan Uzakliklarinin Ortalamasi: %lf'dir\n",ort);
            fprintf(output,"\nSECIM 5\nNoktalarin Birbirlerine Olan Uzakliklarinin Ortalamasi: %lf'dir\n\n",ort);
            break;

        case 6:
            goto LOOP;
            break;



        }
        printf("\n\n1)Dosya Kontrolu\n");
        printf("2)En Yakin/Uzak Noktalar\n");
        printf("3)Tum Noktalari Icine Alan Kupun Kose Bilgileri\n");
        printf("4)Bilgilerini Gireceginiz Kurenin Icinde Kalan Noktalar\n");
        printf("5)Noktalarin Birbirine Olan Uzakliklarinin Ortalamasi\n");
        printf("6)Yeni dosya oku\n");
        printf("7)Cikis\n\n");
        printf("Seciminiz: ");
        scanf("%d",&secim);


    }

    fopen(dosyaismi,"a");
    fclose(dosya);
    fclose(output);
    return 0;
}
