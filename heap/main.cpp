#include<iostream>
using namespace std;

struct Heap
{
    int size;
    int *H;
    int n;
};

void Insert(struct Heap *p,int x)
{
    int s,i=0;
    p->H[p->size+1]=x;
    p->size+=1;
    s=p->H[p->size];
    i=p->size;
    while(i>1&&p->H[i/2]<s)
    {
        p->H[i]=p->H[i/2];
        i=i/2;
    }
    p->H[i]=s;
}

void Delete(struct Heap *p)
{
    int s;
    s=p->H[1];
    p->H[1]=p->H[p->size];
    p->H[p->size]=s;
    int i=1;
    int j=2*i;
    while(j<p->size-1)
    {
        if(p->H[j]<p->H[j+1])
        {
            j=j+1;
        }
        if(p->H[i]<p->H[j])
        {
            s=p->H[i];
            p->H[i]=p->H[j];
            p->H[j]=s;
            i=j;
            j=2*j;
        }
        else
            break;
    }
    p->size--;
}

void Display(struct Heap p)
{
    for(int i=1;i<=p.size;i++)
        cout<<p.H[i]<<" ";
    cout<<endl;
}

int main()
{
    struct Heap p;
    p.size=7;
    p.n=11;
    p.H=(int*)malloc(sizeof(int)*(p.n));
    p.H[1]=30;p.H[2]=20;p.H[3]=15;p.H[4]=5;p.H[5]=10;p.H[6]=12;p.H[7]=6;
    Insert(&p,40);
    Display(p);
    Delete(&p);
    Delete(&p);
    Display(p);
}
