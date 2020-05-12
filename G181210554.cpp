/****************************************************************************
**
**				ÖĞRENCİ ADI...........................:MAFTUN HASHIMLI 
**				ÖĞRENCİ NUMARASI.............:G181210554
**				DERS GRUBU…………………:1C
****************************************************************************/

#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;
    int boyut;
	int tercih;
	int toplam = 0;
	int satir;
	int sutun;
	int matris[100][100];
    int matristemp[100][100];                   //degiskenleri tanimliyoruz
	int matristempsatir[100][100];
	int matristerstemp[100][100];
	bool whiledongu = true;
	void matrisolustur()                      //matrisi olsutrumaya ve yazdirmaya yarayan fonk
	{
		cout << "      ";
		for (int i = 0; i < boyut; i++)
		{                         
			cout << " " << i + 1 << " ";

		}
		cout << endl;
		cout << " ";

		for (int i = 0; i < boyut; i++)
		{
			cout << "____";
		}
		cout << endl;
		cout << endl;
		for (int i = 0; i < boyut; i++)
		{
			cout << i + 1 << " |  ";

			for (int j = 0; j < boyut; j++)
			{

				cout << "  " << matris[i][j];

			}

			cout << endl;
		}

	}
	
	void rastgeledegerata()      //matris elemanlarina rastgele degerler atiyor
	{
		for (int i = 0; i < boyut; i++)
		{

			for (int j = 0; j < boyut; j++)
			{

				matris[i][j] = rand() % 9 + 1;

			}
			cout << endl;

		}
	}
	void satirsutundegis(int satirdegis,int sutundegis)               //menunun 1.isleminin fonk.u
	{
		cout << "satir giriniz : ";
		cin >> satirdegis;

	
		while (satirdegis == 0)
		{
			cout << "Yanlis secim...Ters cevrilecek sutunu secin";
			cin >> satirdegis;
		}
		while (0 > satirdegis || satirdegis > boyut)
		{

			cout << "satir matrisin boyutundan buyuk olamaz  : ";                 //kullanicinin girdigi degerleri kontrol ediyoruz
			cin >> satirdegis;
		}
		cout << "sutun giriniz : ";
		cin >> sutundegis;
		while (sutundegis == 0)
		{
			cout << "Yanlis secim...Ters cevrilecek sutunu secin";
			cin >> sutundegis;
		}

		while (0 > sutundegis || sutundegis > boyut)
		{

			cout << "sutun matrisin boyutundan buyuk olamaz : ";
			cin >> sutundegis;

		}
		int temp = matris[satirdegis - 1][satirdegis - 1] + matris[sutundegis - 1][sutundegis - 1];         //degerleri kaybetmememiz icin tanimliyoruz
		
		for (int i = 0; i < boyut; i++)
		{
			for (int l = 0; l < boyut; l++)
			{
				
				matristemp[satirdegis - 1][i] = matris[satirdegis - 1][i];

				matris[satirdegis - 1][i] = matris[i][sutundegis - 1];     //degistirme islemi

				matris[i][sutundegis - 1] = matristemp[satirdegis - 1][i];

			}

		}
		matris[satirdegis - 1][sutundegis - 1] = temp;
	}
	void tekleribasaal(int satirtek)  //menunun 2.islemi icin olan fonk.
	{
		cout << "satir : ";
		cin >> satirtek;
		while (0 > satirtek || satirtek > boyut)
		{

			cout << "satir matris boyutundan buyuk olamaz  : ";     //kullanicinin girdigi egeri kontrol ediyotuz
			cin >> satirtek;

		}
		int l = 0;

		for (int i = 0; i < boyut; i++)

		{
			if (matris[satirtek - 1][i] % 2 == 1)
			{

				matristempsatir[satirtek - 1][l] = matris[satirtek - 1][i];           //deger tekse if'e girecek
				l++;
			}
		}
		for (int i = 0; i < boyut; i++)

		{
			if (matris[satirtek - 1][i] % 2 == 0)
			{

				matristempsatir[satirtek - 1][l] = matris[satirtek - 1][i];      //deger ciftse if'e girecek
				l++;
			}
		}
		for (int i = 0; i < boyut; i++)
		{

			matris[satirtek - 1][i] = matristempsatir[satirtek - 1][i];          //en son matris'i tuttugumuz degere esitliyoruz
		}
		}
	void terscevir(int sutunt)                //menunun 3. islemi icin gereken fonk.
	{
		cout << "Ters cevrilecek sutunu secin";
		cin >> sutunt;
	
		while (sutunt > boyut)
		{
			cout << "yanlis deger lutfen yeniden giriniz";      //kontrol islemi
			cin >> sutunt;
		}

		int j = boyut - 1;

		for (int i = 0; i < boyut; i++)
		{


			matristerstemp[j][sutunt - 1] = matris[i][sutunt - 1];                //gecici bir matris tanimliyor.Degelrein kaybolmamasi icin

			--j;
		}
		for (int i = 0; i < boyut; i++)
		{
			int j = boyut - 1;


			matris[i][sutunt - 1] = matristerstemp[i][sutunt - 1];

			j--;

		}
	
	}
	void toplamlariyazdir()         //menunun 4.islemi icin gereken fonk.
	{
		

		for (int i = 0; i < boyut; i++)
		{

			for (int n = 0; n < boyut; n++)
			{
				if (i != 0 || n != 0)
					toplam += matris[i][n];              //ilk degeri tutmak icin toplam matrisi


			}cout << "\n";

		}

		for (int i = 0; i < boyut; i++)
		{

			for (int n = 0; n < boyut; n++)
			{

				if (i == 0 && n == 0)
				{
					matris[i][n] = toplam;                                  //matrisin ilk elemainysa ata
				}
				else
				{
					matris[i][n] = toplam - matris[i][n];
					toplam = matris[i][n];                     //degilse eksilterek devam et
				}


		
			}
			
		}



	}
int main()
{
	srand(time(0));
	cout << " Matris Boyutu :  ";
	cin >> boyut;
	rastgeledegerata();
	matrisolustur();
	while (whiledongu)
	{
		if (boyut < 5 || boyut > 25)
		{
			cout << " Matris boyutu 25 'den kucuk ve 5 'ten buyuk olmalidir "; //matris boyutu kontrolu
			cin >> boyut;
		}
		else
			whiledongu = false;
	}
	cout << "1.sutun satir degistir " << endl;
	cout << "2.tekleri basa al (satir)" << endl;
	cout << "3.ters cevir (sutun)" << endl;
	cout << "4.toplamlari yazdir" << endl;
	cin >> tercih;
	cout << endl;
	cout << endl;
	while (tercih < 1 || tercih > 4)
	{
		cout << "1.sutun satir degistir " << endl;
		cout << "2.tekleri basa al (satir)" << endl;     //menu sayisi kontrolu
		cout << "3.ters cevir (sutun)" << endl;
		cout << "4.toplamlari yazdir" << endl;
		cin >> tercih;
	}
	switch (tercih)      //girilen sayiyi uygun islem
	{
	case 1:
	{
		satirsutundegis(satir,sutun);
		break;
	}
	case 2:
	{
		tekleribasaal(satir);
		break;
	}
	case 3:
	{
		terscevir(sutun);
		break;
	}
	case 4:
	{
		toplamlariyazdir();
		break;
	}
	}
	matrisolustur();
	return 0;
}