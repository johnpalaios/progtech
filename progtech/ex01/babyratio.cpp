 #ifndef CONTEST
 #include "babyratio.hpp"
 #include <iostream>
 using namespace std;
 #endif

 using namespace std;

 rational::rational (int n, int d) { nom=n;den=d; }
 rational rational::add (rational r) { return rational(nom*r.den+den*r.nom,r.den*den);}
 rational rational::sub (rational r) { return rational(nom*r.den-den*r.nom,r.den*den);}
 rational rational::mul (rational r) { return rational(nom*r.nom,r.den*den);}
 rational rational::div (rational r) { return rational(nom*r.den,r.nom*den);}
 int rational:: gcd(int a,int b) {if(a==0) return b;return gcd(b%a,a);}
 void rational::print() {
                           int j=gcd(nom,den);
                           int k=abs(j);
                           if(nom==0) {cout<<nom<<"/"<<abs(den)/k; return;}
                           if(nom<0&&den<0) {cout<<abs(nom)/k<<"/"<<abs(den)/k; return;}
                           if(nom>=0 && den>=0) {cout <<nom/k<<"/"<<den/k; return;}
                           if(nom<0||den<0) cout<<"-"<<abs(nom)/k<<"/"<<abs(den)/k;
                        }



