struct pt{

    ll x,y;
    pt(): x(0), y(0) {}
    pt( ll x,  ll y) : x(x), y(y) {}

    pt operator+( pt  p){return pt(x+p.x,y+p.y);}
    pt operator-(pt p){return pt(x-p.x,y-p.y);}
    pt operator*( ll  factor){return pt(x*factor,y*factor);}
    pt operator/( ll  factor){return pt(x/factor,y/factor);}

};


struct Cmp { // IMPORTANT: add const in pt operator -
        pt r;
        Cmp(pt r): r(r) {}
        int cuad(const pt &a)const {
            if(a.x>0&&a.y>=0)return 0;
            if(a.x<=0&&a.y>0)return 1;
            if(a.x<0&&a.y<=0)return 2;
            if(a.x>=0&&a.y<0)return 3;
            assert(a.x==0&&a.y==0);
            return -1;
        }
        bool cmp(const pt& p1, const pt& p2)const {
            int c1=cuad(p1),c2=cuad(p2);
            if(c1==c2)return p1.y*p2.x<p1.x*p2.y;
            return c1<c2;
        }
        bool operator()(const pt& p1, const pt& p2)const {
            return cmp(p1-r,p2-r);
        }
};
istream& operator >> (istream& is, pt& point) {
  return is >> point.x >> point.y; }
ostream& operator << (ostream& os, const pt& point) {
  return os << point.x << ' ' << point.y; }