#ifndef MODEL_H_INCLUDED
#define MODEL_H_INCLUDED

typedef struct {
	double x;
	double y;
	double z;
}axis;

typedef struct {
	axis position;
	axis velocity;
	axis acceleration;
	double phi;
	double theta;
	int teamID;
	int leader;
}UAV;

void get_Xcg();
double get_dis(axis, axis);
double f_dispersion();
double f_speedmatch();
double dis_to_target(axis);
double angle_to_target(axis);

//axis��ά����ṹ��
//UAV���˻��ṹ�壬����λ�á��ٶȡ����ٶȡ��Ƕȡ���ӵ���Ϣ
//get_Xcg���㵱ǰ��Ⱥ����λ��
//f_dispersion���㵱ǰ��Ⱥ��ɢ��
//f_speedmatch���㵱ǰ�ٶ�ƥ���
//dis_to_target���㵱ǰ��Ⱥ������Ŀ������
//angle_to_target���㵱ǰ��Ⱥ�ٶȷ�����Ŀ������߼н�

#endif //
