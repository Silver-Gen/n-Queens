#include <iostream>
void statements(unsigned int *n)
{
    if((*n)==0)
        return;
    switch ((*n))
    {
    case 1:
        std::cout<<"Enter the value of size of Chess board:";
        (*n)++;
        break;
    case 2:
        system("clear");
        std::cout<<"Following are the solutions\n\n";
        (*n)++;
        break;
    case 3:
        std::cout<<" solutions were found for a chess board of ";
        (*n)++;
        break;
    default:
        std::cout<<"Unknown error occured in statements";
        break;
    }
}
class nqueens
{
    private:
        int size;
        bool **arr;//This will store True/false for Queen placement
        int number_of_sols;
        void box(bool *arrk)
        {
            int* j=new int(0);
            while((*j)<size)
            {
                std::cout<<"|   ";
                (*j)++;
            }
            std::cout<<"|\n";
            (*j)=0;
            while((*j)<size)
            {
                std::cout<<"| ";
                if(arrk[(*j)])
                    std::cout<<"Q";
                else
                    std::cout<<" ";
                std::cout<<" ";
                (*j)++;
            }
            std::cout<<"|\n";
            (*j)=0;
            while((*j)<size)
            {
                std::cout<<"|___";
                (*j)++;
            }
            std::cout<<"|\n";
            delete j;
        }
        void printsols()
        {
            for(int i=0;i<(4*size+1);i++)
                std::cout<<"-";
            std::cout<<"\n";
            std::cout<<"Arrangement "<<number_of_sols<<"\n";
            for(int i=0;i<(4*size+1);i++)
                std::cout<<"-";
            std::cout<<"\n";
            std::cout<<"\n ";
            for(int i=0;i<(4*size-1);i++)
                std::cout<<"_";
            std::cout<<"\n";
            for(int i=0;i<size;i++)
                box(arr[i]);
            std::cout<<"\n\n";
        }
        bool issafe(int *row,int *col)//This will check if any other queens threaten the queen placed at position i,j
        {
            for(int i=0;i<(*col);i++)//Checking horizontally along 
            {
                if(arr[(*row)][i])
                    return false;
            }
            for(int i=(*row),j=(*col);i>=0 && j>=0;i--,j--)//Checking diagonally in '\' direction
            {
                if(arr[i][j])
                    return false;
            }
            for(int i=(*row),j=(*col);i<size && j>=0;i++,j--)//Checking diagonally on '/' direction
            {
                if(arr[i][j])
                    return false;
            }
            return true;
        }
        void placement(int *col)
        {
            if((*col)>=size)
            {
                number_of_sols++;
                printsols();
                return;
            }
            for(int row=0;row<size;row++)
            {
                if(issafe((&row),col))
                {
                    arr[row][(*col)]=true;
                    (*col)++;
                    placement(col);
                    (*col)--;
                    arr[row][(*col)]=false;//Backtracking
                }
            }
        }
    public:
        nqueens(int n)
        {
            number_of_sols=0;
            size=n;
            arr=new bool*[size];
            for(int i=0;i<n;i++)
                arr[i]=new bool[size];
            for(int i=0;i<size;i++)
            {
                for(int j=0;j<size;j++)
                    arr[i][j]=false;
            }
        }
        void processor(unsigned int *s)
        {
            statements(s);
            int n=0;
            placement(&n);
            if(number_of_sols==0)
            {
                system("clear");
                std::cout<<"No solutions were found for chess board of dimensions "<<size<<"x"<<size;
            }
            else
            {
                std::cout<<number_of_sols<<" ";
                statements(s);
                std::cout<<"- "<<size<<"x"<<size;
            }
        }
        ~nqueens()
        {
            for(int i=0;i<size;i++)
                delete[] arr[i];
            delete[] arr;
        }
};
int main()
{
    unsigned int statesvar=1;//Variable to switch on/off the statements like 'Enter the variable etc';
    statements(&statesvar);
    unsigned int n;
    std::cin>>n;
    nqueens obj(n);
    obj.processor(&statesvar);
}
