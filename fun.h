#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 40
#define Max_num 50
#define INFINITY 32768
#define LENGTH(a)  (sizeof(a)/sizeof(a[0]))


//����ṹ��
typedef struct
{
    int NO;  //�ص����
    char name[50]; //�ص���
}Vextype;

//�ڽӾ���ṹ��
typedef struct
{
    int arcs[Max_num+1][Max_num+1];  //�߼�
    Vextype vex[Max_num+1];   //���㼯
    int vexnum;    //������Ŀ
    int arcnum;    //����Ŀ
}AdjMatrix;


void switch1();
//��ҳ��
void menu();
//��ӡƽ��ͼ
void map1();
//���ݵص���ȷ���ص����
int Locate(AdjMatrix *G, char name[]);
//�����ڽӾ��󴴽�������
void Create_AdjMatrix(AdjMatrix *G);
//ʹ����Ϣ���ɾ���
void Create_Eex_AdjMatrix(AdjMatrix *G);
//�������������
void Print_AdjMatrix(AdjMatrix *G);
//������ȱ������о���
void DFSTrave(AdjMatrix G );
void DFS(AdjMatrix G, int i);
//����prim�㷨�������ͨͼ
void Prim(AdjMatrix *G, int start);
//��ѯ��ĳ����������������ͨͼ
void Prim_MiniSpanTree(AdjMatrix *G);
//����Dijkstra�㷨��Ԫ������·��
void Dijkstra(AdjMatrix *G, int start, int end, int dist[], int path[][Max_num+1]);
//��ѯ���������������·��
void Dij_Short_Path();
//��ѯ����������������·��
void All_Path(AdjMatrix *G);
//��ѯ�ص���Ϣ
void plcae(AdjMatrix *G);

//�洢��Ϣ
void Store(AdjMatrix *G);
//��ȡ��Ϣ
AdjMatrix Read();

//����µص�
void Add_Place();
//�����·��
void Add_Route();
//������·��
void Del_Route();
//�����ɵص�
void Del_Place();
