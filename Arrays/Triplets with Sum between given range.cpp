bool isInA(double x) {
    if(x>0 && x < 2.0/3.0) return true;
    return false;
}
bool isInB(double x) {
    if(x>=2.0/3.0 && x < 1.0) return true;
    return false;
}
bool isInC(double x) {
    if(x>=1.0 && x < 2.0) return true;
    return false;
}
int Solution::solve(vector<string> &A) {
    double max1A = INT_MIN, max2A = INT_MIN, max3A = INT_MIN, max1B = INT_MIN;
    double min1A = INT_MAX,min2A= INT_MAX,min3A= INT_MAX,min1B= INT_MAX,min2B= INT_MAX,min1C= INT_MAX;
    for(auto x : A) {
        double ele = stod(x);
        if(isInA(ele)) {
            // maximum value updation
            if(ele >= max1A) {
                max3A = max2A;
                max2A = max1A;
                max1A = ele;
            } else if( ele >= max2A) {
                max3A = max2A;
                max2A = ele;
            } else if( ele >= max3A) {
                max3A = ele;
            }
            // minimum value updation
            if(ele <= min1A) {
                min3A = min2A;
                min2A = min1A;
                min1A = ele;
            } else if( ele <= min2A) {
                min3A = min2A;
                min2A = ele;
            } else if( ele <= min3A) {
                min3A = ele;
            }
            
        } else if(isInB(ele)){
            // maximum value updation
            if( ele >= max1B) {
                max1B = ele;
            }
            // minimum value updation
            if( ele <= min1B) {
                min2B = min1B;
                min1B = ele;
            } else if( ele <= min2B) {
                min2B = ele;
            }
        } else if(isInC(ele)) {
            // min value updation
            if(ele <= min1C) {
                min1C = ele;
            }
        }
    }
    
    // case a a a
    if(max1A + max2A + max3A > 1.0) return 1;
    // Tricky case -- Have to figure out why this works
    // case a a b
    if(min1A + min2A + min1B > 1.0 && min1A + min2A + min1B < 2.0 ) return 1;
    if(max1A + max2A + max1B > 1.0 && max1A + max2A + max1B < 2.0) return 1;
    // case a a c
    if(min1A + min2A + min1C < 2.0) return 1;
    // case a b b
    if(min1A + min1B + min2B < 2.0) return 1;
    // case a b c
    if(min1A + min1B + min1C < 2.0) return 1;
    return 0;
}
