#include <iostream>
#include <fstream>
#include <cmath>
#include <climits>
using namespace std;

void solve(int ***rgb, int H, int W, int C, int H_, int W_, int C_) {
    // We've provided you the driver.py and main.cpp for your convinience
    // Please go through them and understand the file handling and input/output format
    // Feel free to experiment on your own

    // can access the array using rgb[i][j][k] like a regular 3D array

    // Write your code here
    int **Enrgy,Ex,Ey,rx,bx,gx,ry,by,gy,i,j,shft,Rx,Ry,it;
    
    while(W>W_)
    {
    int *VerMin =new int [H];
    it=0;
     Enrgy =new int *[H];
    for(int i=0;i<H;i++)
    {
        Enrgy[i]= new int [W];
        for(int j=0;j<W;j++)
        {
            if(j==0)
            {  
               rx=(rgb[i][j+1][0]-rgb[i][W-1][0]);
               gx=(rgb[i][j+1][1]-rgb[i][W-1][1]);
               bx=(rgb[i][j+1][2]-rgb[i][W-1][2]);
            }
            if(j==W-1)
            {
               rx=(rgb[i][j-1][0]-rgb[i][0][0]);
               gx=(rgb[i][j-1][1]-rgb[i][0][1]);
               bx=(rgb[i][j-1][2]-rgb[i][0][2]);
            }
            if(i==0)
            {
               ry=(rgb[i+1][j][0]-rgb[H-1][j][0]);
               gy=(rgb[i+1][j][1]-rgb[H-1][j][1]);
               by=(rgb[i+1][j][2]-rgb[H-1][j][2]);
            }
            if(i==H-1)
            {
               ry=(rgb[i-1][j][0]-rgb[0][j][0]);
               gy=(rgb[i-1][j][1]-rgb[0][j][1]);
               by=(rgb[i-1][j][2]-rgb[0][j][2]);
            }
            if(j>0&&j<W-1)
            {
               rx=(rgb[i][j+1][0]-rgb[i][j-1][0]);
               gx=(rgb[i][j+1][1]-rgb[i][j-1][1]);
               bx=(rgb[i][j+1][2]-rgb[i][j-1][2]);
            }
            if(i>0&&i<H-1)
            {
               ry=(rgb[i+1][j][0]-rgb[i-1][j][0]);
               gy=(rgb[i+1][j][1]-rgb[i-1][j][1]);
               by=(rgb[i+1][j][2]-rgb[i-1][j][2]);
            }
            Rx=sqrt(rx*rx+gx*gx+bx*bx);
            Ry=sqrt(ry*ry+gy*gy+by*by);
            Enrgy[i][j]=sqrt(Rx*Rx+Ry*Ry);
        }
    }
    int MinVal,Cy;
    MinVal=INT_MAX;
    for(j=1;j<W-1;j++)
    {  if(MinVal>Enrgy[H-1][j])
    {
        MinVal=Enrgy[H-1][j];
        Cy=j;
    }
    }
    VerMin[it]=Cy;
    int CmpMin,col;
    for(i=H-2;i>=0;i--)
    {  MinVal=INT_MAX;
         col=VerMin[it];
        for(j=0;j<W;j++)
        {
            if(j==0)
            {
                Enrgy[i][j]+=min(Enrgy[i+1][j],Enrgy[i+1][j+1]);
            }
            if(j==W-1)
            {
                Enrgy[i][j]+=min(Enrgy[i+1][j],Enrgy[i+1][j-1]);
            }
            if(j>0&&j<W-1)
           { 
            CmpMin=min(Enrgy[i+1][j-1],Enrgy[i+1][j]);
            Enrgy[i][j]+=min(CmpMin,Enrgy[i+1][j+1]);
             
           if(col==j||(col-1)==j||(col+1)==j) 
           {
            if(MinVal>Enrgy[i][j])
            {
                MinVal=Enrgy[i][j];
                Cy=j;
            } 
            }
            }
        }
        it++;
        VerMin[it]=Cy;
        
    }
    for(shft=0;shft<H;shft++)
        {
           for(j=VerMin[shft]+1;j<W;j++)
           {
              rgb[H-1-shft][j-1]=rgb[H-1-shft][j];
           }
        }
    W--;
    }
    
    while(H>H_)
    { int *HrzMin =new int[W];
    it=0;
    Enrgy =new int *[H];
    for(int i=0;i<H;i++)
    {
        Enrgy[i]= new int [W];
        for(int j=0;j<W;j++)
        {
            if(j==0)
            {  
               ry=(rgb[i][j+1][0]-rgb[i][W-1][0]);
               gy=(rgb[i][j+1][1]-rgb[i][W-1][1]);
               by=(rgb[i][j+1][2]-rgb[i][W-1][2]);
            }
            if(j==W-1)
            {
               ry=(rgb[i][j-1][0]-rgb[i][0][0]);
               gy=(rgb[i][j-1][1]-rgb[i][0][1]);
               by=(rgb[i][j-1][2]-rgb[i][0][2]);
            }
            if(i==0)
            {
               rx=(rgb[i+1][j][0]-rgb[H-1][j][0]);
               gx=(rgb[i+1][j][1]-rgb[H-1][j][1]);
               bx=(rgb[i+1][j][2]-rgb[H-1][j][2]);
            }
            if(i==H-1)
            {
               rx=(rgb[i-1][j][0]-rgb[0][j][0]);
               gx=(rgb[i-1][j][1]-rgb[0][j][1]);
               bx=(rgb[i-1][j][2]-rgb[0][j][2]);
            }
            if(j>0&&j<W-1)
            {
               ry=(rgb[i][j+1][0]-rgb[i][j-1][0]);
               gy=(rgb[i][j+1][1]-rgb[i][j-1][1]);
               by=(rgb[i][j+1][2]-rgb[i][j-1][2]);
            }
            if(i>0&&i<H-1)
            {
               rx=(rgb[i+1][j][0]-rgb[i-1][j][0]);
               gx=(rgb[i+1][j][1]-rgb[i-1][j][1]);
               bx=(rgb[i+1][j][2]-rgb[i-1][j][2]);
            }
            Rx=sqrt(rx*rx+gx*gx+bx*bx);
            Ry=sqrt(ry*ry+gy*gy+by*by);
            Enrgy[i][j]=sqrt(Rx*Rx+Ry*Ry);
        }
    }
    int MinVal,Cx;
    MinVal=INT_MAX;
    for(i=H-1;i>=0;i--)
    {  if(MinVal>Enrgy[i][W-1])
    {
        MinVal=Enrgy[i][W-1];
        Cx=i;
    }
    }
    HrzMin[it]=Cx;
    int CmpMin,row;
    for(j=W-2;j>=0;j--)
    {  MinVal=INT_MAX;
        row=HrzMin[it];
        for(i=H-1;i>=0;i--)
        {
            if(i==0)
            {
                Enrgy[i][j]+=min(Enrgy[i][j+1],Enrgy[i+1][j+1]);
             
            }
            if(i==H-1)
            {
                Enrgy[i][j]+=min(Enrgy[i-1][j+1],Enrgy[i][j+1]);
              
            }
            if(i>0&&i<H-1)
            {
            CmpMin=min(Enrgy[i+1][j+1],Enrgy[i][j+1]);
            Enrgy[i][j]+=min(CmpMin,Enrgy[i-1][j+1]);
            if(row==i||(row+1)==i||(row-1)==i)
            {
            if(MinVal>Enrgy[i][j])
            {
                MinVal=Enrgy[i][j];
                Cx=i;
            }
            } 
            }
        }
        
      it++;
      HrzMin[it]=Cx;  
    }
      for(shft=0;shft<W;shft++)
        {  
          for(i=HrzMin[shft]+1;i<H;i++)
          {  rgb[i-1][W-1-shft]=rgb[i][W-1-shft];
          }
        }
    H--;
    }
}

