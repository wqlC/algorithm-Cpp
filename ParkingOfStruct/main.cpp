#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct Student {
    char id[15];
    int score;
    int location_number;
    int local_rank;
    int global_rank;
}stu[5000];

bool cmp(Student a, Student b){
    if(a.score != b.score) return a.score>b.score;
    else
        return strcmp(a.id, b.id)<0;
}

int main()
{
    int num = 0;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int m;
        cin >>m;
        for(int j=0; j<m; j++){
            scanf("%s %d", stu[num].id, &stu[num].score);
            stu[num].location_number = i+1;
            num++;
        }
        sort(stu+num-m, stu+num, cmp);
        stu[num-m].local_rank = 1;
        for(int j=num-m+1; j<num; j++){
            if(stu[j].score == stu[j-1].score){
                stu[j].local_rank = stu[j-1].local_rank;
            }else{
                stu[j].local_rank = j+1-(num-m);
            }
        }
    }
    printf("%d\n", num);
    sort(stu, stu+num, cmp);
    int r = 1;
    for(int i=0; i<num; i++){
        if(i>0 && stu[i].score!=stu[i-1].score){
            r = i+1;
        }
        stu[i].global_rank = r;
        printf("%s %d %d %d\n", stu[i].id, stu[i].global_rank, stu[i].location_number, stu[i].local_rank);
    }
    return 0;
}

/*
2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85
*/
