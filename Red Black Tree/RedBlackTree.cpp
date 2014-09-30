#include <iostream>
#include <fstream>
#define high 3590
#include <stdio.h>
#include <cmath>
using namespace std;
class redblack;
class node{
      public:
      float x;
      bool c;
      int r;
      int lsize;
      node *left;
      node *right;
      node *parent;
      friend class redblack;
      };
int b;

///////////////////////////////////////////////////////////////////////////////////////////////////////


class redblack{


      public:
             node *curr;
             node *root;
             node *nil;
      redblack(){
              nil= new node;
                 nil->c=0;
                 nil->left=nil;
                 nil->right=nil;
                 nil->parent=nil;
              //   nil->x=20*high+10;
                 nil->lsize=1;
                 nil->r=-1;
                  root=nil;
                 curr=nil;

                 }

void ll(node *axis){

     node *curr1,*curr2;
 //    cout<<"inside ll"<<axis->x<<endl;
     curr1=axis->left;
     curr2=axis->parent->parent;
     axis->left=axis->parent;
     axis->left->right=curr1;

     if(curr1!=nil){
     curr1->parent=axis->parent;
     }
     axis->parent=axis->parent->parent;

     axis->left->parent=axis;
     if(curr2==nil || curr2==NULL){
                            root=axis;
                            axis->parent=nil;
                            }
     else{
          if(curr2->x > axis->x){
                      curr2->left=axis;
                      }
          else
          {
              curr2->right=axis;
              }
          }
     axis->lsize=axis->lsize + axis->left->lsize;
     }
void rr(node *axis){
   //  cout<<"inside rr"<<axis->x<<endl;
      node *curr1,*curr2;
     
    // cout<<axis->x<<endl;
  //  cout<< axis->parent->x<<endl;
   // if(axis->parent->parent!=NULL) cout<<axis->parent->parent->right->x<<endl;
     curr1=axis->right;
     curr2=axis->parent->parent;
     axis->right=axis->parent;
     axis->right->left=curr1;
       
     if(curr1!=nil){
     curr1->parent=axis->parent;
     }
     
     axis->parent=axis->parent->parent;

     axis->right->parent=axis;
     
     if(curr2==nil || curr2==NULL){
                            root=axis;
                            axis->parent=nil;
                            }
     else{
          
          if(curr2->x > axis->x){
                      
                      curr2->left=axis;
                      }
          else
          {
              
              curr2->right=axis;
              }
          }
          
          axis->right->lsize=(axis->right->lsize) - (axis->lsize);
          //if(axis->parent!=NULL)
        //  cout<<"dff"<<axis->parent->right->x<<endl;
     }
void lr(node *axis){
   //  cout<<"inside lr"<<axis->x<<endl;
     node *curr1,*curr2,*curr3;
     curr1=axis->right->left;
     curr2=axis->right->right;
     curr3=axis->parent->parent;
     axis->right->left=axis;
     axis->right->right=axis->parent;

     axis->parent=axis->right;
     axis->parent->right->parent=axis->parent;
     axis->right=curr1;

     if(curr1!=nil){ curr1->parent=axis;}
     axis->parent->right->left=curr2;
     if(curr2!=nil){curr2->parent=axis->parent->right;}
     axis->parent->parent=curr3;

     if(curr3==nil || curr3==NULL){

                     root=axis->parent;
                     axis->parent->parent=nil;
                     }
     else{
          if(curr3->x >axis->parent->x){
                      curr3->left=axis->parent;
                      }
          else{
               curr3->right=axis->parent;
               }
          }
axis->parent->lsize=axis->parent->lsize + axis->lsize;
axis->parent->right->lsize = axis->parent->right->lsize - axis->parent->lsize;
          }


void rl(node *axis){
  //   cout<<"inside rl"<<axis->x<<endl;
      node *curr1,*curr2,*curr3;
     curr1=axis->left->right;
     curr2=axis->left->left;
     curr3=axis->parent->parent;
     axis->left->right=axis;
     axis->left->left=axis->parent;

     axis->parent=axis->left;
     axis->parent->left->parent=axis->parent;
     axis->left=curr1;

     if(curr1!=nil){ curr1->parent=axis;}
     axis->parent->left->right=curr2;
     if(curr2!=nil){curr2->parent=axis->parent->left;}
     axis->parent->parent=curr3;

     if(curr3==nil || curr3==NULL){

                     root=axis->parent;
                     axis->parent->parent=nil;
                     }
     else{
          if(curr3->x >axis->parent->x){
                      curr3->left=axis->parent;
                      }
          else{
               curr3->right=axis->parent;
               }
          }
     axis->lsize=axis->lsize - axis->parent->lsize;
axis->parent->lsize=axis->parent->lsize + axis->parent->left->lsize;
     }
////////////////////////////////////////////

//node *search(float t);
////////////////////////////////////////////////////////////////////////////////
  void   insert(float t){
          if(search(t)!=NULL){
     return;
     }
        // cout<<"insertin "<< t<<endl;
                   if(root==nil){
                                 // cout<<"inside root=NULL"<<endl;
                                  root=new node;
                                  root->x=t;
                                  root->r=1;
                                 // cout<<root->x<<endl;
                                  root->c=0;
                                  root->lsize=1;
                                  root->left=nil;
                                  root->right=nil;
                                  root->parent=nil;
                                //   cout<<root->x<<endl;
                                  return;
                                  }

////////////////////////////////////////////////////////////////////////////////
else{
 //cout<<"inside root=NULL"<<endl;    
node *temp;
temp=new node;
temp->x=t;
temp->c=1;
temp->lsize=1;
temp->r=0;
temp->parent=nil;
temp->left=nil;
temp->right=nil;
curr=root;
while(1)
{
        
if(t<(curr->x) && curr->left!=nil) {
               (curr->lsize)++;
                curr=curr->left;}
else if(t>(curr->x) && curr->right!=nil) { curr=curr->right;}
else { break; }

}

if(t< curr->x && curr->left==nil){
(curr->lsize)++;
curr->left=temp;
temp->parent=curr;
}
else if(t > curr->x && curr->right==nil){
curr->right=temp;
temp->parent=curr;
}

 
////////////////////////////////////////////////////////////////////////////////two brackets pending
while(temp->parent!=nil && temp->parent->c==1){
                 
                      curr=temp->parent;

                      if(temp->x < temp->parent->x){

					          if(curr->x < curr->parent->x){
                                      if(curr->parent->right!=nil && curr->parent->right->c==1){
                                                             curr->c=0;
                                                             curr->parent->c=1;
                                                             curr->parent->right->c=0;
                                                             temp=curr->parent;
                                                             (curr->r)++;
                                                             curr->parent->right->r++;
                                                             }
                                                    else{
                                             //cout<<"yes"<<endl;
                                                 rr(curr);
                                                 
                                                 curr->c=0;
                                                 curr->right->c=1;
                                                 curr->r++;
                                                 curr->right->r--;

                                                   }
                                                 }
                                      else
                                      {
									  if(curr->parent->left!=nil && curr->parent->left->c==1){
									  curr->c=0;
									  curr->parent->c=1;
									  curr->parent->left->c=0;
									  temp=curr->parent;
									  (curr->r)++;
                                   curr->parent->left->r++;
									  }
									  else{
									  rl(curr);
									  
									  curr->parent->c=0;
									  curr->parent->left->c=1;
									  curr->parent->r++;
									  curr->parent->left->r--;
                                           }
                                           }
                                           }



                      else{
                          // cout<<curr->parent->left->x<<endl;

                          // else{


                                      if(curr->x < curr->parent->x){
                                                 if(curr->parent->right!=nil && curr->parent->right->c==1){
                                                                            //  cout<<"here "<<temp->x<<endl;
                                                        curr->c=0;
                                                        curr->parent->c=1;
                                                        curr->parent->right->c=0;
                                                        temp=curr->parent;
                                                        curr->r++;
                                                        curr->parent->right->r++;
                                                        }


                                                 else{
                                                 lr(curr);
                                                 
                                                 curr->parent->c=0;
                                                 curr->parent->right->c=1;
                                                 curr->parent->r++;
                                                 curr->parent->right->r--;
                                                 }
                                                 }
                                      else{
                                             if(curr->parent->left!=nil && curr->parent->left->c==1){
                                                        curr->c=0;
                                                        curr->parent->c=1;
                                                        curr->parent->left->c=0;
                                                        temp=curr->parent;
                                                        curr->r++;
                                                        curr->parent->left->r++;
                                                        }
                                           else{
                                          ll(curr);
                                          
                                          curr->c=0;
                                          curr->left->c=1;
                                          curr->r++;
                                          curr->left->r--;
                                          }
                                          }
                                   }   //write the four cases here
                               // }

            }

}
    root->c=0;


int p=1;
curr=root;
while(curr->left!=nil){
                        
                        curr=curr->left;
                        if(curr->c==0){ p++; }
                        }
                        root->r=p;
}

//////////////////////////////////////////////////////////////////////////

void foo(node *scr){
     if(scr->parent->x > scr->x){
     scr->parent->left=nil;
     }
     else{
          scr->parent->right=nil;
          }
          }
///////////////////////////////////////////////////////////////////////////////
void fix(node *curr){
     node *curr1=nil;
     while(curr!=root && curr->c==0){
                                    
                     if(curr==curr->parent->left){
                                                 curr1=curr->parent->right;
                                                 
                                                 if(curr1->c==1){
                                                                 curr1->c=0;
                                                                 curr->parent->c=1;
                                                                 ll(curr1);
                                                                 curr1=curr->parent->right;
                                                                
                                                                 }
                                                 if(curr1->left->c==0 && curr1->right->c==0){
                                                                      curr1->c=1;
                                                                      curr=curr->parent;
                                                                      
                                                                     
                                                                      }
                                                
                                                 else if(curr1->right->c==0){
                                                      curr1->left->c=0;
                                                      curr1->c=1;
                                                      rr(curr1->left);
                                                      curr1=curr->parent->right; }
                                                
                                                    
                                                        else{
                                                           curr1->c=curr->parent->c;
                                                           curr->parent->c=0;                   // doubts here
                                                           curr1->right->c=0;
                                                           ll(curr1);
                                                        
                                                           curr=root;
                                                           }
                                                    
                     }

                                       else{
                                                       curr1=curr->parent->left;
                                                 if(curr1->c==1){
                                                                 
                                                                 curr1->c=0;
                                                                 curr->parent->c=1;
                                                               //  cout<<curr1->left->x<<endl;
                                                               //  cout<<curr->parent->x<<endl;
                                                                 rr(curr1);
                                                               //  cout<<"here1"<<endl;
                                                                 curr1=curr->parent->left;
                                                                 }
                                                                 
                                                 if(curr1->left->c==0 && curr1->right->c==0){
                                                                   //   cout<<"here2"<<endl;
                                                                      curr1->c=1;
                                                                      
                                                                      curr=curr->parent;
                                                                           }
                                                                      
                                                             
                                                 else if(curr1->left->c==0){
                                                      curr1->right->c=0;
                                                      curr1->c=1;
                                                      ll(curr1->right);
                                                      curr1=curr->parent->left; }
                                                   
                                                        else{
                                                           curr1->c=curr->parent->c;
                                                           curr->parent->c=0;                   // doubts here
                                                           curr1->left->c=0;
                                                          rr(curr1);
                                                          curr=root;
                                                          }
                                                          }
                                                          
                     }
                     curr->c=0;
                     }











///////////////////////////////////////////////////////////////////////////////
void delte( float t){
int tag=0;
node *del,*curr2,*scr,*curr4;
del=root;
while(del->x!=t && del!=nil){
if(t<del->x) {(del->lsize)--; del=del->left; }
else if(t>del->x) { del=del->right; }
}

if(del->left==nil || del->right==nil){
                     scr=del;
                     
                     }
else{
                     if(del->right!=nil){
                     scr=del->right;
                     while(scr->left!=nil){(scr->lsize)--; scr=scr->left;}   
                     }
                     else{
                          curr4=del;
                          scr=curr4->parent;
                          while(scr != nil && curr4 == scr->right)
                                                                  {
                                                          curr4 = scr;
                                                         scr = scr->parent;
                                                                      } 
                                                                      }            
     }
    //  cout<<"here"<<endl;
     
     if(scr->left!=nil){
                        
                         curr=scr->left;
                         }
                         
     else {
          curr=scr->right;
          }
          curr->parent=scr->parent;                 /// what if curr==nil;
          if(scr->parent==nil){
                               root=curr;
                               
                               }
          else if( scr->parent->x > scr->x ){
               scr->parent->left=curr;
               }
          else{
               scr->parent->right=curr;
               }
               if(scr!=del){
                            del->x=scr->x;
                            }
               if(scr->c==0){
                             fix(curr);
                             }
          
     
}


float select(node *curr1 , int k){
   //   nil->right=nil;
   //   nil->left=nil;
     
     // cout<<k<<" "<<nil->lsize" ";
    //  cout<<"here "<<k<<endl;
      if( curr1->lsize==k){
       //   cout<<"found"<<endl;
          return curr1->x;
          
          }
      else if( curr1->lsize > k){
           return select(curr1->left, k);
           }
      else{
           return select(curr1->right,k - curr1->lsize);
           }
           
           }






void fixnil( node *curr1){
   //  cout<<"inside fixnil"<<endl;
     if( curr1->left->r!=-1){
                           fixnil(curr1->left);
                           }
     else{ curr1->left=nil;}
     if( curr1->right->r!=-1){
                            fixnil(curr1->right);
                            }
     else { curr1->right=nil;
        return;}
     }
     
     
void fixnil2 (node *curr1,int o);
     
          



void calsize( node *curr1, int &i){
     if(curr1!= nil){
                    calsize(curr1->left,i);
                  //  cout<<i<<curr->x<<endl;
                    i++;
                    calsize(curr1->right,i);
     }
     else{//cout<<i<<endl;
      return;}
     }






/*void level(node *curr1)
{
  node *queue[100000] = {(node *)0}; // Important to initialize!
  int size = 0;
  int queue_pointer = 0;
   // queue[size++] = nil;
  while( curr1!=nil && curr1!=NULL )
  {
      cout<<curr1->x<<" c"<<curr1->c<<" ls"<<curr1->lsize<<" r"<<curr1->r<<"    ";

      if(curr1->left!=nil)
      {
        queue[size++] = curr1->left;
      }

      if(curr1->right!=nil)
      {
        queue[size++] = curr1->right;
      }

      curr1 = queue[queue_pointer++];
  }
}
*/

///////////////////////////////////////////////////////////////////////////////////////////////
node *search(float t){
      
curr=root;
while(curr!=nil){
                // cout<<"k"<<root->x<<endl;
if(t<curr->x) {curr=curr->left;}
else if(t>curr->x) {curr=curr->right;}
else { return curr; }
}
if(curr==nil){
return NULL;
}
}
//////////////////////////////////////////////////////////////////////////////////////////////







void fixred(node *temp){
     int p=1;
     while(temp->parent!=nil && temp->parent->c==1){
                 
                      curr=temp->parent;

                      if(temp->x < temp->parent->x){

					          if(curr->x < curr->parent->x){
                                      if(curr->parent->right!=nil && curr->parent->right->c==1){
                                                             curr->c=0;
                                                             curr->parent->c=1;
                                                             curr->parent->right->c=0;
                                                             temp=curr->parent;
                                                             (curr->r)++;
                                                             curr->parent->right->r++;
                                                             }
                                                    else{
                                             //cout<<"yes"<<endl;
                                                 rr(curr);
                                                 
                                                 curr->c=0;
                                                 curr->right->c=1;
                                                 curr->r++;
                                                 curr->right->r--;

                                                   }
                                                 }
                                      else
                                      {
									  if(curr->parent->left!=nil && curr->parent->left->c==1){
									  curr->c=0;
									  curr->parent->c=1;
									  curr->parent->left->c=0;
									  temp=curr->parent;
									  (curr->r)++;
                                   curr->parent->left->r++;
									  }
									  else{
									  rl(curr);
									  
									  curr->parent->c=0;
									  curr->parent->left->c=1;
									  curr->parent->r++;
									  curr->parent->left->r--;
                                           }
                                           }
                                           }



                      else{
                          // cout<<curr->parent->left->x<<endl;

                          // else{


                                      if(curr->x < curr->parent->x){
                                                 if(curr->parent->right!=nil && curr->parent->right->c==1){
                                                                            //  cout<<"here "<<temp->x<<endl;
                                                        curr->c=0;
                                                        curr->parent->c=1;
                                                        curr->parent->right->c=0;
                                                        temp=curr->parent;
                                                        curr->r++;
                                                        curr->parent->right->r++;
                                                        }


                                                 else{
                                                 lr(curr);
                                                 
                                                 curr->parent->c=0;
                                                 curr->parent->right->c=1;
                                                 curr->parent->r++;
                                                 curr->parent->right->r--;
                                                 }
                                                 }
                                      else{
                                             if(curr->parent->left!=nil && curr->parent->left->c==1){
                                                        curr->c=0;
                                                        curr->parent->c=1;
                                                        curr->parent->left->c=0;
                                                        temp=curr->parent;
                                                        curr->r++;
                                                        curr->parent->left->r++;
                                                        }
                                           else{
                                          ll(curr);
                                          
                                          curr->c=0;
                                          curr->left->c=1;
                                          curr->r++;
                                          curr->left->r--;
                                          }
                                          }
                                   }   //write the four cases here
                               // }
                               
                               
                              if( root->c==1){
                                  root->c=0;
                                  root->r++;
}

p=1;
curr=root;
while( curr->left!=nil){
                        
                        curr=curr->left;
                        if(curr->c==0){ p++; }
                        }
                        root->r=p;

            }

}

/////////////////////////////////////////////////////////////////////////////////////

     


/////////////////////////////////////////////////////////////////////////////////////////////
void join(float key,node *t1 ,node *t2){

     node *nd, *newnd;
     int i=0;
     if(t1->c==1){
                  t1->c=0;
                  t1->r++;
                  }
     if(t2->c==1){
                  t2->c=0;
                  t2->r++;
                  }
     if(t1->r==-1){
                 //  cout<<"yes1"<<endl;
                   root=t2;
                   root->parent=nil;
                   fixnil(root);
                   insert(key);
                   return;
                   }
     else if(t2->r==-1){
      //     cout<<"yes2"<<endl;
          root=t1;
        //  root->c=0;
          root->parent=nil;
          fixnil(root);
          insert(key);
          return;
          }
         if(t1->r == t2->r){
                        
                       root=new node;
                       root->x=key;
                       root->left=t1;
                       root->parent=nil;
                       root->c=0;
                       t1->parent=root;
                       root->right=t2;
                       t2->parent=root;
                       
                    //   root->lsize=rb[m].root->lsize+1;
                       root->r=t1->r +1;
                       fixnil(root);
                       calsize(root->left,i);
                       root->lsize=i+1;
                       return;
                      // cout<<root->right->x<<endl;
                       }
         else if(t1->r > t2->r){
              
              
              root=t1;
              root->parent=nil;
              curr=t1->right;
              
              while(curr->r>t2->r){
                                 //   cout<<"returned "<<curr->r<<endl;
                                            curr=curr->right;
                                            }
              
              nd=curr;
              curr=curr->parent;
              newnd= new node;
              newnd->x=key;
              newnd->c=1;
              newnd->left=nd;
              nd->parent=newnd;
              newnd->right=t2;
              t2->parent=newnd;
              newnd->parent=curr;
              if(newnd->left->r>-1){
              newnd->r=newnd->left->r;
              }
              else{
                 newnd->r=newnd->left->r+1;
                 }  
              curr->right=newnd;
              fixnil(root);
              calsize(newnd->left,i);
              newnd->lsize=i+1;
              if(nd->c==1){
                                fixred(nd);
                               }
              
              //   cout<<newnd->lsize<<endl;  
              }
         else{
              
              
              root=t2;
              root->parent=nil;
              curr=root->left;
              while(curr->r>t1->r){
                                //    cout<<"returned "<<curr->r<<endl;
                                            curr=curr->left;
                                            }
              nd=curr;
              curr=curr->parent;
              newnd=new node;
              newnd->x=key;
              newnd->c=1;
              newnd->right=nd;
              nd->parent=newnd;
              newnd->left=t1;
              t1->parent=newnd;
              newnd->parent=curr;
              if(newnd->right->r>-1){
              newnd->r=newnd->right->r;
              }
              else{
                 newnd->r=newnd->right->r+1;
                 } 
            //  newnd->r=newnd->right->r;
              curr->left=newnd;
              fixnil(root);
              
              calsize(newnd->left,i);
              newnd->lsize=i+1;
           
              newnd=newnd->parent;
              root->parent=nil;
              while( newnd!=nil){
                     i=1;
                     calsize(newnd->left,i);
                              newnd->lsize=i;
                              newnd=newnd->parent;
                           //   cout<<"came here"<<endl;
                              }
             if(nd->c==1){
                               fixred(nd);
                               }
                                                   
              
              
              }
             int p=1;
curr=root;
while(curr->left!=nil){
                        
                        curr=curr->left;
                        if(curr->c==0){ p++; }
                        }
                        root->r=p;
           //   cout<<"join completed"<<endl;
}

void  split(int key, int m, int n,int trno);

};



