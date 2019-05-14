/*
Nama Program        :exercise-03
Nama                :Daniel Rama H.
NPM                 :140810180045
Tanggal buat        :14-05-2019
Deskripsi Program   :Tree
*/

#include<iostream>
using namespace std;

struct Simpul
{
    int info;
    Simpul* left;
    Simpul* right;
};

typedef Simpul* pointer;
typedef pointer Tree;

void CreateSimpul(pointer& pBaru)
{
    pBaru=new Simpul;
    cout<<"Masukkan simpul : ";cin>>pBaru->info;
    pBaru->left=0;
    pBaru->right=0;
}

void insertBST(Tree& root,pointer pBaru)
{
	if(root==NULL)
    {
		root=pBaru;
	}
	else if(pBaru->info<root->info)
	{
		insertBST(root->left,pBaru);
	}
	else if(pBaru->info>root->info)
	{
		insertBST(root->right,pBaru);
	}
	else
	{
		cout<<"sudah ada"<<endl;
	}
}

void notasiKurung(Tree Root)
{
    if(Root!=NULL)
    {
        cout<<"(";
        cout<<Root->info<<" ";
        notasiKurung(Root->left);
        notasiKurung(Root->right);
        cout<<")";
    }
}

void preOrder(Tree Root)
{
    if(Root!=NULL)
    {
        cout<<Root->info<<" ";
        preOrder(Root->left);
        preOrder(Root->right);
    }
}

void inOrder(Tree Root)
{
    if(Root!=NULL)
    {
        inOrder(Root->left);
        cout<<Root->info<<" ";
        inOrder(Root->right);
    }
}

void postOrder(Tree Root)
{
    if(Root!=NULL)
    {
        postOrder(Root->left);
        postOrder(Root->right);
        cout<<Root->info<<" ";
    }
}

int main(){
	pointer pb;
	Tree t;
    int n,pil;
    t=NULL;

    cout<<"Masukkan Banyak Simpul : ";cin>>n;
    for(int i=0;i<n;i++)
    {
        CreateSimpul(pb);
        insertBST(t,pb);
    }
    cout<<"Tree : ";
    notasiKurung(t);
    cout<<endl;
    do
    {
        cout<<"\MENU"<<endl;
        cout<<"[1]Pre Order"<<endl;
        cout<<"[2]In Order"<<endl;
        cout<<"[3]Post Order"<<endl;
        cout<<endl;
        cout<<"[0]Exit"<<endl;
        cout<<endl;
        cout<<"Pilihan : ";cin>>pil;
        switch (pil)
        {
        case 1:
            cout<<"Pre Order";
            preOrder(t);
            cout<<endl;
            break;

        case 2:
            cout<<"In Order";
            inOrder(t);
            cout<<endl;
            break;

        case 3:
            cout<<"Post Order";
            postOrder(t);
            cout<<endl;
            break;

        case 0:
            break;

        default:
            cout<<"Input Salah";
            break;
        }
    } while (pil!=0);

}
