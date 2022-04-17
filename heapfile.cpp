#include<bits/stdc++.h>

using namespace std;



class Page{
    public:

    int pagesize;
    int space_left;
    int *keys;
    int count;
    int* positions;

    Page(int size){
        count=0;
        pagesize=size;
        space_left=pagesize;
        keys=new int[pagesize];
        positions=new int[pagesize];
    }

    bool insert(int key, int size){
        if(space_left>=(size+4))
        {
            positions[count+1]=positions[count]+size;
            keys[count]=key;
            count++;
            space_left-=(size+4);
            return true;
        }
        else{return false;}

    }

    int search(int key){
        
        for (int i = 0; i < count; i++)
        {
            if(keys[i]==key){
                return i;
            }
        }

        return -1;  
    }

};


class File{
    public:
    int pagesize;

    list<Page> l;

    File(int p){
        pagesize=p;
    }

    void insert(int key, int size){
        for(auto it=l.begin();it!=l.end();it++){
            if((*it).insert(key,size)) return;
        }
        Page p(pagesize);
        p.insert(key,size);
        l.insert(l.end(),p);
        //insert(key,size);
    }

    pair<int,int> search(int key){
        auto it=l.begin();
        int page=0;
        while(it!=l.end()){
            if((*it).search(key)!=-1)
            return make_pair(page, (*it).search(key));
            it++;
            page++;

        }
        
        return make_pair(-1,-1);
    }

    void status(){
        cout<<l.size();

        for(auto x: l){
            cout<<" "<<x.count;
        }
        cout<<endl;
    }

};

int main(int argc, char const *argv[])
{
    int a,b;
    cin>>a;
    File f(a);
    
    while(cin){
        cin>>a;
        pair<int,int> x;
        switch (a)
        {
        case 1:
            cin>>a>>b;
            f.insert(b,a);
            break;
        case 2:
            f.status();
            break;
        case 3:
            cin>>a;
            x=f.search(a);
            cout<<x.first<<" "<<x.second<<endl;
            break;
        default:
            break;
        }
    }
    return 0;
}
