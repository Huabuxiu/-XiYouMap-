#include "fun.h"

void menu()
{
    printf("\t\t\t\t\t\t西   安   邮   电   大   学\n");
    printf("\t\t\t                                  欢迎进入校园导游系统                                  \n\n\n");
    printf("\t\t\t    『1』      --------------------------      校园平面图\n\n");
    printf("\t\t\t    『2』      --------------------------    	校园地点信息查询\n\n");
    printf("\t\t\t    『3』      --------------------------       最短路径\n\n");
    printf("\t\t\t    『4』      --------------------------       所有路径\n\n");
    printf("\t\t\t    『5』      --------------------------     最佳布网方案\n\n");
    printf("\t\t\t    『0』      --------------------------         退出\n");

}

void switch1()
{
    int choice,k;
    AdjMatrix G;
	Create_Eex_AdjMatrix(&G);
    printf("\t\t\t\t\t请输入您需要的功能：");
    scanf("%d", &choice);

        switch(choice){
            case 1: map1();break; //查看校园平面图
            case 2: plcae(&G); break; //地点信息查询
            case 3: Dij_Short_Path(&G); break; //最短路径
            case 4: All_Path(&G);break;       //所有路径
            case 5: Prim_MiniSpanTree(&G); break; //最短连通图
            case 0: break;   //退出
            default:
                    printf("\t\t\t\t\t\t抱歉，您的输入有误！！！\n");
        }
      if(choice!=0){
        getchar();
        printf("t\t\t\t\t按enter键返回......\n");
        getchar();
        menu();
        switch1();
      }
}

//根据地点名确定地点序号
int Locate(AdjMatrix *G, char name[])
{
    int i;
    for(i = 1; i <= G->vexnum; i++){
        //图中含有该景点，找到其序号
        if(!strcmp(G->vex[i].name, name))
            return i;
    }
    return -1;
}

//采用邻接矩阵创建无向网
void Create_AdjMatrix(AdjMatrix *G)
{
    int i, j, k, weight;
    char name1[50], name2[50];

    printf("\t\t\t创建新地图...\n\n\n");
    printf("\t\t\t请输入学校中的景点数目和路径数目：");
    scanf("%d %d", &G->vexnum, &G->arcnum);

    //初始化边信息
    for(i = 1; i <= G->vexnum; i++){
        for(j = 1; j <= G->vexnum; j++){
            G->arcs[i][j] = INFINITY;
        }
    }

    //初始化顶点集合
    for(i = 1; i <= G->vexnum; i++){
        printf("\t\t\t请分别输入第%d个景点序号和名字：", i);
        scanf("%d %s", &G->vex[i].NO, G->vex[i].name);
    }
    printf("\n\n");
    //建立边关系
    for(k = 1; k <= G->arcnum; k++){
        printf("\t\t\t请输入第NO.%d个相关联的两个景点名字和路径长度：", k);
        scanf("%s %s %d", name1, name2, &weight);
        i = Locate(G, name1);
        j = Locate(G, name2);
        G->arcs[i][j] = weight;
        G->arcs[j][i] = weight;
    }
    printf("\n\n\n\t\t\t\t\t创建新地图成功！\n\n");
    Store(G);
}

//存储邻接矩阵地图
void Store(AdjMatrix *G)
{
    FILE *fp;

    if((fp = fopen("message", "wt")) == NULL){
        printf("\t\t\t\t\t抱歉，无法正常存储!\n");
        return ;

    }
    printf("   存储信息中...\n");
    fwrite(G, sizeof(AdjMatrix), 1, fp);
    fclose(fp);
    printf("\t\t\t\t\t存储成功!\n\n\n");
}

//读取景点及路线信息
AdjMatrix Read()
{
    FILE *fp;
    AdjMatrix G;
    if((fp = fopen("message", "rt")) == NULL){
        printf("\t\t\t\t\t抱歉，无法正常读取!\n");
        return ;
    }
    printf(" 读取信息中...\n");
    fread(&G, sizeof(AdjMatrix), 1, fp);
    fclose(fp);
    printf("读取成功!\n");

    return G;
}
//输出无向网矩阵
void Print_AdjMatrix(AdjMatrix *G)
{

    int i, j;
    for(i = 1; i <= G->vexnum; i++)
        printf("%12s", G->vex[i].name);
    printf("\n\n");
    for(i = 1; i <= G->vexnum; i++){
        for(j = 1; j <= G->vexnum; j++){
            if(G->arcs[i][j] == INFINITY)
                printf("           #");
           else
                printf("%12d", G->arcs[i][j]);
        }
        printf("\n");
    }
}

