#pragma once
#include "pch.h"
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "story.h"

static int HP[20];
static int ATK[20];
static int DEF[20];
static int LV[20];
static int pHP1 = 0;
static int pHP2 = 0;
static int pHP3 = 0;
static int money = 0;
static int EXP[20];
static int HEXP[20] = { 0 };

static int maxHP[20];

static int potionC = 1;

static int i = 0;

int mHP[24];
int maxmHP[24];
int mATK[24];
int nmEXP[24];
int mEXP[24];

void store();
void status();
void buy1();
void buy2();
void buy3();
void drink();


void explain(int *LV, int *HP, int *ATK, int *DEF, int *EXP, int *maxHP) {

	for (int i = 0; i < 20; i++)
		LV[i] = i + 1;

	HP[0] = 8;
	maxHP[0] = 8;
	for (int i = 1; i < 20; i++) {
		maxHP[i] = maxHP[i - 1] + LV[i]*1.1;
		HP[i] = HP[i - 1] + LV[i]*1.1;
	}

	ATK[0] = 10;
	for (int i = 1; i < 20; i++)
		ATK[i] = ATK[i - 1] + LV[i] * 1.5;

	DEF[0] = 5;
	for (int i = 1; i < 20; i++)
		DEF[i] = DEF[i - 1] + LV[i] * 0.5;

	EXP[0] = 5;
	for (int i = 1; i < 20; i++)
		EXP[i] = EXP[i - 1] + LV[i] * 3;

	EXP[19] = 99999999;

	return;
}

void exexplain() {
	explain(LV, HP, ATK, DEF, EXP, maxHP);
}

void choise(){
printf("1.스토리 진행  2.상점  3.스테이터스  4.게임종료\n");
printf("번호를 입력하시오: ");
int cNumB;
scanf_s("%d", &cNumB);
switch (cNumB)
{
case 1:
	return;
	break;
case 2:
	store();
	break;
case 3:
	status();
	break;
default:
	exit(0);
}
}



void store() {
	int cNumS;
	printf("1.구매  2.포션마시기  3.뒤로가기\n");
	printf("번호를 입력하시오: ");
	scanf_s("%d", &cNumS);
	switch (cNumS)
	{
	case 1:
		switch (potionC) {
		case 1:
			buy1();
			break;
		case 2:
			buy2();
			break;
		default :
			buy3();
			break;
		}
		break;
	case 2:
		drink();
		break;
	default:
		choise();
	}
}
void buy1() {
	printf("무엇을 구매할까요\n");
	printf("1.하급HP  2.뒤로가기\n");
	printf("번호를 입력하시오: ");
	int cNumS;
	scanf_s("%d", &cNumS);
	switch (cNumS)
	{
	case 1:
		if (money > 3) {
			pHP1++;
			money -= 3;
			buy1();
		}
		else {
			printf("돈이부족합니다.\n");
			store();
		}
		break;
	default:
		store();
	}
	return;
}
void buy2() {
	printf("무엇을 구매할까요\n");
	printf("1.하급HP  2.중급HP  3.뒤로가기\n");
	printf("번호를 입력하시오: ");
	int cNumS;
	scanf_s("%d", &cNumS);
	switch (cNumS)
	{
	case 1:
		if (money > 3) {
			pHP1++;
			money -= 3;
			buy2();
		}
		else {
			printf("돈이부족합니다.\n");
			store();
		}
		break;
	case 2:
		if (money > 5) {
			pHP2++;
			money -= 5;
			buy2();
		}
		else {
			printf("돈이부족합니다.\n");
			store();
		}
		break;
	default:
		store();
	}
	return;
}
void buy3() {
	printf("무엇을 구매할까요\n");
	printf("1.하급HP  2.중급HP  3.상급HP 4.뒤로가기\n");
	printf("번호를 입력하시오: ");
	int cNumS;
	scanf_s("%d", &cNumS);
	switch (cNumS)
	{
	case 1:
		if (money > 3) {
			pHP1++;
			money -= 3;
			buy3();
		}
		else {
			printf("돈이부족합니다.\n");
			store();
		}
		break;
	case 2:
		if (money > 5) {
			pHP2++;
			money -= 5;
			buy3();
		}
		else {
			printf("돈이부족합니다.\n");
			store();
		}
		break;
	case 3:
		if (money > 7) {
			pHP3++;
			money -= 7;
			buy3();
		}
		else {
			printf("돈이부족합니다.\n");
			store();
		}
		break;
	default:
		store();
	}
	return;
}

