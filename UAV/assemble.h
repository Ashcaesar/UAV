#ifndef ASSEMBLE_H_INCLUDED
#define ASSEMBLE_H_INCLUDED

#include"model.h"

int num_crash;
axis f_match(int);					   /*f_matchΪ�ٶ�ƥ����*/
axis f_attract(int);		           /*f_attractΪ������������ų���*/
axis f_target(int);                    /*f_targetΪĿ������������*/
axis tMatch, tAttract, tTarget;        /*���ڸ�������*/
void initial_uav();                    /*f_initial�����ʼ��*/
double limit_uav(double, double, double);  /*f_sat�Ը���ļ��ٶȺ��ٶȽ�������*/
void crash();                        /*f_crashͳ�Ʒ�����ײ����*/
void update_assemble(int);                    /*f_update���¸�������*/
int finish_assemble();                          /*f_stop�жϼ����Ƿ����,����Ϊ��Ⱥ�ٶȷ���;���*/
int get_leader();						   /*f_leaderȷ���������*/
double f_dispersion();                 /*f_dispersion������ɢ��*/
double f_speedmatch();				   /*f_speedmatch�����ٶ�ƥ��ֵ*/



#endif
