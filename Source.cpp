#pragma warning(disable : 4996)
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>

//#include "Header.h"
void ScanDegre(float, int*);

using namespace std;
using namespace cv;

int main()
{
    //remove("C:/Users/henry/Desktop/Project2/x64/Debug/Lepton_Capture7.tiff");
    FILE* pFile = new FILE;
    unsigned short* buffer;
    float degre, somme = 0;
    size_t result, nombre_de_valeur = 160 * 120;
    int total_moyenne, tour = 0, analyse[6] = { 0,0,0,0 };
    short int i;
    int numero_de_case;
    int numero_ligne;
    int numero_colonne;
   



    VideoCapture cap;
    Mat frame;
    cap.open(0);
    int deviceID = 0;             // 0 = ouverture de  la caméra par défaut 
    int apiID = CAP_ANY;      // 0 = détection de l'API par défaut
    // ouvrir la caméra à l'aide de l'Api sélectionnée
    cap.open(deviceID, apiID);
    resizeWindow("Display frame", 160, 120);

    while (0)
    {
        cap.read(frame);

        imshow("Display frame", frame);
        waitKey(10);
    }

   //imwrite("C:/Users/henry/Desktop/Project2/x64/Debug/Lepton_Capture7.tiff", frame);
    pFile = fopen("C:/Users/henry/Desktop/Project2/x64/Debug/Lepton_Captur6.tiff", "rb");
    new unsigned short[160 * 120];
    buffer = (unsigned short*)malloc(160 * 120 * 2);
    nombre_de_valeur = fread(buffer, sizeof(short int), 160 * 120, pFile);

    for (i = 4; i < (160 * 120) -1; i++)
    {




        degre = (buffer[i] - 27315) / 100;
        somme += degre;
        ScanDegre(degre, &analyse[0]);
        numero_de_case = i-3;
        numero_ligne = (numero_de_case-1) / 160 + 1;
         numero_colonne =  (numero_de_case-1) % 160 + 1;
         printf("\n position: colonne=%d ligne=%d", numero_colonne, numero_ligne);
         printf("     T=  %f \n ", degre);

         


    }
    printf("\n résultats: cas1=%d cas2=%d cas3=%d", analyse[0], analyse[1], analyse[2]);
   
    return 0;
}




void ScanDegre(float degre, int* analyse) {


    float temperature_basse = 20.0, temperature_moyenne = 25.0, temperature_haute = 35.0;
    if ((degre <= temperature_basse)) {
        //printf("cas1\n");
        analyse[0] += 1;
    }
    else if (degre > temperature_basse && degre <= temperature_haute) {
        //printf("cas2\n");
        analyse[1] += 1;
    }
    else if (degre > temperature_haute)
    {
        //printf("cas3\n");
        analyse[2] += 1;
    }




    // compter le nombre de 'pixel' > 30°  > 40 > 50  > 60  > 70 
    /*
    if (degre >= 30 && degre <= 40)
    {
        analyse[0] += 1;
    }
    if (degre >= 40 && degre <= 50)
    {
        analyse[1] += 1;
    }
    if (degre >= 50 && degre <= 60)
    {
        analyse[2] += 1;
    }
    if (degre >= 60 && degre <= 70)
    {
        analyse[3] += 1;
    }
    if (degre >= 70)
    {
        analyse[4] += 1;
    }
    */
    
}
