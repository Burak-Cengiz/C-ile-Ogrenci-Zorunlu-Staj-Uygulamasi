#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <time.h>


typedef struct
{
	int OgrenciNo;
	char OgrenciAd[50];
	char OgrenciSoyad[50];
	
}OgrenciBilgi;

typedef struct
{
	int FirmaVergiNo;
	char FirmaAd[50];
	char FirmaAlan[50];
	
}FirmaBilgi;

typedef struct
{
	int FirmaVergiNo;
	int OgrenciNo;
	int ToplamStajHafta;
	int StajBaslangicAy;
	int StajBaslangicGun;
	int StajBitisAy;
	int StajBitisGun;
	
}DonanimStajBilgi;

typedef struct
{
	int FirmaVergiNo;
	int OgrenciNo;
	int ToplamStajHafta;
	int StajBaslangicAy;
	int StajBaslangicGun;
	int StajBitisAy;
	int StajBitisGun;
	
}YazilimStajBilgi;


int main() {
	OgrenciBilgi Ogrenci[30];
	FirmaBilgi Firma[30];
	DonanimStajBilgi DonanimStaj[30];
	YazilimStajBilgi YazilimStaj[30];
	int kontrol,kontrol2,i=1,j,OgrNoKontrol,OgrenciKontrol=0,OgrenciKontrol2=0;
	int a=1,b=0,VergiNoKontrol,FirmaKontrol=0,FirmaKontrol2=0,Stajkontrol=0;
	int OgrStajKontrol=0,FirmaStajKontrol=0,ToplamStaj=0;
	
	Ogrenci[0].OgrenciNo=1,strcpy(Ogrenci[0].OgrenciAd,"Burak"),strcpy(Ogrenci[0].OgrenciSoyad,"Cengiz");
	Ogrenci[1].OgrenciNo=2,strcpy(Ogrenci[1].OgrenciAd,"Elif"),strcpy(Ogrenci[1].OgrenciSoyad,"Yilmaz");
	Firma[0].FirmaVergiNo=1,strcpy(Firma[0].FirmaAd,"GAP"),strcpy(Firma[0].FirmaAlan,"Insaat");
	Firma[1].FirmaVergiNo=2,strcpy(Firma[1].FirmaAd,"GOOGLE"),strcpy(Firma[1].FirmaAlan,"WEB");
	
	FILE *OgrenciDosya;
	FILE *FirmaDosya;
	FILE *StajDosya;
	
	OgrenciDosya = fopen("OgrenciDosya.txt","w");
	fprintf(OgrenciDosya," %s  ","Ogrenci listesi:");
	fprintf(OgrenciDosya," %s","Ogr No:");
	fprintf(OgrenciDosya,"%d ",1);
	fprintf(OgrenciDosya," %s","Ogr Ad:");
	fprintf(OgrenciDosya,"%s ","Burak");
	fprintf(OgrenciDosya," %s","Ogr Soyad:");
	fprintf(OgrenciDosya,"%s  ","Cengiz");
	fprintf(OgrenciDosya,"  %s","Ogr No:");
	fprintf(OgrenciDosya,"%d ",2);
	fprintf(OgrenciDosya," %s","Ogr Ad:");
	fprintf(OgrenciDosya,"%s ","Elif");
	fprintf(OgrenciDosya," %s","Ogr Soyad:");
	fprintf(OgrenciDosya,"%s ","Yilmaz");
	fclose(OgrenciDosya);
	
	FirmaDosya = fopen("FirmaDosya.txt","w");
	fprintf(FirmaDosya," %s  ","Firma listesi:");
	fprintf(FirmaDosya," %s","Firma No:");
	fprintf(FirmaDosya,"%d ",1);
	fprintf(FirmaDosya," %s","Firma Ad:");
	fprintf(FirmaDosya,"%s ","GAP");
	fprintf(FirmaDosya," %s","Firma Alan:");
	fprintf(FirmaDosya,"%s  ","Insaat");
	fprintf(FirmaDosya,"  %s","Firma No:");
	fprintf(FirmaDosya,"%d ",2);
	fprintf(FirmaDosya," %s","Firma Ad:");
	fprintf(FirmaDosya,"%s ","GOOGLE");
	fprintf(FirmaDosya," %s","Firma Alan:");
	fprintf(FirmaDosya,"%s ","WEB");
	fclose(FirmaDosya);
	
	StajDosya = fopen("StajDosya.txt","w");
	fclose(StajDosya);

	do{
		
		printf("\n\t\tMENU\n\t1- Ogrenci Islemleri\n\t2- Firma Islemleri\n\t3- Staj Islemleri\n\n");
		printf("\tYapmak istediginiz islemi seciniz:  ");
		scanf("%d",&kontrol);
		
		if(kontrol == 1)
		{
			do{
				printf("\n\t\tMENU\n\t1- Ogrenci Ekleme\n\t2- Ogrenci Duzenle\n\t3- Ogrenci Silme\n\t4- Ogrenci Listele\n\n");
				printf("\tYapmak istediginiz islemi seciniz:  ");
				scanf("%d",&kontrol2);
				
				if(kontrol2 == 1)
				{
				
					printf("\n\tOgrenci eklemeye hosgeldiniz.\n\n\tLutfen eklemek istediginiz Ogrencinin adini giriniz: ");			
					scanf("%s",&Ogrenci[i+1].OgrenciAd);	
					printf("\n\tLutfen eklemek istediginiz Ogrencinin soyadini giriniz: ");
					scanf("%s",&Ogrenci[i+1].OgrenciSoyad);	
					Ogrenci[i+1].OgrenciNo=i+2;
					OgrenciDosya = fopen("OgrenciDosya.txt","a");	
					fprintf(OgrenciDosya,"  %s","Ogr No:");				
					fprintf(OgrenciDosya,"%d ", Ogrenci[i+1].OgrenciNo);
					fprintf(OgrenciDosya," %s","Ogr Ad:");
					fprintf(OgrenciDosya,"%s ", Ogrenci[i+1].OgrenciAd);
					fprintf(OgrenciDosya," %s","Ogr Soyad:");
					fprintf(OgrenciDosya,"%s ", Ogrenci[i+1].OgrenciSoyad);
					fclose(OgrenciDosya);
					i++;			
				}	
				
				if(kontrol2 == 2)
				{
					printf("\n\tOgrenci duzenlemeye hosgeldiniz.\n\n\tLutfen duzenlemek istediginiz Ogrencinin numarasini giriniz: ");
					scanf("%d",&OgrNoKontrol);
					OgrenciDosya = fopen("OgrenciDosya.txt","r+");
					
					do{
						for(j=0;j<i+1;j++)
						{
						
							if(Ogrenci[j].OgrenciNo == OgrNoKontrol)
							{
								printf("\n\t%d numarali ogrencinin adini giriniz: ",Ogrenci[j].OgrenciNo);
								scanf("%s",&Ogrenci[j].OgrenciAd);
								printf("\n\t%d numarali ogrencinin soyadini giriniz: ",Ogrenci[j].OgrenciNo);
								scanf("%s",&Ogrenci[j].OgrenciSoyad);
								printf("\n\tKayit basariyla duzenlendi.\n");
								OgrenciKontrol=1;
							}
							fprintf(OgrenciDosya,"  %s","Ogr No:");
							fprintf(OgrenciDosya,"%d ", Ogrenci[j].OgrenciNo);
							fprintf(OgrenciDosya," %s","Ogr Ad:");
							fprintf(OgrenciDosya,"%s ", Ogrenci[j].OgrenciAd);
							fprintf(OgrenciDosya," %s","Ogr Soyad:");
							fprintf(OgrenciDosya,"%s ", Ogrenci[j].OgrenciSoyad);
						
							
						}
					
							fclose(OgrenciDosya);
					
						if(OgrenciKontrol==0)
						{
							printf("\n\tUyari!! Boyle bir ogrenci bulunmamaktadir!!Lutfen Dogru bir numara giriniz:   ");				
							scanf("%d",&OgrNoKontrol);	
						}
					}while(OgrenciKontrol==0);
					
					
				}
				
				if(kontrol2 == 3)
				{
					printf("\n\tOgrenci silmeye hosgeldiniz.\n\n\tLutfen silmek istediginiz Ogrencinin numarasini giriniz: ");
					scanf("%d",&OgrNoKontrol);
					OgrenciDosya = fopen("OgrenciDosya.txt","r+");
					
					do{
						for(j=0;j<i+1;j++)
						{
							if(Ogrenci[j].OgrenciNo == OgrNoKontrol)
							{
								strcpy(Ogrenci[j].OgrenciAd,"Silindi");
								strcpy(Ogrenci[j].OgrenciSoyad,"Silindi");
								printf("\n\tKayit basariyla silindi.\n");
								OgrenciKontrol2=1;
							}
							fprintf(OgrenciDosya,"  %s","Ogr No:");
							fprintf(OgrenciDosya,"%d ", Ogrenci[j].OgrenciNo);
							fprintf(OgrenciDosya," %s","Ogr Ad:");
							fprintf(OgrenciDosya,"%s ", Ogrenci[j].OgrenciAd);
							fprintf(OgrenciDosya," %s","Ogr Soyad:");
							fprintf(OgrenciDosya,"%s ", Ogrenci[j].OgrenciSoyad);
						}
						fclose(OgrenciDosya);
					
						if(OgrenciKontrol2==0)
						{
							printf("\n\tUyari!! Boyle bir ogrenci bulunmamaktadir!! Lutfen Dogru bir numara giriniz:  ");
							scanf("%d",&OgrNoKontrol);	
						}
					}while(OgrenciKontrol2==0);
					
					
				}
				
				if(kontrol2 == 4)
				{
					printf("\n\tOgrencilerin listesi\n");
					printf("\t------------------------\n");
					printf("\tOgr No\t\tOgr Ad\t\tOgr Soyad\n");
					printf("\t------\t\t------\t\t---------\n");
					for(j=0;j<i+1;j++)
					{
						printf("\t%d\t\t%s\t\t%s\n",Ogrenci[j].OgrenciNo,Ogrenci[j].OgrenciAd,Ogrenci[j].OgrenciSoyad);
					}
				}
								
			printf("\n\n\tOgrenci islemlerine donmek icin 1'e ogrenci islemlerinden cikmak icin 2'ye basiniz:  ");
			scanf("%d",&kontrol2);
			}while(kontrol2==1);
				
		}
		
		
		
		if(kontrol == 2)
		{
						
			do{
				printf("\n\t\tMENU\n\t1- Firma Ekleme\n\t2- Firma Duzenle\n\t3- Firma Silme\n\t4- Firma Listele\n\n");
				printf("\tYapmak istediginiz islemi seciniz:  ");
				scanf("%d",&kontrol2);
				
				
				if(kontrol2 == 1)
				{
				
					printf("\n\tFirma eklemeye hosgeldiniz.\n\n\tLutfen eklemek istediginiz firma adini giriniz: ");			
					scanf("%s",&Firma[a+1].FirmaAd);	
					printf("\n\tLutfen eklemek istediginiz firmanin alanini giriniz: ");
					scanf("%s",&Firma[a+1].FirmaAlan);	
					Firma[a+1].FirmaVergiNo=a+2;
					FirmaDosya = fopen("Firma.txt","a");
					fprintf(FirmaDosya," %s","Firma No:");					
					fprintf(OgrenciDosya,"%d ", Firma[a+1].FirmaVergiNo);
					fprintf(FirmaDosya," %s","Firma Ad:");
					fprintf(OgrenciDosya,"%s ", Firma[a+1].FirmaAd);
					fprintf(FirmaDosya," %s","Firma Alan:");
					fprintf(OgrenciDosya,"%s ", Firma[a+1].FirmaAlan);
					fclose(FirmaDosya);
					a++;			
				}	
				
				if(kontrol2 == 2)
				{
					printf("\n\tFirma duzenlemeye hosgeldiniz.\n\n\tLutfen duzenlemek istediginiz Firmanin vergi No'sunu giriniz: ");
					scanf("%d",&VergiNoKontrol);
					FirmaDosya = fopen("FirmaDosya.txt","r+");
					
					do{
						for(j=0;j<a+1;j++)
						{
						
							if(Firma[j].FirmaVergiNo == VergiNoKontrol)
							{
								printf("\n\t%d vergi No'lu firmanin adini giriniz: ",Firma[j].FirmaVergiNo);
								scanf("%s",&Firma[j].FirmaAd);
								printf("\n\t%d vergi No'lu firmanin alanini giriniz: ",Firma[j].FirmaVergiNo);
								scanf("%s",&Firma[j].FirmaAlan);
								printf("\n\tFirma basariyla duzenlendi.\n");
								FirmaKontrol=1;
							}
							fprintf(FirmaDosya," %s","Firma No:");	
							fprintf(FirmaDosya,"%d ", Firma[j].FirmaVergiNo);
							fprintf(FirmaDosya," %s","Firma Ad:");
							fprintf(FirmaDosya,"%s ", Firma[j].FirmaAd);
							fprintf(FirmaDosya," %s","Firma Alan:");
							fprintf(FirmaDosya,"%s ", Firma[j].FirmaAlan);				
						}	
					
							fclose(FirmaDosya);
					
						if(FirmaKontrol==0)
						{
							printf("\n\tUyari!! Boyle bir Firma bulunmamaktadir!! Lutfen Dogru bir firma numarasi giriniz:  ");
							scanf("%d",&VergiNoKontrol);	
						}
					}while(FirmaKontrol==0);

					
				}
				
				if(kontrol2 == 3)
				{
					printf("\n\tFirma silmeye hosgeldiniz.\n\n\tLutfen silmek istediginiz Firmanin Vergi No'sunu giriniz giriniz: ");
					scanf("%d",&VergiNoKontrol);
					FirmaDosya = fopen("FirmaDosya.txt","r+");
					
					do{
						for(j=0;j<a+1;j++)
						{
							if(Ogrenci[j].OgrenciNo == VergiNoKontrol)
							{
								strcpy(Firma[j].FirmaAd,"Silindi");
								strcpy(Firma[j].FirmaAlan,"Silindi");
								printf("\n\tFirma basariyla silindi.\n");
								FirmaKontrol2=1;
							}
							fprintf(FirmaDosya," %s","Firma No:");	
							fprintf(FirmaDosya,"%d ", Firma[j].FirmaVergiNo);
							fprintf(FirmaDosya," %s","Firma Ad:");
							fprintf(FirmaDosya,"%s ", Firma[j].FirmaAd);
							fprintf(FirmaDosya," %s","Firma Alan:");
							fprintf(FirmaDosya,"%s ", Firma[j].FirmaAlan);
						}
						fclose(FirmaDosya);
					
						if(FirmaKontrol2 == 0)
						{
							printf("\n\tUyari!! Boyle bir Firma bulunmamaktadir!! Lutfen Dogru bir firma numarasi giriniz:  ");
							scanf("%d",&VergiNoKontrol);	
						}
					}while(FirmaKontrol2 == 0);
					
				}
				
				
				
				if(kontrol2 == 4)
				{
					printf("\n\tFirmalarin listesi\n");
					printf("\t------------------------\n");
					printf("\tFirma Vergi No\t\tFirma Ad\tFirma Alan\n");
					printf("\t--------------\t\t--------\t----------\n");
					for(j=0;j<a+1;j++)
					{
						printf("\t%d\t\t\t%s\t\t%s\n",Firma[j].FirmaVergiNo,Firma[j].FirmaAd,Firma[j].FirmaAlan);
					}
				}
				
				
			printf("\n\tFirma islemlerine donmek icin 1'e firma islemlerinden cikmak icin 2'ye basiniz:  ");
			scanf("%d",&kontrol2);
			}while(kontrol2 == 1);
			
					
		}
		
		
		
		if(kontrol ==3)
		{
						
			do{
				
				printf("\n\t\tMENU\n\t1- Staj Ekleme\n\t2- Stajini tamamlamamis ogrenciler\n\t3- Stajini tamamlamis ogrenciler\n\n");
				printf("\tYapmak istediginiz islemi seciniz:  ");
				scanf("%d",&kontrol2);
				
				if(kontrol2 == 1)
				{
				
						printf("\n\tStaj eklemeye hosgeldiniz.\n\n\tOnce DONANIM Staji gireceksiniz.  ");
					
					
					
					
						printf("\n\tLutfen DONANIM staji yapacak ogrencinin Numarasini giriniz:  ");
						scanf("%d",&DonanimStaj[b].OgrenciNo);
										
						do{
							
							for(j=0;j<i+1;j++)
							{
								if(DonanimStaj[b].OgrenciNo == Ogrenci[j].OgrenciNo)
								{
									OgrStajKontrol=1;
								}
							}
                            
							if(OgrStajKontrol==0)
							{										
								printf("\n\tBoyle bir Ogrenci bulunmamaktadir!! Lutfen dogru bir numara giriniz:  ");
								scanf("%d",&DonanimStaj[b].OgrenciNo);							
							}
							
						}while(OgrStajKontrol==0);
						
		
						printf("\n\tLutfen %d numarali ogrencinin staj yaptigi firmanin vergi Numarasini giriniz:  ",DonanimStaj[b].OgrenciNo);
						scanf("%d",&DonanimStaj[b].FirmaVergiNo);
						
												
						do{
							for(j=0;j<i+1;j++)
							{
								if(DonanimStaj[b].FirmaVergiNo == Firma[j].FirmaVergiNo)
								{								
									FirmaStajKontrol=1;
								}
							}
							
							if(FirmaStajKontrol==0)
							{
								printf("\n\tBoyle bir Firma bulunmamaktadir!! Lutfen dogru bir firma vergi no giriniz:  ");
								scanf("%d",&DonanimStaj[b].FirmaVergiNo);
							}
							
						}while(FirmaStajKontrol==0);
						
						
						printf("\n\tLutfen %d numarali ogrencinin %d numarali firmada yaptigi donanim stajinin baslangic ayini giriniz (1-12):  ",DonanimStaj[b].OgrenciNo,DonanimStaj[b].FirmaVergiNo);
						scanf("%d",&DonanimStaj[b].StajBaslangicAy);
						while(DonanimStaj[b].StajBaslangicAy<=0 || DonanimStaj[b].StajBaslangicAy>12)
						{
							printf("\n\tHata!! Lutfen 0-12 arasi bir ay giriniz:  ");
							scanf("%d",&DonanimStaj[b].StajBaslangicAy);
						}
						
						printf("\n\tLutfen %d numarali ogrencinin %d numarali firmada yaptigi donanim stajinin baslangic gununu giriniz (1-30):  ",DonanimStaj[b].OgrenciNo,DonanimStaj[b].FirmaVergiNo);
						scanf("%d",&DonanimStaj[b].StajBaslangicGun);
						while(DonanimStaj[b].StajBaslangicGun<=0 || DonanimStaj[b].StajBaslangicGun>30)
						{
							printf("\n\tHata!! Lutfen 0-30 arasi bir Gun giriniz:  ");
							scanf("%d",&DonanimStaj[b].StajBaslangicGun);
						}
						
						printf("\n\tLutfen %d numarali ogrencinin %d numarali firmada yaptigi donanim stajinin bitis ayini giriniz (1-12):  ",DonanimStaj[b].OgrenciNo,DonanimStaj[b].FirmaVergiNo);
						scanf("%d",&DonanimStaj[b].StajBitisAy);
						while((DonanimStaj[b].StajBitisAy<DonanimStaj[b].StajBaslangicAy) ||  (DonanimStaj[b].StajBitisAy<=0 || DonanimStaj[b].StajBitisAy>12) )
						{
							printf("\n\tYa 0-12 arasi bir ay girmediniz ya da Baslangic ayindan kucuk bir ay girdiniz!!! Lutfen Dogru bir ay giriniz:  ");
							scanf("%d",&DonanimStaj[b].StajBitisAy);												
						}
						
										
						printf("\n\tLutfen %d numarali ogrencinin %d numarali firmada yaptigi donanim stajinin bitis gununu giriniz (1-30):  ",DonanimStaj[b].OgrenciNo,DonanimStaj[b].FirmaVergiNo);
						scanf("%d",&DonanimStaj[b].StajBitisGun);
						while(DonanimStaj[b].StajBitisGun<=0 || DonanimStaj[b].StajBitisGun>30)
						{
							printf("\n\tHata!! Lutfen 0-30 arasi bir Gun giriniz:  ");
							scanf("%d",&DonanimStaj[b].StajBitisGun);
						}
						
						j=0;
						
						while(j==0)
						{
							if(DonanimStaj[b].StajBaslangicAy==DonanimStaj[b].StajBitisAy)
							{
								if(DonanimStaj[b].StajBitisGun<=DonanimStaj[b].StajBaslangicGun)
								{
									printf("\n\tAylar ayni oldugu icin baslangic gunu daha buyuk olamaz!!! Lutfen Dogru bir Gun giriniz:  ");
									scanf("%d",&DonanimStaj[b].StajBitisGun);
								}
							}
							else
							{
								break;
							}
							if(DonanimStaj[b].StajBitisGun>DonanimStaj[b].StajBaslangicGun)
								j++;
									
						}
						
						
						DonanimStaj[b].ToplamStajHafta=(((30*DonanimStaj[b].StajBitisAy)+DonanimStaj[b].StajBitisGun) - ((30*DonanimStaj[b].StajBaslangicAy) + DonanimStaj[b].StajBaslangicGun))/7;
						
						StajDosya = fopen("StajDosya.txt","a");	
						fprintf(StajDosya," %s  ","Staj Haftalari:");	
						fprintf(StajDosya," %s","Ogrenci No:");			
						fprintf(StajDosya,"%d ", DonanimStaj[b].OgrenciNo);
						fprintf(StajDosya,"%s","Firma Vergi No:");	
						fprintf(StajDosya,"%d ", DonanimStaj[b].FirmaVergiNo);
						fprintf(StajDosya,"%s","Toplam Donanim Staj Haftasi:");	
						fprintf(StajDosya,"%d ", DonanimStaj[b].ToplamStajHafta);
						fclose(OgrenciDosya);
						
				
						YazilimStaj[b].OgrenciNo = DonanimStaj[b].OgrenciNo;
						YazilimStaj[b].FirmaVergiNo = DonanimStaj[b].FirmaVergiNo;				
						
						printf("\n\tSimdi de lutfen %d numarali ogrencinin YAZILIM staj haftalarini giriniz:  ",DonanimStaj[b].OgrenciNo);							
						
						printf("\n\tLutfen %d numarali ogrencinin %d numarali firmada yaptigi yazilim stajinin baslangic ayini giriniz (1-12):  ",YazilimStaj[b].OgrenciNo,YazilimStaj[b].FirmaVergiNo);
						scanf("%d",&YazilimStaj[b].StajBaslangicAy);
						while(YazilimStaj[b].StajBaslangicAy<=0 || YazilimStaj[b].StajBaslangicAy>12)
						{
							printf("\n\tHata!! Lutfen 0-12 arasi ay giriniz:  ");
							scanf("%d",&YazilimStaj[b].StajBaslangicAy);
						}
						
						printf("\n\tLutfen %d numarali ogrencinin %d numarali firmada yaptigi yazilim stajinin baslangic gununu giriniz (1-30):  ",YazilimStaj[b].OgrenciNo,YazilimStaj[b].FirmaVergiNo);
						scanf("%d",&YazilimStaj[b].StajBaslangicGun);
						while(YazilimStaj[b].StajBaslangicGun<=0 || YazilimStaj[b].StajBaslangicGun>30)
						{
							printf("\n\tHata!! Lutfen 0-30 arasi bir Gun giriniz:  ");
							scanf("%d",&YazilimStaj[b].StajBaslangicGun);
						}
						
						printf("\n\tLutfen %d numarali ogrencinin %d numarali firmada yaptigi yazilim stajinin bitis ayini giriniz (1-12):  ",YazilimStaj[b].OgrenciNo,YazilimStaj[b].FirmaVergiNo);
						scanf("%d",&YazilimStaj[b].StajBitisAy);
						while((YazilimStaj[b].StajBitisAy<YazilimStaj[b].StajBaslangicAy) ||  (YazilimStaj[b].StajBitisAy<=0 || YazilimStaj[b].StajBitisAy>12) )
						{
							printf("\n\tYa 0-12 arasi bir ay girmediniz ya da Baslangic ayindan kucuk bir ay girdiniz!!! Lutfen Dogru bir ay giriniz:  ");
							scanf("%d",&YazilimStaj[b].StajBitisAy);												
						}
						
										
						printf("\n\tLutfen %d numarali ogrencinin %d numarali firmada yaptigi yazilim stajinin bitis gununu giriniz (1-30):  ",YazilimStaj[b].OgrenciNo,YazilimStaj[b].FirmaVergiNo);
						scanf("%d",&YazilimStaj[b].StajBitisGun);
						while(YazilimStaj[b].StajBitisGun<=0 || YazilimStaj[b].StajBitisGun>30)
						{
							printf("\n\tHata!! Lutfen 0-30 arasi bir Gun giriniz:  ");
							scanf("%d",&YazilimStaj[b].StajBitisGun);
						}
						
						j=0;
						
						while(j==0)
						{
							if(YazilimStaj[b].StajBaslangicAy==YazilimStaj[b].StajBitisAy)
							{
								if(YazilimStaj[b].StajBitisGun<=YazilimStaj[b].StajBaslangicGun)
								{
									printf("\n\tAylar ayni oldugu icin baslangic gunu daha buyuk olamaz!!! Lutfen Dogru bir Gun giriniz:  ");
									scanf("%d",&YazilimStaj[b].StajBitisGun);
								}
							}
							else
							{
								break;
							}
							if(YazilimStaj[b].StajBitisGun>YazilimStaj[b].StajBaslangicGun)
								j++;
									
						}
						
						
						YazilimStaj[b].ToplamStajHafta=(((30*YazilimStaj[b].StajBitisAy)+YazilimStaj[b].StajBitisGun) - ((30*YazilimStaj[b].StajBaslangicAy) + YazilimStaj[b].StajBaslangicGun))/7;
						
						StajDosya = fopen("StajDosya.txt","a");
						fprintf(StajDosya,"%s","Toplam Yazilim Staj Haftasi:");	
						fprintf(StajDosya,"%d ", YazilimStaj[b].ToplamStajHafta);
						fclose(OgrenciDosya);
						
						
						b++;
										
				}
				
				if(kontrol2 == 2)
				{
						printf("\n\tStajini Tamamlamamis Ogrencilerin listesi\n");
						printf("\t-------------------------------------------\n");
						printf("\tOgr No\t\tFirma Vergi No\t\tDonanim Staj Hafta\t\tYazilim Staj Hafta\t\tToplam Staj Haftasi\n");
						printf("\t------\t\t--------------\t\t------------------\t\t------------------\t\t-------------------\n");
						
						for(j=0;j<i+1;j++)
						{
							ToplamStaj = DonanimStaj[j].ToplamStajHafta + YazilimStaj[j].ToplamStajHafta;
							if( (ToplamStaj<12) || (DonanimStaj[j].ToplamStajHafta<2) || (YazilimStaj[j].ToplamStajHafta<4))
							{	
								printf("\t%d\t\t\t%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d\n",DonanimStaj[j].OgrenciNo,DonanimStaj[j].FirmaVergiNo,DonanimStaj[j].ToplamStajHafta,YazilimStaj[j].ToplamStajHafta,ToplamStaj);
							}
						}
				}
				
				if(kontrol2 == 3)
				{
						printf("\n\tStajini Tamamlamis Ogrencilerin listesi\n");
						printf("\t-------------------------------------------\n");
						printf("\tOgr No\t\tFirma Vergi No\t\tDonanim Staj Hafta\t\tYazilim Staj Hafta\t\tToplam Staj Haftasi\n");
						printf("\t------\t\t--------------\t\t------------------\t\t------------------\t\t-------------------\n");
						
						for(j=0;j<i+1;j++)
						{
							ToplamStaj = DonanimStaj[j].ToplamStajHafta + YazilimStaj[j].ToplamStajHafta;
							if( (ToplamStaj>=12) && (DonanimStaj[j].ToplamStajHafta>=2) && (YazilimStaj[j].ToplamStajHafta>=4))
							{	
								printf("\t%d\t\t\t%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d\n",DonanimStaj[j].OgrenciNo,DonanimStaj[j].FirmaVergiNo,DonanimStaj[j].ToplamStajHafta,YazilimStaj[j].ToplamStajHafta,ToplamStaj);
							}
						}
				}
				
			printf("\n\tStaj islemlerine donmek icin 1'e staj islemlerinden cikmak icin 2'ye basiniz:  ");
			scanf("%d",&kontrol2);	
			}while(kontrol2 == 1);
			
		}
				
		
		printf("\n\tAna menuye donmek icin 1'e programdan cikmak icin 2'ye basiniz:  ");
		scanf("%d",&kontrol2);
	}while(kontrol2 == 1);
	
	return 0;
}