redblack rb[10001];


void redblack :: fixnil2 (node *curr1,int o){
  //   cout<<"inside fixnil2"<<endl;
     if( curr1->left!=rb[o].nil){
                           fixnil2(curr1->left,o);
                           }
     else{ curr1->left=nil;}
     if( curr1->right!=rb[o].nil){
                            fixnil2(curr1->right,o);
                            }
     else { curr1->right=nil;
        return;}
     }




 
void redblack :: split(int key, int m, int n, int trno){
     
     int tag1=0,tag2=0;
     if(search(key)==NULL){
     insert(key);
     }
 //  level(root);
     curr=root;
     while(curr->x!=key){
                       //  cout<<"inside 1"<<endl;
                         if(key < curr->x){ curr=curr->left; }
                         else { curr=curr->right; }
                         }
                     //    cout<<"curr "<<curr->x<<endl;
     if(curr->left!=nil){
     rb[m].root=curr->left;
     rb[m].root->parent=rb[m].nil;
     if(rb[m].root->c==1){
                          rb[m].root->c=0;
                          rb[m].root->r++;
                          }
     fixnil2(rb[m].root,trno);
     }
     else{
          rb[m].root=rb[m].nil;
          rb[m].nil->r=-1;
          tag1=0; 
        //  rb[m].insert(key);
        //   rb[m].root->lsize=0;
        //  rb[m].root->r=0;
          }
     if(curr->right!=nil){
     rb[n].root=curr->right;
     if(rb[n].root->c==1){
                          rb[n].root->c=0;
                          rb[n].root->r++;
                          }
     fixnil2(rb[n].root,trno);
     }
     else{
         rb[n].root=rb[n].nil;
          rb[m].nil->r=-1;
          tag2=0; 
       //   rb[n].insert(key);
        //  rb[n].root->lsize=0;
        //  rb[n].root->r=0;
          }
     while(curr!=root){
                     // cout<<"m ";
                      // rb[m].level(rb[m].root);
                      // cout<<endl;
                     //  cout<<" n";
                     //  rb[n].level(rb[n].root);
                     //  cout<<endl;
                            //   cout<<"inside 2"<<curr->x<<endl;
                               if(curr==curr->parent->left){
                                                            
                                                            if(curr->parent->right!=nil && curr->parent->right!=NULL){
                                                     //       cout<<"inside 3"<<endl;
                                                            rb[10000].join(curr->parent->x,rb[n].root,curr->parent->right);
                                                            if(rb[10000].root->c==1){
                                                            rb[10000].root->c=0;
                                                            rb[10000].root->r++;
                                                            }
                                                            rb[n].root=rb[10000].root;
                                                            rb[n].root->parent=rb[n].nil;
                                                       //     rb[10000].level(rb[10000].root);
                                                        //    cout<<"before fixnil"<<endl;
                                                            rb[n].fixnil2(rb[n].root,10000);
                                                       //     cout<<"after fixnil"<<endl;
                                                            rb[10000].root=rb[10000].nil;
                                                            
                                                            }
                                                          else{ 
                                                             //     cout<<"inside 4"<<endl;
                                                                        rb[n].insert(curr->parent->x); 
                                                                        }
                                                                        
                                                            }
                               else{
                                    
                                    if(curr->parent->left!=nil && curr->parent->left!=NULL){
                                              //  cout<<"inside 5"<<endl;                                
                                    rb[10000].join(curr->parent->x,curr->parent->left,rb[m].root);
                                 //    cout<<"inside 5"<<endl;
                                    if(rb[10000].root->c==1){
                                                            rb[10000].root->c=0;
                                                            rb[10000].root->r++;
                                                            }
                                    rb[m].root=rb[10000].root;
                                    rb[m].root->parent=rb[m].nil;
                                    rb[m].fixnil2(rb[m].root,10000);
                                     rb[10000].root=rb[10000].nil;
                                  //  rb[m].level(rb[m].root);
                                    
                                    }
                                   else{ 
                                          rb[m].insert(curr->parent->x); 
                                       //   cout<<"inside 6"<<endl;
                                          }
                     

                                    }
                                  
                                                                        curr=curr->parent;
                               }
                               root=nil;
                               root->parent=nil;
                               }



main(const int argc,const char *argv[]){
   //   redblack rb[10000];
       string op;
       int count=0;
       int no_of_inst, tree_no,i,j,no_of_op,l, tr1,tr2,key;
       ifstream f;
       f.open("in5",ios::in);
       f>>no_of_inst;
     //  cout<<no_of_inst<<endl;
      
       for(i=0;i<no_of_inst;i++)
       {
                                f>>op;
                            //    cout<<op<<endl;
                                if(op=="insert"){
                                                 f>>tree_no;
                                                // cout<<tree_no<<endl;
                                                 f>>no_of_op;
                                                // cout<<no_of_op<<endl;
                                                 for(j=0;j<no_of_op;j++){
                                                                       f>>l;
                                                                     //  cout<<l<<endl;
                                                                       rb[tree_no].insert(l);
                                                                       }
                                                                       }
                               // rb[tree_no].level(rb[tree_no].root);
                          else   if(op=="select"){
                                     f>>tree_no;
                                     f>>l;
                                   cout<<rb[tree_no].select(rb[tree_no].root,l)<<endl;
                                     } 
                           else      if(op=="delete"){
                                     f>>tree_no;
                                  //   cout<<tree_no<<endl;
                                                 f>>no_of_op;
                                              //   cout<<no_of_op<<endl;
                                                 for(j=0;j<no_of_op;j++){
                                                                  //       cout<<count<<endl;
                                                                         count++;
                                                                       f>>l;
                                                                  //     cout<<l<<endl;
                                                                       rb[tree_no].delte(l);
                                                                       }
                                                 }
                                else if(op=="join"){
                                     f>>tr1;
                                     f>>key;
                                     f>> tr2;
                                     f>>tree_no;
                                     rb[tree_no].join(key,rb[tr1].root,rb[tr2].root);
                                     }
                                else if(op=="split"){
                                     f>>tree_no;
                                     f>>key;
                                     f>>tr1;
                                     f>>tr2;
                                     rb[tree_no].split(key, tr1,tr2,tree_no);
                                     } 
       } 
                        
      }


