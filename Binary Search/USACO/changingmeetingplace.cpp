#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define forn(i,j) for(ll i = 0; i < j; i++)
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define p push
#define f first
#define s second

#define MOD 1000000007

const double MAX_ERROR = 10e-7;

vector<double> locations;
vector<double> speed;
bool right_has_max = false;
bool left_has_max = false;
double curr_min_time;
double min_ans = (double)INT_MAX;

void siout(string name = "") { 

	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

double time(const double p){
    double MAX_TIME = 0;

    forn(i,locations.size()){
        if(locations[i] == p){ continue;}
        double i_time = abs(locations[i] - p)/speed[i];

        if(i_time > MAX_TIME){ 
            left_has_max = false;
            right_has_max = false;
            if(locations[i] > p){
                right_has_max = true;
            } else{
                left_has_max = true;
            }
            MAX_TIME = i_time;
        }

        else if(i_time == MAX_TIME){
            if(locations[i] > p){
                right_has_max = true;
            } else{
                left_has_max = true;
            }
        }
    }
    return MAX_TIME;
}

int main(){
    siout();
    int n;
    cin >> n;

    locations.resize(n);
    speed.resize(n);

    double low = 0;
    double high = 0;
    double mid;

    forn(i,n){
        cin >> locations[i];
        high = max(locations[i], high);
    }

    forn(i,n){ cin >> speed[i];}

    while(high - low > MAX_ERROR){
        mid = (high+low)/2;

        curr_min_time = time(mid);    
        min_ans = min(curr_min_time, min_ans);

        if(right_has_max && left_has_max){
            break;
        }

        if(right_has_max){
            low = mid;
        }

        else{
            high = mid;
        }
    }

    cout << fixed << min_ans << endl;
}