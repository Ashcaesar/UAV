#ifndef UAV_H_INCLUDED
#define UAV_H_INCLUDED

typedef struct {
	double x;
	double y;
	double z;
}axis;

typedef struct {			 
	axis position;
	axis velocity;
	axis acceleration;
	double speed;
	double phi;
	double theta;
}UAV;

int num_crash;
axis f_match(int);					   /*f_matchΪ�ٶ�ƥ����*/
axis f_attract(int);		           /*f_attractΪ������������ų���*/
axis f_target(int);                    /*f_targetΪĿ������������*/
axis tMatch, tAttract, tTarget;        /*���ڸ�������*/
void f_initial();                      /*f_initial�����ʼ��*/
double f_sat(double, double, double);  /*f_sat�Ը���ļ��ٶȺ��ٶȽ�������*/
void f_crash();                        /*f_crashͳ�Ʒ�����ײ����*/
void f_update(int);                    /*f_update���¸�������*/
int f_stop();                          /*f_stop�жϼ����Ƿ����,����Ϊ��Ⱥ�ٶȷ���;���*/
int f_leader();						   /*f_leaderȷ���������*/
double f_metric(axis, axis);           /*f_metricʵ����������*/
double f_dispersion();                 /*f_dispersion������ɢ��*/
double f_speedmatch();				   /*f_speedmatch�����ٶ�ƥ��ֵ*/

#endif // UAV_H_INCLUDED
