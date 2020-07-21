#include <iostream>

using namespace std;

class link_list{
    public:
int data;
link_list *next;


};

link_list *head = nullptr;


void insert(int d){



link_list *new_node = new link_list;
new_node->data = d;




if(head == nullptr){
new_node->next = nullptr;
head = new_node;
}

else{
    new_node->next = head;
    head = new_node;
}

}

void traverse(){

link_list *temp = head;
while(temp != nullptr){
    cout<<temp->data<<endl;
    temp = temp->next;
}


}
void k_from_last(int k){
link_list *p1 = head;
link_list *p2 = head;

for(int i = 0; i<k;i++){

    p1 = p1->next;

}


while(p1 != nullptr){
    p1 = p1->next;
    p2 = p2->next;
}

cout<<"Kth from last is: "<<p2->data<<endl;

}


void reverse_list(){

link_list *prev,*n,*curr;
n = nullptr;
curr = head;
prev = nullptr;

while(curr != nullptr){

    n = curr->next;
    curr->next = prev;
    prev = curr;
    curr = n;


}

head = prev;


}


void delete_node(int d){

    link_list *temp = head;
    if(head->data == d){
        head = head->next;
        delete temp;
        return;
    }
    while((temp->next)->data != d){
        temp = temp->next;
    }
     link_list *temp2 = temp->next;
     temp->next = temp2->next;
     delete temp2;


}

int main()
{
   /* insert(1);
    insert(60);
    insert(15);
    insert(89);
    insert(8888);*/

    for(int i = 0;i<=100;i++){

        insert(i);

    }




    cout<<"head :"<<head->data<<endl;
    traverse();
    cout<<endl;
    k_from_last(10);
    reverse_list();
    cout<<"after reverse : ";
    cout<<"head :"<<head->data<<endl;
    traverse();
    int del_n;
    cout<<"enter key to delete"<<endl;
    cin>>del_n;
    delete_node(del_n);
    cout<<"after delete :"<<endl;

    traverse();
    return 0;
}
