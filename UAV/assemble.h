#ifndef ASSEMBLE_H_INCLUDED
#define ASSEMBLE_H_INCLUDED

#include"model.h"

int num_crash;
axis f_match(int);
axis f_attract(int);
axis f_target(int);
axis tMatch, tAttract, tTarget;
void initial_uav();
double limit_uav(double, double, double);
void crash();
void update_assemble();

//num_crash��¼��ײ����
//f_matchΪ�ٶ�ƥ����
//f_attractΪ������������ų���
//f_targetΪĿ������������
//tMatch, tAttract, tTarget���ڸ�������
//initial_uav�����ʼ�����˻���Ϣ
//limit_uav�����˻��ٶȡ����ٶȽ�������
//crash������ײ����
//update_assemble����Ⱥ�׶����ݸ���


#endif
