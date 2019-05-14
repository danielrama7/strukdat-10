/*
Nama Program        :exercise-01
Nama                :Daniel Rama H.
NPM                 :140810180045
Tanggal buat        :14-05-2019
Deskripsi Program   :Queue Array
*/

#include<iostream>
using namespace std;

const int maxElemen=255;
struct Queue
{
    char isi[maxElemen];
    int head;
    int tail;
};
Queue q;
void createQueue (Queue& q)
{
    q.head=0;
    q.tail=-1;
}

void insertQueue(Queue& q, char element)
{
    if(q.tail==maxElemen-1)
    {
        cout<<"Sudah penuh"<<endl;
    }
    else
    {
        q.tail=q.tail+1;
        q.isi[q.tail]=element;
    }
}

void deleteQueue(Queue& q, char& elemenHapus)
{
    if(q.head>q.tail)
    {
        cout<<"Data kosong"<<endl;
    }
    else
    {
        elemenHapus= q.isi[q.head];
        for (int i=0;i<q.tail;i++)
        {
            q.isi[i]=q.isi[i+1];
        }
        q.tail=q.tail-1;
    }
}

int main()
{
    char a;
    Queue q;
    int n;

    createQueue(q);
    cout<<"Masukkan jumlah Data : ";cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Masukkan data : ";cin>>a;
        insertQueue(q,a);
    }
    cout<<"Queue : ";
    for(int i=0;i<n;i++)
    {
        cout<<q.isi[i]<<" ";
    }
    cout<<endl;
    deleteQueue(q,a);
    cout<<"Setelah delete : ";
    for(int i=0;i<n-1;i++)
    {
        cout<<q.isi[i]<<" ";
    }
    cout<<endl;

}
