/* 
	 k���ټ��̻Ҥ������ƥ��ȥ���ץ���̤��� 
	 Time-stamp: <09:56:28 2004/6/10> 
*/
#ifndef K_NN_DISC_H
#define K_NN_DISC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "pattern.h"

#define  NAME_LEN      50
#define  DEFAULT_KNUM  1
#define  TRUE          1
#define  FALSE         0

typedef struct {
	int class;                /* ���饹�� */
	int feature;              /* ��ħ�� */
	int *tr_sample;      /* ��������ץ�� */
	int *te_sample;      /* �ƥ��ȥ���ץ�� */
	int tr_total;             /* ��������ץ����� */
	int te_total;             /* �ƥ��ȥ���ץ����� */
} Spec;

typedef struct {
	char trname[NAME_LEN];    /* ��������ץ�Υե����� */
	char tename[NAME_LEN];    /* �ƥ��ȥ���ץ�Υե����� */
} File;

typedef struct {
	double **x_tr;        /* ��������ץ� */
	double **x_te;        /* �ƥ��ȥ���ץ� */
	int *label_tr;       /* ��������ץ�Υ��饹��٥� */
	int *label_te;       /* �ƥ��ȥ���ץ�Υ��饹��٥� */
} Data;

typedef struct {
	int knum;                 /* k���� */
	double *dist_queue;  /* �ƥ���ץ�ޤǤε�Υ */
	int *index;          /* ��������ץ��index */
	int **count;          /* ���̷�� */
} KNN;

/* ����δ������ѥ�᡼���ν���� */
int  read_opt(int argc, char **argv, Spec *spc, File *fil, KNN *knn);
void alloc_param(Spec *spc, Data *dat, KNN *knn);
void free_param(Spec *spc, Data *dat, KNN *knn);
void init_param(Spec *spc, Data *dat, KNN *knn);
void read_data(Spec *spc, File *fil, Data *dat);

/* �ƥ��ȥ���ץ�Ȥε�Υ��׻� */
void calc_dist(Spec *spc, Data *dat, KNN *knn, int x);
void quick_sort(double dist[], int index[], int first, int last);

/* �ƥ��ȥ���ץ���� */
int  disc(Spec *spc, Data *dat, KNN *knn);
void output(Spec *spc, KNN *knn);

#endif
