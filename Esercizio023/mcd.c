//Algoritmo di Euclide
int mcd(int x,int y) {
    
    if(x<y) {
        return mcd(y,x);
    }
    
    if(y==0) {
        return x;
    }
    
    if(x==y) {
        return y;
    } 
    
    return mcd(x-y,y);
}