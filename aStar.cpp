#include <bits/stdc++.h>

#define ROW 3
#define COL 3

using namespace std;

typedef pair<int, pair<int, int>> myPair;

int gethammingDistance(int row, int col, int initial_mat[][3], int goal_mat[][3])
{
    int count = 0; // No of tiles that are out of place

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (initial_mat[i][j] != goal_mat[i][j])
                count++;
        }
    }
    if(count == 0) return 0;
    else return count-1;
}

void aStarAlgorithm(int initial_mat[][3], int goal_mat[][3], int row, int col){
    priority_queue<myPair, vector<myPair>, greater<myPair>>pq;

    int currCol = 0;
    int currRow = 0;

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (initial_mat[i][j] == -1){
                currCol = j;
                currRow = i;
               break;
            }
        }
    }

    int count = 1;
    int h_dist = gethammingDistance(row,col,initial_mat,goal_mat);
    pq.push(make_pair(h_dist,make_pair(currRow,currCol)));
    myPair q;
    
    do{

        cout<<"Iteration: "<<count<<endl;

        if(currRow + 1 < ROW){
            swap(initial_mat[currRow + 1][currCol], initial_mat[currRow][currCol]);      
            h_dist = gethammingDistance(row, col, initial_mat,goal_mat) ;
            cout<<h_dist<<endl;
            for(int i = 0; i < ROW; i++){
                for(int j = 0; j < COL; j++){
                    cout<<initial_mat[i][j]<<" ";

                }
                cout<<endl;
            }
            cout<<endl;
            pq.push(make_pair(h_dist,make_pair(currRow+1,currCol)));
            swap(initial_mat[currRow + 1][currCol], initial_mat[currRow][currCol]); 
        }
        if(currRow - 1 >= 0){
            swap(initial_mat[currRow - 1][currCol], initial_mat[currRow][currCol]);      
            h_dist = gethammingDistance(row, col, initial_mat,goal_mat) ;
            cout<<h_dist<<endl;
            for(int i = 0; i < ROW; i++){
                for(int j = 0; j < COL; j++){
                    cout<<initial_mat[i][j]<<" ";

                }
                cout<<endl;
            }
            cout<<endl;
            pq.push(make_pair(h_dist,make_pair(currRow-1,currCol)));
            swap(initial_mat[currRow - 1][currCol], initial_mat[currRow][currCol]); 
        }
        if(currCol + 1 < COL){
            swap(initial_mat[currRow][currCol + 1], initial_mat[currRow][currCol]);      
            h_dist = gethammingDistance(row, col, initial_mat,goal_mat) ;
             cout<<h_dist<<endl;
            for(int i = 0; i < ROW; i++){
                for(int j = 0; j < COL; j++){
                    cout<<initial_mat[i][j]<<" ";

                }
                cout<<endl;
            }
            cout<<endl;
            pq.push(make_pair(h_dist,make_pair(currRow,currCol+1)));
            swap(initial_mat[currRow][currCol + 1], initial_mat[currRow][currCol]); 
        }
        if(currRow - 1 >= 0){
            swap(initial_mat[currRow][currCol - 1], initial_mat[currRow][currCol]);      
            h_dist = gethammingDistance(row, col, initial_mat,goal_mat) ;
            cout<<h_dist<<endl;
            for(int i = 0; i < ROW; i++){
                for(int j = 0; j < COL; j++){
                    cout<<initial_mat[i][j]<<" ";

                }
                cout<<endl;
            }
            cout<<endl;
            pq.push(make_pair(h_dist,make_pair(currRow,currCol-1)));
            swap(initial_mat[currRow][currCol - 1], initial_mat[currRow][currCol]); 
        }

        q = pq.top();
        pq.pop();

        h_dist = q.first;
        swap(initial_mat[currRow][currCol], initial_mat[q.second.first][q.second.second]);

        currCol = q.second.second;
        currRow = q.second.first;  
        count++;

        cout<<"Choosen"<<endl;
        for(int i = 0; i < ROW; i++){
                for(int j = 0; j < COL; j++){
                    cout<<initial_mat[i][j]<<" ";

                }
                cout<<endl;
            }
        cout<<endl;

    }while(h_dist != 0);

}

int main()
{

    int initial_matrix[3][3];
    int goal_matrix[3][3];

    int rows = 3;
    int cols = 3;

    cout << "Enter initial matrix state\n";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Row" << i << "\tColumn" << j << " : ";

            cin >> initial_matrix[i][j];
        }
    }

    cout << "Printing the matrix\n";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << initial_matrix[i][j] << "\t";
        }

        cout << "\n";
    }

    cout << "Enter goal matrix state\n";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Row" << i << "\tColumn" << j << " : ";

            cin >> goal_matrix[i][j];
        }
    }

    aStarAlgorithm(initial_matrix, goal_matrix, ROW, COL);
    cout << "Printing the matrix\n";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << initial_matrix[i][j] << "\t";
        }

        cout << "\n";
    }

    return 0;
}
