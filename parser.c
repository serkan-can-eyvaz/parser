#include<stdio.h>                                                                                          // Serkan Can EYVAZ 02210224021
#include<stdlib.h> 
#include<string.h>
int main(){
	char dizi[100];
	char dosyaName[100];
	printf("dosya adini giriniz:");//Dosya ad�n� kullan�c�dan ald�k
	gets(dosyaName);
    FILE *dosya=fopen(dosyaName,"r");	
	int i=0;
	printf ("kaynak kod:\n");
	while(!feof(dosya)){
		fscanf(dosya,"%c",&dizi[i]);//dosyay� dizide tuttuk
		printf("%c",dizi[i]);//Kaynak kodu ekrana yazd�rd�k
		i++;		 
	}
	fclose(dosya);
	int j=0,x=0,m=0;
	char dizi2[500][10];
	char token[100];
	printf("\n\nkelimelestirme:\n");//Tokenizer ile kelimeli�tirmeyi ekrana yazd�rd�k
	while(j<i)
	{
		if(dizi[j]!=(int)10)
		{
			if(dizi[j] == (int)32 || dizi[j] == (int)44 || dizi[j] == (int)91 || dizi[j] == (int)93 ||dizi[j] == (int)58)//Ayraclar� kontrol ettik("," ":" "[]" " ") 
			{
				printf(" ");// ekran ��kt�s�nda kelimeler aras�na birer bo�luk b�rakt�k
			}
			else
			{
				token[j]=dizi[j];//dizide tuttu�umuz dosyay� token aktra�p ekran bast�rd�k
				printf("%c",token[j]);
			}
			
		}
		else
		{
			printf(" ");
		}
		j++;
		
	}
	
	printf("\n\nParser:\n");//gramer kurallar�n�n kontrol�
	j=0;
	while (j< i)
	{
		if (
		 dizi[j]!= (int)32 && // ayraclar�n kontrol�n� yapt�k
		 dizi[j]!= (int)44 &&
		 dizi[j]!= (int)91 && 
		 dizi[j]!= (int)93 && 
		 dizi[j]!= (int)10 && 
		 dizi[j]!= (int)58  )
		
		{
			dizi2[x][m]=dizi[j];// kaynak kodumuzu tutan diziyi yeni dizimize aktard�k
			m++;// sat�r� her d�ng�de art�rd�k
			j++;//d�ng�y� ilerlettik
		}
		else
		{
			switch(m)//kontol�n ger�ekle�emesi i�in sat�r� kulland�k
			{
				case 1://tek boyutlular i�in kontrol
					m=0;//en ba�tan gramer kontrol� yapmak i�in ilerlemi� m de�erimizi s�f�rlad�k
					if(dizi2[x][m]<(int)57 && dizi2[x][m]>(int)48)//1-9 aras� sabitlerin kontrol�
					{
						
					}
					else
					{
						printf("hatali kod");
						return;
					}
					
					break;
				case 2://2 boyutlular i�in kontrol
					m=0;
					
					if(dizi2[x][m]<=(int)57&&dizi2[x][m]>(int)48&&dizi2[x][m+1]<=(int)57&&dizi2[x][m+1]>48)//10--99 aras� sabitlerin kontrol�
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
				case 3://3 boyutlular i�in kontrol
					m=0;
					if(dizi2[x][m]<(int)51&&dizi2[x][m]>48&&dizi2[x][m+1]<(int)54&&dizi2[x][m+2]<(int)54);// 100-255 aras� sabitlerin kontrol�
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
				case 7://boyutlular i�in kontrol
					m=0;
					if(dizi2[x][m]==(int)69&&dizi2[x][m+1]==(int)84&&dizi2[x][m+2]==(int)73&&dizi2[x][m+3]==(int)75&&dizi2[x][m+4]==(int)69&&dizi2[x][m+5]==(int)84)
					{
						switch(dizi2[x][m+6])//Etiket kontrol� 1-9 kadar
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
			x++;//en son olarak st�nu art�rd�k
			j++;//d�ng�y� art�rd�k
			
		
		}
	
	}
	printf("hata yok");
	m=m+1;//dizi bir ad�m ileri kayd�rd�k
}
