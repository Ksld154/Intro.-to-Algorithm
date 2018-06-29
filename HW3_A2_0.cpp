#include <iostream>
#define ull unsigned long long 
using namespace std;


ull func(ull a, ull b, ull c, int index){
    return a*(index*index) + b*index + c;
}

int main(int argc, char const *argv[])
{
    int M;
    cin >> M;
    while(M--) {
        ull p, q, r, x, y, z, N;
        cin >> p >> q >> r;
        cin >> x >> y >> z;
        cin >> N; 

        ull a, a2, b, b2;
        ull a_i = N/2, b_i = N/2;
 

        if(N % 2 == 1){
            for(int i = N/2; i >= 0; i /= 2){
                a = func(p, q, r, i);
                b = func(x, y, z, i);
                a2 = func(p, q, r, i+1);
                b2 = func(x, y, z, i+1);
                cout << a << " " << a2 << " " << b  << " " << b2 << endl;
                if(a > b && a <= b2)
                    break;
                else if(b > a && b <= a2)
                    break;
                else if(a > b && a > b2){
                    a_i -= i;
                    b_i += i;
                }
                else{
                    b_i -= i;
                    a_i += i;
                }
            }
            if(a > b)
                cout << a << endl;
            else 
                cout << b << endl;
        }
        
    }
    return 0;
}















