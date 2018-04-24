#include "fun.h"

void menu()
{
    printf("\t\t\t\t\t\t��   ��   ��   ��   ��   ѧ\n");
    printf("\t\t\t                                  ��ӭ����У԰����ϵͳ                                  \n\n\n");
    printf("\t\t\t    ��1��      --------------------------      У԰ƽ��ͼ\n\n");
    printf("\t\t\t    ��2��      --------------------------    	У԰�ص���Ϣ��ѯ\n\n");
    printf("\t\t\t    ��3��      --------------------------       ���·��\n\n");
    printf("\t\t\t    ��4��      --------------------------       ����·��\n\n");
    printf("\t\t\t    ��5��      --------------------------     ��Ѳ�������\n\n");
    printf("\t\t\t    ��0��      --------------------------         �˳�\n");

}

void switch1()
{
    int choice,k;
    AdjMatrix G;
	Create_Eex_AdjMatrix(&G);
    printf("\t\t\t\t\t����������Ҫ�Ĺ��ܣ�");
    scanf("%d", &choice);

        switch(choice){
            case 1: map1();break; //�鿴У԰ƽ��ͼ
            case 2: plcae(&G); break; //�ص���Ϣ��ѯ
            case 3: Dij_Short_Path(&G); break; //���·��
            case 4: All_Path(&G);break;       //����·��
            case 5: Prim_MiniSpanTree(&G); break; //�����ͨͼ
            case 0: break;   //�˳�
            default:
                    printf("\t\t\t\t\t\t��Ǹ�������������󣡣���\n");
        }
      if(choice!=0){
        getchar();
        printf("t\t\t\t\t��enter������......\n");
        getchar();
        menu();
        switch1();
      }
}

//���ݵص���ȷ���ص����
int Locate(AdjMatrix *G, char name[])
{
    int i;
    for(i = 1; i <= G->vexnum; i++){
        //ͼ�к��иþ��㣬�ҵ������
        if(!strcmp(G->vex[i].name, name))
            return i;
    }
    return -1;
}

//�����ڽӾ��󴴽�������
void Create_AdjMatrix(AdjMatrix *G)
{
    int i, j, k, weight;
    char name1[50], name2[50];

    printf("\t\t\t�����µ�ͼ...\n\n\n");
    printf("\t\t\t������ѧУ�еľ�����Ŀ��·����Ŀ��");
    scanf("%d %d", &G->vexnum, &G->arcnum);

    //��ʼ������Ϣ
    for(i = 1; i <= G->vexnum; i++){
        for(j = 1; j <= G->vexnum; j++){
            G->arcs[i][j] = INFINITY;
        }
    }

    //��ʼ�����㼯��
    for(i = 1; i <= G->vexnum; i++){
        printf("\t\t\t��ֱ������%d��������ź����֣�", i);
        scanf("%d %s", &G->vex[i].NO, G->vex[i].name);
    }
    printf("\n\n");
    //�����߹�ϵ
    for(k = 1; k <= G->arcnum; k++){
        printf("\t\t\t�������NO.%d��������������������ֺ�·�����ȣ�", k);
        scanf("%s %s %d", name1, name2, &weight);
        i = Locate(G, name1);
        j = Locate(G, name2);
        G->arcs[i][j] = weight;
        G->arcs[j][i] = weight;
    }
    printf("\n\n\n\t\t\t\t\t�����µ�ͼ�ɹ���\n\n");
    Store(G);
}

//�洢�ڽӾ����ͼ
void Store(AdjMatrix *G)
{
    FILE *fp;

    if((fp = fopen("message", "wt")) == NULL){
        printf("\t\t\t\t\t��Ǹ���޷������洢!\n");
        return ;

    }
    printf("   �洢��Ϣ��...\n");
    fwrite(G, sizeof(AdjMatrix), 1, fp);
    fclose(fp);
    printf("\t\t\t\t\t�洢�ɹ�!\n\n\n");
}

