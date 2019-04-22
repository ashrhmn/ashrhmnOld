#include <iostream>
using namespace std;
typedef struct listNode{
    int data;
    listNode *next, *prev;
}*nodeptr;
nodeptr head=NULL, tail=NULL;
int i=0;
string emptyNode="\nList Empty, Add data First\n";
void addData(int x){
    nodeptr newNode=new listNode;
    newNode->data=x;
    newNode->next=NULL;
    newNode->prev=NULL;
    if(head==NULL){
        head=newNode;
    }
    else{
        newNode->prev=tail;
        tail->next=newNode;
        newNode->next=NULL;
    }
    tail=newNode;
    ++i;
}
void traverse(){
    nodeptr p = head;
    cout<<"\nData(From First): ";
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
void showReverse(){
    nodeptr p = tail;
    cout<<"\nData(From Last): ";
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->prev;
    }
    cout<<endl;
}
void insert(int pos,int x){
    nodeptr newNode=new listNode;
    nodeptr p=head;
    newNode->data=x;
    newNode->prev=NULL;
    while(--pos){
        p=p->next;
    }
    newNode->next=p;
    if(p==head){
        head->prev=newNode;
        head=newNode;
    }
    else{
        newNode->prev=p->prev;
        p->prev->next=newNode;
        p->prev=newNode;
    }
    ++i;
    traverse();
}
void deletion(int pos){
    nodeptr p=head;
    while(--pos){
        p=p->next;
    }
    if(p==head){
        head=head->next;
    }
    else{
        p->prev->next=p->next;
    }
    if(p==tail){
        tail=tail->prev;
    }
    else{
        p->next->prev=p->prev;
    }
    --i;
    traverse();
}
void clearNode(){
    head=NULL;
    tail=NULL;
    i=0;
    cout<<"\nCleared all data\n";
}
bool search(int item){
    nodeptr p = head;
    bool found = false;
    while(p!=NULL){
        if(p->data==item){
            found=true;
            break;
        }
        p=p->next;
    }
    return found;
}
void sortList(){
    nodeptr p = new listNode;
    bool sorted = false;
    while(!sorted){
        p=head;
        while(p->next!=NULL){
            if(p->data>p->next->data){
                swap(p->data,p->next->data);
            }
            p=p->next;
        }
        p=head;
        sorted=true;
        while(p->next!=NULL){
            if(p->data>p->next->data){
                sorted=false;
            }
            p=p->next;
        }

    }

}
int main(){
    int x,pos,opt;
    while(1){
        cout<<endl<<"1.Display From First\n2.Display From Last\n3.Batch Add Data\n4.Insert at(Position)\n5.Delete at(Position)\n6.Search\n7.Sort List\n8.Clear All Data\n0.Exit\n";
        cin>>opt;
        if(!opt){break;}
        switch (opt){
            case 1:
            {
                traverse();
                break;
            }
            case 2:
            {
                showReverse();
                break;
            }
            case 3:
            {
                cout<<"Enter data(\'0\' to Exit):"<<endl;
                while(1){
                    cin>>x;
                    if(!x){break;}
                    addData(x);
                }
                traverse();
                break;
            }
            case 4:
            {
                if(i){
                    cout<<"Insert at(Position no<="<<i<<"): ";
                    cin>>pos;
                    cout<<"Insert: ";
                    cin>>x;
                    insert(pos,x);
                }
                else{
                    cout<<emptyNode;
                }
                break;
            }
            case 5:
            {
                if(i){
                    cout<<"Delete at(Position no<="<<i<<"): ";
                    cin>>pos;
                    deletion(pos);
                }
                else{
                    cout<<emptyNode;
                }
                break;
            }
            case 6:
            {
                cout<<"Search for : ";
                cin>>x;
                if(search(x)){
                    cout<<x<<" found"<<endl;
                }
                else{
                    cout<<x<<" not found"<<endl;
                }
                break;
            }
            case 7:
            {
                sortList();
                cout<<"Data Sorted"<<endl;
                traverse();
                break;
            }
            case 8:
            {
                clearNode();
                break;
            }
            default:
            {
                break;
            }
        }
    }
}
