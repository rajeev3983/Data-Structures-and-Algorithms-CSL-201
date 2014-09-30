//         Submitted by:-
//                        Rajeev Kumar ( 2011CS1031 )


#include <iostream>
#include <string>
#include <cctype>
using namespace std;
class genlistnode{
      public:
             int flag;
             string S;
             genlistnode *next;
             genlistnode *down;
             };
string getword(string A, int &i){
       int k=1;
       int m=0;
       int n=0;
       char D[100];
       int state=1;
       while(k<i){

                    if(A[m]!=' ' && state==0){
                               state=1;
                               k++;
                               }
                    else if(A[m]==' ' && state==1){
                         state=0;
                         }
                         m++;

                  }
                  if(k>1){
                          m--;
                          }
                  while(A[m]!=' ' && A[m]!='\0'){

                                D[n]=A[m];
                                n++;
                                m++;

                                }
D[n]='\0';
                  if(n<3){
                          D[n]='\0';
                          }
                  return D;
}
genlistnode *makenode(string a, int &i){
            string s;
            genlistnode *temp;
            temp= new genlistnode;
            s=getword(a, i);
            i++;
            temp->flag=0;
            temp->S=s;
            temp->next=NULL;
            temp->down=NULL;
            return temp;
            }

genlistnode *makelist(string a, int &i){
            string s;
            genlistnode *head;
            genlistnode *curr;
            head=new genlistnode;
            head->flag=1;
            head->next=NULL;
            head->down=NULL;
            s=getword(a,i);
            head->S=s;
            curr=head;
            i++;
            int p;
            p=0;
            for(;;){
                    s=getword(a,i);
            if(s=="("){
                       if(p==0){
                                curr->down=makelist( a,i);
                                curr=curr->down;
                              
                                }
                     else{
                       curr->next=makelist(a,i);
                       curr=curr->next;
                       }
                       }
            else if(s==")"){
                 i++;
                 return head;

                 }
            else{
                if(p==0){
                         curr->down=makenode(a,i);
                 curr=curr->down;
                 }
                 else{
                 curr->next=makenode(a,i);
                 curr=curr->next;
                 }
                 }
                 p++;
                 }
}


class value {
public:
int tag;
float val;
genlistnode* link;
};

class Env {
public:
value* table[26];
Env* parent;
Env() {
for(int i=0; i<26; i++)
{
table[i]=NULL;
}
parent=NULL;
}
};

void add(char x, value val_new, Env &e) {
  
value *p = new value;
p->tag=val_new.tag;
p->link=val_new.link;
p->val=val_new.val;
e.table[x- 'a']=p;
}



value find(char x, Env& e) {
if (e.table[x- 'a'] != NULL) {
return *(e.table[x- 'a']);
}
else {
if (e.parent == NULL) {
}
else {
return find(x, *(e.parent));
}
}
}

float getnumber(string A){
      float g=0;
      int i=0;
     while(isdigit(A[i]))
     {
                        g=g*10+(A[i]-'0');
                        i++;
                        }

                        if(A[i]=='.'){
                                     i++;
                                     int k=1;
                                     while(isdigit(A[i])){
                                                      g=g*10+(A[i]-'0');
                                                      k=10*k;
                                                      i++;
                                                      }

                                                      g=g/k;
                                     }
                        return g;
                        }

value evalist( genlistnode *p , Env& e);

value evalnode( genlistnode *p , Env& e){

      if( p->flag==1)
      {
          return evalist(p->down, e);
          }
      else {
           if(isdigit(p->S[0])){
                                value v;
                                v.tag=0;
                                v.val=getnumber(p->S);
                                v.link=NULL;
                                return v;
                                }
           else{
                return find(p->S[0],e);
                }
           }
}