//��ȡ���㼰·����Ϣ
AdjMatrix Read()
{
    FILE *fp;
    AdjMatrix G;
    if((fp = fopen("message", "rt")) == NULL){
        printf("\t\t\t\t\t��Ǹ���޷�������ȡ!\n");
        return ;
    }
    printf(" ��ȡ��Ϣ��...\n");
    fread(&G, sizeof(AdjMatrix), 1, fp);
    fclose(fp);
    printf("��ȡ�ɹ�!\n");

    return G;
}
//�������������
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

//ʹ����Ϣ���ɾ���
void Create_Eex_AdjMatrix(AdjMatrix *G)
{

	char vexnum[][50]=
	{
		{
		},
		{"����"},{"ˮ�����"},{"������ѧ¥"},{"ʵ��¥"},{"ͼ���"},{"��ʳ�㳡"},
		{"��������"},{"����Է"},{"�ٳ�"},{"����"},{"����"},{"����"},{"������ѧ¥"},
		{"����Է"},{"��������"}
	};
	char edges[][2][50]={{},
		{{"����"},{"������ѧ¥"}},
		{{"����"},{"ˮ�����"}},
		{{"����"},{"����"}},
		{{"������ѧ¥"},{"ˮ�����"}},
		{{"ʵ��¥"},{"������ѧ¥"}},
		{{"ʵ��¥"},{"ˮ�����"}},
		{{"ͼ���"},{"ˮ�����"}},
		{{"ʵ��¥"},{"ͼ���"}},
		{{"ʵ��¥"},{"��ʳ�㳡"}},
		{{"ͼ���"},{"��ʳ�㳡"}},
		{{"ͼ���"},{"����"}},
		{{"ͼ���"},{"�ٳ�"}},
		{{"����"},{"�ٳ�"}},
		{{"��������"},{"��ʳ�㳡"}},
		{{"ͼ���"},{"����Է"}},
		{{"�ٳ�"},{"����Է"}},
		{{"��������"},{"����Է"}},
		{{"����"},{"����"}},
		{{"����Է"},{"����"}},
		{{"��������"},{"����"}},
		{{"��������"},{"����Է"}},
		{{"������ѧ¥"},{"����Է"}},
		{{"������ѧ¥"},{"��������"}},
		{{"����"},{"������ѧ¥"}},
		{{"����"},{"����"}}
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

    //��ʼ�����㼯��
    for(i = 1; i <= G->vexnum; i++){
		G->vex[i].NO = i;
		strcpy(G->vex[i].name,vexnum[i]);
		//G->vex[i].name = vexnum[i];
    }
    printf("\n\n");
    //�����߹�ϵ
    for(k = 1; k <= G->arcnum; k++){
		strcpy(name1,edges[k][0]);
		strcpy(name2,edges[k][1]);
        i = Locate(G, name1);
        j = Locate(G, name2);
        G->arcs[i][j] = weights[k];
        G->arcs[j][i] = weights[k];
    }
    printf("\n\n\n\t\t\t\t\t������ͼ�ɹ���\n\n");
}

//��ѯ�ص���Ϣ
void plcae(AdjMatrix *G)
{
    char place[500], name[50], choice = 'y';
	char fopened[50];
    int i;
    FILE *fp;
    printf("\t\t\t\t\t   �ص���Ϣ��ѯ...\n\n\n\n\n");
    for(i = 1; i <= G->vexnum; i++)
        printf("%s  ", G->vex[i].name);
    printf("\n");
    while(choice == 'y' || choice == 'Y'){
        printf("\t\t\t\t\t��������Ҫ�˽�ľ�������");
        scanf("%s", name);
        strcpy(fopened,name);
		strcat(fopened,".txt");
        if((fp = fopen(fopened, "rt")) == NULL){
            printf("\t\t\t\t\t��Ǹ���ļ�δ�����򿪣�\n");
            return;
        }
        while((fgets(place, 500, fp)) != NULL){
            printf("%s", place);
        }
        fclose(fp);
        getchar();
        printf("\n\n\t\t\t\t\t�Ƿ�Ҫ����(y || n)��");
        scanf("%c", &choice);
    }
}

//��ѯ����������������·��
int visited[Max_num+1];
int pre[Max_num+1];  //���һ��·�еĸ������������е��±�
void Path(AdjMatrix *G, int start, int end, int length, int dist)
{
    int i;

    if(pre[length] == end && length < G->vexnum){		//�ҵ�һ��ͨ·
        printf("%s ", G->vex[pre[1]].name);
        for(i = 2; i <= length; i++){				//��ӡ·��
            printf("����> %s", G->vex[pre[i]].name);
            if(G->arcs[pre[i-1]][pre[i]] != INFINITY){		//���㵱ǰ����·����ǰһ�����ľ���
                dist += G->arcs[pre[i-1]][pre[i]];
            }
        }

        printf("����Ϊ: %d\n", dist);
        dist = 0;
    }else{  	// û������������
        i = 1;
        while(i <= G->vexnum){
            if(!visited[i] && G->arcs[pre[length]][i] != INFINITY){		//�ڽ���û�з���
                visited[i] = 1;									//ǰ������
                pre[length+1] = i;
                Path(G, i, end, length+1, dist);
                visited[i] = 0;		//�˻ؾ���·����ɾ������
            }
            i++;
        }
    }
}

//��ѯ����������������·��
void All_Path(AdjMatrix *G)
{
    int i, start, end;
    char name1[50], name2[50];
    int dist = 0;

    printf("\t\t\t\t\t��������㣺");
    scanf("%s", name1);
    start = Locate(G, name1);
    while(start == -1)
	{
		printf("\t\t\t\t��Ч����,����������:");
		scanf("%s", name1);
		start = Locate(G,name1);
	}
	printf("\t\t\t\t\t�������յ㣺");
    scanf("%s", name2);
    end = Locate(G, name2);
    while(end == -1)
	{
		printf("\t\t\t\t��Ч����,����������:");
		scanf("%s", name2);
		end = Locate(G,name2);
	}
    for(i = 1; i <= Max_num; i++)
        visited[i] = 0;
    visited[start] = 1;  // ���ʹ�����Ϊ1
    pre[1] = start;
    printf("%s---->%s������·��Ϊ��\n", G->vex[start].name, G->vex[end].name);
    Path(G, start, end, 1, dist);
}



//��ѯ���������������·��
void Dij_Short_Path(AdjMatrix *G)
{
    char name[50], choice = 'y';	//
    int start, end;
    int dist[Max_num+1];
    printf("\t\t\t\t\t  ���·��...\n\n\n\n");
    while(choice == 'y' || choice == 'Y'){
        int path[Max_num+1][Max_num+1] = {0};
        printf("\n\t\t\t\t\t��������㣺");
        scanf("%s", name);
        start = Locate(G, name);
        while(start == -1)
		{
			printf("\t\t\t\t��Ч����,����������:");
			scanf("%s", name);
			start = Locate(G,name);
		}
        printf("\t\t\t\t\t�������յ㣺");
        scanf("%s", name);
        end = Locate(G, name);
        while(end == -1)
		{
			printf("\t\t\t\t��Ч����,����������:");
			scanf("%s", name);
			end = Locate(G,name);
		}
        Dijkstra(G, start, end, dist, path);
        printf("\t\t\t\t\t�Ƿ������ѯ(y || n)��");
        getchar();
        choice = getchar();
    }
}

//����Dijkstra�㷨��Ԫ������·��
void Dijkstra(AdjMatrix *G, int start, int end, int dist[], int path[][Max_num+1])
{
    int mindist, i, j, k, t = 1;

    //��ʼ��
    for(i = 1; i <= G->vexnum; i++){
        dist[i] = G->arcs[start][i];		//���뿪ʼ�е��ڽ���Ϣ
        if(G->arcs[start][i] != INFINITY)
            path[i][1] = start;
    }
    path[start][0] = 1;

    //Ѱ�����·��
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

        //�޸ļ��������·��
        for(j = 1; j <= G->vexnum; j++){
            if(!path[j][0] && G->arcs[k][j] < INFINITY && G->arcs[k][j] + dist[k] < dist[j]){
                dist[j] = dist[k] + G->arcs[k][j];

               //��¼���·��
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
        printf("\n\n\t%s----->%s  ������ͨ·!!!\n", G->vex[start].name, G->vex[end].name);
        return;
    }
    //������·��
    printf("\n\n\t%s----->%s�����·�ߣ�%s ", G->vex[start].name, G->vex[end].name, G->vex[start].name);
    for(j = 2; path[end][j]; j++)
        printf("����>%s ", G->vex[path[end][j]].name);
    printf("����>%s", G->vex[end].name);
    printf("\n\t����Ϊ��%d\n", dist[end]);

}


//��ѯ��ĳ����������������ͨͼ
void Prim_MiniSpanTree(AdjMatrix *G)
{
    char name[50], choice = 'y';
    int start;
    printf("\t\t\t\t\t  ��Ѳ������� \n\n\n\n");
    while(choice == 'y' || choice == 'Y'){
        printf("\t\t\t\t\t��������㣺");
        scanf("%s", name);
        start = Locate(G, name);
        Prim(G, start);
        printf("\t\t\t\t\t�Ƿ������ѯ(y || n): ");
        getchar();
        choice = getchar();
    }
}

//����prim�㷨�������ͨͼ
void Prim(AdjMatrix *G, int start)
{
    struct{
        int adjvex;
        int lowcost;
        int pass;
    }closedge[Max_num+1];
    int i, e, k, m, min;

    //��ʼ��
    closedge[start].lowcost = 0;
    for(i = 1; i <= G->vexnum; i++){
        if(i != start){
        closedge[i].adjvex = start;
        closedge[i].lowcost = G->arcs[start][i];
        }
    }

    //����Сֵ�ı�
    for(e = 1; e <= G->vexnum-1; e++){

        min = INFINITY;
        for(k = 1; k <= G->vexnum; k++){
            if(closedge[k].lowcost != 0 && closedge[k].lowcost < min){
                m = k;
                min = closedge[k].lowcost;
            }
        }
        printf("\t%s----->%s: ����Ϊ%d\n", G->vex[closedge[m].adjvex].name, G->vex[m].name, closedge[m].lowcost);
        closedge[m].lowcost = 0;

        //����󣬸���closedge����
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
printf("\t\t\t ---------------------------�����š�--------------------     ----------------------------------\n");
printf("\t\t\t|                             |  |                     |    |                                  |\n");
printf("\t\t\t|           ------------------   |                     |    |                                  |\n");
printf("\t\t\t|          |    --------------   |                     |    |                                  |\n");
printf("\t\t\t|       ����  ����           ��ˮ��                  |    |     --------                     |\n");
printf("\t\t\t|       ����ѧ¥��           �����ӡ�                  |    �����š�     ����  ����            |\n");
printf("\t\t\t|         |    |              |  |                     |    |     -------����ѧ¥��            |\n");
printf("\t\t\t|         |    |              |  |                     |    |             |      |             |\n");
printf("\t\t\t|         |    |              |  |                     |    |             |      |             |\n");
printf("\t\t\t|         |    |              |  |                     |    |             |      |             |\n");
printf("\t\t\t|         |    |              |  |                     |    |             |      |             |\n");
printf("\t\t\t|         |    |              |  |                     |    |             |      |             |\n");
printf("\t\t\t|         |    |              |  |                     |    |             |      |             |\n");
printf("\t\t\t|         |    |--------------   |                     | �� |             |      ---��������   |\n");
printf("\t\t\t|       ��ʵ��¥��               |                     |    |             |      ---�����᡿   |\n");
printf("\t\t\t|         |-------------------   |                     |    |             |      |             |\n");
printf("\t\t\t|                             |  |                     |    |         -----      |             |\n");
printf("\t\t\t|                             |  |                     |    | ������Է��         |             |\n");
printf("\t\t\t|                             |  |                     |    |         -----      |             |\n");
printf("\t\t\t|                             |  |                     | �� |             |      |             |\n");
printf("\t\t\t|          -------------------    ---------------------|    |-------------|      |             |\n");
printf("\t\t\t|         |                 ��ͼ��ݡ�             �����š������š�              |             |\n");
printf("\t\t\t|         |    --------------     ---------------------|    |---------------------             |\n");
printf("\t\t\t|         |   |               |  |                     |    |                                  |\n");
printf("\t\t\t|         |   |               |  |                     |    |                                  |\n");
printf("\t\t\t|         |   |               |  |                     | �� |                                  |\n");
printf("\t\t\t|         |   |               |  |                     |    |                                  |\n");
printf("\t\t\t|         |   |               |  |                     |    |                                  |\n");
printf("\t\t\t|  ����ʳ��   |               |   --------             |    |                                  |\n");
printf("\t\t\t|  ���㳡��   |               |          ���ٳ���      | �� |                                  |\n");
printf("\t\t\t|         |   |               |   --------             |    |                                  |\n");
printf("\t\t\t|         |   |               |  |                     |    |                                  |\n");
printf("\t\t\t|         |   |               |  |                     |    |                                  |\n");
printf("\t\t\t|         |   |               |  |                     |    |                                  |\n");
printf("\t\t\t|         |   |---------------   |                     |    |                                  |\n");
printf("\t\t\t|      ���������᡿         ������Է��                 |    |                                  |\n");
printf("\t\t\t|         |-------------------   |                     |    |                                  |\n");
printf("\t\t\t|                             |  |                     |    |                                  |\n");
printf("\t\t\t -------------------------------------------------------     ----------------------------------\n");
}



//����µص�
void Add_Place(AdjMatrix *G)
{
    char name[50];
    int i, j, m, num;

    printf("\033[2J\033[15;0H\t\t\t\t\t\033[31m+\033[0m   ����µص�...\n\n\n\n");
    printf("\t\t\t\t\t������Ҫ��ӵľ������Ŀ��");
    scanf("%d", &num);
    m = G->vexnum;
    G->vexnum += num;

    //��ʼ���¼���ı���Ϣ����
    for(j = 1; j <= num; j++){
        for(i = 1; i <= G->vexnum; i++){

            G->arcs[i][m+j] = INFINITY;
            G->arcs[m+j][i] = INFINITY;

        }
    }

    //�¼���Ķ�����Ϣ
    for(i = m+1; i <= G->vexnum; i++){
        printf("\t\t\t\t\t�������NO.%d��������ź����֣�", i);
        scanf("%d %s", &G->vex[i].NO, G->vex[i].name);
    }
    Store(G);
    Print_AdjMatrix(G);
}

//�����·��
void Add_Route(AdjMatrix *G)
{

    char name1[50], name2[50];
    char choice = 'y';
    int arcnum = G->arcnum, weight, i, j;

    while(choice == 'y' || choice == 'Y'){
        printf("\t\t\t\t\t������������������������ֺ�·�������������");
        scanf("%s %s %d", name1, name2, &weight);
        i = Locate(G, name1);
        j = Locate(G, name2);
        G->arcs[i][j] = weight;
        G->arcs[j][i] = weight;
        printf("\t\t\t\t\t�Ƿ�������·��(y || n)��");
        getchar();
        choice = getchar();
    }
    Store(G);
    Print_AdjMatrix(G);
}

//������·��
void Del_Route(AdjMatrix *G)
{

    char name1[50], name2[50];
    char choice = 'y';
    int  i, j;

    while(choice == 'y' || choice == 'Y'){
        printf("\t\t\t\t\t������Ҫ������������������:");
        scanf("%s %s", name1, name2);
        i = Locate(G, name1);
        j = Locate(G, name2);
        G->arcs[i][j] = INFINITY;
        G->arcs[j][i] = INFINITY;
        printf("\t\t\t\t\t�Ƿ��������·��(y || n)��");
        getchar();
        choice = getchar();
    }
    Store(G);
    Print_AdjMatrix(G);
}

//�����ɵص�
void Del_Place(AdjMatrix *G)
{

    char name[50];
    char choice = 'y';
    int  i, j, k;

    while(choice == 'y' || choice == 'Y'){
        printf("\t\t\t\t\t������Ҫ�����ľ��������:");
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
        printf("\t\t\t\t\t�Ƿ�����������㣺(y || n)��");
        getchar();
        choice = getchar();
    }
    Store(G);
    Print_AdjMatrix(G);
}
