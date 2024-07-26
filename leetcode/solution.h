#include <bits/stdc++.h>
using namespace std;


typedef pair<int, int> pos_t;

template<>
class std::hash<pos_t> 
{
public:
	size_t operator()(const pos_t& p)const {
		size_t seed = 0;
	    seed ^= hash<int>()(p.first) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        seed ^= hash<int>()(p.second) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        return seed;
	}
};

class Solution 
{
    char ant_char[4] = {'R', 'D', 'L', 'U'};
    pos_t ant_dir[4] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

    inline void turn(int& ant, int dir) const
    {
        ant += dir;

        if (dir < 0)
        {
            ant += 4;
        }
        else if (dir > 3)
        {
            ant -= 4;
        }
    }

    inline pos_t plus(const pos_t& l, const pos_t& r) const
    {
        return pos_t(l.first + r.first, l.second + r.second);
    }

public:
    vector<string> printKMoves(int K) 
    {
        pos_t ant_pos;                  // 蚂蚁位置
        int ant_i = 0;                  // 蚂蚁状态索引
        unordered_set<pos_t> blacks;    // 所有黑色区块
        pos_t rd_pos = {0, 0};                   // 蚂蚁走过范围的右下角坐标
        pos_t lu_pos = {0, 0};                   // 蚂蚁走过范围的左上角坐标

        // 模拟蚂蚁移动
        while (K--)
        {
            auto it = blacks.find(ant_pos);
            
            // 白色
            if (it == blacks.end())
            {
                blacks.insert(ant_pos);
                turn(ant_i, 1);
            }
            // 黑色
            else
            {
                blacks.erase(it);
                turn(ant_i, -1);
            }

            // 向前移动
            ant_pos = plus(ant_pos, ant_dir[ant_i]);

            // 记录蚂蚁走过的最大范围
            lu_pos = {min(ant_pos.first, lu_pos.first), max(ant_pos.second, lu_pos.second)};
            rd_pos = {max(ant_pos.first, rd_pos.first), min(ant_pos.second, rd_pos.second)};
        }

        // 生成网格
        vector<string> grid(lu_pos.second - rd_pos.second + 1, string(rd_pos.first - lu_pos.first + 1, '_'));
        pos_t t_pos;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].length(); j++)
            {
                t_pos = {lu_pos.first + j, lu_pos.second - i};
                if (t_pos == ant_pos)
                {
                    grid[i][j] = ant_char[ant_i];
                }
                else if (blacks.contains(t_pos))
                {
                    grid[i][j] = 'X';
                }
            }
        }

        return grid;
    }
};
