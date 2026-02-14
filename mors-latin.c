#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
int main() {
    char *morsChars[36][2]={
		{"A",".-"},
		{"B","-..."},
		{"C","-.-."},
		{"D","-.."},
		{"E","."},
		{"F","..-."},
		{"G","--."},
		{"H","...."},
		{"I",".."},
		{"J",".---"},
		{"K","-.-"},
		{"L",".-.."},
		{"M","--"},
		{"N","-."},
		{"O","---"},
		{"P",".--."},
		{"Q","--.-"},
		{"R",".-."},
		{"S","..."},
		{"T","-"},
		{"U","..-"},
		{"V","...-"},
		{"W",".--"},
		{"X","-..-"},
		{"Y","-.--"},
		{"Z","--.."},
		{"0","-----"},
		{"1",".----"},
		{"2","..---"},
		{"3","...--"},
		{"4","....-"},
		{"5","....."},
		{"6","-...."},
		{"7","--..."},
		{"8","---.."},
		{"9","----."},
		}; // Mors karakterleri ve ona karsilik gelen latin harfinin listesi.
    
    char *gelenVeri, // Kullanicinin girdigi karakterleri tutacak.
	*islem; // islem tipini tutacak.
    int i=0,j=0,k=0; // Dongu degiskenleri tanimlandi.
    char kelime[1000][100]={0}; // Kullanicinin girdigi donusturulmus mors kelimelerini tutacak dizi.
    
    gelenVeri=calloc(1000,sizeof(char)); // Kullanicinin girdigi degiskenleri tutacak degiskene daha sonra temizlemek amaciyla 1000 karakterlik alan tahsis edildi.
    
	islem=calloc(1,sizeof(char)); // Kullanici tarafindan girilecek islem tipini tutacak degiskene sonradan silinmek uzere 1 karakterlik alan tahsis edildi.
    
    //Kullaniciya yonlendirmek icin olusturulan ekran ciktilari.
    printf("Dosya uzerinden okumak icin 1'e basin.");
    printf("\nKlavyeden girmek icin 2'ye basin.");
    printf("\n\nLutfen islem tipini seciniz: ");
    
    gets(islem); // Kullanicidan veri aliyor.
    
    if(!strcmp(islem,"1"))
    {
    	FILE * filePointer;  // Acilacak dosyaya ait icerigi tutacak degisken tanimlandi.
    	char dataToBeRead[2], // Dosya icerigini okudukca ilgili karakteri tutacak degisken tanimlandi.
		*dosyaYolu; // Kullanici tarafindan acilmak istenen dosyaya ait yolun tutulacak degisken tanimlandi.
		dosyaYolu=calloc(100,sizeof(char)); // Kullanici tarafindan girilecek dosya yoluna ait degiskene sonradan silinmek uzere 100 karakterlik alan tahsis edildi.
		printf("\nDosya yolunu giriniz: ");
		gets(dosyaYolu); // Kullanicidan icinde mors kodlari olan txt dosyasinin yolu aliniyor.
		printf("\n");
		filePointer = fopen(dosyaYolu, "r"); // Kullanicinin girdigi yoldaki dosya aciliyor.
		free(dosyaYolu); // Dosya yolu icin tahsis edilen 100 karakterlik alan temizlendi. 
		
		if(filePointer==NULL) // Eger ki kullanici hatali veya olmayan bir dosya acmaya calisirsa burada yakalanacak.
			printf("Dosya acilirken bir hata olustu.");
		
		
		while( fgets ( dataToBeRead, 2, filePointer ) != NULL ) // Dosya acildigi takdirde icerisindeki veriler bitene kadar okunacak.
        {
			if(*dataToBeRead==' ') // Kullanicinin yeni bir mors kelimesine basladigini belirten durum.
    		{
        		kelime[j][k]='\0'; // Onceki mors kelimesinin tamamlandigini belirtiyor.
    			k=0; // Sonraki kelimeyi yazmaya baslamak icin imlec basa getiriliyor.
    			j++; // Sonraki kelimeyi tutmak icin dizinin sonraki indisine geciliyor.
			}
			else // Kullanici yeni kelimeye gecmedigi takdirde, mevcut kelimeyi tamamlamak icin calisacak kisim.
			{
				kelime[j][k]=*dataToBeRead; // Kullanicidan alinan karakterler dizinin bir satirinda birlestirilerek bir mors kelimesi haline getiriliyor.
				k++; // Sonraki karakteri basmak icin imlec bir sag sutuna kaydiriliyor.
			}
		}
		
		int len=j; // Dongude kac adet mors kelimesi varsa burada adet sayisini aliyorum. 
		
		for(j=0;j<=len;j++) // Gelen verideki mors kelime sayisi kadar donecek.
		{
			if(j!=0 && kelime[j-1][0]=='\0')
				printf(" ");
				
			for(i=0;i<36;i++) // Baslangita kaydettigimiz tum mors kelimeleri kadar donecek.
			{
				if(!strcmp(kelime[j],morsChars[i][1])) // Gelen verideki mors kelimesi ile baslangicta tanimlanan mors kelimeleri eslestiriliyor.
				{
					printf(morsChars[i][0]); // Gelen veri ile mors baslangicta tanimlanan kelime eslestigi takdirde ilgili kelimeye karsilik gelen karakter ekrana basiliyor.
				}
			}
		}	
		fclose(filePointer);
	}
    else if(!strcmp(islem,"2"))
	{
		printf("\n\nLutfen cevrilecek kelimeyi giriniz:");
    	gets(gelenVeri); // Kullanicidan veri aliyor.
    	
		while(gelenVeri[i]!='\0') // Gelen dizinin icinden veri olan kisim okunuyor.
    	{
    		if(gelenVeri[i]==' ') // Kullanicinin yeni bir mors kelimesine basladigini belirten durum.
    		{
        		kelime[j][k]='\0'; // Onceki mors kelimesinin tamamlandigini belirtiyor.
    			k=0; // Sonraki kelimeyi yazmaya baslamak icin imlec basa getiriliyor.
    			j++; // Sonraki kelimeyi tutmak icin dizinin sonraki indisine geciliyor.
			}
			else // Kullanici yeni kelimeye gecmedigi takdirde, mevcut kelimeyi tamamlamak icin calisacak kisim.
			{
				kelime[j][k]=gelenVeri[i]; // Kullanicidan alinan karakterler dizinin bir satirinda birlestirilerek bir mors kelimesi haline getiriliyor.
				k++; // Sonraki karakteri basmak icin imlec bir sag sutuna kaydiriliyor.
			}
			i++; // Sonraki mors kelimesini okumak icin dongu 1 adim ilerliyor.
		}
		
		
		free(gelenVeri); // gelen veriyi tutmak icin tahsis edilen 1000 karakterlik alan temizlendi.
	
		int len=j; // Dongude kac adet mors kelimesi varsa burada adet sayisini aliyorum. 
		
		for(j=0;j<=len;j++) // Gelen verideki mors kelime sayisi kadar donecek.
		{
			for(i=0;i<36;i++) // Baslangicta kaydettigimiz tum mors kelimeleri kadar donecek.
			{
				if(!strcmp(kelime[j],morsChars[i][1])) // Gelen verideki mors kelimesi ile baslangicta tanimlanan mors kelimeleri eslestiriliyor.
				{
					printf(morsChars[i][0]); // Gelen veri ile mors baslangicta tanimlanan kelime eslestigi takdirde ilgili kelimeye karsilik gelen karakter ekrana basiliyor.
				}
			}
			if(kelime[j][0]=='\0') // Eger dizinin ilgili indisinde bir bosluk var ise 1 karakter bosluk birakiliyor.
			printf(" ");
		}	
	}
	else
		printf("Hatali islem numarasi girdiniz.");
	
    
    
    free(islem); // islemi tutmak icin tahsis edilen 1 karakterlik alan temizlendi.
    return 0;
}




  