//使用信息生成矩阵
void Create_Eex_AdjMatrix(AdjMatrix *G)
{

	char vexnum[][50]=
	{
		{
		},
		{"北门"},{"水煮鸽子"},{"基础教学楼"},{"实验楼"},{"图书馆"},{"美食广场"},
		{"西区宿舍"},{"旭日苑"},{"操场"},{"东门"},{"天桥"},{"西门"},{"东区教学楼"},
		{"东升苑"},{"东区宿舍"}
	};
	char edges[][2][50]={{},
		{{"北门"},{"基础教学楼"}},
		{{"北门"},{"水煮鸽子"}},
		{{"北门"},{"西门"}},
		{{"基础教学楼"},{"水煮鸽子"}},
		{{"实验楼"},{"基础教学楼"}},
		{{"实验楼"},{"水煮鸽子"}},
		{{"图书馆"},{"水煮鸽子"}},
		{{"实验楼"},{"图书馆"}},
		{{"实验楼"},{"美食广场"}},
		{{"图书馆"},{"美食广场"}},
		{{"图书馆"},{"东门"}},
		{{"图书馆"},{"操场"}},
		{{"东门"},{"操场"}},
		{{"西区宿舍"},{"美食广场"}},
		{{"图书馆"},{"旭日苑"}},
		{{"操场"},{"旭日苑"}},
		{{"西区宿舍"},{"旭日苑"}},
		{{"西门"},{"天桥"}},
		{{"东升苑"},{"天桥"}},
		{{"东区宿舍"},{"天桥"}},
		{{"东区宿舍"},{"东升苑"}},
		{{"东区教学楼"},{"东升苑"}},
		{{"东区教学楼"},{"东区宿舍"}},
		{{"西门"},{"东区教学楼"}},
		{{"东门"},{"天桥"}}
	};
	int weights[] = {0,210,129,425,109,272,228,290,145,372,364,372,201,255,144,334,
	133,132,359,153,451,167,317,140,24,106};
	int vlen = LENGTH(vexnum);
    int elen = LENGTH(edges);

    int i, j, k;
    char name1[50], name2[50];

	G->vexnum = vlen;
	G->arcnum = elen;

    for(i = 1; i <= G->vexnum; i++){
        for(j = 1; j <= G->vexnum; j++){
            G->arcs[i][j] = INFINITY;
        }
    }

    //初始化顶点集合
    for(i = 1; i <= G->vexnum; i++){
		G->vex[i].NO = i;
		strcpy(G->vex[i].name,vexnum[i]);
		//G->vex[i].name = vexnum[i];
    }
    printf("\n\n");
    //建立边关系
    for(k = 1; k <= G->arcnum; k++){
		strcpy(name1,edges[k][0]);
		strcpy(name2,edges[k][1]);
        i = Locate(G, name1);
        j = Locate(G, name2);
        G->arcs[i][j] = weights[k];
        G->arcs[j][i] = weights[k];
    }
    printf("\n\n\n\t\t\t\t\t创建地图成功！\n\n");
}

//查询地点信息
void plcae(AdjMatrix *G)
{
    char place[500], name[50], choice = 'y';
	char fopened[50];
    int i;
    FILE *fp;
    printf("\t\t\t\t\t   地点信息查询...\n\n\n\n\n");
    for(i = 1; i <= G->vexnum; i++)
        printf("%s  ", G->vex[i].name);
    printf("\n");
    while(choice == 'y' || choice == 'Y'){
        printf("\t\t\t\t\t请输入需要了解的景点名：");
        scanf("%s", name);
        strcpy(fopened,name);
		strcat(fopened,".txt");
        if((fp = fopen(fopened, "rt")) == NULL){
            printf("\t\t\t\t\t抱歉，文件未正常打开！\n");
            return;
        }
        while((fgets(place, 500, fp)) != NULL){
            printf("%s", place);
        }
        fclose(fp);
        getchar();
        printf("\n\n\t\t\t\t\t是否要继续(y || n)：");
        scanf("%c", &choice);
    }
}