int main() {
    string ip_dir = "./data/input/";
    string ip_file = "rgb_in.txt";
    ifstream fin(ip_dir + ip_file);

    int H, W, C;
    fin >> H >> W >> C;

    int ***rgb;
    rgb = new int **[H];
    for(int i = 0; i < H; ++i) {
        rgb[i] = new int *[W];
        for(int j = 0; j < W; ++j) {
            rgb[i][j] = new int[C];
            for(int k = 0; k < C; ++k)
                fin >> rgb[i][j][k];
        }
    }
    fin.close();

    int H_, W_, C_;
    cout << "Enter new value for H (must be less than " << H << "): ";
    cin >> H_;
    cout << "Enter new value for W (must be less than " << W << "): ";
    cin >> W_;
    cout << '\n';
    C_ = C;

    solve(rgb, H, W, C, H_, W_, C_);

    string op_dir = "./data/output/";
    string op_file = "rgb_out.txt";
    ofstream fout(op_dir + op_file);
    
    fout << H_ << " " << W_ << " " << C_ << endl;
    for(int i = 0; i < H_; ++i) {
        for(int j = 0; j < W_; ++j) {
            for(int k = 0; k < C_; ++k) {
                fout << rgb[i][j][k] << " ";
            }
        }
        fout << '\n';
    }
    fout.close();

    return 0;
}
