#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <opencv2/opencv.hpp>

using namespace cv;

void definindoRx(Mat I, Mat Rx) {
  for (int i = 1; i < I.rows-1; i++) { //Calculando Rx...
    for (int j = 1; j < I.cols-1; j++) {
      int temp_x = (I.at<uchar>(i+1, j-1) + I.at<uchar>(i+1, j) + I.at<uchar>(i+1, j+1)) -
        (I.at<uchar>(i-1, j-1) + I.at<uchar>(i-1, j) + I.at<uchar>(i-1, j+1));

      temp_x = std::clamp(std::abs(temp_x), 0, 255); // Ajustando valores negativos e limitando até 255
      Rx.at<uchar>(i, j) = temp_x; // Atribuindo os valores ajustados a Rx 
    }
  }
}

void definindoRy(Mat I, Mat Ry) {
  for (int i = 1; i < I.rows-1; i++) { //Calculando Ry...
    for (int j = 1; j < I.cols-1; j++) {
      int temp_y = (I.at<uchar>(i-1, j+1) + I.at<uchar>(i, j+1) + I.at<uchar>(i+1, j+1)) -
        (I.at<uchar>(i-1, j-1) + I.at<uchar>(i, j-1) + I.at<uchar>(i+1, j-1));

      temp_y = std::clamp(std::abs(temp_y), 0, 255); // Ajustando valores negativos e limitando até 255
      Ry.at<uchar>(i, j) = temp_y; // Atribuindo os valores ajustados a Ry
    }
  }
}

int main() {
  // Carregando a imagem
  cv::Mat I = cv::imread("coins.png", IMREAD_GRAYSCALE);

  // Criando imagens Rx, Ry e R
  Mat Rx = Mat::zeros(I.rows, I.cols, CV_8UC1);  // Definindo Rx -> Altura x Largura
  Mat Ry = Mat::zeros(I.rows, I.cols, CV_8UC1);  // Definindo Ry -> Altura x Largura
  Mat R  = Mat::zeros(I.rows, I.cols, CV_8UC1);  // Definindo R  -> Altura x Largura

  // Calculando Rx e Ry
  definindoRx(I, Rx);
  definindoRy(I, Ry);

  // Combinando Rx e Ry em R
  for (int i = 0; i < I.rows; i++) {
    for (int j = 0; j < I.cols; j++) {
      R.at<uchar>(i, j) = std::clamp(Rx.at<uchar>(i, j) + Ry.at<uchar>(i, j), 0, 255);
    }
  }

  // Salvando a imagem resultante
  std::string output_filename = "coins_filtered.png";
  imwrite(output_filename, R);

  return 0;
}