//查询任意两景点间的所有路径
int visited[Max_num+1];
int pre[Max_num+1];  //存放一条路中的各顶点在数组中的下标
void Path(AdjMatrix *G, int start, int end, int length, int dist)
{
    int i;

    if(pre[length] == end && length < G->vexnum){		//找到一条通路
        printf("%s ", G->vex[pre[1]].name);
        for(i = 2; i <= length; i++){				//打印路径
            printf("——> %s", G->vex[pre[i]].name);
            if(G->arcs[pre[i-1]][pre[i]] != INFINITY){		//计算当前结点和路径中前一个结点的距离
                dist += G->arcs[pre[i-1]][pre[i]];
            }
        }

        printf("距离为: %d\n", dist);
        dist = 0;
    }else{  	// 没有输出完则进入
        i = 1;
        while(i <= G->vexnum){
            if(!visited[i] && G->arcs[pre[length]][i] != INFINITY){		//邻接且没有访问
                visited[i] = 1;									//前往访问
                pre[length+1] = i;
                Path(G, i, end, length+1, dist);
                visited[i] = 0;		//退回就在路径中删除访问
            }
            i++;
        }
    }
}

//查询任意两景点间的所有路径
void All_Path(AdjMatrix *G)
{
    int i, start, end;
    char name1[50], name2[50];
    int dist = 0;

    printf("\t\t\t\t\t请输入起点：");
    scanf("%s", name1);
    start = Locate(G, name1);
    while(start == -1)
	{
		printf("\t\t\t\t无效输入,请重新输入:");
		scanf("%s", name1);
		start = Locate(G,name1);
	}
	printf("\t\t\t\t\t请输入终点：");
    scanf("%s", name2);
    end = Locate(G, name2);
    while(end == -1)
	{
		printf("\t\t\t\t无效输入,请重新输入:");
		scanf("%s", name2);
		end = Locate(G,name2);
	}
    for(i = 1; i <= Max_num; i++)
        visited[i] = 0;
    visited[start] = 1;  // 访问过则标记为1
    pre[1] = start;
    printf("%s---->%s的所有路径为：\n", G->vex[start].name, G->vex[end].name);
    Path(G, start, end, 1, dist);
}



//查询任意两景点间的最短路径
void Dij_Short_Path(AdjMatrix *G)
{
    char name[50], choice = 'y';	//
    int start, end;
    int dist[Max_num+1];
    printf("\t\t\t\t\t  最短路径...\n\n\n\n");
    while(choice == 'y' || choice == 'Y'){
        int path[Max_num+1][Max_num+1] = {0};
        printf("\n\t\t\t\t\t请输入起点：");
        scanf("%s", name);
        start = Locate(G, name);
        while(start == -1)
		{
			printf("\t\t\t\t无效输入,请重新输入:");
			scanf("%s", name);
			start = Locate(G,name);
		}
        printf("\t\t\t\t\t请输入终点：");
        scanf("%s", name);
        end = Locate(G, name);
        while(end == -1)
		{
			printf("\t\t\t\t无效输入,请重新输入:");
			scanf("%s", name);
			end = Locate(G,name);
		}
        Dijkstra(G, start, end, dist, path);
        printf("\t\t\t\t\t是否继续查询(y || n)：");
        getchar();
        choice = getchar();
    }
}

//采用Dijkstra算法求单元点的最短路径
void Dijkstra(AdjMatrix *G, int start, int end, int dist[], int path[][Max_num+1])
{
    int mindist, i, j, k, t = 1;

    //初始化
    for(i = 1; i <= G->vexnum; i++){
        dist[i] = G->arcs[start][i];		//读入开始行的邻接信息
        if(G->arcs[start][i] != INFINITY)
            path[i][1] = start;
    }
    path[start][0] = 1;

    //寻求最短路径
    for(i = 2; i <= G->vexnum; i++){
        mindist = INFINITY;
        for(j = 1; j <= G->vexnum; j++){
            if(!path[j][0] && dist[j] < mindist){
                mindist = dist[j];
                k = j;
            }
        }
        if(mindist == INFINITY)  break;
        path[k][0] = 1;

        //修改加入后的最短路径
        for(j = 1; j <= G->vexnum; j++){
            if(!path[j][0] && G->arcs[k][j] < INFINITY && G->arcs[k][j] + dist[k] < dist[j]){
                dist[j] = dist[k] + G->arcs[k][j];

               //记录最短路径
                t = 1;
                while(path[k][t]){
                    path[j][t] = path[k][t];
                    t++;
                }
                path[j][t] = k;
                path[j][t+1] = 0;
            }
        }
    }
    if(dist[end] == INFINITY){
        printf("\n\n\t%s----->%s  不存在通路!!!\n", G->vex[start].name, G->vex[end].name);
        return;
    }
    //输出最短路径
    printf("\n\n\t%s----->%s的最短路线：%s ", G->vex[start].name, G->vex[end].name, G->vex[start].name);
    for(j = 2; path[end][j]; j++)
        printf("——>%s ", G->vex[path[end][j]].name);
    printf("——>%s", G->vex[end].name);
    printf("\n\t距离为：%d\n", dist[end]);

}


