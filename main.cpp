#include <opencv2/opencv.hpp>
#include <iostream>
#include <filesystem>
#include <Windows.h>
using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    // Resim dosyasýný okuyoruz

    Mat image = imread("dosyayolu");
    int x;

    if (image.empty())
    {
        cout << "Resim bulunamadi veya acilamadi" << endl;
        cin.get();
        return -1;
    }
    cout << "\t\t\t\t\t\t\x1B[35mMERHABALAR\033[0m\t\n";
    cout << "Oncelikle hangi islemi yapmak istersiniz?" << endl;
    cout << " 1)Blurlama islemi\n 2)Keskinlestirme islemi\n 3)Resize islemi\n 4)Kenar algilama\n 5)Kontrast degisikligi\nCikis yapmak icin -1 rakamini giriniz" << endl;
    cin >> x;
    if (x == 1)
    {
        //Görüntüyü bulanýklaþtýrýyoruz
        Mat blurlu_3x3_kernel;
        blur(image, blurlu_3x3_kernel, Size(3, 3));



        //Açýlacak olan pencerelerin adlarý tanýmlanýr
        String pencere_ismi = "Ýlk Hali";
        String pencere_ismi_blurlu_with_3x3_kernel = "Blurlu Hali";
        cout << "\x1B[33mCiktiyi ekranda gormek istiyor musunuz? (istiyorsaniz evet yazin)\033[0m\n";
        string input1;
        cin >> input1;
        string kontrol1 = "evet";
        if (input1 == kontrol1) {

            //Resimleri oluþturulan pencerelerde gösterir.
            imshow(pencere_ismi, image);
            waitKey(0);
            imshow(pencere_ismi_blurlu_with_3x3_kernel, blurlu_3x3_kernel);
            waitKey(0);
            //Resimler için pencere oluþturur ve açar
            namedWindow(pencere_ismi);
            namedWindow(pencere_ismi_blurlu_with_3x3_kernel);
            destroyAllWindows();

        }
        else {
            cout << ("\x1B[31mCikti ekranda gosterilmeyecek\033[0m\n");

        }
        cout << "\x1B[33mPeki bu ciktiyi kaydetmek istiyor musunuz?(istiyorsaniz evet yaziniz)\033[0m\n";
        string input2;
        cin >> input2;
        string kontrol2 = "evet";
        if (input2 == kontrol2)
        {
            cv::imwrite("kaydedilecekKlasor/birinci.png", image);
            cv::imwrite("kaydedilecekKlasor/birincisorublurlu.png", blurlu_3x3_kernel);
            cout << ("\x1B[31mResimler ve son halleri kaydedildi\033[0m\n");
        }
        else {
            cout << ("\x1B[31mKaydedilmeyecek\033[0m\n");
        }


        destroyAllWindows(); //Tüm açýk pencereleri kapatýr
        cout << "\x1B[33mTekrar duzenlemek istiyorsaniz evet yaziniz:\033[0m\n";
        std::string input11;
        cin >> input11;
        std::string kontrol11 = "evet";
        if (input11 == kontrol11)
        {
            main(argc, argv);
        }
        if (x == -1)
        {
            return 0;
        }
        else {
            cout << "Program sonlandirildi.\n";
            return 0;
        }

    }
    if (x == 2)
    {
        cv::Mat keskinlestirilen;
        cv::GaussianBlur(image, keskinlestirilen, cv::Size(15, 15), 10);
        cv::addWeighted(image, 1.5, keskinlestirilen, -0.5, 0, keskinlestirilen);


        String pencere_ismi = "Orijinal hali";
        String pencere_ismi_keskinlesitirilmis = "Keskinleþtirilmiþ Hali";
        cout << "\x1B[33mCiktiyi ekranda gormek istiyor musunuz? (istiyorsaniz evet yazin)\033[0m\n";
        std::string input3;
        cin >> input3;
        std::string kontrol3 = "evet";
        if (input3 == kontrol3)
        {
            //Resimleri oluþturulan pencerelerde gösterir.
            imshow(pencere_ismi, image);
            waitKey(0);
            imshow(pencere_ismi_keskinlesitirilmis, keskinlestirilen);
            waitKey(0);
            //Resimler için pencere oluþturur ve açar
            namedWindow(pencere_ismi);
            namedWindow(pencere_ismi_keskinlesitirilmis);
            destroyAllWindows();

        }
        else {
            cout << ("\x1B[31mCikti ekranda gosterilmeyecek\033[0m\n");
        }
        cout << "\x1B[33mPeki bu ciktiyi kaydetmek istiyor musunuz?(istiyorsaniz evet yaziniz)\033[0m\n";
        std::string input4;
        cin >> input4;
        std::string kontrol4 = "evet";
        if (input4 == kontrol4)
        {
            cv::imwrite("kaydedilecekKlasor/ikinci.png", image);
            cv::imwrite("kaydedilecekKlasor/ikincisorukeskin.png", keskinlestirilen);
            cout << ("\x1B[31mResimler ve son halleri kaydedildi\033[0m\n");
        }
        else {
            cout << ("\x1B[31mkaydedilmeyecek\033[0m\n");
        }
        destroyAllWindows(); //Tüm açýk pencereleri kapatýr
        cout << "\x1B[33mTekrar duzenlemek istiyorsaniz evet yaziniz:\033[0m\n";
        std::string input11;
        cin >> input11;
        std::string kontrol11 = "evet";
        if (input11 == kontrol11)
        {
            main(argc, argv);
        }
        if (x == -1)
        {
            return 0;
        }
        else {
            cout << "Program sonlandirildi\n";
            return 0;
        }

    }
    if (x == 3)
    {
        //Yeni verileri girerek görüntüyü küçültelim
        int kucultulen_genislik = 300;
        int kucultulen_uzunluk = 200;
        Mat kucultulmus;
        //Küçültme iþlemi yaparýz
        resize(image, kucultulmus, Size(kucultulen_genislik, kucultulen_uzunluk), INTER_LINEAR);
        // Yeni verileri girerek görüntüyü büyütelim
        int buyutulen_genislik = 600;
        int buyutulen_yukseklik = 400;
        Mat buyutulen;
        //Yeniden boyutlandýrýrýz
        resize(image, buyutulen, Size(buyutulen_genislik, buyutulen_yukseklik), INTER_LINEAR);
        cout << "\x1B[33mciktiyi ekranda gormek istiyor musunuz? (istiyorsaniz evet yazin)\033[0m\n";
        string input5;
        cin >> input5;
        string kontrol5 = "evet";
        if (input5 == kontrol5)
        {
            // Resmi görüntüler ve devam etmek için herhangi bir tuþa basýlmasýný bekler
            imshow("Goruntu kucultuluyor", kucultulmus);
            waitKey(0);
            imshow("Goruntu buyutuluyor", buyutulen);
            waitKey(0);
            imshow("orijinal hali", image);
            waitKey(0);
            destroyAllWindows();
        }
        else {
            cout << ("\x1B[31mcikti ekranda gosterilmeyecek\033[0m\n");
        }
        cout << "\x1B[33mPeki bu ciktiyi kaydetmek istiyor musunuz?(istiyorsaniz evet yaziniz)\033[0m\n";
        std::string input6;
        cin >> input6;
        std::string kontrol6 = "evet";
        if (input6 == kontrol6)
        {
            cv::imwrite("kaydedilecekKlasor/üçüncü.png", image);
            cv::imwrite("kaydedilecekKlasor/üçüncüsoruresizeddown.png", kucultulmus);
            cv::imwrite("kaydedilecekKlasor/üçüncüsoruresizedup.png", buyutulen);
            cout << ("\x1B[31mResimler ve son halleri kaydedildi\033[0m\n");
        }
        else {
            cout << ("\x1B[31mkaydedilmeyecek\033[0m\n");
        }
        cout << "\x1B[33mTekrar duzenlemek istiyorsaniz evet yaziniz:\033[0m\n";
        std::string input11;
        cin >> input11;
        std::string kontrol11 = "evet";
        if (input11 == kontrol11)
        {
            main(argc, argv);
        }
        if (x == -1)
        {
            return 0;
        }
        else {
            cout << "Program sonlandirildi.\n";
            return 0;
        }

        destroyAllWindows();

    }
    if (x == 4)
    {
        //Gri tonlamaya dönüþtürür
        Mat img_gri;
        cvtColor(image, img_gri, COLOR_BGR2GRAY);
        //Daha iyi kenar tespiti için görüntüyü bulanýklaþtýrýr
        Mat img_blur;
        GaussianBlur(img_gri, img_blur, Size(3, 3), 0);

        // Sobel ile kenar tespiti
        Mat sobelx, sobely, sobelxy;
        Sobel(img_blur, sobelx, CV_64F, 1, 0, 5);
        Sobel(img_blur, sobely, CV_64F, 0, 1, 5);
        Sobel(img_blur, sobelxy, CV_64F, 1, 1, 5);
        Mat edges;
        Canny(img_blur, edges, 100, 200, 3, false);
        cout << "\x1B[33mciktiyi ekranda gormek istiyor musunuz? (istiyorsaniz evet yazin)\033[0m\n";
        string input7;
        cin >> input7;
        string kontrol7 = "evet";
        if (input7 == kontrol7)
        {
            // Kenar algýlama görüntülerini gösterir
            imshow("orijinal resim", image);
            waitKey(0);
            imshow("Sobel X", sobelx);
            waitKey(0);
            imshow("Sobel Y", sobely);
            waitKey(0);
            imshow("Sobel() fonksiyonu kullanan Sobel XY ", sobelxy);
            waitKey(0);
            imshow("Canny kenar algilama", edges);
            waitKey(0);

            destroyAllWindows();

        }
        else {
            cout << ("\x1B[31mcikti ekranda gosterilmeyecek\033[0m\n");
        }
        cout << "\x1B[33mPeki bu ciktiyi kaydetmek istiyor musunuz?(istiyorsaniz evet yaziniz)\033[0m\n";
        std::string input8;
        cin >> input8;
        std::string kontrol8 = "evet";
        if (input8 == kontrol8)
        {
            cv::imwrite("kaydedilecekKlasor/dördüncü.png", image);
            cv::imwrite("kaydedilecekKlasor/dördüncüsorusobelx.png", sobelx);
            cv::imwrite("kaydedilecekKlasor/dördüncüsorusobely.png", sobely);
            cv::imwrite("kaydedilecekKlasor/dördüncüsorusobelxy.png", sobelxy);
            cv::imwrite("kaydedilecekKlasor/dördüncüsorucannyedge.png", edges);
            cout << ("\x1B[31mResimler ve son halleri kaydedildi\033[0m\n");
        }
        else {
            cout << ("\x1B[31mkaydedilmeyecek\033[0m\n");
        }
        cout << "\x1B[33mTekrar duzenlemek istiyorsaniz evet yaziniz:\033[0m\n";
        std::string input11;
        cin >> input11;
        std::string kontrol11 = "evet";
        if (input11 == kontrol11)
        {
            main(argc, argv);
        }
        if (x == -1)
        {
            return 0;
        }
        else {
            cout << "Program sonlandirildi.\n";
            return 0;
        }

        destroyAllWindows();

    }
    if (x == 5)
    {
        Mat imgContrastHigh2;
        image.convertTo(imgContrastHigh2, -1, 2, 0); //Kontrastý 2artýrýr

        Mat imgContrastHigh4;
        image.convertTo(imgContrastHigh4, -1, 4, 0); //Kontrastý 4 artýrýr

        Mat imgContrastLow0_5;
        image.convertTo(imgContrastLow0_5, -1, 0.5, 0); //Kontrastý 0.5 azaltýr

        Mat imgContrastLow0_25;
        image.convertTo(imgContrastLow0_25, -1, 0.25, 0); //Kontrastý 0.25 azaltýr

        //Resimler için pencere adlarýný tanýmlýyoruz
        String pencereÝsmiorijinalresim = "Orijinal Resim";
        String pencereÝsmiContrastHigh2 = "Kontrastý 2 artirildi";
        String pencereÝsmiContrastHigh4 = "Kontrastý 4 artirildi";
        String pencereÝsmiContrastLow0_5 = "Kontrastý 0.5 azaltildi";
        String pencereÝsmiContrastLow0_25 = "Kontrastý 0.25 azaltildi";

        cout << "\x1B[33mciktiyi ekranda gormek istiyor musunuz? (istiyorsaniz evet yazin)\033[0m\n";
        string input9;
        cin >> input9;
        string kontrol9 = "evet";
        if (input9 == kontrol9)
        {
            //Resimleri oluþturulan pencerelerde gösterir.
            imshow(pencereÝsmiorijinalresim, image);
            waitKey(0);
            imshow(pencereÝsmiContrastHigh2, imgContrastHigh2);
            waitKey(0);
            imshow(pencereÝsmiContrastHigh4, imgContrastHigh4);
            waitKey(0);
            imshow(pencereÝsmiContrastLow0_5, imgContrastLow0_5);
            waitKey(0);
            imshow(pencereÝsmiContrastLow0_25, imgContrastLow0_25);
            waitKey(0);
            //Resimler için pencere oluþturur ve açar
            namedWindow(pencereÝsmiorijinalresim, WINDOW_NORMAL);
            namedWindow(pencereÝsmiContrastHigh2, WINDOW_NORMAL);
            namedWindow(pencereÝsmiContrastHigh4, WINDOW_NORMAL);
            namedWindow(pencereÝsmiContrastLow0_5, WINDOW_NORMAL);
            namedWindow(pencereÝsmiContrastLow0_25, WINDOW_NORMAL);

            destroyAllWindows();

        }
        else {
            cout << ("\x1B[31mcikti ekranda gosterilmeyecek\033[0m\n");
        }
        cout << "\x1B[33mPeki bu ciktiyi kaydetmek istiyor musunuz?(istiyorsaniz evet yaziniz)\033[0m\n";
        std::string input10;
        cin >> input10;
        std::string kontrol10 = "evet";
        if (input10 == kontrol10)
        {
            cv::imwrite("kaydedilecekKlasor/orjinal5soru.png", image);
            cv::imwrite("kaydedilecekKlasor/contrasthigh2.png", imgContrastHigh2);
            cv::imwrite("kaydedilecekKlasor/contrasthigh4.png", imgContrastHigh4);
            cv::imwrite("kaydedilecekKlasor/contrastlow05.png", imgContrastLow0_5);
            cv::imwrite("kaydedilecekKlasor/contrastlow025.png", imgContrastLow0_25);
            cout << ("\x1B[31mResimler ve son halleri kaydedildi\033[0m\n");
        }
        else
        {
            cout << ("\x1B[31mkaydedilmeyecek\033[0m\n");
        }


        cout << "\x1B[33mTekrar duzenlemek istiyorsaniz evet yaziniz:\033[0m\n";
        std::string input11;
        cin >> input11;
        std::string kontrol11 = "evet";
        if (input11 == kontrol11)
        {
            main(argc, argv);
        }
        if (x == -1)
        {
            return 0;
        }
        else {
            cout << "Program sonlandirildi.\n";
            return 0;
        }
        destroyAllWindows(); //Tüm açýk pencereleri kapatýr.
    }
    if (x == -1) {
        return -1;
    }
    if (x != 1 || x != 2 || x != 3 || x != 4 || x != 5) {
        cout << ("\x1B[31mHATALIISLEM! LUTFEN GECERLÝ SAYI GIRIN\033[0m\n");
        main(argc, argv);
    }

    return 0;
}