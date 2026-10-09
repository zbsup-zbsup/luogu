#include <bits/stdc++.h>

using namespace std;

#define dIO_USE_BUFFER
struct IO{
#ifdef dIO_USE_BUFFER
const static int BUFSIZE=1<<20;char ibuf[BUFSIZE],obuf[BUFSIZE],*p1,*p2,*pp;inline int getchar(){return(p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,BUFSIZE,stdin),p1==p2)?EOF:*p1++);}inline int putchar(char x){return((pp-obuf==BUFSIZE&&(fwrite(obuf,1,BUFSIZE,stdout),pp=obuf)),*pp=x,pp++),x;}inline IO&flush(){return fwrite(obuf,1,pp-obuf,stdout),pp=obuf,fflush(stdout),*this;}IO(){p1=p2=ibuf,pp=obuf;}~IO(){flush();}
#else
int(*getchar)()=&::getchar;int(*putchar)(int)=&::putchar;inline IO&flush(){return fflush(stdout),*this;}
#endif
string _sep=" ";int k=2;template<typename Tp,typename enable_if<is_integral<Tp>::value||is_same<Tp,__int128_t>::value>::type* =nullptr>inline int read(Tp&s){int f=1,ch=getchar();s=0;while(!isdigit(ch)&&ch!=EOF)f=(ch=='-'?-1:1),ch=getchar();if(ch==EOF)return false;while(ch=='0')ch=getchar();while(isdigit(ch))s=s*10+(ch^48),ch=getchar();s*=f;return true;}template<typename Tp,typename enable_if<is_floating_point<Tp>::value>::type* =nullptr>inline int read(Tp&s){int f=1,ch=getchar();s=0;while(!isdigit(ch)&&ch!='.'&&ch!=EOF)f=(ch=='-'?-1:1),ch=getchar();if(ch==EOF)return false;while(isdigit(ch))s=s*10+(ch^48),ch=getchar();if(ch=='.'){Tp eps=0.1;ch=getchar();while(isdigit(ch))s=s+(ch^48)*eps,ch=getchar(),eps/=10;}s*=f;return true;}inline int read(char&ch){ch=getchar();while(isspace(ch)&&ch!=EOF)ch=getchar();return ch!=EOF;}inline int read(char*c){char ch=getchar(),*s=c;while(isspace(ch)&&ch!=EOF)ch=getchar();while(!isspace(ch)&&ch!=EOF)*(c++)=ch,ch=getchar();*c='\0';return s!=c;}inline int read(string&s){s.clear();char ch=getchar();while(isspace(ch)&&ch!=EOF)ch=getchar();while(!isspace(ch)&&ch!=EOF)s+=ch,ch=getchar();return s.size()>0;}template<typename Tp=int>inline Tp read(){Tp x;read(x);return x;}template<typename Tp,typename...Ts>inline int read(Tp&x,Ts&...val){return read(x)&&read(val...);}inline int getline(char*c,const char&ed='\n'){char ch=getchar(),*s=c;while(ch!=ed&&ch!=EOF)*(c++)=ch,ch=getchar();*c='\0';return s!=c;}inline int getline(string&s,const char&ed='\n'){s.clear();char ch=getchar();while(ch!=ed&&ch!=EOF)s+=ch,ch=getchar();return s.size()>0;}template<typename Tp,typename enable_if<is_integral<Tp>::value||is_same<Tp,__int128_t>::value>::type* =nullptr>inline IO&write(Tp x){if(x<0)putchar('-'),x=-x;static char sta[41];int top=0;do sta[top++]=x%10^48,x/=10;while(x);while(top)putchar(sta[--top]);return*this;}inline IO&write(const string&str){for(char ch:str)putchar(ch);return*this;}inline IO&write(const char*str){while(*str!='\0')putchar(*(str++));return*this;}inline IO&write(char*str){return write((const char*)str);}inline IO&write(const char&ch){return putchar(ch),*this;}template<typename Tp,typename enable_if<is_floating_point<Tp>::value>::type* =nullptr>inline IO&write(Tp x){if(x>1e18||x<-1e18){write("[Floating point overflow]");throw;}if(x<0)putchar('-'),x=-x;const static long long pow10[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000,100000000000,1000000000000,10000000000000,100000000000000,1000000000000000,10000000000000000,100000000000000000,100000000000000000,100000000000000000};const auto&n=pow10[k];long long whole=x;double tmp=(x-whole)*n;long long frac=tmp;double diff=tmp-frac;if(diff>0.5){++frac;if(frac>=n)frac=0,++whole;}else if(diff==0.5&&((frac==0U)||(frac&1U)))++frac;write(whole);if(k==0U){diff=x-whole;if((!(diff<0.5)||(diff>0.5))&&(whole&1))++whole;}else{putchar('.');static char sta[21];int count=k,top=0;while(frac){sta[top++]=frac%10^48;frac/=10,count--;}while(count--)putchar('0');while(top)putchar(sta[--top]);}return*this;}template<typename Tp,typename...Ts>inline IO&write(Tp x,Ts...val){return write(x),write(_sep),write(val...),*this;}template<typename...Ts>inline IO&writeln(Ts...val){return write(val...),putchar('\n'),*this;}template<typename...Ts>inline IO&writesp(Ts...val){return write(val...),putchar(' '),*this;}inline IO&writeln(void){return putchar('\n'),*this;}inline IO&sep(const string&s=" "){return _sep=s,*this;}inline IO&prec(const int&K=2){return k=K,*this;}}io;

