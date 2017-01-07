class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    set<long long int>occupied;
    int m;
    int n;
    deque<pair<int,int>>snake;
    queue<pair<int,int>>foodCoord;
    int count;
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        m = height;
        n = width;
        for(int i=0;i<food.size();i++)
            foodCoord.push(food[i]);
        snake.push_front(pair<int,int>{0,0});
        occupied.insert(0);
        count=0;
    }

    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
        @return The game's score after the move. Return -1 if game over.
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        pair<int,int> head = snake.front();
        pair<int,int> new_coord = head;
        pair<int, int>back = snake.back();
        occupied.erase(back.first*n+back.second);
        if(direction=="R")
        {
            new_coord.second++;
            if(new_coord.second>=n || occupied.find(new_coord.first*n+new_coord.second)!=occupied.end())
                return -1;
        }
        if(direction=="D")
        {
            new_coord.first++;
            if(new_coord.first>=m || occupied.find(new_coord.first*n+new_coord.second)!=occupied.end())
                return -1;
        }
        if(direction=="U")
        {
            new_coord.first--;
            if(new_coord.first<0 || occupied.find(new_coord.first*n+new_coord.second)!=occupied.end())
                return -1;
        }
        if(direction=="L")
        {
            new_coord.second--;
            if(new_coord.second<0 || occupied.find(new_coord.first*n+new_coord.second)!=occupied.end())
                return -1;
        }
        snake.push_front(new_coord);
        if(!foodCoord.empty())
        {
            pair<int,int> food = foodCoord.front();
            if(new_coord.first==food.first && new_coord.second==food.second)
            {
                foodCoord.pop();
                occupied.insert(back.first*n+back.second);
                count++;
            }
            else
            {
                snake.pop_back();
            }
        }
        else
        {
            snake.pop_back();
        }
        occupied.insert(n*new_coord.first+new_coord.second);
        return count;

    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */
