#include <iostream>
#include <fstream>
#define max 100000
#define inf 100000
using namespace std;
class node{
      public:
      int index;
      int weight;
      node *next;
      };
////////////////////////////////////////////////////////////////////////////////      
class nodel{
      public:
      int vertex;
      int d;
      };
///////////////////////////////////////////////////////////////////////////////
class ind{
      public:
      bool b;
      bool found;
      bool visited;
      int parent;
      int nv;
      node *suc;
      };
      
ind *A;
int n,start,end;

////////////////////////////////////////////////////////////////////////////
void print(){
       int i;
       node *temp;
     
       for(i=0;i<n;i++){
                        
                temp=A[i].suc;
                //  cout<<"here"<<endl;
                while(temp!=NULL){
                                  cout<<"i"<<temp->index<<" w"<<temp->weight<<"    ";
                                  temp=temp->next;
                                  }
                                  cout<<endl;
                                  }
                }
/////////////////////////////////////////////////////////////////////////////
void deleteind( int a){
           int k;
           node *temp1,*temp2;
           for(k=0;k<n;k++){
                            temp1=A[k].suc;
                            temp2=A[k].suc;
                            while(temp2!=NULL){
                                               if(temp2->index==a){
                                                                   if(temp2==A[k].suc){
                                                                                       A[k].suc=temp2->next;
                                                                                       break;
                                                                                       }
                                                                   else{
                                                                        temp1->next=temp2->next;
                                                                        break;
                                                                        }
                                                                        
                                                                   }
                                                                   temp1=temp2;
                                                                   temp2=temp2->next;
                                                                   }
                                               }
                                               A[a].suc=NULL;
                            }
                                               
////////////////////////////////////////////////////////////////////////////
class heap{
      public:
             int top;
             nodel B[max];
             heap(){
                    top=0;
                    }
                    
void insert( int t, int q){
                  B[top].vertex=t;
                  B[top].d=q;
                  int i,m;
              m=top;
              i=(m-1)/2;
              if(m>0){
                      while(B[i].d >= B[m].d && i!=m) {
                                 swap(B[i].d,B[m].d);
                                 swap(B[i].vertex,B[m].vertex);
                                 m=i;
                                 i=m/2;
                                 }
                      }
              top++;
              }

void deltemin(){
      int i,m;
      B[0].d=B[top-1].d;
      B[0].vertex=B[top-1].vertex;
      i=0;
      if(B[2*i+1].d <B[2*i+2].d) m=2*i+1;
      else m=2*i+2;
      while(B[i].d > B[m].d && m<top) {
                                 swap(B[i].d,B[m].d);
                                 swap(B[i].vertex,B[m].vertex);
                                 i=m;
                                 if(B[2*i+1].d < B[2*i+2].d) m=2*i+1;
                                 else m=2*i+2;
                                 }
                                 top--;
      }
             
nodel min(){
     nodel mt;
     mt.d=B[0].d;
     mt.vertex=B[0].vertex;
     return mt;
     }

int search(int k){
      int p=0;
      while(p<top){
                   if(B[p].vertex==k){
                    return B[p].d;
                    }
                   else p++;
                   }
          cout<<"not found"<<endl;
          return 0;
          }

void decrease( int k, int s){
     int p=0,m,i;
      while(p<top){
                   if(B[p].vertex==k){
                                     break;
                    }
                   else p++;
                   }
      B[p].d=s;
       m=p;
              i=(m-1)/2;
              if(m>0){
                      while(B[i].d >= B[m].d && i!=m) {
                                 swap(B[i].d,B[m].d);
                                 swap(B[i].vertex,B[m].vertex);
                                 m=i;
                                 i=m/2;
                                 }
                      }
              }         
                   
};
////////////////////////////////////////////////////////////////////////////////
bool diks(int &l){
     heap h;
   //  cout<<start<<endl;
  //   cout<<end<<endl;
     nodel temp;
     node *temp2;
     int i,t,m,k;
    // print();
     for(i=0;i<n;i++){
                      if(A[i].found==0){
                                        
                                        A[i].visited=0;
                                        A[i].parent=-1;
                                        if(i==end)
                                         h.insert(i,0); 
                                        else h.insert(i,inf);
                                        }
                      }
                      l=0;
     while(h.top>=0){
                temp=h.min();
                h.deltemin();
                
                l=temp.d;
                t=temp.vertex;
                cout<<t<<" and "<<start<<endl;
                A[t].visited=1;
                if(t==start && l< 100000) return 1;
                //cout<<"here"<<endl;
                temp2=A[t].suc;
           //     if(temp2==NULL) return 0;
                while(temp2!=NULL){
                      m=temp2->index;
                      if(A[m].visited==0){
                                          k=h.search(m);
                                          if(k > l+ temp2->weight){
                                               A[m].parent=t;
                                               h.decrease(m,l+temp2->weight);
                                             //  cout<<h.B[0].vertex<<endl;
                                               }
                                               }
                      temp2=temp2->next;
                      }
                      }
                  //    cout<<"A[start].parent"<<A[start].parent<<endl;
                      if(A[start].parent==-1) return 0;
                      else return 1;
}
//////////////////////////////////////////////////////////////////////////////////                                                
                
                    
                                        
             
     
////////////////////////////////////////////////////////////////////////////////////
void stenz(){
     int a,k,l;
     l=0;
     bool z;
     while(1){
             z=diks(l);
             if(z==0){ cout<<"No path to goal exists"<<endl; return; }
              cout<<"Found new path from "<<start<<" of length "<<l<<endl;;
              a=start;
              while(a!=end){
                            cout<<a<<"  ";
                            a=A[a].parent;
                            }
              cout<<a<<endl;
              a=start;
              while(a!=end){
                            k=a;
                            a=A[a].parent;
                            if(A[a].b==1){ cout<<"Found blocked vertex at "<<a<<endl;
                            A[a].found=1;
                            break;
                                                                                }
                            }
              if(a==end){ cout<<"Reached goal"<<endl; return; }
              else{
                   deleteind(a);
                   start=k;
                   }
            }
}
                            
              



///////////////////////////////////////////////////////////////////////////////
int main(){
    
    int nb;
     node *nd,*temp;
     ifstream f;
     f.open("in3",ios::in);
     f>>n;
     f>>start;
     f>>end;
     
     
     A=new ind[n];
     
     int i,j;
     for(i=0;i<n;i++){
                   f>>A[i].nv;
                  A[i].b=0;
                  A[i].parent=1000;
                  A[i].found=0;
                   A[i].visited=0;
                   A[i].suc=NULL;
                   for(j=0;j<A[i].nv;j++){
                                     if(j==0){
                                          A[i].suc=new node;
                                          f>>A[i].suc->index;
                                          f>>A[i].suc->weight;
                                          A[i].suc->next=NULL;
                                           nd=A[i].suc;
                                             }
                                      else{
                                 nd->next=new node;
                                f>>nd->next->index;
                                f>>nd->next->weight;
                                 nd->next->next=NULL;
                                 nd=nd->next;
                                    }
                                 
                                 }
                   }
                   
     f>>nb;
     for(i=0;i<nb;i++){
                       f>>j;
                       A[j].b=1;
                       }
         stenz();              
     
   //  print();
   //  deleteind(3);
   //  cout<<endl;
   //  cout<<"after"<<endl;
     
    // print();
     int l;
     cin>>l;
     }
      