void drink() {
	printf("하급HP: %d  중급HP: %d  상급HP: %d", pHP1, pHP2, pHP3);
	printf("무엇을 마실까요\n");
	printf("1.하급HP  2.중급HP  3.상급HP  4.뒤로가기\n");
	printf("번호를 입력하시오: ");
	int cNumS;
	scanf_s("%d", &cNumS);
	switch (cNumS)
	{
	case 1:
		if (pHP1 > 0) {
			HP[i] += 30;
			if (maxHP[i] < HP[i])
				HP[i] = maxHP[i];
			pHP1--;
			drink();
		}
		else {
			printf("포션이부족합니다.\n");
			drink();
		}
		break;
	case 2:
		if (pHP2 > 0) {
			HP[i] += 70;
			if (maxHP[i] < HP[i])
				HP[i] = maxHP[i];
			pHP2--;
			drink();
		}
		else {
			printf("포션이부족합니다.\n");
			drink();
		}
		break;
	case 3:
		if (pHP3 > 0) {
			HP[i] += 150;
			if (maxHP[i] < HP[i])
				HP[i] = maxHP[i];
			pHP3--;
			drink();
		}
		else {
			printf("포션이부족합니다.\n");
			drink();
		}
		break;
	default:
		return;
	}
	return;
}
void status() {
	printf("LV: %d\n", LV[i]);
	printf("HP: %d\n", HP[i]);
	printf("ATK: %d\n", ATK[i]);
	printf("DEF: %d\n", DEF[i]);
	printf("money: %d\n", money);
	choise();
}
void monster(int *mHP, int *mATK, int *mEXP, int *maxmHP) {
	
	mHP[0] = 10;
	maxmHP[0] = 10;
	mATK[0] = 2;

	for (int i = 1; i < 24; i++) {
		mHP[i] = mHP[i - 1] + i * 4;
		maxmHP[i] = maxmHP[i - 1] + i * 4;
		mATK[i] = mATK[i - 1] + i * 0.7;
	}

	mHP[11] = 400;
	mHP[22] = 1500;
	mHP[23] = 3000;

	mEXP[0] = 8;

	for (int i = 1; i < 24; i++) {
		mEXP[i] = mEXP[i - 1] + i * 1.8;
	}
	return;
}
void exmonster() {
	monster(mHP, mATK, mEXP, maxmHP);
}

void battle(int anm) {
	if (mHP[anm] <= 0) {
		printf("적은 쓰러졌다.\n"
			"%d EXP를 획득하였다.\n%d GOLD를 획득하였다. \n", mEXP[anm], 5);
		HEXP[i] += mEXP[anm];
		money += 5;
		if (HEXP[i] >= EXP[i]) {
			int num = HEXP[i] - EXP[i];
			++ i;
			HEXP[i] += num;
			printf("레벨 업! LV%d가 되었다.\n", LV[i]);
		}
		return;
	}
	printf("\n적\n"
		"HP : %d\n\n", mHP[anm]);

	printf("나\n"
		"HP : %d\n\n", HP[i]);

	printf("1.어택  2.가드  3.포션\n");
	printf("번호를 입력하시오: ");
	int cNumB;
	scanf_s("%d", &cNumB);
	switch (cNumB)
	{
	case 1:
	{
		int ratk = rand() % 6 + ATK[i];
		mHP[anm] -= ratk;
		printf("적 에게 %d의 데미지를 입혔다.\n", ratk);
		if (mHP[anm] <= 0) {
			printf("적은 쓰러졌다.\n"
				"%d EXP를 획득하였다.\n%d GOLD를 획득하였다. \n", mEXP[anm], 5);
			HEXP[i] += mEXP[anm];
			money += 5;
			if (HEXP[i] >= EXP[i]) {
				int num = HEXP[i] - EXP[i];
				++i;
				HEXP[i] += num;
				printf("레벨 업! LV%d가 되었다.\n", LV[i]);
			}
			return;
		}
		int rmatk = rand() % 6 + mATK[anm];
		int dem = DEF[i] - rmatk;
		if (dem < 0) {
			HP[i] += dem;
			printf("적의 공격! %d 데미지를 입었다.\n", dem);
			if (HP[i] <= 0) {
				if (anm == 22)
					badEnding2();
				else if (anm == 23)
					badEnding3();
				else
					printf("\n당신은 사망하였습니다.\n BAD ENDING\n");
				exit(0);
			}
		}
		else
			printf("방어하였다.\n");
		battle(anm);
	}
	break;
	case 2:
	{
		printf("가드 사용!\n");
		int rmatk2 = rand() % 16 + mATK[anm];
		int dem2 = DEF[i] * 2 - rmatk2;
		if (dem2 < 0) {
			HP[i] += dem2;
			printf("적의 공격! %d 데미지를 입었다.\n", dem2);
			if (HP[i] <= 0) {
				if (anm == 22)
					badEnding2();
				else if (anm == 23)
					badEnding3();
				else
					printf("\n당신은 사망하였습니다.\n BAD ENDING\n");
				exit(0);
			}
		}
		else
			printf("방어하였다.\n");
		battle(anm);
	}
		break;
	default:
		drink();
		int rmatk = rand() % 6 + mATK[anm];
		int dem = DEF[i] - rmatk;
		if (dem < 0) {
			HP[i] += dem;
			printf("적의 공격! %d 데미지를 입었다.\n", dem);
			if (HP[i] <= 0) {
				if (anm == 22)
					badEnding2();
				else if (anm == 23)
					badEnding3();
				else
					printf("\n당신은 사망하였습니다.\n BAD ENDING\n");
				exit(0);
			}
		}
		else
			printf("방어하였다.\n");

		battle(anm);;
	}

}

void bChoise(int anm) {
	int cNumB = 2;

	while (cNumB == 2) {
		battle(anm);

		printf("\n1.층을 내려간다 2.이 층을 한 번 더 도전\n");
		printf("번호를 입력하시오: ");
		scanf_s("%d", &cNumB);
		mHP[anm] = maxmHP[anm];
	}
	return;
}