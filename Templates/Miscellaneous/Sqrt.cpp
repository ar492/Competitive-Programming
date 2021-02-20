int Sqrt(int num){ // same as ceil(sqrt(num)) in stl
       int lo=0, hi=num, ans;
       while(lo<=hi){ // rounding up
              int m=(lo+hi)/2;
              if(m*m==num) return m;
              if(m*m < num){
                     if((m+1)*(m+1)<num) ans=m+1, lo=m+1;
                     else return m+1;
              }
              if(m>0 && m*m>num) hi=m-1;
       }
       return ans;
}