//查询从某个景点出发的最短连通图
void Prim_MiniSpanTree(AdjMatrix *G)
{
    char name[50], choice = 'y';
    int start;
    printf("\t\t\t\t\t  最佳布网方案 \n\n\n\n");
    while(choice == 'y' || choice == 'Y'){
        printf("\t\t\t\t\t请输入起点：");
        scanf("%s", name);
        start = Locate(G, name);
        Prim(G, start);
        printf("\t\t\t\t\t是否继续查询(y || n): ");
        getchar();
        choice = getchar();
    }
}

//采用prim算法求最短连通图
void Prim(AdjMatrix *G, int start)
{
    struct{
        int adjvex;
        int lowcost;
        int pass;
    }closedge[Max_num+1];
    int i, e, k, m, min;

    //初始化
    closedge[start].lowcost = 0;
    for(i = 1; i <= G->vexnum; i++){
        if(i != start){
        closedge[i].adjvex = start;
        closedge[i].lowcost = G->arcs[start][i];
        }
    }

    //找最小值的边
    for(e = 1; e <= G->vexnum-1; e++){

        min = INFINITY;
        for(k = 1; k <= G->vexnum; k++){
            if(closedge[k].lowcost != 0 && closedge[k].lowcost < min){
                m = k;
                min = closedge[k].lowcost;
            }
        }
        printf("\t%s----->%s: 距离为%d\n", G->vex[closedge[m].adjvex].name, G->vex[m].name, closedge[m].lowcost);
        closedge[m].lowcost = 0;

        //加入后，更新closedge数组
        for(i = 1; i <= G->vexnum; i++){
            if(i != m && G->arcs[m][i] < closedge[i].lowcost){
                closedge[i].lowcost = G->arcs[m][i];
                closedge[i].adjvex = m;
            }
        }
    }

}

void map1()
{
printf("\t\t\t ---------------------------【北门】--------------------     ----------------------------------\n");
printf("\t\t\t|                             |  |                     |    |                                  |\n");
printf("\t\t\t|           ------------------   |                     |    |                                  |\n");
printf("\t\t\t|          |    --------------   |                     |    |                                  |\n");
printf("\t\t\t|       【基  础】           【水煮】                  |    |     --------                     |\n");
printf("\t\t\t|       【教学楼】           【鸽子】                  |    【西门】     【东  区】            |\n");
printf("\t\t\t|         |    |              |  |                     |    |     -------【教学楼】            |\n");
printf("\t\t\t|         |    |              |  |                     |    |             |      |             |\n");
printf("\t\t\t|         |    |              |  |                     |    |             |      |             |\n");
printf("\t\t\t|         |    |              |  |                     |    |             |      |             |\n");
printf("\t\t\t|         |    |              |  |                     |    |             |      |             |\n");
printf("\t\t\t|         |    |              |  |                     |    |             |      |             |\n");
printf("\t\t\t|         |    |              |  |                     |    |             |      |             |\n");
printf("\t\t\t|         |    |--------------   |                     | 子 |             |      ---【东区】   |\n");
printf("\t\t\t|       【实验楼】               |                     |    |             |      ---【宿舍】   |\n");
printf("\t\t\t|         |-------------------   |                     |    |             |      |             |\n");
printf("\t\t\t|                             |  |                     |    |         -----      |             |\n");
printf("\t\t\t|                             |  |                     |    | 【东升苑】         |             |\n");
printf("\t\t\t|                             |  |                     |    |         -----      |             |\n");
printf("\t\t\t|                             |  |                     | 午 |             |      |             |\n");
printf("\t\t\t|          -------------------    ---------------------|    |-------------|      |             |\n");
printf("\t\t\t|         |                 【图书馆】             【东门】【天桥】              |             |\n");
printf("\t\t\t|         |    --------------     ---------------------|    |---------------------             |\n");
printf("\t\t\t|         |   |               |  |                     |    |                                  |\n");
printf("\t\t\t|         |   |               |  |                     |    |                                  |\n");
printf("\t\t\t|         |   |               |  |                     | 大 |                                  |\n");
printf("\t\t\t|         |   |               |  |                     |    |                                  |\n");
printf("\t\t\t|         |   |               |  |                     |    |                                  |\n");
printf("\t\t\t|  【美食】   |               |   --------             |    |                                  |\n");
printf("\t\t\t|  【广场】   |               |          【操场】      | 道 |                                  |\n");
printf("\t\t\t|         |   |               |   --------             |    |                                  |\n");
printf("\t\t\t|         |   |               |  |                     |    |                                  |\n");
printf("\t\t\t|         |   |               |  |                     |    |                                  |\n");
printf("\t\t\t|         |   |               |  |                     |    |                                  |\n");
printf("\t\t\t|         |   |---------------   |                     |    |                                  |\n");
printf("\t\t\t|      【西区宿舍】         【旭日苑】                 |    |                                  |\n");
printf("\t\t\t|         |-------------------   |                     |    |                                  |\n");
printf("\t\t\t|                             |  |                     |    |                                  |\n");
printf("\t\t\t -------------------------------------------------------     ----------------------------------\n");
}



