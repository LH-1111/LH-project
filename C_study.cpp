#include<iostream>
using namespace std;



int addnum(int a , int b );



int main(){
    // int a;
    // cin >> a;
    // switch (a)
    // {
    // case 1: 
    // case 2:
    //     cout << "1111111" << endl;
    //     break;
    
    // default:
    //     cout << "22222222" << endl;
    //     break;
    // }


    // while(a>1){
    //     cout << "1111111333" << endl;
    //     a--;
    // }
    //猜数字
    // srand((unsigned int)time(NULL));
    // int num = rand()%100 + 1;
    // cout << "num : " << num <<endl;   
    // while (1)
    // {
    //     int mynum ;
    //     cin >>mynum ;
    //     if(mynum == num){
    //         cout << "duile" <<endl; 
    //         break;
    //     } 
    //     if(mynum > num) cout << "dale" <<endl;
        
    //     if(mynum < num) cout << "xiaole" <<endl;
    // }
    //水仙花数
    // int x = 100 ;
    // int mynum = 0 ;
    // int G, S, B, tem;
    // do{
    //     G = x % 10;
    //     B = x / 100;
    //     tem = x %100;
    //     S = tem / 10 ;
    //     mynum = (S*S*S) + (B*B*B) + (G*G*G) ;
    //     if(x == mynum) {
    //         // cout << "水仙花数个" << G <<endl;
    //         // cout << "水仙花数十" << S <<endl;
    //         // cout << "水仙花数百" << B <<endl;
    //         cout << "水仙花数: " << mynum <<endl;
    //     }
    //     x++;
    // }while(x < 1000);
    // 敲桌子
    // for (int i = 1; i < 100; i++)
    // {
    //     int x ,y, z, h ;
    //     y = i%7;
    //     x = i%10;
    //     h = i/10;
    //     if (y == 0 || x == 7 || h == 7 )
    //     {
    //         cout << "num : " << i <<endl;
    //     }
        
    // }
    //99乘法表
    // for (int i = 1; i < 10 ; i++)
    // {
    //     for (int j = 1; j <= i; j++ )
    //     {
    //         cout << j <<"*"<< i << "="<< j*i << "  " ;
    //     }
    //     cout  <<endl;
    //     /* code */
    // }

    // int b[3] = {1,2,3};
    // cout <<sizeof(b) <<endl;
    // cout <<sizeof(b[0]) <<endl;
    // cout <<sizeof(b) / sizeof(b[0]) <<endl;
    // cout << (long long) b <<endl;
    // cout << (long long)&b[0] <<endl;


    // int a[5] = {100,900,500,299,488} ;
    //冒泡排序
    // for (int i = 0; i < 5; i++)
    // {
    //     for (int j = 0; j < 5-i-1; j++)
    //     {
    //         int tmp = a[j];
    //         if (a[j] > a[j+1])
    //         {
    //             a[j] = a[j+1];
    //             a[j+1] = tmp; 
    //         }
        
    //     }   
    // }
    // for (int i = 0; i < 5; i++)
    // {
    //     cout<<a[i]<<endl;  
    // }
    //元素逆转
    // int start = 0 ;
    // int end = sizeof(a) / sizeof(a[0]) - 1;
    // while (start < end)
    // {
    //     int temp = a[start];
    //     a[start] = a[end];
    //     a[end] = temp;
    //     start ++ ;
    //     end --;
    // }
    // for (int i = 0; i < 6; i++)
    // {
    //     cout<<a[i]<<endl;  
    // }

    //print 二维数组
    // int arr[3][2];
    // arr[0][0] = 1;
    // arr[0][1] = 2;
    // arr[1][0] = 3;
    // arr[1][1] = 5;
    // arr[2][0] = 9;
    // arr[2][1] = 8;
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 2; j++)
    //     {
    //          cout<< arr[i][j] <<endl;
    //     }
        
    // }

    // int arr2[2][3] = {
    //     {1,2,3},
    //     {4,6}
    // };
    // for (int i = 0; i < 2; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //          cout<< arr2[i][j] <<endl;
    //     }
        
    // }



    // int arr4[][3] = {1,2,3,2};
    // for (int i = 0; i < 2; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //          cout<< arr4[i][j] <<endl;
    //     }
        
    // }


    //      语文   数学   英语
    //  1    90    83    97
    //  2    94    53    100
    //  3    95    73    109
    //计数总分
    // int scores[3][3]{{90,83,97},{94,53,100},{95,73,109}};
    
    // for (int i = 0; i < 3; i++)
    // {
    //     int max = 0;
    //     for (int j = 0; j < 3; j++)
    //     {
    //         max = scores[i][j]+ max;
    //     }
    //     cout << "zongfeng: " << i+1 <<" :  " << max<<endl;
    //     /* code */
    // }
    int num = addnum(20,20);
    cout << num <<endl;
    return 1;
}



int addnum(int a , int b ){
    return a + b;
}
