#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
void addentry(unordered_map<string, unordered_map<long long, pair<string, pair<long long, string>>>> dire)
{
    cout<<"Enter the number of the club in which you want to get added"<<endl;

    cout<<"Please follow the following menu clubs"<<endl
            <<"1.Radio Club  2.Sambhav  3.Business Club  4.DCEI"<<endl
            <<"5.CINS  6.Webkit Club  7.Muse Club  8.Debate Club  9.Music Club"<<endl
            <<"10.Developer Student Club  11.Chess Club  12.Press Club  13.IEEE"<<endl
            <<"14.Film Club  15.Research Club  16.Programming Club  17.PMMC"<<endl
            <<"18.Khelaiya Club  19.Cubing Club  20.Excursion Club  21.BIS club"<<endl
            <<"22.Heritage Club  23.Electronic Hobby Centre  24.Headrush-quizzing"<<endl
            <<"25.DAIICT Theatre Group"<<endl;
        int c2;
        int x;
        cin>>x;
        do 
        {
        switch(x)
        {
            case 1:
            {
                int a1,a2,a3;
                cout<<"Have you heard any news, speech from radio in the past? (YES - 1 and NO - 0)"<<endl;
                cin>>a1;
                cout<<"Do you have interest in writing poems, giving speeches? (YES - 1 and NO - 0)"<<endl;
                cin>>a2;
                cout<<"Do you love graphic designing? (YES - 1 and NO - 0)"<<endl;
                cin>>a3;
                if(a1 && a2 && a3)
                {
                    add(dire,"Radio");
                }
                else
                {
                    cout<<"Sorry, you are not eligible for radio club"<<endl;
                }
                break;
            }
            case 2:
            {
                int b1,b2,b3;
                cout<<"Do you have interest in contributing for society? (YES - 1 and NO - 0)"<<endl;
                cin>>b1;
                cout<<"Can you spare time for social activities? (YES - 1 and NO - 0)"<<endl;
                cin>>b2;
                cout<<"Do you want to make it possible? (YES - 1 and NO - 0)"<<endl;
                cin>>b3;
                 if(b1 && b2 && b3)
                {
                    add(dire,"Sambhav");
                }
                else
                {
                    cout<<"Sorry, you are not eligible for Sambhav at DAIICT"<<endl;
                }
                break;
            }
            case 3:
            {
                int c1,c2,c3;
                cout<<"Do you have a business mind? (YES - 1 and NO - 0)"<<endl;
                cin>>c1;
                cout<<"Do you have fresh ideas to induce in business community? (YES - 1 and NO - 0)"<<endl;
                cin>>c2;
                cout<<"Can you take risk? (YES - 1 and NO - 0)"<<endl;
                cin>>c3;
                if(c1 && c2 && c3)
                {
                    add(dire,"Business");
                }
                else
                {
                     cout<<"Sorry, you are not eligible for Business club at DAIICT"<<endl;
                }
                break;
            }
            case 4:
            {
                int d1,d2,d3;
                cout<<"Do you have interest in contributing for society? (YES - 1 and NO - 0)"<<endl;
                cin>>d1;
                cout<<"Can you spare time for social activities? (YES - 1 and NO - 0)"<<endl;
                cin>>d2;
                cout<<"Do you want to make it possible? (YES - 1 and NO - 0)"<<endl;
                cin>>d3;
                if(d1 && d2 && d3)
                {
                    add(dire,"DCEI");
                }
                else
                {
                     cout<<"Sorry, you are not eligible for DCEI club at DAIICT"<<endl;
                }
                break;
            }
            case 6:
            {
                int e1,e2,e3;
                cout<<"Do you have interest in development? (YES - 1 and NO - 0)"<<endl;
                cin>>e1;
                cout<<"Are you interested in exploring new web technologies? (YES - 1 and NO - 0)"<<endl;
                cin>>e2;
                cout<<"Are you willing to make a future in this branch? (YES - 1 and NO - 0)"<<endl;
                cin>>e3;
                if(e1 && e2 && e3)
                {
                    add(dire,"WebKit");
                }
                else
                {
                    cout<<"Sorry you are not eligible for WEBKIT at DAIICT"<<endl;
                }
                break;
            }
            case 5:
            {
                 int f1,f2,f3;
                cout<<"Do you have interest in cyber security? (YES - 1 and NO - 0)"<<endl;
                cin>>f1;
                cout<<"Do you like hacking or see your future in this field? (YES - 1 and NO - 0)"<<endl;
                cin>>f2;
                cout<<"Are you willing to take on challenging tasks? (YES - 1 and NO - 0)"<<endl;
                cin>>f3;
                if(f1 && f2 && f3)
                {
                    add(dire,"CINS");
                }
                else
                {
                    cout<<"Sorry you are not eligible for CINS at DAIICT"<<endl;
                }
                break;
            }
            case 7:
            {
                int g1,g2,g3;
                cout<<"Do you have interest in interesting designs? (YES - 1 and NO - 0)"<<endl;
                cin>>g1;
                cout<<"Do you like to flaunt your imaginations through sketch? (YES - 1 and NO - 0)"<<endl;
                cin>>g2;
                cout<<"Are you willing to join Muse Club? (YES - 1 and NO - 0)"<<endl;
                cin>>g3;
                if(g1 && g2 && g3)
                {
                    add(dire,"Muse");
                }
                else
                {
                    cout<<"Sorry you are not eligible for Muse at DAIICT"<<endl;
                }
                break;
            }
            case 8:
            {
                int h1,h2,h3;
                cout<<"Do you have interest in public speaking? (YES - 1 and NO - 0)"<<endl;
                cin>>h1;
                cout<<"Do you like to prove your point through strong voice and facts? (YES - 1 and NO - 0)"<<endl;
                cin>>h2;
                cout<<"Do you want to learn how to convince others? (YES - 1 and NO - 0)"<<endl;
                cin>>h3;
                if(h1 && h2 && h3)
                {
                    add(dire,"Debate");
                }
                else
                {
                    cout<<"Sorry you are not eligible for Debate Club at DAIICT"<<endl;
                }
                break;
            }
            case 9:
            {
                int i1,i2,i3;
                cout<<"Do you have interest in music and musical instruments? (YES - 1 and NO - 0)"<<endl;
                cin>>i1;
                cout<<"Do you know how to play any musical instrument? (YES - 1 and NO - 0)"<<endl;
                cin>>i2;
                cout<<"Do you want to be a part of musical events and contests? (YES - 1 and NO - 0)"<<endl;
                cin>>i3;
                if(i1 && i2 && i3)
                {
                    add(dire,"Music");
                }
                else
                {
                    cout<<"Sorry you are not eligible for Music Club at DAIICT"<<endl;
                }
                break;
            }
             case 10:
            {
                int j1,j2,j3;
                cout<<"Do you have interest in development? (YES - 1 and NO - 0)"<<endl;
                cin>>j1;
                cout<<"Do you know any languages like CSS? (YES - 1 and NO - 0)"<<endl;
                cin>>j2;
                cout<<"Do you want to be a part of Web development contests? (YES - 1 and NO - 0)"<<endl;
                cin>>j3;
                if(j1 || j2 || j3)
                {
                    add(dire,"DSClub");
                }
                else
                {
                    cout<<"Sorry you are not eligible for Developer Student Club at DAIICT"<<endl;
                }
                break;
            }
            case 11:
            {
                int k1,k2,k3;
                cout<<"Do you have interest in chess? (YES - 1 and NO - 0)"<<endl;
                cin>>k1;
                cout<<"Do you know all rules of chess=? (YES - 1 and NO - 0)"<<endl;
                cin>>k2;
                cout<<"Do you want to be a part of chess contests? (YES - 1 and NO - 0)"<<endl;
                cin>>k3;
                if(k1 || k2 || k3)
                {
                    add(dire,"Chess");
                }
                else
                {
                    cout<<"Sorry you are not eligible for Chess Club at DAIICT"<<endl;
                }
                break;
            }
            case 12:
            {
                int l1,l2,l3;
                cout<<"Do you have interest in journalism and press reporting? (YES - 1 and NO - 0)"<<endl;
                cin>>l1;
                cout<<"Do you like to have your own views on any topic? (YES - 1 and NO - 0)"<<endl;
                cin>>l2;
                cout<<"Do you want to make a change through reporting and raising voice? (YES - 1 and NO - 0)"<<endl;
                cin>>l3;
                if(l1 || l2 || l3)
                {
                    add(dire,"Press");
                }
                else
                {
                    cout<<"Sorry you are not eligible for Press Club at DAIICT"<<endl;
                }
                break;
            }
            case 13:
            {
                int l1,l2,l3;
                cout<<"Do you like electronics? (YES - 1 and NO - 0)"<<endl;
                cin>>l1;
                cout<<"Have you made any hardware based projects? (YES - 1 and NO - 0)"<<endl;
                cin>>l2;
                cout<<"Do you want to be a part of workshops of electronics and Arduino? (YES - 1 and NO - 0)"<<endl;
                cin>>l3;
                if(l1 || l2 || l3)
                {
                    add(dire,"IEEE");
                }
                else
                {
                    cout<<"Sorry you are not eligible for IEEE at DAIICT"<<endl;
                }
                break;
            }
            case 14:
            {
                int m1,m2,m3;
                cout<<"Do you like films? (YES - 1 and NO - 0)"<<endl;
                cin>>m1;
                cout<<"Have you ever recommended films to anyone? (YES - 1 and NO - 0)"<<endl;
                cin>>m2;
                cout<<"Do you want to organise movie nights for your friends? (YES - 1 and NO - 0)"<<endl;
                cin>>m3;
                if(m1 || m2 || m3)
                {
                    add(dire,"film");
                }
                else
                {
                    cout<<"Sorry you are not eligible for film club at DAIICT"<<endl;
                }
                break;
            }
            case 15:
            {
                 int n1,n2,n3;
                cout<<"Do you like to do detail research on any topic? (YES - 1 and NO - 0)"<<endl;
                cin>>n1;
                cout<<"Do you like to personally rechack facts and figure to draw conclusions? (YES - 1 and NO - 0)"<<endl;
                cin>>n2;
                cout<<"Have you made any research based projects earlier also? (YES - 1 and NO - 0)"<<endl;
                cin>>n3;
                if(n1 || n2 || n3)
                {
                    add(dire,"Research");
                }
                else
                {
                    cout<<"Sorry you are not eligible for research club at DAIICT"<<endl;
                }
                break;
            }
            case 16:
            {
                int n1,n2,n3;
                cout<<"Do you like to apply deep logic to make program on any topic? (YES - 1 and NO - 0)"<<endl;
                cin>>n1;
                cout<<"Do you like competitive coding? (YES - 1 and NO - 0)"<<endl;
                cin>>n2;
                cout<<"Do you want to make career in coding? (YES - 1 and NO - 0)"<<endl;
                cin>>n3;
                if(n1 || n2 || n3)
                {
                    add(dire,"Programming");
                }
                else
                {
                    cout<<"Sorry you are not eligible for programming club at DAIICT"<<endl;
                }
                break;
            }
            case 17:
            {
                int o1,o2,o3;
                cout<<"Do you like taking photographs and videos? (YES - 1 and NO - 0)"<<endl;
                cin>>o1;
                cout<<"Do you like to take snapshots of beautiful landscapes? (YES - 1 and NO - 0)"<<endl;
                cin>>o2;
                cout<<"Are you interested in making detailed documentaries and editing videos? (YES - 1 and NO - 0)"<<endl;
                cin>>o3;
                if(o1 || o2 || o3)
                {
                    add(dire,"PMMC");
                }
                else
                {
                    cout<<"Sorry you are not eligible for PMMC at DAIICT"<<endl;
                }
                break;
            }
            case 18:
            {
                int p1,p2,p3;
                cout<<"Do you enjoy while doing Garba? (YES - 1 and NO - 0)"<<endl;
                cin>>p1;
                cout<<"Are you excited to learn Garba? (YES - 1 and NO - 0)"<<endl;
                cin>>p2;
                cout<<"Do you play Garba on every occasion ? (YES - 1 and NO - 0)"<<endl;
                cin>>p3;
                if(p1 || p2 || p3)
                {
                    add(dire,"Khelaiya");
                }
                else
                {
                    cout<<"Sorry you are not eligible for Khelaiya at DAIICT"<<endl;
                }
                break;
            }
            case 19:
            {
                int q1,q2,q3;
                cout<<"Do you know how to solve a 3 x 3 Cube? (YES - 1 and NO - 0)"<<endl;
                cin>>q1;
                cout<<"Are you excited to learn 4 x 4 and 2 x 2 cube? (YES - 1 and NO - 0)"<<endl;
                cin>>q2;
                cout<<"Do you think you can represent DAIICT cubing club infront of other colleges ? (YES - 1 and NO - 0)"<<endl;
                cin>>q3;
                if(q1 || q2 || q3)
                {
                    add(dire,"Cubing");
                }
                else
                {
                    cout<<"Sorry you are not eligible for Cubing at DAIICT"<<endl;
                }
                break;
            }
            cout<<"If you want to continue, Press 1 or to exit Press 0"<<endl;
            cin>>c2;
        }
        
        }
        while(c2==1);

    
}
void add(unordered_map<string, unordered_map<long long, pair<string, pair<long long, string>>>> directory,string club_name)
{

}