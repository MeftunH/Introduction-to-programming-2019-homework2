/****************************************************************************
**					SAKARYA ÜNÝVERSÝTESÝ
**			         BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				    BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				          PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI…...:3
**				ÖÐRENCÝ ADI...............:MAFTUN HASHÝMLÝ
**				ÖÐRENCÝ NUMARASI.:G181210554
**				DERS GRUBU…………:B
****************************************************************************/

#include <iostream>
#include <math.h>

using namespace std;

struct Islem
{
	int giris[6][6] = {
	  {3,2,5,1,4,1},
	  {6,2,1,0,7,1},
	  {3,0,0,2,0,1},
	  {1,1,3,2,2,1},
	  {0,3,1,0,0,1},
	  {1,1,1,1,1,1}
	};

	int kaymaMiktari;

	//cekirdekBoyut Sonuc matrisinin Sinirlarini belirler
	int cekirdekBoyut;
	//Cekirdek Matrisi maximum 5x5 boyut alabilir
	int cekirdekMatris[5][5];

	//SonucBoyut Sonuc matrisinin Sinirlarini belirler
	int sonucBoyut;
	//Sonuc Matrisi maximum ((100 - 2) / 1)+1 = 99 boyut alabilir
	int sonucMatris[99][99];

	//giris_satir ve giris_sutun Giris Matrisinin Satir ve Sutunlarýný elde eder
	int giris_satir;
	int giris_sutun;
	//0 dan farklý deger olup olmadýgýný kontrol et
	bool islemKontrol()
	{
		giris_satir = (sizeof(giris) / sizeof(giris[0]));
		giris_sutun = (sizeof(giris[0]) / sizeof(int));
		// asagdaki if kosulu oldugu durumda yanlýþ dondurucek

		if (giris_satir < cekirdekBoyut || giris_sutun < cekirdekBoyut)
		{
			cout << "Giris matrisinin satiri Yada sutunu cekirdek matristen kucuk olamaz..";
			return false;
		}
		
		else
		{// if içindeki kosul dogruysa hata vericek
			if (kaymaMiktari < 1)
			{
				cout << "Kayma miktari 1 den kucuk olamaz..";
				return false;
			}

			else
			{
				//asagdaki kosul dogruysa hata vericek
				if (kaymaMiktari > cekirdekBoyut)
				{
					cout << "Kayma miktari cekirdek matrisinin Giris matrisinden Tasmasina sebep olamaz..";
					return false;
				}

				else
				{//asagdaki kosul dogruysa true dondurucek
					sonucBoyut = ((giris_satir - cekirdekBoyut) / kaymaMiktari) + 1;
					return true;
				}
			}
		}
	}
	//fonksiyonu olusturuyoruz
	void islemYap()
	{
		int sonuc_i = 0;
		int sonuc_j = 0;
		int toplam = 0;

		//Girdi Matrisi ile Cekirdek Matrisi isleme Tabii Tutar
		for (int i = 0; i < giris_satir; i += kaymaMiktari)
		{

			for (int j = 0; j < giris_sutun; j += kaymaMiktari)
			{

				for (int k = 0; k < cekirdekBoyut; k++)
				{

					for (int l = 0; l < cekirdekBoyut; l++)
					{
						toplam += (giris[i + k][j + l] * cekirdekMatris[k][l]);
					}
				}
				sonucMatris[sonuc_i][sonuc_j] = toplam;
				toplam = 0;
				sonuc_j++;
			}
			sonuc_j = 0;
			sonuc_i++;
		}
	}
};

//Yeni Bir Ýslem Tanimlanir
Islem islem;

int main()
{
	cout << "Cekirdek Boyutunu Giriniz: ";
	cin >> islem.cekirdekBoyut;
	cout << "Kayma Miktarini Giriniz: ";
	cin >> islem.kaymaMiktari;

	if (islem.islemKontrol())
	{
		//Cekirdek matris Tanimlanir
		for (int i = 0; i < islem.cekirdekBoyut; i++)
		{
			for (int j = 0; j < islem.cekirdekBoyut; j++)
			{
				cout << "\n cekirdek[" << i << "][" << j << "]=";
				cin >> islem.cekirdekMatris[i][j];
			}
		}

		//Ýki matris arasi islem yaptirilir
		islem.islemYap();

		//Ekrana Sonuc Matrisini Yazdýrýr
		for (int i = 0; i < islem.sonucBoyut; i++)
		{
			for (int j = 0; j < islem.sonucBoyut; j++)
			{
				cout << islem.sonucMatris[i][j] << " ";
			}
			cout << "\n";
		}
	}
	system("pause");
}