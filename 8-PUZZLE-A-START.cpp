#include <bits/stdc++.h>
using namespace std;
#define N 999999

int given_matrix[] = {1, 2, 3, 0, 5, 6, 4, 7, 8};
// int given_matrix[] = {1, 8, 2, 0, 4, 3, 7, 6, 5};
// int given_matrix[] = {1, 2, 3, 4, 8, 6, 7, 5, 0};
// int given_matrix[] = {1, 2, 3, 4, 5, 6, 7, 0,8};
int target_matrix[] = {1, 2, 3, 4, 5, 6, 7, 8, 0};
// int target_matrix[] = {1, 2,3, 8, 0, 4,7, 6, 5};

// int input_array[];

// int getInvCount(int arr[])
// {
//     int inv_count = 0;
//     for (int i = 0; i < 9 - 1; i++)
//         for (int j = i + 1; j < 9; j++)
//             // Value 0 is used for empty space
//             if (arr[j] && arr[i] && arr[i] > arr[j])
//                 inv_count++;
//     return inv_count;
// }

// // This function returns true if given 8 puzzle is solvable.
// bool isSolvable(int puzzle[3][3])
// {
//     // Count inversions in given 8 puzzle
//     int invCount = getInvCount((int *)puzzle);

//     // return true if inversion count is even.
//     return (invCount % 2 == 0);
// }

int find_zero_index(int matrix[])
{

    for (int i = 0; i < 9; i++)
    {
        if (matrix[i] == 0)
        {
            return i;
        }
    }
}

void print_matrix(int matrix[])
{
    for (int i = 0; i < 9; i++)
    {
        if (i % 3 == 0)
        {
            cout << endl;
        }
        cout << matrix[i] << " ";
    }
    cout << endl;
}

int Hamming_distance(int s[])
{
    int c = 0;
    for (int i = 0; i < 9; i++)
    {
        if (s[i] != 0 && s[i] != target_matrix[i])
        {
            c++;
        }
    }

    return c;
}

int eight_puzzle(int arr[], int pos, int given_matrix[], int n)
{
    int val = N;
    int given_matrix_copy[9];
    for (int i = 0; i < 9; i++)
    {
        given_matrix_copy[i] = given_matrix[i];
    }

    for (int i = 0; i < n; i++)
    {
        int duplicate[9];
        for (int i = 0; i < 9; i++)
        {
            duplicate[i] = given_matrix[i];
        }
        // using namespce int arr
        int temp = duplicate[pos];
        duplicate[pos] = duplicate[arr[i]];
        duplicate[arr[i]] = temp;

        int temp_val = Hamming_distance(duplicate);

        if (temp_val < val)
        {
            val = temp_val;
            for (int i = 0; i < 9; i++)
            {
                given_matrix_copy[i] = duplicate[i];
            }
        }
    }

    for (int i = 0; i < 9; i++)
    {
        given_matrix[i] = given_matrix_copy[i];
    }

    return val;
}

int main()
{
    // int matrix[3][3] = {{1, 8, 2},
    //                     {0, 4, 3}, // Value 0 is used for empty space
    //                     {7, 6, 5}};

    // if (isSolvable(matrix))
    // {
    //     cout << "solvable" << endl;
    // }
    // else
    // {
    //     cout << "not-solvable" << endl;
    //     return 0;
    // }

    int solveable = Hamming_distance(given_matrix);

    int level = 1;

    int hvalue = 0;
    cout << "matrix number : " << level << endl;
    print_matrix(given_matrix);

    while (solveable > 0)
    {
        int pos = find_zero_index(given_matrix);
        level++;

        if (pos == 0)
        {
            int neighbours[] = {1, 3};
            solveable = eight_puzzle(neighbours, pos, given_matrix, 2);
        }
        else if (pos == 1)
        {
            int neighbours[] = {0, 2, 4};
            solveable = eight_puzzle(neighbours, pos, given_matrix, 3);
        }
        else if (pos == 2)
        {
            int neighbours[] = {1, 5};
            solveable = eight_puzzle(neighbours, pos, given_matrix, 2);
        }
        else if (pos == 3)
        {
            int neighbours[] = {0, 4, 6};
            solveable = eight_puzzle(neighbours, pos, given_matrix, 3);
        }
        else if (pos == 4)
        {
            int neighbours[] = {3, 5, 7};
            solveable = eight_puzzle(neighbours, pos, given_matrix, 3);
        }
        else if (pos == 5)
        {
            int neighbours[] = {2, 4, 8};
            solveable = eight_puzzle(neighbours, pos, given_matrix, 3);
        }
        else if (pos == 6)
        {
            int neighbours[] = {3, 7};
            solveable = eight_puzzle(neighbours, pos, given_matrix, 2);
        }
        else if (pos == 7)
        {
            int neighbours[] = {4, 6, 8};
            solveable = eight_puzzle(neighbours, pos, given_matrix, 3);
        }
        else if (pos == 8)
        {
            int neighbours[] = {5, 7};
            solveable = eight_puzzle(neighbours, pos, given_matrix, 2);
        }

        cout << "matrix number : " << level << endl;
        print_matrix(given_matrix);
    }

    // ...........................................................
    // int haming_distance(given_matrix[9], size);
    // int cost = 0;
    // for (int i = 0; i < n;i++){
    //     if(arr[i] != given_matrix[i]){
    //     cost++;
    //     }
    // }

    // int hurestic_value = INT_MAX;
    // while (hurstic_value >0 )
    // {
    //     /* code */
    // }

    return 0;
}