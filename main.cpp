#include <bits/stdc++.h>
#include "graph.hpp"

using namespace std; 

list <string> splitString(string s, string del) { 
    list <string> res;
    int pos = 0; 
    string token; 
    while ((pos = s.find(del)) != string::npos) { 
        token = s.substr(0,pos); 
        res.push_back(token); 
        s.erase(0, pos + del.length()); 
    }
    res.push_back(s); 
    return res; 
}

void read_file(Graph& g, map<string,int>& rankAdj) { 
    fstream fi("tiepXucGan.txt", ios::in); 
    if (fi.fail()) { 
        cout<<"Khong mo dc file !!!"<<endl; 
        return; 
    }
    int n; 
    fi>>n; 
    for(int i=0; i<=n; i++) { 
        string line; 
        getline(fi,line); 
        if (line != "") { 
            list <string> splittedName; 
            splittedName = splitString(line," "); 
            string u = splittedName.front(); 
            insert_vertex(g,u); 
            rankAdj[u] = 0; 
            for(auto x:splittedName) { 
                if(x != u) { 
                    insert_edge(g,u,x,1);  
                    rankAdj[u]++; 
                }
            }
        }
    }
    fi.close(); 
    return; 
}

void print_data(Graph g) { 
    for(auto x:g) { 
        for(auto y:g[x.first]) { 
            cout<<x.first<<"--"<<y.first<<endl; 
        }
    }
    return; 
}

void check_adjective (Graph g) { 
    string u,v; 
    cout<<"Nhap ten 2 nguoi can kiem tra tiep xuc gan : "; 
    cin>>u>>v; 
    if(g[u].find(v) != g[u].end()) { 
        cout<<"2 nguoi CO tiep xuc gan"<<endl; 
    } else {
        cout<<"2 nguoi KHONG tiep xuc gan"<<endl;
    }
    return; 
}

void print_adjacent(Graph g) { 
    string inputName;
    cout<<"Nhap ten mot nguoi de in ra danh sach tiep xuc gan : "; 
    cin>>inputName; 
    for(auto x:g[inputName]) { 
        cout<<x.first<<" "; 
    }
    cout<<endl; 
    return; 
}

void find_best_rank(map<string,int> rankAdj) { 
    int maxRank = 0; 
    for(auto x:rankAdj) { 
        maxRank = max(maxRank, x.second); 
    }
    cout<<"Nhung nguoi tiep xuc gan voi nhieu nguoi nhat la : "<<maxRank<<endl; 
    for(auto x:rankAdj) { 
        if (x.second == maxRank) cout<<x.first<<" "; 
    }
    cout<<endl; 
    return;
}

void add_vertex(Graph& g, map<string,int>& rankAdj) { 
    string line; 
    cout<<"Nhap data : "; 
    fflush(stdin); 
    getline(std::cin, line);
    cout<<line<<endl; 
    return;  
}

int main() {
    Graph g; 
    map <string,int> rankAdj; 
    int func; 
    do { 
        cout<<"\tMENU"<<endl; 
        cout<<"1. Doc file"<<endl; 
        cout<<"2. In data tu file"<<endl; 
        cout<<"3. Kiem tra 2 nguoi co tiep xuc gan hay khong"<<endl; 
        cout<<"4. In ra danh sach tiep xuc gan cua 1 nguoi"<<endl; 
        cout<<"5. In ra nguoi tiep xuc gan voi nhieu nguoi nhat"<<endl; 
        cout<<"6. In F1, F2 cua 1 nguoi"<<endl; 
        cout<<"7. Bo sung danh sach"<<endl; 
        cout<<"8. Bo sung thong tin tiep xuc gan"<<endl; 
        cout<<"9. Ghi ra file text danh sach tiep xuc gan"<<endl; 
        cout<<"10. Thoat chuong trinh"<<endl; 
        cout<<"Ban chon : "; cin>>func;
        switch (func)
        {
        case 1:
            read_file(g,rankAdj); 
            break;
        case 2: 
            print_data(g); 
            break;        
        case 3: 
            check_adjective(g); 
            break; 
        case 4: 
            print_adjacent(g); 
            break; 
        case 5: 
            find_best_rank(rankAdj);
            break;  
        case 7: 
            add_vertex(g, rankAdj);
            break;  
        default:
            break;
        } 
    } while (func!=10); 
    return 0; 
}