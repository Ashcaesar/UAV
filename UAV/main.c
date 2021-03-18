﻿#include<stdio.h>
#include<math.h>

#include"model.h"
#include"assemble.h"
#include"assignment.h"
#include"parameter.h"

extern UAV uav[SIZE];
extern axis sum;            /*临时存储数据*/
extern axis p_origin;       /*原点坐标*/
extern axis p_start;        /*出发点坐标*/
extern axis p_final;        /*终点坐标*/
extern int leader_main;     /*记录长机编号*/
extern int change;          /*判定kmeans分组是否完成*/

void main() {
	int i;
	double t;
	FILE *fp;
	FILE *fp2;
	FILE *fp3;
	if ((fp = fopen("data/index.txt", "wb")) == NULL) {
		printf("离散度写入失败!\n");
		return;
	}
	if ((fp2 = fopen("data/coordinate.txt", "wb")) == NULL) {
		printf("坐标写入失败!\n");
		return;
	}
	if ((fp3 = fopen("data/team.txt", "wb")) == NULL) {
		printf("分队写入失败!\n");
		return;
	}

		initial_uav();
		for (t = 0; t < 100; t += delt) {
			if (finish_assemble()) break;
			fprintf(fp, "%f %f\n", f_dispersion(), f_speedmatch());
			for (i = 0; i < SIZE; i++) {
				fprintf(fp2, "%d %d %d\n", (int)uav[i].position.x, (int)uav[i].position.y, (int)uav[i].position.z);
				update_assemble(i);
			}
			crash();
		}

	fclose(fp);
	fclose(fp2);
	
	initial_centroid();
	do {
		update_team();
		update_centroid();
	} while (change != 0);
	leader_main = get_main_leader();
	get_team_leader();
	for (i = 0; i < SIZE; i++) {
		fprintf(fp3, "%d %d %d %d\n", (int)uav[i].position.x, (int)uav[i].position.y, (int)uav[i].position.z, uav[i].teamID);
	}
	fclose(fp3);

	for (i = 0; i < SIZE; i++) printf("uav%2d: team:%d leader:%d\n", i, uav[i].teamID, uav[i].leader);
}
