#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int l[10005],f[10005],a[10],s[10],ans[10005],head,tot;
int main()
{
    int n,m;
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&l[i]);
        s[l[i]]++;//Ͱ��
    }
    for(int i=1;i<=m;i++)
    {
        a[i]=a[i-1]+s[i-1];//ǰ׺��
        for(int j=1;j<=s[i];j++)
        {
            f[++head]=i;
        }
    }
    tot=n+1;
    ans[--tot]=l[1];
    int now=l[1];
    //for(int i=1;i<=m;i++)
    //a[i]++;
    int pos=1;
    for(int i=n;i>0;i--)
    {
        ans[i]=l[pos];//��
        int x=l[pos];//��Ӧǰ׺��
        pos=a[x]+count(l+1,l+pos+1,x);//������ͬ�ַ��Ķ�Ӧλ��
    }
    for(int i=1;i<=n-1;i++)
    {
        printf("%d ",ans[i]);
    }
    printf("%d",ans[n]);
    puts("");
}