typedef long long ll;

const int MAXN = 1e5 + 10;
const int B = 3500;

int T, n, m, q, d[MAXN];
bitset<MAXN> f[MAXN];

vector<int> g[MAXN], t, tmp;

int tot, a[MAXN], b[MAXN], p[MAXN];
bool vis[MAXN];

int op[MAXN], x[MAXN], y[MAXN], z[MAXN], dp[MAXN], ans[MAXN];

int main()
{
    for (io.read(T, T); T--;)
    {
        io.read(n, m, q);
        for (int i = 1; i <= n; i++)
            g[i].clear();
        for (int i = 1, u, v; i <= m; i++)
            io.read(u, v), g[v].emplace_back(u), d[u]++;
        t.clear();
        for (int i = 1; i <= n; i++)
            if (!d[i])
                t.emplace_back(i);
        for (int i = 0; i < n; i++)
            for (int v : g[t[i]])
                if (!--d[v])
                    t.emplace_back(v);
        for (int i = 1; i <= n; i++)
            f[i].reset(), f[i].set(i);
        for (int u : t)
            for (int v : g[u])
                f[v] |= f[u];
        for (int i = 1; i <= n; i++)
            io.read(a[i]), p[a[i]] = i;
        for (int i = 1; i <= n; i++)
            io.read(b[i]);
        for (int i = 1; i <= q; i++)
        {
            io.read(op[i], x[i], y[i]);
            if (op[i] == 3)
                io.read(z[i]);
        }
        for (int i = 1; i <= q; i++)
            ans[i] = 0;
        for (int lq = 1; lq <= q; lq += B)
        {
            int rq = min(lq + B - 1, q);
            tmp.clear();
            for (int i = 1; i <= n; i++)
                vis[i] = 0;
            for (int i = lq; i <= rq; i++)
                if (op[i] <= 2)
                    vis[x[i]] = vis[y[i]] = 1;
            for (int i = 1; i <= n; i++)
                if (vis[i])
                    tmp.emplace_back(i);
            for (int lv = 1; lv <= n; lv += B)
            {
                int rv = min(lv + B - 1, n);
                for (int i = 1; i <= n; i++)
                    dp[i] = 0;
                for (int i = lv; i <= rv; i++)
                    if (!vis[p[i]])
                        dp[p[i]] = b[p[i]];
                for (int u : t)
                    for (int v : g[u])
                        dp[v] = max(dp[v], dp[u]);
                for (int i = lq; i <= rq; i++)
                {
                    if (op[i] == 3 && y[i] <= lv && z[i] >= rv)
                        ans[i] = max(ans[i], dp[x[i]]);
                }
            }
            for (int i = lq; i <= rq; i++)
            {
                if (op[i] < 3)
                    continue;
                int lp = (y[i] - 1) / B * B + B, rp = (z[i] - 1) / B * B + 1;
                if (lp > rp)
                {
                    for (int j = y[i]; j <= z[i]; j++)
                    {
                        if (f[x[i]][p[j]] && !vis[p[j]])
                            ans[i] = max(ans[i], b[p[j]]);
                    }
                }
                else
                {
                    for (int j = y[i]; j <= lp; j++)
                    {
                        if (f[x[i]][p[j]] && !vis[p[j]])
                            ans[i] = max(ans[i], b[p[j]]);
                    }
                    for (int j = rp; j <= z[i]; j++)
                    {
                        if (f[x[i]][p[j]] && !vis[p[j]])
                            ans[i] = max(ans[i], b[p[j]]);
                    }
                }
            }
            for (int i = lq; i <= rq; i++)
            {
                if (op[i] == 1)
                    swap(a[x[i]], a[y[i]]), swap(p[a[x[i]]], p[a[y[i]]]);
                if (op[i] == 2)
                    swap(b[x[i]], b[y[i]]);
                if (op[i] == 3)
                {
                    for (int u : tmp)
                    {
                        if (f[x[i]][u] && y[i] <= a[u] && a[u] <= z[i])
                            ans[i] = max(ans[i], b[u]);
                    }
                }
            }
        }
        for (int i = 1; i <= q; i++)
            if (op[i] == 3)
                io.writeln(ans[i]);
    }
}
