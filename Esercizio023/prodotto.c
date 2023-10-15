int prodotto(int x, int y) {
    if(x<y) {
        return prodotto(y,x);
    }
    
    if(y==0) {
        return 0;
    }
    
    if(y==1) {
        return x;
    }
    
    return y+prodotto(x-1,y);
}