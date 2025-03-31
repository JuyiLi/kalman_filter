#include "kalman_filter.h" 

kalman_filter::kalman_filter(double setQ, double setR)
{
    //Q is 过程噪声协方差; R is 测量噪声协方差，即测量精度
    Q = setQ;
    R = setR;
}  

kalman_filter::~kalman_filter()
{

} 


void kalman_filter::kalman_filter_1d(const double x_real, double &x_after_filter)
{   
	P = P+Q;
	K = P/(P+R);
    x_after_filter = A*x_after_filter + K*(x_real-x_after_filter);
    P = (1-K)*P;
    return;
}  

void kalman_filter::kalman_filter_1d(double * x_real, double * x_after_filter)
{
    for (int i=0; i<6; i++)
    {
        p_array[i] = p_array[i]+Q;
        K = p_array[i]/(p_array[i]+R);
        x_after_filter[i] = A*x_after_filter[i] + K*(x_real[i]-x_after_filter[i]);
        p_array[i] = (1-K)*p_array[i];
    }
    return;
}
