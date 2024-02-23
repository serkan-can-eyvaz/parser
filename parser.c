#include<stdio.h>                                                                                          // Serkan Can EYVAZ 02210224021
#include<stdlib.h> 
#include<string.h>
int main(){
	char dizi[100];
	char dosyaName[100];
	printf("dosya adini giriniz:");//Dosya adýný kullanýcýdan aldýk
	gets(dosyaName);
    FILE *dosya=fopen(dosyaName,"r");	
	int i=0;
	printf ("kaynak kod:\n");
	while(!feof(dosya)){
		fscanf(dosya,"%c",&dizi[i]);//dosyayý dizide tuttuk
		printf("%c",dizi[i]);//Kaynak kodu ekrana yazdýrdýk
		i++;		 
	}
	fclose(dosya);
	int j=0,x=0,m=0;
	char dizi2[500][10];
	char token[100];
	printf("\n\nkelimelestirme:\n");//Tokenizer ile kelimeliþtirmeyi ekrana yazdýrdýk
	while(j<i)
	{
		if(dizi[j]!=(int)10)
		{
			if(dizi[j] == (int)32 || dizi[j] == (int)44 || dizi[j] == (int)91 || dizi[j] == (int)93 ||dizi[j] == (int)58)//Ayraclarý kontrol ettik("," ":" "[]" " ") 
			{
				printf(" ");// ekran çýktýsýnda kelimeler arasýna birer boþluk býraktýk
			}
			else
			{
				token[j]=dizi[j];//dizide tuttuðumuz dosyayý token aktraýp ekran bastýrdýk
				printf("%c",token[j]);
			}
			
		}
		else
		{
			printf(" ");
		}
		j++;
		
	}
	
	printf("\n\nParser:\n");//gramer kurallarýnýn kontrolü
	j=0;
	while (j< i)
	{
		if (
		 dizi[j]!= (int)32 && // ayraclarýn kontrolünü yaptýk
		 dizi[j]!= (int)44 &&
		 dizi[j]!= (int)91 && 
		 dizi[j]!= (int)93 && 
		 dizi[j]!= (int)10 && 
		 dizi[j]!= (int)58  )
		
		{
			dizi2[x][m]=dizi[j];// kaynak kodumuzu tutan diziyi yeni dizimize aktardýk
			m++;// satýrý her döngüde artýrdýk
			j++;//döngüyü ilerlettik
		}
		else
		{
			switch(m)//kontolün gerçekleþemesi için satýrý kullandýk
			{
				case 1://tek boyutlular için kontrol
					m=0;//en baþtan gramer kontrolü yapmak için ilerlemiþ m deðerimizi sýfýrladýk
					if(dizi2[x][m]<(int)57 && dizi2[x][m]>(int)48)//1-9 arasý sabitlerin kontrolü
					{
						
					}
					else
					{
						printf("hatali kod");
						return;
					}
					
					break;
				case 2://2 boyutlular için kontrol
					m=0;
					
					if(dizi2[x][m]<=(int)57&&dizi2[x][m]>(int)48&&dizi2[x][m+1]<=(int)57&&dizi2[x][m+1]>48)//10--99 arasý sabitlerin kontrolü
					{
						
					}						
					else if(dizi2[x][m]==(int)68 && dizi2[x][m+1]==(int)83);	//DS					
					else if(dizi2[x][m]==(int)68 && dizi2[x][m+1]==(int)75);	//DK					
					else if(dizi2[x][m]==(int)68 && dizi2[x][m+1]==(int)66);	//DB				
					else if(dizi2[x][m]==(int)86 && dizi2[x][m+1]==(int)69);	//VE				
					else if(dizi2[x][m]==(int)65 && dizi2[x][m+1]==(int)88);	//AX			
					else if(dizi2[x][m]==(int)66 && dizi2[x][m+1]==(int)88);	//BX				
					else if(dizi2[x][m]==(int)67 && dizi2[x][m+1]==(int)88);	//CX
					else if(dizi2[x][m]==(int)68 && dizi2[x][m+1]==(int)88);	//DX				
					else
					{
						printf("Hatali kod 1");
						return;
					}
					break;
				case 3://3 boyutlular için kontrol
					m=0;
					if(dizi2[x][m]<(int)51&&dizi2[x][m]>48&&dizi2[x][m+1]<(int)54&&dizi2[x][m+2]<(int)54);// 100-255 arasý sabitlerin kontrolü
					else if(dizi2[x][m]==(int)84 && dizi2[x][m+1]==(int)79 &&dizi2[x][m+2]==(int)80);	//TOP					
					else if(dizi2[x][m]==(int)67 && dizi2[x][m+1]==(int)73 &&dizi2[x][m+2]==(int)75);	//CIK						
					else if(dizi2[x][m]==(int)67 && dizi2[x][m+1]==(int)82 && dizi2[x][m+2]==(int)80);	//CRP						
					else if(dizi2[x][m]==(int)66 && dizi2[x][m+1]==(int)79 && dizi2[x][m+2]==(int)76);	//BOL						
					else if(dizi2[x][m]==(int)68 && dizi2[x][m+1]==(int)83 && dizi2[x][m+2]==(int)68);	//DSD						
					else if(dizi2[x][m]==(int)68 && dizi2[x][m+1]==(int)65 && dizi2[x][m+2]==(int)76);	//DAL						
					else if(dizi2[x][m]==(int)86 && dizi2[x][m+1]==(int)69 && dizi2[x][m+2]==(int)89);	//VEY
					else
					{
						printf("Hatali kod 2");
						return;
					}
					break;
				case 7://boyutlular için kontrol
					m=0;
					if(dizi2[x][m]==(int)69&&dizi2[x][m+1]==(int)84&&dizi2[x][m+2]==(int)73&&dizi2[x][m+3]==(int)75&&dizi2[x][m+4]==(int)69&&dizi2[x][m+5]==(int)84)
					{
						switch(dizi2[x][m+6])//Etiket kontrolü 1-9 kadar
						{
							case (int)49:// ETIKET1
								
								break;
							case (int)50:// ETIKET2
								
								break;
							case (int)51:// ETIKET3
								
								break;
							case (int)52:// ETIKET4
								
								break;
							case (int)53:// ETIKET5
								
								break;
							case (int)54:// ETIKET6
								
								break;
							case (int)55:// ETIKET7
								
								break;
							case (int)56:// ETIKET8
								
								break;
							case (int)57:// ETIKET9
							
								break;
							default:
								printf("hatali kod 3");
								return;
						}
					}
					else
					{
						printf("hatali kod 4");
						return;
					}
					break;
			}
			x++;//en son olarak stünu artýrdýk
			j++;//döngüyü artýrdýk
			
		
		}
	
	}
	printf("hata yok");
	m=m+1;//dizi bir adým ileri kaydýrdýk
}
