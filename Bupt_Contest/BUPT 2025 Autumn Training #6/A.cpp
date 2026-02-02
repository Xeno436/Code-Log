#include <iostream>
#include <algorithm>
using namespace std;

double eabs(double a, double b, double c, double d)
{
    if (a > c)
    {
        swap(a, c);
        swap(b, d);
    }
    if (b > d)
    {
        double e_ad_cd = eabs(a, d, c, d);
        double p_ad_cd = (d - a) / (b - a);
        double e_db_cd = (b - c) / 2.0;
        double p_db_cd = (b - d) / (b - a);
        return e_ad_cd * p_ad_cd + e_db_cd * p_db_cd;
    }
    double n = max(b - c, 0.0);
    double e_ab_cd = (c + d - a - b) / 2.0;
    double e_cb_cb = n / 3.0;
    double p_cb_cb = n / (b - a) * n / (d - c);
    return e_ab_cd + e_cb_cb * p_cb_cb;
}