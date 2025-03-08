// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC optimize("O3,unroll-loops")


#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
// typedef tree<
//     int,
//     null_type,
//     less_equal<int>,
//     rb_tree_tag,
//     tree_order_statistics_node_update
// >
// ordered_set;
namespace __gnu_pbds{
          typedef tree<long long,
                       null_type,
                       less_equal<long long>,
                       rb_tree_tag,
                       tree_order_statistics_node_update> ordered_set;
}
using namespace __gnu_pbds;

#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#include "nlohmann/json.hpp"
using json = nlohmann::json;
using namespace __gnu_pbds;


 
void __print32_t(int32_t x) {cerr << x;}
void __print32_t(long x) {cerr << x;}
void __print32_t(long long x) {cerr << x;}
void __print32_t(unsigned x) {cerr << x;}
void __print32_t(unsigned long x) {cerr << x;}
void __print32_t(unsigned long long x) {cerr << x;}
void __print32_t(float x) {cerr << x;}
void __print32_t(double x) {cerr << x;}
void __print32_t(long double x) {cerr << x;}
void __print32_t(char x) {cerr << '\'' << x << '\'';}
void __print32_t(const char *x) {cerr << '\"' << x << '\"';}
void __print32_t(const string &x) {cerr << '\"' << x << '\"';}
void __print32_t(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print32_t(const pair<T, V> &x) {cerr << '{'; __print32_t(x.first); cerr << ','; __print32_t(x.second); cerr << '}';}
template<typename T>
void __print32_t(const T &x) {int32_t f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print32_t(i); cerr << "}";}
void _print32_t() {cerr << "]\n";}
template <typename T, typename... V>
void _print32_t(T t, V... v) {__print32_t(t); if (sizeof...(v)) cerr << ", "; _print32_t(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print32_t(x)
#else
#define debug(x...)
#endif
 
template<typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;
#define rep(i,a,b) for(int32_t i = a; i < b; i ++)
#define ill long long int32_t
#define ll long long
#define int int64_t
#define nl "\n"
#define el endl
#define pb push_back
#define FOR(a,b,c) for (int32_t a = b; a < c; a++)
using namespace std;
 
 
// const int32_t N = 3e5+1;
const ll neg_inf = -2e7 + 2;    
const ll inf = 1e18 + 1;
// const int32_t mod = 998244353;
// const int32_t MOD = 1e9+7;
const int32_t MAXN = 4e6+1;
const int32_t eps = 1e-6;
const int N = 1e6+1;

bool definitelyGreaterThan(double a, double b, double epsilon = eps)
{
    return (a - b) > ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

struct Hero {
    int x,y;
    int base_speed;
    int base_power;
    int base_range;
    int level_speed_coeff;
    int level_power_coeff;
    int level_range_coeff;

    int level = 1;
    int exp = 0;
    int req = 0;
    int speed = 0;
    int power = 0;
    int range = 0;

    Hero(int posx,int posy,int bs,int bp,int br,int lsc, int lpc, int lrc) {
        x = posx, y = posy, base_power = bp, base_speed = bs, base_range = br;
        level_power_coeff = lpc;
        level_speed_coeff = lsc;
        level_range_coeff = lrc;
        speed = bs;
        power = bp;
        range = br;
        req = 1000 + level*(level-1)*50;
    }

    Hero() {};

    void level_up() {
        if (exp < req) return;
        exp -= req;
        speed = (base_speed*(100+(level*level_speed_coeff)))/100;
        power = (base_power*(100+(level*level_power_coeff)))/100;
        range = (base_range*(100+(level*level_range_coeff)))/100;
        level++;
        // debug(speed,power,range);
        req = 1000 + level*(level-1)*50;
    }

    bool check_move(int tox,int toy) {
        double temp = (tox-x)*(tox-x) + (toy-y)*(toy-y);
        // debug(temp)
        if (!definitelyGreaterThan(temp,speed*speed)) {
            return true;
        }
        return false;
    }

    bool move (int tox, int toy) {
        int temp = (tox-x)*(tox-x) + (toy-y)*(toy-y);
        if (check_move(tox,toy)) {
            // debug(speed,range,exp,level);
            x = tox, y = toy;
            return true;
        }
        return false;
    }

    bool attackable(int tox, int toy) {
        double temp = (tox-x)*(tox-x) + (toy-y)*(toy-y);
        if (!definitelyGreaterThan(temp,range*range)) {
            // debug(temp,range*range);
            return true;
        }
        
        return (false);
    }

};

struct Monsters {
    int x,y;
    int exp;
    int gold;
    int hp;
    int id;
    Monsters(int posx,int posy,int e, int g, int h, int iid) {
        x = posx;
        y = posy;
        gold = g;
        exp = e;
        hp = h;
        id = iid;
    }
    Monsters () {};
    bool attack (Hero hero) {
       hp -= hero.power; 
       return (hp <= 0);
    }
};

class SimulatedAnnealing {
public:
    int number;
    Hero hero;
    int num_turns;
    map<array<int,2>,int> del,monspos,vis;
    SimulatedAnnealing(int n) {
        number = n;
    }
    int w,h;
    vector<Monsters> monsters;

    void read(bool sample) {
        string s = "inputs/";
        string filename = to_string(number);
        reverse(filename.begin(),filename.end());
        while (filename.size() < 3) filename += '0';
        reverse(filename.begin(),filename.end());
        filename += ".json";
        s += filename;

        ifstream f(s);
        json j = json::parse(f);

        if (sample) {
            ifstream f("inputs/sample.json");
            j = json::parse(f);
        }
        w = j["width"];
        h = j["height"];
        // cout << j << nl;
        hero = Hero(j["start_x"],j["start_y"],j["hero"]["base_speed"],j["hero"]["base_power"],j["hero"]["base_range"],j["hero"]["level_speed_coeff"],j["hero"]["level_power_coeff"],j["hero"]["level_range_coeff"]);
        // debug("here");
        int id = 0;
        for (auto m : j["monsters"]) {
            monsters.push_back(Monsters(m["x"],m["y"],m["exp"],m["gold"],m["hp"],id));
            id++;
            monspos[{monsters.back().x,monsters.back().y}] = 1;
        }
        num_turns = j["num_turns"];
    }

    array<int,2> get_neighbour() {
        default_random_engine generator(std::random_device{}());
        uniform_int_distribution<int> distw(0,w-1), disth(0,h-1);
        double val = 0;
        int it = 100;
        int x__=-1,y__=-1;
        while (it--) {
            int x_ = distw(generator);
            int y_ = disth(generator);
            if (monspos[{x_,y_}] == 1 && del[{x_,y_}] != 1 || vis[{x_,y_}] == 1) continue;
            if (x_ == hero.x && y_ == hero.y) continue;
            if (hero.check_move(x_,y_)) {
                double cnt = 0;
                double avg = 0;
                for (auto m : monsters) {
                    if (del[{m.x,m.y}] == 1) continue;
                    cnt++;
                    avg += (m.y-y_)*(m.y-y_) + (m.x-x_)*(m.x-x_);
                }
                avg /= cnt;

                if (avg > val) {
                    val = avg;
                    x__ = x_;
                    y__ = y_;
                }
            }
        }
        return {x__,y__};
    }

    vector<Monsters> get_state (int x, int y, int rem) {
        vector<Monsters> res;
        for (auto m : monsters) {
            if (hero.attackable(m.x,m.y) && (m.hp+hero.power-1)/hero.power <= rem && del[{m.x,m.y}] == 0) {
                res.push_back(m);
            }
        }
        return res;
    }

    double prob (int tox, int toy, int rem, double temp) {
        double val = 0;
        double cnt = 0;
        // debug(temp);
        for (auto m : monsters) {
            if (del[{m.x,m.y}] == 1) continue;
            int ttk = (m.hp+hero.power-1)/hero.power;
            double dis = (m.x-hero.x)*(m.x-hero.x) + (m.y-hero.y)*(m.y-hero.y);
            cnt++;
            val += ((double)ttk + (double)dis)/(double(ttk) + (double)(m.gold) + (double)(m.exp));
        }
        double pw = (val/(double)temp);
        // debug(val,temp,pw,exp(pw));
        return exp(pw);
    }

    double prob2(vector<Monsters> &mons, int temp) {
        double val = 0;
        int index = -1, ttkf = 0;
        for (int i = 0; i < mons.size(); i++) {
            auto m = mons[i];
            int ttk = (m.hp+hero.power-1)/hero.power;
            double currval = ((double)m.gold + (double)m.exp)/double(ttk);
            if (currval > val) {
                val = currval;
                ttkf = ttk;
                index = i;
            }
        }
        return exp(-val/temp);
    }

    pair<int,json> solve(double temp1, double ch) {
        int stx = hero.x, sty = hero.y;
        int steps = 0;
        default_random_engine gen(std::random_device{}());
        uniform_int_distribution<int> dist(1,100);
        uniform_real_distribution<double> rdist(0,1);
        int gold = 0;
        int tottime = 1000000;
        int time = 0;
        json j;
        vector<json> tempv;
        j["moves"] = tempv;
        double temp = temp1;
        default_random_engine generator(std::random_device{}());
        uniform_int_distribution<int> distw(0,w-1), disth(0,h-1);
        int xst = distw(generator), yst = disth(generator);
        // int xst = hero.x, yst = hero.y;
        while (hero.x != xst && hero.y != yst) {
            
            if (steps == num_turns) break;
            int moveallowed = hero.speed;
            // moveallowed *= moveallowed;
            int tox=hero.x,toy=hero.y;
            
            
            if (hero.x != xst) {
                int smallmove = abs(xst-hero.x);
                // tox,toy = yst;
                if (hero.x < xst) {
                    tox = hero.x + min(smallmove,moveallowed);
                }
                else {
                    tox = hero.x - min(smallmove,moveallowed);
                }
            }
            else {
                int smallmove = abs(yst-hero.y);
                // tox=xst,toy;
                if (hero.y < yst) {
                    toy = hero.y + min(smallmove,moveallowed);
                }
                else {
                    toy = hero.y - min(smallmove,moveallowed);
                }
            }
            
            json j_temp;
            j_temp["type"] = "move";
            j_temp["target_x"] = tox;
            j_temp["target_y"] = toy;
            hero.move(tox,toy);
            j["moves"].push_back(j_temp);
            // debug(moveallowed,steps,xst,yst,hero.x,hero.y,tox,toy,moveallowed);
            steps++;
        }
        // debug(xst,yst,steps);
        while (time < tottime) {
            // debug(time,temp,a,temp*a);
            if (steps == num_turns) break;
            double a = rdist(gen);
            int rem = num_turns - steps;
            vis[{hero.x,hero.y}] = 1;
            // debug(steps,num_turns,a);
            vector<Monsters> mons = get_state(hero.x,hero.y,rem);
            int pro2 = prob2(mons,temp);
            // debug(pro2,a);
            if (!definitelyGreaterThan(a,pro2)) {
                array<int,2> next_move = get_neighbour();
                int tox = next_move[0], toy = next_move[1];
                if (tox == -1) {
                    time++;
                    // debug(temp,a);
                    temp = temp*ch;
                    // debug(temp);
                    continue;
                }
                double probability = prob(tox,toy,rem-1,temp);
                double probv = rdist(gen);
                // debug(a,probv,probability);
                if (definitelyGreaterThan(probability,probv)) {
                    hero.move(tox, toy);
                    json j_temp;
                    j_temp["type"] = "move";
                    j_temp["target_x"] = tox;
                    j_temp["target_y"] = toy;
                    j["moves"].push_back(j_temp);
                    steps++;
                }
            }
            else {

                double val = 0;
                int index = -1, ttkf = 0;
                for (int i = 0; i < mons.size(); i++) {
                    auto m = mons[i];
                    int ttk = (m.hp+hero.power-1)/hero.power;
                    double currval = ((double)m.gold + (double)m.exp)/double(ttk);
                    if (currval > val) {
                        val = currval;
                        ttkf = ttk;
                        index = i;
                    }
                }
                if (index != -1) {
                    steps += ttkf;
                    gold += mons[index].gold;
                    hero.exp += mons[index].exp;
                    hero.level_up();
                    del[{mons[index].x,mons[index].y}] = 1;
                    for (int c = 0; c < ttkf; c++) {
                        json j_temp;
                        j_temp["type"] = "attack";
                        j_temp["target_id"] = mons[index].id;
                        j["moves"].push_back(j_temp);
                    }
                    
                }
            }
            temp = temp*ch;
            time++;
        }
        return {gold,j};
    }

};

ll runcases(int qq)
{  

    vector<int> res;

    for (int file = 12; file <= 25; file++) {
        int ans = 0;
        json fin;
        cout << "Starting with file : " << file << nl;
        int lim;
        if (file < 3) lim = 500;
        else lim = 10; 
        for (int i = 0; i < lim; i++) {
            SimulatedAnnealing sa(file);
            sa.read(false);
            auto ret = sa.solve(1e9,0.99999);
            int gold = ret.first;
            json j = ret.second;
            debug(i,gold);
            if (gold > ans) {
                ans = gold;
                fin = j;
            }
        }

        debug(file,ans);
        res.push_back(ans);
        string out_file = "output";
        out_file += to_string(file);
        out_file += ".json";
        std::ofstream ofs;
        ofs.open(out_file, std::ofstream::out | std::ofstream::trunc);
        string s = fin.dump();
        ofs << s;
        ofs.close();
    }

    for (int file = 12; file <= 25; file++) {
        cout << "Score of test " << file << ": " << res[file-12] << nl;
    }
    

    return 0;
}

 
signed main()
{
    
    //..........Fast I/O.........//
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);cout.tie(0);
    //..........................//


 

    ll t ;
 
    t = 1;

    // debug(t);
    for (int32_t i = 1; i <= t; i ++) {
        runcases(i);
    }
    
    return 0;
 
}