// RPGP.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <stdio.h>
#include "status.h"
#include "store.h"
#include "story.h"
#include <string>

char chName[8];

int main()
{
	exexplain();
	exmonster();
	stext1();
	scanf_s("%s", chName, sizeof(chName));
	line1();
	printf("- 네 이름은 %s 이구나!잘 부탁해!\n", chName);
	stext2();
	line1();
	choise();
	stext3();

	get();
	battle(0);
	stext4();
	choise();
	stext5();
	choise();
	stext6();

	get();
	battle(1);
	stext7();
	choise();
	stext8();

	get();
	battle(2);
	stext9();
	choise();
	stext10();

	get();
	battle(3);
	stext11();
	choise();
	stext12();
	
	get();
	battle(4);
	stext13();
	choise();
	stext14();

	get();
	battle(5);
	stext15();
	choise();
	stext16();

	get();
	battle(6);
	stext17();
	choise();
	stext18();

	get();
	battle(7);
	potionC += 1;
	stext19();
	choise();
	stext20();

	get();
	battle(8);
	stext21();
	choise();
	stext22();
	
	battle(9);
	stext23();
	choise();
	stext24();

	battle(10);
	stext25();
	choise();
	stext26();

	battle(11);
	stext27();
	choise();

	//이제부터 던전
	printf("<지하 1층>\n\n"
		"박쥐처럼 보이는 몬스터가 날아들었다.\n");
	bChoise(12);
	printf("1층 공략 완료.\n");
	choise();

	printf("<지하 2층>\n\n"
		"들개처럼 보이는 몬스터가 달려들었다.\n");
	bChoise(13);
	printf("2층 공략 완료.\n");
	stext28();
	choise();

	printf("<지하 3층>\n\n"
		"뱀 같은 것이 다리를 감았다.\n");
	bChoise(14);
	printf("3층 공략 완료.\n");
	choise();

	printf("<지하 4층>\n\n"
		"슬라임같은 질척거리는것을 밟아버린 것 같다.\n");
	bChoise(15);
	printf("4층 공략 완료.\n");
	stext29();
	choise();

	printf("<지하 5층>\n\n"
		"불곰같은 커다란 것이 습격해왔다.\n");
	bChoise(16);
	potionC += 1;
	printf("5층 공략 완료.\n");
	stext30();
	choise();

	printf("<지하 6층>\n\n"
		"오크가 어슬렁거린다.\n");
	bChoise(17);
	printf("6층 공략 완료.\n");
	choise();

	printf("<지하 7층>\n\n"
		"거대한 거미가 다가왔다.\n");
	bChoise(18);
	printf("7층 공략 완료.\n");
	choise();

	printf("<지하 8층>\n\n"
		"맘모스 같은 것이 발을 굴렸다.\n");
	bChoise(19);
	printf("8층 공략 완료.\n");
	choise();

	printf("<지하 9층>\n\n"
		"커다란 공룡과 마주하였다.\n");
	bChoise(20);
	printf("9층 공략 완료.\n");
	printf("“이제 마지막 층이지?”");
	choise();

	printf("<지하 10층>\n\n"
		"용이 불을 뿜으며 위협했다.\n");
	bChoise(21);
	printf("10층 공략 완료.\n");
	choise();

	stext31();
	battle(22);
	stext32();
	choise();

	printf("나는 던전의 마지막 문을 열어제쳤다.\n");
	battle(23);
	printf("보스를 쓰러뜨렸다.\n");


	return 0;
}

