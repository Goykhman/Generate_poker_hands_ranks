#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <fstream>

using namespace std;

class GenerateRankings{
public:
    GenerateRankings(){
        ranks={"A","K","Q","J","T","9","8","7","6","5","4","3","2"};
        // encode and decode are use for sorting of each 5-card hand
        encode={{'A',0},{'K',1},{'Q',2},{'J',3},{'T',4},
            {'9',5},{'8',6},{'7',7},{'6',8},{'5',9},
            {'4',10},{'3',11},{'2',12}};
        decode={{0,'A'},{1,'K'},{2,'Q'},{3,'J'},{4,'T'},
            {5,'9'},{6,'8'},{7,'7'},{8,'6'},{9,'5'},
            {10,'4'},{11,'3'},{12,'2'}};
    }
    void generateStraightFlush(){
        cout << "Straight Flush starts at rank=" << all_ranks.size();
        for(int i=0;i<9;++i){
            string ranks_string;
            for(int j=i;j<i+5;++j){
                ranks_string+=ranks[j];
            }
            sort_wrapper(ranks_string);
            all_ranks.push_back(ranks_string);
        }
        string ranks_string="A5432";
        all_ranks.push_back(ranks_string);
        cout << " and ends at " << all_ranks.size() << endl;
    }
    void generateFourOfAKind(){
        cout << "Four of a Kind starts at rank=" << all_ranks.size();
        for(int i=0;i<13;++i){
            string pre_string;
            for(int j=0;j<4;++j)
                pre_string+=ranks[i];
            for(int j=0;j<13;++j){
                if(j==i)
                    continue;
                else{
                    string ranks_string=pre_string;
                    ranks_string+=ranks[j];
                    sort_wrapper(ranks_string);
                    all_ranks.push_back(ranks_string);
                }
            }
        }
        cout << " and ends at " << all_ranks.size() << endl;
    }
    void generateFullHouse(){
    cout << "Full House starts at rank=" << all_ranks.size();
        for(int i=0;i<13;++i){
            string pre_string;
            for(int j=0;j<3;++j)
                pre_string+=ranks[i];
            for(int j=0;j<13;++j){
                if(j==i)
                    continue;
                else{
                    string ranks_string=pre_string;
                    for(int k=0;k<2;++k){
                        ranks_string+=ranks[j];
                    }
                    sort_wrapper(ranks_string);
                    all_ranks.push_back(ranks_string);
                }
            }
        }
        cout << " and ends at " << all_ranks.size() << endl;
    }
    void generateFlush(){
    cout << "Flush starts at rank=" << all_ranks.size();
        for(int i=0;i<9;++i){
            for(int j=i+1;j<10;++j){
                for(int k=j+1;k<11;++k){
                    for(int l=k+1;l<12;++l){
                        for(int m=l+1;m<13;++m){
                            if(j==i+1&&k==j+1&&l==k+1&&m==l+1) // exclude straight flushes
                                continue;
                            if(i==0&&j==9&&k==10&&l==11&&m==12) // exclude A5432 straight flush
                                continue;
                            else{
                                string ranks_string=ranks[i]+ranks[j]+ranks[k]
                                                    +ranks[l]+ranks[m];
                                sort_wrapper(ranks_string);
                                all_ranks.push_back(ranks_string);
                            }
                        }
                    }
                }
            }
        }
        cout << " and ends at " << all_ranks.size() << endl;
    }
    void generateStraight(){
        cout << "Straight starts at rank=" << all_ranks.size();
        for(int i=0;i<9;++i){
            string ranks_string;
            for(int j=i;j<i+5;++j){
                ranks_string+=ranks[j];
            }
            sort_wrapper(ranks_string);
            all_ranks.push_back(ranks_string);
        }
        string ranks_string="5432A";
        sort_wrapper(ranks_string);
        all_ranks.push_back(ranks_string);
        cout << " and ends at " << all_ranks.size() << endl;
    }
    void generateThreeOfAKind(){
        cout << "Three of a Kind starts at rank=" << all_ranks.size();
        for(int i=0;i<13;++i){
            string pre_string;
            for(int j=0;j<3;++j)
                pre_string+=ranks[i];
            for(int j=0;j<13;++j){
                if(j==i)
                    continue;
                else{
                    for(int k=j+1;k<13;++k){
                        if(k==i)
                            continue;
                        else{
                            string ranks_string=pre_string;
                            ranks_string+=ranks[j];
                            ranks_string+=ranks[k];
                            sort_wrapper(ranks_string);
                            all_ranks.push_back(ranks_string);
                        }
                    }
                }
            }
        }
        cout << " and ends at " << all_ranks.size() << endl;
    }
    void generateTwoPair(){
        cout << "Two Pair starts at rank=" << all_ranks.size();
        for(int i=0;i<13;++i){
            string pre_pre_string;
            for(int j=0;j<2;++j)
                pre_pre_string+=ranks[i];
            for(int j=i+1;j<13;++j){
                string pre_string=pre_pre_string;
                for(int k=0;k<2;++k)
                    pre_string+=ranks[j];
                for(int k=0;k<13;++k){
                    if(k==i||k==j)
                        continue;
                    else{
                        string ranks_string=pre_string;
                        ranks_string+=ranks[k];
                        sort_wrapper(ranks_string);
                        all_ranks.push_back(ranks_string);
                    }
                }
            }
        }
        cout << " and ends at " << all_ranks.size() << endl;
    }
    void generatePair(){
        cout << "Pair starts at rank=" << all_ranks.size();
        for(int i=0;i<13;++i){
            string pre_string;
            for(int j=0;j<2;++j)
                pre_string+=ranks[i];
            for(int j=0;j<13;++j){
                if(j==i)
                    continue;
                else{
                    for(int k=j+1;k<13;++k){
                        if(k==i)
                            continue;
                        else{
                            for(int l=k+1;l<13;++l){
                                if(l==i)
                                    continue;
                                else{
                                    string ranks_string=pre_string;
                                    ranks_string+=ranks[j];
                                    ranks_string+=ranks[k];
                                    ranks_string+=ranks[l];
                                    sort_wrapper(ranks_string);
                                    all_ranks.push_back(ranks_string);
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << " and ends at " << all_ranks.size() << endl;
    }
    void generateHighCard(){
        cout << "High Card starts at rank=" << all_ranks.size();
        for(int i=0;i<9;++i){
            for(int j=i+1;j<10;++j){
                for(int k=j+1;k<11;++k){
                    for(int l=k+1;l<12;++l){
                        for(int m=l+1;m<13;++m){
                            if(j==i+1&&k==j+1&&l==k+1&&m==l+1) // exclude straight
                                continue;
                            if(i==0&&j==9&&k==10&&l==11&&m==12) // exclude A5432 straight
                                continue;
                            else{
                                string ranks_string=ranks[i]+ranks[j]+ranks[k]
                                                    +ranks[l]+ranks[m];
                                sort_wrapper(ranks_string);
                                all_ranks.push_back(ranks_string);
                            }
                        }
                    }
                }
            }
        }  
        cout << " and ends at " << all_ranks.size() << endl;
    }
    void generate_ranks(){
        generateStraightFlush();
        generateFourOfAKind();
        generateFullHouse();
        generateFlush();
        generateStraight();
        generateThreeOfAKind();
        generateTwoPair();
        generatePair();
        generateHighCard();
    }
    void write_to_file(){
        string filename="ranks.csv";
        ofstream myfile(filename);
        int vsize = all_ranks.size()-1;
        for(int n=0;n<vsize;++n){
            myfile << all_ranks[n];
            myfile << "," ;
        }
        myfile << all_ranks[vsize];
    }
    void sort_wrapper(string & str){
        vector<int> enc;
        for(char s : str)
            enc.push_back(encode[s]);
        sort(enc.begin(),enc.end());
        string res;
        for(int x : enc)
            res+=decode[x];
        str=res;
    }

    vector<string> get_all_ranks(){
        return all_ranks;
    }
private:
    vector<string> ranks;
    vector<string> all_ranks;
    map<char,int> encode;
    map<int,char> decode;
};

int main(){
    GenerateRankings generate_rankings;
    generate_rankings.generate_ranks();
  //  vector<string> allRanks=generate_rankings.get_all_ranks();
  //  for(string s : allRanks)
  //      cout << s << endl;
  //  cout << allRanks.size() << endl;
    generate_rankings.write_to_file();
    return 0;
}