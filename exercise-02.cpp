/*
Nama Program        :exercise-02
Nama                :Daniel Rama H.
NPM                 :140810180045
Tanggal buat        :14-05-2019
Deskripsi Program   :Queue Linked List
*/

#include<iostream>
using namespace std;

struct ElemenQueue {
    char info;
    ElemenQueue* next;
};
typedef ElemenQueue* pointer;
typedef pointer List;

struct Queue
{
    List Head;
    List Tail;
};
Queue q;

void createList(Queue& q)
{
	q.Head = NULL;
    q.Tail = NULL;
}

void createElemt(pointer& pBaru)
{
	pBaru=new ElemenQueue;
	cout<<"Masukkan data : ";
	cin>>pBaru->info;
	pBaru->next=NULL;
}

void cetak(Queue q)
{
    pointer pBantu=q.Head;
    if(q.Head==NULL && q.Tail==NULL)
    {
        cout<<"Data kosong"<<endl;
    }
    else
    {
        while(pBantu!=NULL)
        {
            cout<<pBantu->info<<" ";
            pBantu=pBantu->next;
        }
    }
}

void traversal(List First)
{
	pointer pBantu;
	if(First==NULL)
    {
		cout<<"data kosong"<<endl;
	}
	else
	{
		pBantu=First;
		do
		{
			cout<<pBantu->info;
			pBantu=pBantu->next;
		}
        while(pBantu!=NULL);
	}
}

void insertQueue(Queue& q, pointer pBaru)
{
    if(q.Head==NULL && q.Tail==NULL)
    {
        q.Head=pBaru;
        q.Tail=pBaru;
    }
    else
    {
        q.Tail->next=pBaru;
        q.Tail=pBaru;
    }
}

void deleteQueue(Queue& q, pointer& pHapus)
{
    if(q.Head==NULL && q.Tail==NULL)
    {
        pHapus=NULL;
        cout<<"Data kosong "<<endl;
    }
    else if(q.Head->next==NULL)
    {
        pHapus=q.Head;
        q.Head=NULL;
        q.Tail=NULL;
    }
    else
    {
        pHapus=q.Head;
        q.Head=q.Head->next;
        pHapus->next=NULL;
    }
}

int main()
{
    Queue q;
    pointer p;
    int n;

    createList(q);
    cout<<"Masukkan jumlah data : ";cin>>n;
    for(int i=0;i<n;i++)
    {
        createElemt(p);
        insertQueue(q,p);
    }
    cout<<"Queue : ";
    cetak(q);
    cout<<endl;
    deleteQueue(q,p);
    cout<<"Setelah delete : ";
    cetak(q);
    cout<<endl;
}
