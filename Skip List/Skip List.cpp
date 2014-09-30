#include <iostream>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include<ctime>
#define ninf -10000
#define pinf 10000000
using namespace std;
int grand(float t){
    float p=1.0*rand()/RAND_MAX;
  //  cout<<p<<endl;
    if(p<t) return 1;
    else return 0;
}
///////////////////////////////////////////////////////////////////////////////
class node{
      public:
      float x;
      node *up;
      node *down;
      node *prev;
      node *next;
      int gap;
      };

//////////////////////////////////////////////////////////////////////////////
class stack{
      public:
      int top;
      node* A[1000];
      stack(){
              top=-1;
              }
              
void  push(node *t){
                A[++top]=t;
                }
node *pop(){
       if(top==-1) return NULL;
       else return A[top--];
       }
       };
      
//////////////////////////////////////////////////////////////////////////////////

      
class skipl{
      public:
      node *head;
      node *tail;
      node *curr;
      int n;
////////////////////////////////////////////////////////////////////////////////
      skipl(){
              tail= new node;
              head= new node;
              tail->x=pinf;
              head->x=ninf;
              tail->prev=head;
              tail->next=NULL;
              tail->up=NULL;
              tail->down=NULL;
              head->next=tail;
              head->prev=NULL;
              head->up=NULL;
              head->down=NULL;
               n=0;   
               head->gap=1; 
               tail->gap=-1;         
              }
/////////////////////////////////////////////////////////////////////////////////              
void print(){
     node *curr2;
     curr=head;
     while(curr!=NULL){
                       curr2=curr;
                       while( curr2!=NULL){
                              cout<<curr2->x<<" g"<<curr2->gap<<"   ";
                              curr2=curr2->next;
                              }
                              
                              curr=curr->down;
                              cout<<endl;
                       }
     }
////////////////////////////////////////////////////////////////////////////////
node *search(float k){
     curr=head;
     while(curr!=NULL){
                       if(k > curr->next->x){ curr=curr->next; }
                       else if(k< curr->next->x){ curr=curr->down;}
                       else {
                            return curr->next; 
                            }
                            }
     return NULL;
     }
////////////////////////////////////////////////////////////////////////////////

void insert(float k){
   //  cout<<"stage 1"<<endl;
     stack s;
     s.top=-1;
     node *temp,*curr2,*newnd,*curr3;
      node *newhead;
      node *newtail;
     int toss,count;
     curr=head;
  //   cout<<"stage 2"<<endl;
     while(1){
              if(k>curr->next->x){curr=curr->next;}
              else if(k < curr->next->x && curr->down!=NULL){
                    
                   curr->gap++;
                 //  cout<<curr->gap<<endl;
                 //  print();
                 //  cout<<endl;
                   curr3=curr;
                   s.push(curr3);
                   curr=curr->down;
                   }
              else if( curr->next->x==k){ cout<<"Already Present"<<endl; return; }
              else { break; }
              }
  //   cout<<"stage 3"<<endl;
     temp= new node;
     temp->x=k;
     temp->prev=curr;
     temp->next=curr->next;
     curr->next=temp;
     temp->next->prev=temp;
     temp->gap=1;
     temp->up=NULL;
     temp->down=NULL;
     n++;
     toss=grand(0.5);
 //    cout<<"toss="<<toss<<endl;
  //   cout<<"stage 4"<<endl;
     while(toss==1){
                  //  cout<<"came here"<<endl;
                  //  cout<<"toss="<<toss<<endl;
                    newnd=new node;
                    newnd->x=k;
                    newnd->down=temp;
                    newnd->up=NULL;
                    temp->up=newnd;
                    curr=s.pop();
                    if(curr==NULL){
                                   newhead=new node;
                                   newtail=new node;
                                   newhead->x=ninf;
                                   newtail->x=pinf;
                                   newhead->gap=n+1;
                                //   cout<<"n "<<n<<" "<<newhead->x<<endl;
                                   newtail->gap=-1;
                                   newhead->down=head;
                                   newhead->next=tail;
                                   newtail->down=tail;
                                   newtail->prev=newhead;
                                   head->up=newhead;
                                   tail->up=newtail;
                                   head=head->up;
                                   head->up=NULL;
                                   curr=head;
                                   }
               //     cout<<curr->gap<<endl;
                    curr2=temp->prev;
                    count=curr2->gap;
                    while(curr2->up==NULL){
                                        //   cout<<"not"<<endl;
                                           curr2=curr2->prev;
                                           count=curr2->gap + count;
                                           }
              //      cout<<"count for" <<k<<"="<<count<<endl;
                    newnd->gap=curr->gap-count;               ///////////// dobts here
                    curr->gap=count;
                    newnd->prev=curr;
                    newnd->next=curr->next;
                    newnd->prev->next=newnd;
                    newnd->next->prev=newnd;
                    temp=temp->up;
                    toss=grand(0.5);
                    }
   //  cout<<"out"<<k<<endl;
}

////////////////////////////////////////////////////////////////////////////////

float select(int k){
      int count=0;
      curr=head;
      while(curr!=NULL){
                        if(count==k) { return curr->x; }
                        else if(count+curr->gap <=k){
                             count=count+ curr->gap;
                             curr=curr->next;
                             }
                        else {curr=curr->down; }
                        }
      cout<<"not found"<<endl;
      return 0;
      }

//////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////

void delte(float k){
     node *curr1,*curr2;
     stack s;
      curr=head;
     while(curr!=NULL){
                       if(k > curr->next->x){ curr=curr->next; }
                       else if(k< curr->next->x){
                             s.push(curr); 
                       curr=curr->down;
                       }
                       else {
                            curr=curr->next;
                            break; 
                            }
                            
                            }
   //  curr=search(k);
     while(curr->up!=NULL){
                           
                           curr=curr->up;
                           }
     curr1=s.pop();
     while(curr1!=NULL){
                    //    cout<<"here"<<endl;
                        curr1->gap--;
                        curr1=s.pop();
                        }
     
      while(curr!=NULL){
                        curr->prev->gap=curr->prev->gap +curr->gap-1;
                        curr->prev->next=curr->next;
                        curr->next->prev=curr->prev;
                        curr=curr->down;
                        }
      }
////////////////////////////////////////////////////////////////////////////////
};

int main(const int argc,const char *argv[]){
   //  srand((unsigned)time(NULL));
    skipl slist;
    string op;
       int no_of_inst, tree_no,i,j,no_of_op,l;
       ifstream f;
       f.open("in4",ios::in);
       f>>no_of_inst;
     //  cout<<no_of_inst<<endl;
       for(i=0;i<no_of_inst;i++)
       {
                                f>>op;
                          //      cout<<op<<endl;
                                if(op=="insert"){
                                                
                                                 f>>no_of_op;
                                           //      cout<<no_of_op<<endl;
                                                 for(j=0;j<no_of_op;j++){
                                                                       f>>l;
                                                                  //     cout<<l<<endl;
                                                                       slist.insert(l);
                                                                       }
                                                                       }
                                else if(op=="select"){
                                     f>>l;
                                   cout<<slist.select(l)<<endl;
                                     }
                                else if(op=="delete"){
                                                 f>>no_of_op;
                                           //      cout<<no_of_op<<endl;
                                                 for(j=0;j<no_of_op;j++){
                                                                       f>>l;
                                                                //       cout<<l<<endl;
                                                                       slist.delte(l);
                                                                       }
                                                                       }
                                                                       } 

 /*   slist.print();
    slist.insert(3);
    slist.print();
    cout<<endl;
    slist.insert(5);
    slist.print();
    cout<<endl;
    slist.insert(2);
    slist.print();
    cout<<endl;
    slist.insert(4);
  //  slist.insert(11);
  //  slist.insert(1); 
    slist.print();
    cout<<endl; 
    slist.delte(3);
    slist.print();
    cout<<endl;  */
    int k;
    cin>>k;
}                       
               
     