//添加新地点
void Add_Place(AdjMatrix *G)
{
    char name[50];
    int i, j, m, num;

    printf("\033[2J\033[15;0H\t\t\t\t\t\033[31m+\033[0m   添加新地点...\n\n\n\n");
    printf("\t\t\t\t\t请输入要添加的景点的数目：");
    scanf("%d", &num);
    m = G->vexnum;
    G->vexnum += num;

    //初始化新加入的边信息集合
    for(j = 1; j <= num; j++){
        for(i = 1; i <= G->vexnum; i++){

            G->arcs[i][m+j] = INFINITY;
            G->arcs[m+j][i] = INFINITY;

        }
    }

    //新加入的顶点信息
    for(i = m+1; i <= G->vexnum; i++){
        printf("\t\t\t\t\t请输入第NO.%d个景点序号和名字：", i);
        scanf("%d %s", &G->vex[i].NO, G->vex[i].name);
    }
    Store(G);
    Print_AdjMatrix(G);
}

//添加新路线
void Add_Route(AdjMatrix *G)
{

    char name1[50], name2[50];
    char choice = 'y';
    int arcnum = G->arcnum, weight, i, j;

    while(choice == 'y' || choice == 'Y'){
        printf("\t\t\t\t\t请输入相关联的两个景点名字和路径长度相关联：");
        scanf("%s %s %d", name1, name2, &weight);
        i = Locate(G, name1);
        j = Locate(G, name2);
        G->arcs[i][j] = weight;
        G->arcs[j][i] = weight;
        printf("\t\t\t\t\t是否继续添加路线(y || n)：");
        getchar();
        choice = getchar();
    }
    Store(G);
    Print_AdjMatrix(G);
}

//撤销旧路线
void Del_Route(AdjMatrix *G)
{

    char name1[50], name2[50];
    char choice = 'y';
    int  i, j;

    while(choice == 'y' || choice == 'Y'){
        printf("\t\t\t\t\t请输入要撤销的两个景点名字:");
        scanf("%s %s", name1, name2);
        i = Locate(G, name1);
        j = Locate(G, name2);
        G->arcs[i][j] = INFINITY;
        G->arcs[j][i] = INFINITY;
        printf("\t\t\t\t\t是否继续撤销路线(y || n)：");
        getchar();
        choice = getchar();
    }
    Store(G);
    Print_AdjMatrix(G);
}

//撤销旧地点
void Del_Place(AdjMatrix *G)
{

    char name[50];
    char choice = 'y';
    int  i, j, k;

    while(choice == 'y' || choice == 'Y'){
        printf("\t\t\t\t\t请输入要撤销的景点的名字:");
        scanf("%s", name);
        k = Locate(G, name);
        for(j = k; j < G->vexnum; j++){
            G->vex[j] = G->vex[j+1];
        }
        for(i = k; i < G->vexnum; i++){
            for(j = 1; j <= G->vexnum; j++)
                G->arcs[i][j] = G->arcs[i+1][j];
        }
        for(j = k; j < G->vexnum; j++){
            for(i = 1; i < G->vexnum; i++)
                G->arcs[i][j] = G->arcs[i][j+1];
        }
        G->vexnum -= 1;
        Print_AdjMatrix(G);
        printf("\t\t\t\t\t是否继续撤销景点：(y || n)：");
        getchar();
        choice = getchar();
    }
    Store(G);
    Print_AdjMatrix(G);
}
