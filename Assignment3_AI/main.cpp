
#include "bits/stdc++.h"
using namespace std;
// v the highest value i can take from this state or the highest value from the Q,s

// q all posible values i can have if i take a specific action
double Q[4][4][4],V[4][4],R[4][4];
int Policy[4][4];

void initialize(double r)
{
    //This function initializes the Value Array V and the Reward Array R to the initial rewards of the system
    int i,j;
    for(i=1;i<=3;i++)
    {
        for(j=1;j<=3;j++)
        {
            V[i][j]=0.0;
            R[i][j]=-1.0;
        }
    }
    R[3][3]=10.0;
    R[3][1]=r;
    V[3][3]=10.0;

}

void printPolicy()
{
    //This fuinction prints the Policy with the arrows signifying the direction
    int i,j;
    for(i=3;i>=1;i--)
    {
        for(j=1;j<=3;j++)
        {
            if(i==3 and j==3)
            {
                cout<<"+10";
                continue;
            }
            switch(Policy[i][j])
            {
                case 0: printf("%c",24);

                        break;
                case 1: printf("%c",25);
                        break;
                case 2: printf("%c",27);
                        break;
                case 3: printf("%c",26);
                        break;
            }
            cout<<"     ";
         }
         cout<<"\n";
         cout<<"\n";
    }
}


void valueIteration(double discount)
{
    //This function computes the values for the Value Array  by doing Value Iteration
    int i,j,l,a,maxQindex;
    double maxQ;

    for(l=0;l<25;l++)
    {
        //Outer loop for the number of iterations
        for(i=3;i>=1;i--)
        {
            for(j=3;j>=1;j--)
            {
                if(i==3 and j==3)
                    continue;
                maxQ=-1000000.0;
                for(a=0;a<=3;a++)
                {
                    //We need to check if the current action is legal or not
                    switch(a)
                    {
                        case 0:
                                //going up
                                Q[i][j][a]=R[i][j];
                                if(i+1<=3 and i+1>=1)
                                {
                                    Q[i][j][a]+=discount*0.8*V[i+1][j];
                                }
                                else
                                {
                                    Q[i][j][a]+=discount*0.8*V[i][j];
                                }

                                //check for left and right conditions
                                if(j-1 >=1 and j-1<=3)
                                {
                                    Q[i][j][a]+=discount*0.1*V[i][j-1];
                                }
                                else
                                {
                                    Q[i][j][a]+=discount*0.1*V[i][j];
                                }

                                if(j+1 <=3 and j+1>=1)
                                {
                                    Q[i][j][a]+=discount*0.1*V[i][j+1];
                                }
                                else
                                {
                                    Q[i][j][a]+=discount*0.1*V[i][j];
                                }

                                if(Q[i][j][a]>maxQ)
                                {
                                    maxQ=Q[i][j][a];
                                    maxQindex=a;
                                }
                                break;

                       case 1:
                                //going doown
                                Q[i][j][a]=R[i][j];
                                if(i-1<=3 and i-1>=1)
                                {
                                    Q[i][j][a]+=discount*0.8*V[i-1][j];
                                }
                                else
                                {
                                    Q[i][j][a]+=discount*0.8*V[i][j];
                                }

                                //check for left and right conditions
                                if(j-1 >=1 and j-1<=3)
                                {
                                    Q[i][j][a]+=discount*0.1*V[i][j-1];
                                }
                                else
                                {
                                    Q[i][j][a]+=discount*0.1*V[i][j];
                                }

                                if(j+1 <=3 and j+1>=1)
                                {
                                    Q[i][j][a]+=discount*0.1*V[i][j+1];
                                }
                                else
                                {
                                    Q[i][j][a]+=discount*0.1*V[i][j];
                                }

                                if(Q[i][j][a]>maxQ)
                                {
                                    maxQ=Q[i][j][a];
                                    maxQindex=a;
                                }
                                break;

                      case 2:
                                //going left
                                Q[i][j][a]=R[i][j];
                                if(j-1>=1 and j-1<=3)
                                {
                                    Q[i][j][a]+=discount*0.8*V[i][j-1];
                                }
                                else
                                {
                                    Q[i][j][a]+=discount*0.8*V[i][j];
                                }

                                //check for up and down conditions

                                if(i+1>=1 and i+1<=3)
                                {
                                    Q[i][j][a]+=discount*0.1*V[i+1][j];
                                }
                                else
                                {
                                    Q[i][j][a]+=discount*0.1*V[i][j];
                                }

                                if(i-1>=1 and i-1<=3)
                                {
                                    Q[i][j][a]+=discount*0.1*V[i-1][j];
                                }
                                else
                                {
                                    Q[i][j][a]+=discount*0.1*V[i][j];
                                }

                                if(Q[i][j][a]>maxQ)
                                {
                                    maxQ=Q[i][j][a];
                                    maxQindex=a;
                                }
                                break;

                        case 3:
                                //going right
                                Q[i][j][a]=R[i][j];
                                if(j+1>=1 and j+1<=3)
                                {
                                    Q[i][j][a]=Q[i][j][a]+discount*0.8*V[i][j+1];
                                }
                                else
                                {
                                    Q[i][j][a]+=discount*0.8*V[i][j];
                                }

                                //check for up and down conditions

                                if(i+1>=1 and i+1<=3)
                                {
                                    Q[i][j][a]+=discount*0.1*V[i+1][j];
                                }
                                else
                                {
                                    Q[i][j][a]+=discount*0.1*V[i][j];
                                }

                                if(i-1>=1 and i-1<=3)
                                {
                                    Q[i][j][a]+=discount*0.1*V[i-1][j];
                                }
                                else
                                {
                                    Q[i][j][a]+=discount*0.1*V[i][j];
                                }

                                if(Q[i][j][a]>maxQ)
                                {
                                    maxQ=Q[i][j][a];
                                    maxQindex=a;
                                }
                                break;


                    }
                }
                    //Now done with checking all the actions . Now time for updating the max Q to V and the Policy
                    V[i][j]=maxQ;
                    Policy[i][j]=maxQindex;

            }
        }


    }
}

int main()
{

    double r[4];
    int i,j;
    r[0]=100.0;
    r[1]=3.0;
    r[2]=0;
    r[3]=-3.0;
    double discount=0.99;
    for(i=0;i<4;i++)
    {
        cout<<"poilicy for r="<<r[i]<<"  is "<<"\n";
        initialize(r[i]);
        valueIteration(discount);
        printPolicy();
        cout<<"\n\n";
    }
    return 0;
}

