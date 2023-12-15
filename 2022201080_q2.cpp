#include<iostream>
using namespace std;
template <class T>
class dequee{
public:
int fr=-1;
int rear=-1;
int qsize;
int CountElm=0;
T *arr;
void dequeue()
{
    arr= new T[1000];
    qsize=1000;
    return;
}
void dequeue(int n,T x)
{
    arr= new T[n];
    int i;
    for(i=0;i<n;i++)
        arr[i]=x;
        qsize=n;
     fr=0;
     rear=n-1;
     CountElm=n;
       return;
}
void push_front(T x)
{
    if(empty())
    {
        fr+=1;
        rear+=1;
        arr[fr]=x;
    }
    else if(((rear+1)%qsize)==fr)
        {   int temp,i;
             temp=qsize;
            qsize=2*qsize;
            T *arrnew= new T[qsize];
            for(i=0;i<temp;i++)
                arrnew[i]=arr[i];
            arrnew[(qsize-1)]=x;
            for(i=temp;i<(qsize-1);i++)
                arrnew[i]=0;
            arr=arrnew;
            fr=(qsize-1);
        }
    else{
        fr=(fr-1+qsize)%qsize;
        arr[fr]=x;
    }
    CountElm+=1;
  return;
}
bool empty()
{
    if(fr==-1&&rear==-1)
        return true;
        return false;
}
void push_back(T x)
{
    if(empty())
    {   fr+=1;
        rear+=1;
        arr[rear]=x;
    }
    if(((rear+1)%qsize)==fr)
        {
             int temp,i;
             temp=qsize;
            qsize=2*qsize;
            T *arrnew= new T[qsize];
            for(i=0;i<temp;i++)
                arrnew[i]=arr[i];
            arrnew[temp]=x;
            for(i=temp+1;i<qsize;i++)
            arrnew[i]=0;
            arr=arrnew;
            rear=temp;
        }
    else{
        rear=(rear+1)%qsize;
        arr[rear]=x;
    }
    CountElm+=1;
}
void pop_back()
{
    if(empty())
        return;
    if(rear==fr)
    {
        rear=-1;
        fr=-1;
    }
    else{
        rear=(rear-1+qsize)%qsize;
    }

    CountElm-=1;
    return;
}
void pop_front()
{
    if(empty())
        return;
    if(fr==rear)
    {
        fr=-1;
        rear=-1;
    }
    else{
        fr=(fr+1)%qsize;
    }
    CountElm-=1;
    return;
}
void clear()
{
    fr=-1;
    rear=-1;
    CountElm=0;
    return;
}
int size()
{
    if(empty())
        return 0;
    return (CountElm);
}
T front()
{
    if(empty())
        return T();
    return arr[fr];
}
T back()
{
    if(empty())
    return T();
    return arr[rear];
}
T operator[](int n)
{
    if(n>=qsize)
        return T() ;
    return arr[n];
}
void resize(int x,T d)
{  int i;
   T *newarr= new T[x];
    if(x<qsize)
    {  for(i=0;i<x;i++)
       newarr[i]=arr[i];
    }
    else{
        for(i=0;i<qsize;i++)
            newarr[i]=arr[i];
        while(i<x)
        {
            newarr[i]=d;
            i++;
        }

    }
    arr=newarr;
    qsize=x;
    CountElm=x;
}
/*void Display()
{
    int i;
    for(i=0;i<qsize;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    cout<<fr<<" "<<rear<<endl;
    cout<<"size "<<qsize<<endl;
    return;
}*/
};
int main()
{   dequee<int> t1;
    int run=1,option,n,val,d,x;
    while(run)
    {
    cout<<"Enter Option"<<endl;
    cin>>option;

        switch(option)
        {
        case 1:
            t1.dequeue();
            break;
        case 2:
            cin>>n;
            cin>>val;
            t1.dequeue(n,val);
            break;
        case  3:
            cin>>val;
            t1.push_back(val);
            break;
        case  4:
            t1.pop_back();
            break;
        case  5:
            cin>>val;
            t1.push_front(val);
            break;
        case  6:
            t1.pop_front();
            break;
        case  7:
            cout<<t1.front()<<endl;
            break;
        case  8:
            cout<<t1.back()<<endl;
            break;
        case  9:
            cin>>n;
            cout<<t1[n]<<endl;
            break;
        case  10:
            cout<<t1.empty()<<endl;
            break;
        case  11:
            cout<<t1.size()<<endl;
            break;
        case  12:
            cin>>x;
            cin>>d;
            t1.resize(x,d);
            break;
        case  13:
            t1.clear();
            break;
        case  14:
            run=0;
            break;
        //case  15:
          //  t1.Display();
            //break;
        default:
            run=0;
            break;
        }

    }

  return 0;
}
