#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>
#include <stdio.h>

int main(int argc, char *argv[]) {
  // GpuMat
  cv::Mat src = cv::imread("turing_white.png");
  cv::Mat dst;

  std::chrono::system_clock::time_point start, end;
  double elapsed;

  float matrix[9] = {9.45135927e-01, -4.92482404e-02, -9.16291224e+01,
                     1.86556287e-02, 9.08238651e-01,  1.29333648e+01,
                     1.78247084e-05, -4.62799593e-05, 9.97536602e-01};

  cv::Mat M = cv::Mat(3, 3, CV_32F, matrix);
  start = std::chrono::system_clock::now();
  for (int i = 0; i < 100; i++) {
    cv::warpPerspective(src, dst, M, cv::Size(src.cols, src.rows),
                        cv::INTER_LINEAR, cv::BORDER_CONSTANT, 1);
  }
  end = std::chrono::system_clock::now();
  elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
                .count();
  printf("opencv 100 loop: %lf \n", elapsed);

  return 0;
}
