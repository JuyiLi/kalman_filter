#ifndef kalman_filter_H
#define kalman_filter_H

#include <stdio.h>   

class kalman_filter
{
public:	

    /**
     * @param setQ 设置过程噪声Q，越小系统越容易收敛，我们对模型预测的值信任度越高；但是太小则容易发散，如果Q为零，那么我们只相信预测值；Q值越大我们对于预测的信任度就越低，而对测量值的信任度就变高；如果Q值无穷大，那么我们只信任测量值；
     * @param setR 设置测量噪声R，R太大，卡尔曼滤波响应会变慢，因为它对新测量的值的信任度降低；越小系统收敛越快，但过小则容易出现震荡；R值的改变主要是影响卡尔曼的收敛速度。
    **/
    kalman_filter(double setQ = 0.001, double setR = 1);

	~kalman_filter(); 

	//public members here;
	//including variables and functions you want to call in scripts;
	int dimension = 1;
    double dt = 1;
    double A = 1;
    double H = 1;
    double K = 0;
    double Q = 0.001;
    double R = 1;
    double P = 1;
    double p_array[6] = {1, 1, 1, 1, 1, 1};

    /**
     * @brief 一阶卡尔曼滤波
     * @param x_real  真实值
     * @param x_after_filter 滤波后的值
    **/
    void kalman_filter_1d(const double x_real, double &x_after_filter);

    /**
     * @brief 一阶卡尔曼滤波(double[6])
     * @param x_real 真实值(double[6])
     * @param x_after_filter 滤波后的值(double[6])
    **/
    void kalman_filter_1d(double * x_real, double * x_after_filter);

protected:


private:

};

#endif