value evalist( genlistnode *p , Env& e){
            
      if(p->S=="+"){
            value v1;
           v1= evalnode(p->next,e);
           value v2= evalnode (p->next->next, e);
           value v;
           v.tag=0;
           v.val=v1.val + v2.val;
           v.link=NULL;
           return v;
           }

      else if(p->S=="-"){
            value v1= evalnode(p->next,e);
           value v2= evalnode (p->next->next, e);
           value v;
           v.tag=0;
           v.val=v1.val - v2.val;
           v.link=NULL;
           return v;
           }

      else if(p->S=="*"){
            value v1= evalnode(p->next,e);
           value v2= evalnode (p->next->next, e);
           value v;
           v.tag=0;
           v.val=(v1.val)*(v2.val);
           v.link=NULL;
           return v;
           }

      else if(p->S=="/"){
            value v1= evalnode(p->next,e);
           value v2= evalnode (p->next->next, e);
           value v;
           v.tag=0;
           v.val=(v1.val)/(v2.val);
           v.link=NULL;
           return v;
           }
      else if(p->S=="%"){
            value v1= evalnode(p->next,e);
           value v2= evalnode (p->next->next, e);
           value v;
           v.tag=0;
           int b=v1.val;
           int c=v2.val;
           v.val=(b)%(c);
           v.link=NULL;
           return v;
           }

      else if(p->S=="=="){
            value v1= evalnode(p->next,e);
           value v2= evalnode (p->next->next, e);
           value v;
           v.tag=0;
           if((v1.val)==(v2.val)){
                                  v.val=1;
                                  }
           else v.val=0;
           v.link=NULL;
           return v;
           }

            else if(p->S=="<="){
            value v1= evalnode(p->next,e);
           value v2= evalnode (p->next->next, e);
           value v;
           v.tag=0;
           if((v1.val)<=(v2.val)){
                                  v.val=1;
                                  }
           else v.val=0;
           v.link=NULL;
           return v;
           }
           else if(p->S=="<"){
            value v1= evalnode(p->next,e);
           value v2= evalnode (p->next->next, e);
           value v;
           v.tag=0;
           if((v1.val)<(v2.val)){
                                  v.val=1;
                                  }
           else v.val=0;
           v.link=NULL;
           return v;
           }

      else if(p->S==">="){
            value v1= evalnode(p->next,e);
           value v2= evalnode (p->next->next, e);
           value v;
           v.tag=0;
           if((v1.val)>=(v2.val)){
                                  v.val=1;
                                  }
           else v.val=0;
           v.link=NULL;
           return v;
           }
           else if(p->S==">"){
            value v1= evalnode(p->next,e);
           value v2= evalnode (p->next->next, e);
           value v;
           v.tag=0;
           if((v1.val)>(v2.val)){
                                  v.val=1;
                                  }
           else v.val=0;
           v.link=NULL;
           return v;
           }

      else if(p->S=="begin"){
           p=p->next;
           while(p->next!= NULL){
                           evalnode(p,e);
                           p=p->next;
                           }
           return evalnode(p,e);
           }

      else if(p->S=="if"){
           value v=evalnode(p->next,e);
           if(v.val==1){
                        return evalnode(p->next->next,e);
                        }
           else
           return evalnode(p->next->next->next,e);
           }
      else if(p->S=="while"){
           value v1=evalnode(p->next, e);
           value v2;
           while(v1.val==1){
                           v2=evalnode(p->next->next, e);
                           v1=evalnode(p->next, e);
                           }
           return v2;
           }
      else if(p->S=="define"){
           value v1=evalnode(p->next->next,e);
           
           add(p->next->S[0],v1,e);
           return v1;                                                  
           }


      else if(p->S=="lambda"){
           
        value new_val;
         new_val.tag=1;
         new_val.link=p;
         return new_val;
        
                       } 
           else if (p->S=="set"){
                value v;
                v=evalnode(p->next->next, e);
                add(p->next->S[0],v,e);
                return v;
                }
                        else if ((p->S[0]>96)&&(p->S[0]<123)&&(p->S[1]=='\0')){ 
            value v;
            v=find(p->S[0],e);
            Env e1;
           e1.parent= &e;
            genlistnode *h,*k;
            k=(v.link)->next->next;
            if(v.tag==1){
                h= (v.link)->next->down;
                add(h->S[0],evalnode(p->next,e),e1);
                h=h->next;
                p=p->next;
                while(h!=NULL){
                add(h->S[0],evalnode(p->next,e),e1);
                h=h->next;
                p=p->next;
                }
                return evalnode(k,e1);
                }
                            }
           else  if(p->flag==1){
                     
                      genlistnode *list,*body,*y;
                              Env e1;
                              e1.parent=&e;
                              list=p->down->next->down;
                              body=p->down->next->next->down;
                              y=p;


                             while(list!=NULL){
                                char r;
                                r=list->S[0];
                                add(r,evalnode(y->next,e),e1);
                                y=y->next;
                                list=list->next;
                              }
                              return evalist(body,e1);
                           
                     }

                
                            
                            
          
                  
}


int main(){
    string a;
    cout<< "Enter the string"<<endl;
    getline(cin,a);
 // a="( begin ( define i 1 ) ( define n 10 ) ( define a 0 ) ( define b 1 ) ( while ( <= i n ) ( begin ( define t ( + a b ) ) ( set a b ) ( set b t ) ( set i ( + i 1 ) ) ) ) a )";
    int i;
    i=1;
    genlistnode *head;
    head=makelist(a,i);
    Env e;
    value v;
    v=evalnode(head, e);
    cout<<v.val<<endl;
}
