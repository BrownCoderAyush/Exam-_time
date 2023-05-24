#include <bits/stdc++.h>
#include <numeric>
#define ll long long
#define ull unsigned long long
#define fl for (int i = 0; i < n; i++)
#define vll vector<ll>
#define pb push_back
#define M 1000000007
#define endl "\n"
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL));

using namespace std;

bool comp(pair<int,double> a , pair<int,double> b){
    return a.first > b.first ; 
}

int main()
{
	fastread();
    
	int n;
    int fweight;
    double result = 0;
    cin>>n;
    cin>>fweight;
    vll weight(n);
    vll profit(n);
    fl{
        cin>>weight[i];
    }
    fl{
        cin>>profit[i];
    }
    vector<pair<int,double>> PPW(n);
    for(int i = 0 ; i < n ; i++){
        PPW[i].first = weight[i];
        PPW[i].second = (double)profit[i]/weight[i];
    }
    sort(PPW.begin(),PPW.end(),comp);



    for(int i = 0 ; i < PPW.size() ; i++){
        cout<<PPW[i].first<<" "<<PPW[i].second<<" "<<PPW[i].first*PPW[i].second<<endl;
        if(PPW[i].first>=fweight){
            result += PPW[i].first*PPW[i].second;
            fweight-=PPW[i].first;
        }else{
            result+= fweight*PPW[i].second;
            break;
        }

    }
    cout<<result;
	return 0;
}